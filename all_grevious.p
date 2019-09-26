set boxwidth 1.0 absolute
set style data histograms
set style fill solid 2.0 border -1
set xtics nomirror rotate by -30 offset -0.5,-1.0  
set xlabel "Name of the cities"
set ylabel "No. of greviously injured"
set yrange [0:3000]
set xrange [-1:51]
plot '2014.txt' using 7:xtic(1) title "Greviously injured in 2014",\
'2015.txt' using 7 title "Greviously injured in 2015"