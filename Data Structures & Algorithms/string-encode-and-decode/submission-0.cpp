class Solution {
public:
    string encode(vector<string>& strs) {
        std::ostringstream sb;
        sb << std::to_string(strs.size());

        for (string s : strs) {
            sb << '|' << std::to_string(s.length()) << '|' << s;
        }

        return sb.str();
    }

    vector<string> decode(string s) {
        int i = 0;
        int n = read_int(s, i);

        vector<string> res = {};
        for (int k = 0; k < n; k++) {
            int len = read_int(s, i);
            string val = read_string(s, len, i);
            res.push_back(val);
        }

        return res;
    }

private:
    int read_int(string s, int& i) {
        std::ostringstream sb;
        while (s[i] != '|' && i < s.length()) {
            sb << s[i++];
        };

        cout << sb.str();

        i++;

        return std::stoi(sb.str());
    }

    string read_string(string s, int len, int& i) {
        std::ostringstream sb;

        for (int j = 0; j < len && i < s.length(); j++) {
            sb << s[i++];
        }

        return sb.str();
    }
};
