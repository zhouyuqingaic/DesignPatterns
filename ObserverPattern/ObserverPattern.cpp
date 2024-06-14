//
// Created by zhouyuqing on 2024/5/22.
//

#include "ObserverPattern.h"

//战士类
//玩家发言
void Fighter::SayWords(string tmpContent,Notifier * notifier){
    notifier->notify(this,tmpContent);
}
//收到发言
void Fighter::RecvWords(Fighter * talker,string tmpContent){
    //显示信息
    cout<<"玩家:"<<m_iPlayerName<<" 收到了玩家:"<<talker->m_iPlayerName<<" 发送的聊天信息:"<<tmpContent<<endl;
}
//设置家族id
void Fighter::SetFamilyID(int tmpID){
    m_iFamilyID=tmpID;
}
//获取家族id
int Fighter::GetFamilyID(){
    return m_iFamilyID;
}

//聊天通知器
//将想要被通知的玩家加入家族列表
void TalkNotifier::addToList(Fighter *player) {
    int tmpfamilyid=player->GetFamilyID();
    if(tmpfamilyid!=-1){
        //玩家加入某个家族，将其加入对应家族列表
        map<int,list<Fighter *>>::iterator iter=m_familyList.find(tmpfamilyid);
        if(iter!=m_familyList.end()){
            //该家族ID存于map中
            iter->second.push_back(player); //直接把该玩家加入该家族列表
        }else{
            //该家族ID不存在于map中
            list<Fighter *> tmpplayerlist;
            //以为家族ID为key，增加条目到map中
            m_familyList.insert(make_pair(tmpfamilyid,tmpplayerlist));
            //向该家族中增加第一个玩家
            m_familyList[tmpfamilyid].push_back(player);
        }
    }
}
//将不想被通知的玩家从家族列表中删除
void TalkNotifier::removeFromList(Fighter *player) {
    int tmpfamilyid=player->GetFamilyID();
    if(tmpfamilyid!=-1){
        //玩家加入了某个家族
        map<int,list<Fighter *>>::iterator iter=m_familyList.find(tmpfamilyid);
        if(iter!=m_familyList.end()){
            //该家族ID存在于map中，则从该家族列表中删除player
            m_familyList[tmpfamilyid].remove(player);
        }
    }
}
//通知操作
void TalkNotifier::notify(Fighter *talker, string tmpContent) {
    int tmpfamilyId=talker->GetFamilyID();
    if(tmpfamilyId!=-1){
        //玩家加入了某个家族
        map<int,list<Fighter *>>::iterator iter=m_familyList.find(tmpfamilyId);
        if(iter!=m_familyList.end()){
            //该家族ID存在map，则遍历该家族list中的所有成员并通知
            for(list<Fighter *>::iterator playerIter=m_familyList[tmpfamilyId].begin();
                playerIter!=m_familyList[tmpfamilyId].end();
                ++playerIter){
                //向该家族成员发送 talker的发言tmpContent
                (* playerIter)->RecvWords(talker,tmpContent);
            }
        }
    }
}











