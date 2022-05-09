/*
link: https://leetcode.com/problems/merge-sorted-array/
TC: O(m+n)
SC: O(1)
Method: Since there is space in the array nums1 so start filling array from that end and lastly fill the left out elements in nums2.
*/


void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{
    int i = m - 1, j = n - 1, k = n + m - 1;
    while (i >= 0 && j >= 0)
    {
        if (nums1[i] > nums2[j])
            nums1[k--] = nums1[i--];
        else
            nums1[k--] = nums2[j--];
    }
    while (j >= 0)
        nums1[k--] = nums2[j--];
}