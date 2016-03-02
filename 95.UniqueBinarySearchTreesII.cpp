#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vetcor<TreeNode*> add_one(TreeNode *p)
{
    vector<TreeNode*> addone;
    addone.push_back(p);

}

vector<TreeNode*> generateTrees(int n)
{
    vector<vector<TreeNode*> > trees;
    vector<TreeNode*> ori;
    if(n==0) return ori;
    trees.push_back(ori);
    TreeNode* p=new TreeNode(1);
    ori.push_back(p);
    trees.push_back(ori);
    int i,j,k;
    for(i=2;i<=n;i++)
    {
        vector<TreeNode*> one;
        for(k=0;k<trees[i-1].size();k++)
        {
            TreeNode* q=new TreeNode(i);
            q->left=trees[i-1][k];
            one.push_back(q);
        }
        for(j=1;j<i;j++)
        {
            TreeNode* t=new TreeNode(j);
            for(k=0;k<trees[j-1].size();k++)
            {
                t->left=trees[j-1][k];
            }
        }
    }
}

void printTree(TreeNode *p)
{
    vector<TreeNode*> tree;
    if(p==NULL) return;
    tree.push_back(p);
    cout<<p->val<<' ';
    int head=0,rear=1;
    while(head!=rear)
    {
        for(int i=head;i<rear;i++)
        {
            TreeNode *q=tree[i];
            if(q->left!=NULL)
            {
                tree.push_back(q->left);
                cout<<q->left->val<<' ';
            }
            else cout<<'#'<<' ';
            if(q->right!=NULL)
            {
                tree.push_back(q->right);
                cout<<q->right->val<<' ';
            }
            else cout<<'#'<<' ';
        }
        head=rear;
        rear=tree.size();
    }
    return;
}

int main()
{
    ifstream fin("in.txt");
    int n;
    fin>>n;
    cout<<n<<endl;
    vector<TreeNode*> result=generateTrees(n);
    for(int i=0;i<result.size();i++)
    {
        printTree(result[i]);
        cout<<endl;
    }
    return 0;
}
