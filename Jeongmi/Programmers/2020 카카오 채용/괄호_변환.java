package practice.programmers.kakao_2020_recruitment;

import java.util.Scanner;

public class 괄호_변환 {
    private static final Scanner SCANNER = new Scanner(System.in);
    private static final char OPEN_PARENTHESIS = '(';
    private static final char CLOSE_PARENTHESIS = ')';

    public static void main(String[] args) {
        String p = SCANNER.nextLine();
        solution(p);
    }

    private static String solution(String p) {
        if (p.isBlank()) {
            return p;
        }

        String answer = correctBalancedParenthesis(p);
        System.out.println(answer);
        return answer;
    }

    private static String correctBalancedParenthesis(String balancedParenthesis) {
        // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환
        if (balancedParenthesis.isBlank()) {
            return balancedParenthesis;
        }

        // 2. w를 두 "균형잡힌 괄호 문자열" u, v로 분리
        String u = "", v = "";
        int divisionPoint = getDivisionPoint(balancedParenthesis);
        if (divisionPoint == balancedParenthesis.length() - 1) {
            u = balancedParenthesis;  // v는 빈 문자열
        } else {
            u = balancedParenthesis.substring(0, divisionPoint + 1);
            v = balancedParenthesis.substring(divisionPoint + 1);
        }

        boolean correctness = isCorrectParenthesis(u);
        // 4. 문자열 u가 "올바른 괄호 문자열"이 아니라면 아래 과정을 수행한다.
        if (!correctness) {
            StringBuilder correctParenthesis = new StringBuilder(Character.toString(OPEN_PARENTHESIS));
            correctParenthesis.append(correctBalancedParenthesis(v)).append(CLOSE_PARENTHESIS);
            for (int j = 1; j < u.length() - 1; j++) {
                if (u.charAt(j) == OPEN_PARENTHESIS) {
                    correctParenthesis.append(CLOSE_PARENTHESIS);
                } else {
                    correctParenthesis.append(OPEN_PARENTHESIS);
                }
            }
            return correctParenthesis.toString();
        }

        // 3. u가 "올바른 괄호 문자열" 이라면 문자열 v에 대해 1단계부터 다시 수행한다.
        u += correctBalancedParenthesis(v);
        return u;
    }

    private static int getDivisionPoint(String balancedParenthesis) { // w를 u와 v로 나누는 분할점을 찾는다.
        int openParenNums = 0;
        int closeParenNums = 0;
        for (int i = 0; i < balancedParenthesis.length(); i++) {
            if (balancedParenthesis.charAt(i) == OPEN_PARENTHESIS) {  // 여는 괄호이면
                openParenNums += 1;
            } else {    // 닫는 괄호이면
                closeParenNums += 1;
            }

            if (openParenNums == closeParenNums) {  // w의 index i까지의 substring이 균형잡힌 괄호 문자열일 경우
                return i;
            }
        }
        return balancedParenthesis.length() - 1;
    }

    private static boolean isCorrectParenthesis(String u) {
        int correctness = 0;
        for (int i = 0; i < u.length(); i++) {
            if (u.charAt(i) == OPEN_PARENTHESIS) {
                correctness += 1;
            } else {
                correctness -= 1;
            }

            if (correctness < 0) {  // 올바른 문자열이 아니라면
                return false;
            }
        }
        return true;
    }
}
