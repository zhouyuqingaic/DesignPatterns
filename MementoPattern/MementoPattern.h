//
// Created by zhouyuqing on 2024/6/18.
//

#ifndef DESIGNPATTERNS_MEMENTOPATTERN_H
#define DESIGNPATTERNS_MEMENTOPATTERN_H

#include<iostream>
#include<vector>

using namespace std;

//前向声明
class Fighter;

//战士数据备忘录
class FighterMemento{
private:
    friend class Fighter; //声明友元类
    //构造函数,用private修饰放置在类外被随意创建
    FighterMemento(int life,int magic,int attack):m_life(life),m_magic(magic),m_attack(attack){}
    int getLife();
    void setLife(int life);
    int getMagic();
    void setMagic(int magic);
    int getAttack();
    void setAttack(int attack);
private:
    //战士数据
    int m_life; //生命值
    int m_magic; //魔法值
    int m_attack; //攻击力
};

//玩家主角类
class Fighter{
public:
    //构造函数
    Fighter(int life,int magic,int attack):m_life(life),m_magic(magic),m_attack(attack){}
    //创建记录当前玩家数据的备忘录对象
    FighterMemento * createFighterMemento();
    //从备忘录中恢复玩家数据
    void restoreFighterMemento(FighterMemento * pfm);
    //设置玩家死亡
    void setToDead();
    //输出玩家信息
    void displayInfo();
private:
    //角色属性
    int m_life; //生命
    int m_magic; //魔法
    int m_attack; //攻击
};

//备忘录管理类
class MementoManager{
public:
    //析构函数用于释放资源
    ~MementoManager();
    //获取指向备忘录对象的指针 index为备忘录(快照)编号
    FighterMemento * getFighterMemento(int index);
    //设置用于指向备忘录对象的指针
    void setFighterMemento(FighterMemento * p_FighterMemento);
private:
    FighterMemento * m_pFighterMemento; //指向备忘录对象的指针
    vector<FighterMemento *> m_pFighterMementoContainer; //存储备忘录指针对象的容器
};



#endif //DESIGNPATTERNS_MEMENTOPATTERN_H

/*

//使用案例

void test01(){
    //引入管理者类后
    Fighter * p_fighter=new Fighter(800,200,300); //创建玩家
    //显示玩家与Boss战斗前的状态
    p_fighter->displayInfo();

    //创建备忘录管理器
    MementoManager * p_memorandumManager=new MementoManager();
    //创建备忘录对象保存状态的第1个快照
    p_memorandumManager->setFighterMemento(p_fighter->createFighterMemento());

    //玩家与boss开始战斗
    cout<<"玩家主角与boss开始激烈的战斗-----"<<endl;
    p_fighter->setToDead(); //玩家战死
    p_fighter->displayInfo(); //显示玩家战死后数据
    //创建备忘录对象保存状态的第2个快照
    p_memorandumManager->setFighterMemento(p_fighter->createFighterMemento());

    //恢复玩家之前保存的状态
    cout<<"玩家通过备忘录对象快照0恢复自己的信息------"<<endl;
    p_fighter->restoreFighterMemento(p_memorandumManager->getFighterMemento(0));
    p_fighter->displayInfo();

    cout<<"玩家通过备忘录对象快照1恢复自己的信息------"<<endl;
    p_fighter->restoreFighterMemento(p_memorandumManager->getFighterMemento(1));
    p_fighter->displayInfo();


    //释放资源
    delete p_memorandumManager;
    delete p_fighter;
}

 */
