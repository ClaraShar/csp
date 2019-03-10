#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	vector<int> nums;
	int n,result;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int temp;
		cin>>temp;
		nums.push_back(temp);
	}
	sort(nums.begin(),nums.end());
	result=nums[1]-nums[0];
	for(int i=2;i<n;i++)
	{
		result=min(result,nums[i]-nums[i-1]);
	}
	cout<<result;
	return 0;
}