#ifndef lyq_cosine_similarity
#define lyq_cosine_similarity
#ifdef __cplusplus
extern "C" {
#endif

#include <cblas.h>

inline float dot(const int both_size, const float *A, const float *B){
  return cblas_sdot(both_size, A, 1, B, 1);
}

/* size(A) >= both_size and size(B) >= both_size */
float cosine_similarity_dd(const int both_size, const float *A, const float *B);

/* A_size <= B_size */
float cosine_similarity_ss(const int A_size, const int *A_indices,
                           const float *A_values, const int B_size,
                           const int *B_indices, const float *B_values,
                           const int *out);

float cosine_similarity_ref(const int both_size, const float *A,
                            const float *B);
#ifdef __cplusplus
}
#endif
#endif
