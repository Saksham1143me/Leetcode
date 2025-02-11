class Solution {
public:
    string removeOccurrences(string s, string part) {
        string stk;
        int n = part.size();
        char last = part.back();

        for (char ch : s) {
            stk.push_back(ch);

            if (ch == last && stk.size() >= n) {
                if (stk.substr(stk.size() - n) == part) {
                    stk.erase(stk.size() - n);
                }
            }
        }
        return stk;
    }
};