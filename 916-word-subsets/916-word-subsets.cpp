 
class Solution {
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
      
        vector<string> ans;
        vector<int> map2(26, 0);

        for (string &w : words2) {
            vector<int> temp2(26, 0);

            for (char &c : w)
                temp2[c - 'a']++;

            // need to store the max frequencies for each character
            for (int i = 0; i < 26; i++)
                map2[i] = max(map2[i], temp2[i]);
        }


        for (auto &w : words1) {

            vector<int> temp1(26, 0);
            for (auto &c : w)
                temp1[c - 'a']++;

            bool ok = true;
            for (int i = 0; i < 26; i++)
                if (temp1[i] < map2[i])
                    ok = false;

            if (ok)
                ans.push_back(w);
        }
        
        return ans;
    }
};
 