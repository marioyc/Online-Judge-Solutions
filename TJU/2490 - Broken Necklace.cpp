#include <cstdio>
#include <algorithm>

using namespace std;

int main(){
    int N;
    scanf("%d",&N);
    
    char s[N+1];
    scanf("%s",s);
    
    bool all=true;
    
    for(int i=0;i<N;i++) if(s[i]!='w') all=false;
    
    if(all){
        printf("%d\n",N);
        return 0;
    }
    
    all=true;
    
    int ind;
    
    for(int i=0;;i++)
        if(s[i]!='w'){
            ind=i;
            break;
        }
    
    for(int i=0;i<N;i++)
        if(s[i]!=s[ind] || s[i]=='w') all=false;
        
    if(all){
        printf("%d\n",N);
        return 0;
    }
    
    int cont1,cont2,ans=0,limit;
    char c;
    bool used[N];
    
    for(int i=0;i<N;i++){
        fill(used,used+N,false);
        
        cont1=0;
        
        for(int j=i;;j++){
            if(j==N) j=0;
            if(s[j]!='w'){
                c=s[j];
                break;
            }
        }
        
        for(int j=i;;j++){
            if(j==N) j=0;
            if(s[j]==c || s[j]=='w'){
                cont1++;
                used[j]=true;
            }else break;
        }
        
        cont2=0;
        
        for(int j=i-1;;j--){
            if(j==-1) j=N-1;
            if(s[j]!='w'){
                c=s[j];
                break;
            }
        }
        
        for(int j=i-1;;j--){
            if(j==-1) j=N-1;
            if(used[j]) break;
            if(s[j]==c || s[j]=='w') cont2++;
            else break;
        }
        
        if(ans<cont1+cont2) ans=cont1+cont2;
    }
    
    printf("%d\n",ans);
    
    return 0;
}
