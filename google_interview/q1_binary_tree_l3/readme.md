Maximum Path Leaf Nodes in a Binary Tree

Difficulty: Medium
Problem Statement

Given the root of a binary tree, return a list of all leaf nodes where the value of the leaf node is the maximum value encountered along the path from the root to that leaf.
Example 1:

Input:
```
       4
      / \
     2   5
    / \    \
   1   3    6
```
Output: [6]
Explanation: The path to leaf node 6 encounters the maximum value 6.
Example 2:

Input:
```
       3
      / \
     1   4
        / \
       1   5
```
Output: [5]
Explanation: The path to leaf node 5 encounters the maximum value 5.
Constraints:
```
    The number of nodes in the tree is in the range [1, 10⁵].
    -10⁴ ≤ Node.val ≤ 10⁴
```
Follow-up:
```
    Can you solve this problem efficiently in O(n) time complexity?
```
Hints:
```
    Perform a preorder traversal (DFS) while keeping track of the maximum value encountered along the path.
    If the current node is a leaf, compare its value with the max encountered so far and store it accordingly.
```