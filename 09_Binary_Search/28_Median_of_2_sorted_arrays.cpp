#include <bits/stdc++.h>
using namespace std;

double brute_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    int left = 0;
    int right = 0;

    vector<int> arr;

    while (left < n && right < m)
    {
        if (nums1[left] <= nums2[right])
        {
            arr.push_back(nums1[left]);
            left++;
        }
        else
        {
            arr.push_back(nums2[right]);
            right++;
        }
    }

    while (left < n)
    {
        arr.push_back(nums1[left]);
        left++;
    }

    while (right < m)
    {
        arr.push_back(nums2[right]);
        right++;
    }

    int total = n + m;

    if (total % 2 == 1)
    {
        return (double) arr[total/2];
    }
    else
    {
        return (double)(arr[total/2] + arr[total/2 - 1])/2.0;
    }
}

double better_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();

    int left = 0;
    int right = 0;

    int count = 0;

    int total = n + m;

    int element1 = -1;
    int element2 = -1;

    while (left < n && right < m)
    {
        if (nums1[left] <= nums2[right])
        {
            count++;
            left++;
        }
        else
        {
            count++;
            right++;
        }

        if (count == total/2 - 1)
        {
            element1 = min(nums1[left], nums2[right]);
        }
        else if (count == total/2)
        {
            element2 = min(nums1[left], nums2[right]);
            if (total % 2 == 1)
            {
                return (double)element2;
            }
            else
            {
                return (double)(element1 + element2)/2.0;
            }
        }
    }

    while (left < n)
    {
        left++;
        if (count == total/2 - 1)
        {
            element1 = min(nums1[left], nums2[right]);
        }
        else if (count == total/2)
        {
            element2 = min(nums1[left], nums2[right]);
            if (total % 2 == 1)
            {
                return (double)element2;
            }
            else
            {
                return (double)(element1 + element2)/2.0;
            }
        }
    }

    while (right < m)
    {
        right++;
        if (count == total/2 - 1)
        {
            element1 = min(nums1[left], nums2[right]);
        }
        else if (count == total/2)
        {
            element2 = min(nums1[left], nums2[right]);
            if (total % 2 == 1)
            {
                return (double)element2;
            }
            else
            {
                return (double)(element1 + element2)/2.0;
            }
        }
    }

    return -1;
}

double optimal_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();
    int m = nums2.size();
    if (n > m) return optimal_findMedianSortedArrays(nums2, nums1);

    int low = 0;
    int high = n;
    int left = (n + m + 1)/2;

    while (low <= high)
    {
        int mid1 = (low + high)/2;
        int mid2 = left - mid1;

        int l1 = INT_MIN;
        int l2 = INT_MIN;
        int r1 = INT_MAX;
        int r2 = INT_MAX;

        if (mid1-1 >= 0)
        {
            l1 = nums1[mid1-1]; 
        }
        if (mid2-1 >= 0)
        {
            l2 = nums2[mid2-1]; 
        }
        if (mid1 < n)
        {
            r1 = nums1[mid1]; 
        }
        if (mid2 < m)
        {
            r2 = nums2[mid2]; 
        }

        if (l1 <= r2 && l2 <= r1)
        {
            int total = n + m;
            if (total % 2 == 1)
            {
                return (double)max(l1, l2);
            }
            else
            {
                return (double)(max(l1, l2) + min(r1, r2))/2.0;
            }
        }
        else if (l1 <= r2 && l2 > r1)
        {
            low = mid1 + 1;
        }
        else
        {
            high = mid1 - 1;
        }
    }

    return -1;
}

int main()
{
    vector<int> v1 = {1,3,4,7,10,12};
    vector<int> v2 = {2,3,6,15};

    cout << brute_findMedianSortedArrays(v1, v2) << endl;
    cout << better_findMedianSortedArrays(v1, v2) << endl;
    cout << optimal_findMedianSortedArrays(v1, v2) << endl;

    return 0;
}