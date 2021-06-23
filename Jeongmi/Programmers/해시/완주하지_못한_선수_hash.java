package practice.programmers.해시;

import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class 완주하지_못한_선수_hash {
    private static final Scanner SCANNER = new Scanner(System.in);
    private static final String DELIMITER = ", ";
    private static final int PLAYERSTATS_DEFAULT_VALUE = 0;

    public static void main(String[] args) {
        String participant = SCANNER.nextLine();
        String completion = SCANNER.nextLine();
        solution(participant.split(DELIMITER), completion.split(DELIMITER));
    }

    public static String solution(String[] participant, String[] completion) {
        // <Key, Value>: <player의 이름 String, 그 이름을 가진 선수가 몇 명 있는지 Integer>
        Map<String, Integer> playerStats = new HashMap<>();
        String poorPlayer = "";

        for (String player : participant) {
            playerStats.put(player, playerStats.getOrDefault(player, PLAYERSTATS_DEFAULT_VALUE) + 1);
        }
        for (String player : completion) {
            playerStats.put(player, playerStats.get(player) - 1);
        }

        for (String player : playerStats.keySet()) {
            if (playerStats.get(player) == 1) {
                poorPlayer = player;
            }
        }

        return poorPlayer;
    }
}
