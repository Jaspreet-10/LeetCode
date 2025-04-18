class MedianFinder {
public:
    priority_queue<int>minHeap;//this is actually max heap
    priority_queue<int, vector<int>, greater<int>>maxHeap;//this is actually min heap
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        maxHeap.push(num);
        minHeap.push(maxHeap.top());
        maxHeap.pop();
        if(maxHeap.size() < minHeap.size()){ 
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {
        if(maxHeap.size()>minHeap.size()) return maxHeap.top();
        if(!minHeap.empty() && !maxHeap.empty())
            return (minHeap.top() + maxHeap.top())/2.0;
        return 0.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */