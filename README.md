# STDLIB2
School project - writing own simple Standard Template Library for c++.
## Building
use `make` for debug build or `make release` for release build.

Run unit tests - `make test`
Clean - `make clean`
## Usage
Build library using `make release`. 
Library is built to `build/libstd2.a` file.

Add `-I [path to library include directory] -l std2 -L [path to directory with .a file]` flags to compile with this library.