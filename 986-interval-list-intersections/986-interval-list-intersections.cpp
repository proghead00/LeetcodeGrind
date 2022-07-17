class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;

        int ff = 0, ss = 0;
        vector<int> temp(2);

        while (ff < firstList.size() and ss < secondList.size()) {

            if (secondList[ss][0] <= firstList[ff][1] and firstList[ff][0] <= secondList[ss][1]) {
                temp[0] = max(firstList[ff][0], secondList[ss][0]);
                temp[1] = min(firstList[ff][1], secondList[ss][1]);
                ans.push_back(temp);
                // temp.clear();
            }

            if (secondList[ss][1] > firstList[ff][1]) ff++;
            else ss++;
        }

        return ans;
    }
};