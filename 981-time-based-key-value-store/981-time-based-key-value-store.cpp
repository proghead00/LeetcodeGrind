class TimeMap {
    unordered_map<string, map<int, string, greater<int>>> mp;

public:
    TimeMap() {
        mp.clear();
    }

    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        auto findKey = mp.find(key);
        if (findKey == mp.end()) return "";

        auto found = findKey->second.lower_bound(timestamp);
        if (found == findKey->second.end()) {
            return "";
        }
        return found->second;
    }
};
