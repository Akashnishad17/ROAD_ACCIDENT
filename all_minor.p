set boxwidth 1.0 absolute
set style data histograms
set style fill solid 2.0 border -1
set xtics nomirror rotate by -30 offset -0.5,-1.0  
set xlabel "Name of the cities"
set ylabel "No. of minor accidents"
set yrange [0:6500]
set xrange [-1:51]
plot '2014.txt' using 8:xtic(1) title "Minor accidents in 2014",\
'2015.txt' using 8 title "Minor accidents in 2015"