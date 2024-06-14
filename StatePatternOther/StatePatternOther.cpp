//
// Created by zhouyuqing on 2024/6/12.
//

#include"StatePatternOther.h"


//怪物类
//构造函数，怪物初始状态为凶悍
SuperMonster::SuperMonster(int life):m_life(life){
    m_pState=new SuperMonsterStateFierce();
}
//析构函数
SuperMonster::~SuperMonster() {
    delete m_pState;
}
//被攻击
void SuperMonster::attacked(int power) {
    //调用当前状态处理怪物攻击
    m_pState->beAttacked(power,this);
}

//凶悍状态类
//处理怪兽所受攻击
void SuperMonsterStateFierce::beAttacked(int power,SuperMonster *mainobj){
    int orglife=mainobj->getLife(); //被攻击前生命值,用于确定原本状态
    if(orglife-power>400){ //怪物处于原本凶悍状态
        mainobj->setLife(orglife-power); //设置怪物剩余血量
        cout<<"<恐惧状态>:怪物受到"<<power<<"点伤害,"<<",当前生命:"<<mainobj->getLife()<<",怪物对主角进行疯狂的反击!"<<endl;
    }else{
        //下一状态不论是什么，只能是不安，恐惧，死亡状态之一
        //先无条件转义到不安状态中(在不安状态中会再次判断)
        delete mainobj->getState(); //删除怪物原有状态
        //设置怪物不安状态，并由不安状态处理受到攻击
        mainobj->setState(new SuperMonsterStateUneasy);
        mainobj->getState()->beAttacked(power,mainobj);
    }
}

//不安状态类
//处理怪兽所受攻击
void SuperMonsterStateUneasy::beAttacked(int power,SuperMonster *mainobj){
    int orglife=mainobj->getLife(); //被攻击前生命值,用于确定原本状态
    if(orglife-power>100){ //怪物处于原本的不安状态
        mainobj->setLife(orglife-power); //设置怪物剩余血量
        cout<<"<不安状态>:怪物受到"<<power<<"点伤害"<<",当前生命:"<<mainobj->getLife()<<",并对主角进行反击,怪物变得焦躁不安开始呼叫支援!"<<endl;
    }else{
        //下一状态不论是什么，只能是恐惧，死亡状态之一
        //先无条件转义到恐惧状态中(在不安状态中会再次判断)
        delete mainobj->getState(); //删除怪物原有状态
        //设置怪物不安状态，并由不安状态处理受到攻击
        mainobj->setState(new SuperMonsterStateFear);
        mainobj->getState()->beAttacked(power,mainobj);
    }
}

//恐惧状态类
//处理怪兽所受攻击
void SuperMonsterStateFear::beAttacked(int power,SuperMonster *mainobj){
    int orglife=mainobj->getLife(); //被攻击前生命值,用于确定原本状态
    if(orglife-power>0){ //怪物处于原本的不安状态
        mainobj->setLife(orglife-power); //设置怪物剩余血量
        cout<<"<恐惧状态>:怪物受到"<<power<<"点伤害,"<<",当前生命:"<<mainobj->getLife()<<",怪物变得恐惧并开始逃跑!"<<endl;
    }else{
        //下一状态不论是什么，只能是死亡状态
        //先无条件转义到死亡状态中(在不安状态中会再次判断)
        delete mainobj->getState(); //删除怪物原有状态
        //设置怪物死亡状态，并由不安状态处理受到攻击
        mainobj->setState(new SuperMonsterStateDead);
        mainobj->getState()->beAttacked(power,mainobj);
    }
}

//死亡状态类
//处理怪兽所受攻击
void SuperMonsterStateDead::beAttacked(int power,SuperMonster *mainobj){
    int orglife=mainobj->getLife(); //被攻击前生命值,用于确定原本状态
    //将怪物生命值减掉
    mainobj->setLife(orglife-power);
    cout<<"<恐惧状态>:怪物受到"<<power<<"点伤害,"<<",当前生命:"<<mainobj->getLife()<<",已经死亡!!"<<endl;
}

