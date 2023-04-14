
# <p align="center">G - Bowling shoes</p>
### Description
You manage a bowling alleys' shoe lending facility. When a customer arrives, they ask for a given shoe size. If you have a pair of shoes in that size, you lend them those shoes, if not you lend a pair of shoes that have a greater size but that are the closest to that customer's ideal size. For example, if they ask for 40, but you only have 39, 42, and 44. You lend the shoes with size 42. If no such shoes are available in a greater size you turn the customer down.

Initially your shoe stand is empty, then there are two operations that can occur.
```
ADD x      # you add a pair of shoes of size x (int) into your stand
REQUEST y  # service a customer's request for a pair of shoes of size y (int)
```
When you receive a request, you need to service it following what was described above, and print either the size that you gave to the customer, or print "impossible" if no feasible size was available. Note that, if you service a request the shoes of that that size leaves your stand.
##
### Input
List of instructions, one per line, until EOF. All sizes are positive integers. There are at most 200000 instructions.
##
### Output
Each time a request comes in print an integer denoting the size of the pair of shoes you lent, or "impossible" if it was not possible to service the request.

##
### Example
#### Input:
```
ADD 30
ADD 50
ADD 50
REQUEST 50
ADD 40
REQUEST 35
REQUEST 33
REQUEST 32
ADD 10
```
##
#### Output:
```
50
40
50
impossible
```
#### Explanation:
```
Available sizes after instruction #1: [30]
Available sizes after instruction #2: [30,50]
Available sizes after instruction #3: [30,50,50]
Available sizes after instruction #4: [30,50]
Available sizes after instruction #5: [30,40,50]
Available sizes after instruction #6: [30,50]
Available sizes after instruction #7: [30]
Available sizes after instruction #8: [30]
Available sizes after instruction #9: [10,30]
```