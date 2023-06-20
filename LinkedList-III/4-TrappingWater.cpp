// Problem Link : https : // www.codingninjas.com/studio/problems/trapping-rain-water_8230693?challengeSlug=striver-sde-challenge&leftPanelTab=0

#include <bits/stdc++.h>
long getTrappedWater(long *height, int n)
{

    vector<long> mxl(n, 0), mxr(n, 0);

    mxl[0] = (height[0]);

    for (int i = 1; i < n; i++)
    {
        mxl[i] = (max(mxl[i - 1], height[i]));
    }

    mxr[n - 1] = (height[n - 1]);

    for (int i = n - 2; i >= 0; i--)
    {
        mxr[i] = (max(mxr[i + 1], height[i]));
    }

    // reverse(mxr.begin(),mxr.end());

    long sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += (min(mxr[i], mxl[i]) - height[i]);
    }

    return sum;
}