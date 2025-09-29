#include "dgesv.h"
#include <stdio.h>
#include <math.h>
#include <stdio.h>

// Function to swap two rows in a matrix
int swap_rows(double *matrix, int row1, int row2, int n) {
  for (int j = 0; j < n; j++) {
    double temp = matrix[row1 * n + j];
    matrix[row1 * n + j] = matrix[row2 * n + j];
    matrix[row2 * n + j] = temp;
  }
  return 0;
}

int my_dgesv(int n, int nrhs, double *a, double *b)
{
  for (int i=0;i<n;i++) {

    // Search for maximum in this column
    int swap_row = i;
    double max_val = fabs(a[i*n + i]);
    for (int j = i+1; j < n; j++) {
      double val = fabs(a[j*n + i]);
      if (val > max_val) {
        max_val = val;
        swap_row = j;
      }
    }

    // Swap maximum row with current row
    if (swap_row != i) {
      swap_rows(a, i, swap_row, n);
      swap_rows(b, i, swap_row, nrhs);
    }

    double pivot = a[i*n+i];
    // Transform to upper triangular matrix
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

  // Back substitution
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
