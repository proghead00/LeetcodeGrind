class Solution {
public:
    string reverseWords(string s) {
        int i = 0, j;
        
        string ans = s;
        
        for(int k = 0; k < s.size(); k++){
            if(s[k] == ' '){
                reverse(ans.begin() + i, ans.begin() + k);
                i = k + 1;
            }    
            else if(k == s.size() - 1){
                reverse(ans.begin() + i, ans.end());
            }
        }
        
        return ans;
    }
};