package cz.datadriven.jni;

class JniBase {

  static {
    System.loadLibrary("jni");
  }

  native void jniPut(byte[] keyBytes, int length, byte[] value);
  native byte[] jniGet(byte[] bytes, int length);
}