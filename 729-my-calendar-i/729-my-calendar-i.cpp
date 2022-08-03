class MyCalendar {

private: map<int, int> mp;

public:
    MyCalendar() {

    }

    // mapping of end to start
    bool book(int start, int end) {

        auto nextGreaterEnd = mp.upper_bound(start);

        if (nextGreaterEnd == mp.end() or nextGreaterEnd->second >= end) {
            mp[end] = start;
            return true;
        }

        else return false;
    }
};