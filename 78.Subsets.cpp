#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int> > subsets(vector<int>& nums)
{
    vector<vector<int> > result;
    vector<int> sub;
    result.push_back(sub);
    if(nums.size()==0) return result;
    sort(nums.begin(),nums.end());
    int i,j,k;
    for(i=0;i<nums.size();i++)
    {
        for(j=result.size()-1;j>=0;j--)
        {
            sub=result[j];
            sub.push_back(nums[i]);
            result.push_back(sub);
        }
    }
    return result;
}

int main()
{
    ifstream fin("in.txt");
    int tmp,i,j;
    vector<int> nums;
    while(!fin.eof())
    {
        fin>>tmp;
        nums.push_back(tmp);
    }
    for(i=0;i<nums.size();i++) cout<<nums[i]<<' ';
    cout<<endl;
    vector<vector<int> > result=subsets(nums);
    for(i=0;i<result.size();i++)
    {
        for(j=0;j<result[i].size();j++) cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
