#include <cstdio>
#include <cmath>

using namespace std;

struct point{
    double x,y;
    
    point(){
    }
};

double dist2(point &A, point &B){
    return (A.x-B.x)*(A.x-B.x)+(A.y-B.y)*(A.y-B.y);
}

double S;

double area2(point &A, point &B, point &C){
    S=A.x*B.y+B.x*C.y+C.x*A.y-A.y*B.x-B.y*C.x-C.y*A.x;
    return S*S;
}

int main(){
    int N,cont;
    char s[14950][5];
    point P[26];
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++) scanf("%lf %lf",&P[i].x,&P[i].y);
        
        cont=0;
        
        for(int a=0;a<N;a++){
            for(int b=a+1;b<N;b++){
                for(int c=b+1;c<N;c++){
                    for(int d=c+1;d<N;d++){
                        if(fabs(dist2(P[c],P[a])*dist2(P[c],P[b])*area2(P[a],P[b],P[d])-dist2(P[d],P[a])*dist2(P[d],P[b])*area2(P[a],P[b],P[c]))<1e-7){
                            s[cont][0]='A'+a;
                            s[cont][1]='A'+b;
                            s[cont][2]='A'+c;
                            s[cont][3]='A'+d;
                            s[cont][4]=0;
                            cont++;
                        }
                    }
                }
            }
        }
        
        printf("%d\n",cont);
        
        for(int i=0;i<cont;i++) printf("%s\n",s[i]);
    }
    
    return 0;
}
