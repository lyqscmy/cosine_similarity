#ifdef __cplusplus
extern "C" {
#endif

#include "cosine_similarity.h"
#include <cblas.h>
#include <math.h>

/* float dot_ss(const int m, const int *A_indices, const float *A_values, */
/*              const int n, const int *B_indices, const float *B_values) { */
/*   int i = 0, j = 0; */
/*   float result = 0.0; */
/*   while (i < m && j < n) { */
/*     if (A_indices[i] < B_indices[j]) */
/*       i++; */
/*     else if (B_indices[j] < A_indices[i]) */
/*       j++; */
/*     else { */
/*       result += A_values[i++] * B_values[j++]; */
/*     } */
/*   } */
/*   return result; */
/* } */

/* double cblas_dsdot (OPENBLAS_CONST blasint n, OPENBLAS_CONST float *x,
 * OPENBLAS_CONST blasint incx, OPENBLAS_CONST float *y, OPENBLAS_CONST blasint
 * incy); */
float cosine_similarity_dd(const int both_size, const float *A,
                           const float *B) {
  if(both_size < 1) return NAN;
  float a2 = cblas_sdot(both_size, A, 1, A, 1);
  float c = cblas_sdot(both_size, A, 1, B, 1);
  float b2 = cblas_sdot(both_size, B, 1, B, 1);
  if (a2 == 0.0 || b2 == 0.0) {
    return NAN;
  } else {
    return c / sqrt(a2 * b2);
  }
}

float cosine_similarity_dd2(const float a2, const int both_size, const float *A,
                           const float *B) {
  if(both_size < 1) return NAN;
  float b2 = cblas_sdot(both_size, B, 1, B, 1);
  float c = cblas_sdot(both_size, A, 1, B, 1);
  if (a2 == 0.0 || b2 == 0.0) {
    return 0.0;
  } else {
    return c / sqrt(a2 * b2);
  }
}

/* float cosine_similarity_ss(const int A_size, const int *A_indices, */
/*                            const float *A_values, const int B_size, */
/*                            const int *B_indices, const float *B_values) { */
/*   float c = dot_ss(A_size, A_indices, A_values, B_size, B_indices, B_values);
 */
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
