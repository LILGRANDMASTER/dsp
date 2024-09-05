set terminal png size 800, 800
set output "plots/noize.png"
set xlabel "t"
set ylabel "x"
set grid
plot "data/plot5.txt" using 1:2 with lines title "signal with noize"

