#include <map>
#include <vector>
#include <iostream>

struct Node{
    int key = 0;
    int value = 0;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int k, int v): key(k), value(v){};
};

class LRU {
private:
    int capacity;
    std::map<int, Node*> cache;
    Node* head;
    Node* tail;

    // Move node to front (mark as recently used)
    void moveToFront(Node* node) {
        removeNode(node);
        insertAtFront(node);
    }

    // Remove node from the linked list
    void removeNode(Node* node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // Insert node at the front
    void insertAtFront(Node* node) {
        node->next = head->next;
        node->prev = head;
        head->next->prev = node;
        head->next = node;
    }

public:
    LRU(int cap) : capacity(cap) {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1; // Key not found

        Node* node = cache[key];
        moveToFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            node->value = value;
            moveToFront(node);
        } else {
            if (cache.size() >= capacity) {
                // Remove least recently used node (from tail)
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
            // Insert new node at front
            Node* newNode = new Node(key, value);
            insertAtFront(newNode);
            cache[key] = newNode;
        }
    }

    ~LRU() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void show(){
        auto next = tail;
        while(next){
            std::cout << next << " " << next->value << " " << next->key << " " << next->next << std::endl;
            next = next->next;
        }
    }
};

int main()
{
    LRU lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    lru.show();
    std::cout << lru.get(1) << std::endl;    // returns 1
    lru.put(3, 3); // evicts key 2
    lru.show();
    std::cout << lru.get(2) << std::endl; // returns -1 (not found)
    
    lru.put(4, 4); // evicts key 2
    lru.show();
    lru.put(5, 5); // evicts key 2
    lru.show();
    lru.put(6, 6); // evicts key 2
    lru.show();
    std::cout << lru.get(2) << std::endl;    // returns -1 (not found)    
}