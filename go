#!/bin/bash
set -ex

top=$(dirname $0)
cd $top
cmake -S src -B build
cd build
make -j4
./protogasm
