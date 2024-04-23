//
// Created by zhouyuqing on 2024/4/21.
//

#include "TemplateMethodPattern.h"
#include<iostream>
using namespace std;

Fighter::Fighter(int life, int magic, int attack) :m_life(life),m_magic(magic),m_attack(attack){}
Fighter::~Fighter() {}
void Fighter::effect_enemy() {}
void Fighter::effect_self() {}
void Fighter::play_effect() {
    cout<<"播放技能'燃烧'的技能给玩家看"<<endl;
}
void Fighter::JN_Burn(){
    if(canUseJN()){
        effect_enemy();
        effect_self();
        play_effect();
    }else
        cout<<"不能使用燃烧技能!!!!!!!"<<endl;
}

F_Warrior::F_Warrior(int life,int magic,int attack):Fighter(life,magic,attack){}
F_Warrior::~F_Warrior(){}
void F_Warrior::effect_enemy(){
    cout<<"战士主角_让所有敌人每人失去500点生命值................"<<endl;
}
void F_Warrior::effect_self(){
    cout<<"战士主角_自身失去300点生命值"<<endl;
    m_life-=300;
}
bool F_Warrior::canUseJN(){
    if(m_life<300)
        return false;
    else
        return true;
}


F_Mage::F_Mage(int life,int magic,int attack):Fighter(life,magic,attack){}
F_Mage::~F_Mage(){}
void F_Mage::effect_enemy(){
    cout<<"法师主角_让所有敌人失去650点生命值............."<<endl;
}
void F_Mage::effect_self(){
    cout<<"法师主角_自身失去100点魔法值"<<endl;
    m_magic-=100;
}
bool F_Mage::canUseJN(){
    if(m_magic<100)
        return false;
    else
        return true;
}




