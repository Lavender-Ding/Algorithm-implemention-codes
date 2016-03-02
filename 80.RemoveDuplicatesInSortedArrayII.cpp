#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if(nums.size()<=2) return nums.size();
    int newlen=2;
    bool flag=false;
    if(nums[1]==nums[0]) flag=false;
    else flag=true;
    for(int i=2;i<nums.size();i++)
    {
        if(nums[i]!=nums[i-1])
        {
            nums[newlen++]=nums[i];
            flag=true;
        }
        else if(nums[i]==nums[i-1]&&flag==true)
        {
            nums[newlen++]=nums[i];
            flag=false;
        }
    }
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<' ';
    cout<<endl;
    return newlen;
}

int main()
{
    ifstream fin("in.txt");
    vector <int> nums;
    int num_tmp;
    while(!fin.eof())
    {
        fin>>num_tmp;
        nums.push_back(num_tmp);
    }
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<' ';
    cout<<endl;
    cout<<removeDuplicates(nums);
    return 0;
}
