test -e googletest || ./build_googletest.sh

autoreconf -ifv && \
./configure --enable-gtest=gtest/googletest-release-1.8.1/googletest && \
make &&
make check

