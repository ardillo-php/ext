### Build requirements

- Your operating system build essentials (Xcode/clang on macOS, build-essential on Linux, MS Visual Studio on Windows);
- PHP development headers and tools;
- Meson/Ninja build system;

For Linux builds, you will also need the GTK development headers and tools.

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
