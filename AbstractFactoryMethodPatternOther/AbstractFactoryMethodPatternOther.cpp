//
// Created by zhouyuqing on 2024/5/16.
//

#include "AbstractFactoryMethodPatternOther.h"

#include<iostream>

using namespace std;

//中国厂商实现3个部件
void China_Body::getName(){
    cout<<"中国厂商生产的_身体部分"<<endl;
}
void China_Clothes::getName(){
    cout<<"中国厂商生产的_衣服部分"<<endl;
}
void China_Shoes::getName(){
    cout<<"中国厂商生产的_鞋子部分"<<endl;
}

//日本厂商实现3个部件
void Japan_Body::getName(){
    cout<<"日本厂商生产的_身体部分"<<endl;
}
void Japan_Clothes::getName(){
    cout<<"日本厂商生产的_衣服部分"<<endl;
}
void Japan_Shoes::getName(){
    cout<<"日本厂商生产的_鞋子部分"<<endl;
}

//美国厂商实现3个部件
void America_Body::getName(){
    cout<<"美国厂商生产的_身体部分"<<endl;
}
void America_Clothes::getName(){
    cout<<"美国厂商生产的_衣服部分"<<endl;
}
void America_Shoes::getName(){
    cout<<"美国厂商生产的_鞋子部分"<<endl;
}

//国家工厂----------------------------
//中国工厂
Body *  China_Factory::createBody(){
    return new China_Body;
}
Clothes * China_Factory::createClothes(){
    return new China_Clothes;
}
Shoes * China_Factory::createShoes(){
    return new China_Shoes;
}
//日本工厂
Body * Japan_Factory::createBody(){
    return new Japan_Body;
}
Clothes * Japan_Factory::createClothes(){
    return new Japan_Clothes;
}
Shoes * Japan_Factory::createShoes(){
    return new Japan_Shoes;
}
//美国工厂
Body * America_Factory::createBody(){
    return new America_Body;
}
Clothes * America_Factory::createClothes(){
    return new America_Clothes;
}
Shoes * America_Factory::createShoes(){
    return new America_Shoes;
}


//芭比娃娃产品-------------------------------------
//构造函数
BarbieDoll::BarbieDoll(Body * tmpbody,Clothes * tmpclothes,Shoes * tmpshoes){
    body=tmpbody;
    clothes=tmpclothes;
    shoes=tmpshoes;
}
//组装芭比娃娃
void BarbieDoll::Assemble(){
    cout<<"成功组装一个芭比娃娃:"<<endl;
    body->getName();
    clothes->getName();
    shoes->getName();
}
