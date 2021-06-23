#!/bin/sh
mkdir build \
 && /bin/cd build \
 && cmake -DYAML_CPP_BUILD_TESTS=off -DYAML_CPP_BUILD_TOOLS=off .. \
 && make \
 && make test
