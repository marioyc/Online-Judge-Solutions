#include <iostream>
#include <string>

using namespace std;

int main(){
    int group[26],times[26];
    
    group[0] = group[1] = group[2] = 0;
    group[3] = group[4] = group[5] = 1;
    group[6] = group[7] = group[8] = 2;
    group[9] = group[10] = group[11] = 3;
    group[12] = group[13] = group[14] = 4;
    group[15] = group[16] = group[17] = group[18] = 5;
    group[19] = group[20] = group[21] = 6;
    group[22] = group[23] = group[24] = group[25] = 7;
    
    times[0] = 1; times[1] = 2; times[2] = 3;
    times[3] = 1; times[4] = 2; times[5] = 3;
    times[6] = 1; times[7] = 2; times[8] = 3;
    times[9] = 1; times[10] = 2; times[11] = 3;
    times[12] = 1; times[13] = 2; times[14] = 3;
    times[15] = 1; times[16] = 2; times[17] = 3; times[18] = 4;
    times[19] = 1; times[20] = 2; times[21] = 3;
    times[22] = 1; times[23] = 2; times[24] = 3; times[25] = 4;
    
    int T,p,w;
    string s;
    
    cin>>T;
    
    while(T--){
        cin>>p>>w;
        
        getline(cin,s);
        getline(cin,s);
        
        int ans = 0,L = s.size();
        
        for(int i = 0,prev = -1;i<L;++i){
            if(s[i]==' '){
                ans += p;
                prev = -1;
            }else if(prev==-1 || group[prev]!=group[s[i]-'A']){
                ans += p*times[s[i]-'A'];
                prev = s[i]-'A';
            }else{
                ans += p*times[s[i]-'A']+w;
                prev = s[i]-'A';
            }
        }
        
        cout<<ans<<endl;
    }
    
    return 0;
}
