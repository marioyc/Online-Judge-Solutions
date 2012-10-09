#include <cstdio>
#include <algorithm>

using namespace std;

char name[30000][11];
int a[30000],b[30000];

int main(){
    int n;
    int a[30000];
    
    while(true){
        scanf("%d",&n);
        if(n == -1) break;
        
        for(int i = 0,x,y,z;i < n;++i){
            scanf("%s %d %d %d",name[i],&x,&y,&z);
            a[i] = 5 * x + 10 * y + 20 * z;
            b[i] = a[i];
        }
        
        sort(b,b + n);
        
        if(b[0] == b[n - 1]) puts("All have the same amount.");
        else{
            int mn = b[0],mx = b[n - 1];
            
            for(int i = 0;i < n;++i){
                if(a[i] == mx){
                    printf("%s has most, ",name[i]);
                    break;
                }
            }
            
            for(int i = 0;i < n;++i){
                if(a[i] == mn){
                    printf("%s has least money.\n",name[i]);
                    break;
                }
            }
        }
    }
    
    return 0;
}
