// Problem Link : https://www.codingninjas.com/codestudio/problems/reverse-pairs_8230825?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
int merge(vector<int> &arr, int start, int mid, int end, vector<int> &temp)
{
    int i = start;
    int j = mid + 1;
    int k = start;

    int count = 0;
    for (i = start; i <= mid; i++)
    {
        while ((j <= end) && (arr[i] > (2 * (long long)(arr[j]))))
        {
            j++;
        }
        count += (j - (mid + 1));
    }

    j = mid + 1;
    i = start;

    while (i <= mid && j <= end)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
            // cout<<start<<" "<<end<<endl;
        }
        else
        {

            // count+= (j-(mid+1));

            temp[k++] = arr[j++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }

    while (j <= end)
    {
        temp[k++] = arr[j++];
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i];
    }

    return count;
}
int count_pairs(vector<int> &arr, int start, int end, vector<int> &temp)
{
    int count = 0;
    if (start < end)
    {
        int mid = (start + end) >> 1;
        count += count_pairs(arr, start, mid, temp);
        count += count_pairs(arr, mid + 1, end, temp);
        count += merge(arr, start, mid, end, temp);
    }

    return count;
}

int reversePairs(vector<int> &arr, int n)
{
    vector<int> temp(arr.size());

    return count_pairs(arr, 0, arr.size() - 1, temp);
}
