// Problem Link : https://www.codingninjas.com/studio/problems/job-sequencing-problem_8230832?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>

bool static comparator(vector<int> &a, vector<int> &b)
{
    return a[1] > b[1];
}

int jobScheduling(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    sort(jobs.begin(), jobs.end(), comparator);
    int maxi = jobs[0][0];
    for (int i = 1; i < n; i++)
    {
        maxi = max(maxi, jobs[i][0]);
    }

    int slot[maxi + 1];

    for (int i = 0; i <= maxi; i++)
        slot[i] = -1;

    int countJobs = 0, jobProfit = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = jobs[i][0]; j > 0; j--)
        {
            if (slot[j] == -1)
            {
                slot[j] = i;
                countJobs++;
                jobProfit += jobs[i][1];
                break;
            }
        }
    }

    return jobProfit;
}
