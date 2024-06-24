//
// Created by zhouyuqing on 2024/6/24.
//

#ifndef CPPSTART_VISITORPATTERN_H
#define CPPSTART_VISITORPATTERN_H

#include<iostream>
#include<list>
using namespace std;

//前向声明
class Visitor;

//药品父类
class Medicine{
public:
    virtual ~Medicine(){}
    virtual void accept(Visitor * p_visitor)=0; //接收访问者访问
    virtual string getMedicineName()=0; //药物名称
    virtual float getPrice()=0; //药物总价格
};

//阿司匹林
class AspirinMedicine:public Medicine{
public:
    virtual void accept(Visitor * p_visitor); //接收访问者访问
    virtual string getMedicineName(); //药物名称
    virtual float getPrice(); //药物价格
};

//青霉素
class PenicilinMedicine:public Medicine{
public:
    virtual void accept(Visitor * p_visitor); //接收访问者访问
    virtual string getMedicineName(); //药物名称
    virtual float getPrice(); //药物总价格
};

//化疗药
class ChemothreapyMedicine:public Medicine{
public:
    virtual void accept(Visitor * p_visitor); //接收访问者访问
    virtual string getMedicineName(); //药物名称
    virtual float getPrice(); //药物总价格
};

//访问者父类
class Visitor{
public:
    virtual ~Visitor(){}

    virtual void visitElementAspirin(AspirinMedicine * p_aspirinMedicine)=0; //访问元素，阿司匹林
    virtual void visitElementPenicilin(PenicilinMedicine * p_penicilinMedicine)=0; //访问元素，青霉素
    virtual void visitElementChomethreapy(ChemothreapyMedicine * p_chemothreapyMedicine)=0; //访问元素，化疗药
};

//收费人员访问者子类
class VisitorCharge:public Visitor{
public:
    VisitorCharge():amount(0){}
    //访问元素，阿司匹林
    virtual void visitElementAspirin(AspirinMedicine * p_aspirinMedicine);
    //访问元素，青霉素
    virtual void visitElementPenicilin(PenicilinMedicine * p_penicilinMedicine);
    //访问元素，化疗药
    virtual void visitElementChomethreapy(ChemothreapyMedicine * p_chemothreapyMedicine);
private:
    float amount;
};

//发药人员访问子类
class VisitorDispense:public Visitor{
public:
    //访问元素，阿司匹林
    virtual void visitElementAspirin(AspirinMedicine * p_aspirinMedicine);
    //访问元素，青霉素
    virtual void visitElementPenicilin(PenicilinMedicine * p_penicilinMedicine);
    //访问元素，化疗药
    virtual void visitElementChomethreapy(ChemothreapyMedicine * p_chemothreapyMedicine);
};

//营养人员访问子类
class VisitorNutrionist:public Visitor{
public:
    //访问元素，阿司匹林
    virtual void visitElementAspirin(AspirinMedicine * p_aspirinMedicine);
    //访问元素，青霉素
    virtual void visitElementPenicilin(PenicilinMedicine * p_penicilinMedicine);
    //访问元素，化疗药
    virtual void visitElementChomethreapy(ChemothreapyMedicine * p_chemothreapyMedicine);
};

//结构对象
class ObjectStructure{
public:
    //增加药品到列表中
    void addMedicine(Medicine * p_medicine);
    //对药品列表里的所有药品进行访问
    void processAccept(Visitor * p_visitor);
private:
    list<Medicine *> m_medicineList; //药品列表
};



#endif //CPPSTART_VISITORPATTERN_H

/* 使用案例


void test(){
    //创建访问者
    Visitor * p_visitorCharge=new VisitorCharge;
    Visitor * p_visitorDispense=new VisitorDispense;
    Visitor * p_visitorNutrionist=new VisitorNutrionist;

    //创建药物
    Medicine * p_aspirinMedicine=new AspirinMedicine;
    Medicine * p_penicilinMedicine=new PenicilinMedicine;
    Medicine * p_chemothreapyMedicine=new ChemothreapyMedicine;

    //创建并初始化结构对象
    ObjectStructure * p_objectStructure=new ObjectStructure;
    //添加药物到结构对象
    p_objectStructure->addMedicine(p_aspirinMedicine);
    p_objectStructure->addMedicine(p_penicilinMedicine);
    p_objectStructure->addMedicine(p_chemothreapyMedicine);

    //药物结构对象接收收费人员访问
    p_objectStructure->processAccept(p_visitorCharge);
    //药物结构对象接收发药人员访问
    p_objectStructure->processAccept(p_visitorDispense);
    //药物结构对象接收营养人员访问
    p_objectStructure->processAccept(p_visitorNutrionist);

    //释放访问者
    delete p_visitorCharge;
    delete p_visitorDispense;
    delete p_visitorNutrionist;

    //释放药物
    delete p_aspirinMedicine;
    delete p_penicilinMedicine;
    delete p_chemothreapyMedicine;

    //释放药物结构对象
    delete p_objectStructure;
}

 */