class Solution {
public:
    int kthFactor(int n, int k) {
        // if(k==1)return 1;
        int div=1,i=0;
        while(div<=n){
            if(n%div==0){
                i++;
            }
            if(i==k)return div;
            div++;
        }
        return -1;
    }
};