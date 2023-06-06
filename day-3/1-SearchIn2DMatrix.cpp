// Problem Link : https://www.codingninjas.com/codestudio/problems/search-in-a-2d-matrix_8230773?challengeSlug=striver-sde-challenge&leftPanelTab=1

int binary_search(vector<int> &arr, int target)
{
    int low = 0;
    int high = arr.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (arr[mid] == target)
        {
            return mid;
        }
        else if (arr[mid] < target)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return -1;
}

bool searchMatrix(vector<vector<int>> &mat, int target)
{
    int low = 0;
    int high = mat.size() - 1;
    int n = mat[0].size();

    while (low <= high)
    {
        int mid = (low + high) >> 1;
        if (mat[mid][0] <= target && mat[mid][n - 1] >= target)
        {
            return (binary_search(mat[mid], target) != -1);
        }
        else if (mat[mid][0] > target)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return false;
}