#include <bits/stdc++.h>
using namespace std;

string convert2Binary(int num)
{
    string b = "";
    while(num != 1)
    {
        if (num%2 == 0) b+="0";
        else b+="1";
        
        num/=2;
    }
    b+="1";
    reverse(b.begin(),b.end());
    return b;
}

int main()
{
    cout << convert2Binary(712903) << endl;

    return 0;
}