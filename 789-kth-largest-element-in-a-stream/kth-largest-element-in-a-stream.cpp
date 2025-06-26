class KthLargest {
    int num;
    priority_queue<int, vector<int>, greater<int>> pq;
public:
    KthLargest(int k, vector<int>& nums) {
        for(int i: nums){
            pq.push(i);
            if(pq.size() > k){
                pq.pop();
            }
        }
        num = k;
    }
    int add(int val) {
        pq.push(val);
        if(pq.size() > num){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */