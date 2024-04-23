//
// Created by zhouyuqing on 2024/4/21.
//

#ifndef DESIGNPATTERNS_TEMPLATEMETHODPATTERN_H
#define DESIGNPATTERNS_TEMPLATEMETHODPATTERN_H

class Fighter{
public:
    Fighter(int life,int magic,int attack);
    virtual ~Fighter();
    void JN_Burn();
private:
    virtual void effect_enemy();
    virtual void effect_self();
    virtual bool canUseJN()=0;
    void play_effect();

protected:
    int m_life;
    int m_magic;
    int m_attack;
};

class F_Warrior:public Fighter{
public:
    F_Warrior(int lfe,int magic,int attack);
    ~F_Warrior();
private:
    virtual void effect_enemy() override;
    virtual void effect_self() override;
    virtual bool canUseJN() override;
};

class F_Mage:public Fighter{
public:
    F_Mage(int life,int magic,int attack);
    ~F_Mage();
private:
    virtual void effect_enemy() override;
    virtual void effect_self() override;
    virtual bool canUseJN() override;
};


//使用案例
/*
void demo(){

    Fighter *prole_war=new F_Warrior(1000,0,200);
    prole_war->JN_Burn();
    prole_war->JN_Burn();
    prole_war->JN_Burn();
    prole_war->JN_Burn();
    prole_war->JN_Burn();
    cout<<"----------------------------------------------------"<<endl;
    Fighter *prole_mag=new F_Mage(800,200,100);
    prole_mag->JN_Burn();
    prole_mag->JN_Burn();
    prole_mag->JN_Burn();
    prole_mag->JN_Burn();
    prole_mag->JN_Burn();

}
*/

#endif //DESIGNPATTERNS_TEMPLATEMETHODPATTERN_H
