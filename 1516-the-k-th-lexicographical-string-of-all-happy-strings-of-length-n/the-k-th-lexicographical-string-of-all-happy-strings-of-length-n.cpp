class Solution {
public:
    string getHappyString(int n, int k) {
        string result = "";
        int count = 0;
        if (backtrack(n, k, "", count, result)) {
            return result;
        }
        return "";
    }

private:
    bool backtrack(int n, int k, string current, int &count, string &result) {
        if (current.size() == n) {
            count++;
            if (count == k) {
                result = current;
                return true;
            }
            return false;
        }
        
        for (char c : {'a', 'b', 'c'}) {
            if (current.empty() || current.back() != c) {
                if (backtrack(n, k, current + c, count, result)) {
                    return true;
                }
            }
        }
        return false;
    }
};