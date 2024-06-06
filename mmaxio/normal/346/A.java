import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];

		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}

		int div = a[0];
		int maxNum = a[0];
		for (int i = 1; i < n; i++) {
			div = gcd(div, a[i]);
			maxNum = Math.max(maxNum, a[i]);
		}

		int max = maxNum / div;

		int k = max - n;
		out.println(k % 2 == 1 ? "Alice" : "Bob");
	}

	static int gcd(int x, int y) {
		return y == 0 ? x : gcd(y, x % y);
	}

	A() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new A();
	}

	String nextToken() {
		while (st == null || !st.hasMoreTokens()) {
			try {
				st = new StringTokenizer(br.readLine());
			} catch (Exception e) {
				eof = true;
				return null;
			}
		}
		return st.nextToken();
	}

	String nextString() {
		try {
			return br.readLine();
		} catch (IOException e) {
			eof = true;
			return null;
		}
	}

	int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}

	long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}

	double nextDouble() throws IOException {
		return Double.parseDouble(nextToken());
	}
}