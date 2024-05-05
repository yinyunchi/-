#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include "CppUnitTest.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
int isExpressionValid(char* expression);
#define MAX_SIZE 100

// 栈结构定义
typedef struct {
    char data[MAX_SIZE];
    int top;
} Stack;

// 初始化栈
void initStack(Stack* stack) {
    stack->top = -1;
}

// 入栈
void push(Stack* stack, char c) {
    stack->data[++stack->top] = c;
}

// 出栈
char pop(Stack* stack) {
    return stack->data[stack->top--];
}

// 判断是否为运算符
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// 判断表达式是否合法
int isExpressionValid(char* expression) {
    Stack stack;
    initStack(&stack);
    int len = strlen(expression);

    for (int i = 0; i < len; i++) {
        char c = expression[i];

        if (isOperator(c)) {
            if (stack.top == -1) {
                push(&stack, c);
            }
            else {
                char top = stack.data[stack.top];
                if (top == '(') {
                    push(&stack, c);
                }
                else {
                    return 0;  // 运算符连续出现，表达式非法
                }
            }
        }
        else if (c == '(') {
            push(&stack, c);
        }
        else if (c == ')') {
            if (stack.top == -1) {
                return 0;  // 出现多余的右括号，表达式非法
            }
            else {
                char top = pop(&stack);
                if (top != '(') {
                    return 0;  // 括号不匹配，表达式非法
                }
            }
        }
    }

    if (stack.top != -1) {
        return 0;  // 还有剩余的左括号，表达式非法
    }

    return 1;  // 表达式合法
}

// 生成随机数
int generateRandomNumber(int max) {
    return rand() % max + 1;
}

// 生成运算符
char generateOperator(const vector<char>& operators) {
    int index = rand() % operators.size();
    return operators[index];
}

// 生成单个题目
string generateProblem(int maxNumber, const vector<char>& operators, bool hasParentheses, bool hasDecimal) {
    int number1 = generateRandomNumber(maxNumber);
    int number2 = generateRandomNumber(maxNumber);
    char oper = generateOperator(operators);

    if (hasParentheses) {
        // 添加括号逻辑
    }
    if (hasDecimal) {
        // 添加小数逻辑
    }

    // 生成题目字符串
    return to_string(number1) + " " + oper + " " + to_string(number2);
}

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
            srand(time(NULL));

            int numProblems = 5, maxNumber = 5;
            vector<char> operators;
            bool hasParentheses = 1, hasDecimal = 1;
            string outputMethod;
            string temp = "+ -*/ ";
            for (char ch : temp) {
                operators.push_back(ch);
            }          
            vector<string> problems;
            for (int i = 0; i < numProblems; ++i) {
                problems.push_back(generateProblem(maxNumber, operators, hasParentheses, hasDecimal));
            }         
            for (int ii = 0; ii < problems.size(); ii++)
            {
                string strr = problems.at(ii);
                const char* cstr = strr.c_str();
                char* expression = new char[strlen(cstr) + 1];
                strcpy(expression, cstr);
            
                Assert::AreEqual(isExpressionValid(expression), 1);
            }          
		}
        TEST_METHOD(TestMethod2)
        {
            srand(time(NULL));
            int numProblems=5, maxNumber=5;
            vector<char> operators;
            bool hasParentheses=1, hasDecimal=1;
            string outputMethod;
            string temp = "+ -*/ ";
            for (char ch : temp) {
                operators.push_back(ch);
            }
            vector<string> problems;
            for (int i = 0; i < numProblems; ++i) {
                problems.push_back(generateProblem(maxNumber, operators, hasParentheses, hasDecimal));
            }


            for (int ii = 0; ii < problems.size(); ii++)
            {
                string strr = problems.at(ii);
                const char* cstr = strr.c_str();
                char* expression = new char[strlen(cstr) + 1];
                
                strcpy(expression, cstr);
                
                Assert::AreEqual(isExpressionValid(expression), 1);
            }
        }
        TEST_METHOD(TestMethod3)
        {
           
            srand(time(NULL));

            int numProblems = 5, maxNumber = 5;
            vector<char> operators;
            bool hasParentheses = 1, hasDecimal = 1;
            string outputMethod;
            string temp = "+ -*/ ";
            for (char ch : temp) {
                operators.push_back(ch);
            }
            vector<string> problems;
            for (int i = 0; i < numProblems; ++i) {
                problems.push_back(generateProblem(maxNumber, operators, hasParentheses, hasDecimal));
            }
            for (int ii = 0; ii < problems.size(); ii++)
            {
                string strr = problems.at(ii);
                const char* cstr = strr.c_str();
                char* expression = new char[strlen(cstr) + 1];
               
                strcpy(expression, cstr);                
                Assert::AreEqual(isExpressionValid(expression), 1);
            }
        }
	};
}
