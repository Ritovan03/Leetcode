// class Solution {
// public:
//     unordered_map<string, string> dict;

//     int helper(string s, string placeholder, int length) {
//         // Base case: if we've reached the end and placeholder is a valid decoding
//         if (length == s.size()) {
//             if (dict.find(placeholder) != dict.end()) return 1;
//             return 0;
//         }

//         // If the current placeholder is invalid, this path is dead
//         if (dict.find(placeholder) == dict.end()) {
//             return 0;
//         }

//         // Continue by trying to extend the current decoding
//         string nextChar = string(1, s[length]); // s[length] is safe now
//         return helper(s, placeholder + nextChar, length + 1) + helper(s, nextChar, length + 1);
//     }

//     int numDecodings(string s) {
//         // Build the dictionary
//         for (int i = 1; i <= 26; i++) {
//             dict[to_string(i)] = string(1, 'A' + i - 1);
//         }

//         if (s.empty()) return 0;
//         return helper(s, string(1, s[0]), 1);  // start with first character, length = 1
//     }
// };

class Solution {
public:
    unordered_map<string, string> dict;
    unordered_map<string, unordered_map<int, int>> memo;

    int helper(string &s, string placeholder, int length) {
        // Memo check
        if (memo[placeholder].count(length)) return memo[placeholder][length];

        if (length == s.size()) {
            return memo[placeholder][length] = dict.count(placeholder) ? 1 : 0;
        }

        if (!dict.count(placeholder)) {
            return memo[placeholder][length] = 0;
        }

        string nextChar = string(1, s[length]);

        // Two options: continue building or start new placeholder
        int ans = helper(s, placeholder + nextChar, length + 1) +
                  helper(s, nextChar, length + 1);

        return memo[placeholder][length] = ans;
    }

    int numDecodings(string s) {
        for (int i = 1; i <= 26; i++) {
            dict[to_string(i)] = string(1, 'A' + i - 1);
        }

        if (s.empty()) return 0;
        return helper(s, string(1, s[0]), 1);
    }
};


