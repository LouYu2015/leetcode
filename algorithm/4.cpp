class Solution {
public:
    // This is O(n) solution
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0;
        int n1 = nums1.size(), n2 = nums2.size();
        int n = (n1 + n2) / 2;
        if ((n1 + n2) % 2 == 0)
            n--;
        while (i + j < n) {
            if (j >= n2 || (i < n1 && nums1[i] < nums2[j])) {
                i++;
            } else {
                j++;
            }
        }
        double result = (j >= n2 || (i < n1 && nums1[i] < nums2[j])) ? nums1[i] : nums2[j];
        if ((n1 + n2) % 2 == 0) {
            if (j >= n2 || (i < n1 && nums1[i] < nums2[j])) {
                i++;
            } else {
                j++;
            }
            int second_largest = (j >= n2 || (i < n1 && nums1[i] < nums2[j])) ? nums1[i] : nums2[j];
            result = (result + second_largest) / 2;
        }
        return result;
    }
};
