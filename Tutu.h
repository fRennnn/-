#include<iostream>
#include<string>
#include<conio.h>
#include<stdlib.h>
#include<windows.h>
#include"iostream"
#include"fstream"
#include<stack>//这个和下面的没用到
#include<queue>
#include<algorithm>
#include<string>
using namespace std;

#define SIZE 10 //最大用户数
#define maxsize 50//最大景点数 
#define INFINITY 32767     //INFINITY表示极大值、无穷大
int scount = 0;
bool IsVip = true;//判断是不是VIP
bool ZHUANGTAI = false;//判断文件是否成功打开
bool UpOrDown = false;//判断用户有无上号
bool MapPrintOk = false;//判断地图是否打印出来


int TEST=1;//不用管这个，测试用的值
int Location = 0;//用户账号所在的位置
int number = 0; //当前景点数 
void Menu();
void gotoxy(int x,int y);

class User//用户类
{
    private:
    string password;//密码
    public:
    string phone;
    int UID;
    User(){};
    void Registers();//注册账号
    void Login();//登录
    void Save();//保存
    void Read();//读取
}us;


User user[SIZE];

class MapNode//顶点信息
{
    public:
    string Name;//地图节点名字
    string Imformation;//地图信息，描述这个建筑
    int Number;//顶点编号
};

class MGraph //邻接矩阵 
{
public:
    MGraph();     //构造函数
    ~MGraph( ){ };            //析构函数
    void Update();//更新数据
    void Dijkstra(int v,int a,int t);  		//两个景点最短路径
	int Min(int r[ ], int n);//返回数组除0外的最小值的下标
    void MapCheck(int);//查看地图^ ^
    void MapRead();//读取地图
    void ChangeMapImf(int);//修改地图信息
    void DeleteNode(int);//删除节点
    void CreatNewNode(); //创造新节点
    void EdgeDataChange();//对节点的边操作
    void DATASAVE(int); //将修改后的数据写入文件。1是为写入边数据，其余是写入地图数据
    void DeleteEdge();  //删除特定边
    int GetEdgeNum();    //获取当前txt文件边的数量
    int GetvertexNum(){return vertexNum++;}
private:
 	MapNode vertex[maxsize];           //存放图中顶点的数组
    int edge[maxsize][maxsize];           //存放图中边的数组
    int vertexNum, edgeNum;              //图的顶点数和边数
 };

void f2(string str, string &str1, string &str2, string &str3);//使用string类的find函数分隔字符串
void f2(string str, string &str1, string &str2);//重载,这个是用来删除边数据的
void f21(string str, string &str1, string &str2);
int f1(string str);//返回str中的数字字符串所对应的整数
void inputString(char *filename,string str[]);//将filename所指文件按行输出到数组str[]中
void CountMenu();//账号菜单
void PrintMap();
void PrintMenu();
void NodeImfMenu();//节点信息菜单
