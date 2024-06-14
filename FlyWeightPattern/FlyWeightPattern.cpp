//
// Created by zhouyuqing on 2024/6/13.
//

#include"FlyWeightPattern.h"

//黑棋子
void BlackPiece::draw(Position tempPos){ //绘制棋子
    cout<<"在位置:("<<tempPos.m_x<<","<<tempPos.m_y<<")处绘制了一个黑色棋子!"<<endl;
}
//白棋子
void WhitePiece::draw(Position tempPos){ //绘制棋子
    cout<<"在位置:("<<tempPos.m_x<<","<<tempPos.m_y<<")处绘制了一个白色棋子!"<<endl;
}

//创建棋子的工厂
//析构函数
PieceFactory::~PieceFactory(){
    //释放内存
    for(map<EnumColor,Piece*>::iterator iter=m_FlyWeightMap.begin();iter!=m_FlyWeightMap.end();++iter){
        //删除位置节点
        Piece* tempFw=iter->second;
        delete tempFw;
    }
    m_FlyWeightMap.clear();
}
//获取享元对象，就是获取共享的棋子对象
Piece* PieceFactory::getFlyWeight(EnumColor tempColor){
    auto iter=m_FlyWeightMap.find(tempColor);
    if(iter==m_FlyWeightMap.end()){
        //没有该享元对象，那就创造出来
        Piece* tempFw= nullptr;
        if(tempColor==Black) //黑子
            tempFw=new BlackPiece();
        else //白子
            tempFw=new WhitePiece();
        m_FlyWeightMap.insert(make_pair(tempColor,tempFw));
        return tempFw;
    }else{
        return iter->second;
    }
}

