happynumbers
============

There are such things as Happy numbers. Some numbers are happy, some are not.

http://en.wikipedia.org/wiki/Happy_number

I took it upon myself to write several algorithms which determine whether a number is happy or not.

This code includes the algorithms and a program to try the algorithms out on a range of numbers (typically 0-10000).

Algorithm 1 tries to check numbers without recording intermediate progress about every number in the current sequence being checked. It does not work.
Algorithm 2 records each number in the current sequence as it is generated and loops are detected by searching that map to see if a number is already in the sequence.
Algorithm 3 records in a map whether a given number is happy or not. When a number is looked up, if it is in the map, the result is returned immediately. If the number is not in the map, then it is iterated until a number which is in the map is found (or 1). Once a result is found with this process, every number in the iteration is recorded in the map as happy or not. This way, every number which has ever been checked before can be looked up with a single map lookup. Given a fast map implementation it is the theoretically fastest lookup although it is memory-intensive.
