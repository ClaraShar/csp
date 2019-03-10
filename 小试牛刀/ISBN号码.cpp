#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int temp=0,j=1;
    for(int i=0;i<(int)s.length()-1;i++)
    {
        if(s[i]!='-')
            temp+=(s[i]-'0')*j++;
    }
	char c=temp%11;
	if(c==10)
		c='X';
	else
        c=c+'0';
	if(c == s[s.length()-1])
		cout<<"Right"<<endl;
	else
	{
		s[s.length()-1]=c;
		cout<<s<<endl;
	}
	cin>>s;
	return 0;
}