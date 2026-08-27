class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> unseen = {};
        for (int i = 0; i < nums.size(); i++) {
            unseen.insert(nums[i]);
        }

        int res = 0;
        unordered_set<int> seen = {};

        for (int i = 0; i < nums.size(); i++) {
            int key = nums[i];
            if (seen.contains(key)) {
                continue;
            }
            seen.insert(key);
            // traverse neighbours back and forth and count their total count            
            int curr = 1;
            int b = key - 1;
            int f = key + 1;

            while (unseen.contains(b) && !seen.contains(b)) {
                seen.insert(b);
                curr += 1;
                b--;
            }

            while (unseen.contains(f) && !seen.contains(f)) {
                seen.insert(f);
                curr += 1;
                f++;
            }

            res = max(res, curr);
        }

        return res;
    }
};
