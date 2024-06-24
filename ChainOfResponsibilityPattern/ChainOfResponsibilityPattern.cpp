//
// Created by zhouyuqing on 2024/6/22.
//

#include"ChainOfResponsibilityPattern.h"

//敏感词过滤器父类
//设置指向责任链中下个过滤器
void SensitiveWorldFilterPar::setNextChain(SensitiveWorldFilterPar *next) {
    m_nextChain=next;
}


//性敏感词过滤器子类
//处理敏感词过滤请求
string SexyWorldFilter::processRequest(string str_world){
    //进行本级过滤
    cout<<"将str_world:<"<<str_world<<">中的\'性\'用\'X\'替换"<<endl;
    int pos=str_world.find("性");
    str_world.replace(pos,pos+1,"X");

    //传递给下个过滤器进行过滤
    return sendRequestToNextHandler(str_world);
}

//脏话敏感词过滤器子类
//处理敏感词过滤请求
string DirtyWorldFilter::processRequest(string str_world){
    //进行本级过滤
    cout<<"将str_world:<"<<str_world<<">中的\'脏\'用\'Z\'替换"<<endl;
    int pos=str_world.find("脏");
    str_world.replace(pos,pos+1,"Z");
    //传递给下个过滤器进行过滤
    return sendRequestToNextHandler(str_world);
}

//政治铭敏感词过滤器子类
//处理敏感词过滤请求
string PoliticsWorldFilter::processRequest(string str_world){
    //进行本级过滤
    cout<<"将str_world:<"<<str_world<<">中的\'政治\'用\'ZZ\'替换"<<endl;
    int pos=str_world.find("政治");
    str_world.replace(pos,pos+2,"ZZ");
    //传递给下个过滤器进行过滤
    return sendRequestToNextHandler(str_world);
}



