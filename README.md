# CMake Static Library VS Shared Library

## Introduction

This application demonstrates the difference between static library and shared library using CMake.

## Usages

### Build Docker Images

To build the custom Docker image, please run the following command.

```bash
$ docker build -f docker/cmake.Dockerfile --no-cache --tag=cmake:3.29.3 --build-arg CMAKE_VERSION=3.29.3 .
```

### Run Docker Container

To run the custom Docker container, please run the following command.

```bash
$ docker run -it --rm -v $(pwd):/mnt cmake:3.29.3
```

### Build Application

To build the application, please run the following commands.

```bash
$ cmake -B build
$ cmake --build build --config Release --parallel
```

### Run Application

To run the application, please run the following commands.

```bash
$ ./build/src/app/app_to_rectangle_shared_to_shape_shared
Area of Rectangle is 6
$ ./build/src/app/app_to_rectangle_static_to_shape_shared
Area of Rectangle is 6
$ ./build/src/app/app_to_rectangle_static_to_shape_static
Area of Rectangle is 6
$ ldd build/src/app/app_to_rectangle_shared_to_shape_shared
        linux-vdso.so.1 (0x00007fff854e2000)
        librectangle_shared_to_shape_shared.so => /mnt/build/src/rectangle/librectangle_shared_to_shape_shared.so (0x0000706733636000)
        libshape_shared.so => /mnt/build/src/shape/libshape_shared.so (0x0000706733631000)
        libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x00007067333b1000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x0000706733384000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x0000706733172000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x0000706733087000)
        /lib64/ld-linux-x86-64.so.2 (0x0000706733642000)
$ ldd build/src/app/app_to_rectangle_static_to_shape_shared
        linux-vdso.so.1 (0x00007fff7676f000)
        libshape_shared.so => /mnt/build/src/shape/libshape_shared.so (0x000075a693ab4000)
        libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x000075a693834000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x000075a693807000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x000075a6935f5000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x000075a69350c000)
        /lib64/ld-linux-x86-64.so.2 (0x000075a693ac0000)
$ ldd build/src/app/app_to_rectangle_static_to_shape_static
        linux-vdso.so.1 (0x00007ffd83ba6000)
        libstdc++.so.6 => /lib/x86_64-linux-gnu/libstdc++.so.6 (0x000072eb4da73000)
        libgcc_s.so.1 => /lib/x86_64-linux-gnu/libgcc_s.so.1 (0x000072eb4da46000)
        libc.so.6 => /lib/x86_64-linux-gnu/libc.so.6 (0x000072eb4d834000)
        libm.so.6 => /lib/x86_64-linux-gnu/libm.so.6 (0x000072eb4d74b000)
        /lib64/ld-linux-x86-64.so.2 (0x000072eb4dcfa000)
$ rm -rf build/src/rectangle/
$ ./build/src/app/app_to_rectangle_shared_to_shape_shared
./build/src/app/app_to_rectangle_shared_to_shape_shared: error while loading shared libraries: librectangle_shared_to_shape_shared.so: cannot open shared object file: No such file or directory
$ ./build/src/app/app_to_rectangle_static_to_shape_shared
Area of Rectangle is 6
$ ./build/src/app/app_to_rectangle_static_to_shape_static
Area of Rectangle is 6
$ rm -rf build/src/shape/
$ ./build/src/app/app_to_rectangle_static_to_shape_shared
./build/src/app/app_to_rectangle_static_to_shape_shared: error while loading shared libraries: libshape_shared.so: cannot open shared object file: No such file or directory
$ ./build/src/app/app_to_rectangle_static_to_shape_static
Area of Rectangle is 6
```
