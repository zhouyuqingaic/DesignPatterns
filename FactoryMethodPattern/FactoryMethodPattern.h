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

Monster * Gbl_CreateMonster(M_ParFactory * factory);


/*使用案例
void test(){
    M_ParFactory * p_ud_fy=new M_UndeadFactory(); //亡灵工厂
    Monster *pM1= Gbl_CreateMonster(p_ud_fy); //生产一只亡灵类怪物

    M_ParFactory * p_elm_fy=new M_ElementFactory(); //元素工厂
    Monster *pM2= Gbl_CreateMonster(p_elm_fy); //生产一只元素怪物

    M_ParFactory * p_mec_fy=new M_MechanicFactory(); //机械工厂
    Monster *pM3= Gbl_CreateMonster(p_mec_fy); //生产一只机械怪物

    //释放资源
    //释放工厂
    delete p_ud_fy;
    delete p_elm_fy;
    delete p_mec_fy;

    //释放怪物
    delete pM1;
    delete pM2;
    delete pM3;
}
 */


#endif //DESIGNPATTERNS_FACTORYMETHODPATTERN_H
