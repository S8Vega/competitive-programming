class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int rep1 = 0, rep2 = 0;

        bool st1[101], st2[101];
        for (int i = 0; i < nums1.size(); i++) {
            st1[nums1[i]] = true;
        }
        for (int i = 0; i < nums2.size(); i++) {
            st2[nums2[i]] = true;
        }

        for (int i = 0; i < nums1.size(); i++) {
            rep1 += st2[nums1[i]];
        }
        for (int i = 0; i < nums2.size(); i++) {
            rep2 += st1[nums2[i]];
        }
        return {rep1, rep2};
    }
};