#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string,string> dict;
string str;

string parseString(int &i)
{
    string temp;
    if(str[i]=='"')
    	i++;
    else assert(0);
    
    while(i<str.size())
    {
        if(str[i]=='\\')
        {
            temp+=str[++i];
            i++;
        }
        else if(str[i]=='"')
            break;
        else
        {
            temp+=str[i];
            i++;
        }
    }
    if(str[i]=='"')
    	i++;
    else
    	assert(0);
    return temp;
}

void parseObject(string prefix,int i)
{
    if(str[i]=='{')
    	i++;
    else
    	assert(0);
    
    string key,value;
    bool strType=false;//false:key,true:value
    while(i<str.size())
    {
        if(str[i]=='"')
        {
            string temp=parseString(i);
            if(strType)
            {//value
                value=temp;
                //cout << key << " " << value << "\n";
                dict[key]=value;
            }
            else
            { // key
                key=prefix+(prefix=="" ? "":".")+temp;
            }
        }
        else if(str[i]==':')
        {
            strType=true;
            i++;
        }
        else if(str[i]==',')
        {
            strType=false;
            i++;
        }
        else if(str[i]=='{')
        {
            dict[key] = ""; 
            parseObject(key,i);
        }
        else if(str[i] == '}') {
            break;
        }
        else {
            i++;
        }
    }
    if(str[i] == '}')
    	i++;
    else
    	assert(0);
}

int main()
{
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
        string temp;
        cin>>temp;
        str+=temp;
    }
    parseObject("",0);
	string query;
    for(int i=0;i<m;i++)
    {
        cin>>query;
        if(dict.find(query)==dict.end())
            cout << "NOTEXIST\n";
        else
        {
            if(dict[query] == "")
                cout << "OBJECT\n";
            else
                cout << "STRING " << dict[query] << "\n";
        }
    }
	return 0;
}