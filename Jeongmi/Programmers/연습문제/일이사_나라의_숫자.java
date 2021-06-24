package practice.programmers.연습문제;

import java.util.Scanner;

public class 일이사_나라의_숫자 {
    private static final Scanner SCANNER = new Scanner(System.in);

    public static void main(String[] args) {
        int n = SCANNER.nextInt();
        solution(n);
    }

    private static String solution(int n) {
        StringBuilder builder = new StringBuilder();

        while (n > 0) {
            int remainder = n % 3;
            n /= 3;

            if (remainder == 0) {
                remainder = 4;
                n -= 1;
            }
            builder.append(remainder);
        }
        String answer = builder.reverse().toString();
        System.out.println(answer);
        return answer;
    }
}
