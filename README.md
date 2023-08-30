### Build requirements

- Your operating system build essentials (Xcode/clang on macOS, build-essential on Linux, MS Visual Studio 2019 on Windows);
- PHP development headers and tools;
- Meson/Ninja build system;

For Linux builds, you will also need the GTK development headers and tools.

### Build and install using PECL

Please note this method is currently available just for Linux and macOS.

```sh
pecl install https://github.com/ardillo-php/ext ... ardillo.tgz
```

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
