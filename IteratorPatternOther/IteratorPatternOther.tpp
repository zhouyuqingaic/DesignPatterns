#include"IteratorPatternOther.h"

//双向链表容器
//获取index位置上元素的data(index从0开始计数)
template<typename T>
T& DoubleLinkedList<T>::getItem(int index){
    DoubleNode<T> * currentNode=m_head;
    int count=1;
    while(currentNode!= nullptr){
        if(count<index){
            count++;
            currentNode=currentNode->next;
        }
    }
    return currentNode->data;
}
//容器中的元素数量
template<typename T>
int DoubleLinkedList<T>::getSize(){
    return m_count;
}
//返回头节点
template<typename T>
DoubleNode<T> * DoubleLinkedList<T>::head(){
    return m_head;
}
//返回尾节点
template<typename T>
DoubleNode<T> * DoubleLinkedList<T>::tail(){
    return m_tail;
}
//清空链表
template<typename T>
void DoubleLinkedList<T>::clear() {
    //链表非空
    if(m_head!=nullptr){
        DoubleNode<T> *currentNode=m_head;
        DoubleNode<T> *nextNode=currentNode->next;
        while(currentNode!= nullptr){
            delete currentNode;
            currentNode=nextNode;
            nextNode=currentNode->next;
        }
    }
}
//在item前插入元素
template<typename T>
DoubleNode<T> * DoubleLinkedList<T>::insert(DoubleNode<T> *item, T data) {
    DoubleNode<T> * node=nullptr;
    if(item==m_head){ //在头节点前插入元素，相当于插入头部
        node= pushFront(data);
    }else{ //在头结点后的元素中插入节点
        node=new DoubleNode<T>(data);
        node->next=item;
        node->prev=item->prev;
        //插入item前
        item->prev->next=node;
        item->prev=node;
        m_count++;
    }
    return node;
}
//在链表头插入元素
template<typename T>
DoubleNode<T> * DoubleLinkedList<T>::pushFront(T data) {
    DoubleNode<T> * node=new DoubleNode<T>(data);
    node->prev= nullptr;
    node->next= nullptr;

    if(m_head==nullptr){ //空链表
        m_head=m_tail=node;
    }else{ //链表非空
        node->next=m_head;
        m_head->prev=node;
        m_head=node;
    }
    m_count++;
    return node;
}
//在链表尾插入元素
template<typename T>
DoubleNode<T> *DoubleLinkedList<T>::pushBack(T data) {
    DoubleNode<T> * node=new DoubleNode<T>(data);
    node->prev= nullptr;
    node->next= nullptr;

    if(m_tail== nullptr){ //空链表
        m_head=m_tail=node;
    }else{ //链表非空
        m_tail->next=node;
        node->prev=m_tail;
        m_tail=node;
    }
    m_count++;
    return node;
}
//创建关于该链表容器的迭代器
template<typename T>
AbstractIter<T> * DoubleLinkedList<T>::createIterator(bool is_reverse){
    if(is_reverse)
        return new ReverseIterator(this);
    else
        return new ForwardIterator(this);
}

//正向迭代器
//第一个元素
template<typename T>
void ForwardIterator<T>::first(){
    m_current=m_list->head();
}
//返回下一个元素
template<typename T>
void ForwardIterator<T>::next(){
    m_current=m_current->next;
}
//判断是否可以继续遍历
template<typename T>
bool ForwardIterator<T>::hasNext(){
    return m_current!=m_list->tail()->next;
}
//获取当前元素
template<typename T>
T& ForwardIterator<T>::currentItem(){
    return m_current->data;
}

//逆向迭代器
//第一个元素
template<typename T>
void ReverseIterator<T>::first(){
    m_current=m_list->tail();
}
//返回下一个元素
template<typename T>
void ReverseIterator<T>::next(){
    m_current=m_current->prev;
}
//判断是否可以继续遍历
template<typename T>
bool ReverseIterator<T>::hasNext(){
    return m_current!=m_list->head()->prev;
}
//获取当前元素
template<typename T>
T& ReverseIterator<T>::currentItem(){
    return m_current->data;
}





