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

int mindepth=0;

int oneTreeDepth(TreeNode* root,int tmpdepth)
{
    TreeNode *p=root;
    if(p==NULL) return 0;
    if(p->left==NULL&&p->right==NULL)
    {
        //cout<<maxdepth<<' '<<tmpdepth<<endl;
        if(mindepth==0) mindepth=tmpdepth;
        else if(tmpdepth<mindepth) mindepth=tmpdepth;
        //tmpdepth=1;
        return mindepth;
    }
    if(p->left!=NULL)
    {
        tmpdepth++;
        //cout<<tmpdepth<<' '<<p->left->val<<endl;
        oneTreeDepth(p->left,tmpdepth);
    }
    if(p->right!=NULL)
    {
        if(p->left!=NULL) tmpdepth--;
        tmpdepth++;
        //cout<<tmpdepth<<' '<<p->right->val<<endl;
        oneTreeDepth(p->right,tmpdepth);
    }
    return mindepth;
}

int minDepth(TreeNode* root)
{
    mindepth=0;
    int tmpdepth=1;
    int depth=oneTreeDepth(root,tmpdepth);
    return depth;
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
    int depth=minDepth(root);
    cout<<depth;
    return 0;
}
