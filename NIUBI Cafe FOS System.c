#include "NIUBI Cafe FOS System.h"

char main_menu()//主菜单函数
{
	char a;
	printf("\n\n");
	printf("********\tFinancial and Ordering System of NIUBI Cafe\t********\n\n\n");
	printf("********\tWelcome To the our cafe!Please enter 1 to order if you are customers!\t\t********\n\n\n\n\n");
	printf("$$$\t1.Customers\n\n\n");
	printf("$$$\t2.Vendors(Password Required)\n\n\n");
	printf("$$$\t3.Generate Random Customer information\n\n\n");
	printf("$$$\t4.Refresh information!(If you want to change the amount of Random Customer information)\n\n\n");
	printf("$$$\t5.Quit!\n\n\n");
	a = _getch();
	return a;
}

void menu() //真菜单函数
{
	printf("\n\n");
	printf("$$$\t1.Cafes\n\n");
	printf("$$$\t(1)Cappuccino $3.99\n\t(2)Latte $2.99\n\t(3)Espresso $3.99\n\t(4)Americano $2.99\n\t(5)Caffè mocha $2.99\n\t(6)Caffè macchiato $2.99\n\n\n");
	printf("$$$\t2.Milk Teas\n\n");
	printf("$$$\t(7)Hot tea,HongKong style $1.99\n\t(8)Chocolate milk tea $2.99\n\t(9)Strawberry milk tea $2.99\n\t(10)Coconut milk tea $3.49\n\t(11)Caramel Bubble Milk Tea $3.49\n\t(12)Honey Boba Frosty Milk $3.49\n\n\n");
	printf("$$$\t3.Snacks\n\n");
	printf("$$$\t(13)Stinky Tofu  $2.99\n\t(14)French fries $3.99\n\t(15)Fried Chicken Leg $1.49\n\t(16)Cold Rice Noodles $6.49\n\t(17)Milk Custard $5.99\n\t(18)Water-lce $4.99\n\n\n");
}

char Submenu_for_customer()// 子菜单(顾客)函数
{
	char a;
	printf("\n\n");
	printf("********\tFinancial and Ordering System of NIUBI Cafe\t********\n\n");
	printf("********\tWelcome To the our cafe's ordering system!Just order your favorite!\t\t********\n\n\n");
	printf("$$$\t1.Menu of NIUBI cafe!!\n\n\n");
	printf("$$$\t2.Check Here to place your Order!!\n\n\n");
	printf("$$$\t3.Check your detailed order information!!\n\n\n");
	printf("$$$\t4.Return to the main menu!(press twice!)\n");
	a = _getch();
	return a;
}

char Submenu_for_vendors()// 子菜单(商家)函数
{
	char a;
	printf("\n\n");
	printf("********\tFinancial and Ordering System of NIUBI Cafe\t********\n\n");
	printf("********\tWelcome to the management system of NIUBI Cafe!\t\t********\n\n\n");
	printf("$$$\t1.Print specific order\n\n\n");	
	printf("$$$\t2.Print all orders\n\n\n");	
	printf("$$$\t3.Sort orders by customer's spend\n\n\n");	
	printf("$$$\t4.Count food distribution\n\n\n");	
	printf("$$$\t5.Write order information to a file\n\n\n");	
	printf("$$$\t6.Check the order information in txt\n\n\n");	
	printf("$$$\t7.Check the profits of all orders\n\n\n");
	printf("$$$\t8.Return to the main menu!(press twice!)\n");
	a = _getch();
	return a;
}

link create_order(int id)//顾客下单函数
{
	link new_order = (link)malloc(sizeof(order));//构建动态链表,为new_order(指向结构体order的指针)动态分配内存
	if (new_order == NULL) {//防止内存分配出错
		printf("$$$\tWarning! Memory allocation failed!\n");
		return NULL;}
	new_order->id = id;//匹配订单id,方便后面的打印订单函数
	printf("$$$\tPlease enter the customer's name:\n");
	scanf("%50s", new_order->name);
	printf("$$$\tPlease enter the customer's age:\n");
	scanf("%d", &(new_order->age));
	getchar();//由于scanf函数会在最后回车留下换行符,要使fgets函数执行,必须使用getcahr函数将换行符消耗掉
	printf("$$$\tPlease enter the customer's phone:\n");
	fgets(new_order->phone, 30, stdin);
	printf("$$$\tPlease enter the customer's address:\n");
	fgets(new_order->address, 150, stdin);
	int i = 0;int n = 0;int a;double add = 0;
	new_order->total_price = 0;//初始化total_price为0,防止后面的累加求和出错
	for (n = 0; n < MAX_FOOD; n++) {
		new_order->food_name[n] = (char*)calloc(50, sizeof(char));}//初始化餐品编号数组为0,方便后续操作,防止报错
	memset(new_order->food_id, 0, sizeof(new_order->food_id));//初始化餐品编号数组为0,方便后续操作,防止报错
	memset(new_order->food_quantity, 0, sizeof(new_order->food_quantity));//初始化餐品数量数组为0,方便后续操作,防止报错
	system("cls");
	menu();//打印菜单,方便点餐
	printf("\n\n");
	while (1) { //让顾客循环输入所点餐品的编号以及份数,确保顾客能点多份餐品,多种餐品
		if (i >= MAX_FOOD) {
			printf("$$$\tMaximum food limit reached.\n");//防止超过数组限制导致程序出错
			break;}
		printf("$$$\tPlease enter the food id you want to order (enter 0 to end):\n");
		scanf("%d", &a);
		if (a == 0) {
			break;}//输入0跳出循环,即结束点餐
		
		if (a < 1 || a > MAX_FOOD) {
			printf("$$$\tInvalid food id!\n");//确保顾客正确输入餐品编号
			continue;}
		//将数据传入链表节点的数据域
		new_order->food_id[i] = a;
		strcpy(new_order->food_name[i], foods[a - 1].name);
		printf("$$$\tPlease enter the food count:\n");
		scanf("%d", &new_order->food_quantity[i]);
		new_order->total_price += (new_order->food_quantity[i]) * foods[a - 1].price;
		add += (new_order->food_quantity[i] * 2.5); //假设每份食品原材料+加工+配送费的成本为2.5美元
		new_order->cost = add;
		new_order->profit = (new_order->total_price - add);
		new_order->profit_margin = new_order->profit / add;
		i++;
	}

	//new_order->next = order_list;//头插法插入节点
	//order_list = new_order;
	//return new_order;

	new_order->next = NULL; //尾插法插入节点(这里选择尾插法是因为id编号从1开始增加,即后面id编号大的订单应该排在后面)
	if (order_list == NULL) {
		order_list = new_order; // 如果链表为空，将新节点设置为头节点
	}
	else {
		link p = order_list;//定义辅助指针通过循环找到链表尾节点
		while (p->next != NULL) {
			p = p->next; }
		p->next = new_order; // 将新节点插入到尾节点后面
	}
	return new_order;
}

void print_order(link order) //打印特定订单函数
{
    if (order == NULL) {
        printf("$$$\t**** Invalid order! *****\n");
        return;}
	//打印基本信息
    printf("$$$\tOrder id: %d\n\n", order->id); 
    printf("$$$\tCustomer name: %s\n\n", order->name);
    printf("$$$\tCustomer age: %d\n\n", order->age); 
    printf("$$$\tCustomer phone: %s\n\n", order->phone);
    printf("$$$\tCustomer address: %s\n\n", order->address); 
    printf("$$$\tFood id\t\tFood name\t\t\tFood count\t\tFood unit price\t\tFood total price\n"); 
    for (int i = 0; i < MAX_FOOD; i++) {
        if (order->food_id[i] != 0) { //前面将在create_order函数中将food_id[]数组初始化为0,这样在这里就可以读取有用的数据
            printf("$$$\t%-5d\t\t%-20s\t\t%6d\t\t\t$%-5.2lf\t\t\t$%-5.2lf\n", order->food_id[i], order->food_name[i], order->food_quantity[i], foods[order->food_id[i] - 1].price,(foods[order->food_id[i] - 1].price)* (order->food_quantity[i]));
		}
    }
	printf("\n");
}

void print_all_orders() //打印全部订单函数
{
	link p = order_list; 
	if (p == NULL) {
		printf("\n\n");
		printf("$$$\t***************************************\n\n");
		printf("$$$\t****** Waring!Order not found! ******\n\n");
		printf("$$$\t***************************************\n");
	}
	while (p != NULL) {//通过移动指针循环链表读取数据
		printf("$$$\t**********************************************************************\n");
		print_order(p); 
		printf("$$$\tTotal price is $%.2lf\n\n", p->total_price);
		printf("$$$\tIncome:$%.2lf\n\n", p->total_price);
		printf("$$$\tCost:$%.2lf\n\n", p->cost);
		printf("$$$\tProfit:$%.2lf\n\n", p->profit);
		printf("$$$\tProfit margin:%.3lf\n\n", p->profit_margin);
		p = p->next; 
		printf("\n");
		printf("$$$\t**********************************************************************\n\n\n");
	}
}

void count_food_distribution() //计算所有订单食物数量分布函数
{
	int i = 0;
	int food_count[18] = { 0 };//定义数量分布统计数组,并初始化为0,防止报错
	link p = order_list;//定义辅助指针循环检视链表
	if (p == NULL) {
		printf("\n\n");
		printf("$$$\t************************************\n\n");
		printf("$$$\t***** Waring!Order not found! *****\n\n");
		printf("$$$\t***********************************\n");
	}
	else {
		for (p = order_list; p != NULL; p = p->next) {
			for ( i = 0; i < MAX_FOOD; i++) {
				if (p->food_id[i] != 0) {//前面将在create_order函数中将food_id[]数组初始化为0,这样在这里就可以读取有用的数据 
					food_count[p->food_id[i]-1] += p->food_quantity[i];//将各订单检测到的餐品数量累加
				}
			}
		}
		printf("$$$\tFood name\t\tFood name\t\t\tFood count\n");
		for ( i = 0; i < MAX_FOOD; i++) {
			if (food_count[i] != 0) {
				printf("$$$\t%-d\t\t\t%-20s\t\t\t%-d\n", foods[i].num ,foods[i].name, food_count[i]);
			}
		}
	}
}

void free_all_orders() //格式化链表函数
{
	link p = order_list;
	while (p != NULL) {
		link temp = p;
		p = p->next;
		for (int i = 0; i < MAX_FOOD; i++) {
			free(temp->food_name[i]); //释放每个结点的food_name数组的空间
		}
		free(temp);//清除每个链表的数据
	}
	order_list = NULL;
}

void write_in_order(int id)//所有订单写入文件函数
{
	double A = 0, B = 0, C = 0, D = 0;
	link p = order_list;
	FILE* file;
	file = fopen("All_orders_information.txt", "w");//打开文件
	if (p == NULL){
		printf("\n\n");
		printf("*****************************************************************\n\n");
		printf("$$$\t*******  Order not found!No need to write in!!  *******\n\n");
		printf("*****************************************************************\n");
	}
	else {
		while (p != NULL) {//使用fprintf函数写入文件
				fprintf(file, "*************************************************\n\n");
				fprintf(file, "Order id:%d\n", p->id);
				fprintf(file, "Name:%s\n", p->name);
				fprintf(file, "Age:%d\n", p->age);
				fprintf(file, "Phone numbers:%s\n", p->phone);
				fprintf(file, "Address:%s\n", p->address);
				fprintf(file, "----------------------------------------\n");
				for (int i = 0; i < MAX_FOOD; i++) {
					if (p->food_id[i] != 0) {//前面将在create_order函数中将food_id[]数组初始化为0,这样在这里就可以读取有用的数据 
						fprintf(file, "Food id:%d\n", p->food_id[i]);
						fprintf(file, "Food name:%s\n", p->food_name[i]);
						fprintf(file, "Food quantity:%d\n", p->food_quantity[i]);
						fprintf(file, "Food unit price:$%.2lf\n", foods[p->food_id[i]-1].price);
						fprintf(file, "Food total price:$%.2lf\n", (foods[p->food_id[i]-1].price) * (p->food_quantity[i]));
						fprintf(file, "----------------------------------------\n");}
				}
				A += p->total_price; B += p->cost; C += p->profit; D = C / B;
				fprintf(file, "Total price:$%.2lf\n", p->total_price);
				fprintf(file, "Income:$%.2lf\n", p->total_price);
				fprintf(file, "Cost:$%.2lf\n", p->cost);
				fprintf(file, "Profit:$%.2lf\n", p->profit);
				fprintf(file, "Profit margin:%.3lf\n\n", p->profit_margin);
				fprintf(file, "*************************************************\n");
				p = p->next;
			}
		fprintf(file, "Total income:$%.2lf  \tAverage income:$%.2lf\n",A,A/id);
		fprintf(file, "Total cost:$%.2lf    \tAverage cost:$%.2lf\n",B,B/id);
		fprintf(file, "Total profit:$%.2lf  \tAverage profit:$%.2lf\n",C,C/id);
		fprintf(file, "Total profit margin:%.3lf\n\n",D);
		printf("\n\n");
		printf("*****************************************************************\n\n");
		printf("$$$\t******  Successfully write in!!  ******\n\n");
		printf("*****************************************************************\n");
		}
		fclose(file);//关闭文件,结束写入
}

void check_information_txt() //查看写入文件函数
{
	FILE* file = NULL;
	char b;
	char* a;//定义指针
	file = fopen("All_orders_information.txt", "r");//以只读方式打开文件
	if (file == NULL) {
		printf("\n\n");
		printf("*****************************************************************\n\n");
		printf("$$$\t**** Warning!Failed to open file! ****\n\n");
		printf("*****************************************************************\n");
		system("pause");
	}
	b = fgetc(file);
	if (b == EOF) {//判断文件是否为空
		printf("\n\n");
		printf("*****************************************************************\n\n");
		printf("$$$\t****** Warning!Empty file! ******\n\n");
		printf("*****************************************************************\n");
		system("pause");
		fclose(file);
	}
	else{
		clock_t start, end;
		start = clock();
		size_t c;
		a = (char*)calloc(101,sizeof(char)); //为读取辅助指针动态分配空间,101是因为有最后的结束符'\0'
		while (1) {
			c = fread(a, sizeof(char), 100, file);//从文件中读取100个字节的数据，存入c指针所指向的内存空间
			if (c == 0) { break; }//如果为零，说明已经到达文件末尾或者发生了错误，跳出循环
			a[c] = '\0';
			printf("%s", a);
		}
		end = clock();
		printf("\n\n");
		printf("Generate time:%.6lfms\n\n\n", (((double)(end - start)) / CLOCKS_PER_SEC));
		system("pause");
		free(a);
		fclose(file); //关闭文件	
	}
}


link Random_order_information(int id)
{
	link customer = (order*)malloc(sizeof(order));
	if (customer == NULL) {
		printf("$$$\tWarning! Memory allocation failed!\n");//防止内存分配失败
		return NULL;}
	int n = 0;
	for (n = 0; n < MAX_FOOD; n++) {
		customer->food_name[n] = (char*)calloc(50, sizeof(char));//通过循环为指向字符串的指针数组的每一个指针动态分配内存空间,防止报错,使用calloc可分配内存并初始化指针
	}
	memset(customer->food_id, 0, sizeof(customer->food_id));//初始化餐品编号数组为0,方便后续操作,防止报错
	memset(customer->food_quantity, 0, sizeof(customer->food_quantity));//初始化餐品数量数组为0,方便后续操作,防止报错
	int a, b, random1[18] = { 0 };//尽量使随机数不重复
	for (a = 0; a < 18; a++) {
		random1[a] = rand() % 18;
		for (b = 0; b < a; b++) {
			if (random1[b] == random1[a]) {
				a--;}//若随机数相同,则再生成直到不同为止
		}
	}
	customer->id = id;
	char first_names[][10] = { "罗","陈","莫","倪","钟","刘","李","尹","曹","苏","梁"};
	char last_names[][10] = { "辉","东","越","杰","舜","妮","艳","嫣","莹","桐","瑜","娴"};
	//结合现实虚构名字...如有雷同,纯属巧合..
	int longth_first_names = sizeof(first_names) / sizeof(first_names[0]);//总字节长度除以单个元素的字节长度,准确得到数组中元素的个数
	int longth_last_names = sizeof(last_names) / sizeof(last_names[0]);//总字节长度除以单个元素的字节长度,准确得到数组中元素的个数
	char districts[][20] = { "南山区", "福田区", "罗湖区", "盐田区","宝安区","龙岗区","龙华区","坪山区","光明区"};
	char streets[][40] = { "深圳大学丽湖校区", "深圳大学粤海校区", "南方科技大学", "哈尔滨工业大学深圳校区", "中山大学深圳校区","清华大学研究生院","北京大学研究生院" ,"深圳技术大学","香港中文大学（深圳)","深圳北理莫斯科大学","深圳职业技术大学","深圳理工大学","深圳海洋大学"};
	//结合现实虚构地址...外卖全城送..
	int longth_districts = sizeof(districts) / sizeof(districts[0]);//总字节长度除以单个元素的字节长度,准确得到数组中元素的个数
	int longth_streets = sizeof(streets) / sizeof(streets[0]);//总字节长度除以单个元素的字节长度,准确得到数组中元素的个数
	int random_first_names = rand() % longth_first_names;
	int random_last_names = rand() % longth_last_names;
	sprintf(customer->name, "%s%s", first_names[random_first_names], last_names[random_last_names]);
	customer->age = rand() % 13 + 18;//随机得到年龄在18-30岁的顾客
	sprintf(customer->phone, "1%d%d%d%d%d%d%d%d%d%d",//随机生成11位手机号码
	rand() % 7 + 3, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10,rand() % 10, rand() % 10, rand() % 10,rand() % 10);
	//搜索发现手机号码第二位是3到9
	int random_districts = rand() % longth_districts;
	int random_streets = rand() % longth_streets;
	sprintf(customer->address, "广东省深圳市%s%s%d栋%d宿舍",districts[random_districts], streets[random_streets],rand() % 10 + 1, rand() % 1800 + 1);
	int num_orders = rand() % 10 + 3;//随机生成循环点餐次数
	customer->total_price = 0;//初始化为0,防止累加出错
	double add=0;
	int i=0;
	for ( i = 0; i < num_orders; i++) {
		customer->food_id[i] = foods[random1[i]].num; // 生成随机餐品编号
		strcpy(customer->food_name[i], foods[customer->food_id[i]-1].name); // 生成随机餐品名字
		customer->food_quantity[i] = rand() % 5 + 1; // 生成随机餐品份数
		customer->total_price+= (customer->food_quantity[i]) * (foods[customer->food_id[i]-1].price);
		add += (customer->food_quantity[i] * 2.5);
		customer->cost = add;
		customer->profit=(customer->total_price - add);
		customer->profit_margin = customer->profit / add;
		// 在此处可以处理随机生成的食物信息，例如将其添加到订单中
	}
	customer->next = NULL; //尾插法插入节点
	if (order_list == NULL){
			order_list = customer; // 如果链表为空，将新节点设置为头节点
	}
	else {
			link q = order_list;//定义辅助指针通过循环找到链表尾节点
			while (q->next != NULL) {
				q = q->next;}
			q->next = customer; // 将新节点插入到尾节点后面
	}
	return customer;
}

link copy_order(link head)//复制原订单链表函数
{
	if (head == NULL) 
	{
		return NULL;
	}
	int n=0;
	link new_head = NULL;
	link new_tail = NULL;
	while (head != NULL)
	{
		link p = (link)malloc(sizeof(order));
		for (n = 0; n < MAX_FOOD; n++) {
			p->food_name[n] = (char*)calloc(50, sizeof(char));}//通过循环为指向字符串的指针数组的每一个指针动态分配内存空间,防止报错,使用calloc可分配内存并初始化指针
		memset(p->food_id, 0, sizeof(p->food_id));//初始化餐品编号数组为0,方便后续操作,防止报错
		memset(p->food_quantity, 0, sizeof(p->food_quantity));//初始化餐品数量数组为0,方便后续操作,防止报错
		int elements1 = sizeof(head->food_name) / sizeof(head->food_name[0]);//求food_name中的元素个数
		//复制数据
		p->id = head->id;
		p->age = head->age;
		p->total_price = head->total_price;
		strcpy(p->name, head->name);
		strcpy(p->phone, head->phone);
		strcpy(p->address, head->address);
		p->profit = head->profit;
		p->profit_margin = head->profit_margin;
		p->cost = head->cost;
		for (int t = 0; t < elements1; t++) {
			strcpy(p->food_name[t], head->food_name[t]);
		}
		for (int l = 0; l < MAX_FOOD; l++) {
			p->food_id[l] = head->food_id[l];
			p->food_quantity[l] = head->food_quantity[l];
		}
		p->next = NULL; 
		if (new_head == NULL) {
			new_head = p;
		}
		else {
			new_tail->next = p;// 如果新链表不为空，把新节点插入到尾部
		}
		new_tail = p;
		head = head->next;	//更新原链表的头指针为下一个节点
	}
	return new_head;
}
void sort_order_by_total_price()//按照顾客消费金额由小到大排序函数
//我认为最困难的函数,参考了很多资料,经过无数次调试,各种nullptr错误以及越界错误,最烦人的是内存泄露,幸亏有Visual Leak Detector会自动显示存在内存泄露代码的行数.
// 由于数据众多,单纯交换数据域非常麻烦,所以选择交换节点的指针域,但节点之间是像火车一样通过一节节车厢也就是指针连起来的,使用冒泡法交换两个节点,被交换的第一个节点前面还连有节点,被交换的第二个节点后面还连有节点
//如  head -> 1 -> 2 -> 3 -> 4 -> 5 ->NULL 要交换3,4节点 ,如果没有切断3,4的前后节点连接就会变这样 head -> 1 -> 2 -> 3 -> 4 -> 5 ->NULL 交换了个寂寞
//正确应该是这样的 head -> 1 -> 2 -> 4 -> 3 -> 5 ->NULL ,即切断重连,使指针正确相连
{
	link q = copy_order(order_list);//复制原订单链表,创建临时链表,防止影响原来的链表顺序
	link a = (link)malloc(sizeof(order));
	link b = NULL;
	link tail = NULL;
	for (a->next = q, q = a; q->next != tail; tail = b) {//由于头两个节点的特殊性,直接将a作为q的头节点更加方便比较
		for (a = q, b = a->next; b->next != tail; a = a->next, b = a->next) {
			if (a->next->total_price > b->next->total_price) {
				//									   ↑ -> -> ↓
				//交换指针如 2 -> 3 -> 4 -> 5      2   3 <- 4   5   
				//			 a	  b				   ↓ -> -> ↑
				a->next = b->next; //a->next=3,b->next=4 交换3,4 即使 4 -> 3
				b->next = b->next->next;//b->next=4,b->next->next=5,即使 3 -> 5
				a->next->next = b;//a->next->next=4,b=3,即使 2 -> 4
			}
		}
	}
	q = q->next;
	free(a);//防止内存泄漏,每malloc一次就要检查是否需要free
	link p = q;
	if (p == NULL) {
		printf("\n\n");
		printf("$$$\t***************************************\n\n");
		printf("$$$\t****** Waring!Order not found! ******\n\n");
		printf("$$$\t***************************************\n");
	}
	while (p != NULL) {//通过移动指针循环链表读取数据
		printf("$$$\t**********************************************************************\n");
		print_order(p);
		printf("$$$\tTotal price is:$%.2lf\n\n", p->total_price);
		printf("$$$\tIncome:$%.2lf\n\n", p->total_price);
		printf("$$$\tcost:$%.2lf\n\n", p->cost);
		printf("$$$\tProfit:$%.2lf\n\n",p->profit);
		printf("$$$\tProfit:%.3lf\n",p->profit_margin);
		p = p->next;
		printf("\n");
		printf("$$$\t**********************************************************************\n\n\n");
	}
	p = q; //重置p为q
	while (p != NULL) {
		link temp = p; 
		p = p->next; 
		for (int i = 0; i < MAX_FOOD; i++) {
			free(temp->food_name[i]); //释放每个结点的food_name数组的空间
		}
		free(temp); //释放当前结点
	}
}
void profit(int id)
{
	link p = order_list;
	double total_profit = 0;//总利润
	double total_cost = 0;//总成本
	double total_income = 0;//总收入
	double total_profit_margin=0;//总利润率
	if (p == NULL) {
		printf("\n\n");
		printf("$$$\t****************************************\n\n");
		printf("$$$\t***** Waring!Order not found! *****\n\n");
		printf("$$$\t****************************************\n");
	}
	else {
		while (p != NULL)//历遍链表
		{
			printf("$$$\t***************************\n\n");
			printf("$$$\tOrder id:%d\n\n", p->id);
			printf("$$$\tIncome:$%.2lf\n\n", p->total_price);
			printf("$$$\tCost:$%.2lf\n\n", p->cost);
			printf("$$$\tProfit:$%.2lf\n\n", p->profit);//打印每个订单的利润
			printf("$$$\tProfit margin:%.3lf\n\n", p->profit_margin);//打印每个订单的利润率
			printf("$$$\t***************************\n\n\n");
			total_income += p->total_price;//计算总收入
			total_cost += p->cost;//计算总成本
			total_profit += p->profit;//计算总利润
			p = p->next;
		}
		total_profit_margin = (total_income - total_cost) / total_cost;//计算总利润率 = 总利润 / 总成本
		printf("$$$\tTotal income:$%.2lf   \tAverage income:$%.2lf\n",total_income,total_income/id);
		printf("$$$\tTotal cost:$%.2lf     \tAverage cost:$%.2lf  \n",total_cost,total_cost / id);
		printf("$$$\tTotal cost:$%.2lf     \tAverage cost:$%.2lf  \n",total_profit,total_profit/id);
		printf("$$$\tTotal profit margin:%.3lf\n",total_profit_margin);
		printf("\n");
	}
}

int main()
{
	FILE* file;
	file = fopen("All_orders_information.txt", "w");//使要写入的文件保持空白
	fclose(file);
	clock_t start, end;
	int order_id = 1; int id; int c; char a,b; char password[30] = "0";
	while (1)//循环显示主菜单
	{
		a = main_menu();
		switch (a) {//switch语句此时相比ifelse语句效率更高,因为ifelse还需要一个个判断,必然会消耗资源
		case '1': {//进入顾客订餐系统
			system("cls");
			while (1)
			{
				a = Submenu_for_customer();
				b = _getch();//使用getch函数提高流畅度,不用回车
				switch (b) {
				case '4': { //返回主菜单(部分)先跳出switch语句
					break; }
				case '1': { //显示真菜单
					system("cls");
					menu();
					system("pause");
					system("cls");
					continue; }
				case '2': {//顾客下单
					system("cls");
					char p;
					printf("\n\n");
					printf("$$$\tEnter 1 to continue or enter 0 to quit!\n");
					p = _getch();
					if (p == '1') {
						system("cls");
						printf("\n");
						link new_order = create_order(order_id++);
						if (new_order == NULL) { //检查数据是否输入,链表是否生成
							break;}
						system("cls");
						printf("\n\n\n");
						printf("****************************************************************************************\n\n");
						printf("$$$\t Order is successfully placed!!Your order id is %d!!Please wait patiently!!\n\n", new_order->id);
						printf("****************************************************************************************\n");
						system("pause");
						system("cls");
						break;}
					else if (p == '0') {
						system("cls");
						break;}
					else {
						system("cls");
						printf("\n\n");
						printf("*****************************************************************\n\n");
						printf("********\tPlease enter a correct value!\t\t********\n\n");
						printf("*****************************************************************\n");
						system("pause");
						system("cls");
						continue;}
					break; }
				case '3': {//顾客根据订单id查询订单(与商家不同,顾客只能看到订单总价)
					system("cls");
					printf("\n\n");
					printf("$$$\tPlease enter the order id:(Enter 0 to quit)\n");
					scanf("%d", &id);
					link p = order_list;
					if (p == NULL) {//检查链表是否为空
						system("cls");
						printf("\n\n");
						printf("*****************************************************************\n\n");
						printf("$$$\t*******  Order list is empty!  *******\n\n");
						printf("*****************************************************************\n");
						system("pause");
						system("cls");
						continue;}
					if (id > (order_id - 1)) {//检查链表是否为空以及输入值是否正确
						system("cls");
						printf("\n\n");
						printf("*****************************************************************\n\n");
						printf("$$$\t*******  Order not found!  *******\n\n");
						printf("*****************************************************************\n");
						system("pause");
						system("cls");
						continue;}
					 if (id == 0) {
						break;}
					while (p != NULL) { //循环检视链表,寻找对应id的订单
						if (p->id == id) {
							system("cls");
							print_order(p);
							printf("\n");
							printf("$$$\tTotal price is $%.2lf\n\n\n", p->total_price);
							system("pause");
							system("cls");
							break;}
						p = p->next;
					}
					system("cls");
					continue; }
				default: {//输错值提醒
					system("cls");
					printf("\n\n");
					printf("*****************************************************************\n\n");
					printf("********\tPlease enter a correct value!\t\t********\n\n");
					printf("*****************************************************************\n");
					system("pause");
					system("cls");
					break;
					if (b == '4') {//返回主菜单(部分)再跳出第二个while函数
						break;}}
					break;
				}
				break;
			}
			system("cls");
			break;//返回主菜单(部分)最后跳出第一个while函数返回主菜单while函数
		}
		case '2': {//进入商家管理系统
			system("cls");
			while (1) {
				printf("\n\n");
				printf("$$$\tPleaes enter the password:(Enter 'Q' or 'q' or '0' to quit)\n");
				scanf("%s", password);
				if (strcmp(password, "123456789") == 0) {//简易密码系统
					system("cls");
					while (1) {
						a = Submenu_for_vendors();
						b = _getch();
						switch (b) {
						case '8': {//返回主菜单(部分)先跳出switch语句
							break; }
						case '2': {//打印全部订单
							system("cls");
							start = clock();
							print_all_orders();
							end = clock();
							printf("\n\n");
							printf("Generate time:%.6lfms\n\n\n", (((double)(end - start)) / CLOCKS_PER_SEC));
							system("pause");
							system("cls");
							continue; }
						case '3': {//按顾客消费金额排序订单
							system("cls");
							start = clock();
							sort_order_by_total_price(order_list);
							end = clock();
							printf("\n\n");
							printf("Generate time:%.6lfms\n\n\n", (((double)(end - start)) / CLOCKS_PER_SEC));
							system("pause");
							system("cls");
							continue; }
						case '4': {//所有订单餐品数量分布函数
							system("cls");
							start = clock();
							count_food_distribution();
							end = clock();
							printf("\n\n");
							printf("Generate time:%.6lfms\n\n\n", (((double)(end - start)) / CLOCKS_PER_SEC));
							system("pause");
							system("cls");
							continue; }
						case '5': {//将所有订单写入All_orders_information.txt文件
							system("cls");
							start = clock();
							write_in_order(order_id++);
							end = clock();
							printf("\n\n");
							printf("Generate time:%.6lfms\n\n\n", (((double)(end - start)) / CLOCKS_PER_SEC));
							system("pause");
							system("cls");
							continue; }
						case '6': {//查看All_orders_information.txt文件
							system("cls");
							check_information_txt();
							system("cls");
							continue; }
						case '7': {//查看所有订单收入,成本,利润,利润率以及总收入,总成本,总利润,总利润率
							system("cls");
							start = clock();
							profit(order_id++);
							end = clock();
							printf("\n\n");
							printf("Generate time:%.6lfms\n\n\n", (((double)(end - start)) / CLOCKS_PER_SEC));
							system("pause");
							system("cls");
							continue; }
						case '1': {//商家根据订单id查看订单(与顾客不同,商家可以看到订单收入,成本,利润,利润率)
							system("cls");
							printf("\n\n");
							printf("$$$\tPlease enter the order id:(Enter 0 to quit)\n");
							scanf("%d", &id);
							link p = order_list;
							if (p == NULL) {//检查链表是否为空
								system("cls");
								printf("\n\n");
								printf("*****************************************************************\n\n");
								printf("$$$\t*******  Order list is empty!  *******\n\n");
								printf("*****************************************************************\n");
								system("pause");
								system("cls");
								continue;}
							if ( id > (order_id-1)) {//检查输入值是否正确
								system("cls");
								printf("\n\n");
								printf("*****************************************************************\n\n");
								printf("$$$\t*******  Order not found!  *******\n\n");
								printf("*****************************************************************\n");
								system("pause");
								system("cls");
								continue;}
							if (id == 0) {
								break;}
							start = clock();
							while (p != NULL) { //循环检视链表,寻找对应id的订单
								if (p->id == id) {
									system("cls");
									print_order(p);
									printf("\n");
									printf("$$$\tTotal price is $%.2lf\n\n", p->total_price);
									printf("$$$\tIncome:$%.2lf\n\n", p->total_price);
									printf("$$$\tCost:$%.2lf\n\n", p->cost);
									printf("$$$\tProfit:$%.2lf\n\n", p->profit);
									printf("$$$\tProfit margin:%.3lf\n\n\n\n", p->profit_margin);
									end = clock();
									printf("Generate time:%.6lfms\n\n\n", (((double)(end - start)) / CLOCKS_PER_SEC));
									system("pause");
									system("cls");
									break;}
								p = p->next;
							}
							continue; }
						default: {//输错值
							system("cls");
							printf("\n\n");
							printf("*****************************************************************\n\n");
							printf("********\tPlease enter a correct value!\t\t********\n\n");
							printf("*****************************************************************\n");
							system("pause");
							system("cls");
							break; }
							   if (b == '8') {//返回主菜单(部分)再跳出第二个while函数
								   break; }}
					 break;
					}
					system("cls");
					break;//返回主菜单(部分)最后跳出第一个while函数返回主菜单while函数
				}
				else if ((strcmp(password, "q") == 0) || (strcmp(password, "0") == 0) || (strcmp(password, "Q") == 0)) {
					system("cls");
					break;}
				else {
					system("cls");
					printf("\n\n\n");
					printf("*****************************************************************\n\n");
					printf("$$$\t*****   Warning!Access Denyed!!  *****\n\n");
					printf("*****************************************************************\n");
					system("pause");
					system("cls");
					continue;}
			}
			break;
		}
		case '3': {
			srand((unsigned int)time(0));
			system("cls");
			printf("\n\n");
			printf("$$$\tHow much customers' information you want to random generate(Enter '0' to quit)\n");
			scanf("%d", &c);
			start = clock();
			if (c <= 1000 && c != 0) {
				for (int i = 0; i < c; i++) {
					Random_order_information(order_id++);}
				end = clock();
				system("cls");
				printf("\n\n");
				printf("*****************************************************************\n\n");
				printf("$$$\t**** Successfully generated!! ****\n\n");
				printf("*****************************************************************\n\n\n");
				printf("Generate time:%.6lfms\n\n", (((double)(end-start))/CLOCKS_PER_SEC));
				system("pause");
				system("cls");}
			else if (c > 1000||c < 0) {
				system("cls");
				printf("\n\n");
				printf("*****************************************************************\n\n");
				printf("$$$\t**** illegal value! Please enter a value between 1 and 100 !****\n\n");
				printf("*****************************************************************\n");
				system("pause");
				system("cls");}
			else if (c == 0) {
				system("cls");
				break;}
			break;}
		case '4': {//格式化链表
			free_all_orders();
			order_id = 1;//重置订单id为1,重新开始计数
			system("cls");
			printf("\n\n");
			printf("*****************************************************************\n\n");
			printf("$$$\t**** Successfully refreshed !****\n\n");
			printf("*****************************************************************\n");
			system("pause");
			system("cls");
			break;}
		case '5': {//退出系统
			printf("********\tWelcome your coming again and thanks for your patronizing!!!\t\t********\n");
			free_all_orders();
			exit(0);//退出程序
			break;}
		default: {//输错值
			system("cls");
			printf("\n\n");
			printf("*****************************************************************\n\n");
			printf("********\tPlease enter a correct value!\t\t********\n\n");
			printf("*****************************************************************\n");
			system("pause");
			system("cls");
			break;}
		}
	}
}