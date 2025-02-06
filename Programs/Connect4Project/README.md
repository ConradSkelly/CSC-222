# Connect4

*Now with CMake!*

## Build Steps

First, install CMake however your platform recommends.
You will also need a C++ compiler. CMake is not a compiler, just a build tool.

```shell
$ cmake --version
cmake version 3.31.5
```

## Manual Compilation

The following steps is what you typically see online, and it works.
Most people are going to be building their cmake projects this way.

```shell
$ mkdir build
$ cd build
$ cmake ../
$ make
$ ./Connect4
```

Subsequent build should then be doable with just `make`, assuming you didn't add any new sources or edit `CMakeLists`.
In those cases, re-run `cmake ../`

Alternatively, you can shorten the first four commands to just Generate and Build
```shell
$ cmake -B build
$ cmake --build build
$ ./build/Connect4
```

The first command generates the build files, the second actually performs the build.
So, similar to just running `make` when you edit a file, you can just run `cmake --build build`.

## Using VSCode

Their link does a much better job than I could
See [here](https://code.visualstudio.com/docs/cpp/cmake-linux)