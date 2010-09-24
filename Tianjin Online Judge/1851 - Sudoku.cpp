#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

int sum=0;
int sudoku[9][9];
bool solved;
bool f[9][10];
bool c[9][10];
bool cuadro[9][10];    

void solve(int x, int y)
{
    if(x==9 && y==0)
    {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                cout<<sudoku[i][j];
            }
            cout<<endl;
        }
        solved=true;
        return;
    }
    if(solved) return;
    if(sudoku[x][y]!=0)
    {
        solve(y==8? x+1:x, y==8? 0:y+1);
    }
    else
    {    
        for(int i=1;i<10;i++)
        {
            if(f[x][i] || c[y][i] || cuadro[(x/3)*3+y/3][i] || solved) continue;
            sudoku[x][y]=i;
            f[x][i]=true;
            c[y][i]=true;
            cuadro[(x/3)*3+y/3][i]=true;
            solve(y==8? x+1:x, y==8? 0:y+1);
            sudoku[x][y]=0;
            f[x][i]=false;
            c[y][i]=false;
            cuadro[(x/3)*3+y/3][i]=false;
        }
    }
    return;
}

int main(){
    
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    
    int n;
    cin>>n;
    string s;
    getline(cin,s);
    for(int i=0;i<n;i++)
    {
        memset(f,false,sizeof(f));
        memset(c,false,sizeof(c));
        memset(cuadro,false,sizeof(cuadro));
        for(int i=0;i<9;i++)
        {
            getline(cin,s);
            for(int j=0;j<9;j++)
            {
                sudoku[i][j]=s[j]-'0'; 
                if(sudoku[i][j]!=0)
                {
                    f[i][sudoku[i][j]]=true;
                    c[j][sudoku[i][j]]=true;
                    cuadro[(i/3)*3+j/3][sudoku[i][j]]=true;
                }
            }
        }
        
        solved=false;
        solve(0,0);
    }
    return 0;
}
