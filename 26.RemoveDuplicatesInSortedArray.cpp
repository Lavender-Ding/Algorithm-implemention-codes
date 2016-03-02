#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int removeDuplicates(vector<int>& nums)
{
    if(nums.size()==0) return 0;
    int newlen=1;
    for(int i=1;i<nums.size();i++)
        if(nums[i]!=nums[i-1]) nums[newlen++]=nums[i];
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
