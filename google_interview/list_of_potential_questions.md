
## **1. Arrays & Strings**  

### **1. Two Sum**  
Find two numbers in an array that add up to a given target.  

📌 **Example:**  
```python
Input: nums = [2, 7, 11, 15], target = 9  
Output: [0, 1]  # Because nums[0] + nums[1] = 2 + 7 = 9
```

---

### **2. Longest Substring Without Repeating Characters**  
Find the length of the longest substring without repeating characters.  

📌 **Example:**  
```python
Input: s = "abcabcbb"  
Output: 3  # ("abc")
```

---

### **3. Merge Intervals**  
Given a list of intervals, merge overlapping ones.  

📌 **Example:**  
```python
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]  
Output: [[1,6],[8,10],[15,18]]  
```

---

### **4. Product of Array Except Self**  
Return an array where each element is the product of all elements except itself, without using division.  

📌 **Example:**  
```python
Input: nums = [1,2,3,4]  
Output: [24,12,8,6]  
```

---

## **2. Linked Lists**  

### **5. Reverse a Linked List**  
Reverse a given singly linked list.  

📌 **Example:**  
```python
Input: 1 → 2 → 3 → 4 → 5  
Output: 5 → 4 → 3 → 2 → 1  
```

---

### **6. Detect Cycle in a Linked List**  
Detect if a linked list has a cycle using Floyd’s cycle detection algorithm.  

📌 **Example:**  
```python
Input: head = [3,2,0,-4] with a cycle at position 1  
Output: True  
```

---

## **3. Trees & Graphs**  

### **7. Binary Tree Level Order Traversal**  
Return a list of values level by level from a binary tree.  

📌 **Example:**  
```python
Input: 
    3
   / \
  9  20
    /  \
   15   7
Output: [[3],[9,20],[15,7]]  
```

---

### **8. Number of Islands**  
Find the number of islands (connected 1s) in a 2D grid.  

📌 **Example:**  
```python
Input: grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]  
Output: 3  
```

---

## **4. Recursion & Backtracking**  

### **9. Generate Parentheses**  
Generate all valid parentheses combinations given `n` pairs.  

📌 **Example:**  
```python
Input: n = 3  
Output: ["((()))","(()())","(())()","()(())","()()()"]  
```

---

### **10. Word Search**  
Find if a given word exists in a 2D board of letters.  

📌 **Example:**  
```python
Input: board = [
  ['A','B','C','E'],
  ['S','F','C','S'],
  ['A','D','E','E']
], word = "ABCCED"  
Output: True  
```

---

## **5. Dynamic Programming**  

### **11. Climbing Stairs**  
Find ways to climb a staircase with `n` steps, taking 1 or 2 steps at a time.  

📌 **Example:**  
```python
Input: n = 3  
Output: 3  # (1+1+1, 1+2, 2+1)
```

---

### **12. Longest Increasing Subsequence**  
Find the length of the longest increasing subsequence in an array.  

📌 **Example:**  
```python
Input: nums = [10,9,2,5,3,7,101,18]  
Output: 4  # [2,3,7,101]  
```

---

## **6. Sorting & Searching**  

### **13. Search in Rotated Sorted Array**  
Find an element in a rotated sorted array in `O(log n)` time.  

📌 **Example:**  
```python
Input: nums = [4,5,6,7,0,1,2], target = 0  
Output: 4  
```

---

### **14. Kth Largest Element in an Array**  
Find the Kth largest element in an unsorted array.  

📌 **Example:**  
```python
Input: nums = [3,2,1,5,6,4], k = 2  
Output: 5  
```

---

## **7. Bit Manipulation**  

### **15. Single Number**  
Find the element that appears once in an array where every other element appears twice.  

📌 **Example:**  
```python
Input: nums = [4,1,2,1,2]  
Output: 4  
```

---

## **8. System Design (For L4 Candidates)**  

### **16. Design a URL Shortener (like Bit.ly)**  
**Problem:** Design a system that takes a long URL and returns a shortened URL.  

📌 **Requirements:**  
- Generate unique short URLs  
- Handle billions of URLs efficiently  
- Support redirection  

---

### **17. Design a Cache System (LRU Cache)**  
**Problem:** Implement an LRU (Least Recently Used) Cache with `O(1)` operations for `get()` and `put()`.  

📌 **Example:**  
```python
Input:
LRUCache(2)
put(1, 1)
put(2, 2)
get(1)    # returns 1
put(3, 3) # evicts key 2
get(2)    # returns -1 (not found)
```

---

### **18. Design Google Drive (File Storage System)**  
**Problem:**  
- Support file uploads and downloads  
- Handle user permissions  
- Efficiently store and retrieve large files  

---

## **Final Notes**
This list covers **Google L3/L4 coding questions** with **descriptions and examples**. Let me know if you need **solutions, explanations, or a practice plan**! 🚀

~ by chatGPT