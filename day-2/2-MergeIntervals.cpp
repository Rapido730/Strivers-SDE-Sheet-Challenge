// Problem Link : https://www.codingninjas.com/codestudio/problems/merge-intervals_8230700?challengeSlug=striver-sde-challenge&leftPanelTab=1

#include <bits/stdc++.h>
/*

    intervals[i][0] = start point of i'th interval
    intervals[i][1] = finish point of i'th interval

*/

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals)
{
    vector<vector<int>> ans;
    sort(intervals.begin(), intervals.end());
    int prev = -1;
    int n = intervals.size();
    for (int i = 0; i < n; i++)
    {
        if (prev >= intervals[i][0])
        {
            prev = max(prev, intervals[i][1]);
            ans[ans.size() - 1][1] = prev;
        }
        else
        {
            ans.push_back(intervals[i]);
            prev = intervals[i][1];
        }
    }

    return ans;
}
