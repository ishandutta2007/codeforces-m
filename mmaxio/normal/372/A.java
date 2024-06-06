import java.io.*;
import java.util.*;

public class A {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;

	static final Random rng = new Random();

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];

		for (int i = 0; i < n; i++) {
			int x = nextInt();
			int j = rng.nextInt(i + 1);
			a[i] = a[j];
			a[j] = x;
		}

		Arrays.sort(a);

		int[] can = new int[n];
		for (int i = 0, j = 0; i < n; i++) {
			while (j < n && a[i] * 2 > a[j]) {
				j++;
			}
			can[i] = n - j;
		}

		int ans = n / 2;
		for (int i = 0; i < n / 2; i++) {
			ans = Math.min(ans, can[i] + i);
		}

		out.println(n - ans);
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