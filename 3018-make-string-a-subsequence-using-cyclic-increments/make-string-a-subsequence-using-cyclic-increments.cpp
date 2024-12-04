class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
    int i = 0, j = 0;
    int n = str1.size(), m = str2.size();
    
    while (i < n && j < m) {
        char char1 = str1[i];
        char char2 = str2[j];
        if (char1 == char2 || (char1 + 1 - 'a') % 26 + 'a' == char2) {
            j++;
        }
        
        i++;
    }
    
    return j == m;
}
};