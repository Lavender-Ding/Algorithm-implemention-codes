#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int climbStairs(int n)
{
    vector<int> nums;
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    if(n<=2) return nums[n];
    else if(n>2)
    {
        for(int i=3;i<=n;i++)
        {
            int tmp=nums[i-1]+nums[i-2];
            nums.push_back(tmp);
        }
        return nums[n];
    }
}

int main()
{
    fstream fin("in.txt");
    int n;
    fin>>n;
    cout<<n<<endl<<climbStairs(n);
}
