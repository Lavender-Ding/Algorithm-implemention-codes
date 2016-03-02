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

void isSum(TreeNode *p,int target,int current,vector<int> onepath,vector<vector<int> > &result)
{
    current+=p->val;
    onepath.push_back(p->val);
    if(current==target&&p->left==NULL&&p->right==NULL) result.push_back(onepath);
    if(p->left!=NULL) isSum(p->left,target,current,onepath,result);
    if(p->right!=NULL) isSum(p->right,target,current,onepath,result);
    current-=p->val;
    onepath.pop_back();
}

vector<vector<int> > pathSum(TreeNode* root, int sum)
{
    vector<vector<int> > result;
    if(root==NULL) return result;
    int current=0;
    vector<int> onepath;
    isSum(root,sum,current,onepath,result);
    return result;
}

int main()
{
    ifstream fin("in.txt");
    int sum;
    fin>>sum;
    cout<<sum<<endl;
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
    vector<vector<int> > result=pathSum(root,sum);
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++) cout<<result[i][j]<<' ';
        cout<<endl;
    }
    return 0;
}
