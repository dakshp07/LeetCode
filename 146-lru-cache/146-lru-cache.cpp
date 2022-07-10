class LRUCache {
public:
    // doubly linked list + hashmap combo can be used as well
    // doubly linked list will be used to store the key values in the most freq, to least freq fashion
    // hashmap can be used to keep track of the most freq one. it will store (key, node address)
    // key is our number and node address is the location where the ele is in dll
    
    // lets make our dll
    class node{
        public:
            int key;
            int val;
            node *prev;
            node *next;
            node(int _key, int _val)
            {
                key=_key;
                val=_val;
            }
    };
    // making our nodes
    node *head=new node(-1, -1);
    node *tail=new node(-1, -1);
    
    int cap; // max cap
    unordered_map<int, node*> mp; // our map to keep track
    LRUCache(int capacity) {
        // constructor
        cap=capacity; // setting cap
        head->next=tail; // intializing our dll
        tail->prev=head;
    }
    
    // add a new node func
    void addnode(node *newnode)
    {
        node *temp=head->next;
        newnode->next=temp;
        newnode->prev=head;
        head->next=newnode;
        temp->prev=newnode;
    }
    
    // delete a node func
    void deletenode(node *delnode)
    {
        node *delprev=delnode->prev;
        node *delnext=delnode->next;
        delprev->next=delnext;
        delnext->prev=delprev;
    }
    
    int get(int key) {
        // check if we have that key by checking our map
        if(mp.find(key)!=mp.end())
        {
            // if found
            node *existing=mp[key]; // take the address
            int res=existing->val; // the value at that address has the ans
            deletenode(existing); // delete this node since it will have a new pos as it was used
            addnode(existing); // add the node back to a new pos
            mp[key]=head->next; // store the new address in the map
            return res;
        }
        return -1;
    }
    
    void put(int key, int value) {
        // first check if its there or not in node
        if(mp.find(key)!=mp.end())
        {
            // if its there
            node *existing=mp[key];
            mp.erase(key); // we erase from map
            deletenode(existing); // since now we are using it again it becomes more freq
        }
        // if size is full
        if(mp.size()==cap)
        {
            // we delete the least recently used
            mp.erase(tail->prev->key); // since we were storing from most freq to least freq in dll
            deletenode(tail->prev); // delete from dll
        }
        // add the node since now its more freq
        addnode(new node(key, value)); // add in dll
        mp[key]=head->next; // also update map
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */