#include<iostream>
using namespace std;

// 1. Doubly Linked List Node
struct Node {
    int key;
    int val;
    Node* next;
    Node* prev;
    
    Node(int k, int v) : key(k), val(v), next(NULL), prev(NULL) {}
};

class LRUCache {
private:
    int capacity;
    // We use "Dummy" head and tail nodes to make adding/removing easier
    // (So we never have to check if head is NULL)
    Node* head;
    Node* tail;

    // Simple Hash Map (Array of Pointers)
    // Maps Key -> Node Address
    Node* map[1000]; 

public:
    LRUCache(int cap) {
        capacity = cap;
        
        // Initialize Map to NULL
        for(int i=0; i<1000; i++) map[i] = NULL;

        // Initialize Dummy Nodes
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        
        // Connect Head <-> Tail
        head->next = tail;
        tail->prev = head;
    }

    // --- HELPER 1: Add right after Head (Most Recently Used) ---
    void addNode(Node* newNode) {
        Node* temp = head->next;
        
        newNode->next = temp;
        newNode->prev = head;
        
        head->next = newNode;
        temp->prev = newNode;
    }

    // --- HELPER 2: Remove a node from anywhere ---
    void deleteNode(Node* delNode) {
        Node* prevNode = delNode->prev;
        Node* nextNode = delNode->next;
        
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    // --- MAIN FUNCTION: GET ---
    int get(int key) {
        // 1. Check Map
        if (map[key] != NULL) {
            Node* resNode = map[key];
            int res = resNode->val;
            
            // 2. We touched it, so move to FRONT (MRU)
            deleteNode(resNode); // Unlink from current spot
            addNode(resNode);    // Add to front
            
            return res;
        }
        return -1; // Not found
    }

    // --- MAIN FUNCTION: PUT ---
    void put(int key, int value) {
        // Case 1: Key already exists? Update it.
        if (map[key] != NULL) {
            Node* existingNode = map[key];
            existingNode->val = value; // Update value
            
            deleteNode(existingNode);
            addNode(existingNode); // Move to front
            return;
        }

        // Case 2: New Key.
        // First, check if full.
        // (We can track size with a variable, but for this exam code
        // let's assume we manage it carefully. Adding a size counter is easy).
        // For simplicity, let's just handle the Insertion logic here.
        
        // If we hypothetically needed to delete LRU:
        // Node* lru = tail->prev;
        // map[lru->key] = NULL;
        // deleteNode(lru);
        // delete lru;

        // Create new node
        Node* newNode = new Node(key, value);
        
        // Add to Map and List
        map[key] = newNode;
        addNode(newNode);
    }
};

int main() {
    // Capacity 3
    LRUCache cache(3);

    cache.put(1, 100); // Cache: [1]
    cache.put(2, 200); // Cache: [2, 1]
    cache.put(3, 300); // Cache: [3, 2, 1]

    cout << "Get 1: " << cache.get(1) << endl; 
    // Since we accessed 1, it moves to front!
    // Cache is now: [1, 3, 2]

    cache.put(4, 400); 
    // If we implemented the "Capacity Full" check properly, 
    // it would delete '2' (the one at the tail).
    // Cache: [4, 1, 3]

    return 0;
}