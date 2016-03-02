#include <iostream>
#include <vector>
#include <fstream>
#include <map>

using namespace std;

vector<int> twoSum(vector<int>& nums, int target);

int main()
{
    ifstream fin("in.txt");
    vector <int> numbers;
    vector <int> index;
    int num_tmp,target=9;
    while (!fin.eof())
    {
        fin>>num_tmp;
        numbers.push_back(num_tmp);
    }
    for (int i=0;i<numbers.size();i++) cout<<numbers[i]<<' ';
    index=twoSum(numbers,target);
    for (int i=0;i<index.size();i++) cout<<index[i]<<' ';
    return 0;
}

vector<int> twoSum(vector<int>& nums, int target)
{
    vector <int> index;
    map <int,int> nummap;
    for (int i=0;i<nums.size();i++)
    {
        if (!nummap.count(nums[i]))
        {
            nummap.insert(pair<int,int>(nums[i],i));
        }
        if (nummap.count(target-nums[i]))
        {
            int j=nummap[target-nums[i]];
            if (j<i)
            {
                index.push_back(j+1);
                index.push_back(i+1);
                return index;
            }
        }
    }
    return index;
}


