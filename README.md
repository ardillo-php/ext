## Ardillo PHP Extension

[![CI Status](https://github.com/ardillo-php/ext/workflows/CI/badge.svg)](https://github.com/ardillo-php/ext/actions/workflows/ci.yaml)
[![License](https://img.shields.io/badge/license-MIT-blue)](LICENSE)

The Ardillo extension provides an object-oriented PHP interface to the [libui-ng](https://github.com/libui-ng/libui-ng) library as well as routines for implementing a [ReactPHP event loop](https://github.com/ardillo-php/loop). The end goal is to provide a framework for developing cross-platform desktop applications in PHP, as seen in our [examples](https://github.com/ardillo-php/examples).

Please head to [ardillo.dev](https://ardillo.dev) for documentation.

### Build requirements

- Your operating system build essentials (Xcode/clang on macOS, build-essential on Linux, MS Visual Studio 2019 on Windows);
- PHP development headers and tools;
- Meson/Ninja build system;

For Linux builds, you will also need the GTK development headers.

### Build and install using PECL

Please note this method is currently available just for Linux and macOS.

Download the [latest extension package](https://github.com/ardillo-php/ext/releases/download/x0.1.0/ardillo-0.1.0.tgz) manually or via curl:

```sh
curl -s -L https://github.com/ardillo-php/ext/releases/download/x0.1.0/ardillo-0.1.0.tgz -o ardillo.tgz
```

Then install it using PECL:

```sh
sudo pecl install ardillo.tgz
```

The Ardillo extension has yet to be published on the PECL repository.

### Build from source

After cloning the repository, you will need to initialize the submodule then you can proceed to build the extension.

On unices, you can use the following commands:

```sh
git submodule update --init
phpize
./configure
make -j
sudo make install
```

On Windows, you should use the following commands:

```sh
git submodule update --init
cd libui-ng
meson setup build --default-library=shared
ninja -C build
cd ..
phpize
configure
nmake
nmake install
```

Since libui-ng is presently built as a shared library, you might want to copy the libui.dll file (`libui-ng\build\meson-out\libui.dll`) to a directory reachable by your Ardillo applications.

### License

The Ardillo extension is licensed under the [MIT license](LICENSE).

### Acknowledgements

The Ardillo extension is based on the [libui-ng](https://github.com/libui-ng/libui-ng) library, which is licensed under the [MIT license](https://github.com/libui-ng/libui-ng/blob/master/LICENSE.md).

The Windows I/O implementation is based on the [wepool](https://github.com/piscisaureus/wepoll) library, which is licensed under the [BSD 2-Clause license](https://github.com/piscisaureus/wepoll/blob/dist/LICENSE).

### Contributing

Bug reports (and small patches) can be submitted via the [issue tracker](https://github.com/ardillo-php/ext/issues). Forking the repository and submitting a Pull Request is preferred for substantial patches. Please be sure to read and comply with the [Contributing Terms](CONTRIBUTING.md) document before proceeding.
