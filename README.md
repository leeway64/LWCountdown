# LWCountdown
![LWCountdown logo](docs/images/LWCountdown_Excalidraw.svg)

LWCountdown is a CLI (command-line interface) that can create multiple countdown
timers and display the time remaining.


## Installation
```shell
git clone https://github.com/leeway64/LWCountdown.git
cd LWCountdown
cmake -DCMAKE_BUILD_TYPE=Release -DCMAKE_MAKE_PROGRAM=ninja -G Ninja -S . -B ./cmake-build-release
cmake --build ./cmake-build-release --target LWCountdown
```
The LWCountdown binary will be built into the [`bin`](bin) folder.

Refer to [this page](docs/cmake_basics.mediawiki) for more information on how CMake works.


## Usage
The following is a brief overview on how to use LWCountdown.

```text
LWCountdown: C++ CLI countdown timer
Usage: LWCountdown [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -c TEXT                     Create/update a timer
  -v TEXT                     View a timer
  -a                          View all timers
  -d TEXT                     Delete a timer
```

For more information on using LWCountdown, refer to [the usage examples](docs/README.md).


## Third-party Tools
- [json](https://github.com/nlohmann/json) (MIT License): C++ JSON library.
- [CLI11](https://github.com/CLIUtils/CLI11) (BSD-3-Clause): Command-line parsing.
- [CMake](https://cmake.org/) (BSD-3-Clause): Build system generator.
- [Excalidraw](https://github.com/excalidraw/excalidraw) (MIT License): Tool for creating diagrams
  in a hand-drawn style. Used to create the LWCountdown logo. Check out the
  [online Excalidraw editor](https://excalidraw.com/).
