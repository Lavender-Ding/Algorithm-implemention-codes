#include <iostream>
#include <fstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseKGroup(ListNode* head, int k)
{
    int count=0;
    if(k<=1||head==NULL) return head;
    ListNode *newhead=new ListNode(0);
    newhead->next=head;
    ListNode *now=newhead;
    ListNode *pk,*mov;
    while(1)
    {
        pk=now->next;
        count=0;
        while(pk!=NULL)
        {
            count++;
            pk=pk->next;
            if(count==k) break;
        }
        if(count<k) break;
        ListNode *h,*r;
        h=r=new ListNode(0);
        mov=now->next;
        now->next=mov->next;
        r->next=mov;
        r=mov;
        while(now->next!=pk)
        {
            mov=now->next;
            now->next=mov->next;
            mov->next=h->next;
            h->next=mov;
        }
        r->next=pk;
        now->next=h->next;
        now=r;
    }
    return newhead->next;
}

int main()
{
    ifstream fin("in.txt");
    int k;
    fin>>k;
    cout<<k<<endl;
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
    ListNode *result=reverseKGroup(head,k);
    p=result;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    return 0;
}
