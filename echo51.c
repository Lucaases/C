#include<stdio.h>
#include<conio.h> //包含getch()函数的头文件
int menu_select(void); //声明主菜单函数
int secmenu_select1(void); //声明第一个子菜单函数
int secmenu_select2(void); //声明第二个子菜单函数
int main()
{
    int select; //定义选择变量
    char ch; //定义字符变量
    while(1) //循环显示主菜单
    {
        select = menu_select(); //调用主菜单函数并获取选择
        if(select == 1) //如果选择1，进入第一个子菜单
        {
            while(1) //循环显示第一个子菜单
            {
                select = secmenu_select1(); //调用第一个子菜单函数并获取选择
                ch = getch(); //读取输入的字符
                if(ch == '#') //如果输入'#'，返回主菜单
                {
                    break; //跳出第一个子菜单循环
                }
                else //否则执行相应的功能
                {
                    printf("这是第一个子菜单的功能%d\n", select);
                }
            }
        }
        else if(select == 2) //如果选择2，进入第二个子菜单
        {
            while(1) //循环显示第二个子菜单
            {
                select = secmenu_select2(); //调用第二个子菜单函数并获取选择
                ch = getch(); //读取输入的字符
                if(ch == '#') //如果输入'#'，返回主菜单
                {
                    break; //跳出第二个子菜单循环
                }
                else //否则执行相应的功能
                {
                    printf("这是第二个子菜单的功能%d\n", select);
                }
            }
        }
        else if(select == 3) //如果选择3，退出程序
        {
            printf("谢谢使用，再见！\n");
            break; //跳出主菜单循环
        }
        else //否则提示无效输入
        {
            printf("请输入有效的选项！\n");
        }
    }
    return 0;
}

int menu_select(void) //定义主菜单函数
{
    int select; //定义选择变量
    printf("**********主菜单**********\n");
    printf("1. 进入第一个子菜单\n");
    printf("2. 进入第二个子菜单\n");
    printf("3. 退出程序\n");
    printf("请输入你的选择：");
    scanf("%d", &select); //获取用户输入
    return select; //返回选择值
}

int secmenu_select1(void) //定义第一个子菜单函数
{
    int select; //定义选择变量
    printf("**********第一个子菜单**********\n");
    printf("1. 功能1\n");
    printf("2. 功能2\n");
    printf("3. 功能3\n");
    printf("输入#返回主菜单\n"); //提示用户输入'#'返回主菜单
    printf("请输入你的选择：");
    scanf("%d", &select); //获取用户输入
    return select; //返回选择值
}

int secmenu_select2(void) //定义第二个子菜单函数
{
    int select; //定义选择变量
    printf("**********第二个子菜单**********\n");
    printf("4. 功能4\n");
    printf("5. 功能5\n");
    printf("6. 功能6\n");
    printf("输入#返回主菜单\n"); //提示用户输入'#'返回主菜单
    printf("请输入你的选择：");
    scanf("%d", &select); //获取用户输入
    return select; //返回选择值
}