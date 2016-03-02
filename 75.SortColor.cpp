#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void sortColors(vector<int>& nums);
void quicksort(vector<int>& nums,int low,int high);
int divide(vector<int>& nums,int low,int high);

int main()
{
    ifstream fin("in.txt");
    vector<int> array;
    int tmp;
    while(!fin.eof())
    {
        fin>>tmp;
        array.push_back(tmp);
    }
    for(int i=0;i<array.size();i++) cout<<array[i]<<' ';
    cout<<endl;
    sortColors(array);
    return 0;
}

void sortColors(vector<int>& nums)
{
    int len=nums.size();
    //cout<<len<<endl;
    if(len==0) return;
    quicksort(nums,0,len-1);
    //for(int ii=0;ii<len;ii++) cout<<nums[ii]<<' ';
}

void quicksort(vector<int>& nums,int low,int high)
{
    int mid;
    if(low>=high) return;
    mid=divide(nums,low,high);
    quicksort(nums,low,mid-1);
    quicksort(nums,mid+1,high);
}

int divide(vector<int>& nums,int low,int high)
{
    int k=nums[low];
    do
    {
        while(low<high&&nums[high]>=k) --high;
        if(low<high)
        {
            nums[low]=nums[high];
            ++low;
        }
        while(low<high&&nums[low]<=k) ++low;
        if(low<high)
        {
            nums[high]=nums[low];
            --high;
        }
    }while(low!=high);
    nums[low]=k;
    return low;
}

