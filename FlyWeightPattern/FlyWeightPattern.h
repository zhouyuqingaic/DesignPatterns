//
// Created by zhouyuqing on 2024/6/13.
//

#ifndef DESIGNPATTERNS_FLYWEIGHTPATTERN_H
#define DESIGNPATTERNS_FLYWEIGHTPATTERN_H

#include<iostream>
#include<map>

using namespace std;

enum EnumColor{ //棋子颜色
    Black,
    White
};

struct Position{ //棋子位置
    int m_x;
    int m_y;
    Position(int x,int y):m_x(x),m_y(y){}
};

//棋子
class Piece{
public:
    virtual void draw(Position temppos)=0;
    virtual ~Piece(){}
};

//黑棋子
class BlackPiece:public Piece{
public:
    virtual void draw(Position tempPos);
};
//白棋子
class WhitePiece:public Piece{
public:
    virtual void draw(Position tempPos);
};

//棋子工厂
class PieceFactory{
public:
    ~PieceFactory();
    //获取享元对象，就是获取共享的棋子对象
    Piece* getFlyWeight(EnumColor tempColor);
private:
    map<EnumColor,Piece*> m_FlyWeightMap; //使用map容器来保存所有的享元对象，一共就两个享元对象
};




#endif //DESIGNPATTERNS_FLYWEIGHTPATTERN_H

/*

//使用案例
void test01(){
    PieceFactory* p_Factory=new PieceFactory();

    Piece* p_piece1=p_Factory->getFlyWeight(Black);
    p_piece1->draw(Position(2,3)); //黑子落到2，3位置

    Piece* p_piece2=p_Factory->getFlyWeight(White);
    p_piece2->draw(Position(5,5)); //白子落到5,5位置

    Piece* p_piece3=p_Factory->getFlyWeight(Black);
    p_piece3->draw(Position(4,6)); //黑子落到4，6位置

    Piece* p_piece4=p_Factory->getFlyWeight(White);
    p_piece4->draw(Position(5,7)); //白子落到5，7位置

    //释放资源
    delete p_Factory;
}

 */