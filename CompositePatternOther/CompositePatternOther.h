//
// Created by zhouyuqing on 2024/6/11.
//

#ifndef DESIGNPATTERNS_COMPOSITEPATTERNOTHER_H
#define DESIGNPATTERNS_COMPOSITEPATTERNOTHER_H

#include<string>
#include<list>

using namespace std;

//公司节点抽象类
class CompanyNode{
public:
    CompanyNode(string name):m_name(name){}
    virtual ~CompanyNode(){}
    //添加部门到公司节点
    virtual void Add(CompanyNode *pCom){}
    //展示公司节点
    virtual void Show(int depth=0){}
protected:
    string m_name;
};

//具体公司
class ConcreteCompany:public CompanyNode{
public:
    ConcreteCompany(string name): CompanyNode(name){}
    //添加部门到公司节点
    virtual void Add(CompanyNode *pCom);
    //展示公司节点
    virtual void Show(int depth=0);
private:
    //具体公司下辖公司节点列表
    list<CompanyNode *> m_listComapny;
};

//具体人事部门
class HRDepartment:public CompanyNode{
public:
    HRDepartment(string name): CompanyNode(name){}
    //展示公司节点
    virtual void Show(int depth=0);
};

//具体财财务部门
class FinanceDepartment:public CompanyNode{
public:
    FinanceDepartment(string name): CompanyNode(name){}
    //展示公司节点
    virtual void Show(int depth=0);
};




#endif //DESIGNPATTERNS_COMPOSITEPATTERNOTHER_H

/*
//使用案例
void test01(){
    //创建公司并且添加子公司
    CompanyNode* parent_company=new ConcreteCompany("AMD公司");
    CompanyNode* depart_cpu=new ConcreteCompany("AMD_CPU分公司");
    CompanyNode* depart_gpu=new ConcreteCompany("AMD_GPU分公司");
    parent_company->Add(depart_cpu);
    parent_company->Add(depart_gpu);

    //CPU分公司添加部门
    CompanyNode* hr_depart_cpu=new HRDepartment("CPU分公司的HR部门");
    CompanyNode* finance_depart_cpu=new FinanceDepartment("CPU分公司的Finance部门");
    depart_cpu->Add(hr_depart_cpu);
    depart_cpu->Add(finance_depart_cpu);

    //GPU分公司添加部门
    CompanyNode* hr_depart_gpu=new HRDepartment("GPU分公司的HR部门");
    CompanyNode* finance_depart_gpu=new FinanceDepartment("GPU分公司的Finance部门");
    depart_gpu->Add(hr_depart_gpu);
    depart_gpu->Add(finance_depart_gpu);

    //展示公司架构
    parent_company->Show();

    //释放公司节点
    //显释放叶节点
    delete hr_depart_cpu;
    delete finance_depart_cpu;
    delete hr_depart_cpu;
    delete finance_depart_cpu;
    //释放非叶节点
    delete depart_cpu;
    delete depart_gpu;
    delete parent_company;

}
 */
