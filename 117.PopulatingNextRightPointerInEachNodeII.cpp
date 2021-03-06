#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

int CharToInt(string c)
{
    stringstream ss;
    ss<<c;
    int tmp;
    ss>>tmp;
    return tmp;
}

void connect(TreeLinkNode *root)
{
    if(root==NULL) return;
    root->next=NULL;
    TreeLinkNode *p=root;
    TreeLinkNode *tmp;
    TreeLinkNode *pre;
    while(1)
    {
        while(p!=NULL&&p->left==NULL&&p->right==NULL) p=p->next;
        if(p==NULL) break;
        tmp=p;
        if(p->left==NULL)
        {
            pre=p->right;
            p=p->right;
        }
        else
        {
            pre=p->left;
            p=p->left;
        }
        while(tmp!=NULL)
        {
            if(tmp->left==NULL&&tmp->right==NULL)
            {
                tmp=tmp->next;
                continue;
            }
            if(tmp==p&&tmp->left!=NULL&&tmp->right!=NULL)
            {
                pre->next=tmp->right;
                pre=tmp->right;
            }
            else if(tmp!=p)
            {
                if(tmp->left!=NULL&&tmp->right!=NULL)
                {
                    pre->next=tmp->left;
                    tmp->left->next=tmp->right;
                    pre=tmp->right;
                }
                else if(tmp->left==NULL)
                {
                    pre->next=tmp->right;
                    pre=tmp->right;
                }
                else if(tmp->right==NULL)
                {
                    pre->next=tmp->left;
                    pre=tmp->left;
                }
            }
            tmp=tmp->next;
        }
        pre->next=NULL;
    }
}

int main()
{
    ifstream fin("in.txt");
    TreeLinkNode *root;
    string c;
    fin>>c;
    if(c!="#") root=new TreeLinkNode(CharToInt(c));
    vector<TreeLinkNode*> tree;
    tree.push_back(root);
    int i=0;
    while(!fin.eof())
    {
        TreeLinkNode *p=tree[i];
        string l,r;
        if(!fin.eof()) fin>>l;
        if(!fin.eof()) fin>>r;
        if(l!="#")
        {
            p->left=new TreeLinkNode(CharToInt(l));
            tree.push_back(p->left);
        }
        if(r!="#")
        {
            p->right=new TreeLinkNode(CharToInt(r));
            tree.push_back(p->right);
        }
        i++;
    }
    for(i=0;i<tree.size();i++) cout<<tree[i]->val<<' ';
    cout<<endl;
    connect(root);
    TreeLinkNode *p=root;
    while(p!=NULL)
    {
        TreeLinkNode *tmp=p;
        while(tmp!=NULL)
        {
            cout<<tmp->val<<' ';
            tmp=tmp->next;
        }
        cout<<endl;
        p=p->left;
    }
    return 0;
}
