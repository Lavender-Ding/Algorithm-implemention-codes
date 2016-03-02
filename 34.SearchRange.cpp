#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int index_start=-1;
int index_end=-1;

void searchIndex(vector<int>& nums,int target,int left,int right)
{
    int mid=(left+right)/2;
    //cout<<left<<' '<<mid<<' '<<right<<endl;
    if(nums[mid]==target)
    {
        if(nums[mid-1]!=target||mid==0) index_start=mid;
        if(nums[mid+1]!=target||mid==nums.size()-1) index_end=mid;
    }
    //cout<<index_start<<' '<<index_end<<endl;
    //cout<<endl;
    if(left==right) return;
    if(nums[mid]>target) searchIndex(nums,target,left,mid);
    else if(nums[mid]<target) searchIndex(nums,target,mid+1,right);
    else if(nums[mid]==target)
    {
        //cout<<left<<' '<<right<<endl;
        searchIndex(nums,target,left,mid);
        searchIndex(nums,target,mid+1,right);
    }
}

vector<int> searchRange(vector<int>& nums, int target)
{
    vector<int> range;
    index_start=-1;
    index_end=-1;
    int left=0;
    int right=nums.size()-1;
    if(nums[left]==target&&nums[right]==target)
    {
        index_start=left;
        index_end=right;
        range.push_back(index_start);
        range.push_back(index_end);
        return range;
    }
    else searchIndex(nums,target,left,right);
    range.push_back(index_start);
    range.push_back(index_end);
    return range;
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
    vector<int> range=searchRange(nums,target);
    for(int i=0;i<range.size();i++) cout<<range[i]<<' ';
    return 0;
}
