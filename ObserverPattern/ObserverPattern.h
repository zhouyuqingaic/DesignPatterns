//
// Created by zhouyuqing on 2024/5/22.
//

#ifndef DESIGNPATTERNS_OBSERVERPATTERN_H
#define DESIGNPATTERNS_OBSERVERPATTERN_H

#include<iostream>
#include<map>
#include<list>
using namespace std;

class Fighter;

//通知器父类
class Notifier{
public:
    virtual void addToList(Fighter * player)=0; //将要被通知的玩家加入列表
    virtual void removeFromList(Fighter * player)=0; //将不想被通知的玩家从列表中移除
    virtual void notify(Fighter * talker,string tmpContent)=0; //通知操作
    virtual ~Notifier(){};
};

//战士类
class Fighter{
private:
    int m_iPlayerID; //玩家ID,全局唯一
    string m_iPlayerName; //玩家姓名
    int m_iFamilyID; //家族ID
public:
    //构造函数
    Fighter(int tmpID,string tmpName):m_iPlayerID(tmpID),m_iPlayerName(tmpName){
        m_iFamilyID=-1; //-1表示没有加入任何家族
    }
    virtual ~Fighter(){}
    virtual void SetFamilyID(int tmpID); //设置家族id
    virtual int GetFamilyID(); //获取家族id
    virtual void SayWords(string tmpContent,Notifier * notifier); //玩家发言
    virtual void RecvWords(Fighter * talker,string tmpContent); //收到发言
};

//步兵类,父类Fighter
class F_Warrior:public Fighter{
public:
    F_Warrior(int tmpId,string tmpName): Fighter(tmpId,tmpName){} //构造函数
};

//法师类,父类Figheter
class F_Mage:public Fighter{
public:
    F_Mage(int tmpId,string tmpName): Fighter(tmpId,tmpName){} //构造函数
};

//聊天通知器
class TalkNotifier:public Notifier{
private:
    //家族成员表,map中的key表示家族ID,value代码该家族中所有玩家列表
    map<int,list<Fighter *>> m_familyList;
public:
    //聊天通知器
    virtual void addToList(Fighter *player);
    //添加玩家到家族
    virtual void removeFromList(Fighter *player);
    virtual void notify(Fighter *talker, string tmpContent);
};

/* 使用案例
void test01(){
    //创建游戏玩家
    Fighter *pplayerobj1=new F_Warrior(10,"张三");
    pplayerobj1->SetFamilyID(100);

    Fighter * pplayerobj2=new F_Warrior(20,"李四");
    pplayerobj2->SetFamilyID(100);

    Fighter * pplayerobj3=new F_Mage(30,"王五");
    pplayerobj3->SetFamilyID(100);

    Fighter * pplayerobj4=new F_Mage(50,"赵六");
    pplayerobj4->SetFamilyID(200);

    //创建通知器类
    Notifier *ptalknotify=new TalkNotifier();

    //玩家增加到家族列表中来，才能收到家族信息
    ptalknotify->addToList(pplayerobj1);
    ptalknotify->addToList(pplayerobj2);
    ptalknotify->addToList(pplayerobj3);
    ptalknotify->addToList(pplayerobj4);

    //族人发送消息,同族人都收到消息
    pplayerobj1->SayWords("全体族人立刻到沼泽地集结，准备进攻!",ptalknotify);

    cout<<"------------------------------王五不想在再收到其他族人的消息--------------------"<<endl;
    ptalknotify->removeFromList(pplayerobj3);


    pplayerobj1->SayWords("请准备打架的家伙,进攻!",ptalknotify);

    //释放资源
    delete pplayerobj1;
    delete pplayerobj2;
    delete pplayerobj3;
    delete pplayerobj4;


}

 */

#endif //DESIGNPATTERNS_OBSERVERPATTERN_H
