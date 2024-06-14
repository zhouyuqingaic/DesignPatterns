//
// Created by zhouyuqing on 2024/4/22.
//

#include<iostream>
#include "FactoryMethodPattern.h"

using namespace std;

Monster::Monster(int life, int magic, int attack):m_life(life),m_magic(magic),m_attack(attack){}
Monster::~Monster(){}

M_Undead::M_Undead(int life, int magic, int attack): Monster(life,magic,attack){
    cout<<"一只亡灵类怪物来到了世界"<<endl;
}
M_Element::M_Element(int life, int magic, int attack): Monster(life,magic,attack) {
    cout<<"一只元素类怪物来到了世界"<<endl;
}
M_Mechanic::M_Mechanic(int life, int magic, int attack) : Monster(life,magic,attack){
    cout<<"一只机械类怪物来到了这个世界"<<endl;
}

M_ParFactory::~M_ParFactory(){}

Monster *M_UndeadFactory::createMonster() {
    return new M_Undead(300,50,80);
}

Monster *M_ElementFactory::createMonster() {
    return new M_Element(200,80,100);
}

Monster *M_MechanicFactory::createMonster() {
    return new M_Mechanic(400,0,110);
}

//创建怪物对象的全局函数
Monster * Gbl_CreateMonster(M_ParFactory * factory){
    return factory->createMonster();  //createMonster虚函数实现了多态new的行为,factory指定的具体怪物工厂类函数不同，创建的怪物对象也不同
}


