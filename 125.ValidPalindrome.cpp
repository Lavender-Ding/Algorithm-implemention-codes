#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool isPalindrome(string s)
{
    int l=0,r=s.size()-1;
    while(l<r)
    {
        while(!(s[l]>=65&&s[l]<=90||s[l]>=97&&s[l]<=122||s[l]>=48&&s[l]<=57)&&l<r) l++;
        while(!(s[r]>=65&&s[r]<=90||s[r]>=97&&s[r]<=122||s[r]>=48&&s[r]<=57)&&l<r) r--;
        if(s[l]==s[r]||s[l]-s[r]==32||s[r]-s[l]==32)
        {
            l++;
            r--;
        }
        else return false;
    }
    return true;
}

int main()
{
    ifstream fin("in.txt");
    string s;
    string tmp;
    while(!fin.eof())
    {
        tmp=fin.get();
        s=s+tmp;
    }
    for(int i=0;i<s.size();i++) cout<<s[i];
    cout<<endl;
    cout<<isPalindrome(s);
    return 0;
}
