import java.io.*;
import java.util.*;

public class B {

	BufferedReader br;
	PrintWriter out;
	StringTokenizer st;
	boolean eof;
	
	static final String VOWELS = "aeioyu";

	void solve() throws IOException {
		int n = nextInt();
		int[] a = new int[n];
		
		for (int i = 0; i < n; i++) {
			a[i] = nextInt();
		}
		
		for (int i = 0; i < n; i++) {
			String s = nextString();
			for (int j = 0; j < s.length(); j++) {
				if (VOWELS.indexOf(s.charAt(j)) != -1) {
					a[i]--;
				}
			}
			if (a[i] != 0) {
				out.println("NO");
				return;
			}
		}
		out.println("YES");
	}

	B() throws IOException {
		br = new BufferedReader(new InputStreamReader(System.in));
		out = new PrintWriter(System.out);
		solve();
		out.close();
	}

	public static void main(String[] args) throws IOException {
		new B();
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