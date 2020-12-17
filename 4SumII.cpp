class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int,int> m;
        int n=A.size(),ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                m[A[i]+B[j]]++;
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                ans+=m[-(C[i]+D[j])];
        }
        return ans;
    }
    
};