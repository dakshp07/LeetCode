// lets start with making node of dll
struct Node{
    int key, value, cnt;
    Node *prev;
    Node *next;
    Node(int _key, int _value)
    {
        key=_key;
        value=_value;
        cnt=1;
    }
};
struct List{
    int size;
    Node *head;
    Node *tail;
    List(){
        head=new Node(0, 0);
        tail=new Node(0, 0);
        head->next=tail;
        tail->prev=head;
        size=0;
    }
    // add front function
    void addfrontnode(Node *node)
    {
        Node *temp=head->next;
        node->next=temp;
        node->prev=head;
        head->next=node;
        temp->prev=node;
        size++;
    }
    // remove a node function
    void removenode(Node *node)
    {
        Node *delprev=node->prev;
        Node *delnext=node->next;
        delprev->next=delnext;
        delnext->prev=delprev;
        size--;
    }
};
class LFUCache {
public:
    // kinda similar to what LRU is
    // here we will be using 2 maps instead of one (1 map to keep track of puts and other one keeps track of freq)
    
    // now we need two maps
    map<int, Node*> keyNode; // to store key and their addresses
    map<int, List*> freqList; // freq of every node
    int mxSize; // max size of cache
    int currSize; // current size of cache
    int minFreq; // minimum freq
    LFUCache(int capacity) {
        mxSize=capacity;
        minFreq=0;
        currSize=0;
    }
    
    //  update freq list function
    void updateFreqList(Node *node){
        keyNode.erase(node->key); // erase node
        freqList[node->cnt]->removenode(node); // remove the node by taking address
        if(node->cnt == minFreq && freqList[node->cnt]->size == 0) {
            minFreq++; 
        }
        
        List* nextHigherFreqList = new List();
        if(freqList.find(node->cnt + 1) != freqList.end()) {
            nextHigherFreqList = freqList[node->cnt + 1];
        } 
        node->cnt += 1; 
        nextHigherFreqList->addfrontnode(node); 
        freqList[node->cnt] = nextHigherFreqList; 
        keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            int val = node->value; 
            updateFreqList(node); 
            return val; 
        }
        return -1; 
    }
    
    void put(int key, int value) {
        if (mxSize == 0) {
            return;
        }
        if(keyNode.find(key) != keyNode.end()) {
            Node* node = keyNode[key]; 
            node->value = value; 
            updateFreqList(node); 
        }
        else {
            if(currSize == mxSize) {
                List* list = freqList[minFreq]; 
                keyNode.erase(list->tail->prev->key); 
                freqList[minFreq]->removenode(list->tail->prev);
                currSize--; 
            }
            currSize++; 
            // new value has to be added who is not there previously 
            minFreq = 1; 
            List* listFreq = new List(); 
            if(freqList.find(minFreq) != freqList.end()) {
                listFreq = freqList[minFreq]; 
            }
            Node* node = new Node(key, value); 
            listFreq->addfrontnode(node);
            keyNode[key] = node; 
            freqList[minFreq] = listFreq; 
    }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */