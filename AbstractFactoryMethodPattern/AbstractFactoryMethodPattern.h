//
// Created by zhouyuqing on 2024/5/16.
//

#ifndef DESIGNPATTERNS_ABSTRACTFACTORYMETHODPATTERN_H
#define DESIGNPATTERNS_ABSTRACTFACTORYMETHODPATTERN_H


//怪物父类
class Par_Monster{
public:
    //构造函数
    Par_Monster(int life,int magic,int attack);
    virtual ~Par_Monster();
protected:
    int m_life;
    int m_magic;
    int m_attack;
};

//---------------------------沼泽怪物---------------------------
//沼泽亡灵类怪物
class M_Undead_Swamp:public Par_Monster{
public:
    M_Undead_Swamp(int life,int magic,int attack);
};
//沼泽元素类怪物
class M_Element_Swamp:public Par_Monster{
public:
    M_Element_Swamp(int life,int magic,int attack);
};
//沼泽机械类怪物
class M_Mechanic_Swamp:public Par_Monster{
public:
    M_Mechanic_Swamp(int life,int magic,int attack);
};

//---------------------------山脉怪物---------------------------
//山脉亡灵类怪物
class M_Undead_Mountain:public Par_Monster{
public:
    M_Undead_Mountain(int life,int magic,int attack);
};
//山脉元素类怪物
class M_Element_Mountain:public Par_Monster{
public:
    M_Element_Mountain(int life,int magic,int attack);
};
//山脉机械类怪物
class M_Mechanic_Mountain:public Par_Monster{
public:
    M_Mechanic_Mountain(int life,int magic,int attack);
};

//---------------------------城镇怪物---------------------------
//城镇亡灵类怪物
class M_Undead_Town:public Par_Monster{
public:
    M_Undead_Town(int life,int magic,int attack);
};
//城镇元素类怪物
class M_Element_Town:public Par_Monster{
public:
    M_Element_Town(int life,int magic,int attack);
};
//城镇机械类怪物
class M_Mechanic_Town:public Par_Monster{
public:
    M_Mechanic_Town(int life,int magic,int attack);
};


//工厂父类
class M_ParFactory{
public:
    virtual Par_Monster * createMonster_Undead()=0; //创建亡灵类怪物
    virtual Par_Monster * createMonster_Element()=0; //创建元素类怪物
    virtual Par_Monster * createMonster_Mechanic()=0; //创建机械类怪物
    virtual ~M_ParFactory(){};
};

//3个工厂代码-------------------------------------
//沼泽地区工厂
class M_Factory_Swamp:public M_ParFactory{
public:
    Par_Monster * createMonster_Element();
    Par_Monster * createMonster_Mechanic();
    Par_Monster * createMonster_Undead();
};
//山脉地区工厂
class M_Factory_Mountain:public M_ParFactory{
public:
    Par_Monster * createMonster_Element();
    Par_Monster * createMonster_Mechanic();
    Par_Monster * createMonster_Undead();
};
//城镇地区工厂
class M_Factory_Town:public M_ParFactory{
public:
    Par_Monster * createMonster_Element();
    Par_Monster * createMonster_Mechanic();
    Par_Monster * createMonster_Undead();
};



#endif //DESIGNPATTERNS_ABSTRACTFACTORYMETHODPATTERN_H
