class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        
        if(hand.size() % groupSize != 0) return false;
        
        map<int, int> mp;
        for(auto x: hand) mp[x]++;
        
        while(!mp.empty()){
            int cur = mp.begin()->first; // current key at the top
           
            for(int i = 0; i < groupSize; i++) {
                // check if consecutives are present
                if(mp[cur + i] == 0 or mp.count(cur + i) == 0) return false;
                mp[cur + i]--;
                if(mp[cur + i] == 0) mp.erase(cur + i);
            }
        }
        
        return true;
    }
};