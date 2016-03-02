#include <iostream>
#include <fstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* removeNthFromEnd(ListNode* head, int n)
{
    ListNode *newhead=new ListNode(0);
    newhead->next=head;
    int len=0,index,i;
    ListNode *p=head;
    while(p!=NULL)
    {
        len++;
        p=p->next;
    }
    index=len-n;
    if(index>=len||index<0) return newhead->next;
    cout<<len<<' '<<index<<endl;
    p=newhead;
    for(i=0;i<index;i++) p=p->next;
    ListNode *del=p->next;
    p->next=del->next;
    delete del;
    return newhead->next;
}

int main()
{
    ifstream fin("in.txt");
    int n;
    fin>>n;
    cout<<n<<endl;
    ListNode *head,*rear,*p;
    int tmp;
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
    ListNode *result=removeNthFromEnd(head,n);
    p=result;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    return 0;
}
