#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include"iostream"
#include"fstream"
using namespace std;

#define SIZE 10
int scount = 0;
bool IsVip = false;//判断是不是VIP
bool ZHUANGTAI = false;//判断文件是否成功打开
void Menu();
void gotoxy(int x,int y);

class User
{
    private:
    string phone;
    string password;
    public:
    User(){};
    void Registers();
    void Login();
    void Save();
    void Read();
}us;

void CountMenu();
User user[SIZE];
