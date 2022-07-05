class Queue {
    // declare arr and variables
    vector<int> arr;
    int q_front, rear;
public:
    Queue() {
        // Implement the Constructor
        q_front=0; // front pointer
        rear=0; // rear pointer
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return (arr.size()==0);
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        arr.push_back(data);
        rear=arr.size()-1;
    }

    int dequeue() {
        // Implement the dequeue() function
        // queue is fifo
        // so the first one to come in will leave
        if(arr.size()==0) return -1;
        else
        {
            int temp=arr[q_front]; // store front
            arr.erase(arr.begin()+0); // erase ele
            return temp; // return front
        }
    }

    int front() {
        // Implement the front() function
        // return front
        if(arr.size()==0) return -1;
        return arr[q_front];
    }
};
