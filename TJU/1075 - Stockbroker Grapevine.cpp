#include<iostream>
#include<string>

using namespace std;

int main(){    
    int T[100][100];
    int N;
    int m,a,b;
    int min_time, start;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++) fill(T[i],T[i]+N,(1<<20));
        for(int i=0;i<N;i++) T[i][i]=0;
        
        for(int i=0;i<N;i++){
            scanf("%d",&m);
            
            for(int j=0;j<m;j++){
                scanf("%d %d",&a,&b);
                T[i][a-1]=b;
            }
        }
        
        for(int k=0;k<N;k++)
            for(int i=0;i<N;i++)
                for(int j=0;j<N;j++)
                    T[i][j]=min(T[i][j],T[i][k]+T[k][j]);
        
        min_time=(1<<20);
        
        for(int i=0;i<N;i++){
            m=-1;
            for(int j=0;j<N;j++){
                m=max(m,T[i][j]);
            }
            if(m<min_time){
                start=i;
                min_time=m;
            }
        }
        
        if(min_time==(1<<20)) printf("disjoint\n");
        else printf("%d %d\n",start+1,min_time);
    }
    
    return 0;
}
