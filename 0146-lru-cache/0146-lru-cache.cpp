class LRUCache {
public:
    class Node{
        public:
        int key,val;
        Node* next;
        Node* prev;

        Node(int key, int val){
            this->key = key;
            this->val = val;
            next = prev = NULL;
        }
    };

    unordered_map<int,Node*>m;

    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int limit = 0;

    LRUCache(int capacity) {
        limit = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* NewNode){
        Node* oldNode = head->next;

        head->next = NewNode;
        NewNode->prev = head;

        NewNode->next = oldNode;
        oldNode->prev = NewNode;
    }

    void deleteNode(Node* oldNode){
        Node* NextNode = oldNode->next;
        Node* PrevNode = oldNode->prev;

        PrevNode->next = NextNode;
        NextNode->prev = PrevNode;

    }
    
    int get(int key) {
        if(!m.count(key)) return -1;

        int ans = m[key]->val;
        Node* ansNode = m[key];

        m.erase(key);
        deleteNode(ansNode);

        addNode(ansNode);
        m[key] = ansNode;

        return ans;
    }
    
    void put(int key, int value) {
        if(m.count(key)){
            Node* oldNode = m[key];
            deleteNode(oldNode);
            m.erase(key);
        }

        if(m.size()==limit){
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        Node* NewNode = new Node(key, value);
        addNode(NewNode);
        m[key] = NewNode;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */