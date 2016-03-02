#include <iostream>
#include <fstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* swapPairs(ListNode* head)
{
    ListNode *newhead=new ListNode(0);
    if(head==NULL) return head;
    newhead->next=head;
    ListNode *p=newhead,*mov;
    if(p->next==NULL||p->next->next==NULL) return newhead->next;
    while(p->next!=NULL&&p->next->next!=NULL)
    {
        mov=p->next->next;
        p->next->next=mov->next;
        mov->next=p->next;
        p->next=mov;
        p=p->next->next;
    }
    return newhead->next;
}

int main()
{
    ifstream fin("in.txt");
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
    ListNode *result=swapPairs(head);
    p=result;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    return 0;
}
