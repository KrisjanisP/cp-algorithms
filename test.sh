#!/usr/bin/bash

set -e # exit on error

DIR=$(dirname "$(readlink -f "$0")")
BUILD_DIR=$DIR/build

pushd $DIR
mkdir -p $BUILD_DIR

pushd $BUILD_DIR
cmake ..
make -j4
ctest -V
popd

popd
