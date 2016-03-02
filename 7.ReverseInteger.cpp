#include <iostream>
#include <fstream>
#include <cstring>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int reverse(int x)
{
    vector<int> nums;
    int tmp=abs(x),ent,rex=0;
    if(x==-2147483648) return 0;
    while(tmp!=0)
    {
        ent=tmp%10;
        tmp/=10;
        nums.push_back(ent);
    }
    if(nums.size()==10&&nums[0]>=3) return 0;
    for(int i=0;i<nums.size();i++)
    {
        double p=pow(10,nums.size()-1-i);
        rex+=nums[i]*p;
    }
    if(x<0) rex=-rex;
    if((x>0&&rex<0)||(x<0&&rex>0)) return 0;
    else return rex;
}

int main()
{
    ifstream fin("in.txt");
    int x;
    fin>>x;
    cout<<x<<endl<<reverse(x);
    return 0;
}
