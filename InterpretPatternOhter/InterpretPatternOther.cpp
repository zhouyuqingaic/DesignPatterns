//
// Created by zhouyuqing on 2024/6/26.
//

#include "InterpretPatternOther.h"

//表达式节点父类
//构造函数
Expression::Expression(int num, char sign) :m_num(num),m_sign(sign){}

//变量表达式(终结符表达式)
//构造函数
VarExpression::VarExpression(const char &key, int num, char sign): Expression(num,sign){
    m_key=key;
}
//解析语法树当前节点
int VarExpression::interpret(map<char, int> var) {
    return var[m_key]; //返回变量对应的数值
}


//运算符操作符(非终结符表达式)
//构造函数
SymbolExpression::SymbolExpression(Expression *left, Expression *right, int num, int sign):m_left(left),m_right(right),Expression(num,sign){}
Expression *SymbolExpression::getLeft() {
    return m_left;
}
Expression *SymbolExpression::getRight() {
    return m_right;
}

//加法运算符(非终结符表达式)
//构造函数
AddExpression::AddExpression(Expression *left, Expression *right, int num, char sign): SymbolExpression(left,right,num,sign){}
//解析语法树当前节点
int AddExpression::interpret(map<char, int> var) {
    //获取左操作数
    int valLeft=m_left->interpret(var);
    //获取右操作数
    int valRight=m_right->interpret(var);
    //生成结果
    int result=valLeft+valRight;
    return result;
}

//减法运算符(非终结符表达式)
//构造函数
SubExpression::SubExpression(Expression *left, Expression *right, int num, char sign): SymbolExpression(left,right,num,sign){}
//解析语法树当前节点
int SubExpression::interpret(map<char, int> var) {
    //获取左操作数
    int valLeft=m_left->interpret(var);
    //获取右操作数
    int valRight=m_right->interpret(var);
    //生成结果
    int result=valLeft-valRight;
    return result;
}

//分析创建语法树(表达式树)
Expression * analyseOther(string stringExpression){ //stringExpression要计算结果的表达式字符串，如"a-b+c+d"
    stack<Expression *> expStack; //#include<stack> 这里用了栈这种顺序容器
    Expression * left=nullptr;
    Expression * right=nullptr;
    int icount=1;

    //循环遍历表达式字符串中的每个字符
    for(int i=0;i<stringExpression.size();i++){
        switch(stringExpression[i]){
            case '+':
                //加法运算操作符(非终结运算符)
                left=expStack.top(); //返回栈顶元素 作为左操作数
                //v代表一个变量节点
                ++i; //取下个字符 作为右操作数
                right=new VarExpression(stringExpression[i],icount++,'v');
                //运算结果压栈
                expStack.push(new AddExpression(left,right,icount++,'+'));
                break;
            case '-':
                left=expStack.top(); //返回栈顶元素 作为左操作数
                ++i; //取下个字符 作为右操作数
                right=new VarExpression(stringExpression[i],icount++,'v');
                //运算结果压栈
                expStack.push(new SubExpression(left,right,icount++,'-'));
                break;
            default:
                //变量(终结运算符)
                //变量压栈
                expStack.push(new VarExpression(stringExpression[i],icount++,'v'));

                break;
        }
    }
    Expression * expression=expStack.top(); //返回栈顶元素(语法树)
    return expression;
}




