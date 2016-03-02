#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int numTrees(int n)
{
    vector<int> nums;
    nums.assign(n+1,1);
    int i,j,tmp;
    for(i=2;i<=n;i++)
    {
        tmp=0;
        for(j=0;j<i;j++) tmp=tmp+nums[j]*nums[i-1-j];
        nums[i]=tmp;
    }
    return nums[n];
}

int main()
{
    ifstream fin("in.txt");
    int n;
    fin>>n;
    cout<<n<<endl<<numTrees(n);
    return 0;
}
