Instrcutions how this analysis needs to be done:

1. First all change the dataset into tab limited text file and update the pattern according to the classes in the code.
2. Execute the ROAD_ACCIDENT_ANALYSIS CODE:
	-> You will get all the data stored in the ojects of the class.
	-> Through file handling partition the data of all the years in separate text file.
	-> You will get the total of every attribute of aggregation of all the cities in totalall text file. 
3. Use gnuplot to create the graphs applying the statistics over the partitioned text file.
	-> You will create graphs on the basis of cities year-wise.
	-> You will create graphs on the basis of years on overall level.
	-> All the graphs are histogram

Note:

1. You can run this code over g++(I used codeblocks) and make it is supported by ISO-c++11 confiurations.
	(-U__STRICT_ANSI__)-apply this in other compiler setting in case if don't execute.
2. Make sure to install gnuplot for making graphs.
3. For any graph to be plot file needs to be saved by using .p extension and to be loaded through gnuplot cmd.
4. Make sure you change the directory to where you store these files.
5. You need to execute the source code only once for creating partitions.