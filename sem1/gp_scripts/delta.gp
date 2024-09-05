set terminal png size 800, 800
set output "plots/delta.png"
set xlabel "n"
set ylabel "y"
set grid
plot 'data/plot1.txt' using 1:2 with linespoints title "d(n - n0)", \
'' using 1:3 with linespoints title "u(n - n0)", \
'' using 1:4 with linespoints title "3d(n-n0) + d(n-2)", \
'' using 1:5 with linespoints title "u(n-n0) - 2u(n)"

