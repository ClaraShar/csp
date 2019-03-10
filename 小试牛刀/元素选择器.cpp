#include <iostream>
#include <string>
using namespace std;

struct File
{
	int row;
	string css;
};

int n,m;

void choose(string s,File file[])
{
	int xzgs_row[n];
	int xzgs=0,dgs=0;//选中个数,点个数
	for(int i=0;i<n;i++)
	{
		if(file[i].css.find(s)!=-1)
		{
			dgs=count(file[i].css.begin(),file[i].css.end(),'.');//点个数
			for(int j=i+1;j<n;j++)
			{
				if(file[j].css.find(s)&&count(file[j].css.begin(),file[j].css.end(),'.')>dgs)
				{
					xzgs_row[xzgs]=file[j].row;
					xzgs++;
				}
			}
			break;
		}
	}
	cout<<xzgs;
	for(int i=0;i<xzgs;i++)
		cout<<" "<<xzgs_row[i];
	cout<<endl;
}

int main()
{
	cin>>n>>m;
	File file[n];
	string s[m];
	for(int i=0;i<n;i++)
	{
		file[i].row=i+1;
		cin>>file[i].css;
	}
	for(int i=0;i<m;i++)
		cin>>s[i];
	for(int i=0;i<m;i++)
		choose(s[i],file);
	return 0;
}