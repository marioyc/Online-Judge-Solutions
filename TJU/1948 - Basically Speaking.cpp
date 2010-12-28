#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    string num;
    int b1,b2;
    
    while(cin>>num>>b1>>b2){
        int N = 0,L = num.size();
        
        for(int i = 0;i<L;++i)
            N = N*b1+(num[i]>='A' && num[i]<='Z'? num[i]-'A'+10 : num[i]-'0');
        
        string ans;
        
        while(N!=0){
            int x = N%b2;
            N /= b2;
            
            ans += (char)(x>9? 'A'+x-10 : '0'+x);
        }
        
        reverse(ans.begin(),ans.end());
        
        if(ans.size()>7) cout<<setw(7)<<"ERROR"<<'\n';
        else cout<<setw(7)<<ans<<'\n';
    }
    
    return 0;
}
