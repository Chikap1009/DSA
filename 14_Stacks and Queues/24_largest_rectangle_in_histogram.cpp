#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerElement(vector<int>& heights) {
    vector<int> nse(heights.size());
    stack<int> st;

    for (int i=heights.size()-1 ; i>=0 ; i--) {

        while(!st.empty() && heights[st.top()] >= heights[i]) {
            st.pop();
        }

        if (st.empty()) nse[i] = heights.size();
        else nse[i] = st.top();

        st.push(i);
    }

    return nse;
}

vector<int> previousSmallerEqualElement(vector<int>& heights) {
    vector<int> psee(heights.size());
    stack<int> st;

    for (int i=0 ; i<heights.size() ; i++) {

        while(!st.empty() && heights[st.top()] > heights[i]) {
            st.pop();
        }

        if (st.empty()) psee[i] = -1;
        else psee[i] = st.top();

        st.push(i);
    }

    return psee;
}

int bruteLargestRectangleArea(vector<int>& heights) {
    vector<int> nse = nextSmallerElement(heights);
    vector<int> psee = previousSmallerEqualElement(heights);

    int ans = INT_MIN;

    for (int i=0 ; i<heights.size() ; i++) {
        int left = psee[i];
        int right = nse[i];

        ans = max(ans, heights[i]*(right-left-1));
    }

    return ans;
}

int optimalLargestRectangleArea(vector<int>& heights) {
    stack<int> st;
    int maxi = 0;

    for (int i=0 ; i<heights.size() ; i++) {

        while(!st.empty() && heights[st.top()] > heights[i]) {
            int element = st.top();
            st.pop();

            int nse = i;
            int pse = st.empty() ? -1 : st.top();

            maxi = max(maxi, heights[element]*(nse - pse - 1));
        }

        st.push(i);
    }

    while(!st.empty()) {
        int element = st.top();
        st.pop();
        int nse = heights.size();
        int pse = st.empty() ? -1 : st.top();

        maxi = max(maxi, heights[element]*(nse - pse - 1));
    }

    return maxi;
}

int main() {

    vector<int> heights = {2,1,5,6,2,3};

    cout << bruteLargestRectangleArea(heights) << endl;
    cout << optimalLargestRectangleArea(heights) << endl;

    return 0;
}