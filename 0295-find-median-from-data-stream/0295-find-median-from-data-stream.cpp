class MedianFinder {
public:
    priority_queue<int>smallerElements;
    priority_queue<int,vector<int>,greater<int>>greaterElements;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
       // Add number to max-heap
        smallerElements.push(num);
        
        // Balance the heaps: move the largest element of smallerElements to greaterElements
        greaterElements.push(smallerElements.top());
        smallerElements.pop();
        
        // Ensure size property: if greaterElements has more elements, move the smallest element back to smallerElements
        if (greaterElements.size() > smallerElements.size()) {
            smallerElements.push(greaterElements.top());
            greaterElements.pop();
        }
    }
    
    double findMedian() {
        if(smallerElements.size() == greaterElements.size()){
            return (double)((smallerElements.top()+greaterElements.top())/2.0);
        }
        return smallerElements.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */