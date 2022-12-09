#include"Tutu.h"
void gotoxy(int x,int y)
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}
void Menu()
{
    char i=0;
    int j=0;
    gotoxy(5,0);
    cout<<"菜单";
    gotoxy(0,1);
    cout<<"1 -- 打印地图"<<endl;
    gotoxy(0,2);
    cout<<"2 -- 查询任意两个景点之间的最短路径"<<endl;
    gotoxy(0,3);
    cout<<"3 -- 查询各景点的相关信息"<<endl;
    gotoxy(0,4);
    cout<<"4 -- 查询任意两个景点之间的最短距离"<<endl;
    gotoxy(0,5);
    cout<<"5 -- 增加，删除和更新有关景点和道路信息"<<endl;
    gotoxy(0,6);
    cout<<"6 -- 退出系统"<<endl;
    i=getch();
    switch (i)
    {
    case '1':
    {
        cout<<"I am 1"<<endl;
        system("pause>nul");
    }break;
    case '2':
    {
        cout<<"I am 2"<<endl;
        system("pause>nul");
    }break;
    case '3':
    {
        cout<<"I am 3"<<endl;
        system("pause>nul");
    }break;
    case '4':
    {
        cout<<"I am 4"<<endl;
        system("pause>nul");
    }break;
    case '5':
    {
        if(IsVip)
        {
            cout<<"I am 5";system("pause>nul");
        }
        else
        cout<<"没有权限 > <";system("pause>nul");
    }
        break;
    case '6':
    exit(0);
    default:
        break;
    }
    system("cls");
}
