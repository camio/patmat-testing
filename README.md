# `patmat-testing`

**PURPOSE:** Provide tests that verify pattern matching features of C++.

## Build

This is a standard CMake build. It is assumed you have a compiler that supports
`-fpattern-matching`. Here is a sample cmake invocation:

```bash
env CXX=$HOME/build/llvm-patmat/bin/clang++ \
  cmake -G Ninja -DCMAKE_BUILD_TYPE=Debug ~/code/patmat-testing
```

## Run

`ctest` can be used to execute the tests.
