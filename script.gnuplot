#!/usr/bin/env gnuplot
set xrange [0:750]    
set yrange [0:500]  
set pm3d map
set term jpeg 

print" plotting"


set output "Ergebnis1A.jpeg"
set title "Ergebnis 1A"
spl './ergebnis1A.dat' u 1:2:3 with image
print  "Ergebnis 1A"
unset output
unset title
set output "Ergebnis1B.jpeg"
set title "Ergebnis 1B"
spl 'ergebnis1B.dat' u 1:2:3 with image
print  "Ergebnis 1B"
unset output
unset title

set output "Ergebnis2A.jpeg"
set title "Ergebnis 2A"
spl 'ergebnis2A.dat' u 1:2:3 with image
print  "Ergebnis 2A"
unset output
unset title

set output "Ergebnis2B.jpeg"
set title "Ergebnis 2B"
spl 'ergebnis2B.dat' u 1:2:3 with image
print  "Ergebnis 2B"
unset output
unset title

set output "Ergebnis3A.jpeg"
set title "Ergebnis 3A"
spl 'ergebnis3A.dat' u 1:2:3 with image
print  "Ergebnis 3A"
unset output
unset title

