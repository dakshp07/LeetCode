class MedianFinder {
public:
    // we will use heaps (min and max) to get the median using . We will try to keep them balanced on basis of their size so that at    end we will have the medians at top.
    // we are not interested in other numbers just the middle one thats why using heap combo of min and max .
	// we are using min and max beacuse we will maintain our heaps in a way that max of max heap will always be lesser than equal to min of min Heap in this way we be able to get the medians
    // tc: O(nlogn) and sc: O(n)
    priority_queue<int,vector<int>,greater<int>> minH;
    priority_queue<int> maxH;
    MedianFinder() {}
    
    void addNum(int num) {
        // we are trying to maintain a stream i.e., maxH.top() <= minH.top() in that way only we can assure the medians
        if(maxH.empty() || num<maxH.top()){
            maxH.push(num);
        }
        // incase we encounter greater number than the one present in maxH we need to add it in minH 
        else{
            minH.push(num);
        }
        // we are trying to balance our heaps the max diff of size can be only 1
        // therefore popping the extra from that heap and pushing that in the other one
        if(maxH.size()>minH.size()+1){
            minH.push(maxH.top());
            maxH.pop();
        }
        else if(minH.size()>maxH.size()+1){
            maxH.push(minH.top());
            minH.pop();
        }
    }
    
    double findMedian() {
        // this operation is going to be O(1)
        // incase of even entries
        if(maxH.size() == minH.size()){
            // we will find mean of middle 2 entries and return 
            return (maxH.top() + minH.top()) / 2.0;
        }
        // incase of odd entries:
        // our median will be present in that heap which has greater size
        else{
            return maxH.size() > minH.size() ? maxH.top() : minH.top();
        }
        
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */