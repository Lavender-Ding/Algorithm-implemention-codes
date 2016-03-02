#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int CharToInt(string c)
{
    stringstream ss;
    ss<<c;
    int tmp;
    ss>>tmp;
    return tmp;
}

TreeNode* divide(vector<int>& nums,int head,int rear)
{
    if(head>rear) return NULL;
    else if(head==rear) return new TreeNode(nums[head]);
    else
    {
        int mid=(head+rear)/2;
        TreeNode *p=new TreeNode(nums[mid]);
        p->left=divide(nums,head,mid-1);
        p->right=divide(nums,mid+1,rear);
        return p;
    }
}

TreeNode* sortedArrayToBST(vector<int>& nums)
{
    int head=0,rear=nums.size()-1;
    return divide(nums,head,rear);
}

void printTree(TreeNode *p)
{
    vector<TreeNode*> tree;
    if(p==NULL) return;
    tree.push_back(p);
    cout<<p->val<<' ';
    int head=0,rear=1;
    while(head!=rear)
    {
        for(int i=head;i<rear;i++)
        {
            TreeNode *q=tree[i];
            if(q->left!=NULL)
            {
                tree.push_back(q->left);
                cout<<q->left->val<<' ';
            }
            else cout<<'#'<<' ';
            if(q->right!=NULL)
            {
                tree.push_back(q->right);
                cout<<q->right->val<<' ';
            }
            else cout<<'#'<<' ';
        }
        head=rear;
        rear=tree.size();
    }
    return;
}

int main()
{
    ifstream fin("in.txt");
    vector<int> nums;
    int tmp;
    while(!fin.eof())
    {
        fin>>tmp;
        nums.push_back(tmp);
    }
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<' ';
    cout<<endl;
    TreeNode* root=sortedArrayToBST(nums);
    printTree(root);
    return 0;
}
