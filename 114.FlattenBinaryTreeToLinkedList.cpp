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

TreeNode *now;

void TreeToList(TreeNode *p)
{
    if(p->left==NULL&&p->right==NULL) return;
    else if(p->right!=NULL&&p->left!=NULL)
    {
        TreeNode *tmp=p->left;
        p->left=NULL;
        p->left=p->right;
        p->right=NULL;
        p->right=tmp;
    }
    else if(p->right==NULL&&p->left!=NULL)
    {
        p->right=p->left;
        p->left=NULL;
    }
    if(p->right!=NULL)
    {
        now=p->right;
        TreeToList(p->right);
    }
    if(p->left!=NULL)
    {
        now->right=p->left;
        p->left=NULL;
        now=now->right;
        TreeToList(now);
    }
}

void flatten(TreeNode* root)
{
    if(root==NULL) return;
    now=NULL;
    TreeToList(root);
    TreeNode *p;
    p=root;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->right;
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
    while(!fin.eof())
    {
        TreeNode *p=tree[i];
        string l,r;
        if(!fin.eof()) fin>>l;
        if(!fin.eof()) fin>>r;
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
    flatten(root);

}
