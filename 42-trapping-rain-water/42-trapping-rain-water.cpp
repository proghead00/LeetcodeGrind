class Solution {
public:
    int trap(vector<int>& height) {
        int leftmax = 0, rightmax = 0;
        int ans = 0;
        
        int l = 0, r = height.size() - 1;
        
        while(l < r){
            if(height[l] <= height[r]) {    // if block means that we have a taller building on the right
                
                // we just need to find if we have a taller building on the LEFT
                
                if(leftmax > height[l]) { // means that we do have a taller building on the left and we can hence store water
                    ans += leftmax - height[l]; // why? see: https://imgur.com/a/5DmSfnu
                }
                
                else{
                    // no taller building on the left
                    leftmax = height[l];
                }
                
                l++;
            }
            
            else { // else block here signifies that we already have a taller building on the left
                
                // we just need to find if we have a taller building on the RIGHT

                if(rightmax > height[r]) ans += rightmax - height[r];
                else rightmax = height[r];
                
                r--;
            }
        }
        
        return ans;
    }
};