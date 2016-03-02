#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include <limits.h>

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

int maxsum=INT_MIN;

int findMaxSum(TreeNode *p)
{
    if (p==NULL) return 0;
    int leftsum=findMaxSum(p->left);
    int rightsum=findMaxSum(p->right);
    int tmpmax=max(max(max(leftsum+p->val,rightsum+p->val),leftsum+rightsum+p->val),p->val);
    if(tmpmax>maxsum) maxsum=tmpmax;
    return max(max(leftsum+p->val,rightsum+p->val),p->val);
}

int maxPathSum(TreeNode* root)
{
    maxsum=INT_MIN;
    findMaxSum(root);
    return maxsum;
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
    cout<<maxPathSum(root);
    return 0;
}
