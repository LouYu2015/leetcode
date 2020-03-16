class Solution {
    public boolean isMatch(String s, String p) {
        return isMatch(s, 0, p, 0);
    }
    
    public boolean isMatch(String s, int sc, String p, int pc) {
        if (sc == s.length() && pc == p.length()) {
            return true;
        } else if (sc >= s.length() || pc >= p.length()) {
            return false;
        }
        
        if (s.charAt(sc) == '.') {
            return isMatch(s, sc + 1, p, pc + 1);
        }
        
        boolean result = false;
        if (sc + 1 < s.length() && s.charAt(sc + 1) == '*') {
            if (s.charAt(sc) == p.charAt(pc)) {
                result = result || isMatch(s, sc, p, pc + 1);
            }
            result = result || isMatch(s, sc + 2, p, pc);
        } else {
            result = s.charAt(sc) == p.charAt(pc) && isMatch(s, sc + 1, p, pc + 1);
        }
        return result;
    }
}
