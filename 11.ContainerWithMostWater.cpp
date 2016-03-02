#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

int maxArea(vector<int>& height)
{
    if(height.size()<2) return 0;
    int left=0,right=height.size()-1;
    int maxarea=0;
    int area;
    int r,l;
    while(left<right)
    {
        area=min(height[left],height[right])*(right-left);
        if(area>maxarea) maxarea=area;
        if(height[left]>=height[right])
        {
            r=right-1;
            while(height[r]<=height[right]&&r>left) r--;
            right=r;
        }
        else if(height[left]<height[right])
        {
            l=left+1;
            while(height[l]<=height[left]&&l<right) l++;
            left=l;
        }
    }
    return maxarea;
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
    cout<<maxArea(nums);
    return 0;
}
