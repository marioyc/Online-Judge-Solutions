#include<cstdio>
#include<queue>

using namespace std;

int dx[]={1,-1,0,0,0,0};
int dy[]={0,0,1,-1,0,0};
int dz[]={0,0,0,0,1,-1};

bool valid(int &x1, int &y1, int &z1, int &x2, int &y2, int  &z2){
    for(int i=0;i<6;i++)
        if(x1+dx[i]==x2 && y1+dy[i]==y2 && z1+dz[i]==z2) return true;
    
    return false;
}

int main(){    
    int T,N;
    int x[1000],y[1000],z[1000];
    bool check;
    int cont;
    
    scanf("%d\n",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&N);
        
        for(int i=0;i<N;i++) scanf("%d,%d,%d",&x[i],&y[i],&z[i]);
        
        cont=0;
        
        for(int i=1;i<N;i++){
            check=true;
            
            for(int j=0;j<i;j++) if(x[i]==x[j] && y[i]==y[j] && z[i]==z[j]) check=false;
            
            if(check){
                check=false;
                for(int j=0;j<i;j++)
                    if(valid(x[i],y[i],z[i],x[j],y[j],z[j])){
                        check=true;
                        cont++;
                    }
            }
            
            if(!check){
                printf("%d NO %d\n",tc,i+1);
                break;
            }
        }
        
        if(!check) continue;
        
        printf("%d %d\n",tc,6*N-2*cont);
    }
    
    return 0;
}
