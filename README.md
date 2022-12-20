# Book-Arrangement

Problem Description:

Boook is a librarian, and arranging books to make them look beautiful is his hobby. Boook thinks that a sequence of books is beautiful if the thickness of adjacent books differs by 1. Formally, if the thickness of the books in the sequence are x1, x2, . . . , xk, respectively, then it is beautiful if and only if |xi − xi+1| = 1 for all i = 1, 2, . . . , k − 1.
One day, Boook receives some books. More specifically, there are ci books with the thickness i, for all i = 1, 2, . . . , n. Boook would like to make them beautiful by arranging them into a beautiful sequence. However, he finds that sometimes doing so is impossible, so he wants to insert the least number of additional books with thickness also in the range [1,n] so that he can make these books beautiful. Please help Boook complete the mission.


Input:

The first line contains a positive integer n (2 ≤ n ≤ 105), which is mentioned in the description.
The second line contains n non-negative integers. The i-th integer ci (0 ≤ ci ≤ 106) represents the
number of books with thickness i Boook initially has. It is guaranteed that at least one ci is non-zero. The third contains only one integer flag (flag ∈ {0,1}), indicating whether you should print an
beautiful arrangement of the books or not.
It is guaranteed that the size of the output is less than 107 bytes.

Output:

In the first line of the output, print an integer indicating the least number of additional books Boook needs to insert. Furthermore, if flag = 1 in the input, print a beautiful arrangement of the books using the least number of additional books in the second line. If there are multiple ways to arrange the books, you may print any of them.
