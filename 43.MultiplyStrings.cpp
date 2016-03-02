class Solution {
public:
    string multiply(string num1, string num2) {
        int m=num1.size(),n=num2.size(),i,j;
        vector<int> ans(m+n,0);
        for(i=m-1;i>=0;i--){
            for(j=n-1;j>=0;j--){
                int tmp=(num1[i]-'0')*(num2[j]-'0');
                int p1=i+j,p2=p1+1;
                tmp+=ans[p2];
                ans[p1]+=tmp/10;
                ans[p2]=tmp%10;
            }
        }
        string anstr;
        if(m==0||n==0) return anstr;
        for(i=0;i<m+n&&ans[i]==0;i++);
        if(i==m+n) return "0";
        for(;i<m+n;i++) anstr+=to_string(ans[i]);
        return anstr;
    }
};
