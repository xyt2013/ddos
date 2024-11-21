# ddos

## 用C++实现的ddos攻击

**注:请勿将此程序用于不法手段**

- 编译环境：Visual Studio 2022、CMake

- 编译语言：C17/C++17

## 使用方法：

### 自己编译:

此程序需要用CMake生成。

~~关于CMake的使用网上有很多，这里就不赘述了~~这里教一下CMake的用法

#### Windows

  首先，到CMake官网<https://www.cmake.org>上下载CMake

  然后，打开CMake-gui，设下载下来的源代码目录(...\\ddos\\ddos)为\${downloadFolder}(这里只是自己写的方便，**请勿在CMake-gui中填入这个**)，再`Where is source code`一栏中填入\${downloadFolder}，在`Where to build binaries`中填入\${downloadFolder}/build，然后先点击Configure，无脑选择Yes和Finish，再点击Generate，就能在\${downloadFolder}/build里找到VS2022的解决方案文件ddos.sln了。

  最后，用VS打开ddos.sln，右键单击解决方案，选择属性，在弹出的窗口选择单启动项目，选择"ddos",然后在VS的四个下拉框的第一个中选择Release,最后重新生成解决方案即可在\${downloadFolder}/build/ddos/Release中找到可执行文件ddos.exe。

#### Linux
  在bash中输入
  ```bash
  sudo apt install cmake
  ```

 然后，cd到源代码目录，输入`cmake .`，接着输入`make`，最后就直接运行ddos文件即可。
```bash
.\ddos
```
### 使用已编译的发行版
#### 目前仅支持Windows，Linux请自己编译（也没多麻烦）
  在<https://www.github.com/xyt2013/ddos/release>或<https://gitcode.com/xie_yuting/ddos/releases>中下载ddos-win32-XXXX.zip，解压，然后用VS打开ddos.sln并生成解决方案即可。
### 使用效果图
#### 未攻击时:
![](https://www.helloimg.com/i/2024/11/21/673ec66394e77.jpeg)
#### 攻击时:
![](https://www.helloimg.com/i/2024/11/21/673ec663c6963.jpeg)
