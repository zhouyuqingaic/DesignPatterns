//
// Created by zhouyuqing on 2024/5/18.
//

#include "BuilderPattern.h"

//日报中的标题部分
//构造函数
DailyHeaderData::DailyHeaderData(string strDepName,string strGenDate):m_strDepName(strDepName),m_strGenDate(strGenDate){}
//获取部门名称
string DailyHeaderData::getDepName(){
    return m_strDepName;
}
//获取日报生成日期
string DailyHeaderData::getExportDate(){
    return m_strGenDate;
}

//日报中的内容部分
//构造函数
DailyContentData::DailyContentData(string strContent,double spendTime):m_strContent(strContent),m_dspendTime(spendTime){}
//获取该项工作内容描述
string DailyContentData::getContent(){
    return m_strContent;
}
//完成该项工作花费的时间
double DailyContentData::getSpendTime(){
    return m_dspendTime;
}

//日报中的结尾部分
//构造函数
DailyFooterData::DailyFooterData(string strUserName):m_strUserName(strUserName){}
//获取报告人姓名
string DailyFooterData::getUserName(){
    return m_strUserName;
}

//抽象构建器类(文件构建器父类)
//重置结果
void FileBuilder::resetResult(){
    m_strResult="";
}
//获取结果
string FileBuilder::GetResult(){
    return m_strResult;
}

//纯文本构建器类
//拼接标题
void TxtFileBuilder::buildHeader(DailyHeaderData &dailyHeaderObj){
    //1.拼接标题
    m_strResult+=dailyHeaderObj.getDepName()+","+dailyHeaderObj.getExportDate()+"\n";
}
//拼接主体
void TxtFileBuilder::buildBody(vector<DailyContentData *> &vec_DailyContentObj){
    //2.拼接主体内容
    for(vector<DailyContentData *>::iterator iter=vec_DailyContentObj.begin();iter!=vec_DailyContentObj.end();iter++){
        ostringstream  oss;
        oss<<(* iter)->getSpendTime();
        m_strResult+=(*iter)->getContent()+":(花费的时间:"+oss.str()+"小时)\n";
    }
}
//拼接结尾
void TxtFileBuilder::buildFooter(DailyFooterData &dailyFooterObj){
    //3.拼接结尾
    m_strResult+="报告人:"+dailyFooterObj.getUserName()+"\n";
}

//XML文件构建器类
//拼接标题
void XmlFileBuilder::buildHeader(DailyHeaderData &dailyHeaderObj){
    m_strResult+="<?xml version=\"1.0\" encoding=\"utf-8\" ?>\n";
    m_strResult+="<DailyReport>\n";

    //1.拼接标题
    m_strResult+="   <Header>\n";
    m_strResult+="       <DepName>"+dailyHeaderObj.getDepName()+"</DepName>\n";
    m_strResult+="       <GenDate>"+dailyHeaderObj.getExportDate()+"</GenDate>\n";
    m_strResult+="   </Header>\n";

}
//拼接主体
void XmlFileBuilder::buildBody(vector<DailyContentData *> &vec_DailyContentObj){
    m_strResult+="   <Body>\n";
    for(vector<DailyContentData *>::iterator iter=vec_DailyContentObj.begin();iter!=vec_DailyContentObj.end();iter++){
        m_strResult+="       <Content>"+(*iter)->getContent()+"</Content>\n";
        ostringstream oss;
        oss<<(*iter)->getSpendTime();
        m_strResult+="       <SpendTime>"+oss.str()+"小时</SpendTime>\n";
    }
    m_strResult+="   </Body>\n";

}
//拼接结尾
void XmlFileBuilder::buildFooter(DailyFooterData &dailyFooterObj){
    m_strResult+="   <Footer>\n";
    m_strResult+="       <Username>"+dailyFooterObj.getUserName()+"</Username>\n";
    m_strResult+="   </Footer>\n";
    m_strResult+="</DailyReport>\n";
}

//文件构造者
FileConstructror::FileConstructror(FileBuilder *ptmpBuilder){ //构造函数
    m_pFileBuilder=ptmpBuilder;
}
//文件构造
string FileConstructror::Construct(DailyHeaderData &dailyHeaderObj,vector<DailyContentData *> &vec_dailyContentObj,DailyFooterData & dailyFooterObj){
    //重置结果
    m_pFileBuilder->resetResult();
    //构造者利用委托的方式把功能交给构建器完成
    m_pFileBuilder->buildHeader(dailyHeaderObj);
    m_pFileBuilder->buildBody(vec_dailyContentObj);
    m_pFileBuilder->buildFooter(dailyFooterObj);
    //返回结果
    return m_pFileBuilder->GetResult();
}


