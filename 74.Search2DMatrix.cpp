#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool is_exist=false;

void searchcol(vector<int>& nums,int target,int left,int right)
{
    int mid=(left+right)/2;
    //cout<<mid<<' '<<nums[mid]<<endl;
    if(nums[mid]==target) {is_exist=true; return;}
    else if(left==right) return;
    if(nums[mid]>target) searchcol(nums,target,left,mid);
    else if(nums[mid]<target) searchcol(nums,target,mid+1,right);
}

void searchrow(vector <vector<int> >& matrix,int target,int top,int bottom)
{
    int mid=(top+bottom)/2;
    if(matrix[mid][0]==target) {is_exist=true; return;}
    if(top==bottom)
    {
        if(mid==0&&matrix[mid][0]<target) {searchcol(matrix[top],target,0,matrix[top].size()-1);return;}
        else if(mid==0&&matrix[mid][0]>target) return;
        else if(mid==matrix.size()-1&&matrix[mid][0]<target) {searchcol(matrix[top],target,0,matrix[top].size()-1);return;}
        else {searchcol(matrix[top-1],target,0,matrix[top].size()-1);return;}
    }
    if(matrix[mid][0]>target) searchrow(matrix,target,top,mid);
    else if(matrix[mid][0]<target) searchrow(matrix,target,mid+1,bottom);
}

bool searchMatrix(vector <vector<int> >& matrix, int target)
{
    is_exist=false;
    if(matrix.size()==0) return false;
    int top=0,bottom=matrix.size()-1;
    if(top==bottom) searchcol(matrix[0],target,0,matrix[0].size());
    else searchrow(matrix,target,top,bottom);
    return is_exist;
}

int main()
{
    ifstream fin("in.txt");
    vector< vector<int> > matrix;
    int target;
    fin>>target;
    char ch=fin.get();
    int tmp;
    while(1)
    {
        vector<int> nums;
        fin>>tmp;
        nums.push_back(tmp);
        ch=fin.get();
        while(ch!='\n'&&ch!=EOF)
        {
            fin>>tmp;
            nums.push_back(tmp);
            ch=fin.get();
        }
        if(ch=='\n') matrix.push_back(nums);
        if(ch==EOF)
        {
            matrix.push_back(nums);
            break;
        }
    }
    for(int i=0;i<matrix.size();i++)
    {
        for(int j=0;j<matrix[i].size();j++) cout<<matrix[i][j]<<' ';
        cout<<endl;
    }
    cout<<target<<endl;
    cout<<searchMatrix(matrix,target);
    return 0;
}
