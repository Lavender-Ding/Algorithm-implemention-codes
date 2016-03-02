#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void construct(TreeNode *p,int head,int rear,vector<int>::iterator start,
               vector<int>::iterator end,vector<int> &preorder,vector<int> &inorder)
{
    if(rear<head||end<start) return;
    int mid;
    vector<int>::iterator it=find(start,end,p->val);
    mid=it-start+head;
    if(mid>head)
    {
        p->left=new TreeNode(preorder[head]);
        construct(p->left,head+1,mid-1,start,it-1,preorder,inorder);
    }
    if(mid<=rear)
    {
        p->right=new TreeNode(preorder[mid]);
        construct(p->right,mid+1,rear,it+1,end,preorder,inorder);
    }
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
    if(preorder.size()==0) return NULL;
    TreeNode *root=new TreeNode(preorder[0]);
    construct(root,1,preorder.size()-1,inorder.begin(),inorder.end()-1,preorder,inorder);
    return root;
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
    vector<int> preorder;
    vector<int> inorder;
    char c='a';
    int tmp;
    while(c!='\n')
    {
        fin>>tmp;
        preorder.push_back(tmp);
        c=fin.get();
    }
    while(!fin.eof())
    {
        fin>>tmp;
        inorder.push_back(tmp);
    }
    for(int i=0;i<preorder.size();i++) cout<<preorder[i]<<' ';
    cout<<endl;
    for(int i=0;i<inorder.size();i++) cout<<inorder[i]<<' ';
    cout<<endl;
    TreeNode *root=buildTree(preorder,inorder);
    printTree(root);
    return 0;
}
