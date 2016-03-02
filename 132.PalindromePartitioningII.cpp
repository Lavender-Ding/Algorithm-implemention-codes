#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

vector<int> isPalindrome(string s,int head,int now)
{
    vector<int> endpos;
    bool flag1=true,flag2=true;
    int i=now-head;
    while(i>0)
    {
        if(s[now-i]!=s[now+i])
        {
            flag1=false;
            break;
        }
        else i--;
    }
    i=now-head;
    while(i>=0)
    {
        if(now+i+1>=s.size()||s[now-i]!=s[now+i+1])
        {
            flag2=false;
            break;
        }
        else i--;
    }
    if(flag1==true) endpos.push_back(now+now-head);
    if(flag2==true) endpos.push_back(now+now-head+1);
    return endpos;
}

int minCut(string s)
{
    int len=s.size();
    vector<vector<int> > palindrome;
    vector<int> row;
    row.assign(len,0);
    palindrome.assign(len,row);
    int mincut=len;
    if(len==0) return mincut;
    vector<int> cutnum;
    cutnum.assign(len+1,len);
    cutnum[len]=0;
    for(int head=len-1;head>=0;head--)
    {
        for(int rear=head;rear<len;rear++)
        {
            if(s[head]==s[rear]&&(rear-head<2||palindrome[head+1][rear-1]==1))
            {
                palindrome[head][rear]=1;
                cutnum[head]=min(cutnum[rear+1]+1,cutnum[head]);
            }
        }
    }
    for(int i=0;i<cutnum.size();i++) cout<<cutnum[i]<<' ';
    cout<<endl;
    mincut=cutnum[0];
    return mincut-1;
}

int main()
{
    ifstream fin("in.txt");
    string s;
    fin>>s;
    for(int i=0;i<s.size();i++) cout<<s[i];
    cout<<endl;
    cout<<minCut(s);
    return 0;
}

/*
vector<int> isPalindrome(string s,int head,int now)
{
    vector<int> endpos;
    bool flag1=true,flag2=true;
    int i=now-head;
    while(i>0)
    {
        if(s[now-i]!=s[now+i])
        {
            flag1=false;
            break;
        }
        else i--;
    }
    i=now-head;
    while(i>=0)
    {
        if(now+i+1>=s.size()||s[now-i]!=s[now+i+1])
        {
            flag2=false;
            break;
        }
        else i--;
    }
    if(flag1==true) endpos.push_back(now+now-head);
    if(flag2==true) endpos.push_back(now+now-head+1);
    return endpos;
}

class Solution {
public:
    int minCut(string s) {
        int len=s.size();
        int mincut=len;
        if(len==0) return mincut;
        vector<int> cutnum;
        cutnum.assign(len+1,0);
        for(int head=len-1;head>=0;head--)
        {
            for(int i=head;i<=head+(s.size()-1-head)/2;i++)
            {
                vector<int> endpos=isPalindrome(s,head,i);
                for(int j=0;j<endpos.size();j++)
                {
                    cutnum[head]=1+cutnum[endpos[j]+1];
                }
            }
        }
        mincut=cutnum[0];
        return mincut-1;
    }
};
*/
