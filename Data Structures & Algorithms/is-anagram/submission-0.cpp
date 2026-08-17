class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        }
        
        array<int, 26> counts = {};

        for (int i = 0; i < counts.size(); i++) {
            counts[i] = 0;
        }

        for (int i = 0; i < s.size(); i++) {
            counts[s[i] - 'a'] = counts[s[i] - 'a'] + 1;
        }
        
        for (int i = 0; i < t.size(); i++) {
            if (counts[t[i] - 'a'] == 0) {
                return false;
            } else {
                counts[t[i] - 'a'] = counts[t[i] - 'a'] - 1;
            }
        }

        for (int i = 0; i < counts.size(); i++) {
            if (counts[i] > 0) {
                return false;
            }
        }

        return true;
    }
};
