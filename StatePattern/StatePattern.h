//
// Created by zhouyuqing on 2024/6/12.
//

#ifndef DESIGNPATTERNS_STATEPATTERN_H
#define DESIGNPATTERNS_STATEPATTERN_H

#include<iostream>
using namespace std;

//前向声明
class BigMonsterState;

//怪物类
class BigMonster{
public:
    BigMonster(int life);
    ~BigMonster();
    virtual void attacked(int power); //遭受攻击后的怪物行为
    virtual int getLife(){
        return m_life;
    }
    virtual void setLite(int life){
        m_life=life;
    }
    virtual BigMonsterState* getState(){
        return m_pState;
    }
    virtual void setState(BigMonsterState *state){
        m_pState=state;
    }
private:
    int m_life; //血量(生命值)
    BigMonsterState* m_pState; //持有状态对象
};

//怪兽状态类
class BigMonsterState{
public:
    virtual void beAttacked(int power,BigMonster *mainobj)=0; //处理怪兽所受攻击
    virtual ~BigMonsterState(){}
};

//凶悍状态类
class BigMonsterStateFierce:public BigMonsterState{
public:
    //处理怪兽所受攻击
    virtual void beAttacked(int power,BigMonster *mainobj);
};
//不安状态类
class BigMonsterStateUneasy:public BigMonsterState{
public:
    //处理怪兽所受攻击
    virtual void beAttacked(int power,BigMonster *mainobj);
};
//恐惧状态类
class BigMonsterStateFear:public BigMonsterState{
public:
    //处理怪兽所受攻击
    virtual void beAttacked(int power,BigMonster *mainobj);
};
//死亡状态类
class BigMonsterStateDead:public BigMonsterState{
public:
    //处理怪兽所受攻击
    virtual void beAttacked(int power,BigMonster *mainobj);
};


#endif //DESIGNPATTERNS_STATEPATTERN_H

/*
//使用案例
#include "StatePattern/StatePattern.h"
void test01(){
    BigMonster monster(500);
    cout<<"怪物出生，当前处于凶悍状态，500点血!"<<endl;
    monster.attacked(20);
    monster.attacked(100);
    monster.attacked(200);
    monster.attacked(170);
    monster.attacked(100);
    monster.attacked(100);
}


 */