#!/bin/bash

alg=( rec rec_cache tailrec iterative iterative_cache unroll )
alg_wo_rec=( rec_cache tailrec iterative iterative_cache unroll )
alg_wo_rec2=( tailrec iterative iterative_cache unroll )

echo "Creating perf stat files"
n=30
for f in "${alg[@]}"
do
    perf stat -r 4 -o build/debug/fib_"$f"_"$n".stat build/debug/fib_$f $n
    perf stat -r 4 -o build/release/fib_"$f"_"$n".stat build/release/fib_$f $n
done

n=10000
for f in "${alg_wo_rec[@]}"
do
    perf stat -r 4 -o build/debug/fib_"$f"_"$n".stat build/debug/fib_$f $n
    perf stat -r 4 -o build/release/fib_"$f"_"$n".stat build/release/fib_$f $n
done

n=1000000000
for f in "${alg_wo_rec2[@]}"
do
    perf stat -r 4 -o build/debug/fib_"$f"_"$n".stat build/debug/fib_$f $n
    perf stat -r 4 -o build/release/fib_"$f"_"$n".stat build/release/fib_$f $n
done
