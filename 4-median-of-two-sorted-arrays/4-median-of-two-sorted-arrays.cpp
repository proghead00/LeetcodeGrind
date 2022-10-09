class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        // BS on the smaller array
        if (nums1.size() > nums2.size()) nums1.swap(nums2);

        int n1 = nums1.size();
        int n2 = nums2.size();

        int l = 0, h = n1;
        int l1, l2, r1, r2;
        int total = n1 + n2;

        while (l <= h) {

            int cut1 = (l + h) / 2;
            int cut2 = (total + 1) / 2 - cut1;

            l1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            l2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];

            r1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            r2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            if (l1 <= r2 and l2 <= r1) {
                if (total & 1) return max(l1, l2);
                else return (max(l1, l2) + min(r1, r2)) / 2.0;
            }
            else {
                if (l1 > r2)
                    h = cut1 - 1;

                else
                    l = cut1 + 1;
            }
        }

        return 0.0;
    }
};