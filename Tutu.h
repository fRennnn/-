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

#define SIZE 10 //最大用户数
#define maxsize 50//最大景点数 
#define INFINITY 32767     //INFINITY表示极大值、无穷大
int scount = 0;
bool IsVip = false;//判断是不是VIP
bool ZHUANGTAI = false;//判断文件是否成功打开
bool UpOrDown = false;//判断用户有无上号
bool MapPrintOk = false;//判断地图是否打印出来

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


User user[SIZE];

class MapNode//顶点信息
{
    public://他妈的不用public又访问不了下面的数据，用了又感觉不太安全，这玩意要小心处理   
    string Name;//地图节点名字
    string Imformation;//地图信息，描述这个建筑
    int Number;//顶点编号
};
MapNode Point[maxsize];//50个地图节点
class MGraph //邻接矩阵 
{
public:
    MGraph();     //构造函数
    ~MGraph( ){ };            //析构函数
private:
 MapNode vertex[maxsize];           //存放图中顶点的数组
    int edge[maxsize][maxsize];           //存放图中边的数组
    int vertexNum, edgeNum;              //图的顶点数和边数
 };
void f2(string str, string &str1, string &str2, string &str3);
int f1(string str);
int inputString(char *filename,string str[]);
void CountMenu();
void PrintMap();
void MapCheck(int);// ^ ^
void MapRead();
