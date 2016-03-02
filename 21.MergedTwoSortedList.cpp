#include <iostream>
#include <fstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

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

int main()
{
    ifstream fin("in.txt");
    ListNode *l1,*l2,*r1,*r2,*p;
    char c;
    int tmp;
    fin>>tmp;
    r1=l1=new ListNode(tmp);
    c=fin.get();
    while(c!='\n'&&!fin.eof())
    {
        fin>>tmp;
        c=fin.get();
        p=new ListNode(tmp);
        r1->next=p;
        r1=p;
    }
    fin>>tmp;
    r2=l2=new ListNode(tmp);
    while(!fin.eof())
    {
        fin>>tmp;
        p=new ListNode(tmp);
        r2->next=p;
        r2=p;
    }
    r1->next=NULL;
    r2->next=NULL;
    p=l1;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    cout<<endl;
    p=l2;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    cout<<endl;
    ListNode *result=mergeTwoLists(l1,l2);
    p=result;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    return 0;
}
