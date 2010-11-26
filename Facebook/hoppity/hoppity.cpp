#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char *argv[]){
    ifstream input(argv[1]);
    
    int n;
    input>>n;
    
    for(int i = 1;i<=n;++i){
        if(i%15==0) printf("Hop\n");
        else if(i%3==0) printf("Hoppity\n");
        else if(i%5==0) printf("Hophop\n");
    }
    
    return 0;
}
