package practice.programmers.월간_챌린지;

import java.util.Scanner;

public class 삼진법_뒤집기 {
    private static final Scanner SCANNER = new Scanner(System.in);
    private static final int BASE = 3;  // 밑

    public static void main(String[] args) {
        int n = SCANNER.nextInt();
        solution(n);
    }

    private static int solution(int n) {
        StringBuilder builder = new StringBuilder();
        int answer = 0;

        // 3진법 변환
        while (n > 0) {
            builder.append(n % BASE);
            n /= BASE;
        }

        String reversedN = builder.toString();
        System.out.println("reversedN: " + reversedN);
        for (int i = 0; i < reversedN.length(); i++) {
            answer += Character.getNumericValue(reversedN.charAt(reversedN.length() - i - 1)) * (int)Math.pow(BASE, i);
        }

        return answer;
    }
}
