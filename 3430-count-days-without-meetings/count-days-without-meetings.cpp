class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
       sort(meetings.begin(), meetings.end(), [](const vector<int>& a, const vector<int>& b) {
        return a[0] < b[0];
    });
        int dayz=0,lastday=INT_MIN;
        int n=meetings.size();
        for(int i=0;i<n;i++){
            if(i==0){
                dayz+=meetings[i][0]-1;
            }
            else if(lastday>=meetings[i][0]){
            lastday=max(lastday,meetings[i][1]);
            continue;
            }
            else{
                if(meetings[i][0]>meetings[i-1][1]){
                    dayz+=meetings[i][0]-lastday-1;
                    cout << meetings[i][0] << " ";
                    cout << dayz << " ";
                }
            }
            lastday=max(lastday,meetings[i][1]);
        }
        return dayz+days-lastday;
    }
};