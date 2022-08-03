# learn-c

> C 语言学习。学习材料为 《C 程序设计语言 第二版新版》

## 编译运行

```bash
cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM=ninja -G Ninja -S .. -B .
cmake --build . --target clean -j 8
cmake --build . --target all -j 8
```

## C 程序设计语言

* ### [导言](doc/chapter-one.md)

* ### [第二章](doc/chapter-two.md)