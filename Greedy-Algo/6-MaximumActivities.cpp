// Problem Link : https : // www.codingninjas.com/studio/problems/maximum-activities_8230800?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

        bool static comparator(vector<int> &m1, vector<int> &m2)
{
    if (m1[0] < m2[0])
        return true;
    else if (m1[0] > m2[0])
        return false;
    else if (m1[2] < m2[2])
        return true;
    return false;
}

int maximumActivities(vector<int> &start, vector<int> &end)
{
    vector<vector<int>> time;
    int n = end.size();
    for (int i = 0; i < n; i++)
    {
        vector<int> temp;
        temp.push_back(end[i]);
        temp.push_back(start[i]);
        temp.push_back(end[i] - start[i]);
        time.push_back(temp);
    }

    sort(time.begin(), time.end(), comparator);

    int end_time = -1;
    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (end_time <= time[i][1])
        {
            ans++;
            end_time = time[i][0];
        }
    }

    return ans;
}