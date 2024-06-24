//
// Created by zhouyuqing on 2024/6/15.
//

#include "AdapterPatternOther.h"

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

//数据库日志适配器(private继承:是has组合关系)
void LogAdapterToDatabase::initDb() {
    cout<<"<LogAdapterToDatabase>适配:void initDb()"<<endl;
    initFile(); //调用LogToFile对象的initFile();
}
void LogAdapterToDatabase::writeToDb(const char* p_content) {
    cout<<"<LogAdapterToDatabase>适配:void writeToDb(const char* p_content)"<<endl;
    writeToFile(p_content); //调用LogToFile对象的initFile();
}
void LogAdapterToDatabase::readFromDb() {
    cout<<"<LogAdapterToDatabase>适配:void readFromDb()"<<endl;
    readFromFile(); //调用LogToFile对象的readFromFile();
}
void LogAdapterToDatabase::closeDb(){
    cout<<"<LogAdapterToDatabase>适配:void closeFile()"<<endl;
    closeFile(); //调用LogToFile对象的closeFile();
}
