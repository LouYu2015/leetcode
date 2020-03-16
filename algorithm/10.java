class Solution {
    public boolean isMatch(String s, String p) {
        return isMatch(s, 0, p, 0);
    }
    
    public boolean isMatch(String s, int sc, String p, int pc) {
        if (sc == s.length() && pc == p.length()) {
            System.out.println("8:" + sc + " " + pc + " " + "true");
            return true;
        } else if (sc >= s.length() || pc >= p.length()) {
            System.out.println("11:" + sc + " " + pc + " " + "false");
            if (pc == p.length() - 2 && p.charAt(pc + 1) == '*') {
                return true;
            }
            return false;
        }
        
        boolean result = false;
        if (pc + 1 < p.length() && p.charAt(pc + 1) == '*') {
            if (isMatch(s.charAt(sc), p.charAt(pc))) {
                result = result || isMatch(s, sc + 1, p, pc);
                System.out.println("23:" + sc + " " + pc + " " + result);
            }
            result = result || isMatch(s, sc, p, pc + 2);
            System.out.println("26:" + sc + " " + pc + " " + result);
        } else {
            result = isMatch(s.charAt(sc), p.charAt(pc)) && isMatch(s, sc + 1, p, pc + 1);
            System.out.println("29:" + sc + " " + pc + " " + result);
        }
        return result;
    }
    
    public boolean isMatch(char s, char p) {
        if (p == '.') {
            return true;
        } else {
            return s == p;
        }
    }
}
