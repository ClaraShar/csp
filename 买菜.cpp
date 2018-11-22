#include <iostream>
using namespace std;

int t[1000000]={0};//栈溢出，改成全局变量

int main()
{
    int n;
    cin>>n;
    int time=0,start=1000000,end=0;
    for(int i=0;i<n;i++)
    {
        int come,go;
        cin>>come>>go;
        if(come<start)
            start=come;
        if(go>end)
            end=go;
        for(int j=come;j<go;j++)
            t[j]++;
    }
    for(int i=0;i<n;i++)
    {
        int come,go;
        cin>>come>>go;
        if(come<start)
            start=come;
        if(go>end)
            end=go;
        for(int j=come;j<go;j++)
            t[j]++;
    }
    for(int i=start;i<end;i++)
        if(t[i]==2)
            time+=1;
    cout<<time;
    return 0;
}