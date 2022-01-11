import java.util.Stack;

class GFG{
    static boolean isOperator(char c){
        return switch (c) {
            case '+', '-', '*', '/' -> true;
            default -> false;
        };
    }
    public static String convert(String str){
        Stack<String> stack = new Stack<>();

        int length = str.length();
        for(int i = length - 1; i >= 0; i--)
        {
            char c = str.charAt(i);
            if(isOperator(c))
            {
                String op1 = stack.pop();
                String op2 = stack.pop();

                String temp = "(" + op1 + c + op2 + ")";
                stack.push(temp);
            }
            else
            {
                stack.push(c + "");
            }
        }
        return stack.pop();
    }
    public static void main(String args[])
    {
        String exp = "*-A/BC-/AKL";
        System.out.println("Infix : " + convert(exp));
    }
}
