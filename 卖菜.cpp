#include <iostream>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int first[n],second[n];
    for(int i=0;i<n;i++)
        cin>>first[i];
    second[0]=(first[0]+first[1])/2;
    cout<<second[0]<<" ";
    for(int i=1;i<n-1;i++)
    {
        second[i]=(first[i-1]+first[i]+first[i+1])/3;
        cout<<second[i]<<" ";
    }
    second[n-1]=(first[n-2]+first[n-1])/2;
    cout<<second[n-1];
    return 0;
}
