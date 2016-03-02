#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

string getPermutation(int n, int k)
{
    string result;
    if(n==0||k==0) return result;
    int i,j,factorial=1;
    vector<int> nums;
    for(i=1;i<=n;i++) nums.push_back(i);
    for(i=1;i<=n;i++) factorial*=i;
    k=k-1;
    for(i=1;i<=n;i++)
    {
        factorial/=(n-i+1);
        for(j=i;j<=n;j++)
        {
            if(k>=factorial*(j-i)&&k<factorial*(j-i+1))
            {
                k=k-factorial*(j-i);
                stringstream ss;
                string s;
                ss<<nums[j-i];
                ss>>s;
                result+=s;
                nums.erase(nums.begin()+j-i);
                break;
            }
        }
    }
    return result;
}

int main()
{
    ifstream fin("in.txt");
    vector<int> nums;
    int n,k;
    fin>>n>>k;
    cout<<n<<' '<<k<<endl;
    int tmp,i,j;
    for(i=1;i<=n;i++) nums.push_back(i);
    for(int i=0;i<n;i++) cout<<nums[i]<<' ';
    cout<<endl;
    string result=getPermutation(n,k);
    for(i=0;i<result.size();i++) cout<<result[i];
    return 0;
}
