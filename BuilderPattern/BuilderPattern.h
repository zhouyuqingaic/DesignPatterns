//
// Created by zhouyuqing on 2024/5/18.
//

#ifndef DESIGNPATTERNS_BUILDERPATTERN_H
#define DESIGNPATTERNS_BUILDERPATTERN_H

#include<algorithm>
#include<iostream>
#include<string>
#include<sstream>

using namespace std;

//日报中的标题部分
class DailyHeaderData{
public:
    //构造函数
    DailyHeaderData(string strDepName,string strGenDate);
    //获取部门名称
    string getDepName();
    //获取日报生成日期
    string getExportDate();
private:
    string m_strDepName;    //部门名称
    string m_strGenDate;    //日报生成日期
};
//日报中的内容部分
class DailyContentData{
public:
    //构造函数
    DailyContentData(string strContent,double spendTime);
    //获取该项工作内容描述
    string getContent();
    //完成该项工作花费的时间
    double getSpendTime();
private:
    string m_strContent;
    double m_dspendTime;
};
//日报中的结尾部分
class DailyFooterData{
public:
    //构造函数
    DailyFooterData(string strUserName);
    //获取报告人姓名
    string getUserName();
private:
    string m_strUserName;
};

//抽象构建器类(文件构建器父类)
class FileBuilder{
protected:
    string m_strResult;
public:
    virtual ~FileBuilder(){}
public:
    virtual void buildHeader(DailyHeaderData &dailyHeaderObj)=0; //拼接标题
    virtual void buildBody(vector<DailyContentData *> &vec_DailyContentObj)=0; //拼接内容主体
    virtual void buildFooter(DailyFooterData &dailyFooterObj)=0;   //拼接结尾
    void resetResult(); //重置结果
    string GetResult(); //获取结果
};


//纯文本构建器类
class TxtFileBuilder:public FileBuilder{
public:
    //拼接标题
    virtual void buildHeader(DailyHeaderData &dailyHeaderObj);
    //拼接主体
    virtual void buildBody(vector<DailyContentData *> &vec_DailyContentObj);
    //拼接结尾
    virtual void buildFooter(DailyFooterData &dailyFooterObj);
};

//XML文件构建器类
class XmlFileBuilder:public FileBuilder{
public:
    //拼接标题
    virtual void buildHeader(DailyHeaderData &dailyHeaderObj);
    //拼接主体
    virtual void buildBody(vector<DailyContentData *> &vec_DailyContentObj);
    //拼接结尾
    virtual void buildFooter(DailyFooterData &dailyFooterObj);
};


//文件构造者
class FileConstructror{
private:
    FileBuilder * m_pFileBuilder; //指向所有构建器类的父亲
public:
    //构造函数
    FileConstructror(FileBuilder *ptmpBuilder);
    //文件构造
    string Construct(DailyHeaderData &dailyHeaderObj,vector<DailyContentData *> &vec_dailyContentObj,DailyFooterData & dailyFooterObj);
};

/*

//使用案例

void test01(){
    //创建标题
    DailyHeaderData * pdhd=new DailyHeaderData("研发一部","11月1日");
    //创建主体
    DailyContentData * pdcd1=new DailyContentData("完成A项目的需求分析工作",3.5);
    DailyContentData * pdcd2=new DailyContentData("确定A项目的开发所用工具",4.5);
    vector<DailyContentData *> vec_dcd;
    vec_dcd.push_back(pdcd1);
    vec_dcd.push_back(pdcd2);
    //创建结尾
    DailyFooterData * pdfd=new DailyFooterData("姜姜");

    //创建txt文件构建器
    FileBuilder *fileBuilder=new TxtFileBuilder();
    //创建文件构造者
    FileConstructror *fileConstructror=new FileConstructror(fileBuilder);
    string result=fileConstructror->Construct(*pdhd,vec_dcd,*pdfd);

    cout<<result<<endl;

    //释放资源
    delete pdhd;
    for(vector<DailyContentData *>::iterator iter=vec_dcd.begin();iter!=vec_dcd.end();iter++){
        delete *iter;
    }
    delete pdfd;
    delete fileBuilder;
    delete fileConstructror;
}

void test02(){
    //创建标题
    DailyHeaderData * pdhd=new DailyHeaderData("研发二部","12月12日");
    //创建主体
    DailyContentData * pdcd1=new DailyContentData("完成项目B的需求分析工作",5.6);
    DailyContentData * pdcd2=new DailyContentData("完成项目B的需求分析工作",9.5);
    vector<DailyContentData *> vec_dcd;
    vec_dcd.push_back(pdcd1);
    vec_dcd.push_back(pdcd2);
    //创建结尾
    DailyFooterData * pdfd=new DailyFooterData("葱葱");

    //创建xml文件构建器
    FileBuilder *fileBuilder=new XmlFileBuilder();
    //创建文件构造者
    FileConstructror *fileConstructror=new FileConstructror(fileBuilder);
    string result=fileConstructror->Construct(*pdhd,vec_dcd,*pdfd);

    cout<<result<<endl;

    //释放资源
    delete pdhd;
    for(vector<DailyContentData *>::iterator iter=vec_dcd.begin();iter!=vec_dcd.end();iter++){
        delete *iter;
    }
    delete pdfd;
    delete fileBuilder;
    delete fileConstructror;
}

 */

#endif //DESIGNPATTERNS_BUILDERPATTERN_H
