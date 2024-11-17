# ddos

## 用C++实现的ddos攻击

**注:请勿将此程序用于不法手段**

- 编译环境：Visual Studio 2022、CMake

- 编译语言：C17/C++17

  ## 使用方法：

  ### 自己编译:

  此程序需要用CMake生成。

  ~~关于CMake的使用网上有很多，这里就不赘述了~~这里教一下CMake的用法

  首先，到CMake官网<https://www.cmake.org>上下载CMake

  然后，打开CMake-gui，设下载下来的源代码为\${downloadFolder}(这里只是自己写的方便，**请勿在CMake-gui中填入这个**)，再`Where is sourse code`一栏中填入\${downloadFolder}，在`Where to build binaries`中填入\${downloadFolder}/build，然后先点击Configure，无脑选择Yes和Finish，再点击Generate，就能在\${downloadFolder}/build里找到VS2022的解决方案文件ddos.sln了。

  最后，用VS打开ddos.sln，右键单击解决方案，选择属性，在弹出的窗口选择单启动项目，选择"ddos",然后在VS的三个下拉框的第一个中选择Release,最后重新生成解决方案即可在\${downloadFolder}/build/ddos/Release中找到可执行文件ddos.exe。

