# <p align="center">(Un)social network</p>
### Description
Nowadays, everybody knows many, many people. So much so, that the producers of a TV game show are finding it increasingly difficult to find enough people to take part in their show. Given a set of members of a social network, they want to know the size of the largest group of people such that none of its members know one another.

<img src=https://i.imgur.com/hNVG4aS.jpg/>

##
### Input
For each test case, the number of members, n, and the number of connections between members, m, are given in the first line, separated by white space. Then, in each of the next m lines, a pair of values, also separated by white space, indicates that two members of the network know each other. Members are numbered from 0 to n-1. Note that some members may not know anyone in the network.
##
### Output
The output for each test case consists of a single line with the maximum size of a group of members who do not know one another.
##
### Example
#### Input 1:
```
6 6
0 1
0 2
0 3
0 4
0 5
1 5
```
#### Input 2:
```
30 21
15 10
6 25
12 20
17 20
20 11
18 4
1 19
5 22
14 4
24 13
7 8
21 24
24 8
11 18
20 19
0 16
28 13
16 10
27 24
22 16
16 21
```
#### Output 1:
```
4
```
#### Output 2:
```
19
```