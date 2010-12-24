#include <iostream>
#include <sstream>
#include <string>

using namespace std;

int main(){
    int T;
    string s;
    
    int num[12];
    char sign[11];
    
    cin>>T;
    
    while(T--){
        cin>>s;
        istringstream is(s);
        
        is>>num[0];
        int n = 1;
        
        while(is>>sign[n-1]){
            is>>num[n];
            ++n;
        }
        
        long long ans1 = 1,tmp = 0;
        
        for(int i = 0;i<n;++i){
            tmp += num[i];
            
            if(i==n-1 || sign[i]=='*'){
                ans1 *= tmp;
                tmp = 0;
            }
        }
        
        long long ans2 = 0;
        tmp = 1;
        
        for(int i = 0;i<n;++i){
            tmp *= num[i];
            
            if(i==n-1 || sign[i]=='+'){
                ans2 += tmp;
                tmp = 1;
            }
        }
        
        cout<<"The maximum and minimum are "<<ans1<<" and "<<ans2<<".\n";
    }
    
    return 0;
}
