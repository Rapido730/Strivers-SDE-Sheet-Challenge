// Problem Link : https://www.codingninjas.com/studio/problems/remove-duplicates-from-sorted-array_8230811?challengeSlug=striver-sde-challenge&leftPanelTab=0

int removeDuplicates(vector<int> &nums, int n)
{

    int j = 0;
    for (int i = 1; i < n; i++)
    {
        if (nums[i] != nums[j])
        {

            nums[++j] = nums[i];
        }
    }

    return j + 1;
}