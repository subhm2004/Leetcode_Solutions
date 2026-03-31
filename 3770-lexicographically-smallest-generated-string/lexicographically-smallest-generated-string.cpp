class Generator {
public:
    string createPattern(string patternType, string baseString) {
        int n = patternType.size();
        int m = baseString.size();
        int totalLen = n + m - 1;

        if (m == 0) return string(n, 'a');

        vector<char> result(totalLen, '?');
        vector<bool> locked(totalLen, false);

        for (int i = 0; i < n; ++i) {
            if (patternType[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    int pos = i + j;
                    if (pos >= totalLen) break;
                    char required = baseString[j];

                    if (result[pos] != '?' && result[pos] != required) {
                        return "";
                    }

                    if (result[pos] == '?') {
                        result[pos] = required;
                        locked[pos] = true;
                    }
                }
            }
        }

        for (int i = 0; i < totalLen; ++i) {
            if (result[i] == '?') {
                result[i] = 'a';
            }
        }

        for (int i = 0; i <= totalLen - m; ++i) {
            if (patternType[i] == 'F') {
                bool matches = true;
                for (int j = 0; j < m; ++j) {
                    if (result[i + j] != baseString[j]) {
                        matches = false;
                        break;
                    }
                }
                if (!matches) continue;

                bool modified = false;
                for (int j = m - 1; j >= 0; --j) {
                    int pos = i + j;
                    if (!locked[pos]) {
                        result[pos] = (baseString[j] == 'a') ? 'b' : 'a';
                        modified = true;
                        break;
                    }
                }
                if (!modified) return "";
            }
        }

        return string(result.begin(), result.end());
    }
};

class Solution {
public:
    string generateString(string str1, string str2) {
        Generator gen;
        return gen.createPattern(str1, str2);
    }
};
