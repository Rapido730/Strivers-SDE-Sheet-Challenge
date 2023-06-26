// Problem Link : https://www.codingninjas.com/studio/problems/k-th-permutation-sequence_8230822?challengeSlug=striver-sde-challenge&leftPanelTab=1

vector<int> fact;
string solve(vector<int> &arr, int k)
{
    string cur = "";
    k = k - 1;
    while (arr.size() > 0)
    {
        int n = arr.size();
        cur = cur + to_string(arr[k / fact[n - 1]]);
        arr.erase(arr.begin() + int(k / fact[n - 1]));

        k = k % fact[n - 1];
    }

    return cur;
}

string kthPermutation(int n, int k)
{
    vector<int> arr;
    fact = vector<int>(21, 0);
    fact[0] = 1;
    for (int i = 0; i < n; i++)
    {
        arr.push_back(i + 1);
    }
    for (int i = 0; i < 12; i++)
    {

        fact[i + 1] = fact[i] * (i + 1);
    }

    return solve(arr, k);
}
