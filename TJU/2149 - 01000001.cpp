#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int T;
    cin>>T;
    
    string A,B;
    
    for(int tc = 1;tc<=T;++tc){
        cin>>A>>B;
        reverse(A.begin(),A.end());
        reverse(B.begin(),B.end());
        
        int L1 = A.size(),L2 = B.size();
        
        if(L1>L2) B += string(L1-L2,'0');
        if(L1<L2) A += string(L2-L1,'0');
        L1 = max(L1,L2);
        
        string ans;
        int c = 0;
        
        for(int i = 0;i<L1;++i){
            c += A[i]-'0'+B[i]-'0';
            ans += (char)('0'+c%2);
            c /= 2;
        }
        
        if(c==1){
            ans += '1';
            ++L1;
        }
        
        reverse(ans.begin(),ans.end());
        
        int s = 0;
        while(s+1<L1 && ans[s]=='0') ++s;
        
        cout<<tc<<" "<<ans.substr(s,L1-s)<<endl;
    }
    
    return 0;
}
