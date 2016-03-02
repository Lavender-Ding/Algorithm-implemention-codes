#include <iostream>
#include <fstream>

using namespace std;

bool isPalindrome(int x)
{
    int tmp=x;
    int len=0;
    if(x<0) return false;
    if(x<10) return true;
    while(tmp!=0)
    {
        len++;
        tmp=tmp/10;
    }
    int comp1=x,comp2=0,count=0;
    while(count<len/2)
    {
        comp2=comp2*10+comp1%10;
        comp1=comp1/10;
        count++;
    }
    if(len%2==1) comp1=comp1/10;
    if(comp1==comp2) return true;
    else return false;
}

int main()
{
    ifstream fin("in.txt");
    int x;
    fin>>x;
    cout<<x<<endl<<isPalindrome(x);
    return 0;
}
