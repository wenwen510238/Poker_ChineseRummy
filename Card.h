#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <map>
#include <string.h>
#include <windows.h>
#include <algorithm>
#include <fstream>

using namespace std;

class Card{
friend ostream &operator<<( ostream &, const Card &);
private:
    map<string,int> suit;
    map<int,string> ConvertNum;
    string num[14]={"0","A","2","3","4","5","6","7","8","9","10","J","Q","K"};
    vector< pair<int,int> > player[4],CanPlay[4],screen;//︹ 计
    int TotalPoint[4],Record[4][13];

public:
    Card();
    void SetColor(int = 7);
    void Spade(string a,int n);
    void Heart(string a,int n);
    void Diamond(string a,int n);
    void Club(string a,int n);
    bool run();//祘Α
    bool decide(int a);
    void CountPoint(pair<int,int> deck,pair<int,int> deck2,int a);//癘翴计
    void FlopCard(int a);//陆礟
    void PrintScreen();
    void PrintHuman();
    //void FinalPoint();//程翴计
};
#endif
