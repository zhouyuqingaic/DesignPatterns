//
// Created by zhouyuqing on 2024/6/17.
//

#ifndef DESIGNPATTERNS_BRIDGEPATTERN_H
#define DESIGNPATTERNS_BRIDGEPATTERN_H

#include<iostream>
using namespace std;

//操作系统相关图像
class ImageOS{
public:
    virtual void draw(char* pData,int iLen)=0;
    virtual ~ImageOS(){}
};

//Windows操作系统
class ImageOsWindows:public ImageOS{
public:
    void draw(char *pData, int iLen);
};
//Linux操作系统
class ImageOsLinux:public ImageOS{
public:
    void draw(char *pData, int iLen);
};
//MacOS操作系统
class ImageOsMac:public ImageOS{
public:
    void draw(char *pData, int iLen);
};

//图像文件格式相关类
class ImageFormat{
public:
    //构造函数
    ImageFormat(ImageOS* p_imageOS):m_pImageOS(p_imageOS){}
    virtual void parseFile(const char* p_fileName)=0; //根据文件名分析文件内容，每个子类因为图像文件格式不同，会有不同的读取和处理代码
    virtual ~ImageFormat(){}
protected:
    ImageOS* m_pImageOS; //委托,操作系统相关图像
};

//png格式的图像文件
class ImagePNG:public ImageFormat{
public:
    //构造函数式
    ImagePNG(ImageOS* p_ImageOS): ImageFormat(p_ImageOS){}
    virtual void parseFile(const char *p_fileName);
};

//JPG格式的图像文件
class ImageJPG:public ImageFormat{
public:
    //构造函数
    ImageJPG(ImageOS* p_ImageOS): ImageFormat(p_ImageOS){}
    virtual void parseFile(const char *p_fileName);
};

//bmp图像文件
class ImageBMP:public ImageFormat{
public:
    //构造函数
    ImageBMP(ImageOS* p_ImageOS): ImageFormat(p_ImageOS){}
    virtual void parseFile(const char *p_fileName);
};

#endif //DESIGNPATTERNS_BRIDGEPATTERN_H


/*

//使用案例
void test01(){
    //windows图像的文件操作类
    ImageOS* p_ImageOSWindows=new ImageOsWindows();
    //png图像类,用于windows系统
    ImageFormat* p_pngWindows=new ImagePNG(p_ImageOSWindows);
    p_pngWindows->parseFile("c:\\picture\\a.png");

    //Linux图像的文件操作类
    ImageOS* p_ImageOSLinux=new ImageOsLinux();
    //png图像类,用于Linux系统
    ImageFormat* p_jpgLinux=new ImageJPG(p_ImageOSLinux);
    p_jpgLinux->parseFile("/home/picture/b.jpg");

    //Mac图像的文件操作类
    ImageOS* p_ImageOSMac=new ImageOsMac();
    //png图像类,用于Linux系统
    ImageFormat* p_jpgMac=new ImageJPG(p_ImageOSMac);
    p_jpgMac->parseFile("/mac/picture/c.jpg");

}

 */