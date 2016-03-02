#include <iostream>
#include <fstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* rotateRight(ListNode* head, int k)
{
    if(head==NULL) return head;
    ListNode *p1,*p2;
    p1=head;
    p2=head;
    int len=0;
    while(p1!=NULL)
    {
        len++;
        p1=p1->next;
    }
    k=k%len;
    //cout<<len<<endl;
    if(k==0) return head;
    for(int i=0;i<k;i++) p2=p2->next;
    p1=head;
    while(p2->next!=NULL)
    {
        p1=p1->next;
        p2=p2->next;
    }
    ListNode *rehead=p1->next;
    p1->next=p2->next;
    p2->next=head;
    return rehead;
}

int main()
{
    ifstream fin("in.txt");
    int k;
    fin>>k;
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
    cout<<k<<endl;
    p=head;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    cout<<endl;
    ListNode *result=rotateRight(head,k);
    p=result;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    return 0;
}
