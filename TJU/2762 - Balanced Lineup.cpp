#include <cstdio>
#include <algorithm>

using namespace std;

int h[50000],T1[(1<<17)+1],T2[(1<<17)+1];

void initialize_T1(int a, int b, int num){
    if(a==b) T1[num]=h[a];
    else{
        initialize_T1(a,(a+b)>>1,2*num+1);
        initialize_T1(((a+b)>>1)+1,b,2*num+2);
        T1[num]=min(T1[2*num+1],T1[2*num+2]);
    }
}

void initialize_T2(int a, int b, int num){
    if(a==b) T2[num]=h[a];
    else{
        initialize_T2(a,(a+b)>>1,2*num+1);
        initialize_T2(((a+b)>>1)+1,b,2*num+2);
        T2[num]=max(T2[2*num+1],T2[2*num+2]);
    }
}

int x,y;

int search_T1(int a, int b, int num){
    if(x>b || y<a) return -1;
    else if(x<=a && b<=y) return T1[num];
    else{
        int h1=search_T1(a,(a+b)>>1,2*num+1);
        int h2=search_T1(((a+b)>>1)+1,b,2*num+2);
        if(h1==-1) return h2;
        if(h2==-1) return h1;
        return min(h1,h2);
    }
}

int search_T2(int a, int b, int num){
    if(x>b || y<a) return -1;
    else if(x<=a && b<=y) return T2[num];
    else{
        int h1=search_T2(a,(a+b)>>1,2*num+1);
        int h2=search_T2(((a+b)>>1)+1,b,2*num+2);
        if(h1==-1) return h2;
        if(h2==-1) return h1;
        return max(h1,h2);
    }
}

int main(){
    int N,Q;
    scanf("%d %d",&N,&Q);
    
    for(int i=0;i<N;i++) scanf("%d",&h[i]);
    
    initialize_T1(0,N-1,0);
    initialize_T2(0,N-1,0);
    
    for(int i=0;i<Q;i++){
        scanf("%d %d",&x,&y);
        x--; y--;
        printf("%d\n",search_T2(0,N-1,0)-search_T1(0,N-1,0));
    }
    
    return 0;
}
