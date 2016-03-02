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

bool flag=false;
int state=0;

void inorder(TreeNode* p,TreeNode* &pre,vector<TreeNode*> &swich)
{
    if(p==NULL) return;
    if(p->left!=NULL) inorder(p->left,pre,swich);
    if(flag==true)
    {
        if(p->val<=pre->val)
        {
            state++;
            if(state==1)
            {
                swich.push_back(pre);
                swich.push_back(p);
            }
            else
            {
                swich.pop_back();
                swich.push_back(p);
            }
        }
        pre=p;
    }
    else if(flag==false)
    {
        pre=p;
        flag=true;
    }
    if(p->right!=NULL) inorder(p->right,pre,swich);
}

void recoverTree(TreeNode* root)
{
    vector<TreeNode*> swich;
    TreeNode* pre;
    flag=false;
    state=0;
    inorder(root,pre,swich);
    int tmp=swich[0]->val;
    swich[0]->val=swich[1]->val;
    swich[1]->val=tmp;
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
    TreeNode *root;
    string c;
    fin>>c;
    if(c!="#") root=new TreeNode(CharToInt(c));
    vector<TreeNode*> tree;
    tree.push_back(root);
    int i=0;
    char cc=fin.get();
    while(!fin.eof())
    {
        TreeNode *p=tree[i];
        string l,r;
        if(!fin.eof()) fin>>l;
        if(!fin.eof()) fin>>r;
        cc=fin.get();
        if(l!="#")
        {
            p->left=new TreeNode(CharToInt(l));
            tree.push_back(p->left);
        }
        if(r!="#")
        {
            p->right=new TreeNode(CharToInt(r));
            tree.push_back(p->right);
        }
        i++;
    }
    for(i=0;i<tree.size();i++) cout<<tree[i]->val<<' ';
    cout<<endl;
    recoverTree(root);
    printTree(root);
    return 0;
}
