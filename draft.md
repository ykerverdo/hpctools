## 10.1.0
### REF/O0
1024x1024 : 7573 / 6765 / 6687
2048x2048 : 80718 / 81188 / 81177
4096x4096 : 974268 / 967964 / 979925
O(n^3) donc ça explique

### O2 -novecsq
- 02 : Optimisations intermédiaires sans ralentir la compilation de manière excessive.Réorganisation du code pour accélérer les boucles, suppressions d’instructions inutiles. Active la plupart des optimisations sauf celles qui augmenteraient beaucoup la taille du binaire ou ralentiraient le debug.

- novecsq : Pas de vectorization

1024x1024 : 2624 / 2573 / 2589
2048x2048 : 26919 / 27400 / 27204
4096x4096 : 429919 / 431474 / 429119

### 03
no modifications
1024x1024 : 4319 / 4434 / 4545
2048x2048 : 49308 / 50986 / 50194
4096x4096 : 644904 / 632710 / 640890

Temps de calcul plus long.
Le compilateur vectorise automatiquement, mais il ne sait pas que les données sont alignées ni qu’il n’y a pas d’aliasing. Il doit donc générer des instructions SIMD plus prudentes pour gérer les accès mémoire non alignés et les possibles dépendances entre pointeurs. Ces précautions ajoutent des surcoûts mémoire et réduisent l’efficacité du cache.

- restrict sur les pointeurs a et b : explicitement : "aucune autre variable ne pointe sur cette mémoire"
assert there is not aliasing (two pointers pointing to the same memory location). moins de garde contre l’aliasing, vectoriser et réordonner les instructions plus librement, Moins de précautions pour le compilateur → vectorisation plus agressive

- __builtin_assume_aligned sur a et b : assume an aligned pointer is returned, Avant : le compilateur devait générer du code compatible avec des accès non alignés, plus lent pour SIMD. Après : on affirme que a et b sont alignés sur 32 octets (avx et avx2), ce qui correspond à l’alignement nécessaire pour des instructions SIMD (AVX).
Les boucles qui accèdent à a et b peuvent utiliser chargements/stocks vectoriels rapides et alignés. Réduit le nombre de micro-opérations et les pénalités de cache/mémoire. il faut vraiment que les pointeurs fourni soient aligné en mémoire,

- main.c -> _mm_malloc : pour aligner sur 32 octets et pouvoir utiliser __builtin_assume_aligned

- #pragma omp simd pour les boucles k : the loop can be transformed into a SIMD loop ⇒ vectorized!

1024x1024 : 2790 / 2816 / 2132
2048x2048 : 27222 / 27033 / 22215
4096x4096 : 261521 / 259560 / 369221

Le compilateur vectorise les mêmes boucles, mais cette fois-ci il sait que : Les données sont alignées sur 32 octets (__builtin_assume_aligned), donc il peut utiliser des instructions SIMD rapides. Les pointeurs ne se chevauchent pas (restrict), donc pas besoin de générer des instructions conservatrices. La boucle est explicitement vectorisable (#pragma omp simd). On ne perd pas le temps perdu précédemment. L’accès mémoire optimisé (meilleur usage du cache) L’exécution SIMD sur plusieurs données en parallèle Donc, plus la matrice est grande, plus ces optimisations ont un effet sur le temps d’exécution. On le voit pour 2 petites matrices meme temps mais pour grande temps /2 ou 3


Vectorization : 
```c
for (int j = 0; j < n; j++) {
    double temp = matrix[row1 * n + j];
    matrix[row1 * n + j] = matrix[row2 * n + j];
    matrix[row2 * n + j] = temp;
}
```
Vectorisée par gcc : dgesv.c:8:3: optimized: loop vectorized using 16 byte vectors
chaque itération de j accède à des éléments contigus en mémoire et indépendants. Il n’y a aucune dépendance entre les itérations, donc le compilateur peut exécuter les copies simultanément avec SIMD
```c
for (int k=i+1;k<n;k++) {
    a[j*n+k] -= factor*a[i*n+k];
}
for (int k=0;k<nrhs;k++) {
    b[j*nrhs+k] -= factor*b[i*nrhs+k];
}
```
Les boucles sur k sont vectorisables car chaque itération accède à des éléments contigus en mémoire et indépendants. Il n’y a aucune dépendance entre les itérations, ce qui permet au compilateur d’exécuter les opérations sur plusieurs éléments en parallèle avec SIMD
```c
for (int k=j+1;k<n;k++) {
 b[j*nrhs+i] -= a[j*n+k]*b[k*nrhs+i];
}
```
Pas vectorisée par gcc: WAW (Write after Write) aka Output dependency -> On écrit toujours sur la même variable b[j*nrhs+i] et on lit plusieurs valeurs pour le calcul de sum In general it cannnot
be vectorized. ensuite j'ai fait ça :
```c
#pragma omp simd
for (int k=j+1;k<n;k++) {
    sum += a[j*n+k]*b[k*nrhs+i];
}
b[j*nrhs+i] -= sum;
```
normally It can be vectorized when recognized as a sum
reduction by the compiler
Nouveau problème : accès en colonne non contigu donc vectorisation impossible à nouveau. Nécessiterai un resturcturing entier du code pour passer en column major, mais ducoup la triangularisation perdrait sa vectorisation sur b. Dans le cas ou nrhs est petit ça permettrai d'améliorer grandement la vitesse d'execution mais ici nrhs vaut n donc peut d'intéret.
```c
double sum = 0.0;
double tmp_col[n];
for (int k=j+1;k<n;k++){
    tmp_col[k] = b[k*nrhs+i];
}
#pragma omp simd
for (int k=j+1;k<n;k++) {
    sum += a[j*n+k]*tmp_col[k];
}
b[j*nrhs+i] -= sum;
```
Copie dans un buffer avant permet de vectoriser la boucle d'après, mais pas la copie. Donc on perd beaucoup de temps au final puisqu'on ajoute une nouvelle boucle non vectorisable.
```c
for (int j = i+1; j < n; j++) {
    double val = fabs(a[j*n + i]);
    if (val > max_val) {
        max_val = val;
        swap_row = j;
    }
}
```
Conditional statements are allowed in a loop if they can be replaced by
masks donc là pas possible
```c
double max_val = fabs(a[i*n + i]);
#pragma omp simd
for (int j = i+1; j < n; j++) {
    double val = fabs(a[j*n + i]);
    max_val = fmax(max_val, val);
}
for (int j=i+1; j < n; j++) {
    if (fabs(a[j*n + i]) == max_val) {
        swap_row = j;
        break;
    }
}
```
Tentative de solution : faire le if dans une autre boucle séquentielle après, mais ducoup pas sur d'avoir un gain de temps. Autre problème, Write after write et accès non contigue en mémoire donc trop compliqué à vectoriser
```c
for (int i=0;i<n;i++) 
```
Boucle principale jamais vectorisables, trop de dépendances, de boucles imbriquées etc ...
### -Ofast
optimisations agressives et mathématiques rapides, mais moins strict sur la conformité aux normes
Enables -ffast-math, optimizations that are not valid for all
standard-compliant programs.

1024x1024 : 2418 / 2344 / 2496
2048x2048 : 36350 / 38594 / 38399
4096x4096 : 542840 / 542857 / 538060


## 11.4.0
### REF/O0
1024x1024 : 7704 / 7768 / 7776
2048x2048 : 58725 / 59127 / 59428
4096x4096 : 923832 / 973812 / 973747

### O2 -novecsq

1024x1024 : 2663 / 2634 / 2612
2048x2048 : 27591 / 27081 / 27017
4096x4096 : 475970 / 471019 / 470737

### 03

1024x1024 : 3317 / 3282 / 3285
2048x2048 : 51579 / 47073 / 60205
4096x4096 : 753977 / 758971 / 732310

### -Ofast

1024x1024 : 3553 / 3293 / 3539
2048x2048 : 51899 / 47518 / 59792
4096x4096 : 680866 / 687900 / 732173

## 8.4.0
### REF/O0
1024x1024 : 8301 / 9245 / 8283
2048x2048 : 148741 / 147702 / 111939
4096x4096 : 1086809 / 1085050 / 1111796

### O2 -novecsq

1024x1024 : 3375 / 3329 / 3404
2048x2048 : 45714 / 43184 / 39009
4096x4096 : 709211 / 689009 / 715041

### 03

1024x1024 : 2899 / 2954 / 3047
2048x2048 : 34311 / 34111 / 34674
4096x4096 : 772146 / 772257 / 711900

### -Ofast

1024x1024 : 3783 / 3888 / 4070
2048x2048 : 54343 / 56351 / 56874
4096x4096 : 637878 / 657119 /   