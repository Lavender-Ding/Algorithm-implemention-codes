#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stack>
#include <cmath>
#include <map>
#include <cstring>
#include <bitset>

using namespace std;

int maxProduct(vector<string>& words)
{
    int i,j,len=words.size(),val,maxPro=0;
    int nums[len],siz[len];
    for(i=0;i<len;i++)
    {
        val=0;
        siz[i]=words[i].size();
        for(j=0;j<siz[i];j++)
            val=(1<<words[i][j]-'a')|val;
        nums[i]=val;
    }
    for(i=0;i<len;i++)
        for(j=i+1;j<len;j++)
            if((nums[i]&nums[j])==0) maxPro=max(maxPro,siz[i]*siz[j]);
    return maxPro;
}

int main()
{
    ifstream fin("in.txt");
    vector<string> words;
    string tmp;
    while(!fin.eof())
    {
        fin>>tmp;
        words.push_back(tmp);
    }
    for(int i=0;i<words.size();i++) cout<<words[i]<<' ';
    cout<<endl;
    cout<<maxProduct(words);
    return 0;
}
