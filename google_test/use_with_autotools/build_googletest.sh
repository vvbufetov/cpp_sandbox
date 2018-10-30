#!/bin/bash

set -e

test -e gtest && exit 0

mkdir gtest
cd gtest
wget "https://github.com/google/googletest/archive/release-1.8.1.tar.gz"
tar -xzf release-1.8.1.tar.gz 
cd googletest-release-1.8.1/
autoreconf -ifv
./configure
make
