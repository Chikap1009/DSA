#include <bits/stdc++.h>
using namespace std;

int minimumMultiplications(vector<int> &arr, int start, int end) {

    queue<pair<int,int>> q;
    vector<int> steps(100000, 1e9);

    q.push({0,start});
    steps[start] = 0;

    while(!q.empty()){
        int step = q.front().first;
        int num = q.front().second;
        q.pop();

        for (int i=0 ; i<arr.size() ; i++) {
            int number = (num * arr[i]) % 100000;
            if (step + 1 < steps[number]) {
                steps[number] = step + 1;
                if (number == end) return steps[number];
                q.push({steps[number], number});
            }
        }
    }

    return -1;
}

int main() {
    vector<int> arr = {3, 4, 65};
    int start = 7;
    int end = 66175;

    int result = minimumMultiplications(arr, start, end);
    cout << "Minimum steps to reach end from start: " << result << endl;

    return 0;
}