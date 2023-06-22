// Problem Link : https://www.codingninjas.com/studio/problems/maximum-meetings_8230795?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

bool static comparator(vector<int> &a, vector<int> &b)
{
    if (a[0] < b[0])
        return true;
    else if (a[0] > b[0])
        return false;
    else if (a[3] < b[3])
        return true;
    return false;
}

vector<int> maximumMeetings(vector<int> &start, vector<int> &end)
{

    vector<vector<int>> arr;
    int n = start.size();

    for (int i = 0; i < n; i++)
    {
        arr.push_back({end[i], start[i], end[i] - start[i], i + 1});
    }

    sort(arr.begin(), arr.end(), comparator);

    int end_time = -1;
    vector<int> ans;

    for (int i = 0; i < n; i++)
    {
        if (arr[i][1] > end_time)
        {
            ans.push_back(arr[i][3]);
            end_time = arr[i][0];
        }
    }

    return ans;
}