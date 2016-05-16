#include <cstdio>

using namespace std;

int main(){
    printf("1\n3 1 1 2\n3 3 3 4\n");
    fflush(stdout);

    int diff;
    scanf("%d",&diff);

    if(diff == 0){
        printf("2\n5\n");
    }else if(diff == 2){
        printf("2\n1\n");
    }else if(diff == 1){
        printf("2\n2\n");
    }else if(diff == -2){
        printf("2\n3\n");
    }else if(diff == -1){
        printf("2\n4\n");
    }

    fflush(stdout);

    return 0;
}
