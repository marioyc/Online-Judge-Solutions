#include<cstdio>

using namespace std;

int pot3[12];

void print(int n){
    if(n==0){
        printf("-");
        return;
    }
    
    print(n-1);
    for(int i=0;i<pot3[n-1];i++) printf(" ");
    print(n-1);
}

int main(){
    pot3[0]=1;
    for(int i=1;i<12;i++) pot3[i]=3*pot3[i-1];
    
    int n;
    
    while(scanf("%d",&n)==1){
        print(n);
        printf("\n");
    }
    
    return 0;
}
