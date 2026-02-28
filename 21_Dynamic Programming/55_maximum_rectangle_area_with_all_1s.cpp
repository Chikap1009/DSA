#include <bits/stdc++.h>
using namespace std;

int largestRectangleInHistogram(vector<int> histogram) {
    stack<int> st;
    int maxiArea = 0;

    for (int i=0 ; i<histogram.size() ; i++) {

        while(!st.empty() && histogram[st.top()] > histogram[i]) {
            int element = st.top();
            st.pop();

            int nse = i;
            int pse = st.empty() ? -1 : st.top();

            maxiArea = max(maxiArea, histogram[element]*(nse-pse-1));
        }

        st.push(i);
    }

    while(!st.empty()) {
        int element = st.top();
        st.pop();

        int nse = histogram.size();
        int pse = st.empty() ? -1 : st.top();

        maxiArea = max(maxiArea, histogram[element]*(nse-pse-1));
    }

    return maxiArea;
}
int maximalRectangle(vector<vector<string>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();

    int ans = 0;

    vector<int> prefixSum(m,0);

    for (int i=0 ; i<n ; i++) {
        
        for (int j=0 ; j<m ; j++) {
            if (matrix[i][j] == "0") prefixSum[j] = 0;
            else prefixSum[j]++;
        }

        ans = max(ans, largestRectangleInHistogram(prefixSum));
    }

    return ans;
}

int main() {
    vector<vector<string>> matrix = {{"1","0","1","0","0"},{"1","0","1","1","1"},{"1","1","1","1","1"},{"1","0","0","1","0"}};

    cout << maximalRectangle(matrix) << endl;

    return 0;
}