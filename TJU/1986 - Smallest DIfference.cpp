#include <iostream>
#include <sstream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int T,N,d[10];
    cin>>T;
    
    string line;
    getline(cin,line);
    
    while(T--){
        getline(cin,line);
        
        istringstream is(line);
        
        N = 0;
        while(is>>d[N]) ++N;
        
        if(N==2){
            cout<<abs(d[0]-d[1])<<endl;
        }else{
            sort(d,d+N);
            
            int m = N/2,ans = (1<<30),num1,num2;
            
            do{
                num1 = num2 = 0;
                
                for(int i = 0;i<m;++i) num1 = num1*10+d[i];
                for(int i = m;i<N;++i) num2 = num2*10+d[i];
                
                if(d[0]!=0 && d[m]!=0)
                    ans = min(ans,abs(num1-num2));
            }while(next_permutation(d,d+N));
            
            cout<<ans<<endl;
        }
    }
    
    return 0;
}
