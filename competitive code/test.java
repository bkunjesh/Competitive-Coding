/**
	@author ikung
*/

// import java.io.BufferedReader;
// import java.io.IOException;
// import java.io.InputStreamReader;
// import java.io.PrintWriter;
// import java.util.StringTokenizer;
import java.io.*;
import java.util.*;

public class test {

	public static long n;


	public static void solve() {
		long i,j,k;
		


	}

	public static void main(String[] args) {
		long t = 1;
		t = fs.nextLong();
		// out.println(t);
		while (t-- > 0) {
			solve();
		}
		out.close();
	}

	public static FastScanner fs = new FastScanner();
	public static PrintWriter out = new PrintWriter(System.out);
	public static long mod=1000000007;
	public static long N=1000006;

	static class FastScanner {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		String next() {

			while (!st.hasMoreTokens())
				try {
					st = new StringTokenizer(br.readLine());
					// return br.readLine();
				} catch (IOException e) {
					e.printStackTrace();
				}
			return st.nextToken();
		}
		int nextInt() {
			return Integer.parseInt(next());
		}

		int[] readArray(int n) {
			int[] a = new int[n];
			for (int i = 0; i < n; i++)
				a[i] = nextInt();
				return a;
		}

		long nextLong() {
			return Long.parseLong(next());
		}
	}
}