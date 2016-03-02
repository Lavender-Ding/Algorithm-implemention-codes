#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int index_min=0;
bool is_exist=false;

void searchMinIndex(vector<int>& nums,int left,int right)
{
    int mid=(left+right)/2;
    if(left==right) return;
    if(nums[mid+1]<nums[mid]) {index_min=mid+1; return;}
    searchMinIndex(nums,left,mid);
    searchMinIndex(nums,mid+1,right);
}

void searchValue(vector<int>& nums,int target,int left,int right)
{
    int mid=(left+right)/2;
    if(nums[mid]==target) {is_exist=true; return;}
    else if(left==right) return;
    if(nums[mid]>target) searchValue(nums,target,left,mid);
    else if(nums[mid]<target) searchValue(nums,target,mid+1,right);
}

bool search(vector<int>& nums, int target)
{
    index_min=0;
    is_exist=false;
    int left=0,right=nums.size()-1;
    searchMinIndex(nums,left,right);
    if(index_min==0) searchValue(nums,target,left,right);
    else
    {
        if(nums[0]<target) searchValue(nums,target,left,index_min-1);
        else if(nums[0]>target) searchValue(nums,target,index_min,right);
        else if(nums[0]==target) return true;
    }
    return is_exist;
}

int main()
{
    ifstream fin("in.txt");
    vector <int> nums;
    int target;
    fin>>target;
    while(!fin.eof())
    {
        int tmp;
        fin>>tmp;
        nums.push_back(tmp);
    }
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<' ';
    cout<<endl<<target<<endl;
    cout<<search(nums,target);
    return 0;
}
