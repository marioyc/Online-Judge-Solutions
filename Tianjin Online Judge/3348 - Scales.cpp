#include <cstdio>
#include <vector>

using namespace std;

int main(){
    int m,N1=0,N2=0;
    long long pot=1;
    vector<int> a,b;
    
    scanf("%d",&m);
    
    while(m!=0){
        if(m%3==1){
            N2++;
            m/=3;
            b.push_back(pot);
        }else if(m%3==2){
            N1++;
            m/=3;
            m++;
            a.push_back(pot);
        }else m/=3;
        pot*=3;
    }
    
    printf("%d",N1); for(int i=0;i<N1;i++) printf(" %d",a[i]); printf("\n");
    printf("%d",N2); for(int i=0;i<N2;i++) printf(" %d",b[i]); printf("\n");
    
    return 0;
}
