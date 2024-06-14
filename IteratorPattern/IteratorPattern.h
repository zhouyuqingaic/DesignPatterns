//
// Created by zhouyuqing on 2024/6/7.
//
//               ╰(✿´⌣`✿)╯♡
// 祝邸小玉年永远18岁。一笑出门去，千里落花风。
//
//

#ifndef DESIGNPATTERNS_ITERATORPATTERN_H
#define DESIGNPATTERNS_ITERATORPATTERN_H

#include<iostream>
using namespace std;

//抽象迭代器模板
template<typename T>
class AbstractIter{
public:
    virtual void first()=0; //指向容器第一个元素
    virtual void next()=0; //指向下一个元素
    virtual bool hasNext()=0; //是否可以继续遍历
    virtual T& currentItem()=0; //获取当前的元素
    virtual ~AbstractIter(){}
};

//抽象容器模板
template<typename T>
class AbstractContainer{
public:
    virtual AbstractIter<T> * createIterator()=0; //创建关于该容器的迭代器
    virtual T& getItem(int index)=0; //获取当前元素
    virtual int getSize()=0; //容器中的元素数量
    virtual ~AbstractContainer(){}
};

//具体迭代器类
template<typename T>
class ContretenessIter:public AbstractIter<T>{
public:
    ContretenessIter(AbstractContainer<T> * p_c):p_container(p_c),m_current(0){}
    //指向容器第一个元素
    virtual void first();
    //指向下一个元素
    virtual void next();
    //是否可以继续遍历
    virtual bool hasNext();
    //获取当前的元素
    virtual T& currentItem();
private:
    AbstractContainer<T> * p_container= nullptr; //容器
    int m_current; //指向容器中的当前要访问元素
};

//具体容器类
template<typename T>
class ContretenessContainer:public AbstractContainer<T>{
public:
    ContretenessContainer(){
        //将数组中元素初始化
        for(int i=0;i<10;i++)
            m_elem[i]=i;
    }
    //创建关于该容器的迭代器
    virtual AbstractIter<T> * createIterator();
    //获取当前元素
    virtual T& getItem(int index);
    //容器中的元素数量
    virtual int getSize();
private:
    //简化代码,为容器固定大小为10
    T m_elem[10];
};

#include "IteratorPattern.tpp"


/* 使用案例
void test01(){
    cout<<"start"<<endl;
    //创建容器
    AbstractContainer<int> * p_container=new ContretenessContainer<int>();
    //生成该容器的迭代器
    AbstractIter<int> * p_iter=p_container->createIterator();
    //利用迭代器遍历容器
    for(p_iter->first();p_iter->hasNext();p_iter->next())
        cout<<p_iter->currentItem()<<endl;
    //清空资源
    delete p_iter;
    delete p_container;
}

 */

#endif //DESIGNPATTERNS_ITERATORPATTERN_H
