//
// Created by zhouyuqing on 2024/6/12.
//

#ifndef DESIGNPATTERNS_STATEPATTERNOTHER_H
#define DESIGNPATTERNS_STATEPATTERNOTHER_H

#include<iostream>
using namespace std;

//前向声明
class SuperMonster;


//怪兽状态类
class SuperMonsterState{
public:
    virtual void beAttacked(int power,SuperMonster *mainobj)=0; //处理怪兽所受攻击
    virtual ~SuperMonsterState(){}
};

//死亡状态类
class SuperMonsterStateDead:public SuperMonsterState{
public:
    //处理怪兽所受攻击
    virtual void beAttacked(int power,SuperMonster *mainobj);
};
//恐惧状态类
class SuperMonsterStateFear:public SuperMonsterState{
public:
    //处理怪兽所受攻击
    virtual void beAttacked(int power,SuperMonster *mainobj);
};
//不安状态类
class SuperMonsterStateUneasy:public SuperMonsterState{
public:
    //处理怪兽所受攻击
    virtual void beAttacked(int power,SuperMonster *mainobj);
};
//凶悍状态类
class SuperMonsterStateFierce:public SuperMonsterState{
public:
    //处理怪兽所受攻击
    virtual void beAttacked(int power,SuperMonster *mainobj);
};


//怪物类
class SuperMonster{
public:
    SuperMonster(int life);
    ~SuperMonster();
    virtual void attacked(int power);
    virtual int getLife(){
        return m_life;
    }
    virtual void setLife(int life){
        m_life=life;
    }
    virtual SuperMonsterState* getState(){
        return m_pState;
    }
    virtual void setState(SuperMonsterState* state){
        m_pState=state;
    }
private:
    int m_life; //血量(生命值)
    SuperMonsterState* m_pState; //持有状态对象
};




#endif //DESIGNPATTERNS_STATEPATTERNOTHER_H

/*
//使用案例

void test01(){
    SuperMonster monster(500);
    cout<<"怪物出生，当前处于凶悍状态，500点血!"<<endl;
    monster.attacked(20);
    monster.attacked(100);
    monster.attacked(200);
    monster.attacked(170);
    monster.attacked(100);
    monster.attacked(100);

}

 */
