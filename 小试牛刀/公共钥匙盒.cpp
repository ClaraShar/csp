#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Teacher
{
	int key;
	int time;//使用的时刻
	int flag;//1归还,0取出
};

bool cmp(Teacher t1,Teacher t2)
{
	if(t1.time!=t2.time)
		return t1.time<t2.time;
	else if(t1.flag!=t2.flag)
		return t1.flag>t2.flag;
	else
		return t1.key<t2.key;
}

int main()
{
	int n,k;
	cin>>n>>k;
	int Key[n+1];//钥匙盒
	vector<Teacher> teacher;
	for(int i=1;i<=n;i++)
		Key[i]=i;
	int key_no,lend_time,use_time;
	for(int i=0;i<k;i++)
	{
		cin>>key_no>>lend_time>>use_time;
		Teacher t;
		t.key=key_no;
		t.time=lend_time;
		t.flag=0;
		teacher.push_back(t);//取出时刻信息
		t.key=key_no;
		t.time=lend_time+use_time;
		t.flag=1;
		teacher.push_back(t);//归还时刻信息
	}
	sort(teacher.begin(),teacher.end(),cmp);//按所有操作时刻顺序排序
	for(int i=0;i<teacher.size();i++)
	{
		Teacher t=teacher[i];
		if(t.flag==0)//取出时刻信息
		{
			for(int j=1;j<=n;j++)
			{
				if(Key[j]==t.key)
				{
					Key[j]=0;
					break;
				}
			}
		}
		else
		{
			for(int j=1;j<=n;j++)
			{
				if(Key[j]==0)
				{
					Key[j]=t.key;
					break;
				}
			}
		}
	}
	for(int i=1;i<n;i++)
		cout<<Key[i]<<" ";
	cout<<Key[n];
	return 0;
}