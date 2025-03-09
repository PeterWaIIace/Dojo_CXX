### **13. Search in Rotated Sorted Array**  
Find an element in a rotated sorted array in `O(log n)` time.  

📌 **Example:**  
```python
Input: nums = [4,5,6,7,0,1,2], target = 0  
Output: 4  
```


id it is rotated then middle can be found at the begging and at the end: [4,5,6,7,0,1,2]
```Thought process
[4,5,6,7,0,1,2]

if x == 4 return x
if x < 4
    if x == 7 return x
    [7,0,1,2]
    if x < 7
        if x == 1 return x
        [1,2]
        if x < 1
            if x == 2 return x
        else:
            if x == 1 return x
    else:
        if x == 0 return x
        [7,0]
        if x > 0:
            if x == 7 return x
```