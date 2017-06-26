# Aria #

[![Build Status](https://travis-ci.org/gunhoon/aria.svg?branch=master)](https://travis-ci.org/gunhoon/aria)
[![Build status](https://ci.appveyor.com/api/projects/status/f8ml9o3x340fo4hb/branch/master?svg=true)](https://ci.appveyor.com/project/gunhoon/aria/branch/master)

Welcome to **Aria library**, C++ cross-platform core library!

**Aria** is a general purpose cross-platform library written in the C++ programming language for personal learning.

## How to build ##

**default build**
```
$ mkdir build
$ cd build

$ cmake ..
$ cmake --build .
```

**make build**
```
$ mkdir build
$ cd build

$ cmake -G "Unix Makefiles" -D CMAKE_BUILD_TYPE=Release ..
$ make
```

**MSBuild build**
```
$ mkdir build
$ cd build

$ cmake -G "Visual Studio 14 2015 Win64" ..
$ cmake --build . --config Release
```

**ninja build**
```
// The below line is for only Windows
$ "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\vcvarsall.bat" amd64

$ mkdir build
$ cd build

$ cmake -G "Ninja" -D CMAKE_BUILD_TYPE=Release ..
$ ninja
```

## How to use cpplint ##

```
$ python tools/cpplint/cpplint.py --help
$ python tools/cpplint/cpplint.py file_name
```
