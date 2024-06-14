//
// Created by zhouyuqing on 2024/5/16.
//

#ifndef DESIGNPATTERNS_ABSTRACTFACTORYMETHODPATTERNOTHER_H
#define DESIGNPATTERNS_ABSTRACTFACTORYMETHODPATTERNOTHER_H

//部件抽象-------------------------------------
//身体抽象类
class Body{
public:
    virtual void getName()=0;
    virtual ~ Body(){}
};
//衣服抽象类
class Clothes{
public:
    virtual void getName()=0;
    virtual ~ Clothes(){}
};
//鞋子抽象类
class Shoes{
public:
    virtual void getName()=0;
    virtual ~Shoes(){}
};


//中国厂商实现3个部件
class China_Body:public Body{
public:
    virtual void getName();
};
class China_Clothes:public Clothes{
public:
    virtual void getName();
};
class China_Shoes:public Shoes{
public:
    virtual void getName();
};


//日本厂商实现3个部件
class Japan_Body:public Body{
public:
    virtual void getName();
};
class Japan_Clothes:public Clothes{
public:
    virtual void getName();
};
class Japan_Shoes:public Shoes{
public:
    virtual void getName();
};

//美国厂商实现3个部件
class America_Body:public Body{
public:
    virtual void getName();
};
class America_Clothes:public Clothes{
public:
    virtual void getName();
};
class America_Shoes:public Shoes{
public:
    virtual void getName();
};


//抽象工厂---------------------------
class AbstractFactory{
public:
    //所创建的部件稳定的保持这3个部件，适合用抽象工厂模式
    virtual Body * createBody()=0;  //创建身体
    virtual Clothes * createClothes()=0;    //创建衣服
    virtual Shoes * createShoes()=0;    //创建鞋子
    virtual ~AbstractFactory(){}
};


//国家工厂----------------------------
//中国工厂
class China_Factory:public AbstractFactory{
public:
    virtual Body * createBody();
    virtual Clothes * createClothes();
    virtual Shoes * createShoes();
};
//日本工厂
class Japan_Factory:public AbstractFactory{
public:
    virtual Body * createBody();
    virtual Clothes * createClothes();
    virtual Shoes * createShoes();
};
//美国工厂
class America_Factory:public AbstractFactory{
public:
    virtual Body * createBody();
    virtual Clothes * createClothes();
    virtual Shoes * createShoes();
};

//芭比娃娃产品-------------------------------------
class BarbieDoll{
public:
    //构造函数
    BarbieDoll(Body * tmpbody,Clothes * tmpclothes,Shoes * tmpshoes);
    //组装芭比娃娃
    void Assemble();
private:
    Body * body;
    Clothes * clothes;
    Shoes * shoes;
};

/* 使用案例

void test(){
    //创建第一个芭比娃娃---------------------
    //1.创建一个中国工厂
    AbstractFactory *pChinaFactory=new China_Factory();
    //2.创建中国产各种部件
    Body *pChinaBody=pChinaFactory->createBody();
    Clothes *pChinaClothes=pChinaFactory->createClothes();
    Shoes *pChinaShoes=pChinaFactory->createShoes();
    //3.创建芭比娃娃
    BarbieDoll *pbd1obj=new BarbieDoll(pChinaBody,pChinaClothes,pChinaShoes);
    pbd1obj->Assemble();

    //创建第二个芭比娃娃---------------------
    //1.创建日本工厂和美国工厂
    AbstractFactory *pJapanFactory=new Japan_Factory();
    AbstractFactory *pAmericaFactory=new America_Factory();
    //2.创建中国产身体，日本产衣服，美国产鞋子
    Body *pChinaBody2=pChinaFactory->createBody();
    Clothes *pJapanClothes=pJapanFactory->createClothes();
    Shoes *pAmericaShoes=pAmericaFactory->createShoes();
    //3.创建芭比娃娃
    BarbieDoll *pbd2obj=new BarbieDoll(pChinaBody2,pJapanClothes,pAmericaShoes);
    pbd2obj->Assemble();

    //释放内存----------------------------------------

    //删除芭比娃娃和组件
    delete pbd1obj;
    delete pChinaBody;
    delete pChinaClothes;
    delete pChinaShoes;
    delete pbd2obj;
    delete pChinaBody2;
    delete pJapanClothes;
    delete pAmericaShoes;

    //删除工厂
    delete pChinaFactory;
    delete pJapanFactory;
    delete pAmericaFactory;

}

 */

#endif //DESIGNPATTERNS_ABSTRACTFACTORYMETHODPATTERNOTHER_H
