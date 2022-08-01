class Solution {
public:
    
    bool isPal(string &s, int i, int j){

        while(i <= j){
            if(s[i] != s[j]) return false;
            i++, j--;
        }
        
        return true;
    }
    
    void help(string &s, vector<string> temp, vector<vector<string>> &ans, int idx){
    
        if(idx == s.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx ; i < s.size(); i++){
            if(isPal(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                help(s, temp, ans, i + 1);
                temp.pop_back();
            }
        }
            
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> temp;
        vector<vector<string>> ans;
        help(s, temp, ans, 0);
        
        return ans;
    }
};