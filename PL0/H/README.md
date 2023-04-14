
# <p align="center">H - Inventory Management</p>
### Description
You are responsible for the software that manages the inventory for your company. To do this, you need to quickly process three types of instructions:

Initially your shoe stand is empty, then there are two operations that can occur.
```
ADD x y    # you add `x` copies of the item with id `y` to the inventory
REM x y    # you remove `x` copies of the item `y` from the inventory
QUERY y    # you print how many items with id `y` exist in the inventory 
```
Note that, if not enough items exist in the inventory for the remove instruction you print "removal refused" and do not remove any item.
##
### Input
List of instructions, one per line, until EOF. All ids and quantities are positive integers. There are at most 500000 instructions.

##
### Output
When a query instruction appears, print the number of items available for the queried item id. For the remove instruction, if there are not enough items to remove print "removal refused".

##
### Example
#### Input:
```
ADD 10 1
ADD 5 2
REM 4 2
REM 2 2
QUERY 2
REM 2 1
QUERY 1
QUERY 3
```
##
#### Output:
```
removal refused
1
8
0
```