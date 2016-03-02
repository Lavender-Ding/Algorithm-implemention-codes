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

int TreeHeight(TreeNode* p)
{
    if(p==NULL) return 0;
    int leftHeight=TreeHeight(p->left);
    int rightHeight=TreeHeight(p->right);
    if(leftHeight==-1||rightHeight==-1) return -1;
    if(abs(leftHeight-rightHeight)<=1) return 1+max(leftHeight,rightHeight);
    else return -1;
}

bool isBalanced(TreeNode* root)
{
    if (TreeHeight(root)>=0) return true;
    else return false;
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
    cout<<isBalanced(root);
    return 0;
}
