package com.logan.dev.ndksampleapp;

/**
 * Created by logan on 2016/06/18.
 */
public class NdkSampleApp {
    public static native String getHtml(String url);

    /**
     * invert boolean array
     * @param values boolean array
     * @return inverted boolean array
     */
    public static native boolean[] invertBooleans(boolean[] values);

    /**
     * sort the byte array
     * @param values byte array
     * @return sorted byte array
     */
    public static native byte[] sortBytes(byte[] values);

    /**
     * concatenate chars to string
     * @param values char array
     * @return String
     */
    public static native String concatCharsToString(char[] values);

    /**
     * sort the int array
     * @param values int array
     * @return sorted int array
     */
    public static native int[] sortInts(int[] values);

    /**
     * callback java static method
     */
    public static native void callJavaStaticMethod();

    /**
     * callback java method
     */    
    public static native void callJavaInstaceMethod();
    
}
