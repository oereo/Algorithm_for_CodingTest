package practice.programmers.kakao_2021_recruitment;

import java.util.Scanner;

public class 신규_아이디_추천 {
    private static final Scanner SCANNER = new Scanner(System.in);

    public static void main(String[] args) {
        String newId = SCANNER.nextLine();
        String recommendedId = solution(newId);
        System.out.println(recommendedId);
    }

    private static String solution(String newId) {
        String recommendedId;
        recommendedId = verifyUpperCase(newId); // phase 1: 모든 대문자를 소문자로 치환
        recommendedId = verifySpecialCharacter(recommendedId);  // phase 2: 알파벳 소문자, 숫자, -, ., _ 제외한 모든 문자 제거
        recommendedId = verifyContinuousPeriods(recommendedId); // phase 3: 2번 이상 연속된 .를 하나의 .로 치환
        recommendedId = verifyFirstOrLastPeriod(recommendedId); // phase 4: .가 처음이나 끝에 위치하면 제거
        recommendedId = verifyBlankString(recommendedId); //phase 5: 빈 문자열이면 a 대입
        recommendedId = verifyExceededLength(recommendedId); //phase 6: 16자 이상이면 나머지 문제 제거
        recommendedId = verifyShorterLength(recommendedId); //phase 7: 2자 이하이면 3자까지 마지막 문자 반복

        return recommendedId;
    }

    private static String verifyUpperCase(String id) {
        return id.toLowerCase();
    }

    private static String verifySpecialCharacter(String id) {
        String regex = "[^0-9a-z_.-]";
        return id.replaceAll(regex, "");
    }

    private static String verifyContinuousPeriods(String id) {
        String regex = "\\.+";
        return id.replaceAll(regex, ".");
    }

    private static String verifyFirstOrLastPeriod(String id) {
        char period = '.';
        String modifiedId = id;

        // s = s.replaceAll("^[.]|[.]$", "");
        if (!id.isBlank() && id.charAt(0) == period) {
            modifiedId = modifiedId.substring(1);
        }
        if (!id.isBlank() && modifiedId.charAt(modifiedId.length() - 1) == period) {
            modifiedId = modifiedId.substring(0, modifiedId.length() - 1);
        }

        return modifiedId;
    }

    private static String verifyBlankString(String id) {
        return id.isBlank() ? "a" : id;
    }

    private static String verifyExceededLength(String id) {
        String modifiedId = id;
        if (id.length() > 15) {
            modifiedId = id.substring(0, 15);
        }
        modifiedId = verifyFirstOrLastPeriod(modifiedId);
        return modifiedId;
    }

    private static String verifyShorterLength(String id) {
        String modifiedId = id;
        if (id.length() < 3) {
            char lastCharacter = id.charAt(id.length() - 1);
            for (int i = id.length(); i < 3; i++) {
                modifiedId += lastCharacter;
            }
        }
        return modifiedId;
    }
}
