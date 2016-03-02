#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include <map>

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

vector<int> inorderTraversal(TreeNode* root)
{
    map<TreeNode *,int> treepop;
    vector<int> result;
    if(root==NULL) return result;
    vector<TreeNode *> treestack;
    treestack.push_back(root);
    treepop.insert(pair<TreeNode *,int>(root,0));
    TreeNode *p;
    while(treestack.size()!=0)
    {
        p=treestack[treestack.size()-1];
        treestack.pop_back();
        if(treepop[p]==1||p->left==NULL&&p->right==NULL) result.push_back(p->val);
        else
        {
            if(p->right!=NULL)
            {
                treestack.push_back(p->right);
                treepop.insert(pair<TreeNode *,int>(p->right,0));
            }
            treestack.push_back(p);
            treepop[p]++;
            if(p->left!=NULL)
            {
                treestack.push_back(p->left);
                treepop.insert(pair<TreeNode *,int>(p->left,0));
            }
        }
    }
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
    vector<int> result=inorderTraversal(root);
    for(int i=0;i<result.size();i++) cout<<result[i]<<' ';
    return 0;
}
