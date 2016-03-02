#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <algorithm>
#include <limits>

using namespace std;

int threeSumClosest(vector<int>& nums, int target)
{
    sort(nums.begin(),nums.end());
    int i,j,k,big,small,tmp;
    bool flag1=false,flag2=false;
    for(i=0;i<nums.size();i++)
    {
        j=i+1;
        k=nums.size()-1;
        while(j<k)
        {
            tmp=nums[i]+nums[j]+nums[k];
            if(tmp<target)
            {
                if(tmp>small&&flag1==true) small=tmp;
                if(flag1==false)
                {
                    flag1=true;
                    small=tmp;
                }
                j++;
            }
            else if(tmp>target)
            {
                if(tmp<big&&flag2==true) big=tmp;
                k--;
                if(flag2==false)
                {
                    flag2=true;
                    big=tmp;
                }
            }
            else return target;
        }
    }
    if(flag1==true&&flag2==true) return abs(small-target)<abs(big-target)?small:big;
    if(flag1==true) return small;
    if(flag2==true) return big;
}

int main()
{
    ifstream fin("in.txt");
    int target;
    fin>>target;
    cout<<target<<endl;
    vector <int> nums;
    int num_tmp;
    while(!fin.eof())
    {
        fin>>num_tmp;
        nums.push_back(num_tmp);
    }
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<' ';
    cout<<endl<<threeSumClosest(nums,target);
    return 0;
}
