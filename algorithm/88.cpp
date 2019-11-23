class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int k = m + n - 1;
        m--;
        n--;
        // invariant: nums1[k+1..m+n-1] is merged and sorted array
        //   nums1[0..m] is not merged and nums2[0..n] is not merged
        while (k >= 0) {
            if (m == -1 || (m != -1 && n != -1 && nums2[n] > nums1[m])) {
                nums1[k] = nums2[n];
                n--;
            } else {
                nums1[k] = nums1[m];
                m--;
            }
            k--;
        }
    }
};
