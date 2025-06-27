#include <bits/stdc++.h>
using namespace std;

class StockSpanner {
public:
    stack<pair<int,int>> st;
    int count;

    StockSpanner() {
        while(!st.empty()) {
            st.pop();
        }
        count = -1;
    }
    
    int next(int price) {
        count++;
        while(!st.empty() && st.top().first <= price) {
            st.pop();
        }
        int pge = st.empty() ? -1 : st.top().second;
        st.push({price,count});
        return count-pge;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main() {
    StockSpanner ss = StockSpanner();

    cout << ss.next(100) << endl;
    cout << ss.next(80) << endl;
    cout << ss.next(60) << endl;
    cout << ss.next(70) << endl;
    cout << ss.next(60) << endl;
    cout << ss.next(75) << endl;
    cout << ss.next(85) << endl;

    return 0;
}