class Solution {
public:
    int fib(int n) {
        if(n<=1) return n;
        int p2 = 0, p = 1, cur;
        for(int i=2; i<=n; i++){
            cur = p2 + p;
            p2 = p;
            p = cur;
        }
        return cur;
    }
};