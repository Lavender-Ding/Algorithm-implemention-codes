#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

void wiggleSort(vector<int>& nums)
{
    sort(nums.begin(),nums.end());

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
    wiggleSort(nums);
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<' ';
    return 0;
}

