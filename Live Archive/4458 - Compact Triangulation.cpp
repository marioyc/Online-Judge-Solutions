#include <cstdio>
#include <algorithm>

using namespace std;

struct point{
    int x,y;
    
    point(){
    }
    
    point(const int &_x, const int &_y){
        x=_x; y=_y;
    }
};

int signed_area(const point &p1, const point &p2, const point &p3){
    return (p1.x*p2.y+p2.x*p3.y+p3.x*p1.y-p1.y*p2.x-p2.y*p3.x-p3.y*p1.x);
}

point a[49];
int memo[49][49];

int Solve(int i, int j){
    if(j==i+1) return 0;
    if(memo[i][j]!=-1) return memo[i][j];
    
    int aux=INT_MAX;
    
    for(int k=i+1;k<j;k++)
        aux=min(aux,max(abs(signed_area(a[i],a[k],a[j])),max(Solve(i,k),Solve(k,j))));
    
    memo[i][j]=aux;
    return aux;
}

int main(){
    int T,N,x,y;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%d",&N);
        for(int i=0;i<N;i++){
            scanf("%d %d",&x,&y);
            a[i]=point(x,y);
        }
        
        for(int i=0;i<N;i++)
            for(int j=i+1;j<N;j++)
                memo[i][j]=-1;
        
        printf("%.1f\n",Solve(0,N-1)/2.0);
    }
    
    return 0;
}
