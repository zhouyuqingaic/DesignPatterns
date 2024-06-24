//
// Created by zhouyuqing on 2024/6/18.
//

#include"MediatorPattern.h"

//ui控件的父类
//ui控件发生变化后调用
void CtrlParent::changed(){
    m_pMediator->ctrlChanged(this); //通知中介者，本ui控件发生变化，所有事情让中介者对象去做
}

//普通按钮相关类
//设置按钮的启用或禁用
void Button::enable(bool sign){
    if(sign==true)
        cout<<"按钮<"<<m_caption<<">处于<开启状态>"<<endl;
    else
        cout<<"按钮<"<<m_caption<<">处于<关闭状态>"<<endl;
}

//单选按钮类
//设置单选按钮的启用或禁用
void RadioBtn::enable(bool sign){
    cout<<"单选按钮<"<<m_caption<<">无此功能"<<endl;
}
//设置单选按钮被选中或者被取消选中，被选中单选按钮中有个黑色实心圆点
void RadioBtn::selected(bool sign){
    if(sign==true)
        cout<<"单选按钮<"<<m_caption<<">处于<被选中状态>"<<endl;
    else
        cout<<"单选按钮<"<<m_caption<<">处于<取消选中状态>"<<endl;
}

//编辑框类
//设置编辑框的启用或禁用
void EditCtrl::enable(bool sign){
    if(sign==true)
        cout<<"编辑框<"<<m_caption<<">处于<启用状态>"<<endl;
    else
        cout<<"编辑框<"<<m_caption<<">处于<禁用状态>"<<endl;
}
//判断编辑框中内容是否为空
bool EditCtrl::isContentEmpty(){
    return m_content.empty();
}
void EditCtrl::setMContent(string content){
    m_content=content;
}
string EditCtrl::getContent(){
    return m_content;
}

//具体中介类
//析构函数
ConcertMediator::~ConcertMediator(){
    //释放资源
    if(m_pLogin){
        delete m_pLogin;
        m_pLogin= nullptr;
    }
    if(m_pLogout){
        delete m_pLogout;
        m_pLogout= nullptr;
    }
    if(m_pRadioBtnAccount){
        delete m_pRadioBtnAccount;
        m_pRadioBtnAccount= nullptr;
    }
    if(m_pRadioBtnTourist){
        delete m_pRadioBtnAccount;
        m_pRadioBtnAccount=nullptr;
    }
    if(m_pEditAccount){
        delete m_pEditAccount;
        m_pEditAccount=nullptr;
    }
    if(m_pEditPassword){
        delete m_pEditAccount;
        m_pEditPassword=nullptr;
    }
}
//创建ui控件
void ConcertMediator::ConcertMediator::createCtrl() {
    m_pLogin=new Button(this,"登录");
    m_pLogout=new Button(this,"退出");

    m_pRadioBtnTourist=new RadioBtn(this,"游客登录");
    m_pRadioBtnAccount=new RadioBtn(this,"账号登录");

    m_pEditAccount=new EditCtrl(this,"账号编辑框");
    m_pEditPassword=new EditCtrl(this,"密码编辑框");

    //设置ui控件状态
    m_pRadioBtnTourist->selected(true); //游客按钮选中
    m_pRadioBtnAccount->selected(false); //账号按钮取消选中

    m_pEditAccount->enable(false); //账号编辑框设置为禁用
    m_pEditPassword->enable(false); //密码编辑框设置为禁用

    m_pLogin->enable(true); //登录设置为启用
    m_pLogout->enable(false); //退出设置为启用
}
//当某个ui控件发生变化时调用该成员函数来通知中介者
void ConcertMediator::ctrlChanged(CtrlParent *p_CtrlParent){
    if(p_CtrlParent==m_pRadioBtnTourist){ //游客登录单选按钮被选中
        m_pRadioBtnAccount->selected(false);
        m_pRadioBtnTourist->selected(true);

        m_pEditAccount->enable(false);
        m_pEditPassword->enable(false);

        m_pLogin->enable(true);

    }else if(p_CtrlParent==m_pRadioBtnAccount){ //账号登录单选按钮被选中
        m_pRadioBtnAccount->selected(true);
        m_pRadioBtnTourist->selected(false);

        m_pEditAccount->enable(false);
        m_pEditPassword->enable(false);

        if(m_pEditAccount->isContentEmpty() || m_pEditAccount->isContentEmpty()){
            //账号 编辑框 或者 密码编辑框 有一个为空，则不允许登录
            m_pLogin->enable(false);
        }else{
            //登录按钮启用
            m_pLogin->enable(true);
        }
    }
    if(p_CtrlParent==m_pEditAccount || p_CtrlParent==m_pEditPassword){ //账号 或 密码 编辑框内容发生改变
        if(m_pEditAccount->isContentEmpty() || m_pEditAccount->isContentEmpty()){
            //账号 编辑框 或者 密码编辑框 有一个为空，则不允许登录
            m_pLogin->enable(false);
        }else{
            //登录按钮启用
            m_pLogin->enable(true);
        }
    }
}





