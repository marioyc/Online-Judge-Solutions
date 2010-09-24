/*
ID:zion_ba1
LANG:C++
TASK:crypt1
*/

#include <cstdio>
#include <algorithm>

using namespace std;

bool valid[10];

bool check(int n){
    while(n!=0){
        if(!valid[n%10]) return false;
        n/=10;
    }
    
    return true;
}

int main(){
    freopen("crypt1.in","r",stdin);
    freopen("crypt1.out","w",stdout);
    
    int N;
    scanf("%d",&N);
    fill(valid,valid+10,false);
    
    int d;
    for(int i=0;i<N;i++){
        scanf("%d",&d);
        valid[d]=true;
    }
    
    int cont=0,A,B,C,D;
    
    for(int i=1;i<10;i++){
        if(!valid[i]) continue;
        for(int j=0;j<10;j++){
            if(!valid[j]) continue;
            for(int k=0;k<10;k++){
                if(!valid[k]) continue;
                for(int a=1;a<10;a++){
                    if(!valid[a]) continue;
                    for(int b=1;b<10;b++){
                        if(!valid[b]) continue;
                        A=100*i+10*j+k;
                        B=A*a;
                        C=A*b;
                        D=10*C+B;
                        if(B<1000 && check(B) && C<1000 && check(C) && check(D)) cont++;
                    }
                }
            }
        }
    }
    
    printf("%d\n",cont);
    
    return 0;
}
