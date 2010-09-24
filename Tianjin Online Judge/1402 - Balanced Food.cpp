#include<cstdio>
#include<cmath>

#define PI acos(-1)

using namespace std;

int n,cont;
bool solution_found;
double px,py,r,tx,ty,ux,uy,vx,vy;
bool cut[9];
int order[9];
double CMx,CMy,R2,a,b;
double x[9],y[9];

bool fall(){    
    //Hallar CMX y CMY
    cont=0;
    CMx=0;
    CMy=0;
    
    for(int i=0;i<n;i++){
        if(!cut[i]){
            cont++;            
            CMx+=x[i];
            CMy+=y[i];
        }
    }
    
    CMx=CMx/cont+px;
    CMy=CMy/cont+py;
    
    //verificar que el CM esté sobre la mesa
    
    if(pow(CMx-tx,2.0)+pow(CMy-ty,2.0)>R2) return true;
    
    a=((CMx-tx)*(vy-ty)-(CMy-ty)*(vx-tx))/((ux-tx)*(vy-ty)-(uy-ty)*(vx-tx));
    if(a<0) return true;
    
    b=((CMy-ty)*(ux-tx)-(CMx-tx)*(uy-ty))/((ux-tx)*(vy-ty)-(uy-ty)*(vx-tx));
    if(b<0) return true;
    
    return false;
}

void backtracking(int a){
    if(a==n){
        solution_found=true;
        
        for(int i=0;i<n;i++){
            printf("%d",order[i]);
            if(i!=n-1) printf(" ");
            else printf("\n");
        }
        
        return;
    }
    
    if(solution_found) return;
    
    if(fall()) return;
    
    for(int i=0;i<n && !solution_found;i++){
        if(!cut[i]){
            cut[i]=true;
            
            order[a]=i+1;
            backtracking(a+1);
            
            cut[i]=false;
        }
    }
}

int main(){
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    while(1){
        scanf("%d",&n);
        if(n==0) break;
        
        scanf(" (%lf,%lf) %lf (%lf,%lf) (%lf,%lf) (%lf,%lf)",&px,&py,&r,&tx,&ty,&ux,&uy,&vx,&vy);
        
        R2=pow(ux-tx,2.0)+pow(uy-ty,2.0);
        
        for(int i=0;i<n;i++) cut[i]=false;
        
        for(int i=0;i<n;i++){
            x[i]=2*r/3*(sin(2*PI/n*(i+1))-sin(2*PI/n*i))/(2*PI/n);
            y[i]=2*r/3*(cos(2*PI/n*i)-cos(2*PI/n*(i+1)))/(2*PI/n);
        }
        
        solution_found=false;
        
        backtracking(0);
        
        if(!solution_found) printf("impossible\n");
    }
    
    return 0;
}
