#include <iostream>
#include <string>

using namespace std;

int main(){
    string n,m;
    
    while(cin>>n>>m){
        if(n==m) printf("No\n");
        else printf("Yes\n");
    }
    
    return 0;
}
