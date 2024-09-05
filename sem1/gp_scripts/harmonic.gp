set terminal png size 800, 800
set output "plots/harmonic.png"
set xlabel "t"
set ylabel "x"
set grid
plot "data/plot2.txt" using 1:2 with linespoints title "Fs", \
"data/plot3.txt" using 1:2 with linespoints title "Fs * 5", \
"data/plot4.txt" using 1:2 with linespoints title "Fs / 2"


