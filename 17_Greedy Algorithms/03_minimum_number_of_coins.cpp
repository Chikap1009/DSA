#include <bits/stdc++.h>
using namespace std;

void recursiveMinCoins(vector<int>& coins, int& sum, int& currSum, int& countCoins, int& minCountCoins) {
    if (currSum == sum) {
        if (minCountCoins == -1) minCountCoins = countCoins;
        else minCountCoins = min(minCountCoins, countCoins);

        return;
    }

    for (int i=coins.size()-1 ; i>=0 ; i--) {
        if (currSum + coins[i] <= sum) {
            currSum += coins[i];
            countCoins++;
            recursiveMinCoins(coins,sum,currSum,countCoins,minCountCoins);
            currSum -= coins[i];
            countCoins--;
        }
    }
}

int minCoins(vector<int>& coins, int sum) {
    if (sum == 0) return 0;
    sort(coins.begin(),coins.end());
    while(coins.size() >= 1 && coins[coins.size()-1] > sum) {
        coins.pop_back();
    }
    if (coins.empty()) return -1;
    int currSum = 0;
    int countCoins = 0;
    int minCountCoins = -1;
    recursiveMinCoins(coins,sum,currSum,countCoins,minCountCoins);
    return minCountCoins;
}

int main() {
    vector<int> coins = {1,5,6,9};

    cout << minCoins(coins,11) << endl;

    return 0;
}