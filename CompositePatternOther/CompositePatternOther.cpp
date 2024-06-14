//
// Created by zhouyuqing on 2024/6/11.
//

#include "CompositePatternOther.h"

#include<iostream>

//具体公司
//添加部门到公司节点
void ConcreteCompany::Add(CompanyNode *pCom) {
    m_listComapny.push_back(pCom);
}
//展示公司节点
void ConcreteCompany::Show(int depth) {
    //1.打印层次填充符
    for(int i=0;i<depth;i++)
        cout<<"__";
    //2.打印单亲啊公司节点名称
    cout<<m_name<<endl;
    //3.展示当前公司节点下所有下层节点
    for(list<CompanyNode *>::iterator iter=m_listComapny.begin();iter!=m_listComapny.end();iter++)
        (*iter)->Show(depth+1);
}

//具体人事部门
//展示公司节点
void HRDepartment::Show(int depth) {
    //1.打印层次填充符
    for(int i=0;i<depth;i++)
        cout<<"__";
    //2.打印当前公司节点名称
    cout<<m_name<<endl;
}

//具体财务部门
//展示公司节点
void FinanceDepartment::Show(int depth) {
    //1.打印层次填充符
    for(int i=0;i<depth;i++)
        cout<<"__";
    //2.打印当前公司节点名称
    cout<<m_name<<endl;
}
