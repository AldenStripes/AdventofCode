package AdventOfCode2023;
import java.util.*;
import java.io.*;
public class Day03Part2 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static char[][] a;
	static boolean isDigit(char c) {
		return Character.isDigit(c);
	}
	static boolean hasTwoNumbers(int r, int c) {
		int n = 0;
		if (isDigit(a[r][c-1])) {
			n ++;
		}
		if (isDigit(a[r][c+1])) {
			n ++;
		}
		if (isDigit(a[r-1][c])) {
			n ++;
		}	else if (isDigit(a[r-1][c-1])||isDigit(a[r-1][c+1])) {
			if (isDigit(a[r-1][c-1])&&isDigit(a[r-1][c+1])) {
				n += 2;
			}	else {
				n ++;
			}
		}
		if (isDigit(a[r+1][c])) {
			n ++;
		}	else if (isDigit(a[r+1][c-1])||isDigit(a[r+1][c+1])) {
			if (isDigit(a[r+1][c-1])&&isDigit(a[r+1][c+1])) {
				n += 2;
			}	else {
				n ++;
			}
		}
		return (n==2) ? true : false;
	}
	static int leftOf(int r, int c) {
		String num = "";
		for (int i=c; i>=c-2; --i) {
			if (isDigit(a[r][i])) {
				num = a[r][i] + num;
			}	else {
				break;
			}
		}
		return Integer.parseInt(num);
	}
	static int rightOf(int r, int c) {
		String num = "";
		for (int i=c; i<=c+2; ++i) {
			if (isDigit(a[r][i])) {
				num += a[r][i];
			}	else {
				break;
			}
		}
		return Integer.parseInt(num);
	}
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("Day3Input.txt"));
		a = new char[140][140];
		for (int i=0; i<140; ++i) {
			String S = sc.nextLine();
			for (int j=0; j<140; ++j) {
				a[i][j] = S.charAt(j);
			}
		}
		long sum = 0;
		for (int r=0; r<140; ++r) {
			for (int c=0; c<140; ++c) {
				if (a[r][c]=='*'&&hasTwoNumbers(r, c)) {
					LinkedList<Integer> cur = new LinkedList<>();
					if (isDigit(a[r][c-1])) { //check left
						int num = leftOf(r, c-1);
						cur.push(num);
					}
					if (isDigit(a[r][c+1])) { //check right
						int num = rightOf(r, c+1);
						cur.push(num);
					}
					if (isDigit(a[r-1][c-1])||isDigit(a[r-1][c])||isDigit(a[r-1][c+1])) { //check top
						if (isDigit(a[r-1][c-1])&&isDigit(a[r-1][c])&&isDigit(a[r-1][c+1])) {
							int num = leftOf(r-1, c+1);
							cur.push(num);
						}	else {
							if (isDigit(a[r-1][c])) { //check above
								if (isDigit(a[r-1][c-1])&&!isDigit(a[r-1][c+1])) {
									int num = leftOf(r-1, c);
									cur.push(num);
								}	else if (!isDigit(a[r-1][c-1])&&isDigit(a[r-1][c+1])) {
									int num = rightOf(r-1, c);
									cur.push(num);
								}	else {
									cur.push(Integer.parseInt(String.valueOf(a[r-1][c])));
								}
							}	else {
								if (isDigit(a[r-1][c-1])) {
									int num = leftOf(r-1, c-1);
									cur.push(num);
								}
								if (isDigit(a[r-1][c+1])) {
									int num = rightOf(r-1, c+1);
									cur.push(num);
								}
							}
						}
					}
					if (isDigit(a[r+1][c-1])||isDigit(a[r+1][c])||isDigit(a[r+1][c+1])) { //check bottom
						if (isDigit(a[r+1][c-1])&&isDigit(a[r+1][c])&&isDigit(a[r+1][c+1])) {
							int num = leftOf(r+1, c+1);
							cur.push(num);
						}	else {
							if (isDigit(a[r+1][c])) { //check below
								if (isDigit(a[r+1][c-1])&&!isDigit(a[r+1][c+1])) {
									int num = leftOf(r+1, c);
									cur.push(num);
								}	else if (!isDigit(a[r+1][c-1])&&isDigit(a[r+1][c+1])) {
									int num = rightOf(r+1, c);
									cur.push(num);
								}	else {
									cur.push(Integer.parseInt(String.valueOf(a[r+1][c])));
								}
							}	else {
								if (isDigit(a[r+1][c-1])) {
									int num = leftOf(r+1, c-1);
									cur.push(num);
								}
								if (isDigit(a[r+1][c+1])) {
									int num = rightOf(r+1, c+1);
									cur.push(num);
								}
							}
						}
					}
					sum += cur.pop()*cur.pop();
				}
			}
		}
		System.out.println("sum: "+sum);
	}

	static String next() throws IOException {
		while (st == null || !st.hasMoreTokens())
			st = new StringTokenizer(br.readLine().trim());
		return st.nextToken();
	}

	static int readInt() throws IOException {
		return Integer.parseInt(next());
	}

	static long readLong() throws IOException {
		return Long.parseLong(next());
	}

	static double readDouble() throws IOException {
		return Double.parseDouble(next());
	}

	static String readLine() throws IOException {
		return br.readLine().trim();
	}

	static char readChar() throws IOException {
		return next().charAt(0);
	}
}
