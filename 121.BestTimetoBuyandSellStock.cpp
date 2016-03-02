#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
    int days=prices.size();
    if(days==0) return 0;
    int curmin=prices[0],tmp;
    prices[0]=0;
    for(int i=1;i<days;i++)
    {
        tmp=prices[i];
        prices[i]=max(prices[i-1],prices[i]-curmin);
        curmin=min(curmin,tmp);
    }
    return prices[days-1];
}

int main()
{
    ifstream fin("in.txt");
    vector<int> prices;
    int tmp;
    while(!fin.eof())
    {
        fin>>tmp;
        prices.push_back(tmp);
    }
    for(int i=0;i<prices.size();i++) cout<<prices[i]<<' ';
    cout<<endl;
    cout<<maxProfit(prices);
    return 0;
}
