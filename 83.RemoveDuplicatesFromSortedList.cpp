#include <iostream>
#include <fstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteDuplicates(ListNode* head)
{
    ListNode *p=head,*del;
    if(head==NULL) return head;
    if(p->next==NULL) return head;
    while(p->next!=NULL)
    {
        while(p->next!=NULL&&p->next->val==p->val)
        {
            del=p->next;
            p->next=del->next;
            delete del;
        }
        if(p->next==NULL) break;
        p=p->next;
    }
    return head;
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
    ListNode *result=deleteDuplicates(head);
    p=result;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    return 0;
}
