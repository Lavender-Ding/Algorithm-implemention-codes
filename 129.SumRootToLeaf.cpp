#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>

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

void sumonepath(TreeNode *p,int onepath,int &result)
{
    onepath=onepath*10+p->val;
    if(p->left==NULL&&p->right==NULL) result+=onepath;
    if(p->left!=NULL) sumonepath(p->left,onepath,result);
    if(p->right!=NULL) sumonepath(p->right,onepath,result);
    onepath=(onepath-p->val)/10;
}

int sumNumbers(TreeNode* root)
{
    int result=0;
    int onepath=0;
    if(root==NULL) return result;
    sumonepath(root,onepath,result);
    return result;
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
    cout<<sumNumbers(root);
    return 0;
}
