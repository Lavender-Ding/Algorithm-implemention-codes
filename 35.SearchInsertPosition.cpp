#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int result=0;

int insertIndex(vector<int>& nums,int target,int left,int right)
{
    //cout<<left<<' '<<right<<endl;
    int mid=(left+right)/2;
    if(left==right&&nums[mid]<target) {result=mid+1;return mid+1;}
    if(left==right||nums[mid]==target) {result=mid;return mid;}
    if(nums[mid]>target) return insertIndex(nums,target,left,mid);
    else if(nums[mid]<target) return insertIndex(nums,target,mid+1,right);
}

int searchInsert(vector<int>& nums, int target)
{
    result=0;
    int left=0,right=nums.size()-1;
    if(nums.size()==0) return 0;
    insertIndex(nums,target,left,right);
    return result;
}

int main()
{
    ifstream fin("in.txt");
    int target;
    fin>>target;
    vector <int> nums;
    while(!fin.eof())
    {
        int tmp;
        fin>>tmp;
        nums.push_back(tmp);
    }
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<' ';
    cout<<endl<<target<<endl;
    cout<<searchInsert(nums,target);
    return 0;
}
