#include <cstdio>
#include <cmath>

using namespace std;

double x,y;

double dist2(double &x1, double &y1, double &x2, double &y2){
    x=x1-x2;
    y=y1-y2;
    return x*x+y*y;
}

int N,f[12],ans;
bool M[12][12];

bool ok(int v){
    for(int i=0;i<v;i++)
        if(M[v][i] && f[v]==f[i]) return false;
    return true;
}

void search(int n, int freq){
    if(freq>=ans) return;
    if(n==N) ans=freq;
    else{
        for(int i=1;i<=freq;i++){
            f[n]=i;
            if(!ok(n)) continue;
            search(n+1,freq);
        }
        for(int i=freq+1;i<ans;i++){
            f[n]=i;
            if(!ok(n)) continue;
            search(n+1,i);
        }
    }
}

int main(){
    int tc=1;
    double x[12],y[12];
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++) scanf("%lf %lf",&x[i],&y[i]);
        
        for(int i=0;i<N;i++){
            M[i][i]=false;
            for(int j=i+1;j<N;j++)
                if(dist2(x[i],y[i],x[j],y[j])<=400) M[i][j]=M[j][i]=true;
                else M[i][j]=M[j][i]=false;
        }
        
        f[0]=1; ans=N;
        search(0,1);
        
        printf("The towers in case %d can be covered in %d frequencies.\n",tc++,ans);
    }
    
    return 0;
}
