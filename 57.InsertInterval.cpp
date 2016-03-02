#include <iostream>
#include <fstream>
#include <vector>
#include<algorithm>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> insert(vector<Interval>& intervals,Interval newInterval)
{
    vector<Interval> result;
    int len=intervals.size();
    vector<Interval> numset;
    int i,j,k;
    int flag=0;
    if(len==0)
    {
        result.push_back(newInterval);
        return result;
    }
    for(i=0;i<len;i++)
    {
        if(intervals[i].start>newInterval.start&&flag==0)
        {
            numset.push_back(newInterval);
            flag=1;
        }
        numset.push_back(intervals[i]);
    }
    if(flag==0) numset.push_back(newInterval);
    //for(int i=0;i<numset.size();i++) cout<<numset[i].start<<' '<<numset[i].end<<endl;
    i=0;
    len=numset.size();
    while(i<len)
    {
        k=numset[i].end;
        int k_tmp=k;
        for(j=i+1;j<len&&numset[i].end>=numset[j].start;j++)
        {
            k_tmp=numset[j].end;
            if(k_tmp>k) k=k_tmp;
        }
        Interval tmp1(numset[i].start,k);
        //cout<<endl<<tmp1.start<<' '<<tmp1.end<<' '<<j<<endl;
        if(j>=len)
        {
            result.push_back(tmp1);
            return result;
        }
        if(k<numset[j].start)
        {
            result.push_back(tmp1);
            i=j;
        }
        else
        {
            numset[j-1]=tmp1;
            i=j-1;
        }
        //cout<<k<<' '<<i<<endl;
    }
    return result;
}

int main()
{
    ifstream fin("in.txt");
    int s,e;
    vector<Interval> intervals,result;
    Interval newInterval(2,7);
    while(!fin.eof())
    {
        fin>>s>>e;
        Interval tmp(s,e);
        intervals.push_back(tmp);
    }
    for(int i=0;i<intervals.size();i++) cout<<intervals[i].start<<' '<<intervals[i].end<<endl;
    cout<<endl;
    result=insert(intervals,newInterval);
    cout<<endl;
    for(int i=0;i<result.size();i++) cout<<result[i].start<<' '<<result[i].end<<endl;
    return 0;
}

