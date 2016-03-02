#include <iostream>
#include <fstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseBetween(ListNode* head, int m, int n)
{
    if(m==n) return head;
    ListNode *newhead=new ListNode(0);
    newhead->next=head;
    ListNode *result,*rear,*rp;
    result=rear=new ListNode(0);
    ListNode *p=newhead,*q;
    if(p->next==NULL) return newhead->next;
    int mcount=1,ncount=1;
    while(mcount<m)
    {
        mcount++;
        ncount++;
        p=p->next;
    }
    q=p;
    rp=p->next;
    p->next=rp->next;
    rear->next=rp;
    rear=rp;
    ncount++;
    while(ncount<=n)
    {
        rp=p->next;
        p->next=rp->next;
        rp->next=result->next;
        result->next=rp;
        ncount++;
    }
    rear->next=p->next;
    q->next=result->next;
    return newhead->next;
}

int main()
{
    ifstream fin("in.txt");
    int m,n;
    fin>>m>>n;
    cout<<m<<' '<<n<<endl;
    int tmp;
    ListNode *head,*rear,*p;
    fin>>tmp;
    head=rear=new ListNode(tmp);
    while(!fin.eof())
    {
        fin>>tmp;
        p=new ListNode(tmp);
        rear->next=p;
        rear=p;
    }
    rear->next=NULL;
    p=head;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    cout<<endl;
    ListNode *result=reverseBetween(head,m,n);
    p=result;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    return 0;
}
