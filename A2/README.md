
(b) (8 points) Port to C. Port this benchmark to C, as closely as possible to the Python version. You may use any standard library functions. Repeat the above measurements and create a new graph that adds the C line to the Python line.
You may find that you can run many more iterations now, and perhaps larger object counts. Explain any parameter changes you make and demonstrate how it’s better (or worse) than before.
To time a function in C, you can use clock gettime (with the CLOCK MONOTONIC argument). Since you’re using a different random number generator now, you’ll probably have different initial values and therefore a different checksum than the Python version. That’s fine, as long as you’re getting the same checksum from run to run.
(c) (3 points) Comparing Types. Compare your C implementation using different C types: float, double, int8 t, int16 t, int32 t, int64 t for the coordinate and velocity types in terms of performance. Report your findings.
Note: the checksum will probably not be computed correctly for the integral types due to precision loss. That’s OK, though: we’re only interested in the performance trade-offs.


a)
```sh
~/CLionProjects/CS389/A2 Galaxy Explorers master*
❯ python update_locations.py 28 10000
Mean time per coordinate: 0.12339687507067408us
Final checksum is: -59738.67132790007
svmem(total=34359738368, available=6738526208, percent=80.4, used=9497919488, free=61964288, active=6688178176, inactive=6647365632, wired=2809741312)

~/CLionProjects/CS389/A2 Galaxy Explorers master*
❯ python update_locations.py 56 10000
Mean time per coordinate: 0.12664404826604628us
Final checksum is: 41070.751767567046
svmem(total=34359738368, available=6726434816, percent=80.4, used=9537470464, free=62177280, active=6677823488, inactive=6653804544, wired=2859646976)

~/CLionProjects/CS389/A2 Galaxy Explorers master*
❯ python update_locations.py 112 10000
Mean time per coordinate: 0.11798493303233824us
Final checksum is: 115118.04266155532
svmem(total=34359738368, available=6720290816, percent=80.4, used=9512747008, free=80510976, active=6656704512, inactive=6626131968, wired=2856042496)

~/CLionProjects/CS389/A2 Galaxy Explorers master*
❯ python update_locations.py 224 10000
Mean time per coordinate: 0.11522377231553296us
Final checksum is: -36624.59717058417
svmem(total=34359738368, available=6732349440, percent=80.4, used=9509666816, free=65175552, active=6681853952, inactive=6650560512, wired=2827812864)
```

# TODO 
KO CMAKE )))): makefile ONLY
make sure i have the "clean" command and all that other bullshit





a) I used 28,56,112,224 as my object count parameters as suggested by the instructions. 

I chose 10,000 as iterations/game turns parameter as I needed a high enough number to rule out statistical noise and that was the number that started to add a noticable lag when running the program.



![python.png](python.png)

b)

This time with a logarithmic y-axis. I kept parameters fixed for a proper comparison. The C++ code is 3-4x orders of magnitude faster.

![pythonc.png](pythonc.png)