#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

int main(){
    int p[10];
    for(int i=0;i<10;i++) p[i]=i+1;
    bool M[11][11];
    
    int tc=1,n,v;
    string s;
    
    bool found;
    
    while(1){
        scanf("%d\n",&n);
        if(n==0) break;
        
        memset(M,false,sizeof(M));
        
        for(int i=1;i<=n;i++){
            getline(cin,s);
            istringstream is(s);
            while(is>>v) M[i][v]=M[v][i]=true;
        }
        
        do{
            found=true;
            
            if(!M[0][p[0]]) found=false;
            
            for(int i=1;i<n && found;i++)
                if(!M[p[i-1]][p[i]])
                    found=false;
            
            if(!found || !M[p[n-1]][0]) found=false;
        }while(!found && next_permutation(p,p+n));
        
        printf("Case %d: ",tc++);
        if(found) printf("Granny can make the circuit.\n");
        else printf("Granny can not make the circuit.\n");
    }
}
