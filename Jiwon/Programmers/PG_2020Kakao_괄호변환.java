package algo.Programmers;

public class PG_2020Kakao_괄호변환 {

    public String solution(String p) {
        return correct(p);
    }

    static String correct(String given) {
        if (given.length() == 0)
            return "";

        int cut = division(given);
        String u = given.substring(0, cut);
        String v = given.substring(cut, given.length());

        if (isCorrect(u)) {
            return u + correct(v);
        } else {
            String temp = '(' + correct(v) + ')';
            u = u.substring(1, u.length() - 1);
            u = reverse(u);
            return temp + u;
        }

    }

    static int division(String w) {
        int close = 0, open = 0;

        int i;
        for (i = 0; i < w.length(); i++) {
            if (w.charAt(i) == '(') {
                open++;
            } else
                close++;
            if (open == close)
                return i + 1;
        }

        return i;
    }

    static boolean isCorrect(String w) {
        int count = 0;
        for (int i = 0; i < w.length(); i++) {
            if (w.charAt(i) == '(') {
                count++;
            } else
                count--;
            if (count < 0)
                return false;
        }
        return count == 0;
    }

    static String reverse(String w) {

        StringBuffer rev = new StringBuffer();
        for (int i = 0; i < w.length(); i++) {
            if (w.charAt(i) == ')') {
                rev.append('(');
            } else
                rev.append(')');
        }
        return rev.toString();
    }

}
