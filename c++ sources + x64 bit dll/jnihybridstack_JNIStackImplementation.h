/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class jnihybridstack_JNIStackImplementation */

#ifndef _Included_jnihybridstack_JNIStackImplementation
#define _Included_jnihybridstack_JNIStackImplementation
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     jnihybridstack_JNIStackImplementation
 * Method:    init
 * Signature: ()[B
 */
JNIEXPORT jbyteArray JNICALL Java_jnihybridstack_JNIStackImplementation_init
  (JNIEnv *, jobject);

/*
 * Class:     jnihybridstack_JNIStackImplementation
 * Method:    push
 * Signature: (I[B)V
 */
JNIEXPORT void JNICALL Java_jnihybridstack_JNIStackImplementation_push
  (JNIEnv *, jobject, jint, jbyteArray);

/*
 * Class:     jnihybridstack_JNIStackImplementation
 * Method:    peek
 * Signature: ([B)I
 */
JNIEXPORT jint JNICALL Java_jnihybridstack_JNIStackImplementation_peek
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     jnihybridstack_JNIStackImplementation
 * Method:    isEmpty
 * Signature: ([B)Z
 */
JNIEXPORT jboolean JNICALL Java_jnihybridstack_JNIStackImplementation_isEmpty
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     jnihybridstack_JNIStackImplementation
 * Method:    pop
 * Signature: ([B)V
 */
JNIEXPORT void JNICALL Java_jnihybridstack_JNIStackImplementation_pop
  (JNIEnv *, jobject, jbyteArray);

/*
 * Class:     jnihybridstack_JNIStackImplementation
 * Method:    cloneBuffer
 * Signature: ([B)[B
 */
JNIEXPORT jbyteArray JNICALL Java_jnihybridstack_JNIStackImplementation_cloneBuffer
  (JNIEnv *, jobject, jbyteArray);

#ifdef __cplusplus
}
#endif
#endif
