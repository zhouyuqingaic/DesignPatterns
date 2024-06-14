//
// Created by zhouyuqing on 2024/6/14.
//

#include "ProxyPattern.h"

//购物网站类
//执行访问网站的动作
void WebAddrShopping::visit(){
    cout<<"访问WebAddrShopping购物网站"<<endl;
}
//视频网站
//执行访问网站的动作
void WebAddrVideo::visit(){
    cout<<"访问WebAddVideo视频网站"<<endl;
}

//网站安全代理类
//执行访问动作
void WebAddrSecurityProxy::visit(){
    cout<<"进行网络完环境安全扫描......"<<endl;
    mp_webaddr->visit();
    cout<<"清除用户缓存......"<<endl;
}



