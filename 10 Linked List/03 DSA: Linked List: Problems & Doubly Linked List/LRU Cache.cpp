// https://www.scaler.com/academy/mentee-dashboard/class/297893/assignment/problems/239?navref=cl_tt_nv_dd

// Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and set.

// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
// The LRUCache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

// Definition of "least recently used" : An access to an item is defined as a get or a set operation of the item. "Least recently used" item is the one with the oldest access time.

// NOTE: If you are using any global variables, make sure to clear them in the constructor.

// Example :

// Input : 
//          capacity = 2
//          set(1, 10)
//          set(5, 12)
//          get(5)        returns 12
//          get(1)        returns 10
//          get(10)       returns -1
//          set(6, 14)    this pushes out key = 5 as LRU is full. 
//          get(5)        returns -1

ListNode* dummyTail;
ListNode* dummyHead;
unordered_map<int, ListNode*> cachemap;

LRUCache::LRUCache(int capacity) {
    int size=0;
    int maxcap=capacity;
    dummyHead=new ListNode(-1, -1);
    dummyTail=new ListNode(-1, -1);
    dummyHead->next=dummyTail;
    dummyTail->prev=dummyHead;
}

int LRUCache::get(int key) {
    if (cachemap.find(key) != cachemap.end()) {
        ListNode* node = cachemap[key];
        remove(node);  //remove the node from its current position
        add(node);     //add the node to the end (most recently used)
        return node->val;
    } else {
        return -1;
    }
}

void LRUCache::set(int key, int value) {
    if (cachemap.find(key) != cachemap.end()) {
        ListNode* node = cachemap[key];
        node->val = value;
        remove(node);  //remove it from its current position
        add(node);     //move to the most recently used position
    } else {
        ListNode* newNode = new ListNode(key, value);
        cachemap[key] = newNode;
        add(newNode);   //add the new node to the end (most recently used)
        size++;

        if (size > maxcap) {
            ListNode* lru = dummyHead->next;
            remove(lru);
            cachemap.erase(lru->key);
            delete lru;
            size--;
        }
    }
}

void LRUCache::add(ListNode* x){
    x->next=dummyTail;
    x->prev=dummyTail->prev;
    dummyTail->prev->next=x;
    dummyTail->prev=x;
}

void LRUCache::remove(ListNode* x){
    x->prev->next=x->next;
    x->next->prev=x->prev;
    x->next=NULL;
    x->prev=NULL;
}