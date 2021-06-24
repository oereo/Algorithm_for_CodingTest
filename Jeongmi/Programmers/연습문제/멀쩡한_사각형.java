package practice.programmers.연습문제;

import java.util.Scanner;

public class 멀쩡한_사각형 {
    private static final Scanner SCANNER = new Scanner(System.in);

    public static void main(String[] args) {
        int w = SCANNER.nextInt();
        int h = SCANNER.nextInt();
        solution(w, h);
    }

    private static long solution(int w, int h) {
        long totalSquares = (long)w * (long)h;
        long gcd = gcd(w, h);
        totalSquares -= (w / gcd + h / gcd - 1) * gcd;
        return totalSquares;
    }

    private static long gcd(long a, long b) { // 최대공약수, the greatest common denominator
        if (a % b == 0) {
            return b;
        }
        return gcd(b, a % b);
    }
}
