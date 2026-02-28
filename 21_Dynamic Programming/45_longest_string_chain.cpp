#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool comp(const string &a, const string &b) {
    return a.size() < b.size();
}

int longestStrChain(vector<string>& words) {
    int n = words.size();

    sort(words.begin(), words.end(), comp);

    vector<int> dp(n, 1);
    int maxi = 1;

    for (int i = 1; i < n; i++) {
        for (int prev = i-1; prev >= 0; prev--) {
            if (words[i].size() - words[prev].size() > 1) {
                break;
            }

            if (words[i].size() == words[prev].size() + 1) {
                int mismatch = 0;
                int first = 0, second = 0;
                while (first < words[prev].size() && second < words[i].size()) {
                    if (words[prev][first] == words[i][second]) {
                        first++;
                        second++;
                    } else {
                        mismatch++;
                        second++;
                    }
                    if (mismatch > 1) break;
                }
                if (mismatch <= 1) {
                    dp[i] = max(dp[i], dp[prev] + 1);
                }
            }
        }

        maxi = max(maxi, dp[i]);
    }

    return maxi;
}

int main() {
    vector<string> words = {"a", "b", "ba", "bca", "bda", "bdca"};
    int result = longestStrChain(words);
    cout << "Length of Longest String Chain: " << result << endl;
    return 0;
}