#include "dgesv.h"

int my_dgesv(int n, int nrhs, double *a, double *b)
{

  for (int i=0;i<n;i++) {
    double pivot = a[i*n+i];
    for (int j=i+1;j<n;j++) {
      double factor = a[j*n+i]/pivot;
      a[j*n+i] = 0.0;
      for (int k=i+1;k<n;k++) {
        a[j*n+k] -= factor*a[i*n+k];
      }
      for (int k=0;k<nrhs;k++) {
        b[j*nrhs+k] -= factor*b[i*nrhs+k];
      }
    }
  }

  for (int i=0;i<nrhs;i++) {
    for (int j=n-1;j>=0;j--) {
      for (int k=j+1;k<n;k++) {
        b[j*nrhs+i] -= a[j*n+k]*b[k*nrhs+i];
      }
      b[j*nrhs+i] /= a[j*n+j];
    }
  }
  return 0;
}
