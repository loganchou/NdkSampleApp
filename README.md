NDK sample project

#How to create and build jni with NDK on Android Studio 
1. use [command+,] to open Preferences，than select External Tools
2. add javah, ndk-build, ndk-build clean as External Tools
  - Configure javah
  
    name: javah
    options: select all
    Show in: select all
    Program: $JDKPath$/bin/javah
    Paramaters: -classpath $Calsspath$ -v -jin $FileClass$
    Working directory: $SourcepathEntry$/../jin

  - Configure ndk-build
  
    name: ndk-build
    options: select all
    Show in: select all
    Program: /home/logan/Android/Sdk/ndk-bundle/ndk-build
    Paramaters: 
    Working directory: $ProjectFileDir$/app/src/main

  - Configure ndk-build clean
    name: ndk-build clean
    options: select all
    Show in: select all
    Program: /home/logan/Android/Sdk/ndk-bundle/ndk-build
    Paramaters: clean
    Working directory: $ProjectFileDir$/app/src/main

3. Configure build.gradle
  ``` 
  android {
    ...
    defaultConfig {
      ...
      ndk {
        moduleName "your dllname"
      }
  
      sourceSets.main {
        jni.srcDirs = []
        jniLibs.srcDir "src/main/libs"
      }
      ...
    }
    ...
    ```
  }

4. add one line in 'gradle.properties'
  ```
  android.useDeprecatedNdk=true
  ```
    
5. Create some MakeFiles
  - Application.mk
    ```
    APP_MODULES := YourLibrary
    APP_ABI := all
    ```
    
  - Android.mk
    ```
    LOCAL_PATH := $(call my-dir)
    include $(CLEAR_VARS)
    LOCAL_MODULE := YourLibrary
    LOCAL_SRC_FILES =: YourLibrary.cpp
    include $(BUILD_SHARED_LIBRARY)
    ```
 
 
