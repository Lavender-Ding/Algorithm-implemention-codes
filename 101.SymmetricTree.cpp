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

bool isSym=true;

void symmetric(TreeNode *p,TreeNode *q)
{
    if(p!=NULL&&q!=NULL&&p->val==q->val)
    {
        symmetric(p->left,q->right);
        symmetric(p->right,q->left);
    }
    else if(p==NULL&&q==NULL) return;
    else
    {
        isSym=false;
        return;
    }
}

bool isSymmetric(TreeNode* root)
{
    if(root==NULL||(root->left==NULL&&root->right==NULL)) return true;
    isSym=true;
    symmetric(root->left,root->right);
    return isSym;
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
    cout<<isSymmetric(root);
    return 0;
}
