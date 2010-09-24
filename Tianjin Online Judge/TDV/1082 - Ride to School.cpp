#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

struct biker{
    int v, t;
    
    biker(){
    }
    
    biker(int a,int b){
        v=a;
        t=b;
    }
    
    bool operator < (biker X) const{
        if(v!=X.v) return v<X.v;
        return t<X.t;
    }
};

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int N,v;
    double x,T,T_aux;
    biker a[10000];
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++)scanf("%d\t%d",&a[i].v,&a[i].t);
        
        sort(a,a+N);
        
        for(int i=0;i<N;i++) printf("%d %d\n",a[i].v,a[i].t);
        
        x=0;
        v=0;
        T=0;
        
        printf("int:\n");
        
        for(int i=0;i<N;i++){
            T_aux=(x-a[i].v*(T-a[i].t)/3600.0)/(a[i].v-v);//tiempo de encuentro en horas
            if(T_aux>=0 && x+v*T_aux<=4.5){
                printf(" (%d %.6f)",i,T_aux);
                printf(" %d %.4f %d",a[i].v,(T-a[i].t),a[i].v-v);
                T+=T_aux*3600.0;
                x=x+v*T_aux;
                v=a[i].v;
                printf(" (%.6f %d)\n",x,v);
            }
        }
        printf("\n");
        printf("x , v : %.4f %d\n",x,v);
        
        T+=(4.5-x)*3600.0/v;
        
        printf("%.0f\n",ceil(T));
    }
    
    return 0;
}
