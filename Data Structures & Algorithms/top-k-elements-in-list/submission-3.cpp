class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq = {};
        vector<vector<int>> groups(nums.size() + 1);

        for (int x : nums) {
            freq[x]++;
        }

        for (auto& [k, v] : freq) {
            groups[v].push_back(k);
        }

        vector<int> res = {};
        for (int i = groups.size() - 1; i >= 0 && res.size() < k; i--) {
            for (int x : groups[i]) {
                res.push_back(x);
                if (res.size() == k) {
                    break;
                }
            }
        }
    
        return res;
    }
};
