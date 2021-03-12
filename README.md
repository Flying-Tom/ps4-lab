# Graph Library

This is the project for Problem Solving IV in Nanjing University.

The project is to create a C++ shared library implementing graph data structure and algorithms.

## Get Started

```shell
$ git clone https://git.doowzs.com/PS4/CodeBase.git Lab
```

## Compile

On Windows, install CLion or Visual Studio and open project folder.

On Linux/macOS, install CLion or use cmake directly:

```shell
$ mkdir -p build && cd build
$ cmake -DCMAKE_BUILD_TYPE=Release ..
$ make
```

## Submit

To submit manually, remove all files except `.git` and create a zip archive of your project folder, then upload it to online judge. The archive should not exceed 10MiB in size and its content looks like:

```
XXXXXX.zip
  - Lab (any folder)
    - .git
```

or (supports after doowzs/DotOJ#4)

```
XXXXXX.zip
  - .git
```

On Linux/macOS, run `make submit TOKEN=token` or submit manually.