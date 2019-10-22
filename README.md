# Google BigQuery C++ Client Library

This repository contains the implementation of the Google BigQuery C++ client
library.

This library is currently under development and subject to breaking changes.

## Table of Contents

- [Requirements](#requirements)
  - [Compiler](#compiler)
  - [Build Tools](#build-tools)
  - [Libraries](#libraries)
- [Build](#build)
  - [Bazel](#bazel)
    - [Install Dependencies](#install-dependencies)
    - [Build](#build-1)
  - [CMake](#cmake)
    - [Install Dependencies](#install-dependencies-1)
    - [Build](#build-2)

## Requirements

> Currently, we do not have all the infrastructure set up to test a wide
range of compilers, build tool versions, and platforms. As such, the
requirements below are narrow and represent what we know works through ad hoc
testing.

#### Compiler

The Google BigQuery C++ Client is tested with the following compilers:

| Compiler    | Minimum Version |
| ----------- | --------------- |
| Clang       | 6.0.1 |

#### Build Tools

The Google BigQuery C++ Client can be built with [CMake](https://cmake.org) or
[Bazel](https://bazel.io). The minimal versions of these tools we test with are:

| Tool       | Minimum Version |
| ---------- | --------------- |
| CMake      | 3.5 |
| Bazel      | 0.29.1 |

#### Libraries

The libraries also depend on the following libraries and their dependencies. The
Google BigQuery C++ library is tested with the following versions of these
dependencies:

| Library | Minimum version |
| ------- | --------------- |
| gRPC    | v1.16.x |

## Build

### Bazel

#### Install Dependencies

To build the project using Bazel, first install Bazel by following [the
instructions](https://docs.bazel.build/versions/master/install.html) for your
platform.

#### Build

To build all targets using Bazel, run the following command after cloning this
repo:

```bash
bazel build ...
```

The executables can be found in the `bazel-bin/` directory.

To run all tests, run the following command:

```bash
bazel test ...
```

### CMake

#### Install Dependencies

##### Ubuntu (18.04 - Bionic Beaver)

```bash
sudo apt update && \
sudo apt install -y build-essential cmake git gcc g++ cmake \
        libc-ares-dev libc-ares2 libcurl4-openssl-dev libssl-dev make \
        pkg-config tar wget zlib1g-dev
```

#### Build

To build all available libraries and run the tests, run the following commands
after cloning this repo:

##### Linux

To automatically download the dependencies and compile the libraries and
examples you can use the CMake [super build][super-build-link]:

[super-build-link]: https://blog.kitware.com/cmake-superbuilds-git-submodules/

```bash
# Add -DBUILD_TESTING=OFF to disable tests
cmake -Hsuper -Bcmake-out

# Adjust the number of threads used by modifying parameter for `-j 4`
# following command will also invoke ctest at the end
cmake --build cmake-out -- -j 4
```

You will find compiled binaries in `cmake-out/` respective to their source
paths.
