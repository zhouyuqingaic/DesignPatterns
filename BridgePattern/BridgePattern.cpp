//
// Created by zhouyuqing on 2024/6/17.
//

#include "BridgePattern.h"

//Windows操作系统
void ImageOsWindows::draw(char *pData, int iLen) {
    cout<<"在Windows操作系统下显示pData所指向的缓冲区中的图像数据"<<endl;
}
//Linux操作系统
void ImageOsLinux::draw(char *pData, int iLen){
    cout<<"在Linux操作系统下显示pData所指向的缓冲区中的图像数据"<<endl;
}
//MacOS操作系统
void ImageOsMac::draw(char *pData, int iLen){
    cout<<"在Mac操作系统下显示pData所指向的缓冲区中的图像数据"<<endl;
}


//png格式的图像文件
void ImagePNG::parseFile(const char *p_fileName){
    cout<<"开始分析png文件<"<<p_fileName<<">中的数据并将分析结果放到pData中"<<endl;
    int iLen=100;
    char *pResult=new char[iLen];
    //调用特定os的图像类显示图像
    m_pImageOS->draw(pResult,iLen);
    //释放内存
    delete pResult;
}


//jpg格式的图像文件
void ImageJPG::parseFile(const char *p_fileName){
    cout<<"开始分析jgp文件<"<<p_fileName<<">中的数据并将分析结果放到pData中"<<endl;
    int iLen=200;
    char *pResult=new char[iLen];
    //调用特定os的图像类显示图像
    m_pImageOS->draw(pResult,iLen);
    //释放内存
    delete pResult;
}

//bmp图像文件
void ImageBMP::parseFile(const char *p_fileName){
    cout<<"开始分析bmp文件<"<<p_fileName<<">中的数据并将分析结果放到pData中"<<endl;
    int iLen=300;
    char *pResult=new char[iLen];
    //调用特定os的图像类显示图像
    m_pImageOS->draw(pResult,iLen);
    //释放内存
    delete pResult;
}




