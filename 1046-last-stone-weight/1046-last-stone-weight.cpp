class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        
        priority_queue<int> pq(stones.begin(),stones.end());
        
        while(pq.size()>1){
            int x = pq.top();
            pq.pop();
            int y= pq.top();
         
            pq.pop();
            pq.push(x-y);
        }
        
        return pq.top();
    }
};