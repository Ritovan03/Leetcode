struct TrieNode {
    unordered_map<char, TrieNode*> children;
    string word = "";
};

class Solution {
public:
    vector<string> result;
    int rows, cols;

    void insertWord(TrieNode* root, const string& word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (!node->children.count(ch)) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {
        char c = board[i][j];
        if (!node->children.count(c)) return;

        TrieNode* nextNode = node->children[c];
        if (!nextNode->word.empty()) {
            result.push_back(nextNode->word);
            nextNode->word.clear();  // Avoid duplicates
        }

        board[i][j] = '#'; // Mark visited

        vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto [dx, dy] : directions) {
            int x = i + dx, y = j + dy;
            if (x >= 0 && x < rows && y >= 0 && y < cols && board[x][y] != '#') {
                dfs(board, x, y, nextNode);
            }
        }

        board[i][j] = c; 
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& word : words) {
            insertWord(root, word);
        }

        rows = board.size();
        cols = board[0].size();

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dfs(board, i, j, root);
            }
        }

        return result;
    }
};
