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

bool isSame=true;

void sametree(TreeNode *p,TreeNode *q)
{
    if(isSame==true)
    {
        if(p!=NULL&&q!=NULL&&p->val==q->val)
        {
            sametree(p->left,q->left);
            sametree(p->right,q->right);
        }
        else if(p==NULL&&q==NULL) return;
        else
        {
            isSame=false;
            return;
        }
    }
    else return;
}

bool isSameTree(TreeNode* p, TreeNode* q)
{
    isSame=true;
    sametree(p,q);
    return isSame;
}

int main()
{
    ifstream fin("in.txt");
    TreeNode *root1,*root2;
    string c;
    fin>>c;
    if(c!="#") root1=new TreeNode(CharToInt(c));
    vector<TreeNode*> tree1;
    vector<TreeNode*> tree2;
    tree1.push_back(root1);
    int i=0;
    char cc=fin.get();
    while(cc!='\n')
    {
        TreeNode *p=tree1[i];
        string l,r;
        if(!fin.eof()) fin>>l;
        if(!fin.eof()) fin>>r;
        cc=fin.get();
        if(l!="#")
        {
            p->left=new TreeNode(CharToInt(l));
            tree1.push_back(p->left);
        }
        if(r!="#")
        {
            p->right=new TreeNode(CharToInt(r));
            tree1.push_back(p->right);
        }
        i++;
    }
    if(!fin.eof())
    {
        fin>>c;
        if(c!="#") root2=new TreeNode(CharToInt(c));
        tree2.push_back(root2);
        i=0;
    }
    while(!fin.eof())
    {
        TreeNode *p=tree2[i];
        string l,r;
        if(!fin.eof()) fin>>l;
        if(!fin.eof()) fin>>r;
        if(l!="#")
        {
            p->left=new TreeNode(CharToInt(l));
            tree2.push_back(p->left);
        }
        if(r!="#")
        {
            p->right=new TreeNode(CharToInt(r));
            tree2.push_back(p->right);
        }
        i++;
    }
    for(i=0;i<tree1.size();i++) cout<<tree1[i]->val<<' ';
    cout<<endl;
    for(i=0;i<tree2.size();i++) cout<<tree2[i]->val<<' ';
    cout<<endl;
    cout<<isSameTree(root1,root2);
    return 0;
}
