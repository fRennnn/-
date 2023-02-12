#include"TutuSm.h"
int main()
{
    MapRead();//把txt文件数据都读取进去
    while(1)
    {
  MGraph a;
        if(MapPrintOk==true)PrintMap();//打开地图后保留地图，输入选项再关闭
        Menu();//累死爷了
    }    
  
    system("pause");
    return 0;
}
