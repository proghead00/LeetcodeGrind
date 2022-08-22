class Solution {
public:
    bool isPowerOfFour(int n) {
        
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        bool sub1 = !(n % 4);
        bool sub2 = isPowerOfFour(n / 4);
        
        return sub1 & sub2;
        
    }
};