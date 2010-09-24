#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;

int main(){
    char A[90];
    
    while(true){
        scanf("%s",A);
        if(A[0]=='#') break;
        
        int L = strlen(A),cont = 0;
        
        for(int i=0;i<L;++i){
            if(A[i]=='.') cont += 2;
            else if(A[i]=='/'){
                int pos = i-1;
                bool falls = false;
                
                while(true){
                    if(pos==-1 || A[pos]=='.'){
                        falls = true;
                        break;
                    }
                    
                    if(A[pos]=='|' || A[pos]=='\\') break;
                    
                    --pos;
                }
                
                if(falls) cont += 2;
            }else if(A[i]=='\\'){
                int pos = i+1;
                bool falls = false;
                
                while(true){
                    if(pos==L || A[pos]=='.'){
                        falls = true;
                        break;
                    }
                    
                    if(A[pos]=='|' || A[pos]=='/') break;
                    
                    ++pos;
                }
                
                if(falls) cont += 2;
            }else if(A[i]=='|'){
                int pos = i-1;
                bool falls = false;
                
                while(true){
                    if(pos==-1 || A[pos]=='.'){
                        falls = true;
                        break;
                    }
                    
                    if(A[pos]=='|' || A[pos]=='\\') break;
                    
                    --pos;
                }
                
                if(falls) ++cont;
                falls = false;
                pos = i+1;
                
                while(true){
                    if(pos==L || A[pos]=='.'){
                        falls = true;
                        break;
                    }
                    
                    if(A[pos]=='|' || A[pos]=='/') break;
                    
                    ++pos;
                }
                
                if(falls) ++cont;
            }
        }
        
        printf("%.0lf\n",floor(cont*50.0/L));
    }
    
    return 0;
}
