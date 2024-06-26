//
// Created by zhouyuqing on 2024/6/26.
//

#include "InterpretPattern.h"

//运动方向表达式(终结符表达式)
//构造函数
DirectionExpression::DirectionExpression(const string &direction) {
    m_direction=direction;
}
//解析语法树当前节点
string DirectionExpression::interpret() {
    if(m_direction=="up")
        return "向上";
    else if(m_direction=="down")
        return "向下";
    else if(m_direction=="left")
        return "向左";
    else if(m_direction=="right")
        return "向右";
    else
        return "运动方向错";
}

//运动方式表达式(终结符表达式)
//构造函数
ActionExpression::ActionExpression(const string &action) {
    m_action=action;
}
//解析语法树当前节点
string ActionExpression::interpret() {
    if(m_action=="walk")
        return "行走";
    else if(m_action=="run")
        return "奔跑";
    else
        return "运动方式错误";
}

//运动距离表达式(终结符表达式)
//构造函数
DistanceExpression::DistanceExpression(const string &distance) {
    m_distance=distance;
}
//解析语法树当前节点
string DistanceExpression::interpret() {
    return m_distance+"米";
}

//句子表达式(非终结符表达式)
//构造函数
SentenceExpression::SentenceExpression(Expression *direction, Expression *action, Expression *distance):m_direction(direction),
m_action(action),m_distance(distance){}
Expression *SentenceExpression::getDirection() {
    return m_direction;
}
Expression *SentenceExpression::getAction() {
    return m_action;
}
Expression *SentenceExpression::getDistance(){
    return m_distance;
}
//解析语法树当前节点
string SentenceExpression::interpret() {
    return m_direction->interpret()+m_action->interpret()+m_distance->interpret();
}

//和表达式(非终结运算符)
//构造函数
AndExpression::AndExpression(Expression *left, Expression *right):m_left(left),m_right(right){}
Expression *AndExpression::getLeft() {
    return m_left;
}
Expression *AndExpression::getRight() {
    return m_right;
}
//解析语法树当前节点
string AndExpression::interpret() {
    return m_left->interpret()+" 再 "+m_right->interpret();
}

//创建语法树
Expression * analyse(const string stringExpression){
    stack<Expression *> expressionStack;

    Expression * direction= nullptr;
    Expression * action= nullptr;
    Expression * distance= nullptr;
    Expression * left= nullptr;
    Expression * right= nullptr;

    //利用空格分割机器人运动指令，对整个指令字符串进行拆分
    char * strc=new char[strlen(stringExpression.c_str())+1];
    strcpy(strc,stringExpression.c_str());
    vector<string> resultVector;

    //空格切割字符串
    char * tempStr=strtok(strc," ");
    while(tempStr!= nullptr){
        resultVector.push_back(tempStr);
        tempStr=strtok(NULL," ");
    }
    delete[] strc;
    for(vector<string>::iterator iter=resultVector.begin();iter!=resultVector.end();iter++) {
        if ((*iter) == "and") {
            left = expressionStack.top(); //返回栈顶元素 充当 and左操作数

            ++iter;
            direction = new DirectionExpression(*iter); //运动方向

            ++iter;
            action = new ActionExpression(*iter); //运动方式

            ++iter;
            distance = new DistanceExpression(*iter); //运动距离

            right = new SentenceExpression(direction, action, distance); //and右操作数
            //构建and非终结运算符,并加入stack栈
            expressionStack.push(new AndExpression(left, right));
        } else { //当前字段为direction
            direction = new DirectionExpression(*iter); //运动方向

            ++iter;
            action = new ActionExpression(*iter); //运动方式

            ++iter;
            distance = new DistanceExpression(*iter); //运动距离
            //构建Sentence非终结运算符,并加入stack栈
            expressionStack.push(new SentenceExpression(direction, action, distance));
        }
    }

    Expression * expression=expressionStack.top(); //返回栈顶元素
    return expression;
}









