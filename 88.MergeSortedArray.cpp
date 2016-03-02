#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
{
    int p1=0,p2=0;
    vector<int> result;
    while(p1<m&&p2<n)
    {
        if(nums1[p1]<=nums2[p2]) result.push_back(nums1[p1++]);
        else result.push_back(nums2[p2++]);
    }
    while(p1<m) result.push_back(nums1[p1++]);
    while(p2<n) result.push_back(nums2[p2++]);
    nums1=result;
}

int main()
{
    ifstream fin("in.txt");
    char c;
    int tmp;
    vector<int> nums1,nums2;
    fin>>tmp;
    nums1.push_back(tmp);
    c=fin.get();
    while(c!='\n'&&!fin.eof())
    {
        fin>>tmp;
        nums1.push_back(tmp);
        c=fin.get();
    }
    fin>>tmp;
    nums2.push_back(tmp);
    while(!fin.eof())
    {
        fin>>tmp;
        nums2.push_back(tmp);
    }
    for(int i=0;i<nums1.size();i++) cout<<nums1[i]<<' ';
    cout<<endl;
    for(int i=0;i<nums2.size();i++) cout<<nums2[i]<<' ';
    cout<<endl;
    int m=nums1.size();
    int n=nums2.size();
    cout<<m<<' '<<n<<endl;
    merge(nums1,m,nums2,n);
    for(int i=0;i<nums1.size();i++) cout<<nums1[i]<<' ';
    return 0;
}
