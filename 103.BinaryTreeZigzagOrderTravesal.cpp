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

vector<vector<int> > zigzagLevelOrder(TreeNode* root)
{
    vector<TreeNode*> TreeLevel;
    vector<vector<int> > result;
    if(root==NULL) return result;
    TreeLevel.push_back(root);
    int head=0;
    int rear;
    vector<int> first;
    first.push_back(root->val);
    result.push_back(first);
    int flag=1;
    while(head!=TreeLevel.size())
    {
        vector<int> oneLevel;
        rear=TreeLevel.size();
        for(int i=rear-1;i>=head;i--)
        {
            TreeNode *p=TreeLevel[i];
            if(flag==0)
            {
                if(p->left!=NULL)
                {
                    TreeLevel.push_back(p->left);
                    oneLevel.push_back(p->left->val);
                }
                if(p->right!=NULL)
                {
                    TreeLevel.push_back(p->right);
                    oneLevel.push_back(p->right->val);
                }
            }
            else if(flag==1)
            {
                if(p->right!=NULL)
                {
                    TreeLevel.push_back(p->right);
                    oneLevel.push_back(p->right->val);
                }
                if(p->left!=NULL)
                {
                    TreeLevel.push_back(p->left);
                    oneLevel.push_back(p->left->val);
                }
            }
        }
        flag=1-flag;
        if(oneLevel.size()!=0) result.push_back(oneLevel);
        head=rear;
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
    vector<vector<int> > result=zigzagLevelOrder(root);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++) cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
