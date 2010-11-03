#include<cstdio>
#include<algorithm>

using namespace std;

int main(){    
    bool N[1001];
    int m[6];
    int a[]={1,2,3,5,10,20};
    int total,cont;
    
    while(scanf("%d %d %d %d %d %d",&m[0],&m[1],&m[2],&m[3],&m[4],&m[5])==6){
        total=0;
        for(int i=0;i<6;i++) total+=a[i]*m[i];
        
        fill(N,N+total+1,false);
        N[0]=true;
        
        for(int i=0;i<6;i++)
            for(int j=0;j<m[i];j++)
                for(int k=total;k>=a[i];k--) N[k]|=N[k-a[i]];
        
        cont=0;
        for(int i=0;i<=total;i++) if(N[i]) cont++;
        printf("%d\n",cont);
    }
    
    return 0;
}
