class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n=blocks.size();
        if(k>n){return -1;}
        int black=0;
        int minop=INT_MAX;
        for(int i=0;i<k;i++){
            if(blocks[i]=='B'){
                black++;
            }
        }
        minop=k-black;
        int i=1,j=k;
        while(j<n){
            if(blocks[j]=='B' && blocks[i-1]=='W'){
                black++;
            }
            else if(blocks[j]=='W' && blocks[i-1]=='B'){
                black--;
            }
            minop=min(minop,k-black);
            i++;
            j++;
        }
return minop;
    }
};