class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool>prime(right+1,true);
        prime[0]=false;
        prime[1]=false;
        int minDiff=INT_MAX;
        for(int i=2;i*i<=right;i++){
          if(prime[i]==true){
            for(int j=i*i;j<=right;j+=i){
                prime[j]=false;
            }
          }
        }
        vector<int>ans={-1,-1};
        int a,b;
        for(int i=left;i<=right;i++){
            if(prime[i]){
              if(ans[0]==-1){
                ans[0]=i;
                a=i;
              }
              else if(ans[0]!=-1 && ans[1]==-1){
                ans[1]=i;
                b=i;
                minDiff=min(minDiff,ans[1]-ans[0]);
              }
              else{
                 a=b;
                 b=i;
                 if(minDiff>b-a){
                    cout << minDiff << " ";
                    ans[0]=a;
                    ans[1]=b;
                minDiff=b-a;
                 }
              }
            }
        }
        if(ans[1]==-1){
            return {-1,-1};
        }
        return ans;
    }
};