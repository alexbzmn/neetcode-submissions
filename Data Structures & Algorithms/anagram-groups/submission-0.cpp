class Solution {
public:
    array<int, 26> charCount(string& str) {
        array<int, 26> counts = {};

        for (int i = 0; i < str.size(); i++) {
            char c = str[i];
            counts[c - 'a'] = counts[c - 'a'] + 1;
        }

        return counts;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<array<int, 26>, vector<string>> groups = {};

        for (int i = 0; i < strs.size(); i++) {
            string& s = strs[i];
            array<int, 26> counts = charCount(s);

            if (groups.contains(counts)) {
                groups[counts].push_back(s);
            } else {
                groups[counts] = vector<string>{s};
            }
        }

        vector<vector<string>> res = {};

        for (auto& [key, val] : groups) {
            res.push_back(val);
        }

        return res;
    }
};
