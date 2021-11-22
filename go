#!/bin/bash
set -ex

cd ~/src/a
cmake -S src -B build
cd build
make
./protogasm
