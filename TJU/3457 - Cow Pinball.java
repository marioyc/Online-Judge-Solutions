import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.StringTokenizer;

public class Main{
    public static void main(String args[]) throws IOException{
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st;

        int R = Integer.parseInt(in.readLine());
        int N = R*(R+1)/2;

        int L[] = new int [N];
        int dp[] = new int[N];

        for(int i=0,k=0;i<R;i++){
            st = new StringTokenizer(in.readLine());
            for(int j=0;j<=i;j++) L[k++] = Integer.parseInt(st.nextToken());
        }

        for(int i=(R-1)*R/2;i<N;i++) dp[i] = L[i];

        for(int i=R-2;i>=0;i--){
            int n1 = i*(i+1)/2;
            int n2 = (i+1)*(i+2)/2;

            for(int j=0;j<=i;j++) dp[n1+j] = L[n1+j]+Math.max(dp[n2+j],dp[n2+j+1]);
        }

        System.out.println(dp[0]);
    }
}
