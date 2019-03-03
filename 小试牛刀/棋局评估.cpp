#include <iostream>
using namespace std;

int mp[4][4];//map为棋盘

bool row(int r,int tag){                                            
    return mp[r][0]==tag && mp[r][0]==mp[r][1] && mp[r][1]==mp[r][2];          //判断行是否三颗相连
}
bool col(int c,int tag){
    return mp[0][c]==tag && mp[0][c]==mp[1][c] && mp[1][c]==mp[2][c];          //判断列是否三颗相连
}

int space(){
    int res=0;
    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            if(!mp[i][j])
            	res++;
    return res;
}

int win(int tag){//tag为当时下棋的人，判断当前局面胜负情况,看是否已经是赢的局面了
    int wi=0,ans;
    if(row(0,tag)||row(1,tag)||row(2,tag)) wi=1;
    if(col(0,tag)||col(1,tag)||col(2,tag)) wi=1;
    if(mp[0][0]==tag && mp[0][0]==mp[1][1] && mp[1][1]==mp[2][2])wi=1;//对角线
    if(mp[0][2]==tag && mp[0][2]==mp[1][1] && mp[1][1]==mp[2][0])wi=1;
    if(!wi)//wi标志是否是有人赢的局面
    	return 0;
    ans=space()+1;
    return (tag==1)?ans:-ans;//返回分数                                       
}

int DFS(int peo){                                                        //对抗搜索
    if(!space())
    	return 0;//下满了，结束
    int Max=-10,Min=10;//0-Alice-Max，1-Bob-Min
    for(int i=0;i<3;i++)
    {
        for(int j=0,w;j<3;j++)
        {
            if(!mp[i][j])//如果当前格子为空
            {
                mp[i][j]=peo+1;//下棋的人，1为X，2为O
                w=win(peo+1);//计算当前可以赢吗？
                if(w)//如果可以赢
                {
                    mp[i][j]=0;//回溯
                    return w>0?max(Max,w):min(Min,w);//看得分是正是负？
                }
                //如果当前还不能赢
                if(!peo)
                	Max=max(Max,DFS(1));//Alice得分最大
                else
                	Min=min(Min,DFS(0));//Bob得分最小
                mp[i][j]=0;//回溯
            }
        }
    }
    return peo?Min:Max;//0-Alice-Max，1-Bob-Min
}

int main()
{
	int T;
	cin>>T;//注意可能是文件
	while(T--){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                cin>>mp[i][j];
        int x=win(1),y=win(2);//判断是否已经有人赢了
        if(x){cout<<x<<endl;continue;}
        if(y){cout<<y<<endl;continue;}
        cout<<DFS(0)<<endl; //不是的话，Alice先下（0表示Alice下，1表示Bob下）
    }
	return 0;
}