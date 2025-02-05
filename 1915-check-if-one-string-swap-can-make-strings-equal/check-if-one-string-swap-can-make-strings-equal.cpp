class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        vector<int> ch;
        for(int i = 0; i < s2.size(); i++) {
            if(s2[i] != s1[i]) {
                count++;
                ch.push_back(i);
            }
            if(count > 2) return false;
        }
        if(count == 0) return true;
        if(count == 1) return false;
        swap(s2[ch[0]], s2[ch[1]]);
        return s1 == s2;
    }
};
