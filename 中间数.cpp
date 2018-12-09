#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<int> nums;
	cin>>n;
	for(int i=0;i<n;++i)
	{
		int temp;
		cin>>temp;
		nums.push_back(temp);
	}
	sort(nums.begin(),nums.end());
	int mid=n/2,left=mid,right=n-mid-1;
	for(int i=0;i<mid;i++)
	{
		if(nums[i]==nums[mid])
			left--;
	}
	for(int i=mid+1;i<n;i++)
	{
		if(nums[i]==nums[mid])
			right--;
	}
	if(left==right)
		cout<<nums[mid];
	else
		cout<<"-1";
	return 0;
}

/*
https://blog.csdn.net/daijin888888/article/details/76199741
*/