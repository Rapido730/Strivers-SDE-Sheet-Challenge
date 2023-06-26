// Problem Link : https: // practice.geeksforgeeks.org/problems/subset-sums2234/1

void solve(vector<int> arr, int N, vector<int> &sums, int sum)
{
    if (N == 0)
    {
        sums.push_back(sum);
        return;
    }

    solve(arr, N - 1, sums, sum + arr[N - 1]);
    solve(arr, N - 1, sums, sum);
}

vector<int> subsetSum(vector<int> &num)
{
    vector<int> sums;
    int n = num.size();
    solve(num, n, sums, 0);
    return sums;
}