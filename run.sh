#!/usr/bin/env bash
echo 'starte Berechnung'
./konvergence<start1A.dat
echo '1A berechnet'
./konvergence<start1B.dat
echo '1B berechnet'
./konvergence<start2A.dat
echo '2A berechnet'
./konvergence<start2B.dat
echo '2B berechnet'
./konvergence<start3A.dat
echo '3A berechnet'

