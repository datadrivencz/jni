package cz.datadriven.jni;

class JniBase {

  static {
    System.loadLibrary("jni");
  }

  native void jniPut(byte[] keyBytes, int length, byte[] valueBytes, int length1);
  native String jniGet(byte[] bytes, int length);
}