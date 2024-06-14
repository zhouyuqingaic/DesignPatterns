//
// Created by zhouyuqing on 2024/5/19.
//

#ifndef DESIGNPATTERNS_STRATEGYPATTERN_H
#define DESIGNPATTERNS_STRATEGYPATTERN_H

class Fighter; //类前向声明

//道具策略类基类
class ItemStrategy{
public:
    virtual void UseItem(Fighter * mainobj)=0;
    virtual ~ItemStrategy(){}
};

//战斗者父类
class Fighter{
public:
    Fighter(int life,int magic,int attack);
    virtual ~Fighter(){}
    //设置道具使用策略
    void SetItemStrategy(ItemStrategy *strategy);
    //使用道具
    void UserItem();
    //获取人物生命值
    int GetLife();
    //设置人物生命值
    void SetLife(int life);
private:
    int m_life;
    int m_magic;
    int m_attack;
    ItemStrategy *itemStrategy=nullptr;
};
//战士类,父类Fighter
class F_Warrior:public Fighter{
public:
    F_Warrior(int life,int magic,int attack);
};
//法师类，父类Fighter
class F_Mage:public Fighter{
public:
    F_Mage(int life,int magic,int attack);
};

//补血丹策略类
class ItemStrategy_BXD:public ItemStrategy{
    virtual void UseItem(Fighter *mainobj);
};
//大还丹策略类
class ItemStrategy_DHD:public ItemStrategy{
public:
    virtual void UseItem(Fighter *mainobj);
};
//守护丹策略类
class ItemStrategy_SHD:public ItemStrategy{
public:
    virtual void UseItem(Fighter *mainobj);
};


/*
 使用案例:

void test01(){
    //创建主角
    Fighter * prole_war=new F_Warrior(1000,0,200);

    cout<<"猪脚当前生命值:"<<prole_war->GetLife()<<endl;

    //吃一颗补血丹
    ItemStrategy *strategy_BXD=new ItemStrategy_BXD(); //创新补血丹策略
    prole_war->SetItemStrategy(strategy_BXD); //设置补血丹策略，准备吃补血丹
    prole_war->UserItem(); //主角吃补血丹

    //吃一颗大还丹
    ItemStrategy *strategy_DHD=new ItemStrategy_DHD(); //创建大还丹策略
    prole_war->SetItemStrategy(strategy_DHD); //设置大还丹策略，准备吃大还丹
    prole_war->UserItem(); //主角吃大还丹

    //吃一颗守护丹
    ItemStrategy *strategy_SHD=new ItemStrategy_SHD(); //创建守护丹策略
    prole_war->SetItemStrategy(strategy_SHD); //设置守护丹策略，准备吃守护丹
    prole_war->UserItem(); //主角吃守护丹

    cout<<"吃完药后,猪脚当前生命值:"<<prole_war->GetLife()<<endl;

    //释放资源
    delete strategy_BXD;
    delete strategy_DHD;
    delete strategy_SHD;
    delete prole_war;

}

 */

#endif //DESIGNPATTERNS_STRATEGYPATTERN_H
