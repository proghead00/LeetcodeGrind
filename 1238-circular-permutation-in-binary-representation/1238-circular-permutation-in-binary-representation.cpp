class Solution {
public:

    // Functions for Gray Code:

    vector<string> help(int n) {

        if (n == 1) {
            return {"0", "1"};
        }

        vector<string> temp = help(n - 1);

        vector<string> zeroesAdd;
        vector<string> onesAdd;

        for (auto pp : temp) {
            zeroesAdd.push_back("0" + pp);
        }

        reverse(temp.begin(), temp.end());
        for (auto pp : temp) {
            onesAdd.push_back("1" + pp);
        }

        vector<string> merged;

        for (auto ff : zeroesAdd)
            merged.push_back(ff);

        for (auto ff : onesAdd)
            merged.push_back(ff);

        return merged;
    }


    vector<int> grayCode(int n) {
        vector<int> ans;

        vector<string> ansStr = help(n);

        for (auto x : ansStr) {
            int y = stoi(x, 0, 2);
            ans.push_back(y);
        }

        return ans;
    }

    // -------------------------------------------------------

    vector<int> circularPermutation(int n, int start) {
        vector<int> graycodeVec = grayCode(n); // I get the gray code answer here


        // now we need to find the circular one

        auto it = find(graycodeVec.begin(), graycodeVec.end(), start);
        int idx = it - graycodeVec.begin(); // index of start

        vector<int> circularAns;

        // push from start's index till the end
        for (int i = idx; i < graycodeVec.size(); i++) {
            circularAns.push_back(graycodeVec[i]);
        }

        // push the remaining elements from 0 to idx-1 (idx = start's index)
        for (int i = 0; i < idx; i++) {
            circularAns.push_back(graycodeVec[i]);
        }

        return circularAns;
    }

};