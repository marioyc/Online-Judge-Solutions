#include <iostream>
#include <string>

using namespace std;

int main(){
    ios::sync_with_stdio(0);
    
    int T,N;
    string line;
    string s[40];
    
    cin >> T;
    
    while(T--){
        cin >> N;
        getline(cin,line);
        
        for(int i = 0;i < N;++i)
            getline(cin,s[i]);
        
        for(int i = N - 1;i >= 0;--i){
            string aux;
            
            if(s[i][0] == 'B') aux = s[i].substr(5,s[i].size() - 5);
            else if(s[i][0] == 'R') aux = s[i].substr(5,s[i].size() - 5);
            else aux = s[i].substr(4,s[i].size() - 4);
            
            if(i == N - 1) cout << "Begin";
            else if(s[i + 1][0] == 'R') cout << "Left";
            else cout << "Right";
            
            cout << aux << '\n';
        }
        
        cout << '\n';
    }
    
    return 0;
}
