#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

double myPow(double x, int n)
{
    if(n==0)
        return 1.0;
    if(n<0)
        return 1.0/pow(x,-n);
    double half = pow(x,n>>1);
    if(n%2==0)
        return half*half;
    else
        return half*half*x;
}

int main()
{
    ifstream fin("in.txt");
    int n;
    double x;
    fin>>x>>n;
    cout<<x<<' '<<n<<endl;
    cout<<myPow(x,n);
    return 0;
}
