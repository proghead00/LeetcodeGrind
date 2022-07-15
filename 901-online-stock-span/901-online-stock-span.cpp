class StockSpanner {
public:
       stack<pair<int, int>> st; //price , span
       StockSpanner() {

       }

       int next(int price) {
              int span = 1; 
              while (!st.empty() and st.top().first <= price) {
                     span += st.top().second;
                     st.pop();
              }
              st.push({price, span});
              return span;
       }
};