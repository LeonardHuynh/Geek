def isOperator(c):
    if c == '=' or c == '-' or c == '*' or c == '/' or c == '^' or c == '(' or c == ')':
        return True
    return False

def preToInfix(prefix):

    i = len(prefix) - 1
    stack = []
    
    while i >= 0:
        if isOperator(prefix[i]):
            str = '(' + stack.pop() + prefix[i] + stack.pop() + ')'
            stack.append(str)
            i -= 1
        else:
            stack.append(prefix[i])
            i -= 1
    return stack.pop()

str = "*-A/BC-/AKL"
print(preToInfix(str))
