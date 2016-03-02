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
    bool flag=false;
    if(head==NULL) return head;
    if(p->next==NULL) return head;
    ListNode *newhead=new ListNode(0);
    newhead->next=head;
    p=newhead->next;
    while(p->next!=NULL)
    {
        flag=false;
        while(p->next!=NULL&&p->next->val==p->val)
        {
            flag=true;
            del=p->next;
            p->next=del->next;
            delete del;
        }
        if(flag==true&&p->next!=NULL)
        {
            p->val=p->next->val;
            del=p->next;
            p->next=del->next;
            delete del;
        }
        else if(flag==true&&p->next==NULL)
        {
            ListNode*q=newhead;
            while(q->next!=p) q=q->next;
            del=q->next;
            q->next=del->next;
            delete del;
            break;
        }
        else if(flag==false&&p->next==NULL) break;
        else if(flag==false&&p->next!=NULL) p=p->next;
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
    ListNode *result=deleteDuplicates(head);
    p=result;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    return 0;
}
