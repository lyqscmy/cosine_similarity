#include "./CosineSimilarity.h"
#include "./cosine_similarity.h"
#include <math.h>

/*
 * Class:     CosineSimilarity
 * Method:    dd
 * Signature: ([F[F)F
 */
JNIEXPORT jfloat JNICALL
Java_com_vivo_ai_service_process_CosineSimilarity_dd___3F_3F(
    JNIEnv *jenv, jclass jcls, jfloatArray jAarray, jfloatArray jBarray) {
  float *A = (float *)(*jenv)->GetPrimitiveArrayCritical(jenv, jAarray, 0);
  float *B = (float *)(*jenv)->GetPrimitiveArrayCritical(jenv, jBarray, 0);
  const int len = (const int)(*jenv)->GetArrayLength(jenv, jAarray);
  /* We need to check in case the VM tried to make a copy. */
  jfloat result = NAN;
  if (A != NULL && B != NULL) {
    result = cosine_similarity_dd(len, A, B);
  }
  (*jenv)->ReleasePrimitiveArrayCritical(jenv, jAarray, A, JNI_ABORT);
  (*jenv)->ReleasePrimitiveArrayCritical(jenv, jBarray, B, JNI_ABORT);
  return result;
}

/*
 * Class:     CosineSimilarity
 * Method:    dd
 * Signature: (F[F[F)F
 */
JNIEXPORT jfloat JNICALL
Java_com_vivo_ai_service_process_CosineSimilarity_dd__F_3F_3F(
    JNIEnv *jenv, jclass jcls, jfloat ja2, jfloatArray jAarray,
    jfloatArray jBarray) {
  float *A = (float *)(*jenv)->GetPrimitiveArrayCritical(jenv, jAarray, 0);
  float *B = (float *)(*jenv)->GetPrimitiveArrayCritical(jenv, jBarray, 0);
  const int len = (const int)(*jenv)->GetArrayLength(jenv, jAarray);
  /* We need to check in case the VM tried to make a copy. */
  jfloat result = NAN;
  if (A != NULL && B != NULL) {
    result = cosine_similarity_dd2((const float)ja2, len, A, B);
  }
  (*jenv)->ReleasePrimitiveArrayCritical(jenv, jAarray, A, JNI_ABORT);
  (*jenv)->ReleasePrimitiveArrayCritical(jenv, jBarray, B, JNI_ABORT);
  return result;
}
