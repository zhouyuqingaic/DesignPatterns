//
// Created by zhouyuqing on 2024/6/14.
//

#ifndef DESIGNPATTERNS_FLYWEIGHTPATTERNOTHER_H
#define DESIGNPATTERNS_FLYWEIGHTPATTERNOTHER_H

#include<map>
#include<iostream>
using namespace std;

enum Ammunition{
    Missile,
    CannonBall
};

//弹体基类
class FlyWeightBody{
public:
    FlyWeightBody(string id):m_id(id){}
    virtual void move(int x,int y,int speed)=0;
    virtual void draw()=0;
    string getId(){
        return m_id;
    }
    virtual ~FlyWeightBody(){}
protected:
    string m_id; //弹体序列号
    //弹体坐标
    int m_x;
    int m_y;
};


//导弹弹体共享数据类
class MissileBody:public FlyWeightBody{
public:
    MissileBody(string id);
    virtual void move(int x,int y,int speed);
    virtual void draw();
};

//炮弹弹体共享数据类
class CannonBallBody:public FlyWeightBody{
public:
    CannonBallBody(string id);
    virtual void move(int x,int y,int speed);
    virtual void draw();
};

//弹药享元工厂
class AmmunitionBodyFactory{
public:
    FlyWeightBody* getAmmunitionBody(Ammunition ammunition);
    ~AmmunitionBodyFactory();
private:
    //享元集合
    map<Ammunition,FlyWeightBody*> m_bodyMap;
};






#endif //DESIGNPATTERNS_FLYWEIGHTPATTERNOTHER_H

/*
//使用案例

void test01(){

    //创建弹药工厂
    AmmunitionBodyFactory* ammunitionFactory=new AmmunitionBodyFactory;

    //获取导弹1
    FlyWeightBody* missile_1=ammunitionFactory->getAmmunitionBody(Missile);
    //获取导弹2
    FlyWeightBody* missile_2=ammunitionFactory->getAmmunitionBody(Missile);
    //获取导弹3
    FlyWeightBody* missile_3=ammunitionFactory->getAmmunitionBody(Missile);
    //获取导弹4
    FlyWeightBody* missile_4=ammunitionFactory->getAmmunitionBody(Missile);
    //获取炮弹1
    FlyWeightBody* canoonBall_1=ammunitionFactory->getAmmunitionBody(CannonBall);
    //获取炮弹2
    FlyWeightBody* canoonBall_2=ammunitionFactory->getAmmunitionBody(CannonBall);

    cout<<"|--------------------弹药发射------------------------|"<<endl;
    //移动并绘制导弹1
    missile_1->move(1,1,200);
    missile_1->draw();
    cout<<"----------------------------------------------------"<<endl;
    //移动并绘制导弹2
    missile_1->move(3,5,550);
    missile_1->draw();
    cout<<"----------------------------------------------------"<<endl;
    //移动并绘制导弹3
    missile_3->move(9,5,650);
    missile_3->draw();
    cout<<"----------------------------------------------------"<<endl;
    //移动并绘制导弹4
    missile_4->move(5,2,250);
    missile_4->draw();
    cout<<"----------------------------------------------------"<<endl;
    //移动并绘制炮弹1
    canoonBall_1->move(4,4,999);
    canoonBall_1->draw();
    cout<<"----------------------------------------------------"<<endl;
    //移动并绘制炮弹2
    canoonBall_2->move(8,8,1024);
    canoonBall_2->draw();
    cout<<"----------------------------------------------------"<<endl;

    //回收工厂
    delete ammunitionFactory;
}
 */