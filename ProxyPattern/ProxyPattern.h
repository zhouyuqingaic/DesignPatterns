//
// Created by zhouyuqing on 2024/6/14.
//

#ifndef DESIGNPATTERNS_PROXYPATTERN_H
#define DESIGNPATTERNS_PROXYPATTERN_H

#include<iostream>
using namespace std;


//页面抽象类
class WebAddr{
public:
    virtual void visit()=0; //访问网站的动作
    virtual ~WebAddr(){} //析构函数
};

//购物网站
class WebAddrShopping:public WebAddr{
public:
    //执行访问网站的动作
    virtual void visit();
};

//视频网站
class WebAddrVideo:public WebAddr{
public:
    //执行访问网站的动作
    virtual void visit();
};

//网站安全代理类
class WebAddrSecurityProxy:public WebAddr{
public:
    //构造函数，设置要访问的具体网站对象
    WebAddrSecurityProxy(WebAddr* p_webAddr):mp_webaddr(p_webAddr){}
    virtual void visit();
private:
    WebAddr* mp_webaddr; //代表具体要访问的具体网站
};

#endif //DESIGNPATTERNS_PROXYPATTERN_H

/*
//使用案例

void test00(){
    //网站对象
    WebAddr* web_s=new WebAddrShopping();
    WebAddr* web_v=new WebAddrVideo();
    //创建对应代理
    WebAddr* web_a_proxy=new WebAddrSecurityProxy(web_s);
    WebAddr* web_b_proxy=new WebAddrSecurityProxy(web_v);
    //使用代理访问网站
    web_a_proxy->visit();
    cout<<"-------------------------------------------------------"<<endl;
    web_b_proxy->visit();
    //资源释放
    delete web_s;
    delete web_v;

}

 */
