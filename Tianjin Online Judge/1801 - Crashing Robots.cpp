#include<cstdio>

using namespace std;

int main(){
    int T,N,M,R,C;
    bool ok;
    int X[100];
    int Y[100];
    int dir[100];
    char c;
    
    int dr[]={1,0,-1,0};
    int dc[]={0,1,0,-1};
    
    int pos[100][100];
    
    int n,m;
    
    scanf("%d",&T);
    
    for(int i=0;i<T;i++){
        scanf("%d %d %d %d",&C,&R,&N,&M);
        
        for(int j=0;j<C;j++)
            for(int k=0;k<R;k++) pos[j][k]=-1;
        
        for(int j=0;j<N;j++){
            scanf("%d %d %c",&X[j],&Y[j],&c);
            X[j]--;
            Y[j]--;
            pos[X[j]][Y[j]]=j;
            
            switch(c){
                case 'N':
                    dir[j]=0;
                    break;
                case 'E':
                    dir[j]=1;
                    break;
                case 'S':
                    dir[j]=2;
                    break;
                case 'W':
                    dir[j]=3;
                    break;
            }
        }
        
        ok=true;
        
        for(int j=0;j<M;j++){
            scanf("%d %c %d",&n,&c,&m);
            
            if(!ok) continue;
            
            n--;
            
            if(c=='L') dir[n]=(dir[n]+3*m)%4;
            else if(c=='R') dir[n]=(dir[n]+m)%4;
            else{
                for(int k=1;k<=m && X[n]+k*dc[dir[n]]<C && X[n]+k*dc[dir[n]]>=0 && Y[n]+k*dr[dir[n]]<R && Y[n]+k*dr[dir[n]]>=0;k++){
                    if(pos[X[n]+k*dc[dir[n]]][Y[n]+k*dr[dir[n]]]!=-1){
                        printf("Robot %d crashes into robot %d\n",n+1,pos[X[n]+k*dc[dir[n]]][Y[n]+k*dr[dir[n]]]+1);
                        ok=false;
                        break;
                    }
                }
                
                if(ok && (X[n]+m*dc[dir[n]]>=C || X[n]+m*dc[dir[n]]<0 || Y[n]+m*dr[dir[n]]>=R || Y[n]+m*dr[dir[n]]<0)){
                    ok=false;
                    printf("Robot %d crashes into the wall\n",n+1);
                }
                
                if(ok){
                    pos[X[n]][Y[n]]=-1;
                    pos[X[n]+m*dc[dir[n]]][Y[n]+m*dr[dir[n]]]=n;
                    X[n]=X[n]+m*dc[dir[n]];
                    Y[n]=Y[n]+m*dr[dir[n]];
                }
            }
        }
        
        if(ok) printf("OK\n");
    }
    
    return 0;
}
