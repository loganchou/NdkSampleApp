package com.logan.dev.ndksampleapp;

/**
 * Created by logan on 2016/06/21.
 */
public class CallbackMethod {

  private static void callbackStaticMethod(String str, int i) {
      System.out.format("CallbackMethod::callbackStaticMethod called!-->str=%s," + " i=%d\n", str, i);
  }

  private void callbackInstanceMethod(String str, int i) {
      System.out.format("CallbackMethod::callbackInstanceMethod called!-->str=%s, " + "i=%d\n", str, i);
  }

}
