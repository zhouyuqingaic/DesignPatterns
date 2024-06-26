//
// Created by zhouyuqing on 2024/6/26.
//

#ifndef CPPSTART_INTERPRETPATTERN_H
#define CPPSTART_INTERPRETPATTERN_H

#include<map>
#include<stack>
#include<vector>
#include<string>
#include<cstring>
#include<iostream>

using namespace std;

//表达式父类
class Expression{
public:
    virtual ~Expression(){}
    //解析当前节点
    virtual string interpret()=0;
};

//运动方向表达式(终结符表达式)
class DirectionExpression:public Expression{
public:
    DirectionExpression(const string & direction);
    //解析当前节点
    virtual string interpret() override;
private:
    string m_direction; //运动方向
};

//运动方式表达式(终结符表达式)
class ActionExpression:public Expression{
public:
    ActionExpression(const string & action);
    //解析当前节点
    virtual string interpret() override;
private:
    string m_action; //运动方式
};

//距离表达式(终结符表达式)
class DistanceExpression:public Expression{
public:
    DistanceExpression(const string & distance);
    //解析当前节点
    virtual string interpret() override;
private:
    string m_distance; //运动距离
};

//句子表达式(非终结符表达式)
class SentenceExpression:public Expression{
public:
    SentenceExpression(Expression * direction,Expression * action,Expression * distance);
    Expression * getDirection();
    Expression * getAction();
    Expression * getDistance();
    //解析当前节点
    virtual string interpret() override;
private:
    Expression * m_direction; //运动方向
    Expression * m_action; //运动方式
    Expression * m_distance; //运动距离
};

//和表达式(非终结符表达式)
class AndExpression:public Expression{
public:
    AndExpression(Expression * left,Expression * right);
    Expression * getLeft();
    Expression * getRight();
    //解析当前节点
    virtual string interpret() override;
private:
    //左，右各有一个操作数
    Expression * m_left;
    Expression * m_right;
};

//创建语法树
Expression * analyse(const string stringExpression);

#endif //CPPSTART_INTERPRETPATTERN_H

/* 使用案例

int main(){
    string stringExpression="left walk 15 and down run 20";
    Expression * p_expression= analyse(stringExpression);
    cout<<p_expression->interpret()<<endl;

    return 0;
}

 */