//
// Created by zhouyuqing on 2024/6/7.
//

#include "IteratorPattern.h"


//指向容器第一个元素
template<typename T>
void ContretenessIter<T>::first(){
    m_current=0; //数组容器中第一元素下标为0
}
//指向下一个元素
template<typename T>
void ContretenessIter<T>::next(){
    m_current++; //下标+1，表示数组中下一个元素
}
//是否可以继续遍历
template<typename T>
bool ContretenessIter<T>::hasNext(){
    if(m_current>=p_container->getSize())
        return false;
    return true;
}
//获取当前的元素
template<typename T>
T& ContretenessIter<T>::currentItem(){
    return p_container->getItem(m_current);
}



//创建迭代器
template<typename T>
AbstractIter<T> * ContretenessContainer<T>::createIterator(){
    //工厂模式，传递的为本容器的指针this
    return new ContretenessIter<T>(this);
}
//获取当前元素
template<typename T>
T& ContretenessContainer<T>::getItem(int index){
    return m_elem[index];
}
//容器中元素数量
template<typename T>
int ContretenessContainer<T>::getSize(){
    return 10;
}





