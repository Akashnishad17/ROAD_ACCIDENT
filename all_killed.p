set boxwidth 1.0 absolute
set style data histograms
set style fill solid 2.0 border -1
set xtics nomirror rotate by -30 offset -0.5,-1.0  
set xlabel "Name of the cities"
set ylabel "Total no. of killed"
set yrange [0:2500]
set xrange [-1:51]
plot '2011.txt' using 4:xtic(1) title "Total killed in 2011",\
'2012.txt' using 4 title "Total killed in 2012",\
'2013.txt' using 4 title "Total killed in 2013",\
'2014.txt' using 4 title "Total killed in 2014",\
'2015.txt' using 4 title "Total killed in 2015"