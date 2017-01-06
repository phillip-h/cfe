# cfe

Utility to compute continued fraction expansions

## about

`cfe` is a small utility that can be used to compute continued fraction
expansions. Right now only expansions of square roots of integers are supported,
but more might be supported in the future.

## usage

Run `make` to build. The only dependency is a compiler with C99 support. `make
clean` will clean up binaries and object files.

Once built, `cfe` can be used with the following syntax:

```
    cfe N1 N2 N3 ...
```

Each argument will be parsed as an integer and the continued fraction of its
square root will be calculated and printed.

`cfe` works with any number less than `2^64 - 1`, i.e., any number that will fit
in a `uint64_t`.

## example

```
$ cfe 0 1 2 4 5 10 14 17 20

[0]
[1]
[1; 2]
[2]
[2; 4]
[3; 6]
[3; 1, 2, 1, 6]
[4; 8]
[4; 2, 8]

```

## license 

Licensed under a 2-clause BSD licence. See `LICENSE` for more information.
