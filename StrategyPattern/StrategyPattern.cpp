//
// Created by zhouyuqing on 2024/5/19.
//

#include "StrategyPattern.h"

//战斗者父类
//构造函数
Fighter::Fighter(int life, int magic, int attack) {
    m_life=life;
    m_magic=magic;
    m_attack=attack;
}
//设置道具使用策略
void Fighter::SetItemStrategy(ItemStrategy *strategy){
    itemStrategy=strategy;
}
//使用道具
void Fighter::UserItem(){
    itemStrategy->UseItem(this);
}
//获取人物生命值
int Fighter::GetLife(){
    return m_life;
}
//设置人物生命值
void Fighter::SetLife(int life){
    m_life=life;
}

//战士类,父类Fighter
F_Warrior::F_Warrior(int life,int magic,int attack):Fighter(life,magic,attack){}
//法师类，父类Fighter
F_Mage::F_Mage(int life,int magic,int attack): Fighter(life,magic,attack){}


//补血丹策略类
void ItemStrategy_BXD::UseItem(Fighter *mainobj){
    mainobj->SetLife(mainobj->GetLife()+9); //补充200点生命值
}
//大还丹策略类
void ItemStrategy_DHD::UseItem(Fighter *mainobj){
    mainobj->SetLife(mainobj->GetLife()+30); //补充300点生命值
}
//守护丹策略类
void ItemStrategy_SHD::UseItem(Fighter *mainobj){
    mainobj->SetLife(mainobj->GetLife()+500); //补充500点生命值
}


