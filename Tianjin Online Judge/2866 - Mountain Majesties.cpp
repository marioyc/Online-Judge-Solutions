#include<cstdio>
#include<vector>
#include<algorithm>

using namespace std;

struct triangle{
    int x1,x2;
    
    triangle(){
    }
    
    triangle(int _x1, int _x2){
        x1=_x1;
        x2=_x2;
    }
    
    bool operator < (triangle X)const{
        if(x1!=X.x1) return x1<X.x1;
        return x2-x1<X.x2-X.x1;
    }
};

int main(){    
    int N,a,b,total,x;
    
    vector<triangle> T;
    
    scanf("%d",&N);
    
    for(int i=0;i<N;i++){
        scanf("%d %d",&a,&b);
        T.push_back(triangle(min(a,b),max(a,b)));
    }
    
    sort(T.begin(),T.end());
    
    total=(T[0].x2-T[0].x1)*(T[0].x2-T[0].x1);
    x=T[0].x2;
    
    for(int i=1;i<N;i++){
        if(T[i].x2<=x) continue;
        else if(x<=T[i].x1){
            total+=(T[i].x2-T[i].x1)*(T[i].x2-T[i].x1);
            x=T[i].x2;
        }else{
            total+=(T[i].x2-T[i].x1)*(T[i].x2-T[i].x1)-(x-T[i].x1)*(x-T[i].x1);
            x=T[i].x2;
        }
    }
    
    printf("%d\n",total);
    
    return 0;
}
