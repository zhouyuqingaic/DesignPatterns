//
// Created by zhouyuqing on 2024/6/15.
//

#ifndef DESIGNPATTERNS_ADAPTERPATTERN_H
#define DESIGNPATTERNS_ADAPTERPATTERN_H

#include<iostream>
using namespace std;

//文件日志
class LogToFile{
public:
    void initFile();
    void writeToFile(const char* p_content);
    void readFromFile();
    void closeFile();
};

//数据库日志适配器接口
class LogToDatabaseInterface{
public:
    virtual void initDb()=0;
    virtual void writeToDb(const char* p_content)=0;
    virtual void readFromDb()=0;
    virtual void closeDb()=0;
};

//数据库日志
class LogToDatabase:public LogToDatabaseInterface{
public:
    virtual void initDb();
    virtual void writeToDb(const char* p_content);
    virtual void readFromDb();
    virtual void closeDb();
};

//数据库日志适配器(使 日志文件 适配 数据库文件)
class LogAdapterToDatabase:public LogToDatabaseInterface{
public:
    //构造函数
    LogAdapterToDatabase(LogToFile* p_LogFile);
    virtual void initDb();
    virtual void writeToDb(const char* p_content);
    virtual void readFromDb();
    virtual void closeDb();
private:
    LogToFile* m_pLogFile; //日志文件对象
};


#endif //DESIGNPATTERNS_ADAPTERPATTERN_H


/*

//使用案例
void test01(){
    //使用日志数据库
    LogToDatabaseInterface* p_logToDatabase=new LogToDatabase();
    p_logToDatabase->initDb();
    p_logToDatabase->writeToDb("使用数据库日志记录数据");
    p_logToDatabase->readFromDb();
    p_logToDatabase->closeDb();

    cout<<"-------------------数据库崩溃，使用日志数据库适配器--------------------------"<<endl;

    //创建文件日志
    LogToFile* p_logToFile=new LogToFile();
    //创建 数据库日志 适配器
    p_logToDatabase=new LogAdapterToDatabase(p_logToFile);
    p_logToDatabase->initDb();
    p_logToDatabase->writeToDb("使用数据库日志记录数据");
    p_logToDatabase->readFromDb();
    p_logToDatabase->closeDb();

}

 */
