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

int convert2Decimal(string num)
{
    int n=0;
    long long p = 1;
    for (int i=num.length()-1 ; i>=0 ; i--)
    {
        if (num[i] == '1') n+=p;
        p*=2;
    }
    return n;
}

void bitManipulation(int num, int i) {
    string b = convert2Binary(num);
    
    int arr[3];
    if (b.size() < i)
    {
        arr[0] = 0;
        arr[2] = num;
        
        int diff = i-b.size();
        diff--;
        while(diff--)
        {
            b = "0" + b;
        }
        b = "1" + b;
        
        arr[1] = convert2Decimal(b);
        
    }
    else if (b[b.size()-i] == '1') 
    {
        arr[0] = 1;
        arr[1] = num;
        
        b[b.size()-i] = '0';
        arr[2] = convert2Decimal(b);
        
    }
    else
    {
        arr[0] = 0;
        arr[2] = num;
        
        b[b.size()-i] = '1';
        arr[1] = convert2Decimal(b);
    }
    
    cout << arr[0] << " " << arr[1] << " " << arr[2] << " ";
}

int main()
{
    bitManipulation(446733544, 30);

    return 0;
}