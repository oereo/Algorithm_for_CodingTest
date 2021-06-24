package practice.programmers.연습문제;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class 나머지_한_점_xor {
    // private static final Scanner SCANNER = new Scanner(System.in);

    public static void main(String[] args) {
        int[][] v = {{1, 4}, {3, 4}, {3, 10}};
        solution(v);
    }

    private static int[] solution(int[][] v) {
        int[] answer = {0, 0};

        // ^= : xor 연산자
        // A xor A = 0, A xor A xor B = B
        for (int i = 0; i < 3; i++) {
            answer[0] ^= v[i][0];
            answer[1] ^= v[i][1];
        }

        return answer;
    }
}
