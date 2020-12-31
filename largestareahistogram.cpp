class Solution {
public:
    vector<int> nsol,nsor;
    void smallerSides(vector<int>& h){
        stack<int> st;
        int n=h.size();
        nsol.resize(n,-1);
        nsor.resize(n,n);
        for(int i=0;i<n;i++){
            while(!st.empty() && h[st.top()]>h[i]){
                nsor[st.top()]=i;
                st.pop();
            }
            if(!st.empty()){
                if(h[st.top()]<h[i])nsol[i]=st.top();
                else nsol[i]=nsol[st.top()];
            }
            st.push(i);
        }
    }
    int largestRectangleArea(vector<int>& h) {
        smallerSides(h);
        int ans=0,n=h.size();
        for(int i=0;i<n;i++){
            ans=max(ans,(nsor[i]-nsol[i]-1)*h[i]);
        }
        return ans;
    }
};