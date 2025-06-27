#include <bits/stdc++.h>
using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> v;
    for (int i=0 ; i<asteroids.size() ; i++) {
        if (asteroids[i] < 0) {
            while(!v.empty() && v.back() > 0 && v.back() < abs(asteroids[i])) {
                v.pop_back();
            }
            if (!v.empty() && v.back() > 0 && v.back() == abs(asteroids[i])) {
                v.pop_back();
            }
            else if (v.empty() || v.back() < 0) v.push_back(asteroids[i]);
            // for (int j=i-1 ; j>=0 ; j--) {
            //     if (asteroids[j] < 0) break;
            //     if (asteroids[j] > asteroid) {
            //         asteroids[i] = 0;
            //         break;
            //     }
            //     else if (asteroids[j] == asteroid) {
            //         asteroids[i] = 0;
            //         asteroids[j] = 0;
            //         break;
            //     }
            //     else {
            //         asteroids[j] = 0;
            //     }
            // }
        }
        else v.push_back(asteroids[i]);
    }
    // vector<int> ans;
    // for (int i=0 ; i<asteroids.size() ; i++) {
    //     if (asteroids[i] != 0) ans.push_back(asteroids[i]);
    // }

    return v;
}

int main() {
    vector<int> asteroids = {4,7,1,1,2,-3,-7,17,15,-16};
    
    vector<int> ans = asteroidCollision(asteroids);

    for (auto x : ans) {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}