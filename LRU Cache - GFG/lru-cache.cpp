//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

class LRUCache
{
    private:

    public:
    class Node{
        public:
        int key;
        int value;
        Node * prev;
        Node * next;

        Node(int key , int value){
            this->key = key;
            this->value = value;
        }
    };

    Node * head = NULL;
    Node * tail = NULL;
    int capacity;
    unordered_map<int , Node*> cache;
    

    void addNode(Node * node){ // add node to front
        Node * nbrNode = head->next;

        node->prev = head;
        node->next = nbrNode;

        head->next = node;
        nbrNode->prev = node;
    }

    void deleteNode(Node * node){ // delete node from end
        Node * prevNode = node->prev;
        Node * nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        node->next = NULL;
        node->prev = NULL;
    }

    void moveNode(Node * node) { // move node to front
        deleteNode(node);
        addNode(node);
    }
    
    //Constructor for initializing the cache capacity with the given value.
    LRUCache(int cap)
    {
        head = new Node(-1 , -1);
        tail = new Node(-1 , -1);
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }
    
    //Function to return value corresponding to the key.
    int GET(int key)
    {
        if(cache.find(key) == cache.end()){
            return -1;
        }else{
            Node * node = cache[key];
            int val = node->value;
            deleteNode(node);
            addNode(node);
            return val;
        }
    }
    
    //Function for storing key-value pair.
    void SET(int key, int value)
    {
        if(cache.find(key) != cache.end()){
            Node * node = cache[key];
            node->value = value;
            moveNode(node);
        }else{
            Node * node = new Node(key , value);
            if(cache.size() == capacity){
                Node * LRU_node = tail->prev;
                deleteNode(LRU_node);
                cache.erase(LRU_node->key);
            }
            cache[key] = node;
            addNode(node);
        }

    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);
        
        int queries;
        cin >> queries;
        while (queries--)
        {
            string q;
            cin >> q;
            if (q == "SET")
            {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->SET(key, value);
            }
            else
            {
                int key;
                cin >> key;
                cout << cache->GET(key) << " ";
            }
        }
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends