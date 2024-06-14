//
// Created by zhouyuqing on 2024/6/12.
//

#include "StatePattern.h"


//怪兽类
//构造函数,怪物初始状态为"凶悍"
BigMonster::BigMonster(int life):m_life(life){
    m_pState=new BigMonsterStateFierce();
}
//析构函数
BigMonster::~BigMonster() {
    delete m_pState;
}
//怪兽行为
void BigMonster::attacked(int power){
    int orglife=m_life; //被攻击前生命值,用于确定原本状态
    m_life-=power; //设置受到攻击后的生命值,用于确定受到攻击后的状态

    if(orglife>400){ //怪物原本处于凶悍状态
        if(m_life>400){ //状态未变
            m_pState->beAttacked(power,this); //原有状态处理攻击
        }else if(m_life>100){ //变为不安
            delete m_pState; //释放原有状态
            m_pState=new BigMonsterStateUneasy(); //怪物状态转为不安
            m_pState->beAttacked(power,this); //不安状态处理攻击
        }else if(m_life>0){ //变为恐惧
            delete m_pState; //释放原有状态
            m_pState=new BigMonsterStateFear(); //怪物状态转为害怕
            m_pState->beAttacked(power,this); //害怕状态处理攻击
        }else{ //变为死亡
            delete m_pState; //释放原有状态
            m_pState=new BigMonsterStateDead(); //怪物状态转为死亡
            m_pState->beAttacked(power,this); //死亡状态处理攻击
        }
    }else if(orglife>100){ //怪物原本处于不安状态
        if(m_life>100){ //状态未变
            m_pState->beAttacked(power,this);  //原有对象处理攻击
        }else if(m_life>0){ //变为恐惧
            delete m_pState; //释放原有状态
            m_pState=new BigMonsterStateFear(); //状态从不安变为恐惧
            m_pState->beAttacked(power,this); //恐惧状态处理攻击
        }
    }else if(orglife>0){ //怪物原本处于恐惧状态
        if(m_life>0){ //变为不安
            m_pState->beAttacked(power,this);  //原有状态处理攻击
        }else{ //变为死亡
            delete m_pState; //释放原有状态
            m_pState=new BigMonsterStateDead(); //状态从恐惧变为死亡
            m_pState->beAttacked(power,this); //死亡状态处理攻击
        }
    }else{ //怪物处于死亡状态
        m_pState->beAttacked(power,this); //原状态处理攻击
    }
}

//凶悍状态类
//处理怪兽所受攻击
void BigMonsterStateFierce::beAttacked(int power,BigMonster *mainobj){
    cout<<"<恐惧状态>:怪物受到"<<power<<"点伤害,"<<",当前生命:"<<mainobj->getLife()<<",怪物对主角进行疯狂的反击!"<<endl;
}
//不安状态类
//处理怪兽所受攻击
void BigMonsterStateUneasy::beAttacked(int power,BigMonster *mainobj){
    cout<<"<不安状态>:怪物受到"<<power<<"点伤害"<<",当前生命:"<<mainobj->getLife()<<",并对主角进行反击,怪物变得焦躁不安开始呼叫支援!"<<endl;
}
//恐惧状态类
//处理怪兽所受攻击
void BigMonsterStateFear::beAttacked(int power,BigMonster *mainobj){
    cout<<"<恐惧状态>:怪物受到"<<power<<"点伤害,"<<",当前生命:"<<mainobj->getLife()<<",怪物变得恐惧并开始逃跑!"<<endl;
}
//死亡状态类
//处理怪兽所受攻击
void BigMonsterStateDead::beAttacked(int power,BigMonster *mainobj){
    cout<<"<恐惧状态>:怪物受到"<<power<<"点伤害,"<<",当前生命:"<<mainobj->getLife()<<",已经死亡!!"<<endl;
}

