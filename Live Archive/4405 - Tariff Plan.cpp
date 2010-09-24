#include <cstdio>

using namespace std;

int main(){
    int T,N,t[19],s1,s2;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        printf("Case %d: ",tc);
        
        scanf("%d",&N);
        for(int i=0;i<N;i++) scanf("%d",&t[i]);
        
        s1=s2=0;
        for(int i=0;i<N;i++){
            s1+=t[i]/30+1;
            s2+=t[i]/60+1;
        }
        
        s1*=10; s2*=15;
        
        if(s1<s2) printf("Mile %d\n",s1);
        else if(s1>s2) printf("Juice %d\n",s2);
        else if(s1==s2) printf("Mile Juice %d\n",s1);
    }
    
    return 0;
}
