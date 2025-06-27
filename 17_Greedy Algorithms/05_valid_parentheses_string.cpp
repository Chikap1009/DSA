#include <bits/stdc++.h>
using namespace std;

bool checkValidString(string s) {
    int min = 0, max = 0;
    for (int i=0 ; i<s.length() ; i++) {
        if (s[i] == '(') {
            min++;
            max++;
        }
        else if (s[i] == ')') {
            min--;
            max--;
        }
        else {
            min--;
            max++;
        }
        if (min < 0) min = 0;
        if (max < 0) return false;
    }
    if (min == 0) return true;
    return false;
}

// bool checkValidString(string s) {
//     int open = 0;
//     int temp = 0;
//     for (int i=0 ; i<s.length() ; i++) {
//         if (s[i] == '(') open++;
//         else if (s[i] == ')') {
//             if (open > 0) open--;
//             else if (temp > 0) temp--;
//             else return false;
//         }
//         else temp++;
//     }
//     if (open > 0) {
//         if (temp < open) return false;
//     }

//     int closed = 0;
//     temp = 0;
//     for (int i=s.length()-1 ; i>=0 ; i--) {
//         if (s[i] == ')') closed++;
//         else if (s[i] == '(') {
//             if (closed > 0) closed--;
//             else if (temp > 0) temp--;
//             else return false;
//         }
//         else temp++;
//     }
//     if (closed > 0) {
//         if (temp < closed) return false;
//     }
//     return true;
// }

int main() {

    cout << checkValidString("(*))") << endl;

    return 0;
}