//
// Created by zhouyuqing on 2024/6/15.
//

#include "AdapterPattern.h"

//文件日志
void LogToFile::initFile(){
    cout<<"初始化:日志文件"<<endl;
}
void LogToFile::writeToFile(const char* p_content){
    cout<<"写入("<<p_content<<"):日志数据库"<<endl;
}
void LogToFile::readFromFile(){
    cout<<"读取:日志文件"<<endl;
}
void LogToFile::closeFile(){
    cout<<"保存:日志文件"<<endl;
}

//数据库日志
void LogToDatabase::initDb(){
    cout<<"初始化:日志数据库"<<endl;
}
void LogToDatabase::writeToDb(const char* p_content){
    cout<<"写入("<<p_content<<"):日志数据库"<<endl;
}
void LogToDatabase::readFromDb(){
    cout<<"读取:日志数据库"<<endl;
}
void LogToDatabase::closeDb(){
    cout<<"保存:日志数据库"<<endl;
}

//数据库日志适配器(使 日志文件 适配 数据库文件)
//构造函数
LogAdapterToDatabase::LogAdapterToDatabase(LogToFile* p_LogFile){
    m_pLogFile=p_LogFile;
}
void LogAdapterToDatabase::initDb(){
    cout<<"<LogAdapterToDatabase>适配:void initDb()"<<endl;
    m_pLogFile->initFile();
}
void LogAdapterToDatabase::writeToDb(const char* p_content){
    cout<<"<LogAdapterToDatabase>适配:void writeToDb(const char* p_content)"<<endl;
    m_pLogFile->writeToFile(p_content);
}
void LogAdapterToDatabase::readFromDb(){
    cout<<"<LogAdapterToDatabase>适配:void readFromDb()"<<endl;
    m_pLogFile->readFromFile();
}
void LogAdapterToDatabase::closeDb(){
    cout<<"<LogAdapterToDatabase>适配:void closeFile()"<<endl;
    m_pLogFile->closeFile();
}

