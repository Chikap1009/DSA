#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int maxProfit(vector<int>& prices) {
    int n = prices.size();
    int mini = prices[0];
    int maxProfit = 0;
    for (int i=1 ; i<n ; i++) {
        maxProfit = max(maxProfit, prices[i] - mini);
        mini = min(mini, prices[i]);
    }
    return maxProfit;
}

int main() {
    vector<int> prices = {7,1,5,3,6,4};
    int result = maxProfit(prices);
    cout << "Maximum Profit: " << result << endl;
    
    return 0;
}