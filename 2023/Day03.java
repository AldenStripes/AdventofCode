package AdventOfCode2023;
import java.util.*;
import java.io.*;
public class Day03 {
	static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	static StringTokenizer st;
	static char[][] a;
	static boolean isSymbol(char c) {
		if (!Character.isDigit(c)&&c!='.') {
			return true;
		}
		return false;
	}
	static boolean isPart(int r, int begin, int end) {
		if (r==0||r==139||begin==0||end==139) {
			if (r==0) {
				for (int i=begin-1; i<=end+1; ++i) {
					if (isSymbol(a[r+1][i])) {
						return true;
					}
				}
				if (isSymbol(a[r][begin-1])||isSymbol(a[r][end+1])) {
					return true;
				}
				return false;
			}	else if (r==139) {
				for (int i=begin-1; i<=end+1; ++i) {
					if (isSymbol(a[r-1][i])) {
						return true;
					}
				}
				if (isSymbol(a[r][begin-1])||isSymbol(a[r][end+1])) {
					return true;
				}
			}	else if (begin==0) {
				for (int i=begin; i<=end+1; ++i) {
					if (isSymbol(a[r-1][i])||isSymbol(a[r+1][i])) {
						return true;
					}
				}
				if (isSymbol(a[r][end+1])) {
					return true;
				}
				return false;
			}	else if (end==139) {
				for (int i=begin-1; i<=end; ++i) {
					if (isSymbol(a[r-1][i])||isSymbol(a[r+1][i])) {
						return true;
					}
				}
				if (isSymbol(a[r][begin-1])) {
					return true;
				}
				return false;
			}
		}	else { //in the middle somewhere
			for (int i=begin-1; i<=end+1; ++i) {
				if (isSymbol(a[r-1][i])||isSymbol(a[r+1][i])) {
					return true;
				}
			}
			if (isSymbol(a[r][begin-1])||isSymbol(a[r][end+1])) {
				return true;
			}
			return false;
		}
		return false;
	}
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("Day3Input.txt"));
		String firstLine = sc.nextLine();
		int len = firstLine.length();
		a = new char[140][len];
		for (int i=0; i<firstLine.length(); ++i) {
			a[0][i] = firstLine.charAt(i);
		}
		for (int i=1; i<140; ++i) {
			String S = sc.nextLine();
			for (int j=0; j<len; ++j) {
				a[i][j] = S.charAt(j);
			}
		}
		LinkedList<Integer> parts = new LinkedList<>();
		for (int r=0; r<140; ++r) {
			for (int c=0; c<140; ++c) {
				if (Character.isDigit(a[r][c])) {
					int begin = c; 
					int end;
					int i = c+1; 
					while (true) {
						if (Character.isDigit(a[r][i])&&i==139) {
							end = 139;
							break;
						}
						if (Character.isDigit(a[r][i])) {
							i ++;
						}	else {
							end = i-1;
							break;
						}
					}
					c = end;
					//now we have a number from begin to end
					if (isPart(r, begin, end)) {
						String S = "";
						for (int j=begin; j<=end; ++j) {
							S += a[r][j];
						}
						parts.push(Integer.parseInt(S));
						
						
					}
				}
			}
		}
		int sum = 0;
		for (int i: parts) {
			sum += i;
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
