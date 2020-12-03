# Eight_Queens_Puzzle

The eight queens puzzle is the problem of placing eight chess queens on an 8×8 chessboard so that no two queens threaten each other; thus, a solution requires that no two queens share the same row, column, or diagonal.

The algorithm arranges the queens pre-placed on the 8x8 chessboard according to the rule and gives you the result of the game with the action steps.
The result is found with the **"heuristic repair method"** approach.
Take the following pattern is an example:
```
Queens            => 9  
Available regions => 0
```
``` 
0   0   0   0   0   9   0   0  
0   9   0   0   0   0   0   0  
0   0   0   0   9   0   0   0  
9   0   0   0   0   0   0   0  
0   0   0   9   0   0   0   0  
0   0   0   0   0   0   9   0  
0   0   9   0   0   0   0   0  
0   0   0   0   0   0   0   9  
```
In the matrix, queens are represented by 9, and appropriate regions with 0. According to this input value, the result will be found as follows.

```
0   0   0   9   0   0   0   0  
0   9   0   0   0   0   0   0  
0   0   0   0   9   0   0   0  
0   0   0   0   0   0   0   9  
0   0   0   0   0   9   0   0  
9   0   0   0   0   0   0   0  
0   0   9   0   0   0   0   0  
0   0   0   0   0   0   9   0  
```

Finally, before running the algorithm, make sure that the queens must be expressed in the same row and column without intersection.