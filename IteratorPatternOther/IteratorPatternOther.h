//
// Created by zhouyuqing on 2024/6/7.
//

#ifndef DESIGNPATTERNS_ITERATORPATTERNOTHER_H
#define DESIGNPATTERNS_ITERATORPATTERNOTHER_H

#include<iostream>
#include<vector>

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
    virtual AbstractIter<T> * createIterator(bool reverse=false)=0; //创建关于该容器的迭代器
    virtual T& getItem(int index)=0; //获取当前元素
    virtual int getSize()=0; //容器中的元素数量
    virtual ~AbstractContainer(){}
};

//链表节点
template<typename T>
class DoubleNode{
public:
    T data;
    DoubleNode * next= nullptr;
    DoubleNode * prev= nullptr;
    DoubleNode(const T &d):data(d){}
};

//双向链表容器
template<typename T>
class DoubleLinkedList:public AbstractContainer<T>{
private:
    int m_count; //链表长度
    DoubleNode<T> * m_head= nullptr; //指向头节点
    DoubleNode<T> * m_tail= nullptr; //指向尾节点
public:
    //获取index位置上元素的data(index从0开始计数)
    virtual T& getItem(int index);
    //容器中的元素数量
    virtual int getSize();
    //返回头节点
    inline DoubleNode<T> * head();
    //返回尾节点
    inline DoubleNode<T> * tail();

    DoubleNode<T> * insert(DoubleNode<T> * item,T data); //在item前插入元素
    DoubleNode<T> * pushFront(T data); //从头部插入元素
    DoubleNode<T> * pushBack(T data);  //从尾部插入元素
    void clear(); //清空链表
    virtual AbstractIter<T> * createIterator(bool reverse=false); //创建关于该容器的迭代器
};


//正向迭代器
template<typename T>
class ForwardIterator:public AbstractIter<T>{
public:
    ForwardIterator(DoubleLinkedList<T> * d_list){
        m_list=d_list;
    }
    //第一个元素
    virtual void first();
    //返回下一个元素
    virtual void next();
    //判断是否可以继续遍历
    virtual bool hasNext();
    //获取当前元素
    virtual T& currentItem();
private:
    DoubleLinkedList<T> * m_list= nullptr; //指向双链表
    DoubleNode<T> * m_current= nullptr; //指向当前元素节点
};


//逆向迭代器
template<typename T>
class ReverseIterator:public AbstractIter<T>{
public:
    ReverseIterator(DoubleLinkedList<T> * d_list){
        m_list=d_list;
    }
    //第一个元素
    virtual void first();
    //返回下一个元素
    virtual void next();
    //判断是否可以继续遍历
    virtual bool hasNext();
    //获取当前元素
    virtual T& currentItem();
private:
    DoubleLinkedList<T> * m_list= nullptr; //指向双链表
    DoubleNode<T> * m_current=nullptr; //指向当前元素节点
};

#include "IteratorPatternOther.tpp"

/*
//使用案例

int test01(){
    vector<string> name_list={
            "A10","F35","AR15","HK416","CH64","C130","C17",
            "B52","B2","F22","H2","M1A1"
    };
    DoubleLinkedList<string> d_list;
    for(int i=0;i<name_list.size();i++)
        d_list.pushBack(name_list.at(i));

    //正序遍历
    AbstractIter<string> * it=d_list.createIterator();
    cout<<"1--------------------Weapons:"<<endl;
    it->first();
    while(it->hasNext()){
        cout<<" "<<it->currentItem()<<" Uesed!"<<endl;
        it->next();
    }

    delete it; //释放迭代器

    //逆序遍历
    it=d_list.createIterator(true);
    cout<<"1--------------------Weapons:"<<endl;
    it->first();
    while(it->hasNext()){
        cout<<" "<<it->currentItem()<<" Uesed!"<<endl;
        it->next();
    }
    delete it; //释放迭代器

    d_list.clear(); //清空容器

    return 0;
}


 */

#endif

