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
    gotoxy(65,0);
    if(!UpOrDown)
    cout<<"当前为游客状态";
    else
    {
        cout<<"当前为管理员状态";
        gotoxy(65,1);
        cout<<"当前UID:"<<user[Location].phone;//使用隐藏密码输入会导致uid错乱
    }
    
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
    cout<<"5 -- 增加，删除和更新有关景点和道路信息";
    if(!IsVip)
    cout<<"(管理员专用)";
    else
    cout<<"(当前有权限使用)";
    gotoxy(0,6);
    cout<<"6 -- 账号系统"<<endl;
    gotoxy(0,7);
    cout<<"7 -- 退出系统"<<endl;
    
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
    {
        cout<<"I am 6"<<endl;
        CountMenu();
        //ser UID;
        //UID.Registers();
        system("pause>nul");
    }
    break;
    case '7':
    exit(0);
    default:
        break;
    }
    system("cls");
}
void CountMenu()
{
    system("cls");
    char ch;
    if(!UpOrDown)
    {
    cout<<"1-- 登录账号 "<<endl;
    cout<<"2-- 注册账号"<<endl;
    }
    cout<<"3-- 退出账号"<<endl;
    User Uid;
    while(1)
    {
        ch=getch();
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            system("cls");
            return;
        }
        if(ch=='1'||ch=='2'||ch=='3')
        {
            break;
        }
        else{
            cout<<"重新输入!"<<endl;
            system("pause<nul");
        }
    }
    switch(ch)
    {
        case '1':
        {
            if(UpOrDown)
            {
                cout<<"干什么呢?";
            }
            else
            Uid.Login();
        }
        break;
        case '2':
        {
            if(UpOrDown)
            {
                cout<<"干什么呢?";
            }
            else
            Uid.Registers();
        }
        break;
        case '3':
        {
            IsVip=false;
            UpOrDown=false;
            system("cls");
            cout<<"退出成功";
        }
    }
}
void User::Save()
{
    ofstream ofile;
    ofile.open("user.txt",ios::out);

    for(int i = 0; i<scount; i++)
    {
        ofile << user[i].phone <<endl;
        ofile << user[i].password <<endl;
    }
    ofile.close();
}
void User::Read()
{
    ifstream ifile;
    ifile.open("user.txt",ios::in);

    scount = 0;
    if(!ifile.is_open())
    {
        cout<<"文件打开失败"<<endl;
        ZHUANGTAI = false;
        return;
    }
    ZHUANGTAI = true;

    for(int i=0;!ifile.eof();i++)
    {
        ifile >> user[i].phone;
        ifile >> user[i].password;
        scount++;
    }
    scount--;
    ifile.close();
}
void User::Registers()
{
    us.Read();
    if(!ZHUANGTAI) return; //如果没有文件就退出
    string ph;
    string pword;
    string pword1;
    char ch,password0[20];
    char ch1,password1[20];
    int x = 0,x1 = 0;
    
    for(int i=scount;i<SIZE;i++)
    {
        system("cls");
        here:
        cout<<"\t\t\t请输入手机号:(输入000退出)";
        
        cin>>ph;
        
        if(ph=="000")
        {
            return;
        }

        for(int i=0;i<scount;i++)
        {
            if(ph==user[i].phone)
            {
                cout<<"用户已存在"<<endl;
                goto here;
            }
        }
        user[i].phone = ph;

        
        cout<<endl;
        cout<<"选择输入模式:"<<endl;
        cout<<"1 --显示密码输入  2 --隐藏密码输入"<<endl;

        char chose=getch();
        if(chose > '2' || chose < '0')
        {
            cout<<"请重新输入:";
            chose=getch();
        }
        
        switch(chose)
        {
            case '1':
            {
                cout<<"请输入密码:";
                cin>>pword;
                user[i].password=pword;
                cout<<"再次输入密码:";
                cin>>pword1;
                if(pword1 != user[i].password)
                {
                    cout<<"密码不一致"<<endl;
                    goto here;
                }
                else
                {
                    scount++;
                    cout<<"注册成功!"<<endl;
                    IsVip = true;
                    us.Save();
                }
                break;
            }
            case '2':
            {
                cout<<"请输入密码:";
                while((ch=_getch())!='\r'&&x<=20)
                {
                    if(ch=='\b')
                    {
                        if(x>0)
                        {
                            x--;
                            cout<<"\b \b";
                        }
                        else putchar(7);
                    }
                    else
                    {
                        password0[x++]=ch;
                        cout<<"*";
                    }
                }
                password0[x]='\0';
                cout<<endl;
                user[i].password = password0;

                cout<<"请再次输入密码:";
                while((ch1 = _getch())!= '\r' && x1 <= 20)
                {
                    if(ch1 == '\b')
                    {
                        if(x1>0)
                        {
                            x1--;
                            cout<<"\b \b";
                        }
                        else putchar(7);
                    }
                    else
                    {
                        password1[x1++] = ch1;
                        cout<<"*";
                    }
                }
                password1[x1] = '\0';
                cout<<endl;
                if(password1!= user[i].password)
                {
                    cout<<"\t\t\t密码不一致!"<<endl;
                    goto here;
                }
                else 
                {
                    scount++;
                    cout<<"\t\t\t注册成功!"<<endl;
                    us.Save();
                }
                break;
            }
        }
        char choice;
        //IsVip=true;//这是管理员账号，所以你有权限了
            cout<<"是否继续注册(Y/N)?:";
            while(1)
            {
                cin>>choice;
                if(choice =='y'||choice =='Y'||choice=='n'||choice=='N')break;
                else cout<<"请重新输入:";
            }
            if(choice == 'n'||choice == 'N')
            break;
    }
}
void User::Login()
{
    us.Read();
    string ph,pw,pword;
    char ch;
    char passwords0[20];
    int time = 0;
    int x=0;
    char chose;
    here:
    cout<<"\t\t\t请输入手机号:(输入000退出)";

    cin>>ph;
    if(ph=="000")
        {
            return;
        }
    cout<<endl;
    cout<<"选择输入模式:"<<endl;
    cout<<"1--显示密码输入 2--隐藏密码输入"<<endl;
     while(1)
    {
        chose=getch();
        if(chose=='1'||chose=='2')
        {
            break;
        }
        else{
            cout<<"重新输入!"<<endl;
            system("pause>nul");
        }
    }
    switch(chose)
    {
        case '1':
        {
            cout<<"请输入密码:";
            cin>>pword;
            for(int i=0;i<scount;i++)//检查密码是否正确
            {
                if(ph == user[i].phone && pword ==user[i].password)
                {
                    time++;
                    cout<<"登陆成功!";
                    UpOrDown = true;
                    IsVip=true;

                    Location=i;
                    return;
                }
            }
            if(time =0)
            {
                cout<<"手机号或密码错误!"<<endl;
                goto here;
            }
        }
        break;
        case '2':
        {
            cout<<"请输入密码:";
            while((ch=_getch())!='\r' && x<=20)
            {
                if(ch == '\b')
                {
                    if(x>0)
                    {
                        x--;
                        cout<<"\b \b";
                    }
                    else putchar(7);
                }
                else
                {
                    passwords0[x++]=ch;
                    cout<<"*";
                }
            }
            passwords0[x]='\0';
            cout<<endl;
        }
        break;
    } 
    for(int i=0;i<scount;i++)
            {
                if(ph==user[i].phone && passwords0 == user[i].password)//检查密码是否正确
                {
                    time++;
                    cout<<"登陆成功"<<endl;
                    UpOrDown = true;
                    IsVip=true;
                    Location=i;
                }
            }
            if(time == 0)
            {
                cout<<"手机号或者密码错误"<<endl;
                goto here;
            }
}
