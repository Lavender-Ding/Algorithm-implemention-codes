#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

bool isNumber(string s)
{
    int len=s.size(),i=0,j=0;
    if(len==0) return false;
    if(len==1)
    {
        if(!(s[0]>='0'&&s[0]<='9')) return false;
    }
    if(s[0]==' ')
    {
        for(i=0;i<len&&s[i]==' ';i++);
        if(i==len) return false;
        else j=i;
    }
    if(s[j]=='-'||s[j]=='+') j++;
    int eflag=0;
    int dflag=0;
    int sflag=0;
    for(i=j;i<len;i++)
    {
        if(sflag>0&&s[i]!=' ') return false;
        if(s[i]=='-'||s[i]=='+')
        {
            if(s[i-1]!='e'||i==len-1) return false;
            else continue;
        }
        if(s[i]!=' '&&s[i]!='.'&&s[i]!='e'&&(!(s[i]>='0'&&s[i]<='9'))) return false;
        if(s[i]=='e')
        {
            if(eflag==1) return false;
            if(i>j&&i!=len-1&&(s[i-1]>='0'&&s[i-1]<='9'||s[i-1]=='.'&&i-1!=j)) eflag++;
            else return false;
        }
        if(s[i]=='.')
        {
            if(dflag==1||dflag==0&&eflag==1) return false;
            else if(dflag==0&&eflag==0)
            {
                if(i>j&&(s[i-1]>='0'&&s[i-1]<='9'||s[i-1]==' ')||i==j&&j!=len-1) dflag++;
                else return false;
            }
        }
        if(s[i]==' ')
        {
            if(sflag>0)
            {
                sflag++;
                continue;
            }
            if(s[i-1]>='0'&&s[i-1]<='9') sflag++;
            else if(s[i-1]=='.'&&i!=1&&s[i-2]>='0'&&s[i-2]<='9') sflag++;
            else return false;
        }
    }
    return true;
}

int main()
{
    string s=" -54.53061";
    for(int i=0;i<s.size();i++) cout<<s[i];
    cout<<endl;
    cout<<isNumber(s);
    return 0;
}
