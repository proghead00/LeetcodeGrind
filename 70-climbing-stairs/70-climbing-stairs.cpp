class Solution {
public:
    int climbStairs(int n) {
        
        if(n<=2) return n;
        
        int prev = 2;
        int prevPrev = 1;
        
        int ans = 0;
        
        for(int i = 2; i<n; i++){
            ans = prev + prevPrev;
            prevPrev = prev;
            prev = ans;
        }
        
        return ans;
    }
};