class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        map<int,int>prevcount;
        map<int,int>count;
        int ind=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            count[nums[i]]++;
        }
        for(int i=0;i<n;i++){
            prevcount[nums[i]]++;
            cout << prevcount[nums[i]] << (ind+1)/2 << "prev"<<  endl;
            cout << count[nums[i]]-prevcount[nums[i]] << (n-ind)/2<< "rem"  <<endl;
            if(prevcount[nums[i]]>((ind+1)/2) && count[nums[i]]-prevcount[nums[i]]>((n-ind-1)/2)){
             return ind;
            }
            ind++;
        }
        return -1;
    }
};