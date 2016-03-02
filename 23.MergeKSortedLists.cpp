#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/*
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode *h1=new ListNode(0);
    ListNode *h2=new ListNode(0);
    h1->next=l1;
    h2->next=l2;
    ListNode *p1=h1,*p2=h2,*p,*del;
    while(1)
    {
        if(p1->next==NULL&&p2->next!=NULL)
        {
            p1->next=p2->next;
            return h1->next;
        }
        if(p2->next==NULL) return h1->next;
        if(p1->next->val<=p2->next->val) p1=p1->next;
        else
        {
            p=new ListNode(p2->next->val);
            p->next=p1->next;
            p1->next=p;
            del=p2->next;
            p2->next=del->next;
            delete del;
            p1=p1->next;
        }
    }
    return h1->next;
}
*/

ListNode* mergeTwoLists(ListNode* p1, ListNode* p2)
{
    ListNode *r=new ListNode(0),*tmp,*q=r;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->val<=p2->val)
        {
            tmp=p1;
            p1=p1->next;
            q->next=tmp;
            q=q->next;
        }
        else
        {
            tmp=p2;
            p2=p2->next;
            q->next=tmp;
            q=q->next;
        }
    }
    if(p1!=NULL) q->next=p1;
    if(p2!=NULL) q->next=p2;
    return r->next;
}

ListNode* DivideTwo(int right,int left,vector<ListNode*>& lists)
{
    if(right==left) return lists[right];
    return mergeTwoLists(DivideTwo(right,(right+left)/2,lists),DivideTwo((right+left)/2+1,left,lists));
}

ListNode* mergeKLists(vector<ListNode*>& lists)
{
    if(lists.size()==0)
    {
        ListNode *result=NULL;
        return result;
    }
    return DivideTwo(0,lists.size()-1,lists);
}

int main()
{
    ifstream fin("in.txt");
    vector<ListNode*> lists;
    char c;
    ListNode *head,*rear,*p;
    int tmp;
    fin>>tmp;
    head=rear=new ListNode(tmp);
    c=fin.get();
    while(!fin.eof())
    {
        if(c=='\n')
        {
            rear->next=NULL;
            lists.push_back(head);
            fin>>tmp;
            head=rear=new ListNode(tmp);
            c=fin.get();
        }
        else
        {
            fin>>tmp;
            c=fin.get();
            p=new ListNode(tmp);
            rear->next=p;
            rear=p;
        }
    }
    rear->next=NULL;
    lists.push_back(head);
    for(int i=0;i<lists.size();i++)
    {
        head=lists[i];
        p=head;
        while(p!=NULL)
        {
            cout<<p->val<<' ';
            p=p->next;
        }
        cout<<endl;
    }
    ListNode *result=mergeKLists(lists);
    p=result;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    return 0;
}
