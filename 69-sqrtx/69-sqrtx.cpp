class Solution {
public:
    int mySqrt(int x) {
        int l = 0, h = x, ans;

        while (l <= h) {
            long long mid = l + (h - l) / 2;

            if (mid * mid == x)  
                return mid;

            else if (mid * mid < x)  
                l = mid + 1;
       
            else h = mid - 1;
        }
        
        return ans;
    }
};