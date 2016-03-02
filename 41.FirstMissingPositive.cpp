#include <iostream>
#include <fstream>
#include <vector>
#include <limits.h>

using namespace std;

int firstMissingPositive(vector<int>& nums)
{
    if(nums.size()==0) return 1;
    int i,tmp;
    for(i=0;i<nums.size();i++)
    {
        while(nums[i]>0&&nums[i]<=nums.size()&&nums[i]!=i+1&&nums[i]!=nums[nums[i]-1])
        {
            tmp=nums[nums[i]-1];
            nums[nums[i]-1]=nums[i];
            nums[i]=tmp;
        }
    }
    for(i=0;i<nums.size();i++)
    {
        if(nums[i]!=i+1) return i+1;
    }
    return i+1;
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
    cout<<firstMissingPositive(nums);
}
