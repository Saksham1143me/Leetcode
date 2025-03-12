class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        int neg=0,zero=0;
        while(i<n && nums[i]<0){
            neg++;
            i++;
        }
        while(i<n && nums[i]==0){
            zero++;
            i++;
        }
        return max(neg,n-neg-zero);
    }
};