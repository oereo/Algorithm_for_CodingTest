package algorithm.SWEA;

import java.util.Scanner;

public class SWEA_2112_보호필름 {
	static int T, D, W, K;
	static int map[][];
	static int temp[][];
	static int answer;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		T = sc.nextInt();

		for (int t = 1; t <= T; t++) {
			D = sc.nextInt();
			W = sc.nextInt();
			K = sc.nextInt();

			map = new int[D][W];
			for (int r = 0; r < D; r++) {
				for (int c = 0; c < W; c++) {
					map[r][c] = sc.nextInt();
				}
			}

			temp = new int[D][W];
			for (int r = 0; r < D; r++) {
				for (int c = 0; c < W; c++) {
					temp[r][c] = map[r][c];
				}
			}
			
			answer = Integer.MAX_VALUE;

			if (check()) {
				answer = 0;
			} else {
				dfs(0, 0);
			}

			System.out.println("#" + t + " " + answer);
		}

	}

	static void dfs(int cnt, int depth) {
		if (cnt >= answer) {
			return;
		}

		if (depth == D) {
			if (check()) {
				answer = answer > cnt ? cnt : answer;
			}
			return;
		}

		dfs(cnt, depth + 1);

		for (int c = 0; c < W; c++) {
			temp[depth][c] = 0;
		}
		dfs(cnt + 1, depth + 1);

		for (int c = 0; c < W; c++) {
			temp[depth][c] = 1;
		}
		dfs(cnt + 1, depth + 1);

		for (int c = 0; c < W; ++c) {
			temp[depth][c] = map[depth][c];
		}

	}

	static boolean check() {
		for (int c = 0; c < W; c++) {
			int cnt = 1;
			int status = temp[0][c];

			boolean pass = false;

			for (int r = 1; r < D; r++) {
				if (status == temp[r][c]) {
					cnt++;
				} else {
					status = temp[r][c];
					cnt = 1;
				}

				if (cnt == K) {
					pass = true;
					break;
				}

			}
			if (!pass)
				return false;
		}
		return true;
	}

}
