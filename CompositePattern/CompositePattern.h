//
// Created by zhouyuqing on 2024/6/11.
//

#ifndef DESIGNPATTERNS_COMPOSITEPATTERN_H
#define DESIGNPATTERNS_COMPOSITEPATTERN_H

#include<iostream>
#include<string>
#include<list>
using namespace std;

//抽象父类
class FileSystem{
public:
    virtual void showName(int level)=0; //显示名字，level用于表示显示的层级，用于显示对齐
    virtual bool add(FileSystem * p_fileSystem)=0; //向当前目录中添加文件或者子目录
    virtual bool remove(FileSystem * p_fileSystem)=0; //从当前目录中删除文件或者子目录
    virtual int countNumOfFiles()=0; //获取目录下文件个数
    virtual int countSizeOfFiles()=0; //获取目录的大小
    virtual void setFileSize(int size)=0; //设置文件节点大小
    virtual ~FileSystem(){} //作父类时析构函数应该为虚函数
};


//文件类
class File:public FileSystem{
public:
    File(string name,int size=0):m_filename(name),m_size(size){}
    virtual void showName(int level); //显示名字，level用于表示显示的层级，用于显示对齐
    virtual bool add(FileSystem * p_fileSystem); //向当前目录中添加文件或者子目录
    virtual bool remove(FileSystem * p_fileSystem); //从当前目录中删除文件或者子目录
    virtual int countNumOfFiles(); //获取目录下文件个数
    virtual int countSizeOfFiles(); //获取目录的大小
    virtual void setFileSize(int size); //设置文件节点大小
private:
    string m_filename; //文件名
    int m_size; //文件大小
};

//目录
class Dir:public FileSystem{
public:
    Dir(string dirname):m_dirname(dirname){}
    virtual void showName(int level); //显示名字，level用于表示显示的层级，用于显示对齐
    virtual bool add(FileSystem * p_fileSystem); //向当前目录中添加文件或者子目录
    virtual bool remove(FileSystem * p_fileSystem); //从当前目录中删除文件或者子目录
    virtual int countNumOfFiles(); //获取目录下文件个数
    virtual int countSizeOfFiles(); //获取目录的大小
    virtual void setFileSize(int size); //设置文件节点大小
private:
    string m_dirname; //目录名
    list<FileSystem *> m_childlist; //目录中包含的文件或者其他目录列表
};


/*

//使用案例
 void test01(){
    //1.创建各种目录，文件对象
    FileSystem* pdir1=new Dir("Root");
    //-------------
    FileSystem* pfile1=new File("common.mk");
    pfile1->setFileSize(10);
    FileSystem* pfile2=new File("config.mk");
    pfile2->setFileSize(20);
    FileSystem* pfile3=new File("makefile");
    pfile3->setFileSize(30);
    //-------------
    FileSystem* pdir2=new Dir("app");
    FileSystem* pfile4=new File("nginx.c");
    pfile4->setFileSize(40);
    FileSystem* pfile5=new File("ngx_conf.c");
    pfile5->setFileSize(50);
    //-------------
    FileSystem* pdir3=new Dir("single");
    FileSystem* pfile6=new File("ngx_signal.c");
    pfile6->setFileSize(60);
    //-------------
    FileSystem* pdir4=new Dir("_include");
    FileSystem* pfile7=new File("ngx_func.h");
    pfile7->setFileSize(70);
    FileSystem* pfile8=new File("ngx_signal.h");
    pfile8->setFileSize(80);
    //2.构造树形目录结构
    pdir1->add(pfile1);
    pdir2->add(pfile2);
    pdir1->add(pfile3);
    //-------------
    pdir1->add(pdir2);
    pdir2->add(pfile4);
    pdir2->add(pfile5);
    //-------------
    pdir1->add(pdir3);
    pdir3->add(pfile6);
    //-------------
    pdir1->add(pdir4);
    pdir4->add(pfile7);
    pdir4->add(pfile8);

    //3.输出目录
    pdir1->showName(0);
    //4.输出文件总数
    cout<<"文件总数:"<<pdir1->countNumOfFiles()<<endl;
    //5.输出文件总大小
    cout<<"文件总大小:"<<pdir1->countSizeOfFiles()<<endl;

    //4.释放资源(按照添加顺序删除)
    delete pfile8;
    delete pfile7;
    delete pdir4;
    //-------------
    delete pfile6;
    delete pdir3;
    //-------------
    delete pfile5;
    delete pfile4;
    delete pdir2;
    //-------------
    delete pfile3;
    delete pfile2;
    delete pfile1;
    delete pdir1;
}

 */


#endif //DESIGNPATTERNS_COMPOSITEPATTERN_H
