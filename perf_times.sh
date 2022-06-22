#!/bin/bash
shopt -s extglob

echo "DEBUG n = 30"
echo ""
find build/debug/*30.stat | while read f ; do printf "%-50s" $f; tail -2 $f | head -1 | awk '{print $1 * 1000, "ms"}' ; done
echo ""
echo ""

echo "DEBUG n = 10000"
echo ""
find build/debug/*10000.stat | while read f ; do printf "%-50s" $f; tail -2 $f | head -1 | awk '{print $1 * 1000, "ms"}' ; done
echo ""
echo ""

echo "DEBUG n = 1000000000"
echo ""
find build/debug/*1000000000.stat | while read f ; do printf "%-50s" $f; tail -2 $f | head -1 | awk '{print $1, "s"}' ; done
echo ""
echo ""

echo "RELEASE n = 1000000000"
echo ""
find build/release/*1000000000.stat | while read f ; do printf "%-50s" $f; tail -2 $f | head -1 | awk '{print $1, "s"}' ; done
