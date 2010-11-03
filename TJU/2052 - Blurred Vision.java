import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main{
    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;
        String line;
        String M[] = new String[9];
        int R,C;

        while(true){
            line = in.readLine();

            if(line.charAt(0) == 'E') break;

            st = new StringTokenizer(line);
            st.nextToken();

            R = Integer.parseInt(st.nextToken());
            C = Integer.parseInt(st.nextToken());

            for(int i=0;i<R;i++) M[i]=in.readLine();

            for(int i=0;i<R-1;i++){
                for(int j=0;j<C-1;j++)
                    System.out.print((M[i].charAt(j)+M[i].charAt(j+1)+M[i+1].charAt(j)+M[i+1].charAt(j+1)-4*'0')/4);
                System.out.println();
            }

            in.readLine();
        }
    }
}
