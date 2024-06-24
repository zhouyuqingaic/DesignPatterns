//
// Created by zhouyuqing on 2024/6/24.
//

#include "VisitorPattern.h"

//阿司匹林
//接收访问者访问
void AspirinMedicine::accept(Visitor *p_visitor) {
    p_visitor->visitElementAspirin(this);
}
//药物名称
string AspirinMedicine::getMedicineName() {
    return "阿司匹林";
}
//药物价格
float AspirinMedicine::getPrice() {
    return 11.1;
}

//青霉素
//接收访问者访问
void PenicilinMedicine::accept(Visitor *p_visitor) {
    p_visitor->visitElementPenicilin(this);
}
//药物名称
string PenicilinMedicine::getMedicineName() {
    return "青霉素";
}
//药物价格
float PenicilinMedicine::getPrice() {
    return 22.2;
}

//化疗药
//接收访问者访问
void ChemothreapyMedicine::accept(Visitor *p_visitor) {
    p_visitor->visitElementChomethreapy(this);
}
//药物名称
string ChemothreapyMedicine::getMedicineName() {
    return "化疗药";
}
//药物价格
float ChemothreapyMedicine::getPrice() {
    return 33.3;
}

//收费人员访问者子类
//访问元素，阿司匹林
void VisitorCharge::visitElementAspirin(AspirinMedicine *p_aspirinMedicine) {
    amount+=p_aspirinMedicine->getPrice();
    cout<<"收费人员累计药物:"<<p_aspirinMedicine->getPrice()<<"的价格:"<<p_aspirinMedicine->getPrice()<<",当前总价:"<<amount<<endl;
}
//访问元素，青霉素
void VisitorCharge::visitElementPenicilin(PenicilinMedicine *p_penicilinMedicine) {
    amount+=p_penicilinMedicine->getPrice();
    cout<<"收费人员累计药物:"<<p_penicilinMedicine->getPrice()<<"的价格:"<<p_penicilinMedicine->getPrice()<<",当前总价:"<<amount<<endl;
}
//访问元素，化疗药
void VisitorCharge::visitElementChomethreapy(ChemothreapyMedicine *p_chemothreapyMedicine) {
    amount+=p_chemothreapyMedicine->getPrice();
    cout<<"收费人员累计药物:"<<p_chemothreapyMedicine->getPrice()<<"的价格:"<<p_chemothreapyMedicine->getPrice()<<",当前总价:"<<amount<<endl;
}

//发药人员访问者子类
//访问元素，阿斯匹林
void VisitorDispense::visitElementAspirin(AspirinMedicine * p_aspirinMedicine){
    cout<<"发药人员分发药物:"<<p_aspirinMedicine->getMedicineName()<<",其价格:"<<p_aspirinMedicine->getPrice()<<endl;
}
//访问元素，青霉素
void VisitorDispense::visitElementPenicilin(PenicilinMedicine * p_penicilinMedicine){
    cout<<"发药人员分发药物:"<<p_penicilinMedicine->getMedicineName()<<",其价格:"<<p_penicilinMedicine->getPrice()<<endl;
}
//访问元素，化疗药
void VisitorDispense::visitElementChomethreapy(ChemothreapyMedicine *p_chemothreapyMedicine) {
    cout<<"发药人员分发药物:"<<p_chemothreapyMedicine->getMedicineName()<<",其价格:"<<p_chemothreapyMedicine->getPrice()<<endl;
}

//营养人员子类
//访问元素，阿斯匹林
void VisitorNutrionist::visitElementAspirin(AspirinMedicine * p_aspirinMedicine){
    cout<<"营养人员建议:多吃甲鱼,来促进"<<p_aspirinMedicine->getMedicineName()<<"的吸收"<<endl;
}
//访问元素，青霉素
void VisitorNutrionist::visitElementPenicilin(PenicilinMedicine * p_penicilinMedicine){
    cout<<"营养人员建议:多吃乌龟,来促进"<<p_penicilinMedicine->getMedicineName()<<"的吸收"<<endl;
}
//访问元素，化疗药
void VisitorNutrionist::visitElementChomethreapy(ChemothreapyMedicine * p_chemothreapyMedicine){
    cout<<"营养人员建议:多吃老鼠,来促进"<<p_chemothreapyMedicine->getMedicineName()<<"的吸收"<<endl;
}

//对象结构
//添加药物到药物列表中
void ObjectStructure::addMedicine(Medicine *p_medicine) {
    m_medicineList.push_back(p_medicine);
}
//访问者对药品列表中的所有药品进行访问
void ObjectStructure::processAccept(Visitor *p_visitor) {
    cout<<"\n\n|-------------------------------processAccept START-----------------------------|"<<endl;
    for(list<Medicine *>::iterator iter=m_medicineList.begin();iter!=m_medicineList.end();iter++)
        (*iter)->accept(p_visitor);
    cout<<"|_______________________________processAccept END_______________________________|\n\n"<<endl;
}

