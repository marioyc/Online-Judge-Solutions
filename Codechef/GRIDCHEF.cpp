#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int T,N,M,G[100000];
    
    scanf("%d",&T);
    
    while(T--){
        scanf("%d %d",&N,&M);
        
        for(int i = 0;i<N;++i)
            for(int j = 0;j<M;++j)
                scanf("%d",&G[M*i+j]); 
        
        if(N==1){
            if(G[M*0+1]>G[M*0+M-2]){
                printf("%d\n3\n",G[M*0+1]);
                printf("0 0\n0 1\n0 0\n");
            }else{
                printf("%d\n3\n",G[M*0+M-2]);
                printf("0 %d\n0 %d\n0 %d\n",M-1,M-2,M-1);
            }
        }else if(M==1){
            if(G[M*1+0]>G[M*(N-2)+0]){
                printf("%d\n3\n",G[M*1+0]);
                printf("0 0\n1 0\n0 0\n");
            }else{
                printf("%d\n3\n",G[M*(N-2)+0]);
                printf("%d 0\n%d 0\n%d 0\n",N-1,N-2,N-1);
            }
        }else{
            int sum1 = 0,sum2 = 0;
            
            for(int i = 0;i<N;++i)
                for(int j = 0;j<M;++j)
                    if(((i+j)&1)!=0)
                        sum1 += G[M*i+j];
                    else
                        sum2 += G[M*i+j];
            
            if(N%2==0){
                printf("%d\n",max(sum1,sum2));
                printf("%d\n",M*N+1);
                
                if(sum1>sum2){
                    for(int i = 0;i<N;++i) printf("%d 0\n",i);
                    for(int i = N-1;i>=0;--i){
                        if(i&1) for(int j = 1;j<M;++j) printf("%d %d\n",i,j);
                        else for(int j = M-1;j>0;--j) printf("%d %d\n",i,j);
                    }
                    printf("0 0\n");
                }else{
                    for(int i = N-1;i>=0;--i) printf("%d 0\n",i);
                    for(int i = 0;i<N;++i){
                        if(i&1) for(int j = M-1;j>0;--j) printf("%d %d\n",i,j);
                        else for(int j = 1;j<M;++j) printf("%d %d\n",i,j);
                    }
                    printf("%d 0\n",N-1);
                }
                
            }else if(M%2==0){
                printf("%d\n",max(sum1,sum2));
                printf("%d\n",M*N+1);
                
                if(sum1>sum2){
                    for(int i = 0;i<M;++i) printf("0 %d\n",i);
                    for(int i = M-1;i>=0;--i){
                        if(i&1) for(int j = 1;j<N;++j) printf("%d %d\n",j,i);
                        else for(int j = N-1;j>0;--j) printf("%d %d\n",j,i);
                    }
                    printf("0 0\n");
                }else{
                    for(int i = M-1;i>=0;--i) printf("0 %d\n",i);
                    for(int i = 0;i<M;++i){
                        if(i&1) for(int j = N-1;j>0;--j) printf("%d %d\n",j,i);
                        else for(int j = 1;j<N;++j) printf("%d %d\n",j,i);
                    }
                    printf("0 %d\n",M-1);
                }
            }else{
                printf("%d\n",sum1);
                printf("%d\n",M*N);
                
                printf("0 0\n");
                for(int i = 0;i+2<M;++i){
                    if(i&1) for(int j = N-1;j>0;--j) printf("%d %d\n",j,i);
                    else for(int j = 1;j<N;++j) printf("%d %d\n",j,i);
                }
                for(int i = N-1;i>1;--i){
                    if(i&1) printf("%d %d\n%d %d\n",i,M-1,i,M-2);
                    else printf("%d %d\n%d %d\n",i,M-2,i,M-1);
                }
                printf("%d %d\n",1,M-1);
                for(int i = M-1;i>=0;--i) printf("%d %d\n",0,i);
            }
        }
    }
    
    return 0;
}
