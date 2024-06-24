//
// Created by zhouyuqing on 2024/6/18.
//

#include"MementoPattern.h"

//战士数据备忘录
int FighterMemento::getLife(){
    return m_life;
}
void FighterMemento::setLife(int life){
    m_life=life;
}
int FighterMemento::getMagic(){
    return m_magic;
}
void FighterMemento::setMagic(int magic){
    m_magic=magic;
}
int FighterMemento::getAttack(){
    return m_attack;
}
void FighterMemento::setAttack(int attack){
    m_attack=attack;
}

//玩家主角类
//创建记录当前玩家数据的备忘录对象
FighterMemento *Fighter::createFighterMemento() {
    return new FighterMemento(m_life,m_magic,m_attack);
}
//从备忘录中恢复玩家数据
void Fighter::restoreFighterMemento(FighterMemento *pfm) {
    m_life=pfm->getLife();
    m_magic=pfm->getMagic();
    m_attack=pfm->getAttack();
}
//设置玩家死亡
void Fighter::setToDead() {
    m_life=0;
}
//输出信息
void Fighter::displayInfo() {
    cout<<"当前玩家的生命值，魔法值，攻击力分别为:"<<m_life<<","<<m_attack<<","<<m_attack<<endl;
}

//管理者类
//析构函数用于释放资源
MementoManager::~MementoManager() {
    //释放所有快照
    for(vector<FighterMemento *>::iterator iter=m_pFighterMementoContainer.begin();iter!=m_pFighterMementoContainer.end();iter++)
        delete (*iter);
}
//获取指向备忘录对象的指针 index指向快照编号
FighterMemento *MementoManager::getFighterMemento(int index) {
    vector<FighterMemento *>::iterator iter=m_pFighterMementoContainer.begin();
    for(int i=0;i<index;i++){
            ++iter;
    }
    return (*iter);
}
//设置用于指向备忘录对象的指针
void MementoManager::setFighterMemento(FighterMemento *p_FighterMemento) {
    m_pFighterMementoContainer.push_back(p_FighterMemento);
}
