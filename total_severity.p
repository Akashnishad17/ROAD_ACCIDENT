set boxwidth 1.0 absolute
set style data histograms
set style fill solid 2.0 border -1 
set xlabel "Year"
set ylabel "Overall in all the cities"
set yrange [0:20]
set xrange [-0.5:5]
plot 'totalall.txt' using 6:xtic(1) title "Severity(%)"
