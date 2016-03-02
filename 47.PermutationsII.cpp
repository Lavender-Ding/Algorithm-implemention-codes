#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void FindPermutation(int head,vector<int> per,vector<int> nums,vector< vector<int> > &permutation)
{
    int i,j,tmp;
    if(head==nums.size()-2)
    {
        per.push_back(nums[head]);
        per.push_back(nums[head+1]);
        permutation.push_back(per);
        per.pop_back();
        per.pop_back();
        if(nums[head]!=nums[head+1])
        {
            per.push_back(nums[head+1]);
            per.push_back(nums[head]);
            permutation.push_back(per);
            per.pop_back();
            per.pop_back();
        }
    }
    else
    {
        for(i=head;i<nums.size();i++)
        {
            if(i!=head&&nums[head]==nums[i]) continue;
            tmp=nums[head];
            nums[head]=nums[i];
            nums[i]=tmp;
            per.push_back(nums[head]);
            //cout<<endl<<nums[head]<<endl<<nums[i]<<endl;
            FindPermutation(head+1,per,nums,permutation);
            per.pop_back();
        }
    }
}

vector< vector<int> > permuteUnique(vector<int>& nums)
{
    vector< vector<int> > permutation;
    if(nums.size()==0) return permutation;
    if(nums.size()==1)
    {
        permutation.push_back(nums);
        return permutation;
    }
    sort(nums.begin(),nums.end());
    vector<int> per;
    int head=0;
    FindPermutation(head,per,nums,permutation);
    return permutation;
}

int main()
{
    ifstream fin("in.txt");
    vector<int> nums;
    int tmp;
    while(!fin.eof())
    {
        fin>>tmp;
        nums.push_back(tmp);
    }
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<' ';
    cout<<endl;
    vector< vector<int> > permutation;
    permutation=permuteUnique(nums);
    for(int i=0;i<permutation.size();i++)
    {
        for(int j=0;j<permutation[i].size();j++) cout<<permutation[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
