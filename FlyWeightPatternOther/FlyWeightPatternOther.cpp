//
// Created by zhouyuqing on 2024/6/14.
//

#include"FlyWeightPatternOther.h"

//导弹弹体
//构造函数
MissileBody::MissileBody(string id) : FlyWeightBody(id){
    cout<<"正在创建<"<<id<<">导弹..."<<endl;
}
//移动
void MissileBody::move(int x, int y, int speed) {
    m_x=x;
    m_y=y;
    cout<<"导弹<"<<m_id<<">以速度:"<<speed<<"飞到了("<<x<<","<<y<<")的位置..."<<endl;
}
//绘制弹体
void MissileBody::draw() {
    cout<<"导弹<"<<m_id<<">在("<<m_x<<","<<m_y<<")的位置重绘导弹弹体..."<<endl;
}

//炮弹单体共享数据类
//构造函数
CannonBallBody::CannonBallBody(string id): FlyWeightBody(id){
        cout<<"正在创建<"<<id<<">炮弹..."<<endl;
}
//移动
void CannonBallBody::move(int x,int y,int speed){
    m_x=x;
    m_y=y;
    cout<<"炮弹<"<<m_id<<">以速度:"<<speed<<"飞到了("<<x<<","<<y<<")的位置..."<<endl;
}
//绘制炮弹
void CannonBallBody::draw(){
    cout<<"炮弹<"<<m_id<<">在("<<m_x<<","<<m_y<<")的位置重绘炮弹弹体..."<<endl;
}

//弹药享元工厂
//获取弹体
FlyWeightBody *AmmunitionBodyFactory::getAmmunitionBody(Ammunition ammunition) {
    FlyWeightBody* data= nullptr;
    //遍历容器
    for(map<Ammunition,FlyWeightBody*>::iterator iter=m_bodyMap.begin();iter!=m_bodyMap.end();iter++)
        if (iter->first == ammunition) {
            //找到指定类型的弹药
            if (iter->first == ammunition) {
                //创建导弹
                data = iter->second;
                cout << "正在复用弹药<" << data->getId() << ">..." << endl;
            }
        }
    //么有找到，则创建新的的弹药类型
    if(data== nullptr){
        if(ammunition==Missile){
            //创建导弹
            data=new MissileBody("MISSILE-1996");
            cout<<"正在复用弹药<"<<data->getId()<<">..."<<endl;
            m_bodyMap.insert(make_pair(ammunition,data));
        }else if(ammunition==CannonBall){
            //创建炮弹
            data=new CannonBallBody("CAOONBALL-1998");
            cout<<"正在复用弹药<"<<data->getId()<<">..."<<endl;
            m_bodyMap.insert(make_pair(ammunition,data));
        }else{
            //未知弹药，不作处理
        }
    }
    return data;
}
//析构函数
AmmunitionBodyFactory::~AmmunitionBodyFactory() {
    //遍历容器，清空创建出来的弹药
    for(map<Ammunition,FlyWeightBody*>::iterator iter=m_bodyMap.begin();iter!=m_bodyMap.end();iter++){
        cout<<"释放弹药<"<<iter->second->getId()<<">"<<endl;
        delete iter->second;
    }
    //清空容器
    m_bodyMap.clear();
}
