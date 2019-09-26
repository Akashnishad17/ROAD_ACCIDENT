set boxwidth 1.0 absolute
set style data histograms
set style fill solid 2.0 border -1 
set xlabel "Year"
set ylabel "Overall in all the cities"
set yrange [0:122000]
set xrange [-1:5]
plot 'totalall.txt' using 2:xtic(1) title "Total accidents",\
'' using 3 title "Total fatals",\
'' using 4 title "Total killed",\
'' using 5 title "Total injured",\
'' using 7 title "Total grevious accidents",\
'' using 8 title "Total minor accidents",\
'' using 9 title "Total non injurey"