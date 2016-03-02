#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include <sstream>

using namespace std;

string tmp;

void Abbreviation(string word,vector<string>& abbr,int h,int r,int len)
{
    for(int i=1;i<=len;i++)
    {
        //cout<<i<<' '<<len<<' ';
        stringstream stream;
        stream<<i;
        stream>>tmp;
        string one_revise=word.substr(0,h)+tmp+word.substr(h+i,len-i);
        abbr.push_back(one_revise);
        //cout<<one_revise<<endl;
        r=one_revise.size();
        for(int j=h+tmp.size()+1;j<r;j++)
            Abbreviation(one_revise,abbr,j,r,r-j);
    }
}

vector<string> generateAbbreviations(string word)
{
    vector<string> abbr;
    abbr.push_back(word);
    int head=0,rear=word.size();
    for(int h=head;h<rear;h++) Abbreviation(word,abbr,h,rear,rear-h);
    return abbr;
}

int main()
{
    ifstream fin("in.txt");
    string word;
    fin>>word;
    cout<<word<<endl;
    vector<string> abbr=generateAbbreviations(word);
    for(int i=0;i<abbr.size();i++) cout<<abbr[i]<<' ';
    return 0;
}
