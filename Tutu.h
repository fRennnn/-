#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
using namespace std;

#define UserNumber 100

bool IsVip = false;
void Menu();
void gotoxy(int x,int y);

class User
{
    public:
    User();
    ~User();
    void Registers();
    void Login();
    void Save();
    void Read();
    private:
    string password;
}Us;

User user[UserNumber];//Hello
