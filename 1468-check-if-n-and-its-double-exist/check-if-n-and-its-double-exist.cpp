class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(binarySearch(i,arr)){
                return true;
            }
        }
        return false;
    }
private:
    bool binarySearch(int i,vector<int>& arr){
        int lo=0,hi=arr.size()-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(arr[mid]<2*arr[i]){
               lo=mid+1;
            }
            else if(arr[mid]==2*arr[i] && i!=mid){
                return true;
            }
            else{
                hi=mid-1;
            }
        }
        return false;
    }
};