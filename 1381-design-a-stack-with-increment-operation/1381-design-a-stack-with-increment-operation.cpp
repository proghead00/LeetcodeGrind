class CustomStack {
public:
       vector<int> v;
       int mx;
       CustomStack(int maxSize) {
              mx = maxSize;
       }

       void push(int x) {
              if (v.size() < mx) v.push_back(x);
       }

       int pop() {
              if (!v.size()) return -1;
              int pp = v.back();
              v.pop_back();
              return pp;
       }

       void increment(int k, int val) {
              int x = k;
              if (v.size() < k) x = v.size();
              for (int i = 0; i < x; i++) v[i] += val;
       }
};
