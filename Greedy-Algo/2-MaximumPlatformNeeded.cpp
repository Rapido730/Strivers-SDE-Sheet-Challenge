// Problem Link : https://www.codingninjas.com/studio/problems/minimum-number-of-platforms_8230720?challengeSlug=striver-sde-challenge&leftPanelTab=0

int calculateMinPatforms(int arr[], int dep[], int n)
{
    sort(arr, arr + n);
    sort(dep, dep + n);

    int i = 1, j = 0;
    int ans = 1;
    int count = 1;
    while (i < n && j < n)
    {
        if (arr[i] <= dep[j])
        {
            count++;
            i++;
        }
        else
        {
            count--;
            j++;
        }

        ans = max(ans, count);
    }

    return ans;
}