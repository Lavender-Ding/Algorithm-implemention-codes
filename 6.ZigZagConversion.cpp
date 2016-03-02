#include <iostream>
#include <fstream>
#include <cstring>
#include <math.h>

using namespace std;

string convert(string s, int numRows)
{
    string ss;
    if(s.size()==0) return ss;
    if(s.size()<=numRows||numRows==1) return s;
    int step=numRows+numRows-2,i,k;
    for(i=0;i<numRows;i++)
    {
        ss+=s[i];
        int l=step-i*2,r=i*2;
        for(k=i;k<s.size();k+=step)
        {
            if(k+l<s.size()&&l!=0) ss+=s[k+l];
            if(k+l+r<s.size()&&r!=0) ss+=s[k+l+r];
        }
    }
    return ss;
}

int main()
{
    ifstream fin("in.txt");
    string c;
    string s;
    while(!fin.eof())
    {
        c=fin.get();
        s+=c;
    }
    for(int i=0;i<s.size();i++) cout<<s[i];
    cout<<endl;
    string ss=convert(s,5);
    for(int i=0;i<ss.size();i++) cout<<ss[i];
    return 0;
}
