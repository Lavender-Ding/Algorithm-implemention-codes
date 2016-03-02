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

void allpartition(string s,int head,vector<string> one,vector<vector<string> > &result)
{
    if(head>=s.size())
    {
        result.push_back(one);
        return;
    }
    for(int i=head;i<=head+(s.size()-1-head)/2;i++)
    {
        vector<int> endpos=isPalindrome(s,head,i);
        for(int j=0;j<endpos.size();j++)
        {
            string ss=s.substr(head,endpos[j]-head+1);
            one.push_back(ss);
            allpartition(s,endpos[j]+1,one,result);
            one.pop_back();
        }
    }
    return;
}

vector<vector<string> > partition(string s)
{
    vector<vector<string> > result;
    if(s.size()==0) return result;
    int head=0;
    vector<string> one;
    allpartition(s,head,one,result);
    return result;
}

int main()
{
    ifstream fin("in.txt");
    string s;
    fin>>s;
    for(int i=0;i<s.size();i++) cout<<s[i];
    cout<<endl;

    //vector<int> result=isPalindrome(s,8,8);
    //for(int i=0;i<result.size();i++) cout<<result[i]<<' ';

    vector<vector<string> > result=partition(s);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
        {
            for(int k=0;k<result[i][j].size();k++) cout<<result[i][j][k];
            cout<<' ';
        }
        cout<<endl;
    }
    return 0;
}
