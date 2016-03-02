#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k)
{

}

int main()
{
    ifstream fin("in.txt");
    int k;
    fin>>k;
    vector<int> nums1,nums2;
    int tmp;
    char c='0';
    while(c!='\n')
    {
        fin>>tmp;
        nums1.push_back(tmp);
        c=fin.get();
    }
    while(!fin.eof())
    {
        fin>>tmp;
        nums2.push_back(tmp);
    }
    for(int i=0;i<nums1.size();i++) cout<<nums1[i]<<' ';
    cout<<endl;
    for(int i=0;i<nums2.size();i++) cout<<nums2[i]<<' ';
    cout<<endl;
    cout<<k<<endl;
    vector<int> maxNum=maxNumber(nums1,nums2,k);
    for(int i=0;i<maxNum.size();i++) cout<<maxNum[i]<<' ';
    return 0;
}
