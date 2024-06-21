#define _CRT_SECURE_NO_WARNINGS//去除关于scanf,strcpy,fopen,sprintf的安全警告
//通过动态链表实现FOS系统
//Programed with Microsoft Visual Studio 2022

//#include "vld.h" //使用Visual Leak Detector检查程序是否有内存泄漏
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"//方便使用getch函数提高流畅度,不用回车
#include "time.h"//运行效率可视化,在debug下才可能看到数值,release版本非常快

#define MAX_FOOD 18 //宏定义最大餐品种类数

typedef struct order//订单结构体
{
    int id; //订单编号
    char name[50]; //顾客姓名
    int age; //顾客年龄
    char phone[30]; //顾客电话
    char address[150]; //顾客外卖地址
    double total_price; //订单总价
    double profit;//订单利润
    double cost;//订单成本 (假设每份餐品的原材料+加工费+配送费均为2.5美元)
    double profit_margin;//订单利润率
    struct order* next; //指向下一个节点
    int food_id[MAX_FOOD];// 餐品编号数组
    int food_quantity[MAX_FOOD];//餐品数量数组
    char* food_name[MAX_FOOD];//餐品名称指向字符串的指针数组
}order, * link;//使用typedef函数起别名方便使用

link order_list = NULL;//定义动态链表头节点

typedef struct foods//定义餐品结构体,方便使用
{
    int num;//餐品编号
    char name[30];//餐品名称
    double price;//餐品价格
}food;

//注意以下价格单位均为美元
food foods[18] = { {1,"Cappuccino",3.99},{2,"Latte",2.99},{3,"Espresso",3.99},{4,"Americano",2.99},{5,"Caffè mocha",2.99},{6,"Caffè macchiato",2.99},
    {7,"Hot tea,HongKong style",1.99},{8,"Chocolate milk tea",2.99},{9,"Strawberry milk tea",3.49},{10,"Coconut milk tea",3.49},{11,"Caramel Bubble Milk Tea",3.49},{6,"Honey Boba Frosty Milk",3.49}
    ,{13,"Stinky Tofu",2.99},{14,"French fries",3.99},{15,"Fried Chicken Leg",1.49},{16,"Cold Rice Noodles",6.49},{17,"Milk Custard",5.99},{18,"Water-Ice",4.99} };
//自己随便设计的餐品菜单,价格随意设置,可能与现实不符,仅供参考

//函数声明
char main_menu();//主菜单函数
void menu();//真菜单函数
char Submenu_for_customer(); //子菜单(顾客)函数
char Submenu_for_vendors(); //子菜单(商家)函数
void print_order(link order);//打印特定订单函数
void print_all_orders();//打印全部订单函数
void count_food_distribution();//计算所有订单餐品数量分布函数
link create_order(int id);//顾客下单函数
void free_all_orders();//格式化链表函数
link copy_order(link head);////复制原订单链表函数
void write_in_order();//所有订单写入文件函数
void check_information_txt(); //查看写入文件函数
link Random_order_information(int id);//随机生成订单信息函数
void sort_order_by_total_price();//订单根据顾客消费金额排序函数
void profit();//查看订单利润函数
