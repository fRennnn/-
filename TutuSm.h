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
        
        cout<<"\t\t\t                                 当前UID:"<<user[Location].phone<<endl;//使用隐藏密码输入会导致uid错乱(已解决)
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
    	cout<<"请按从左（出发）到右（目的地）顺序分别输入要查询的两个景点的编号：";
    	cin>>i>>k;
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
        cout<<"请输入地图编号:"<<endl;
        cin>>x;
        a.MapCheck(x);
        cout<<"按任意键返回菜单";
        system("pause>nul");
    }break;
    case '4':
    {
        int i,k;
    	cout<<"请按从左（出发）到右（目的地）顺序分别输入要查询的两个景点的编号：";
    	cin>>i>>k;
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
            cout<<"退出成功"<<endl;
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
                    user[i].UID=i+1;
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
                    user[i].UID=i+1;
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
    MapPrintOk=true;
}

/*void MapRead()
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
        cout<<"没有相关数据:C";
    }
    else
    cout<<vertex[position].Name<<endl;
    cout<<vertex[position].Imformation<<endl;
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
         cout<<"ESC退出\t按任意键开始修改"<<endl;
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
           vertex[position].Imformation=Imformation1;//修改对应地图的信息
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
 	edgeNum = inputString("distance.txt",fileString);//返回distance文件的行数，即边的数量
    edgeNum=0;
    edgeNum = GetEdgeNum();
 	 for(int i = 0; i <edgeNum; i++)
 	f2(fileString[i], subString1[i], subString2[i], subString3[i]);
 	for(int r = 0; r < edgeNum; r++)
	{   
        if((f1(subString1[r])-1)>vertexNum||(f1(subString2[r])-1)>vertexNum)//检查字符的数字是否超出顶点数
        {
            cout<<"数据错误,请进行数据检查"<<endl;
            cout<<"位于数组["<<r<<"]的元素出错,请修改!"<<endl;;
            system("pause");
            return;
        }

		edge[f1(subString1[r])-1][f1(subString2[r])-1] = f1(subString3[r]);//由于是无向图,因而路径是双向的
		edge[f1(subString2[r])-1][f1(subString1[r])-1] = f1(subString3[r]);
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
    return i - 1;       //返回表达式的实际个数,这里的i返回有问题
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
        if(i < m){str1 += str[i];}                 //读第一个地图编号
        else if(i > m && i < n){str2 += str[i];}   //读第二个地图编号
        else if(i > n){str3 += str[i];}            //读两个景点之间的距离
    }
}

void MGraph :: Dijkstra(int v,int a,int MODE)                      //从源点v出发
{
  	int i,k, num, dist[maxsize],distance[maxsize];
  	string path[maxsize];
	for (i = 0; i < vertexNum; i++)            //初始化数组dist和path
	{
   		dist[i] = edge[v-1][i];
   		if (dist[i] != INFINITY)                    //假设32767为边上权的最大值
			path[i] = vertex[v-1].Name +"->"+ vertex[i].Name;       //+为字符串连接操作
   		else path[i] = "";
   	}
	for (num = 1; num < vertexNum; num++)
	{
		k = Min(dist, vertexNum);      //在dist数组中找最小值并返回其下标
		distance[k]=dist[k];//?
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
	cout<<vertex[v-1].Name +"到"+ vertex[a-1].Name<<"的最短距离是:"<< distance[a-1]<<endl;
    }
	if(MODE==2)
	{
    cout<<vertex[v-1].Name +"到"+ vertex[a-1].Name<<"的最短路径是:"<<endl;
    cout<< path[a-1]<<endl;
    }
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
    cout<<"3--更新景点"<<endl;
    cout<<"4--增加边数"<<endl;

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
    default:
        break;
    }
}

void MGraph::DeleteNode(int x)
{

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
}

void MGraph::EdgeDataChange()
{
    string FirAndSec;
    ofstream ofs;
    cout<<"格式为(地图A编号)>(地图B编号)>(权值):"<<endl;
    cout<<"请输入:";
    cin>>FirAndSec;
    FirAndSec.erase(remove(FirAndSec.begin(),FirAndSec.end(),' '),FirAndSec.end());
    ofs.open("distance.txt",ios::binary|ios::out|ios::app);
    if(!ofs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        system("pause");
        return;
    }
    ofs<<FirAndSec<<endl;
    ofs.close();
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
 	edgeNum = inputString("distance.txt",fileString);//返回distance文件的行数，即边的数量
    edgeNum = GetEdgeNum();
 	 for(int i = 0; i <edgeNum; i++)
 	f2(fileString[i], subString1[i], subString2[i], subString3[i]);
 	for(int r = 0; r < edgeNum; r++)
	{   
        if((f1(subString1[r])-1)>vertexNum||(f1(subString2[r])-1)>vertexNum)//检查字符的数字是否超出顶点数
        {
            cout<<"数据错误,请进行数据检查"<<endl;
            cout<<"位于数组["<<r<<"]的元素出错,请修改!"<<endl;;
            system("pause");
            return;
        }

		edge[f1(subString1[r])-1][f1(subString2[r])-1] = f1(subString3[r]);//由于是无向图,因而路径是双向的
		edge[f1(subString2[r])-1][f1(subString1[r])-1] = f1(subString3[r]);
	}
}
