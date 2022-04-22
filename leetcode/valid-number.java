import java.util.regex.Matcher;
import java.util.regex.Pattern;
class Solution {
    public boolean isNumber(String s) {
        String integerRegex = "([+-]?\\d+)";
        String decimalRegex = "([+-]?((\\d+\\.)|(\\d+\\.\\d+?)|(\\.\\d+)))";
        String validNumberRegex = "^("+integerRegex+"|"+decimalRegex+"){1}(([eE]"+integerRegex+")?)$";
        // String validNumberRegex = "\\.";

        Pattern r = Pattern.compile(validNumberRegex);
        Matcher m = r.matcher(s);
        System.out.println(validNumberRegex);
        return m.matches();                
    }
}