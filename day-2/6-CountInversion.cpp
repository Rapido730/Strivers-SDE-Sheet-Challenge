// Problem Link : https://www.codingninjas.com/codestudio/problems/count-inversions_615?leftPanelTab=1

#include <bits/stdc++.h>

long long inversion_count(long long *arr, int start, int mid, int end, long long *temp)
{
    int i = start;
    int j = mid + 1;
    int k = start;
    long long count = 0;

    while (i <= mid && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            count += (mid - i) + 1;
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        i++;
        k++;
    }

    while (j <= end)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (int i = start; i <= end; i++)
    {
        arr[i] = temp[i];
    }

    return count;
}

long long inversion(long long *arr, int start, int end, long long *temp)
{
    long long count = 0;
    if (start < end)
    {
        int mid = (start + end) >> 1;

        count += inversion(arr, start, mid, temp);
        count += inversion(arr, mid + 1, end, temp);
        count += inversion_count(arr, start, mid, end, temp);
    }
    return count;
}

long long getInversions(long long *arr, int n)
{
    long long temp[n];
    return inversion(arr, 0, n - 1, temp);
}