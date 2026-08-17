class Solution {
public:
    string charCount(string& str) {

        string count (26, 0);

        for (char c : str) {
            count[c - 'a']++;
        }
        // array<uint8_t, 26> counts = {};

        // for (uint8_t i = 0; i < str.size(); i++) {
        //     char c = str[i];
        //     counts[c - 'a'] = counts[c - 'a'] + 1;
        // }

        return count;
    }

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> groups = {};

        for (int i = 0; i < strs.size(); i++) {
            string& s = strs[i];
            string counts = charCount(s);

            groups[counts].push_back(s);
        }

        vector<vector<string>> res = {};

        for (auto& [key, val] : groups) {
            res.push_back(val);
        }

        return res;
    }
};
