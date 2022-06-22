#!/bin/bash
shopt -s extglob

find build/*/CMakeFiles/lib*dir/src/*.c.o | while read f; do  ls -lh $f | awk '{print $5,$9 }' ; done
