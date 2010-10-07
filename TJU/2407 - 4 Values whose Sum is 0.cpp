#include <cstdio>
#include <algorithm>

using namespace std;

#define MAX_SZ 16000000

int A[MAX_SZ],szA,contA[MAX_SZ];
int B[MAX_SZ],szB,contB[MAX_SZ];

int main(){
    int N;
    scanf("%d",&N);
    
    int S1[N],S2[N],S3[N],S4[N];
    
    for(int i = 0;i<N;++i)
        scanf("%d %d %d %d",&S1[i],&S2[i],&S3[i],&S4[i]);
    
    int m = 0;
    
    for(int i = 0;i<N;++i)
        for(int j = 0;j<N;++j,++m)
            A[m] = S1[i]+S2[j];
    
    m = 0;
    
    for(int i = 0;i<N;++i)
        for(int j = 0;j<N;++j,++m)
            B[m] = -S3[i]-S4[j];
    
    sort(A,A+m);
    sort(B,B+m);
    
    szA = 0;
    contA[0] = 1;
    
    for(int i = 1;i<m;++i){
        if(A[i]!=A[i-1]){
            ++szA;
            A[szA] = A[i];
            contA[szA] = 1;
        }else{
            ++contA[szA];
        }
    }
    
    ++szA;
    
    szB = 0;
    contB[0] = 1;
    
    for(int i = 1;i<m;++i){
        if(B[i]!=B[i-1]){
            ++szB;
            B[szB] = B[i];
            contB[szB] = 1;
        }else{
            ++contB[szB];
        }
    }
    
    ++szB;
    
    long long ans = 0;
    
    for(int i = 0,j = 0;i<szA && j<szB;){
        if(A[i]<B[j]) ++i;
        else if(A[i]>B[j]) ++j;
        else{
            ans += (long long)contA[i]*contB[j];
            ++i; ++j;
        }
    }
    
    printf("%lld\n",ans);
    
    return 0;
}
