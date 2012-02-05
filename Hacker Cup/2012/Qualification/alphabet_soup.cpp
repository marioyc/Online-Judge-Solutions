#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(){
    int T;
    string line;
    
    cin >> T;
    getline(cin,line);
    
    char c[] = {'H','A','C','K','E','R','U','P'};
    int cont[] = {1,1,2,1,1,1,1,1};
    
    for(int tc = 1;tc <= T;++tc){
        getline(cin,line);
        
        int ans = 100000;
        
        for(int i = 0;i < 8;++i)
            ans = min(ans,count(line.begin(),line.end(),c[i]) / cont[i]);
        
        cout << "Case #" << tc << ": " << ans << '\n';
    }
    
    return 0;
}
