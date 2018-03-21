#ifdef __cplusplus
extern "C" {
#endif

#include "cosine_similarity.h"
#include <math.h>

/* int intersection(const int arr1[], const int arr2[], const int m, const int n, */
/*                  int *out) { */
/*   int i = 0, j = 0, k = 0; */
/*   while (i < m && j < n) { */
/*     if (arr1[i] < arr2[j]) */
/*       i++; */
/*     else if (arr2[j] < arr1[i]) */
/*       j++; */
/*     else /1* if arr1[i] == arr2[j] *1/ */
/*     { */
/*       /1* printf(" %d ", arr2[j++]); *1/ */
/*       out[k++] = arr2[j++]; */
/*       i++; */
/*     } */
/*   } */
/*   return k; */
/* } */

/* double cblas_dsdot (OPENBLAS_CONST blasint n, OPENBLAS_CONST float *x,
 * OPENBLAS_CONST blasint incx, OPENBLAS_CONST float *y, OPENBLAS_CONST blasint
 * incy); */
float cosine_similarity_dd(const int both_size, const float *A,
                            const float *B) {
  float a2 = cblas_sdot(both_size, A, 1, A, 1);
  float b2 = cblas_sdot(both_size, B, 1, B, 1);
  float c = cblas_sdot(both_size, A, 1, B, 1);
  return c / sqrt(a2 * b2);
}

/* float cosine_similarity_ss(const int A_size, const int *A_indices, */
/*                             const float *A_values, const int B_size, */
/*                             const int *B_indices, const float *B_values, */
/*                             int *out) { */
/*   int c_size = intersection(A_indices, B_indices, A_size, B_size, out); */
/*   float c = 0.0; */
/*   for (int i = 0; i < c_size; i++) { */
/*     c += A_values[out[i]] * B_values[out[i]]; */
/*   } */
/*   float a2 = cblas_dsdot(A_size, A_values, 1, A_values, 1); */
/*   float b2 = cblas_dsdot(B_size, B_values, 1, B_values, 1); */
/*   return c / sqrt(a2 * b2); */
/* } */

float cosine_similarity_ref(const int both_size, const float *A,
                             const float *B) {
  float c = 0.0;
  for (int i = 0; i < both_size; i++) {
    c += A[i] * B[i];
  }
  float a2 = 0.0;
  for (int i = 0; i < both_size; i++) {
    a2 += A[i] * A[i];
  }
  float b2 = 0.0;
  for (int i = 0; i < both_size; i++) {
    b2 += B[i] * B[i];
  }
  return c / sqrt(a2 * b2);
}

/* int main() { */
/*   float A[6] = { 1.0, 2.0, 1.0, -3.0, 4.0, -1.0 }; */
/*   float B[6] = { 1.0, 2.0, 1.0, -3.0, 4.0, -1.0 }; */
/*   printf("ref:%lf\n", cosine_similarity_ref(6, A, B)); */
/*   printf("%lf\n", cosine_similarity_dd(6, A, B)); */
/*   return 0; */
/* } */

#ifdef __cplusplus
}
#endif
