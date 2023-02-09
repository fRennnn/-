#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include"iostream"
#include"fstream"
#include<stack>
#include<queue>
using namespace std;

#define SIZE 10
int scount = 0;
bool IsVip = false;//判断是不是VIP
bool ZHUANGTAI = false;//判断文件是否成功打开
bool UpOrDown = false;//判断用户有无上号
int Location = 0;//用户账号所在的位置
void Menu();
void gotoxy(int x,int y);

class User//用户类
{
    private:
    string password;//密码
    public:
    string phone;
    User(){};
    void Registers();
    void Login();
    void Save();
    void Read();
}us;

void CountMenu();
User user[SIZE];
