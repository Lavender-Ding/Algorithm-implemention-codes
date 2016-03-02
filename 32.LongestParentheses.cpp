#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int longestValidParentheses(string s)
{
    int n=s.size();
    vector<int> nums;
    nums.assign(n,0);
    if(n<2) return 0;
    int i,j;
    int maxlength=0;
    for(i=1;i<n;i++)
    {
        if(s[i]==')')
        {
            j=i-1-nums[i-1];
            if(j>=0&&s[j]=='(')
            {
                nums[i]=nums[i-1]+2;
                if(j>0) nums[i]=nums[i]+nums[j-1];
            }
        }
        if(nums[i]>maxlength) maxlength=nums[i];
    }
    for(i=0;i<n;i++) cout<<nums[i];
    cout<<endl;
    return maxlength;
}

int main()
{
    ifstream fin("in.txt");
    string s;
    fin>>s;
    for(int i=0;i<s.size();i++) cout<<s[i];
    cout<<endl;
    cout<<longestValidParentheses(s);
    return 0;
}
