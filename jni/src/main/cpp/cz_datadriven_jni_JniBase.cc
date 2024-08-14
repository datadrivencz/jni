#include "cz_datadriven_jni_JniBase.h"

extern "C" {
/*
 * Class:     cz_datadriven_jni_JniBase
 * Method:    jniPut
 * Signature: ([BI[BI)V
 */
JNIEXPORT void JNICALL Java_cz_datadriven_jni_JniBase_jniPut
  (JNIEnv *env, jobject self, jbyteArray keyBytes, jint keyLength, jbyteArray valueBytes, jint valueLength) {

}

/*
 * Class:     cz_datadriven_jni_JniBase
 * Method:    jniGet
 * Signature: ([BI)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_cz_datadriven_jni_JniBase_jniGet
  (JNIEnv *env, jobject self, jbyteArray keyBytes, jint keyLength) {

  return 0;
}

} // extern "C"
