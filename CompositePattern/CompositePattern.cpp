//
// Created by zhouyuqing on 2024/6/11.
//

#include "CompositePattern.h"

//文件类
//显示名字
void File::showName(int level){
    for(int i=0;i<level;i++)
        cout<<"    ";
    cout<<"-"<<m_filename<<endl;
}
bool File::add(FileSystem * p_fileSystem){
    //文件中起始是不可添加其他文件或者目录的，这里返回false,表示添加失败
    return false;
}
bool File::remove(FileSystem * p_fileSystem){
    //文件中不包含其他文件或者目录，这里直接返回false,表示删除失败
    return false;
}
//获取目录下文件个数
int File::countNumOfFiles(){
    return 1; //文件节点，按照1计算
}
//获取目录的大小
int File::countSizeOfFiles(){
    return m_size; //返回文件节点大小
}
//设置文件节点大小
void File::setFileSize(int size){
    m_size=size;
}


//目录
//显示名字
void Dir::showName(int level){
    //1.显示对齐空格
    for(int i=0;i<level;i++)cout<<"    ";
    //2.输出本目录名
    cout<<"+"<<m_dirname<<endl;
    //3.显示层级向下走一层
    level++;
    //4.输出所有包含的子内容
    //遍历目录中的文件和子目录
    for(list<FileSystem *>::iterator iter=m_childlist.begin();iter!=m_childlist.end();iter++)
        (*iter)->showName(level);
}
//向当前目录中添加文件或者子目录
bool Dir::add(FileSystem * p_fileSystem){
    m_childlist.push_back(p_fileSystem);
    return true;
}
//从当前目录中删除文件或者子目录
bool Dir::remove(FileSystem * p_fileSystem){
    m_childlist.remove(p_fileSystem);
    return false;
}
//获取目录下文件个数
int Dir::countNumOfFiles(){
    //遍历目录中所有的文件和子目录，计算文件总数
    int num_files=0;
    for(list<FileSystem *>::iterator iter=m_childlist.begin();iter!=m_childlist.end();iter++)
        num_files+=(*iter)->countNumOfFiles();
    return num_files;
}
//获取目录的大小
int Dir::countSizeOfFiles(){
    //遍历目录中所有文件和子目录,计算文件总大小
    int size_files=0;
    for(list<FileSystem *>::iterator iter=m_childlist.begin();iter!=m_childlist.end();iter++)
        size_files+=(*iter)->countSizeOfFiles();
    return size_files;
}
//设置文件节点大小
void Dir::setFileSize(int size){} //目录没有大小，不进行任何操作




