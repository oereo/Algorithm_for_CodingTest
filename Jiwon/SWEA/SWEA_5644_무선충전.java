package java.SWEA;

import java.util.Scanner;

public class SWEA_5644_무선충전 {
    static int T, M, A, N, tim;
    static int[][] map;
    static int[] personA;
    static int[] personB;
    static BC[] bcList;
    static int[] sum;
    static int dirs[][] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        T = sc.nextInt();
        for (int t = 1; t <= T; t++) {
            M = sc.nextInt();
            N = sc.nextInt();

            personA = new int[M];
            personB = new int[M];

            for (int i = 0; i < M; i++) {
                personA[i] = sc.nextInt();
            }

            for (int i = 0; i < M; i++) {
                personB[i] = sc.nextInt();
            }

            bcList = new BC[N];

            for (int bc = 0; bc < N; bc++) {
                int r = sc.nextInt();
                int c = sc.nextInt();
                int ran = sc.nextInt();
                int p = sc.nextInt();
                bcList[bc] = new BC(r - 1, c - 1, ran, p);
            }

            sum = new int[N];

            for (int i = 0; i < N; i++) {
                if (Math.abs(0 - bcList[i].r) + Math.abs(0 - bcList[i].c) <= bcList[i].range) {
                    sum[0] += bcList[i].power;
                }
                if (Math.abs(9 - bcList[i].r) + Math.abs(9 - bcList[i].c) <= bcList[i].range) {
                    sum[1] += bcList[i].power;
                }
            }

            move(0, 0, personA[0], 9, 9, personB[0]);

        }

    }

    static boolean isIn(int rA, int cA, int rB, int cB) {
        return 0 <= rA && rA < 10 && 0 <= cA && cA < 10 && 0 <= rB && rB < 10 && 0 <= cB && cB < 10;
    }

    static void move(int rA, int cA, int dirA, int rB, int cB, int dirB) {

        int nrA = 0;
        int ncA = 0;
        int nrB = 0;
        int ncB = 0;


        if (dirA == 0) {
            nrA = rA;
            ncA = cA;
        } else if (dirA == 1) {
            nrA = rA - 1;
            ncA = cA;
        } else if (dirA == 2) {
            nrA = rA;
            ncA = cA + 1;
        } else if (dirA == 3) {
            nrA = rA + 1;
            ncA = cA;
        } else if (dirA == 4) {
            nrA = rA;
            ncA = cA - 1;
        }

        if (dirB == 0) {
            nrB = rB;
            ncB = cB;
        } else if (dirB == 1) {
            nrB = rB - 1;
            ncB = cB;
        } else if (dirB == 2) {
            nrB = rB;
            ncB = cB + 1;
        } else if (dirB == 3) {
            nrB = rB + 1;
            ncB = cB;
        } else if (dirB == 4) {
            nrB = rB;
            ncB = cB - 1;
        }

        checkpower(nrA, ncA, nrB, ncB);

        tim++;
        
        if (tim == M) {
            return;
        } else {
            move(nrA, ncA, personA[tim], nrB, ncB, personB[tim]);
        }

    }

    static void checkpower(int rA, int cA, int rB, int cB) {
        int[] chargedA = new int[N];
        int[] chargedB = new int[N];

        for (int i = 0; i < N; i++) {
            if (chargedA[i] == 0) {
                if (Math.abs(rA - bcList[i].r) + Math.abs(cA - bcList[i].c) <= bcList[i].range) {
                    sum[0] += bcList[i].power;
                    chargedA[i] = i;
                }
            } else {

            }

            if (chargedB[i] == 0) {
                if (Math.abs(rB - bcList[i].r) + Math.abs(cB - bcList[i].c) <= bcList[i].range) {
                    sum[1] += bcList[i].power;
                    chargedB[i] = i;
                }
            }

        }

        for (int i = 0; i < N; i++) {
            if (chargedA[i] > 0 || chargedB[i] > 0) {

            }
        }
        return;

    }

    static class BC {
        int r;
        int c;
        int range;
        int power;

        public BC(int r, int c, int range, int power) {
            super();
            this.r = r;
            this.c = c;
            this.range = range;
            this.power = power;
        }

        @Override
        public String toString() {
            StringBuilder builder = new StringBuilder();
            builder.append("BC [r=");
            builder.append(r);
            builder.append(", c=");
            builder.append(c);
            builder.append(", range=");
            builder.append(range);
            builder.append(", power=");
            builder.append(power);
            builder.append("]");
            return builder.toString();
        }

    }

}
