
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