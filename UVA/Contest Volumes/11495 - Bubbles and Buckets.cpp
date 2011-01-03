#include <cstdio>
#include <algorithm>

using namespace std;

int A[100000],C[100000],pos1,pos2,sz;

int count(int a, int b){
    if(a==b) return 0;
    
    int c=((a+b)>>1),aux=count(a,c)+count(c+1,b);
    
    pos1=a; pos2=c+1; sz=0;
    
    while(pos1<=c && pos2<=b){
        if(A[pos1]<A[pos2]) C[sz]=A[pos1++];
        else{
            C[sz]=A[pos2++];
            aux+=c-pos1+1;
        }
        
        sz++;
    }
    
    if(pos1>c) memcpy(C+sz,A+pos2,(b-pos2+1)*sizeof(int));
    if(pos2>b) memcpy(C+sz,A+pos1,(c-pos1+1)*sizeof(int));
    
    sz=b-a+1;
    
    memcpy(A+a,C,sz*sizeof(int));
    
    return aux;
}

int main(){
    int N,inversions;
    
    while(1){
        scanf("%d",&N);
        if(N==0) break;
        
        for(int i=0;i<N;i++) scanf("%d",&A[i]);
        inversions=count(0,N-1);
        
        if(inversions & 1) printf("Marcelo\n");
        else printf("Carlos\n");
    }
    
    return 0;
}
