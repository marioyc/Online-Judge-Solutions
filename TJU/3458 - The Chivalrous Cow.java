import java.util.Scanner;
import java.util.StringTokenizer;
import java.util.Queue;
import java.util.LinkedList;

class node{
    int r,c,cont;

    node(int _r, int _c, int _cont){
        r=_r;
        c=_c;
        cont=_cont;
    }
}

public class Main{
    public static void main(String args[]){
        Scanner in = new Scanner(System.in);
        String line;

        StringTokenizer st = new StringTokenizer(in.nextLine());

        int C = Integer.parseInt(st.nextToken());
        int R = Integer.parseInt(st.nextToken());

        String map[] = new String[R];
        
        for(int i=0;i<R;i++) map[i] = in.nextLine();

        boolean visited[][] = new boolean[R][C];

        int rs=-1,cs=-1,re=-1,ce=-1;

        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                if(map[i].charAt(j)=='K'){
                    rs = i;
                    cs = j;
                }else if(map[i].charAt(j)=='H'){
                    re=i;
                    ce=j;
                }else if(map[i].charAt(j)!='.') visited[i][j] = true;
                else visited[i][j]=false;
            }
        }


        Queue<node> Q = new LinkedList<node>();
        Q.clear();
        Q.add(new node(rs,cs,0));
        visited[rs][cs]=true;

        node aux;
        int dr[] = {-1,-1,1,1,-2,-2,2,2};
        int dc[] = {-2,2,-2,2,-1,1,-1,1};
        int r,c;

        while(true){
            aux = Q.poll();

            if(aux.r==re && aux.c==ce){
                System.out.println(aux.cont);
                break;
            }

            for(int i=0;i<8;i++){
                r = aux.r+dr[i];
                c = aux.c+dc[i];

                if(r>=0 && r<R && c>=0 && c<C && !visited[r][c]){
                    visited[r][c]=true;
                    Q.add(new node(r,c,aux.cont+1));
                }
            }
        }
    }
}
