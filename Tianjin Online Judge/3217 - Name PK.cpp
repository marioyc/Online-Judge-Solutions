#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int main(){
    int T,n,m;
    char s1[21],s2[21];
    int x,y,z,HP1,STR1,SPD1,HP2,STR2,SPD2,t1,t2,t;
    
    scanf("%d",&T);
    
    for(int tc=1;tc<=T;tc++){
        scanf("%s %s",s1,s2);
        
        n=strlen(s1);
        
        x=0;
        for(int i=0;i<n;i++) x=(x+(83-s1[i])*(83-s1[i]))%97;
        HP1=300-x;
        
        y=1;
        for(int i=0;i<n;i++) y=(y*s1[i])%79;
        STR1=22+y;
        
        z=0;
        for(int i=0;i<n;i++)
            for(int j=i+1;j<n;j++)
                z=(z+s1[i]*s1[j])%11;
        SPD1=z;
        
        m=strlen(s2);
        
        x=0;
        for(int i=0;i<m;i++) x=(x+(83-s2[i])*(83-s2[i]))%97;
        HP2=300-x;
        
        y=1;
        for(int i=0;i<m;i++) y=(y*s2[i])%79;
        STR2=22+y;
        
        z=0;
        for(int i=0;i<m;i++)
            for(int j=i+1;j<m;j++)
                z=(z+s2[i]*s2[j])%11;
        SPD2=z;
        
        t1=20-SPD1;
        t2=20-SPD2;
        
        while(1){
            t=min(t1,t2);
            
            if(t1==t){
                HP2-=STR1;
                t1+=20-SPD1;
            }
            
            if(t2==t){
                HP1-=STR2;
                t2+=20-SPD2;
            }
            
            if(HP1<=0 && HP2<=0){
                printf("tie\n");
                break;
            }else if(HP1<=0){
                printf("lose\n");
                break;
            }else if(HP2<=0){
                printf("win\n");
                break;
            }
        }
    }
    
    return 0;
}
