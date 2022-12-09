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
    gotoxy(52,0);
    cout<<"Test Menu";
    gotoxy(50,1);
    for(j=0;j<6;j++)
    {
        cout<<j+1<<"-- 我是选项 "<<j+1<<endl;
        gotoxy(50,j+2);
    }
    i=getch();
    switch (i)
    {
    case '1':cout<<"I am 1"<<endl;system("pause>nul");
        break;
    case '2':cout<<"I am 2"<<endl;system("pause>nul");
        break;
    case '3':cout<<"I am 3"<<endl;system("pause>nul");
        break;
    case '4':cout<<"I am 4"<<endl;system("pause>nul");
        break;
    case '5':
    {
        if(IsVip)
        {
            cout<<"I am 5";system("pause>nul");
        }
        else
        cout<<"You are not VIP,PA! > <";system("pause>nul");
    }
        break;
    case '6':
    exit(0);
    default:
        break;
    }
    system("cls");
}