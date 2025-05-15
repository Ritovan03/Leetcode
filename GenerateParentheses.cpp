class Solution {
public:
void generateParenthesisHelper(int open, int close, string current, vector<string>& result) {
    // If there are no more open or close parentheses to add, add the current combination to result
    if (open == 0 && close == 0) {
        result.push_back(current);
        return;
    }

    // If there are open parentheses left to add, add an open parenthesis
    if (open > 0) {
        generateParenthesisHelper(open - 1, close, current + "(", result);
    }

    // If the number of closing parentheses is greater than the open ones, add a closing parenthesis
    if (close > open) {
        generateParenthesisHelper(open, close - 1, current + ")", result);
    }
}
    vector<string> generateParenthesis(int n) {
    vector<string> result;
    generateParenthesisHelper(n, n, "", result);
    return result;
    }
};