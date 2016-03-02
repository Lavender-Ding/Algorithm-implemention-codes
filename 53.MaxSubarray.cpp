#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int maxSubArray(vector<int>& nums)
{
    vector<int> maxsum;
    int n=nums.size();
    maxsum.assign(n,0);
    if(n==0) return 0;
    if(n==1) return nums[0];
    maxsum[0]=nums[0];
    for(int i=1;i<n;i++)
    {
        nums[i]=max(nums[i],nums[i]+nums[i-1]);
        if(nums[i]>maxsum[i-1]) maxsum[i]=nums[i];
        else maxsum[i]=maxsum[i-1];
    }
//    maxsum[i]=max(nums[i],nums[i]+maxsum[i-1]),maxsum[i-1];
//    cout<<endl;
//    for(int i=0;i<n;i++) cout<<maxsum[i]<<' ';
    return maxsum[n-1];
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
    cout<<endl<<maxSubArray(nums);
    return 0;
}
