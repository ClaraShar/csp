#include<iostream>
using namespace std;
 
int main()
{
    int n,seat[20],head,j,mi;
    cin>>n;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int i=0;i<20;i++)
        seat[i]=5;
    for(int i=0;i<n;i++)
    {
        while(arr[i]!=0)
        {
            for(j=0;j<20;j++)
            {
                if(seat[j]>=arr[i])
                {
                    head=j*5+(6-seat[j]);
                    seat[j]-=arr[i];
                    for(int k=0;k<arr[i];k++,head++)
                        cout<<head<<' ';
                    cout<<endl;
                    arr[i]=0;
                    break;
                }
            }
            if(j==20)//没有连续的了
            {
                for(int k=0;k<20;k++)
                    if(seat[k]!=0)
                    {
                        mi=seat[k]>arr[i]?arr[i]:seat[k];
                        head=k*5+(6-seat[k]);
                        for(int k=0;k<mi;k++,head++)
                            cout<<head<<' ';
                        arr[i]-=seat[k];
                        seat[k]=0;
                    }
            }
        }
    }
    return 0;
}