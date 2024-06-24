//
// Created by zhouyuqing on 2024/6/22.
//

#ifndef DESIGNPATTERNS_CHAINOFRESPONSIBILITY_H
#define DESIGNPATTERNS_CHAINOFRESPONSIBILITY_H

#include<iostream>
using namespace std;

//敏感词过滤器父类
class SensitiveWorldFilterPar{
public:
    SensitiveWorldFilterPar():m_nextChain(nullptr){}
    //设置指向责任链中下一个过滤器
    void setNextChain(SensitiveWorldFilterPar * next);
    //处理敏感词过滤请求
    virtual string processRequest(string str_world)=0;
protected:
    //找到责任链中下个对象，并把请求传递个下个对象
    string sendRequestToNextHandler(string str_world){
        //有下个责任链对象，交给下个对象处理
        if(m_nextChain!= nullptr)
            return m_nextChain->processRequest(str_world);
        //没有下个下个责任链对象，直接返回
        return str_world;
    }
private:
    SensitiveWorldFilterPar * m_nextChain;
};

//性敏感词过滤器子类
class SexyWorldFilter:public SensitiveWorldFilterPar{
public:
    string processRequest(string str_world) override;
};

//脏话敏感词过滤器子类
class DirtyWorldFilter:public SensitiveWorldFilterPar{
public:
    string processRequest(string str_world) override;
};

//政治铭敏感词过滤器子类
class PoliticsWorldFilter:public SensitiveWorldFilterPar{
public:
    string processRequest(string str_world) override;
};

#endif //DESIGNPATTERNS_CHAINOFRESPONSIBILITY_H
