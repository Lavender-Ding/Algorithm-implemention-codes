#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

double compareMedian(vector<int>& nums1,int l1,int r1,vector<int>& nums2,int l2,int r2)
{
    int m1=(l1+r1)/,;m2=(l2+r2)/2;
    int len1=r1-l1+1,len2=r2-l2+1;
    if(len1%2==0) mid1=(nums1[m1]+nums1[m1+1])/2.0;
    else if(len1%2!=0) mid1=nums1[m1];
    if(len2%2==0) mid2=(nums2[m2]+nums2[m2+1])/2.0;
    else if(len2%2!=0) mid2=nums2[m2];
    if(len1==1&&len2==1) return (len1+len2)/2.0;
    else if(len1==1)
    {
        if(len2%2==0)
        {
            if(nums1[m1]>nums2[m2]&&nums1[m1]<nums2[m2+1]) return nums1[m1];
            else if(nums1[m1]>=nums2[m2+1]) return nums2[m2+1];
            else if(nums1[m1]<=nums2[m2]) return nums2[m2];
        }
        else if(len2%2==1)
        {
            if(nums1[m1]>=nums2[m2-1]&&nums1[m1]<=nums2[m2+1]) return (nums1[m1]+nums2[m2]/2.0);
            else if(nums1[m1]>nums2[m2+1]) return (nums2[m2]+nums2[m2+1]/2.0);
            else if(nums1[m1]<nums2[m2-1]) return (nums2[m2]+nums2[m2-1]/2.0);
        }
    }
    else if(len2==1)
    {
        if(len1%2==0)
        {
            if(nums2[m2]>nums1[m1]&&nums2[m2]<nums1[m1+1]) return nums2[m2];
            else if(nums2[m2]>=nums1[m1+1]) return nums1[m1+1];
            else if(nums2[m2]<=nums1[m1]) return nums1[m1];
        }
        else if(len1%2==1)
        {
            if(nums2[m2]>=nums1[m1-1]&&nums2[m2]<=nums1[m1+1]) return (nums2[m2]+nums1[m1]/2.0);
            else if(nums2[m2]>nums1[m1+1]) return (nums1[m1]+nums1[m1+1]/2.0);
            else if(nums2[m2]<nums1[m1-1]) return (nums1[m1]+nums1[m1-1]/2.0);
        }
    }
    else if(len1!=1&&len2!=1)
    {
        if(mid1==mid2) return mid1;
        if(mid1<mid2)
        {

        }
    }
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
{

}

int main()
{
    ifstream fin("in.txt");
    vector<int> array1;
    vector<int> array2;
    char ch;
    int tmp;
    while(1)
    {
        fin>>tmp;
        array1.push_back(tmp);
        ch=fin.get();
        if(ch=='\n') break;
    }
    while(1)
    {
        fin>>tmp;
        array2.push_back(tmp);
        ch=fin.get();
        if(ch==EOF) break;
    }
    for(int i=0;i<array1.size();i++) cout<<array1[i]<<' ';
    cout<<endl;
    for(int i=0;i<array2.size();i++) cout<<array2[i]<<' ';
    cout<<endl;
    cout<<findMedianSortedArrays(array1,array2);
    return 0;
}
