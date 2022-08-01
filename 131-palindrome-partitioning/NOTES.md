Let's see the thought process and the flow of the loop.
The indices should be cumulatively like:
(0), (1), (2),  (3) --> loop from 0 to n - 1
(0, 1), 2, 3 --> loop from 1 to n - 1 (substring from 0th idx to 1st index is taken in)
(0, 1, 2), 3 -- > 2 to n - 1 (substring from 0 to 2nd index is taken in)
(0, 1, 2, 3) ---> so on
​
String = "aabb"
​
Start idx from 0:
a | a | b | b --> idx: 0, 1, 2, 3 (individually)
aa | b | b --> idx: (0, 1) , 2, 3
aab | b --> NOT POSSIBLE --> Skip
aabb --> NOT POSSIBLE
​
​
Now, take in cumulatively:
Start index from 1 now:
aa | b | b
aab | b --> X
aabb --> X
​
Start index from 2 and so on...