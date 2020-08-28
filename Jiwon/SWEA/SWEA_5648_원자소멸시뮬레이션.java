package algo.SWEA;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class SWEA_5648_원자소멸시뮬레이션 {

    static int T, N;
    static int[] dx = {-1, 1, 0, 0};
    static int[] dy = {0, 0, -1, 1};
    static int[][] map = new int[4001][4001];
    static Queue<Atom> q = new LinkedList<>();
    static int answer;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        T = sc.nextInt();

        for (int t = 1; t <= T; t++) {
            N = sc.nextInt();
            answer = 0;
            for (int i = 0; i < N; i++) {
                int y = (sc.nextInt() + 1000) * 2;
                int x = 4000 - ((sc.nextInt() + 1000) * 2);
                int dir = sc.nextInt();
                int value = sc.nextInt();

                map[x][y] = value;
                q.add(new Atom(x, y, dir, value));
            }

            bfs();
            System.out.println("#" + t + " " + answer);
        }
    }

    private static void bfs() {

        while (!q.isEmpty()) {
            Atom at = q.poll();
            if (map[at.x][at.y] != at.k) {
                answer += map[at.x][at.y];
                map[at.x][at.y] = 0;
                continue;
            }

            int nx = at.x + dx[at.dir];
            int ny = at.y + dy[at.dir];

            if (isIn(nx, ny)) {
                if (map[nx][ny] == 0) {
                    map[nx][ny] = at.k;
                    q.add(new Atom(nx, ny, at.dir, at.k));
                } else {
                    map[nx][ny] += at.k;
                }
            }
            map[at.x][at.y] = 0;
        }
    }

    static boolean isIn(int r, int c) {
        return 0 <= r && r <= 4000 && 0 <= c && c <= 4000;
    }

    static class Atom {
        int x, y, dir, k;

        Atom(int x, int y, int dir, int k) {
            this.x = x;
            this.y = y;
            this.dir = dir;
            this.k = k;
        }
    }

}

