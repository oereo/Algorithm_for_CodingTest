package practice.programmers;

import java.util.Scanner;

public class 약수의_개수와_덧셈 {
    private static final Scanner SCANNER = new Scanner(System.in);

    public static void main(String[] args) {
        int left = SCANNER.nextInt();
        int right = SCANNER.nextInt();
        solution(left, right);
    }

    private static int solution(int left, int right) {
        int answer = 0;

        for (int i = left; i < (right + 1); i++) {
            int numOfDivisor = getNumberOfDivisors(i);  // i의 약수 개수 구하기
            if (numOfDivisor % 2 == 0) {    // 약수의 개수가 짝수이면 더한다
                answer += i;
            } else {    // 약수의 개수가 홀수이면 뺀다
                answer -= i;
            }
        }
        return answer;
    }

    private static int getNumberOfDivisors(int number) {
        int numOfDivisors = 0;

        for (int i = 1; i <= (int) Math.sqrt(number); i++) {
            if (number % i == 0) {  // k가 약수일 경우
                numOfDivisors += 1;
                if (number / i != i) {  // n/k가 약수일 경우
                    numOfDivisors += 1;
                }
            }
        }
        return numOfDivisors;
    }
}
