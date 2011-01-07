#include <cstdio>

using namespace std;

struct point{
    int px,py;
    
    point(){}
}P[500];

int dist(point a, point b){
    return (a.px-b.px)*(a.px-b.px)+(a.py-b.py)*(a.py-b.py);
}

int main(){
    int N;
    scanf("%d",&N);
    
    for(int i = 0;i<N;++i)
        scanf("%d %d",&P[i].px,&P[i].py);
    
    int best = dist(P[0],P[1]),id1 = 0,id2 = 1;
    
    for(int i = 0;i<N;++i) for(int j = i+1;j<N;++j){
        int aux = dist(P[i],P[j]);
        
        if(aux>best){
            best = aux;
            id1 = i;
            id2 = j;
        }
    }
    
    printf("%d %d\n",id1+1,id2+1);
    
    return 0;
}
