//
// Created by zhouyuqing on 2024/5/16.
//

#include "AbstractFactoryMethodPattern.h"
#include <iostream>

using namespace std;


Par_Monster::Par_Monster(int life, int magic, int attack):m_life(life),m_magic(magic),m_attack(attack){}
Par_Monster::~Par_Monster(){}

//---------------------------沼泽怪物---------------------------
//沼泽亡灵类怪物
M_Undead_Swamp::M_Undead_Swamp(int life,int magic,int attack):Par_Monster(life,magic,attack){
    cout<<"一只沼泽的亡灵类怪物来到了这个世界"<<endl;
}
//沼泽元素类怪物
M_Element_Swamp::M_Element_Swamp(int life,int magic,int attack): Par_Monster(life,magic,attack){
    cout<<"一只沼泽的元素类怪物来到了这个世界"<<endl;
}
//沼泽机械类怪物
M_Mechanic_Swamp::M_Mechanic_Swamp(int life,int magic,int attack): Par_Monster(life,magic,attack){
    cout<<"一只沼泽的机械类怪物来到了这个世界"<<endl;
}

//---------------------------山脉怪物---------------------------
//山脉亡灵类怪物
M_Undead_Mountain::M_Undead_Mountain(int life,int magic,int attack): Par_Monster(life,magic,attack){
    cout<<"一只山脉的亡灵类怪物来到了这个世界"<<endl;
}
//山脉元素类怪物
M_Element_Mountain::M_Element_Mountain(int life,int magic,int attack): Par_Monster(life,magic,attack){
    cout<<"一只山脉的元素类怪物来到了这个世界"<<endl;
}
//山脉机械类怪物
M_Mechanic_Mountain::M_Mechanic_Mountain(int life,int magic,int attack): Par_Monster(life,magic,attack){
    cout<<"一只山脉的机械类怪物来到了这个世界"<<endl;
}

//---------------------------城镇怪物---------------------------
//城镇亡灵类怪物
M_Undead_Town::M_Undead_Town(int life,int magic,int attack): Par_Monster(life,magic,attack){
    cout<<"一只城镇的亡灵类怪物来到了这个世界"<<endl;
}
//城镇元素类怪物
M_Element_Town::M_Element_Town(int life,int magic,int attack): Par_Monster(life,magic,attack){
    cout<<"一只城镇的元素类怪物来到了这个世界"<<endl;
}
//城镇机械类怪物
M_Mechanic_Town::M_Mechanic_Town(int life,int magic,int attack): Par_Monster(life,magic,attack){
    cout<<"一只城镇的机械类怪物来到了这个世界"<<endl;
}


//3个工厂代码-------------------------------------
//沼泽地区工厂
Par_Monster * M_Factory_Swamp::createMonster_Element(){
    return new M_Element_Swamp(200,80,110); //创建沼泽元素类怪物
}
Par_Monster * M_Factory_Swamp::createMonster_Mechanic(){
    return new M_Mechanic_Swamp(400,0,90); //创建沼泽机械类怪物
}
Par_Monster * M_Factory_Swamp::createMonster_Undead(){
    return new M_Undead_Swamp(300,50,120); //创建沼泽亡灵类怪物
}
//山脉地区工厂
Par_Monster * M_Factory_Mountain::createMonster_Element(){
    return new M_Element_Mountain(200,80,110); //创建山脉元素类怪物
}
Par_Monster * M_Factory_Mountain::createMonster_Mechanic(){
    return new M_Mechanic_Mountain(600,0,110); //创建山脉机械类怪物
}
Par_Monster * M_Factory_Mountain::createMonster_Undead(){
    return new M_Undead_Mountain(300,50,120); //创建山脉亡灵类怪物
}
//城镇地区工厂
Par_Monster * M_Factory_Town::createMonster_Element(){
    return new M_Element_Town(200,80,100); //创建城市元素类怪物
}
Par_Monster * M_Factory_Town::createMonster_Mechanic(){
    return new M_Mechanic_Town(400,0,110); //创建城镇元素类怪物
}
Par_Monster * M_Factory_Town::createMonster_Undead(){
    return new M_Undead_Town(300,50,80); //创建城镇亡灵类怪物
}

/*使用案例
void test01(){
    M_ParFactory * p_mountain_factory=new M_Factory_Mountain(); //山脉地区工厂
    M_ParFactory * p_town_factory=new M_Factory_Town(); //城镇地区工厂
    M_ParFactory * p_swamp_factory=new M_Factory_Swamp(); //沼泽地区工厂

    Par_Monster *pM1=p_mountain_factory->createMonster_Element(); //创建山脉地区元素类怪物
    Par_Monster *pM2=p_town_factory->createMonster_Undead(); //创建城镇地区亡灵类怪物
    Par_Monster *pM3=p_swamp_factory->createMonster_Mechanic(); //创建沼泽地区机械类怪物

    //释放资源
    //释放工厂
    delete p_mountain_factory;
    delete p_town_factory;
    delete p_swamp_factory;
    //释放怪物
    delete pM1;
    delete pM2;
    delete pM3;
}
 */



