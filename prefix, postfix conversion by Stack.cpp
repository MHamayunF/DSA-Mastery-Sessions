#include <iostream>
#include <string>
#include <stack>
using namespace std;

int MyPrecedence(char MyOp) 
{
    if (MyOp == '+' || MyOp == '-') 
    {
        return 1;
    } 
    else if (MyOp == '*' || MyOp == '/') 
    {
        return 2;
    }
    return 0;
}

bool IsMyOperator(char MyChar) 
{
    return MyChar == '+' || MyChar == '-' || MyChar == '*' || MyChar == '/';
}

string InfixToPostfix(string MyInfix) 
{
    string MyPostfix = "";
    stack<char> MyOperators;

    for (int i = 0; i < MyInfix.length(); i++) 
	{
        char MyC = MyInfix[i];

        if (MyC == ' ' || MyC == '\t') 
		{
            continue;  
        }

        if (isdigit(MyC) || isalpha(MyC)) 
		{
            MyPostfix += MyC;  
        } 
		else if (MyC == '(') 
		{
            MyOperators.push(MyC);
        } 
		else if (MyC == ')') 
		{
            while (!MyOperators.empty() && MyOperators.top() != '(') 
			{
                MyPostfix += MyOperators.top();
                MyOperators.pop();
            }
            if (!MyOperators.empty() && MyOperators.top() == '(') 
			{
                MyOperators.pop();  
            } else 
			{
                
                return "Error: Invalid input expression.";
            }
        } 
		else if (IsMyOperator(MyC)) 
		{
            while (!MyOperators.empty() && MyPrecedence(MyC) <= MyPrecedence(MyOperators.top())) 
			{
                MyPostfix += MyOperators.top();
                MyOperators.pop();
            }
            MyOperators.push(MyC);
        } else 
		{
            return "Error: Invalid input expression.";
        }
    }

    while (!MyOperators.empty()) 
	{
        if (MyOperators.top() == '(') 
		{
            return "Error: The expression is Invalid.";
        }
        MyPostfix += MyOperators.top();
        MyOperators.pop();
    }

    return MyPostfix;
}

int EvaluateMyPostfix(string MyPostfix) 
{
    stack<int> MyOperands;

    for (int i = 0; i < MyPostfix.length(); i++) 
	{
        char MyC = MyPostfix[i];
        if (isdigit(MyC)) 
		{
            int MyNum = 0;
            while (i < MyPostfix.length() && isdigit(MyPostfix[i])) 
			{
                MyNum = MyNum * 10 + (MyPostfix[i] - '0');
                i++;
            }
            i--;
            MyOperands.push(MyNum);

            
            cout << "Postfix Stack: ";
            
            stack<int> MyTempStack = MyOperands;
            while (!MyTempStack.empty()) {
                cout << MyTempStack.top() << " ";
                MyTempStack.pop();
            }
            cout << endl;
        } else if (IsMyOperator(MyC)) {
            int MyOperand2 = MyOperands.top();
            MyOperands.pop();
            int MyOperand1 = MyOperands.top();
            MyOperands.pop();
            int MyResult;
            switch (MyC) {
                case '+':
                    MyResult = MyOperand1 + MyOperand2;
                    break;
                case '-':
                    MyResult = MyOperand1 - MyOperand2;
                    break;
                case '*':
                    MyResult = MyOperand1 * MyOperand2;
                    break;
                case '/':
                    if (MyOperand2 == 0) {
                        return 0; 
                    }
                    MyResult = MyOperand1 / MyOperand2;
                    break;
                default:
                    return 0; 
            }
            MyOperands.push(MyResult);

            
            cout << "Postfix Stack: ";
            stack<int> MyTempStack = MyOperands;
            while (!MyTempStack.empty()) {
                cout << MyTempStack.top() << " ";
                MyTempStack.pop();
            }
            cout << endl;
        }
    }

    if (MyOperands.size() == 1) {
        return MyOperands.top();
    } else {
        return 0; 
    }
}

int main() {
    string MyInfix;
	cout << "Enter an infix expression: ";
    getline(cin, MyInfix);

    string MyPostfix = InfixToPostfix(MyInfix);
    cout << "Postfix expression is: " << MyPostfix << endl;
    cout<<endl;
    cout<<"Now  Evaluate 12 7 3 - / 2 1 5 + * + postfix expression "<<endl;
    cout<<endl;
    string MyPostfixExpression = "12 7 3 - / 2 1 5 + * +";
    int MyResult = EvaluateMyPostfix(MyPostfixExpression);
    cout<<endl;
    cout << "Final result is: " << MyResult << endl;
    return 0;
}

