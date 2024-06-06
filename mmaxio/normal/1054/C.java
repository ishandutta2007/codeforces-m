import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class C {

	void submit() {
		int n = nextInt();
		int[] l = new int[n];
		int[] r = new int[n];
		
		for (int i = 0; i < n; i++) {
			l[i] = nextInt();
		}
		for (int i = 0; i < n; i++) {
			r[i] = nextInt();
		}
		
		int[] ans = new int[n];
		Arrays.fill(ans, -1);
		int alive = n;
		
		while (alive > 0) {
			ArrayList<Integer> now = new ArrayList<>();
			for (int i = 0; i < n; i++) {
				if (ans[i] == -1 && l[i] == 0 && r[i] == 0) {
					now.add(i);
				}
			}
			if (now.isEmpty()) {
				out.println("NO");
				return;
			}
			for (int x : now) {
				ans[x] = alive;
			}
			alive -= now.size();
			for (int i = 0; i < n; i++) {
				if (ans[i] != -1) {
					continue;
				}
				for (int j : now) {
					if (j < i) {
						l[i]--;
					} else {
						r[i]--;
					}
				}
				if (l[i] < 0 || r[i] < 0) {
					out.println("NO");
					return;
				}
			}
		}
		
		
		out.println("YES");
		for (int x : ans) {
			out.print(x + " ");
		}
		out.println();
	}

	void test() {

	}

	void stress() {
		for (int tst = 0;; tst++) {
			if (false) {
				throw new AssertionError();
			}
			System.err.println(tst);
		}
	}

	C() throws IOException {
		is = System.in;
		out = new PrintWriter(System.out);
		submit();
		// stress();
		// test();
		out.close();
	}

	static final Random rng = new Random();
	static final int C = 5;

	static int rand(int l, int r) {
		return l + rng.nextInt(r - l + 1);
	}

	public static void main(String[] args) throws IOException {
		new C();
	}

	private InputStream is;
	PrintWriter out;

	private byte[] buf = new byte[1 << 14];
	private int bufSz = 0, bufPtr = 0;

	private int readByte() {
		if (bufSz == -1)
			throw new RuntimeException("Reading past EOF");
		if (bufPtr >= bufSz) {
			bufPtr = 0;
			try {
				bufSz = is.read(buf);
			} catch (IOException e) {
				throw new RuntimeException(e);
			}
			if (bufSz <= 0)
				return -1;
		}
		return buf[bufPtr++];
	}

	private boolean isTrash(int c) {
		return c < 33 || c > 126;
	}

	private int skip() {
		int b;
		while ((b = readByte()) != -1 && isTrash(b))
			;
		return b;
	}

	String nextToken() {
		int b = skip();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b)) {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	String nextString() {
		int b = readByte();
		StringBuilder sb = new StringBuilder();
		while (!isTrash(b) || b == ' ') {
			sb.appendCodePoint(b);
			b = readByte();
		}
		return sb.toString();
	}

	double nextDouble() {
		return Double.parseDouble(nextToken());
	}

	char nextChar() {
		return (char) skip();
	}

	int nextInt() {
		int ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}

	long nextLong() {
		long ret = 0;
		int b = skip();
		if (b != '-' && (b < '0' || b > '9')) {
			throw new InputMismatchException();
		}
		boolean neg = false;
		if (b == '-') {
			neg = true;
			b = readByte();
		}
		while (true) {
			if (b >= '0' && b <= '9') {
				ret = ret * 10 + (b - '0');
			} else {
				if (b != -1 && !isTrash(b)) {
					throw new InputMismatchException();
				}
				return neg ? -ret : ret;
			}
			b = readByte();
		}
	}
}