#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int numDecodings(string s)
{
    vector<int> nums;
    int n=s.size()-1;
    cout<<n<<endl;
    nums.assign(n+1,0);
    if(n==0) return 0;
    if(s[0]<=57&&s[0]>=49) nums[1]=1;
    else nums[1]=0;
    if(n==1) return nums[1];
    if(s[0]==49&&(s[1]<=57&&s[1]>=49)||(s[0]==50&&(s[1]>=49&&s[1]<=54))) nums[2]=nums[1]+1;
    else if(s[1]==48&&(s[0]==49||s[0]==50)) nums[2]=1;
    else if(s[1]<=57&&s[1]>=49) nums[2]=nums[1];
    else if(s[1]>57||s[1]<49) nums[2]=0;
    for(int i=2;i<n;i++)
    {
        if(s[i-1]==49&&(s[i]<=57&&s[i]>=49)||(s[i-1]==50&&(s[i]>=49&&s[i]<=54)))
            nums[i+1]=nums[i]+nums[i-1];
        else if((s[i-1]==49||s[i-1]==50)&&s[i]==48) nums[i+1]=nums[i-1];
        //else nums[i+1]=nums[i];
        else if(s[i]<=57&&s[i]>=49) nums[i+1]=nums[i];
        else if(s[i]>57||s[i]<49) nums[i+1]=0;
    }
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<' ';
    cout<<endl;
    return nums[n];
}

int main()
{
    ifstream fin("in.txt");
    string s;
    string tmp;
    s=fin.get();
    while(!fin.eof())
    {
        tmp=fin.get();
        s=s+tmp;
    }
    for(int i=0;i<s.size();i++) cout<<s[i];
    cout<<endl;
    cout<<numDecodings(s);
    return 0;
}
