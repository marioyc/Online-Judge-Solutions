#include <cstdio>
#include <algorithm>

using namespace std;

int mcd(int a, int b){
    while(a%b!=0){
        a%=b;
        swap(a,b);
    }
    
    return b;
}

int main(){
    int ans[1001];
    for(int i=1;i<=1000;i++) ans[i]=3; // (0,1) , (1,0) , (1,1)
    
    bool checked[1001][1001];
    for(int i=0;i<=1000;i++) fill(checked[i],checked[i]+1001,false);
    
    for(int i=1;i<=1000;i++)
        for(int j=i+1;j<=1000;j++)
            if(!checked[i][j]){
                if(mcd(i,j)==1){
                    for(int k=max(i,j);k<=1000;k++) ans[k]+=2;
                    for(int x=2*i,y=2*j;x<=1000 && y<=1000;x+=i,y+=j) checked[x][y]=true;
                }
            }
    
    int T,N;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&N);
        printf("%d %d %d\n",tc,N,ans[N]);
    }
    
    return 0;
}
