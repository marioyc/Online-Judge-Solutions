#include <cstdio>

using namespace std;

int main(){
    char name1[21],name2[21],call[5];
    int N;
    
    while(true){
        scanf("%s %s %s",name1,name2,call);
        if(name1[0]=='#') break;
        
        scanf("%d",&N);
        
        int p1 = 0,p2 = 0;
        
        if(call[0]=='o'){
            for(int i = 0,x;i<N;++i){
                scanf("%d",&x);
                if(x & 1) ++p2;
                else ++p1;
            }
        }else{
            for(int i = 0,x;i<N;++i){
                scanf("%d",&x);
                if(x & 1) ++p1;
                else ++p2;
            }
        }
        
        printf("%s %d %s %d\n",name1,p1,name2,p2);
    }
    
    return 0;
}
