#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin>>s;
	int res=0;
	for(int i=0;i<s.length();++i)
		res+=s[i]-'0';
	cout<<res;
	return 0;
}