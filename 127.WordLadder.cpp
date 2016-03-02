#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <limits.h>

using namespace std;

bool flag=false;

vector<string> addrelatedWord(string beginWord,set<string>& wordList,int wlen){
        int i,j;
        vector<string> relatedWords;
        for(i=0;i<wlen;i++){
            char tmp=beginWord[i];
            for(j=0;j<26;j++){
                beginWord[i]='a'+j;
                if(wordList.find(beginWord)!=wordList.end()){
                    wordList.erase(beginWord);
                    relatedWords.push_back(beginWord);
                }
            }
            beginWord[i]=tmp;
        }
        return relatedWords;
    }

    void findTrans(string beginWord,string endWord,vector<string> relatedWords,set<string>& wordList,int&minDis,int dis,int wlen){
        if(relatedWords.size()==0){
            if(flag==false) minDis=0;
            return;
        }
        for(int i=0;i<relatedWords.size();i++){
            cout<<relatedWords[i]<<' '<<dis<<endl;
            if(dis>=minDis) return;
            if(relatedWords[i]==endWord){
                flag=true;
                minDis=min(minDis,dis);
                return;
            }
            else findTrans(relatedWords[i],endWord,addrelatedWord(relatedWords[i],wordList,wlen),wordList,minDis,dis+1,wlen);
        }
    }

    int ladderLength(string beginWord, string endWord, set<string>& wordList) {
        flag=false;
        int wlen=beginWord.size(),minDis=INT_MAX,dis=1;
        vector<string> relatedWords(1,beginWord);
        if(wordList.find(beginWord)!=wordList.end()) wordList.erase(beginWord);
        if(wordList.find(endWord)!=wordList.end()) wordList.erase(endWord);
        findTrans(beginWord,endWord,relatedWords,wordList,minDis,dis,wlen);
        return minDis;
    }

int main()
{
    ifstream fin("in.txt");
    string beginWord,endWord;
    fin>>beginWord>>endWord;
    set<string> wordList;
    string tmp;
    while(!fin.eof()){
        fin>>tmp;
        wordList.insert(tmp);
    }
    cout<<beginWord<<' '<<endWord<<endl;
    cout<<ladderLength(beginWord,endWord,wordList);
    return 0;
}
