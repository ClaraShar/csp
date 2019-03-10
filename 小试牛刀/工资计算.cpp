#include <iostream>
using namespace std;

int main()
{
	int T,S,tax=0;
	cin>>T;
	if(T<=3500)
		S=T;
	else if(T>3500&&T<=4955)
		S=(T-3500)/0.97+3500;
	else if(T>4955&&T<=7655)
		S=(T-4955)/0.9+5000;
	else if(T>7655&&T<=11255)
		S=(T-7655)/0.8+8000;
	else if(T>11255&&T<=30755)
		S=(T-11255)/0.75+12500;
	else if(T>30755&&T<=44755)
		S=(T-30755)/0.7+38500;
	else if(T>44755&&T<=61005)
		S=(T-44755)/0.65+58500;
	else
		S=(T-61005)/0.55+83500;
	cout<<S;
	return 0;
}
//这尼玛是数学题啊
