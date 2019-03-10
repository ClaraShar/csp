#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> step;
	int temp;
	do
	{
		cin>>temp;
		step.push_back(temp);
	}
	while(temp!=0);
	int i=0,last=1,score=0;
	do
	{
		if(step[i]==0)
			break;
		if(last==1)
		{
			if(step[i]==1)
				score+=1;
			else if(step[i]!=1)
			{
				last=2;
				score+=last;
			}
		}
		else
		{
			if(step[i]==1)
			{
				score+=1;
				last=1;
			}
			else if(step[i]!=1)
			{
				last+=2;
				score+=last;
			}
		}
		i++;
	}while(i<step.size());
	cout<<score;
	return 0;
}