#define _CRT_SECURE_NO_WARNINGS//ȥ������scanf,strcpy,fopen,sprintf�İ�ȫ����
//ͨ����̬����ʵ��FOSϵͳ
//Programed with Microsoft Visual Studio 2022

//#include "vld.h" //ʹ��Visual Leak Detector�������Ƿ����ڴ�й©
#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "conio.h"//����ʹ��getch�������������,���ûس�
#include "time.h"//����Ч�ʿ��ӻ�,��debug�²ſ��ܿ�����ֵ,release�汾�ǳ���

#define MAX_FOOD 18 //�궨������Ʒ������

typedef struct order//�����ṹ��
{
    int id; //�������
    char name[50]; //�˿�����
    int age; //�˿�����
    char phone[30]; //�˿͵绰
    char address[150]; //�˿�������ַ
    double total_price; //�����ܼ�
    double profit;//��������
    double cost;//�����ɱ� (����ÿ�ݲ�Ʒ��ԭ����+�ӹ���+���ͷѾ�Ϊ2.5��Ԫ)
    double profit_margin;//����������
    struct order* next; //ָ����һ���ڵ�
    int food_id[MAX_FOOD];// ��Ʒ�������
    int food_quantity[MAX_FOOD];//��Ʒ��������
    char* food_name[MAX_FOOD];//��Ʒ����ָ���ַ�����ָ������
}order, * link;//ʹ��typedef�������������ʹ��

link order_list = NULL;//���嶯̬����ͷ�ڵ�

typedef struct foods//�����Ʒ�ṹ��,����ʹ��
{
    int num;//��Ʒ���
    char name[30];//��Ʒ����
    double price;//��Ʒ�۸�
}food;

//ע�����¼۸�λ��Ϊ��Ԫ
food foods[18] = { {1,"Cappuccino",3.99},{2,"Latte",2.99},{3,"Espresso",3.99},{4,"Americano",2.99},{5,"Caff�� mocha",2.99},{6,"Caff�� macchiato",2.99},
    {7,"Hot tea,HongKong style",1.99},{8,"Chocolate milk tea",2.99},{9,"Strawberry milk tea",3.49},{10,"Coconut milk tea",3.49},{11,"Caramel Bubble Milk Tea",3.49},{6,"Honey Boba Frosty Milk",3.49}
    ,{13,"Stinky Tofu",2.99},{14,"French fries",3.99},{15,"Fried Chicken Leg",1.49},{16,"Cold Rice Noodles",6.49},{17,"Milk Custard",5.99},{18,"Water-Ice",4.99} };
//�Լ������ƵĲ�Ʒ�˵�,�۸���������,��������ʵ����,�����ο�

//��������
char main_menu();//���˵�����
void menu();//��˵�����
char Submenu_for_customer(); //�Ӳ˵�(�˿�)����
char Submenu_for_vendors(); //�Ӳ˵�(�̼�)����
void print_order(link order);//��ӡ�ض���������
void print_all_orders();//��ӡȫ����������
void count_food_distribution();//�������ж�����Ʒ�����ֲ�����
link create_order(int id);//�˿��µ�����
void free_all_orders();//��ʽ��������
link copy_order(link head);////����ԭ����������
void write_in_order();//���ж���д���ļ�����
void check_information_txt(); //�鿴д���ļ�����
link Random_order_information(int id);//������ɶ�����Ϣ����
void sort_order_by_total_price();//�������ݹ˿����ѽ��������
void profit();//�鿴����������
