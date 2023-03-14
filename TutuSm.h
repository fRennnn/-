#include"Tutu.h"
MGraph a;//直接在这初始化，不然下面的函数不能用。
void gotoxy(int x,int y)//什么垃圾? 狗都不用
{
    COORD c;
    c.X=x;
    c.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);//依托答辩
}

void PrintMenu()//打印菜单，并且根据地图打开情况做出相应的打印变化
{
    cout<<"\t\t\t菜单"<<endl;
    
    if(MapPrintOk==false)//如果地图没打开
    {
    cout<<"1 -- 显示地图"<<endl;
    cout<<"2 -- 查询任意两个景点之间的最短路径"<<endl;
    
    cout<<"3 -- 查询各景点的相关信息"<<endl;
    
    cout<<"4 -- 查询任意两个景点之间的最短距离"<<endl;
    
    cout<<"5 -- 增加，删除和更新有关景点信息";
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
        
        cout<<"\t\t\t                                 当前UID:"<<user[Location].UID<<endl;//使用隐藏密码输入会导致uid错乱(已解决)
    }
    }
    else                 //如果地图打开了
    {
    system("cls");
    cout<<"\t\t\t菜单"<<endl;
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
        
        cout<<"\t\t\t                                 当前UID:"<<user[Location].UID<<endl;//使用隐藏密码输入会导致uid错乱(已解决)
    }
    PrintMap();
    }
}
void Menu()
{
    /*ofstream ofs;
    ofs.open("Node.txt",ios::out|ios::app);
    ofs<<"TEST1"<<endl;
    ofs<<"TEST2"<<endl;
    ofs<<"TEST3"<<endl;
    ofs.close();
    */
    char i=0;
    int j=0;
    
    PrintMenu();   //打印菜单表
    cout<<">>";
    i=getch();
    //-----------------------------------这是菜单,写好的函数放进去就是了
    switch (i)
    {
    case '1':
    {
        if(MapPrintOk==false)//如果没打开地图就打开地图
        PrintMap();
        else                 //关闭地图
        {
        system("cls");
        MapPrintOk=false;
        }
        cout<<endl;
    }break;
    case '2':
    {
        int i,k;
    	cout<<"请按从左（出发）到右（目的地）顺序分别输入要查询的两个景点的编号："<<endl;
        cout<<"出发地编号:";
    	cin>>i;
        cout<<"目的地编号:";
        cin>>k;
    	while(i==k||i>number||k>number)
    	{
        	cout<<"景点编号不能输入一致或编号错误！请重新输入::"<<endl; 
        	cin>>i>>k;
		}
		a.Dijkstra(i,k,2);
        cout<<"按任意键返回菜单";
        system("pause>nul");
    }break;
    case '3':
    {
        int x=0;
        cout<<"请输入地图编号:";
        cin>>x;
        a.MapCheck(x);
        cout<<"按任意键返回菜单";
        system("pause>nul");
    }break;
    case '4':
    {
        int i,k;
    	cout<<"请按从左（出发）到右（目的地）顺序分别输入要查询的两个景点的编号："<<endl;
        cout<<"出发地编号:";
    	cin>>i;
        cout<<"目的地编号:";
        cin>>k;
    	while(i==k||i>number||k>number)
    	{
        	cout<<"景点编号不能输入一致或编号错误！请重新输入::"<<endl; 
        	cin>>i>>k;
		}		
            a.Dijkstra(i,k,1);      
        cout<<"按任意键返回菜单";
		system("pause>nul");
    }break;
    case '5':
    {
        if(IsVip)//简单的判断是不是VIP
        {
            NodeImfMenu();
            cout<<"按任意键返回菜单";
            system("pause>nul");
        }
        else
        {
        cout<<"没有权限 > <"<<endl;
        cout<<"按任意键返回菜单";
        system("pause>nul");
        }
    }
        break;
    case '6':
    {
        CountMenu();
        //ser UID;
        //UID.Registers();
        cout<<"按任意键返回菜单";
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
    char ch;
    if(!UpOrDown)
    {
    cout<<"1-- 登录账号 "<<endl;
    cout<<"2-- 注册账号"<<endl;
    }
    cout<<"3-- 退出账号"<<endl;
    cout<<"4-- 注销账号"<<endl;
    cout<<">>";
    User Uid;
    while(1)
    {
        ch=getch();
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            system("cls");
            return;
        }
        if(ch=='1'||ch=='2'||ch=='3'||ch=='4')
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
            if(UpOrDown== false)
            {
            cout<<"|   |你还没登录过账号"<<endl;
            cout<<"    ^"<<endl;
            return;
            }
            IsVip=false;
            UpOrDown=false;
            system("cls");
            cout<<"退出成功"<<endl;
        }break;
        case '4':
        {
            Uid.Delete_Account();
        }break;
    }
}
void User::Save()
{
    ofstream ofile;
    ofile.open("user.txt",ios::out);

    for(int i = 0; i<scount; i++)
    {
        ofile << user[i].Account <<endl;
        ofile << user[i].password <<endl;
        ofile << user[i].UID<<endl;
    }
    ofile.close();
}
inline void User::Read()//user文件不能有多余的行数
{
    ifstream ifile;
    string str;
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
        ifile >> user[i].Account;
        ifile >> user[i].password;
        ifile >> user[i].UID;     
        scount++;
    }
    scount--;
    ifile.close();

    ifile.open("uidNumber.txt",ios::in);
    if(!ifile.is_open())
    {
        cout<<"文件打开失败"<<endl;
        system("pause");
        return;
    }
    ifile>>UidNumber;
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
        cout<<"\t\t\t请输入帐号:(输入000退出)";
        
        cin>>ph;
        
        if(ph=="000")
        {
            return;
        }

        for(int i=0;i<scount;i++)
        {
            if(ph==user[i].Account)
            {
                cout<<"用户已存在"<<endl;
                goto here;
            }
        }
        user[i].Account = ph;
        
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
                    user[i].UID=to_string(++UidNumber);
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
                    user[i].UID=to_string(++UidNumber);
                    scount++;
                    cout<<"\t\t\t注册成功!"<<endl;
                    us.Save();
                }
                break;
            }
        }
        ofstream ofile;
        ofile.open("uidNumber.txt",ios::in);
        if(!ofile.is_open())
    {
        cout<<"文件打开失败"<<endl;
        system("pasue<nul");
        return;
    }
        ofile<<UidNumber;
        ofile.close();
        
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

void User::Delete_Account()
{
    int loopSkip=0;
    if(!UpOrDown)
    {
        cout<<"|   |需要登陆账号才能执行账号注销"<<endl;
        cout<<"    ^"<<endl;
        return;
    }
    string str;
    string NUM=user[Location].UID+'\r';//debug了好久才发现这里少了'\r'，难怪删除没反应。
    string ACC=user[Location].Account+'\r';//这些数据和str就差个'\r'，故加了这个东西
    string PAS=user[Location].password+'\r';
    cout<<"当前账号为:"<<user[Location].Account<<endl;
    cout<<"是否删除账号?(ESC键--不删除,其余键--删除)"<<endl;
    cout<<">>";
    char _ch=_getch();
    if(GetAsyncKeyState(VK_ESCAPE))
    {
        cout<<"退出成功";
        system("pause>nul");
        return;
    }
    ifstream ifs;
    ofstream ofs;
    ifs.open("user.txt",ios::binary|ios::out|ios::in);//把user给tmp
    ofs.open("tmp.txt",ios::binary|ios::out);
    while(getline(ifs,str))
    {
        if(loopSkip!=0)//如果找到账号，后面两行账号数据自动跳过
        {
            loopSkip--;
            continue;
        }
        if(!str.compare(ACC))//首先如果找到该账号，设置循环跳过次数
        {
            loopSkip=2;
            continue;
        }
        ofs<<str<<endl;
    }
    ifs.close();
    ofs.close();
    ifs.open("tmp.txt",ios::binary|ios::out|ios::in);
    ofs.open("user.txt",ios::binary|ios::out);
    while(getline(ifs,str))//再把tep文件给uesr文件
    {
        ofs<<str<<endl;
    }
    ofs.close();
    ifs.close();
    cout<<"删除成功!";
    scount--;
    IsVip=false;
    UpOrDown=false;
}
void User::Login()
{
    us.Read();
    string ph,pw,pword;
    char ch;
    char passwords0[20];
    int time = 0;
    bool Found=false;
    bool Passw=false;
    int x=0;
    char chose;
    here:
    cout<<"\t\t\t请输入帐号:(输入000退出)";

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
            for(int i=0;i<=scount;i++)//检查密码是否正确
            {
                if(ph==user[i].Account) Found = true;//先查找是否存在该账号
                if(Found)//如果找到了在看看密码对不对
                {
                    if(pword == user[i].password)
                    {
                    cout<<"登陆成功"<<endl;//检查密码是否正确
                    UpOrDown = true;
                    IsVip=true;
                    Passw=true;
                    Location=i; 
                    break;
                    }
                    else 
                    {
                        Passw=false;
                        break;//既然都找到账号但没输对密码就直接退出循环，不需要在遍历下去了
                    }
                }
            }
            if(Found == false)
            {
                cout<<"没有找到该账号"<<endl;
                goto here;
            }
            else if(Passw == false)
            {
                cout<<"密码输入错误!"<<endl;
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
            for(int i=0;i<=scount;i++)
            {
                if(ph==user[i].Account) Found = true;//先查找是否存在该账号
                if(Found)//如果找到了在看看密码对不对
                {
                    if(passwords0 == user[i].password)
                    {
                    cout<<"登陆成功"<<endl;//检查密码是否正确
                    UpOrDown = true;
                    IsVip=true;
                    Passw=true;
                    Location=i; 
                    break;
                    }
                    else 
                    {
                        Passw=false;
                        break;//既然都找到账号但没输对密码就直接退出循环，不需要在遍历下去了
                    }
                }
            }
            if(Found == false)
            {
                cout<<"没有找到该账号"<<endl;
                goto here;
            }
            else if(Passw == false)
            {
                cout<<"密码输入错误!"<<endl;
                goto here;
            }
        }
        break;
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
    cout<<endl;
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
    
    MapPrintOk=true;//告诉程序地图已经打印了
}

/*void MapRead()这个函数多余的
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
*/

void MGraph::MapCheck(int i)
{
    int position=i-1;
    if(vertex[position].Name=="")
    {
        cout<<"没有相关数据:C"<<endl;
    }
    else
    {
    cout<<"景点名字:"<<vertex[position].Name<<endl;
    cout<<"景点介绍:"<<vertex[position].Imformation<<endl;
    }
}

void MGraph::ChangeMapImf(int i)
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
    ifs.open("Node.txt",ios::binary|ios::out|ios::in);//把node给tmp
    ofs.open("tmp.txt",ios::binary|ios::out);
    while(ifs>>Number1&&ifs>>Name1&&ifs>>Imformation1)//将Node文件复制给tmp文件
    {
        if(Number1==i)
        {
         cout<<"原地图名字:"<<vertex[position].Name<<endl;
         cout<<"原地图介绍:"<<vertex[position].Imformation<<endl;
         cout<<endl;
         cout<<"1--修改地图名字"<<endl;
         cout<<"2--修改地图介绍"<<endl;
         cout<<"3--两者都要?"<<endl;
         cout<<"ESC退出\t按任意键开始修改"<<endl;
         char ch=_getch();
         if(GetAsyncKeyState(VK_ESCAPE))//ESC键退出
          {
            system("cls");
            return;
          }
         else
          {
           switch(ch)
           {
            case '1':
            {
            cout<<"修改为:";
            cin>>Name1;
            vertex[position].Name=Name1; 
            }break;
            case '2':
            {
            cout<<"修改为:";
            cin>>Imformation1;
            vertex[position].Imformation=Imformation1;//修改对应地图的信息
            }break;
            case '3':
            {
            cout<<"修改地图名字为:";
            cin>>Name1;
            vertex[position].Name=Name1; 
            cout<<"修改地图介绍为:";
            cin>>Imformation1;
            vertex[position].Imformation=Imformation1;//修改对应地图的信息
            }break;
            default:{
                cout<<"输入错误,返回菜单";
                return;
            }
          }
        }
        }
        ofs<<Number1<<endl;
        ofs<<Name1<<endl;
        ofs<<Imformation1<<endl;
    }
    cout<<"修改完毕!"<<endl;
    ifs.close();
    ofs.close();
    
    ifs.open("tmp.txt",ios::binary|ios::out|ios::in);
    ofs.open("Node.txt",ios::binary|ios::out);
    while(ifs>>Number1>>Name1>>Imformation1)//再把tep文件给Node文件
    {
        ofs<<Number1<<endl;
        ofs<<Name1<<endl;
        ofs<<Imformation1<<endl;
    }
    ofs.close();
    ifs.close();//但愿成功   
    /*
    ifs.open("tmp.txt",ios::binary|ios::out|ios::in);//对的
    ofs.open("Node.txt",ios::binary|ios::out);
      
    ifs1.open("tmp.txt",ios::binary|ios::out);//错的
    ofs1.open("Node.txt",ios::binary|ios::out|ios::in);*/
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
        number=vertexNum;
    }
	ifile.close();
	for (int i = 0; i < maxsize; i++)          //初始化邻接矩阵
 		for (int j = 0; j < maxsize; j++)
			edge[i][j] = INFINITY;            //假设边上权值最大是32767
	
    string fileString[50];	//静态定义文件字符串数组
    string subString1[50];  //静态定义三个子字符串数组
    string subString2[50];
    string subString3[50];
 	inputString("distance.txt",fileString);//返回distance文件的行数，即边的数量
    edgeNum = GetEdgeNum();
 	 for(int i = 0; i <edgeNum; i++)
 	return_data1(fileString[i], subString1[i], subString2[i], subString3[i]);
 	for(int r = 0; r < edgeNum; r++)
	{   
        if((return_Number(subString1[r])-1)>vertexNum||(return_Number(subString2[r])-1)>vertexNum)//检查字符的数字是否超出顶点数
        {
            cout<<"数据错误,请进行数据检查"<<endl;
            cout<<"位于数组["<<r<<"]的元素出错,请修改!"<<endl;;
            system("pause");
            return;
        }

		edge[return_Number(subString1[r])-1][return_Number(subString2[r])-1] = return_Number(subString3[r]);//由于是无向图,因而路径是双向的
		edge[return_Number(subString2[r])-1][return_Number(subString1[r])-1] = return_Number(subString3[r]);
	}
} 


void inputString(char *filename,string str[])//将filename所指文件按行输出到数组str[]中，返回表达式的实际个数
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
           //返回表达式的实际个数,这里的i返回有问题
}

int return_Number(string str)//返回str中的数字字符串所对应的整数
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

void return_data1(string str, string &str1, string &str2, string &str3)//使用string类的find函数分隔字符串
{
    int m = str.find('>');
    int n = str.find('>', m + 1);
    for(int i = 0; i < str.length(); i++) //for循环
    {
        if(i < m){str1 += str[i];}                 //读第一个地图编号
        else if(i > m && i < n){str2 += str[i];}   //读第二个地图编号
        else if(i > n){str3 += str[i];}            //读两个景点之间的距离
    }
}
void return_data1(string str, string &str1, string &str2)//使用string类的find函数分隔字符串
{
    int m = str.find('>');
    int n = str.find('>', m + 1);
    for(int i = 0; i < str.length(); i++) //for循环
    {
        if(i < m){str1 += str[i];}                 //读第一个地图编号
        else if(i > m && i < n){str2 += str[i];}   //读第二个地图编号
    }
}

void MGraph :: Dijkstra(int v,int a,int MODE)                      //从源点v出发到达a
{
    int check=0;
  	int i,k, num, dist[maxsize],distance[maxsize]={0},s[maxsize]={0};
  	string path[maxsize];
    bool A=false,B=false;
	for (i = 0; i < vertexNum; i++)            //初始化数组dist和path
	{
   		dist[i] = edge[v-1][i];
   		if (dist[i] != INFINITY)                    //假设32767为边上权的最大值
			path[i] = vertex[v-1].Name +"->"+ vertex[i].Name;       //+为字符串连接操作
   		else path[i] = "";
   	}
    while(1)//这里是检查两个点是否至少有一边，主要是检查能不能到达的问题
    {
        if(A==false)
        {
        if(edge[v-1][check]!=INFINITY)//如果有边
       {
        A=true;
       }
       else
       {
        A=false;
       }
        }

         if(B==false)
       {
        if(edge[a-1][check]!=INFINITY)//如果有边
       {
        B=true;
       }
       else
       {
        B=false;
       }
       }

        if(A==true&&B==true)break;//如果两点都有路的话
        else check++;
        if(check==vertexNum)//查找完后发现没有路
        {
        if(A==false)
        {
        cout<<vertex[v-1].Name<<"没有路能走";
        }
        else if(B==false)
        {     
        cout<<vertex[a-1].Name<<"没有路能走";       
        }
        system("pause");
        return;
        }
    }
	for (num = 1; num <= vertexNum; num++)//少循环一次了 sb
	{     
		k = Min(dist, vertexNum);      //在dist数组中找最小值并返回其下标，就是找出离源节点最近的节点，让他迭代
		distance[k]=dist[k];           //打印距离的，这里有点问题
  		for (i = 0; i < vertexNum; i++)             //修改数组dist和path
    		if (dist[i] > dist[k] + edge[k][i]) 
            {
       			dist[i] = dist[k] + edge[k][i];
       			path[i] = path[k] + "->"+vertex[i].Name;         //+为字符串连接操作            
    		}
		dist[k] = 0;                            //将顶点k加到集合S中        
	}
	if(MODE==1)
    {
	cout<<vertex[v-1].Name +"到"+ vertex[a-1].Name<<"的最短距离是:"<< distance[a-1]<<endl;//BUG: 1到13不行 13到1行
    }
	if(MODE==2)
	{
    cout<<vertex[v-1].Name +"到"+ vertex[a-1].Name<<"的最短路径是:"<<endl;
    cout<< path[a-1]<<endl;
    }
    cout<<endl;
}

int MGraph ::Min(int r[ ], int n)
{
	int index = 0, min = 32767;
	for (int i = 0; i < n; i++)
		if (r[i] != 0 && r[i] < min)
		{
			min = r[i]; index = i;		
		}
	return index;
}



void NodeImfMenu()
{
    cout<<"\t\t\t菜单"<<endl;
    cout<<"1--增加景点"<<endl;
    cout<<"2--删除景点"<<endl;
    cout<<"3--修改景点"<<endl;
    cout<<"4--增加边数"<<endl;
    cout<<"5--删除特定边"<<endl;

    int x;
    char cha=_getch();

    switch (cha)
    {
    case '1':
    {
        a.CreatNewNode();
        a.EdgeDataChange();
    }
    break;
    case '2':
    {
        cout<<"请输入待删除景点的编号:";
        cin>>x;
        a.DeleteNode(x);
        a.DATASAVE(0);
        a.DATASAVE(1);
        a.Update();
    }
    break;
    case '3':
    {
        cout<<"输入待修改景点的编号:";
        cin>>x;
        a.ChangeMapImf(x);
    }
    break;
    case '4':
    {
        cout<<"输入起始地图的编号:";
        a.EdgeDataChange();
    }
    break;
    case '5':
    {
        cout<<"输入特定边 ( 编号A>编号B ) :";
        a.DeleteEdge();
    }break;
    default:
        break;
    }
}

void MGraph::DeleteNode(int x)
{
    string _Number=to_string(x);//将数字赋值给string;
    
    int position=x-1;//地图编号
    ifstream ifs;
    ofstream ofs;
    string str;
    string name1,number1,imf1;//记录需要删除的数据
    string Fir,Sec;//记录边是否相等
    name1=vertex[position].Name;
    number1=vertex[position].Number;
    imf1=vertex[position].Imformation;
    vertex[position].Name="NULL";
    vertex[position].Number=0;
    vertex[position].Imformation="NULL";
    ifs.open("Node.txt",ios::binary|ios::out|ios::in);//把node给tmp
    ofs.open("tmp.txt",ios::binary|ios::out);
    while(getline(ifs,str))
    {
        if(!str.compare(number1))continue;//对比数据是否一致，一致则跳过
        if(!str.compare(name1))continue;
        if(!str.compare(imf1))continue;
        ofs<<str<<endl;
    }
    ifs.close();
    ofs.close();
    ifs.open("tmp.txt",ios::binary|ios::out|ios::in);
    ofs.open("Node.txt",ios::binary|ios::out);
    while(getline(ifs,str))//再把tep文件给Node文件
    {
        ofs<<str<<endl;
    }
    ofs.close();
    ifs.close();
//------------------下面处理边
    ifs.open("distance.txt",ios::binary|ios::out|ios::in);
    ofs.open("tmp.txt",ios::binary|ios::out);
    while(getline(ifs,str))
    {
        Fir.clear();
        Sec.clear();

        return_data1(str,Fir,Sec);                        //使用string类的find函数分隔字符串

        if(!Fir.compare(_Number)||!Sec.compare(_Number))//返回str中的数字字符串所对应的整数
        { 
            continue;
        }
        ofs<<str<<endl;
    }
    ifs.close();
    ofs.close();
    ifs.open("tmp.txt",ios::binary|ios::out|ios::in);
    ofs.open("distance.txt",ios::binary|ios::out);
    while(getline(ifs,str))//再把tep文件给distance文件
    {
        ofs<<str<<endl;
    }
    ofs.close();
    ifs.close();
//----------------
    cout<<"删除成功"<<endl;
}

void MGraph::CreatNewNode()
{
    string FirAndSec;
    int NUM=a.GetvertexNum();
    number++;//增加一个顶点
    string name,imf;
    cout<<"请输入景点名字:";
    cin>>name;
    cout<<"请输入景点信息:";
    cin>>imf;
    vertex[NUM].Number=NUM+1;//13在数组里面是14，这里需要加1
    vertex[NUM].Name=name;
    vertex[NUM].Imformation=imf;
    ofstream ofs;
    ofs.open("Node.txt",ios::binary|ios::out|ios::app);
    if(!ofs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        system("pause");
        return;
    }
    ofs<<vertex[NUM].Number<<endl;
    ofs<< vertex[NUM].Name<<endl;
    ofs<<vertex[NUM].Imformation<<endl;
    ofs.close();
    cout<<"输入成功^ ^"<<endl;
    a.DATASAVE(0);
    a.DATASAVE(1);
}

void MGraph::EdgeDataChange()
{
    string FirAndSec;
    ofstream ofs;
    cout<<"注意:编号大于景点数的数据不被记录"<<endl;
    cout<<"格式为(地图A编号)>(地图B编号)>(权值):"<<endl;
    do{
    cout<<"请输入:";
    cin>>FirAndSec;
    FirAndSec.erase(remove(FirAndSec.begin(),FirAndSec.end(),' '),FirAndSec.end());
    if((FirAndSec.find('>')==-1))
    {
        cout<<"请按格式输入!"<<endl;
    }
    else 
    break;
    }while(1);
    ofs.open("distance.txt",ios::binary|ios::out|ios::app);
    if(!ofs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        system("pause");
        return;
    }
    ofs<<FirAndSec<<endl;
    ofs.close();
    a.DATASAVE(1);
    a.Update();
    cout<<"已更新数据^ ^";
}

int MGraph::GetEdgeNum()
{
    string tmp;
    int numBeR;
    ifstream ReadFile;
    ReadFile.open("distance.txt",ios::in);
    if(ReadFile.fail())
    {
        cout<<"打开文件失败";
        system("pause");
        exit(0);
    }
    else
    {
        while(getline(ReadFile,tmp))
        {
            if(tmp=="")//忽略空行
            continue;
            else
            {
            numBeR++;
            //cout<<tmp<<endl;
            }
        }        
    }
    ReadFile.close();
    return numBeR/2+1;//我也不知道为什么numBeR是行数的2倍 :C
}

void MGraph::Update()
{
    ifstream ifile;
    ifile.open("Node.txt",ios::in);//更新咯

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
        number=vertexNum;
    }
	ifile.close();

	for (int i = 0; i < maxsize; i++)          //初始化邻接矩阵
 		for (int j = 0; j < maxsize; j++)
			edge[i][j] = INFINITY;            //假设边上权值最大是32767
	
    string fileString[50];	//静态定义文件字符串数组
    string subString1[50];  //静态定义三个子字符串数组
    string subString2[50];
    string subString3[50];
 	inputString("distance.txt",fileString);//返回distance文件的行数，即边的数量
    edgeNum = GetEdgeNum();
 	 for(int i = 0; i <edgeNum; i++)
 	return_data1(fileString[i], subString1[i], subString2[i], subString3[i]);
 	for(int r = 0; r < edgeNum; r++)
	{   
        if((return_Number(subString1[r])-1)>vertexNum||(return_Number(subString2[r])-1)>vertexNum)//检查字符的数字是否超出顶点数
        {
            cout<<"数据错误,请进行数据检查"<<endl;
            cout<<"位于数组["<<r<<"]的元素出错,请修改!"<<endl;;
            system("pause");
            return;
        }

		edge[return_Number(subString1[r])-1][return_Number(subString2[r])-1] = return_Number(subString3[r]);//由于是无向图,因而路径是双向的
		edge[return_Number(subString2[r])-1][return_Number(subString1[r])-1] = return_Number(subString3[r]);
	}
}

void MGraph::DATASAVE(int ModeSetting)
{
    if(ModeSetting==1)//1是保存边数据
    {
    ifstream ifs;
    ofstream ofs;
    string str;
    string Fir,Sec;//记录边是否相等
    ifs.open("distance.txt",ios::binary|ios::out|ios::in);//把node给tmp
    if(!ifs.is_open())
    {
        cout<<"打开文件失败"<<endl;
        system("pause");
        return;
    }
    ofs.open("tmp.txt",ios::binary|ios::out);
    if(!ofs.is_open())
    {
        cout<<"打开文件失败"<<endl;
        system("pause");
        return;
    }
    while(ifs>>str)
    {
        ofs<<str<<endl;
    }
    ifs.close();
    ofs.close();
    ifs.open("tmp.txt",ios::binary|ios::out|ios::in);
    if(!ifs.is_open())
    {
        cout<<"打开文件失败"<<endl;
        system("pause");
        return;
    }
    ofs.open("distance.txt",ios::binary|ios::out);
    if(!ofs.is_open())
    {
        cout<<"打开文件失败"<<endl;
        system("pause");
        return;
    }
    while(getline(ifs,str))
    {
        Fir.clear();
        Sec.clear();
        return_data1(str,Fir,Sec); 
        if(return_Number(Fir)>vertexNum||return_Number(Sec)>vertexNum)continue;//编号大于景点数的不被写入文件
        ofs<<str<<endl;
    }
    ofs.close();
    ifs.close();
    }
    else
    {
    ifstream ifs;
    ofstream ofs;
    int Number1;//顶点编号
    string Name1;//地图节点名字
    string Imformation1;//地图信息，描述这个建筑
    ifs.open("Node.txt",ios::binary|ios::out|ios::in);//把node给tmp
    if(!ifs.is_open())
    {
        cout<<"打开文件失败"<<endl;
        system("pause");
        return;
    }
    ofs.open("tmp.txt",ios::binary|ios::out);
    if(!ofs.is_open())
    {
        cout<<"打开文件失败"<<endl;
        system("pause");
        return;
    }
    while(ifs>>Number1&&ifs>>Name1&&ifs>>Imformation1)//将Node文件复制给tmp文件
    {
        ofs<<Number1<<endl;
        ofs<<Name1<<endl;
        ofs<<Imformation1<<endl;
    }
    ifs.close();
    ofs.close();
    ifs.open("tmp.txt",ios::binary|ios::out|ios::in);
    if(!ifs.is_open())
    {
        cout<<"打开文件失败"<<endl;
        system("pause");
        return;
    }
    ofs.open("Node.txt",ios::binary|ios::out);
    if(!ofs.is_open())
    {
        cout<<"打开文件失败"<<endl;
        system("pause");
        return;
    }
    while(ifs>>Number1>>Name1>>Imformation1)//再把tep文件给Node文件
    {
        ofs<<Number1<<endl;
        ofs<<Name1<<endl;
        ofs<<Imformation1<<endl;
    }
    ofs.close();
    ifs.close();
    }
}

void MGraph::DeleteEdge()
{
    bool Mode=false;
    string FirAndSec,str,Fir,Sec,One,Two;
    do{
    cin>>FirAndSec;
    FirAndSec.erase(remove(FirAndSec.begin(),FirAndSec.end(),' '),FirAndSec.end());
    if((FirAndSec.find('>')==-1))//如果输入格式不对的话，也就是找不到这个大于符号的话
    {
        cout<<"请按格式输入!"<<endl;
    }
    else 
    break;
    }while(1);
    return_data2(FirAndSec,Fir,Sec);//记录输入的字符
    ifstream ifs;
    ofstream ofs;
    ifs.open("distance.txt",ios::binary|ios::out|ios::in);
    ofs.open("tmp.txt",ios::binary|ios::out);
    
    while(getline(ifs,str))//找边
    {
        One.clear();
        Two.clear();
        return_data1(str,One,Two);
         if(!One.compare(Fir)&&!Two.compare(Sec))//找到的话
         {
            cout<<"该边详细数据为(编号>编号>权值):"<<str<<endl;
            cout<<"是否决定删除?"<<endl;
            cout<<"ESC--不删   其他键--删!";
            char _ch=_getch();
             if(GetAsyncKeyState(VK_ESCAPE))
            {
            return;
            }
            system("pause>nul");
            FirAndSec=str;//把具体的复制给它
            Mode=true;
            continue;
         }
         ofs<<str<<endl;   
    }
    ifs.close();
    ofs.close();


    ifs.open("tmp.txt",ios::binary|ios::out|ios::in);
    ofs.open("distance.txt",ios::binary|ios::out);
    while(getline(ifs,str))//再把tep文件给distance文件
    {
        ofs<<str<<endl;
    }
    ofs.close();
    ifs.close();
    if(Mode!=true)
    {
        cout<<"没找到改条边,试着编号顺序反过来写"<<endl;
        system("pause>nul");
        return;
    }
    else
    {
        cout<<"删除成功"<<endl;
    }
    a.DATASAVE(1);
    a.DATASAVE(0);
    a.Update();
}

void return_data2(string str, string &str1, string &str2)//主要为了输入格式好看一些
{
    int m = str.find('>');
    int n = str.length();
    for(int i = 0; i < str.length(); i++) //for循环
    {
        if(i < m){str1 += str[i];}                 //读第一个地图编号
        else if(i > m && i < n){str2 += str[i];}   //读第二个地图编号
    }
}
