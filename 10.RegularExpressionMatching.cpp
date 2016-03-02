#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

bool isMatch(string s, string p)
{
    int slen=s.size(),plen=p.size(),i,j;
    bool dp[slen+1][plen+1];
    dp[0][0]=true;
    for(i=0;i<slen;i++) dp[i+1][0]=false;
    for(i=0;i<plen;i++) dp[0][i+1]=dp[0][i-1]&&p[i]=='*'&&i>0;
    for(i=0;i<=slen;i++)
        for(j=0;j<=plen;j++)
        {
            if(p[j]!='*') dp[i+1][j+1]=dp[i][j]&&(s[i]==p[j]||p[j]=='.');
            else dp[i+1][j+1]=dp[i+1][j-1]&&j>0||dp[i+1][j]||dp[i][j+1]&&j>0&&(p[j-1]=='.'||p[j-1]==s[i]);
        }
    return dp[slen][plen];
}

int main()
{
    ifstream fin("in.txt");
    string s,p;
    fin>>s>>p;
    cout<<s<<' '<<p<<endl;
    cout<<isMatch(s,p);
    return 0;
}
