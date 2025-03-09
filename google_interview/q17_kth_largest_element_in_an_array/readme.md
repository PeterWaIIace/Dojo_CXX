### **14. Kth Largest Element in an Array**  
Find the Kth largest element in an unsorted array.  

📌 **Example:**  
```python
Input: nums = [3,2,1,5,6,4], k = 2  
Output: 5 
```

How to sort it:

```
{7,2,9,5,6,4}

i = 7
j = 7
p = 4

check j 7 < 4: no swap j++
check j 2 < 4: swap {2,7,9,5,6,4} i++ j++
i = 7
check j 9 < 4: no swap j++
check j 5 < 4: no swap j++
check j 6 < 4: no swap j++

{2,7,9,5,6,4} p = 4, j 6, i 7

swap(i,pivot)
{2,4,9,5,6,7}

{2,4} | {9,5,6,7}
```