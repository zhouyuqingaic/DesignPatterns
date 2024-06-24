//
// Created by zhouyuqing on 2024/6/15.
//

#ifndef DESIGNPATTERNS_ADAPTERPATTERNOTHER_H
#define DESIGNPATTERNS_ADAPTERPATTERNOTHER_H


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

//数据库日志接口
class LogToDatabase{
public:
    virtual void initDb()=0;
    virtual void writeToDb(const char* p_content)=0;
    virtual void readFromDb()=0;
    virtual void closeDb()=0;
};

//数据库日志适配器
class LogAdapterToDatabase:public LogToDatabase,private LogToFile{
    virtual void initDb();
    virtual void writeToDb(const char* p_content);
    virtual void readFromDb();
    virtual void closeDb();
};

#endif

/*

//使用案例
void test01(){
    cout<<"-------------------数据库崩溃，使用日志数据库适配器--------------------------"<<endl;

    //创建文件日志
    LogToDatabase* p_logToDatabase=new LogAdapterToDatabase();
    //创建 数据库日志 适配器
    p_logToDatabase->initDb();
    p_logToDatabase->writeToDb("使用数据库日志记录数据");
    p_logToDatabase->readFromDb();
    p_logToDatabase->closeDb();
}

 */