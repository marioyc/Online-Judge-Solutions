#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
    int N;
    string s[1000];
    
    cin >> N;
    getline(cin,s[0]);
    
    for(int i = 0;i < N;++i)
        getline(cin,s[i]);
    
    sort(s,s + N);
    
    int ans = 0;
    
    for(int i = 0,j;i < N;i = j){
        j = i;
        
        while(j < N && s[j] == s[i]) ++j;
        
        ans += j-i-1;
    }
    
    cout << ans << endl;
    
    return 0;
}
