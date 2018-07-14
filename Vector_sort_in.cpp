#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int>nums(100,100);
    int i;
    for(i=0 ; i<10 ; i++)
    {
        nums.insert(lower_bound(nums.begin(),nums.end(),1),1); //帮助元素添加的同时进行排序
    }
    auto j = find(nums.begin(),nums.end(),1);
    nums.erase(j);
    for(i=0 ; i<10 ; i++)
    {
        cout<<nums[i]<<"\n";
    }
    return 0;
}
