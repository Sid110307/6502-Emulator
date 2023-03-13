# 6502 Emulator in C++

> This is an emulator for the [6502](https://en.wikipedia.org/wiki/MOS_Technology_6502) microprocessor written in C++.

## Getting Started

### Prerequisites

- A C++20 compiler (
  e.g. [GCC](https://gcc.gnu.org/), [Clang](https://clang.llvm.org/), [MSVC](https://visualstudio.microsoft.com/))
- [CMake v3.2+](https://cmake.org/)

### Getting the Source

- Clone the repository
  ```sh
  $ git clone https://github.com/Sid110307/6502-Emulator.git
  ```

- Change directory to the repository
  ```sh
    $ cd 6502-Emulator
  ```

### Building

- Configure the project using CMake (only on the first build)
  ```sh
  $ cmake -S . -B bin
  ```

- Build the project
  ```sh
    $ cmake --build bin --target all -j4
  ```

- Run the emulator

```sh
  $ ./bin/6502
```

## Usage

- Edit between the `BEGIN Code` and `END Code` regions in [`main.cpp`](src/main.cpp) (currently you have to load machine
  code into memory manually).
  ```cpp
  // BEGIN Code
    // ...
  // END Code
  ```

- **Note:** Don't forget to change the clock cycles at the `cpu.execute()` call.
- Build and run the emulator as described [above](#building).

## License

> [MIT](https://opensource.org/licenses/MIT)
