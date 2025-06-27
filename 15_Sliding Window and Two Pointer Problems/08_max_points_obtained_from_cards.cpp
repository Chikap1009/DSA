#include <bits/stdc++.h>
using namespace std;

int maxScore(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int leftSum = 0;
    int rightSum = 0;
    for (int i=0 ; i<k ; i++) {
        leftSum += cardPoints[i];
    }
    int maxScore = leftSum;
    for (int i=0 ; i<k ; i++) {
        leftSum -= cardPoints[k-i-1];
        rightSum += cardPoints[n-i-1];
        maxScore = max(maxScore, leftSum+rightSum);
    }
    return maxScore;
}

int main() {

    vector<int> scores = {1,2,3,4,5,6,1};
    cout << maxScore(scores, 3) << endl;

    return 0;
}