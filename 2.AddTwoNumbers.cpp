#include <iostream>
#include <fstream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

int main()
{
    ifstream fin("in.txt");
    ListNode *l1_head,*l1_rear,*p;
    ListNode *l2_head,*l2_rear;
    l1_head=l1_rear = new ListNode(-1);
    l2_head=l2_rear = new ListNode(-1);
    while (1)
    {
        int tmp;
        fin>>tmp;
        p=new ListNode(tmp);
        l1_rear->next=p;
        l1_rear=p;
        if (fin.get()=='\n')
            break;
    }
    l1_rear->next=NULL;
    p=l1_head->next;
    while (p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    cout<<endl;
    while (!fin.eof())
    {
        int tmp;
        fin>>tmp;
        p=new ListNode(tmp);
        l2_rear->next=p;
        l2_rear=p;
    }
    l2_rear->next = NULL;
    p=l2_head->next;
    while (p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    cout<<endl;
    ListNode *result=addTwoNumbers(l1_head->next,l2_head->next);
    p=result;
    cout<<endl;
    while(p!=NULL)
    {
        cout<<p->val<<' ';
        p=p->next;
    }
    return 0;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
{
    ListNode *p1=l1;
    ListNode *p2=l2;
    ListNode *re_head,*re_rear,*r;
    re_head=re_rear=new ListNode(-1);
    int num1=p1->val;
    int num2=p2->val;
    int c=0;
    while(1)
    {
        int sum=num1+num2+c;
        r=new ListNode(sum%10);
        if(sum<10) c=0;
        if(sum>=10) c=1;
        //cout<<sum<<' ';
        re_rear->next=r;
        re_rear=r;
        if(p1==NULL&&p2==NULL) break;
        if(p1->next!=NULL&&p2->next!=NULL)
        {
            p1=p1->next;
            p2=p2->next;
            num1=p1->val;
            num2=p2->val;
        }
        else if(p1->next==NULL&&p2->next!=NULL)
        {
            num1=0;
            p2=p2->next;
            num2=p2->val;
        }
        else if(p1->next!=NULL&&p2->next==NULL)
        {
            num2=0;
            p1=p1->next;
            num1=p1->val;
        }
        else
        {
            if(c==1)
            {
                num1=num2=0;
                p1=p1->next;
                p2=p2->next;
            }
            else break;
        }
    }
    re_rear->next=NULL;
    return re_head->next;
}
