#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

string countAndSay(int n) {
    if(n==0) return "";
    if(n==1) return "1";
    vector<string> nstr;
    nstr.push_back("1");
    int i,j=0;
    for(i=2;i<=n;i++){
        string str=nstr[i-2],tmp;
        int len=str.size(),cnt=1;
        while(j<len){
                cout<<j<<endl;
            if(j+1<len&&str[j]==str[j+1]){
                j++;
                cnt++;
            }
            else if(j==len-1||(j+1<len&&str[j]!=str[j+1])){
                tmp=tmp+"0"+str[j];
                cout<<tmp<<endl;
                j++;
                cnt=1;
            }
        }
        nstr.push_back(tmp);
    }
    return nstr[n-1];
}

int main()
{
    cout<<countAndSay(4);
}
