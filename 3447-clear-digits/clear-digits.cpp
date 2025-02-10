class Solution {
public:
    string clearDigits(string s) {
        stack<char>stk;
        for(int i=0;i<s.size();i++){
            if('0'<=s[i] && s[i]<='9' && !stk.empty()){
                stk.pop();
            }
            else{
               stk.push(s[i]);
            }
        }
        string str="";
        int n=stk.size();
        for(int i=0;i<n;i++){
           str+=stk.top();
           stk.pop();
        }
        reverse(str.begin(), str.end());
        return str;
    }
};