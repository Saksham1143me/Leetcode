class Solution {
public:
    int minOperations(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                int j=i;
                count++;
                while(j<i+3){
                    if(j>=n) return -1;
                    nums[j]=!nums[j];
                    j++;
                }
            }
        }
        return count;
    }
};