# ALGORITHM AND DESIGN CHOICES
> A modifed Mergesort is used for this 
> First the function - calculate average is used to find a reasonable partition point. 
> All numbers smaller than the calculated average is pushed into stack B. It is pushed into stack B in a sorted manner (ie. stack b would be arranged from biggest -> smallest at the end of it).
> This is done recursively until  Stack A is sorted (from smallet -> biggest) OR only two numbers remain in Stack A. 
> After which all the numbers would be pushed from stack B back to A. 

#Functions 
> calculate average to find a reasonable partition point 
> rotate_B : which re-arranges stack B so the new number can be placed at the right point // smallest at the top 
> check_A: which checks if A is sorted. it accounts for if A is sorted with rotations, and returns the rotations to be done if able.
> push to b: checks top and bottom of A to push to B if smaller than calculated partition. if top and bottom is greater, go next > ie. to do it with the least rotation
> rotate list: rotates and returns the new list state.  

#data structures 
> a state to hold the current Stack A and Stack B
> a state to hold the current list of moves done. 



#steps involved 
1. The input is validated 
2. The input is sorted in place using quicksort algorithim. It is then converted to its rank, where 0 is the smallest of the lot. and the numbers only go from 0 - length - 1
--> initialize snapshot 
3. The average is calculated to find a reasonable partition point. We aim for half of the length into B


