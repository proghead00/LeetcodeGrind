class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        vector<int> lastIdx(26);

        for (int i = 0; i < n; i++)
            lastIdx[s[i] - 'a'] = i;


        int start = 0;
        int end = 0;

        vector<int> ans;

        for (int i = 0; i < n; i++) {
            // start++;
            end = max(end, lastIdx[s[i] - 'a']);
            if (i == end) {
                ans.push_back(end - start + 1);
                start = end + 1;
            }
        }

        return ans;
    }
};