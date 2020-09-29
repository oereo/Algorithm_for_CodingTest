package com.ssafy.algo.BJ;

import java.util.Scanner;

public class BJ_G5_17144_미세먼지안녕 {
    static int R, C, T;
    static int map[][];
    static Machine[] m;
    static int dirs[][] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    static int answer;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        R = sc.nextInt();
        C = sc.nextInt();
        T = sc.nextInt();

        map = new int[R][C];
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                map[r][c] = sc.nextInt();
            }
        }

        int index = 0;
        m = new Machine[2];
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (map[r][c] == -1) {
                    m[index++] = new Machine(r, c);
                }
            }
        }

        for (int i = 0; i < T; i++) {
            spread(new int[R][C]);
            move(new int[R][C]);
        }

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                if (map[r][c] > 0) {
                    answer += map[r][c];
                }
            }
        }

        System.out.println(answer);

    }

    static void spread(int[][] temp) {
        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                temp[r][c] += map[r][c];
                
                if (map[r][c] < 5) {
                    continue;
                }
                
                int cnt = map[r][c] / 5;
                for (int d = 0; d < dirs.length; d++) {
                    int nr = r + dirs[d][0];
                    int nc = c + dirs[d][1];
                    if (isIn(nr, nc) && map[nr][nc] != -1) {
                        temp[r][c] -= cnt;
                        temp[nr][nc] += cnt;
                    }
                }
            }
        }

        for (int r = 0; r < R; r++) {
            for (int c = 0; c < C; c++) {
                map[r][c] = temp[r][c];
            }
        }
    }

    static void move(int[][] temp) {
        for (int i = 0; i < 2; i++) {
            Machine now = m[i];
            int nr = now.r;
            int nc = now.c + 1;
            
            while (nc < C - 1) {
                temp[nr][nc + 1] = map[nr][nc];
                nc++;
            }
            
            if (i == 0) {
                while (nr > 0) {
                    temp[nr - 1][nc] = map[nr][nc];
                    nr--;
                }
            } else {
                while (nr < R - 1) {
                    temp[nr + 1][nc] = map[nr][nc];
                    nr++;
                }
            }
            
            while (nc > 0) {
                temp[nr][nc - 1] = map[nr][nc];
                nc--;
            }
            
            if (i == 0) {
                while (nr < now.r - 1) {
                    temp[nr + 1][nc] = map[nr][nc];
                    nr++;
                }
            } else {
                while (nr > now.r + 1) {
                    temp[nr - 1][nc] = map[nr][nc];
                    nr--;
                }
            }
        }

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (i == 0 || i == R - 1 || j == 0 || j == C - 1 || i == m[0].r || i == m[1].r) {
                    map[i][j] = temp[i][j];
                }
            }
        }
        
        map[m[0].r][m[0].c] = -1;
        map[m[1].r][m[1].c] = -1;
    }

    static boolean isIn(int r, int c) {
        return 0 <= r && r < R && 0 <= c && c < C;
    }

    static class Machine {
        int r, c;

        public Machine(int r, int c) {
            this.r = r;
            this.c = c;
        }

    }

}
