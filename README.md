happynumbers
============

There are such things as Happy numbers. Some numbers are happy, some are not.

http://en.wikipedia.org/wiki/Happy_number

I took it upon myself to write several algorithms which determine whether a number is happy or not.

This code includes the algorithms and a program to try the algorithms out on a range of numbers (typically 0-10000).

Algorithm 1 tries to check numbers without recording intermediate progress about every number in the current sequence being checked. It does not work.

Algorithm 2 records each number in the current sequence as it is generated and loops are detected by searching that map to see if a number is already in the sequence. Number visits are recorded in a map (hash).

Algorithm 3 records in a map whether a given number is happy or not. When a number is looked up, if it is in the map, the result is returned immediately. If the number is not in the map, then it is iterated until a number which is in the map is found (or 1). Once a result is found with this process, every number in the iteration is recorded in the map as happy or not. This way, every number which has ever been checked before can be looked up with a single map lookup. Given a fast map implementation it is the theoretically fastest lookup although it is memory-intensive.

Many algorithms below this point take into account the following properties:

That there is a number 163 and every number below this number produces upon iteration a number which is also below 163. Any iteration upon this number will of course also be below 163. Thus this set of numbers is a closed set where once any number within the set is seen, all further numbers will also be within the set. (property 1)

That there is another set of numbers, the set of all numbers above 99, whereupon operating on a number in this set always produces a number less than the original number. (property 2)

That given that any closed loop which contains more than one number in it must  either move to a higher number and then return to the original number or go to a lower number and then move back up to the original number any closed loop must contain at least one iteration where the result produced is greater than the input number. (property 3)

That given that all numbers 163 and above are also above 99, all numbers which are not in the closed set will produce upon interation a new number which is smaller than the previous number. (property 4)

That because of these 3 properties any number which is not in the closed set will, upon repeated iteration eventually produce a number which is within the closed set. (property 5)

That given that any closed loop which contains more than one number contains an iteration which produces a higher number than the input number at least one of the numbers in the closed loop must be in the range below 100 where an interation can produce a new number which is higher than the previous number. (property 6)

That since all numbers below 100 are in the closed set, any closed loop which contains more than one number contains a number in the closed set. (property 7)

That since no amount of iterations upon a number in the closed set can produce a number which is not in the closed set, any closed loop which contains more than one number must be entirely composed of numbers within the closed set. (property 8)

That the numbers 0 and 1 produces themselves upon iteration. And are the only numbers which produce themselves upon iteration. (property 9)

That any loop which contains the number 0 or 1 must contain only 0 or 1 as no amount of iteration upon these numbers will ever produce any other number. (property 10)

That since any loop must fall under property 10 or property 7 and the numbers 0 and 1 are within the closed set, all loops must be composed entirely of numbers within the closed set. (property 11)

Algorithm 4 uses property 11 and property 5 to reduce the number of numbers which must be recorded to only the numbers within the closed set. Any number is iterated and every number seen within the closed set is recorded. And every number checked will be recorded in a map with its final result (happiness or unhappiness) if it is within the closed set. Every recorded result is memoized. Every loop will be detected given property 11 as soon as a number within its loop is reached which has been checked before.

Algorithm 5 is the same as algorithm 4 except it also takes advantage of the fact that the size of the closed set is known. Thus results are recorded in array instead of a map. It also removes 0 and 1 as special cases by inserting them into the map as final results before the first calculation. Finally, it takes into account that you cannot leave the closed set once you enter it and you also must enter the closed set before entering a loop, including 0 or 1.

Given properties 1 to 11, there can be no more than 163 different mappings within the closed set. So the longest possible path within the closed set that terminates at 0 or 1 can be no more than 162 traversals long. In fact the longest possible traversal that leads to 0 or 1 is much shorter than this.

Algorithm 6 iterates a number, counting the number of iterations within the closed set. If after a fixed number of iterations within the closed set the number has not reached 0 or 1 it is known it will never reach 0 or 1. With this algorithm visitions of numbers need not be recorded at all. This algorithm thus uses very little memory.

Algorithm 7 iterates a number of times (including possibly 0) until it enters the closed set and then the number is iterated a fixed number of additional times. If the number does not reach 0 or 1 within this number of iterations it will not reach 0 or 1 ever. With this algorithm visitions of numbers need not be recorded at all. This algorithm thus uses very little memory.
