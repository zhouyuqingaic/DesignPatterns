//
// Created by zhouyuqing on 2024/6/26.
//

#ifndef CPPSTART_INTERPRETPATTERNOTHER_H
#define CPPSTART_INTERPRETPATTERNOTHER_H

#include<iostream>
#include<map>
#include<stack>

using namespace std;

//表达式节点父类
class Expression{
public:
    Expression(int num,char sign);
    virtual ~Expression(){}
    //解析语法树当前节点
    virtual int interpret(map<char,int> var)=0;

    int m_num; //创建该对象时的一个编号，记录该对象是第几个创建的
    char m_sign; //标记该对象的类型，可能是字符v表示
};

//变量表达式(终结符表达式)
class VarExpression:public Expression{
public:
    VarExpression(const char & key,int num,char sign);
    //解析语法树当前节点
    virtual int interpret(map<char,int> var) override;
private:
    char m_key; //变量名
};

//运算符表达式(非终结符表达式)
class SymbolExpression:public Expression{
public:
    SymbolExpression(Expression * left,Expression * right,int num,int sign);
    Expression * getLeft();
    Expression * getRight();
protected:
    Expression * m_left; //左操作数
    Expression * m_right; //右操作数
};

//加法运算符表示(非终结运算符表达式)
class AddExpression:public SymbolExpression{
public:
    AddExpression(Expression * left,Expression * right,int num,char sign);
    //解析语法树当前节点
    virtual int interpret(map<char,int> var) override;
};

//减法运算符表示(非终结运算符表达式)
class SubExpression:public SymbolExpression{
public:
    SubExpression(Expression * left,Expression * right,int num,char sign);
    //解析语法树当前节点
    virtual int interpret(map<char,int> var) override;
};

//分析创建语法树(表达式树)
Expression * analyseOther(string stringExpression);

#endif //CPPSTART_INTERPRETPATTERNOTHER_H

/* 使用案例


void test01(){
    string stringExpression="a-b+c+d"; //表达式字符串
    //变量字典
    map<char,int> varmap;
    varmap.insert(make_pair('a',10)); //a=10
    varmap.insert(make_pair('b',20)); //b=20
    varmap.insert(make_pair('c',30)); //b=20
    varmap.insert(make_pair('d',40)); //b=20

    //调用analyse创建语法树
    Expression * resultExpression= analyseOther(stringExpression);
    //调用interpret获取输出结果
    int result=resultExpression->interpret(varmap);
    cout<<"字符串表达式\"a-b+c+d\"结果:"<<result<<endl;

}


 */