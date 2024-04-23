//
// Created by zhouyuqing on 2024/4/22.
//

#ifndef DESIGNPATTERNS_FACTORYMETHODPATTERN_H
#define DESIGNPATTERNS_FACTORYMETHODPATTERN_H

class Monster{
public:
    Monster(int life,int magic,int attack);
    virtual ~Monster();
protected:
    int m_life;
    int m_magic;
    int m_attack;
};

class M_Undead:public Monster{
public:
    M_Undead(int life,int magic,int attack);
};

class M_Element:public Monster{
public:
    M_Element(int life,int magic,int attack);
};

class M_Mechanic:public Monster{
public:
    M_Mechanic(int life,int magic,int attack);
};

class M_ParFactory{
public:
    virtual Monster *createMonster()=0;
    virtual ~M_ParFactory();
};

class M_UndeadFactory:public M_ParFactory{
public:
    virtual Monster *createMonster();
};
class M_ElementFactory:public M_ParFactory{
public:
    virtual Monster *createMonster();
};
class M_MechanicFactory:public M_ParFactory{
public:
    virtual Monster *createMonster();
};

//使用案例
/*
void demo(){
    M_ParFactory *p_ud_fy=new M_UndeadFactory();
    Monster *pM1=p_ud_fy->createMonster();

    M_ParFactory *p_elm_fy=new M_ElementFactory();
    Monster *pM2=p_elm_fy->createMonster();

    M_ParFactory *p_mec_fy=new M_MechanicFactory();
    Monster *pM3=p_mec_fy->createMonster();

    delete p_ud_fy;
    delete p_elm_fy;
    delete p_mec_fy;

    delete pM1;
    delete pM2;
    delete pM3;
}
*/


#endif //DESIGNPATTERNS_FACTORYMETHODPATTERN_H
