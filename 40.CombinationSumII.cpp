#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void FindSum(int head,vector<int> nums,vector<int> com,int target,vector<vector<int> > &sum)
{
    int i;
    if(target<=0)
    {
        sum.push_back(com);
        return;
    }
    for(i=head;i<nums.size();i++)
    {
        while(nums[i]==nums[i-1]&&i>head) i++;
        if(i<nums.size()&&nums[i]<=target)
        {
            com.push_back(nums[i]);
            FindSum(i+1,nums,com,target-nums[i],sum);
            com.pop_back();
        }
    }
}

vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
{
    int head=0;
    vector<int> com;
    vector<vector<int> > sum;
    sort(candidates.begin(),candidates.end());
    FindSum(head,candidates,com,target,sum);
    return sum;
}

int main()
{
    ifstream fin("in.txt");
    int target;
    fin>>target;
    int tmp,i,j;
    vector<int> nums;
    while(!fin.eof())
    {
        fin>>tmp;
        nums.push_back(tmp);
    }
    for(i=0;i<nums.size();i++) cout<<nums[i]<<' ';
    cout<<endl<<target<<endl;
    vector<vector<int> > result=combinationSum2(nums,target);
    for(i=0;i<result.size();i++)
    {
        for(j=0;j<result[i].size();j++) cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
