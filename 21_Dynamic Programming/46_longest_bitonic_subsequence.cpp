#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int longestBitonicSubsequence(vector<int>& arr) {
    int n = arr.size();
    vector<int> lis(n, 1);
    vector<int> lds(n, 1);

    // Compute Longest Increasing Subsequence (LIS)
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                lis[i] = max(lis[i], lis[j] + 1);
            }
        }
    }

    // Compute Longest Decreasing Subsequence (LDS)
    for (int i = n - 2; i >= 0; i--) {
        for (int j = n - 1; j > i; j--) {
            if (arr[i] > arr[j]) {
                lds[i] = max(lds[i], lds[j] + 1);
            }
        }
    }

    // Find the maximum length of bitonic subsequence
    int maxLength = 0;
    for (int i = 0; i < n; i++) {
        maxLength = max(maxLength, lis[i] + lds[i] - 1);
    }

    return maxLength;
}

int main() {
    vector<int> arr = {1, 11, 2, 10, 4, 5, 2, 1};
    int result = longestBitonicSubsequence(arr);
    cout << "Length of Longest Bitonic Subsequence: " << result << endl;
    return 0;
}