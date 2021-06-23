#!/bin/bash

docker run -it --rm -v ${pwd}:/workdir -e CROSS_TRIPLE=x86_64-apple-darwin multiarch/crossbuild build.sh
