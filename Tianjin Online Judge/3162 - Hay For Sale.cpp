#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    int H,C;
    int V[5000];
    
    scanf("%d %d",&C,&H);
    
    for(int i=0;i<H;i++) scanf("%d",&V[i]);
    
    bool M[50001];    
    fill(M,M+C+1,false);
    M[0]=true;
    
    for(int i=0;i<H;i++)
        for(int j=V[i];j<=C;j++) M[j]|=M[j-V[i]];
    
    int mx;
    
    for(int i=C;i>=0;i--)
        if(M[i]){
            mx=i;
            break;
        }
    
    printf("%d\n",mx);
    
    return 0;
}
