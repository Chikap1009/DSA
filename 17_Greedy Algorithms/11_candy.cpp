#include <bits/stdc++.h>
using namespace std;

int brute_candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left(n,1), right(n,1);

    for (int i=1 ; i<n ; i++) {
        if (ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
    }

    for (int i=n-2 ; i>=0 ; i--) {
        if (ratings[i] > ratings[i+1]) right[i] = right[i+1] + 1;
    }

    int totalCandies = 0;
    for (int i=0 ; i<n ; i++) {
        totalCandies += max(left[i], right[i]);
    }

    return totalCandies;
}

int better_candy(vector<int>& ratings) {
    int n = ratings.size();
    vector<int> left(n,1);

    for (int i=1 ; i<n ; i++) {
        if (ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
    }

    int right = 1;
    int totalCandies = left[n-1];

    for (int i=n-2 ; i>=0 ; i--) {
        if (ratings[i] > ratings[i+1]) right++;
        else right = 1;

        totalCandies += max(left[i], right);
    }

    return totalCandies;
}

int optimal_candy(vector<int>& ratings) {
    int n = ratings.size();

    int i = 1;
    int totalCandies = 1;

    while(i<n) {

        while(i<n && ratings[i] == ratings[i-1]) {
            totalCandies++;
            i++;
        }

        int peak = 1;
        while(i<n && ratings[i] > ratings[i-1]) {
            peak++;
            totalCandies += peak;
            i++;
        }

        int down = 1;
        while(i<n && ratings[i] < ratings[i-1]) {
            totalCandies += down;
            down++;
            i++;
        }

        if (down > peak) {
            totalCandies += (down - peak);
        }
    }

    return totalCandies;
}

int main() {
    vector<int> ratings = {1,6,10,8,7,3,2}; // ans = 18;

    cout << brute_candy(ratings) << endl;
    cout << better_candy(ratings) << endl;
    cout << optimal_candy(ratings) << endl;

    return 0;
}