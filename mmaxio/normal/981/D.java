import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

public class D {
	
	static final int LOG = 57;
	static final long MASK = (1L << LOG) - 1;
	
	long[] b;
	
	int n, k;
	
	void submit() {
		n = nextInt();
		k = nextInt();
		
		long[] a = new long[n];
		for (int i = 0; i < n; i++) {
			a[i] = nextLong();
		}
		
		b = new long[n + 1];
		for (int i = 0; i < n; i++) {
			b[i + 1] = b[i] + a[i];
		}
		
		int bigBit = -1;
		
		for (int bit = LOG - 1; bit >= 0; bit--) {
			if (can(1L << bit)) {
				bigBit = bit;
				break;
			}
		}
		
		if (bigBit == -1) {
			out.println(0);
			return;
		}
		
		long ans = 1L << bigBit;
		
		for (int bit = bigBit - 1; bit >= 0; bit--) {
			if (can(ans | (1L << bit))) {
				ans |= 1L << bit;
			}
		}
		
		out.println(ans);
	}
	
	boolean can(long mask) {
		boolean[] arr = new boolean[n + 1];
		arr[0] = true;
		for (int it = 0; it < k; it++) {
			for (int i = n; i >= 0; i--) {
				if (!arr[i]) {
					continue;
				}
				for (int j = i + 1; j <= n; j++) {
					if (((b[j] - b[i]) & mask) == mask) {
						arr[j] = true;
					}
				}
				arr[i] = false;
			}
		}
		return arr[n];
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

	D() throws IOException {
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
		new D();
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