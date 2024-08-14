#include "cz_datadriven_jni_JniBase.h"
#include <iostream>
#include <string>
#include <unordered_map>

static std::unordered_map<std::string, jbyteArray> map = std::unordered_map<std::string, jbyteArray>();

extern "C" {

JNIEXPORT void JNICALL Java_cz_datadriven_jni_JniBase_jniPut
  (JNIEnv *env, jobject self, jbyteArray keyBytes, jint keyLength, jbyteArray value) {

    jboolean isCopy;
    // this should be released, when removing from map, but this test does not remove elements
    void *arr = env->GetPrimitiveArrayCritical(keyBytes, &isCopy);
    const char *ptr = (const char *) arr;
    if (!isCopy) {
        env->NewGlobalRef(keyBytes);
    }
    map.insert({std::string(ptr, keyLength), (jbyteArray) env->NewGlobalRef(value)});
    env->ReleasePrimitiveArrayCritical(keyBytes, arr, 0);
}

JNIEXPORT jbyteArray JNICALL Java_cz_datadriven_jni_JniBase_jniGet
  (JNIEnv *env, jobject self, jbyteArray keyBytes, jint keyLength) {
    
    jboolean ign;    
    auto arr = env->GetPrimitiveArrayCritical(keyBytes, &ign);
    const char *ptr = (const char *) arr;
    auto it = map.find(std::string(ptr, keyLength));
    env->ReleasePrimitiveArrayCritical(keyBytes, arr, 0);
    if (it != map.end()) {
        return it->second;      
    }
    return 0;
}

} // extern "C"
