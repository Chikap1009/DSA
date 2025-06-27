#include <bits/stdc++.h>
using namespace std;

void moveZeroes(vector<int> &arr)
{
    int j=-1;

    for (int i=0 ; i<arr.size() ; i++)
    {
        if (arr[i] == 0)
        {
            j=i;
            break;
        }
    }

    if (j==-1) return;

    for (int i=j+1 ; i<arr.size() ; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i],arr[j]);
            j++;
        }
    }
}

// void moveZeroes(vector<int> &arr)
// {
//     int index = 0;
//     int last = arr.size()-1;

//     for (int i=0 ; i<arr.size() ; i++)
//     {
//         if (arr[i] != 0)
//         {
//             arr[index] = arr[i];
//             index++;
//         }
//     }
//     for (int i=index ; i<arr.size() ; i++)
//     {
//         arr[i] = 0;
//     }
// }

int main()
{
    vector<int> v = {1,0,2,3,2,0,0,4,5,1};

    moveZeroes(v);

    for (auto x : v)
    {
        cout << x << " ";
    }
    cout << endl;

    return 0;
}