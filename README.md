# learn-c

> C 语言学习。学习材料为 《C 程序设计语言 第二版新版》

## 编译运行

```bash
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=ninja -G Ninja -S . -B cmake-build-debug
cmake --build cmake-build-debug --clean-first -j 8
cmake --build cmake-build-debug --clean-first --target exercise_1_9 -j 8
```

在 CMake 中，可以使用 ``--build`` 选项来控制构建过程，``--target`` 选项可以用于指定要构建的特定目标。

在使用 CMake 构建项目时，可以使用 -DCMAKE_BUILD_TYPE 选项指定构建的类型。Debug 是其中一种类型，它用于在调试时使用。

使用 -DCMAKE_BUILD_TYPE=Debug 选项构建的项目会启用调试信息，并可能关闭某些优化，使得在调试时可以更容易地进行代码分析和错误调试。相反，如果将
CMAKE_BUILD_TYPE 设置为 Release，则项目将启用优化以提高性能，但在调试时可能会更难进行代码分析和错误调试。

可以使用其他值来设置 CMAKE_BUILD_TYPE，如Release、MinSizeRel、RelWithDebInfo 等。

在使用CMake生成项目时，通过 -G 选项可以指定生成的工程文件类型，例如：makefile、Visual Studio工程等。-G Ninja 则是表示使用
Ninja 生成工具。

Ninja 是一个高效的构建系统，能够快速生成项目。在使用 -DCMAKE_MAKE_PROGRAM=ninja 后，CMake 会将生成的工程文件绑定到
Ninja，使得编译时能够直接使用 Ninja 进行构建，从而提高项目的构建速度。

* ``-S <path-to-source>``：指定 CMakeLists.txt 所在的源码目录，也就是项目的根目录。
* ```-B <path-to-build>```：指定编译目录，也就是生成 Makefile 文件和编译结果的目录。

在 CMake 中，-j 参数用于指定并行构建时使用的工作线程数量。具体来说，-j&lt;N&gt; 参数将工作线程数设置为 N，例如 -j4 将使用 4
个线程进行并行构建。

此参数可用于加速构建过程，因为它允许在多个 CPU 核心上同时构建代码，从而减少总体构建时间。但是，在选择线程数时需要权衡多个因素，例如可用
CPU 核心数量，可用内存等等。

需要注意的是，使用 -j 参数时，构建输出可能会更难读取，因为不同线程的输出可能会交错在一起。

## C 程序设计语言

* ### [导言](doc/chapter-one.md)

* ### [第二章](doc/chapter-two.md)

* ## *<font color="red">考虑到个人时间及学习效率问题，本项目练习搁置，今后应该不会更新，个人之后仅对书快速过遍知识，不对书上的习题进行练习</font>*