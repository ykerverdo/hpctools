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
4096x4096 : 

### 03