class Conversion:
    
    def __init__(self, capacity):
        self.top = -1
        self.capacity = capacity
        
        #sử dụng stack ở đây
        self.array = []
        #Thứ tự uuw tiên của toán tử
        self.output = []
        
        self.precedence = {'+':1,'-':1,'*':2,'/':2,'^':3}
        
    
    #kiểm tra xem ngăn xếp có rỗng không
    def isEmpty(self):
        return True if self.top == -1 else False
    #Đưa ra giá trị top của stack
    def peek(self):
        return self.array[-1]
    
    #xóa phần tử khỏi stack
    def pop(self):
        if not self.isEmpty():
            self.top -= 1
            return self.array.pop()
        else:
            return "$"
    #thêm phần tử vào stack
    def push(self,val):
        self.top += 1
        self.array.append(val)
    #hàm kiểm tra toán tử
    def isOperand(self,ch):
        return ch.isalpha()
    #hàm kiểm tra xem số có lớn hơn hay không
    def notGreater(self,i):
        try:
            a = self.precedence[i]
            b = self.precedence[self.peek()]    #thứ tự ưu tiên của phần tử top trong stack
            return True if a <= b else False
        except KeyError:    #toán tử không có trong precedence
            return False
    
    def infixToPostfix(self, exp):
        for i in exp:
            if self.isOperand(i):
                self.output.append(i)
            #Nếu phần tử tìm được là '('
            elif i == '(':
                self.push(i)
            #Nếu phần tử tìm được là ')'
            elif i == ')':
                while(not self.isEmpty() and self.peek() != '('):
                    a = self.pop()
                    self.output.append(a)
                if(not self.isEmpty() and self.peek() != '('):
                    return -1
                else:
                    self.pop()
            #Nếu tim được toán tử
            else:
                while(not self.isEmpty() and self.notGreater(i)):
                    self.output.append(self.pop())
                self.push(i)    #Nếu không thì thêm toán tử vào stack
        #xóa hết phần tử trong stack
        while not self.isEmpty():
            self.output.append(self.pop())
        
        print("".join(self.output))


        
exp = "a+b*(c^d-e)^(f+g*h)-i"
obj = Conversion(len(exp))
obj.infixToPostfix(exp)

