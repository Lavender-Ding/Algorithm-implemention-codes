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

bool valid=true;
int pre=0;
bool flag=false;

void inorder(TreeNode* p)
{
    if(p==NULL||valid==false) return;
    if(p->left!=NULL) inorder(p->left);
    if(flag==true)
    {
        if(p->val<=pre) valid=false;
        pre=p->val;
    }
    else if(flag==false)
    {
        pre=p->val;
        flag=true;
    }
    if(p->right!=NULL) inorder(p->right);
}

bool isValidBST(TreeNode* root)
{
    valid=true;
    pre=0;
    flag=false;
    inorder(root);
    return valid;
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
    cout<<isValidBST(root);
    return 0;
}
