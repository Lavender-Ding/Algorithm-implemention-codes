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
               vector<int>::iterator end,vector<int> &postorder,vector<int> &inorder)
{
    if(rear<head||end<start) return;
    int mid;
    vector<int>::iterator it=find(start,end,p->val);
    mid=rear-(end-it);
    if(mid>=head)
    {
        p->left=new TreeNode(postorder[mid]);
        construct(p->left,head,mid-1,start,it-1,postorder,inorder);
    }
    if(mid<rear)
    {
        p->right=new TreeNode(postorder[rear]);
        construct(p->right,mid+1,rear-1,it+1,end,postorder,inorder);
    }
}

TreeNode* buildTree(vector<int>& postorder, vector<int>& inorder)
{
    if(postorder.size()==0) return NULL;
    TreeNode *root=new TreeNode(postorder[postorder.size()-1]);
    construct(root,0,postorder.size()-2,inorder.begin(),inorder.end()-1,postorder,inorder);
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
    vector<int> postorder;
    vector<int> inorder;
    char c='a';
    int tmp;
    while(c!='\n')
    {
        fin>>tmp;
        postorder.push_back(tmp);
        c=fin.get();
    }
    while(!fin.eof())
    {
        fin>>tmp;
        inorder.push_back(tmp);
    }
    for(int i=0;i<postorder.size();i++) cout<<postorder[i]<<' ';
    cout<<endl;
    for(int i=0;i<inorder.size();i++) cout<<inorder[i]<<' ';
    cout<<endl;
    TreeNode *root=buildTree(postorder,inorder);
    printTree(root);
    return 0;
}
