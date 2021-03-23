# Sort-Search-Time
Sorting and searching methods
The use of ordered vectors is quite intense in computing. These vectors form a more efficient basis for search methods, as in the case of binary search. In this sense, in this project you must write a program to search for elements of a given vector A in another vector B, using the techniques listed below and measuring the time required in each one.

To be clearer, your program must search, within the vector B, for each of the elements of the vector A, counting how many of them were found (this result should be shown on the screen). For each execution your program must ask which technique will be used and measure the application of that technique. The times presented as a response must be the average of 5 executions of each technique.

In all tests, vector A will have a total of 2000 integers and vector B will have a total of 200 thousand integers.

The techniques to be measured, including the time to do the ordering when applicable, are:

1 -> Sequential search with disordered vector B.
2 -> Search sequentially with vector B ordered by the bubble sort.
3 -> Binary search with vector B ordered by bubble sort.
4 -> Weighed search with vector B ordered by bubble sort.
5 -> Sequential search with vector B ordered by insertion sort.
6 -> Binary search with vector B ordered by insertion sort.
7 -> Weighted search with vector B ordered by insertion sort.
8 -> Sequential search with vector B ordered by selection sort.
9 -> Binary search with vector B ordered by selection sort.
10 -> Weighed search with vector B ordered by selection sort.
