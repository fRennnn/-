#include"Tutu.h"
void gotoxy(int x,int y)//什么垃圾? 狗都不用
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);//依托答辩
}
void Menu()
{
    char i=0;
    int j=0;
    
   
    
    cout<<"\t\t\t菜单"<<endl;
    
    if(MapPrintOk==false)
    cout<<"1 -- 显示地图"<<endl;
    else
    cout<<"1 -- 关闭地图"<<endl;
    
    cout<<"2 -- 查询任意两个景点之间的最短路径"<<endl;
    
    cout<<"3 -- 查询各景点的相关信息"<<endl;
    
    cout<<"4 -- 查询任意两个景点之间的最短距离"<<endl;
    
    cout<<"5 -- 增加，删除和更新有关景点和道路信息";
    if(!IsVip)
    cout<<"(管理员专用)"<<endl;
    else
    cout<<"(当前有权限使用)"<<endl;
    
    cout<<"6 -- 账号系统"<<endl;
   
    cout<<"7 -- 退出系统";

     if(!UpOrDown)
    cout<<"\t\t                                 当前为游客状态"<<endl;
    else
    {
        cout<<"\t\t                                 当前为管理员状态"<<endl;
        
        cout<<"\t\t\t                                 当前UID:"<<user[Location].phone<<endl;//使用隐藏密码输入会导致uid错乱(已解决)
    }

   
    i=getch();
    //-----------------------------------这是菜单,写好的函数放进去就是了
    switch (i)
    {
    case '1':
    {
        if(MapPrintOk==false)
        PrintMap();
        else
        {
        system("cls");
        MapPrintOk=false;
        }
        cout<<endl;
    }break;
    case '2':
    {
        cout<<"I am 2"<<endl;
        system("pause>nul");
    }break;
    case '3':
    {
        int x=0;
        cout<<"请输入地图编号:"<<endl;
        cin>>x;
        MapCheck(x);
        system("pause>nul");
    }break;
    case '4':
    {
        cout<<"I am 4"<<endl;
        system("pause>nul");
    }break;
    case '5':
    {
        if(IsVip)//简单的判断是不是VIP
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
    exit(0);//关闭整个文件
    default:
        break;
    }
//--------------------------------------------
if(MapPrintOk==false)//如果地图已经打开就别清屏了
    system("cls");
}
void CountMenu()
{
    system("cls");
    MapPrintOk=false;
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
            MapPrintOk=false;
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
            if(UpOrDown)//账号登陆后就不要再用登陆账号和注册账号这两个功能了
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
            MapPrintOk=false;
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
        MapPrintOk=false;
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
  /*
       　  　▃▆█▇▄?
　 　 　 ?◤?　　　◥█▎
   　 ◢◤　 ?　　　 　?▉
　 ?◤　　　▂　??　　▕█▎
　◤　?▅?◥▄　 ?◣　　█▊
?　▕▎◥?◣◤　　　　◢██
█◣　◥▅█?　　　　?██◤
?█?▂　　     　◢██◤
◥██◣　　　　◢▄◤
 　　?██▅▇?
 */
void PrintMap()
{
    system("cls");
    ifstream ifile;
    ifile.open("map.txt",ios::in);

    if(!ifile.is_open())
    {
        cout<<"文件打开失败"<<endl;
        system("pause>nul");
        return;
    }

    for(string str;getline(ifile,str);)//输出txt文件的所有内容
    cout<<str<<endl;
    MapPrintOk=true;
}

void MapRead()
{
    ifstream ifile;
    ifile.open("Node.txt",ios::in);

    if(!ifile.is_open())
    {
        cout<<"文件打开失败"<<endl;
        system("pause>nul");
        return;
    }

    for(int i=0;!ifile.eof();i++)
    {
        ifile >> Point[i].Number;
        ifile >> Point[i].Name;
        ifile >> Point[i].Imformation;
    }
    ifile.close();
}

void MapCheck(int i)
{
    int position=i-1;
    cout<<Point[position].Name<<endl;
    cout<<Point[position].Imformation<<endl;
}

void ChangeMapImf(int i)
{
    /*首先是需要查找到特定数据的所在，
    然后打开原本存有数据的文件test.txt与中间文件tmp.txt，
    随后通过while语句循环读取test.txt的数据，并逐一写入tmp.txt中，
    当读到与特定数据一致的数据时，通过重新定义变量的值并将重定义后的数据写入文件tmp.txt中。
    这样就能够实现对特定数据的修改，
    但还有一步便是将tmp.txt的数据写入test.txt中，
    从而实现在原文件中修改特定数据。
    */

    int position=i-1;//地图编号
    ifstream ifs;
    ofstream ofs;
    int Number1;//顶点编号
    string Name1;//地图节点名字
    string Imformation1;//地图信息，描述这个建筑
    ifs.open("Node.txt",ios::binary|ios::out|ios::in);
    ofs.open("tmp.txt",ios::binary|ios::out);
    while(ifs>>Number1&&ifs>>Name1&&ifs>>Imformation1)//将Node文件复制给tmp文件
    {
        if(Number1==i)
        {
         cout<<"原地图信息:"<<Point[position].Name<<" "<<Point[position].Imformation<<endl;
         cout<<"ESC退出,按任意键开始修改"<<endl;
         char ch=_getch();
         if(GetAsyncKeyState(VK_ESCAPE))
          {
            system("cls");
            return;
          }
         else
          {
           cout<<"修改为:";
           cin>>Imformation1;
           Point[position].Imformation=Imformation1;//修改对应地图的信息
          }
        }
        ofs<<Number1<<endl;
        ofs<<Name1<<endl;
        ofs<<Imformation1<<endl;
    }
    cout<<"修改完毕!"<<endl;
    ifs.close();
    ofs.close();

   
    ofstream ofs1;
    ifstream ifs1;
    ifs1.open("tmp.txt",ios::binary|ios::out);
    ofs1.open("Node.txt",ios::binary|ios::out|ios::in);
    while(ifs1>>Number1>>Name1>>Imformation1)//再把tep文件给Node文件
    {
        ofs1<<Number1<<endl;
        ofs1<<Name1<<endl;
        ofs1<<Imformation1<<endl;
    }
    ofs1.close();
    ifs1.close();//但愿成功   
}

MGraph::MGraph()//初始化邻接矩阵 
{
	ifstream ifile;
    ifile.open("Node.txt",ios::in);

    if(!ifile.is_open())
    {
        cout<<"文件打开失败"<<endl;
        system("pause>nul");
        return;
    }

    for(int i=0;!ifile.eof()&&i<50;i++)
    {
        ifile >> vertex[i].Number;
        ifile >> vertex[i].Name;
        ifile >> vertex[i].Imformation;
        vertexNum=i;
    }
	ifile.close();
	for (int i = 0; i < maxsize; i++)          //初始化邻接矩阵
 		for (int j = 0; j < maxsize; j++)
			edge[i][j] = INFINITY;            //假设边上权值最大是32767
	for(int i=0;i<vertexNum;i++)
		edge[i][i]=0;
	
    string fileString[50];	//静态定义文件字符串数组
    string subString1[50];  //静态定义三个子字符串数组
    string subString2[50];
    string subString3[50];
 	edgeNum = inputString("distance.txt",fileString);
 	 for(int i = 0; i <edgeNum; i++)
 	f2(fileString[i], subString1[i], subString2[i], subString3[i]);
 	for(int r = 0; r < edgeNum; r++)
	{   
		edge[f1(subString1[r])][f1(subString2[r])] = f1(subString3[r]);//由于是无向图,因而路径是双向的
		edge[f1(subString2[r])][f1(subString1[r])] = f1(subString3[r]);
	}

} 


int inputString(char *filename,string str[])//将filename所指文件按行输出到数组str[]中，返回表达式的实际个数
{
    
    ifstream infile;
	infile.open(filename,ios::in);//功能：定义输入文件流对象infile，打开磁盘filename所指文件，并使filename所指文件与流对象infile关联。
    if(!infile.is_open())//如果infile关联的文件打开失败，infile返回0
    {
        cout<<"文件打开出错！"<<endl; //输出错误信息
        system("pause>nul");
        exit(0);
    }
    int i=0;
    while(!infile.eof()) //infile关联的文件尚未到文件尾
    {

        getline(infile,str[i]); //从输入流对象infile所关联的文件读取一行存入str[i]
        i++;
    }
    infile.close();     //关闭infile所关联的磁盘文件
    return i - 1;           //返回表达式的实际个数
}

int f1(string str)//返回str中的数字字符串所对应的整数
{
    int result = 0;
	for(unsigned int i = 0; i < str.length(); i++)//for循环遍历字符串
	{
		if(str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + str[i] - 48;//根据ASCII,00110000~00111001表示'0'~'9'及十进制的规则
		}
	}
	return result;	//返回字符串所对应的整数
}

void f2(string str, string &str1, string &str2, string &str3)//使用string类的find函数分隔字符串
{
    int m = str.find('>');
    int n = str.find('>', m + 1);
    for(int i = 0; i < str.length(); i++) //for循环
    {
        if(i < m){str1 += str[i];}                 //读编号
        else if(i > m && i < n){str2 += str[i];}   //读编号
        else if(i > n){str3 += str[i];}            //读两个景点之间的距离
    }
}
