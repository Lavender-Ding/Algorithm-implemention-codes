#include <iostream>
#include <fstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* partition(ListNode* head, int x)
{
    ListNode *newhead=new ListNode(0);
    newhead->next=head;
    ListNode *small=newhead,*now=newhead,*del;
    if(head==NULL||head->next==NULL) return head;
    while(now->next!=NULL&&now->next->val<x) now=now->next;
    small=now;
    while(now->next!=NULL)
    {
        if(now->next->val>=x) now=now->next;
        else
        {
            del=now->next;
            now->next=del->next;
            del->next=small->next;
            small->next=del;
            small=small->next;
        }
    }
    return newhead->next;
}

int main()
{
    ifstream fin("in.txt");
    int val;
    fin>>val;
    cout<<val<<endl;
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
    ListNode *result=partition(head,val);
    p=result;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    return 0;
}
