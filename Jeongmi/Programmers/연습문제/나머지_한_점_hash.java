package practice.programmers.연습문제;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class 나머지_한_점_hash {
    // private static final Scanner SCANNER = new Scanner(System.in);

    public static void main(String[] args) {
        int[][] v = {{1, 4}, {3, 4}, {3, 10}};
        solution(v);
    }

    private static int[] solution(int[][] v) {
        List<Integer> answer = new ArrayList<>();
        Map<Integer, Integer> xPositions = new HashMap<>();
        Map<Integer, Integer> yPositions = new HashMap<>();
        int x = 0;
        int y = 0;

        for (int[] position : v) {
            xPositions.put(position[0], xPositions.getOrDefault(position[0], 0) + 1);
            yPositions.put(position[1], yPositions.getOrDefault(position[1], 0) + 1);
        }
        for (int xKey : xPositions.keySet()) {
            if (xPositions.get(xKey) == 1) {
                x = xKey;
                break;
            }
        }
        for (int yKey : yPositions.keySet()) {
            if (yPositions.get(yKey) == 1) {
                y = yKey;
                break;
            }
        }

        answer.add(x);
        answer.add(y);
        return convertIntegers(answer);
    }

    private static int[] convertIntegers(List<Integer> integers) {
        int[] result = new int[integers.size()];
        for (int i = 0; i < result.length; i++) {
            result[i] = integers.get(i);
        }
        return result;
    }
}
