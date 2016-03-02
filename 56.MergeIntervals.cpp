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

int divide(vector<Interval>& nums,int low,int high)
{
    Interval k(nums[low].start,nums[low].end);
    do
    {
        while(low<high&&nums[high].start>=k.start) --high;
        if(low<high)
        {
            nums[low]=nums[high];
            ++low;
        }
        while(low<high&&nums[low].start<=k.start) ++low;
        if(low<high)
        {
            nums[high]=nums[low];
            --high;
        }
    }while(low!=high);
    nums[low]=k;
    return low;
}

void quicksort(vector<Interval>& nums,int low,int high)
{
    int mid;
    if(low>=high) return;
    mid=divide(nums,low,high);
    quicksort(nums,low,mid-1);
    quicksort(nums,mid+1,high);
}

void sortstart(vector<Interval>& nums)
{
    int len=nums.size();
    if(len==0) return;
    quicksort(nums,0,len-1);
}

vector<Interval> merge(vector<Interval>& intervals)
{
    vector<Interval> result;
    int len=intervals.size();
    vector<Interval> numset=intervals;
    int i,j,k;
    sortstart(numset);
    i=0;
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
    }
    return result;
}

int main()
{
    ifstream fin("in.txt");
    int s,e;
    vector<Interval> intervals,result;
    while(!fin.eof())
    {
        fin>>s>>e;
        Interval tmp(s,e);
        intervals.push_back(tmp);
    }
    for(int i=0;i<intervals.size();i++) cout<<intervals[i].start<<' '<<intervals[i].end<<endl;
    cout<<endl;
    result=merge(intervals);
    cout<<endl;
    for(int i=0;i<result.size();i++) cout<<result[i].start<<' '<<result[i].end<<endl;
    return 0;
}

