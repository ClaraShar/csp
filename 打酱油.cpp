#include <iostream>
using namespace std;

int main()
{
	int N,cnt=0;
	cin>>N;
	N/=10;
	int five=N/5;
	cnt+=five*7;
	N-=five*5;
	int three=N/3;
	cnt+=three*4;
	N-=three*3;
	cnt+=N;
	cout<<cnt;
	return 0;
}