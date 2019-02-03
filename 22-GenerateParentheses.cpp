class Solution {
public:
    void recursiveGenerateParenthesis(vector<string> &results, string &generatedString, int depth, int remain) {
        if (depth == 0 && remain == 0) {
            results.push_back(string(generatedString));
            generatedString.pop_back();
            return;
        }

        if (remain > 0 && depth + 1 <= remain) {
            // judge '('
            generatedString.push_back('(');
            recursiveGenerateParenthesis(results, generatedString, depth + 1, remain);
        }

        if (depth > 0 && remain > 0) {
            // judge ')'
            generatedString.push_back(')');
            recursiveGenerateParenthesis(results, generatedString, depth - 1, remain - 1);
        }

        generatedString.pop_back();
    }

    vector<string> generateParenthesis(int n) {
        vector<string> results;

        if (n > 0) {
            string generatedString = string("(");
            recursiveGenerateParenthesis(results, generatedString, 1, n);
        }

        return results;
    }
};