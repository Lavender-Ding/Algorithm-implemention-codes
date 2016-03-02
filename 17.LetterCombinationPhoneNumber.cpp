#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>

using namespace std;

void FindCombination(int head,string com,vector<string> letters,vector<string> &result)
{
    int i,j;
    //cout<<head<<' '<<letters.size()<<endl;
    for(i=0;i<letters[head].size();i++)
    {
        com=com+letters[head][i];
        //for(j=0;j<com.size();j++) cout<<com[j];cout<<endl;
        if(head==letters.size()-1) {result.push_back(com);}
        else FindCombination(head+1,com,letters,result);
        com=com.substr(0,com.length()-1);
    }
}

vector<string> letterCombinations(string digits)
{
    map<char,string> relations;
    relations.insert(pair<char,string>('0',""));
    relations.insert(pair<char,string>('1',""));
    relations.insert(pair<char,string>('2',"abc"));
    relations.insert(pair<char,string>('3',"def"));
    relations.insert(pair<char,string>('4',"ghi"));
    relations.insert(pair<char,string>('5',"jkl"));
    relations.insert(pair<char,string>('6',"mno"));
    relations.insert(pair<char,string>('7',"pqrs"));
    relations.insert(pair<char,string>('8',"tuv"));
    relations.insert(pair<char,string>('9',"wxyz"));
    vector<string> result;
    vector<string> letters;
    if(digits.size()==0) return result;
    int head=0;
    string com;
    for(int i=0;i<digits.size();i++) letters.push_back(relations[digits[i]]);
    FindCombination(head,com,letters,result);
    return result;
}

int main()
{
    ifstream fin("in.txt");
    string digits;
    fin>>digits;
    int i,j;
    for(i=0;i<digits.size();i++) cout<<digits[i];
    cout<<endl;
    vector<string> result=letterCombinations(digits);
    for(i=0;i<result.size();i++)
    {
        for(j=0;j<result[i].size();j++) cout<<result[i][j];
        cout<<endl;
    }
    return 0;
}
