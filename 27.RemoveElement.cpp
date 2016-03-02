#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
    int newlen=0;
    for(int i=0;i<nums.size();i++)
        if(nums[i]!=val) nums[newlen++]=nums[i];
    return newlen;
}

int main()
{
    ifstream fin("in.txt");
    vector <int> nums;
    int val;
    fin>>val;
    cout<<val<<endl;
    int num_tmp;
    while(!fin.eof())
    {
        fin>>num_tmp;
        nums.push_back(num_tmp);
    }
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<' ';
    cout<<endl;
    cout<<removeElement(nums,val);
    return 0;
}
