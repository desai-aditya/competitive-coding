class Solution {
    private boolean isToken(String c)
    {
        return (c.length() == 1) && (c.equals("+") ||c.equals("-") ||c.equals("*") ||c.equals("/") );
        
    }
    public int evalRPN(String[] tokens) {
        Stack<String> s  = new Stack<String>();
        
        for(int i = 0 ; i < tokens.length; i++)
        {
            if(isToken(tokens[i]) && !s.empty())
            {
                int op2 = Integer.parseInt(s.pop());
                int op1 = Integer.parseInt(s.pop());
                int result = 0;
                if(tokens[i].equals("+"))
                    result = op1 + op2;
                else if(tokens[i].equals("-"))
                    result = op1 - op2;
                else if(tokens[i].equals("*"))
                    result = op1 * op2;
                else if(tokens[i].equals("/"))
                    result = op1 / op2;        
                System.out.println(result);
                s.push(String.valueOf(result));
                
            }
            else
            {
                s.push(tokens[i]);
            }            
        }

        return Integer.valueOf(s.pop());
    }
}