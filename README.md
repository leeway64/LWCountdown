# LWCountdown

![LWCountdown logo](docs/LWCountdown.jpg)

LWCountdown is a CLI (command-line interface) that can create multiple countdown
timers and display the time remaining.

## Installation

The easiest way to get LWCountdown is to download the pre-built binary from the
[releases](https://github.com/leeway64/LWCountdown/releases) page.

Alternatively, you can clone this repository and build the binary on your own machine. The binary
will be built into the `\out\build\x64-Debug` folder.


## Usage

The following is a brief overview on how to use LWCountdown.

```
LWCountdown: C++ CLI countdown timer
Usage: LWCountdown [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -c TEXT                     Create/update a timer
  -v TEXT                     View a timer
  -a                          View all timers
  -d TEXT                     Delete a timer
```

For more information on using LWCountdown, refer to [the usage examples](docs/usage.md).

## Third-party Tools

The following third-party tools were used in LWCountdown; they were very helpful in making
LWCountdown possible.

- [json](https://github.com/nlohmann/json) (MIT License): json is a C++ JSON library.

- [CLI11](https://github.com/CLIUtils/CLI11) (BSD-3-Clause): CLI11 provided the command line parsing.

- [CMake](https://cmake.org/) (BSD-3-Clause): CMake was used as the build system.
