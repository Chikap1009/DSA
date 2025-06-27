#include <bits/stdc++.h>
using namespace std;

int trap1(vector<int>& height) {
    vector<int> rightMax (height.size(),0);
    int maxi = height[height.size()-1];
    for (int i=height.size()-2 ; i>=0 ; i--) {
        rightMax[i] = maxi;
        maxi = max(maxi, height[i]);
    }
    int leftMax = 0;
    int ans = 0;
    for (int i=0 ; i<height.size() ; i++) {
        if (min(leftMax, rightMax[i]) > height[i]) ans += min(leftMax, rightMax[i]) - height[i];

        leftMax = max(leftMax, height[i]);
    }

    return ans;
}

int trap2(vector<int>& height) {
    int ans = 0;
    int leftMax = 0;
    int rightMax = 0;
    int left = 0;
    int right = height.size()-1;

    while(left < right) {

        if (height[left] <= height[right]) {
            if (leftMax > height[left]) ans += leftMax-height[left];
            else leftMax = height[left];
            left++;
        }
        else {
            if (rightMax > height[right]) ans += rightMax-height[right];
            else rightMax = height[right];
            right--;
        }
    }

    return ans;
}

int main() {

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};

    cout << trap1(height) << endl;
    cout << trap2(height) << endl;
    
    return 0;
}