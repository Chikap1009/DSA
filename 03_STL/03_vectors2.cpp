#include <bits/stdc++.h>     
using namespace std;

int main()
{
    vector<int> v = {10,20,30,40};

    vector<int>::iterator it = v.begin();
    cout << *(it) << endl;
    it++;
    cout << *(it) << endl;
    it+=2;
    cout << *(it) << endl;

    it++;
    vector<int>::iterator it_temp = v.end();
    cout << *(it) << " " << *(it_temp) << endl;

    vector<int>::reverse_iterator it1 = v.rbegin();
    vector<int>::reverse_iterator it2 = v.rend();
    cout << *(it1) << endl;
    cout << *(it2) << endl;

    it1++;
    cout << *(it1) << endl;
    

    for (vector<int>::iterator it_forward = v.begin() ; it_forward != v.end() ; it_forward++)
    {
        cout << *(it_forward) << " ";
    }
    for (vector<int>::reverse_iterator it_back = v.rbegin() ; it_back != v.rend() ; it_back++)
    {
        cout << *(it_back) << " ";
    }

    return 0;
}