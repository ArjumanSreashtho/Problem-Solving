void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int l = nums1.size()-1;
    int i = m-1, j = n-1;
    while(i >= 0 && j >= 0)
    {
        if(nums1[i] > nums2[j])
        {
            nums1[l] = nums1[i];
            i--;
        }
        else
        {
            nums1[l] = nums2[j];
            j--;
        }
        l--;
    }
    while(i >= 0)
    {
        nums1[l] = nums1[i];
        i--;
        l--;
    }
    while(j >= 0)
    {
        nums1[l] = nums2[j];
        j--;
        l--;
    }
}