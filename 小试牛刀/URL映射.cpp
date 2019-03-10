#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int n,m;
map<string,string> reg;//规则、规则名
vector<string> url;

void match(string s)
{
	for(map<string,string>::iterator::it=reg.begin();it!=reg.end();++it)
	{
		if(it->first.find(s)!=-1)
	}
}

void deal(string s)//分割字符串
{
	vector<string> words;
	string temp;
	for(int i=1;i<s.length;++i)
	{
		if(s[i]=='/'&&i!=s.length-1)
		{
			words.push_back(temp);
			temp.erase(0.temp.length);
		}
		else
			temp+=s[i];
	}
	words.push_back(temp);
	bool tag=false;
	for(int i=0;i<words.size();++i)
	{
		match(words[i]);
	}
}

int main()
{
	cin>>n>>m;
	for(int i=0;i<n;++i)
	{
		string regular,reg_name;
		cin>>regular>>reg_name;
		map[regular]=reg_name;
	}
	for(int i=0;i<m;++i)
	{
		string url_name;
		cin>>url_name;
		url.push_back(url_name);
	}
	for(int i=0;i<m;++i)
	{
		deal(url[i]);
	}
	return 0;
}