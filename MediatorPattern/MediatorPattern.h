//
// Created by zhouyuqing on 2024/6/18.
//

#ifndef DESIGNPATTERNS_MEDIATORPATTERN_H
#define DESIGNPATTERNS_MEDIATORPATTERN_H

#include<iostream>
using namespace std;

//类前向声明
class CtrlParent;

//ui界面中介者接口
class Mediator{
public:
    virtual ~Mediator(){}
    virtual void createCtrl()=0; //创建所有需要用到的ui控件
    virtual void ctrlChanged(CtrlParent* p_ctrl)=0; //某个ui空间发生变化时调用真接着对象的该函数来通知中介者
};

//ui控件的父类
class CtrlParent{
public:
    //构造函数
    CtrlParent(Mediator* p_media,string caption):m_pMediator(p_media),m_caption(caption){}
    virtual ~CtrlParent(){}
    //ui控件发生变化后调用
    virtual void changed();
    //设置ui控件启用或禁用
    virtual void enable(bool sign)=0;
protected:
    Mediator* m_pMediator; //指向中介者对象
    string m_caption; //ui控件名称
};

//普通按钮相关类
class Button:public CtrlParent{
public:
    Button(Mediator* p_mediator,string caption): CtrlParent(p_mediator,caption){}
    //设置按钮的启用或禁用
    virtual void enable(bool sign);
};

//单选按钮类
class RadioBtn:public CtrlParent{
public:
    RadioBtn(Mediator* p_mediator,string caption): CtrlParent(p_mediator,caption){}
    //设置单选按钮的启用或禁用
    virtual void enable(bool sign);
    //设置单选按钮被选中或者被取消选中，被选中单选按钮中有个黑色实心圆点
    void selected(bool sign);
};

//编辑框类
class EditCtrl:public CtrlParent{
public:
    EditCtrl(Mediator* p_mediator,string caption): CtrlParent(p_mediator,caption){}
    //设置编辑框的启用或禁用
    virtual void enable(bool sign);
    //判断编辑框中内容是否为空
    bool isContentEmpty();
    void setMContent(string content);
    string getContent();
private:
    string m_content="";
};

//具体中介类
class ConcertMediator:public Mediator{
public:
    //析构函数
    ~ConcertMediator();
    //创建ui控件
    virtual void createCtrl();
    //当某个ui控件发生变化时调用该成员函数来通知中介者
    virtual void ctrlChanged(CtrlParent *p_CtrlParent);

public:
    Button * m_pLogin=nullptr; //登录按钮
    Button * m_pLogout=nullptr; //退出按钮

    RadioBtn * m_pRadioBtnTourist=nullptr; //游客登录单选框
    RadioBtn * m_pRadioBtnAccount=nullptr; //账号登录单选框

    EditCtrl * m_pEditAccount=nullptr; //账号编辑框
    EditCtrl * m_pEditPassword=nullptr; //密码编辑框

};




#endif //DESIGNPATTERNS_MEDIATORPATTERN_H

/*

//使用案例
void test01(){
    //创建具体中介者
    Mediator* p_media=new ConcertMediator();
    //创建ui界面及控件
    p_media->createCtrl();
    cout<<"|---------------------------------------初始化完毕---------------------------------------|"<<endl;
    cout<<"----------------------------------------当<账号登录>单选按钮被按下----------------------------------------"<<endl;
    //模拟 账号登录 单选按钮被按下时，则去通知 中介者，有中介者实现 具体的逻辑处理
    ((ConcertMediator *)p_media)->m_pRadioBtnAccount->changed();
}

 */
