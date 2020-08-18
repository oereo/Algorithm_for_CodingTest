package algorithm.SWEA;

import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class SWEA_5656_벽돌깨기 {
	static int T, N, W, H;
	static int[][] dirs = { { 1, 0 }, { 0, 1 }, { -1, 0 }, { 0, -1 } };
	static int[][] map;
	static int[][] tempMap;
	static int[] possibleC;
	static int answer;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

		T = sc.nextInt();

		for (int t = 1; t <= T; t++) {
			N = sc.nextInt();
			W = sc.nextInt();
			H = sc.nextInt();

			map = new int[H][W];
			for (int r = 0; r < H; r++) {
				for (int c = 0; c < W; c++) {
					map[r][c] = sc.nextInt();
//					if (map[r][c] != 0) {
//						answer++;
//					}
				}
			}

			possibleC = new int[W * N];
			possibleC[0] = 0;
			for (int i = 1; i < W * N; i++) {
				possibleC[i] = i % W;
			}

			answer = Integer.MAX_VALUE;
			makeCombination(N, 0, new int[N]);

			System.out.println("#" + t + " " + answer);
		}

	}

	static boolean isIn(int r, int c) {
		return 0 <= r && r < H && 0 <= c && c < W;
	}

	static void makeCombination(int r, int start, int[] temp) {
		if (r == 0) {
			tempMap = new int[H][W];
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					tempMap[i][j] = map[i][j];
				}
			}

			for (int i = 0; i < temp.length; i++) {
				hit(temp[i]);
			}

			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					System.out.print(tempMap[i][j]);
				}
				System.out.println();
			}

			int cnt = 0;
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					if (tempMap[i][j] > 0) {
						cnt++;
					}
				}
			}

			System.out.println(cnt);
			
			if (cnt == 0) {
				answer = 0;
				return;
			}
			
			answer = answer > cnt ? cnt : answer;

			return;
		}

		for (int i = start; i < possibleC.length; i++) {
			temp[r - 1] = possibleC[i];
			makeCombination(r - 1, i + 1, temp);
		}

	}

	static class Now {
		int r, c, value;

		public Now(int r, int c, int value) {
			super();
			this.r = r;
			this.c = c;
			this.value = value;
		}

	}

	static void hit(int cHit) {
		boolean clean = false;
		for (int r = 0; r < H; r++) {
			if (tempMap[r][cHit] > 1) {
				Queue<Now> q = new LinkedList<>();
				q.offer(new Now(r, cHit, tempMap[r][cHit]));
				while (!q.isEmpty()) {
					Now front = q.poll();

					for (int i = 1; i < front.value; i++) {
						for (int d = 0; d < dirs.length; d++) {
							int nr = front.r + dirs[d][0] * i;
							int nc = front.c + dirs[d][1] * i;

							if (isIn(nr, nc)) {
								if (tempMap[nr][nc] > 1) {
									q.offer(new Now(nr, nc, tempMap[nr][nc]));
									tempMap[nr][nc] = 0;
								} else if (tempMap[nr][nc] == 1) {
									tempMap[nr][nc] = 0;
								}
							}
						}
					}

				}
				break;
			} else if (tempMap[r][cHit] == 1) {
				clean = true;
				tempMap[r][cHit] = 0;
				break;
			}

		}

		// 맵 정리
		if (!clean) {
			int brick = 0;
			for (int i = 0; i < H; i++) {
				for (int j = 0; j < W; j++) {
					brick += tempMap[i][j];
				}
			}
			
			if(brick == 0) {
				return;
			}
			
			Queue<Now> q = new LinkedList<>();
			for (int c = 0; c < W; c++) {
				for (int r = H - 1; r >= 0; r--) {
					if (tempMap[r][c] > 0) {
						q.offer(new Now(r, c, tempMap[r][c]));
						tempMap[r][c] = 0;
					}
				}

				while (!q.isEmpty()) {
					Now front = q.poll();
					for (int r = H - 1; r >= 0; r--) {
						if (tempMap[r][c] == 0) {
							tempMap[r][c] = front.value;
							break;
						}
					}
				}
			}
		}
	}

}
