#!/bin/bash
gcc -o matrix matrix.c
gcc -o reverse reverse.c
chmod u+x reverse
chmod u+x matrix

echo "reverse.c and matrix.c have been compiled to "reverse" and "matrix" executable programs!"
