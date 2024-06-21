#include "NIUBI Cafe FOS System.h"

char main_menu()//���˵�����
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

void menu() //��˵�����
{
	printf("\n\n");
	printf("$$$\t1.Cafes\n\n");
	printf("$$$\t(1)Cappuccino $3.99\n\t(2)Latte $2.99\n\t(3)Espresso $3.99\n\t(4)Americano $2.99\n\t(5)Caff�� mocha $2.99\n\t(6)Caff�� macchiato $2.99\n\n\n");
	printf("$$$\t2.Milk Teas\n\n");
	printf("$$$\t(7)Hot tea,HongKong style $1.99\n\t(8)Chocolate milk tea $2.99\n\t(9)Strawberry milk tea $2.99\n\t(10)Coconut milk tea $3.49\n\t(11)Caramel Bubble Milk Tea $3.49\n\t(12)Honey Boba Frosty Milk $3.49\n\n\n");
	printf("$$$\t3.Snacks\n\n");
	printf("$$$\t(13)Stinky Tofu  $2.99\n\t(14)French fries $3.99\n\t(15)Fried Chicken Leg $1.49\n\t(16)Cold Rice Noodles $6.49\n\t(17)Milk Custard $5.99\n\t(18)Water-lce $4.99\n\n\n");
}

char Submenu_for_customer()// �Ӳ˵�(�˿�)����
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

char Submenu_for_vendors()// �Ӳ˵�(�̼�)����
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

link create_order(int id)//�˿��µ�����
{
	link new_order = (link)malloc(sizeof(order));//������̬����,Ϊnew_order(ָ��ṹ��order��ָ��)��̬�����ڴ�
	if (new_order == NULL) {//��ֹ�ڴ�������
		printf("$$$\tWarning! Memory allocation failed!\n");
		return NULL;}
	new_order->id = id;//ƥ�䶩��id,�������Ĵ�ӡ��������
	printf("$$$\tPlease enter the customer's name:\n");
	scanf("%50s", new_order->name);
	printf("$$$\tPlease enter the customer's age:\n");
	scanf("%d", &(new_order->age));
	getchar();//����scanf�����������س����»��з�,Ҫʹfgets����ִ��,����ʹ��getcahr���������з����ĵ�
	printf("$$$\tPlease enter the customer's phone:\n");
	fgets(new_order->phone, 30, stdin);
	printf("$$$\tPlease enter the customer's address:\n");
	fgets(new_order->address, 150, stdin);
	int i = 0;int n = 0;int a;double add = 0;
	new_order->total_price = 0;//��ʼ��total_priceΪ0,��ֹ������ۼ���ͳ���
	for (n = 0; n < MAX_FOOD; n++) {
		new_order->food_name[n] = (char*)calloc(50, sizeof(char));}//��ʼ����Ʒ�������Ϊ0,�����������,��ֹ����
	memset(new_order->food_id, 0, sizeof(new_order->food_id));//��ʼ����Ʒ�������Ϊ0,�����������,��ֹ����
	memset(new_order->food_quantity, 0, sizeof(new_order->food_quantity));//��ʼ����Ʒ��������Ϊ0,�����������,��ֹ����
	system("cls");
	menu();//��ӡ�˵�,������
	printf("\n\n");
	while (1) { //�ù˿�ѭ�����������Ʒ�ı���Լ�����,ȷ���˿��ܵ��ݲ�Ʒ,���ֲ�Ʒ
		if (i >= MAX_FOOD) {
			printf("$$$\tMaximum food limit reached.\n");//��ֹ�����������Ƶ��³������
			break;}
		printf("$$$\tPlease enter the food id you want to order (enter 0 to end):\n");
		scanf("%d", &a);
		if (a == 0) {
			break;}//����0����ѭ��,���������
		
		if (a < 1 || a > MAX_FOOD) {
			printf("$$$\tInvalid food id!\n");//ȷ���˿���ȷ�����Ʒ���
			continue;}
		//�����ݴ�������ڵ��������
		new_order->food_id[i] = a;
		strcpy(new_order->food_name[i], foods[a - 1].name);
		printf("$$$\tPlease enter the food count:\n");
		scanf("%d", &new_order->food_quantity[i]);
		new_order->total_price += (new_order->food_quantity[i]) * foods[a - 1].price;
		add += (new_order->food_quantity[i] * 2.5); //����ÿ��ʳƷԭ����+�ӹ�+���ͷѵĳɱ�Ϊ2.5��Ԫ
		new_order->cost = add;
		new_order->profit = (new_order->total_price - add);
		new_order->profit_margin = new_order->profit / add;
		i++;
	}

	//new_order->next = order_list;//ͷ�巨����ڵ�
	//order_list = new_order;
	//return new_order;

	new_order->next = NULL; //β�巨����ڵ�(����ѡ��β�巨����Ϊid��Ŵ�1��ʼ����,������id��Ŵ�Ķ���Ӧ�����ں���)
	if (order_list == NULL) {
		order_list = new_order; // �������Ϊ�գ����½ڵ�����Ϊͷ�ڵ�
	}
	else {
		link p = order_list;//���帨��ָ��ͨ��ѭ���ҵ�����β�ڵ�
		while (p->next != NULL) {
			p = p->next; }
		p->next = new_order; // ���½ڵ���뵽β�ڵ����
	}
	return new_order;
}

void print_order(link order) //��ӡ�ض���������
{
    if (order == NULL) {
        printf("$$$\t**** Invalid order! *****\n");
        return;}
	//��ӡ������Ϣ
    printf("$$$\tOrder id: %d\n\n", order->id); 
    printf("$$$\tCustomer name: %s\n\n", order->name);
    printf("$$$\tCustomer age: %d\n\n", order->age); 
    printf("$$$\tCustomer phone: %s\n\n", order->phone);
    printf("$$$\tCustomer address: %s\n\n", order->address); 
    printf("$$$\tFood id\t\tFood name\t\t\tFood count\t\tFood unit price\t\tFood total price\n"); 
    for (int i = 0; i < MAX_FOOD; i++) {
        if (order->food_id[i] != 0) { //ǰ�潫��create_order�����н�food_id[]�����ʼ��Ϊ0,����������Ϳ��Զ�ȡ���õ�����
            printf("$$$\t%-5d\t\t%-20s\t\t%6d\t\t\t$%-5.2lf\t\t\t$%-5.2lf\n", order->food_id[i], order->food_name[i], order->food_quantity[i], foods[order->food_id[i] - 1].price,(foods[order->food_id[i] - 1].price)* (order->food_quantity[i]));
		}
    }
	printf("\n");
}

void print_all_orders() //��ӡȫ����������
{
	link p = order_list; 
	if (p == NULL) {
		printf("\n\n");
		printf("$$$\t***************************************\n\n");
		printf("$$$\t****** Waring!Order not found! ******\n\n");
		printf("$$$\t***************************************\n");
	}
	while (p != NULL) {//ͨ���ƶ�ָ��ѭ�������ȡ����
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

void count_food_distribution() //�������ж���ʳ�������ֲ�����
{
	int i = 0;
	int food_count[18] = { 0 };//���������ֲ�ͳ������,����ʼ��Ϊ0,��ֹ����
	link p = order_list;//���帨��ָ��ѭ����������
	if (p == NULL) {
		printf("\n\n");
		printf("$$$\t************************************\n\n");
		printf("$$$\t***** Waring!Order not found! *****\n\n");
		printf("$$$\t***********************************\n");
	}
	else {
		for (p = order_list; p != NULL; p = p->next) {
			for ( i = 0; i < MAX_FOOD; i++) {
				if (p->food_id[i] != 0) {//ǰ�潫��create_order�����н�food_id[]�����ʼ��Ϊ0,����������Ϳ��Զ�ȡ���õ����� 
					food_count[p->food_id[i]-1] += p->food_quantity[i];//����������⵽�Ĳ�Ʒ�����ۼ�
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

void free_all_orders() //��ʽ��������
{
	link p = order_list;
	while (p != NULL) {
		link temp = p;
		p = p->next;
		for (int i = 0; i < MAX_FOOD; i++) {
			free(temp->food_name[i]); //�ͷ�ÿ������food_name����Ŀռ�
		}
		free(temp);//���ÿ�����������
	}
	order_list = NULL;
}

void write_in_order(int id)//���ж���д���ļ�����
{
	double A = 0, B = 0, C = 0, D = 0;
	link p = order_list;
	FILE* file;
	file = fopen("All_orders_information.txt", "w");//���ļ�
	if (p == NULL){
		printf("\n\n");
		printf("*****************************************************************\n\n");
		printf("$$$\t*******  Order not found!No need to write in!!  *******\n\n");
		printf("*****************************************************************\n");
	}
	else {
		while (p != NULL) {//ʹ��fprintf����д���ļ�
				fprintf(file, "*************************************************\n\n");
				fprintf(file, "Order id:%d\n", p->id);
				fprintf(file, "Name:%s\n", p->name);
				fprintf(file, "Age:%d\n", p->age);
				fprintf(file, "Phone numbers:%s\n", p->phone);
				fprintf(file, "Address:%s\n", p->address);
				fprintf(file, "----------------------------------------\n");
				for (int i = 0; i < MAX_FOOD; i++) {
					if (p->food_id[i] != 0) {//ǰ�潫��create_order�����н�food_id[]�����ʼ��Ϊ0,����������Ϳ��Զ�ȡ���õ����� 
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
		fclose(file);//�ر��ļ�,����д��
}

void check_information_txt() //�鿴д���ļ�����
{
	FILE* file = NULL;
	char b;
	char* a;//����ָ��
	file = fopen("All_orders_information.txt", "r");//��ֻ����ʽ���ļ�
	if (file == NULL) {
		printf("\n\n");
		printf("*****************************************************************\n\n");
		printf("$$$\t**** Warning!Failed to open file! ****\n\n");
		printf("*****************************************************************\n");
		system("pause");
	}
	b = fgetc(file);
	if (b == EOF) {//�ж��ļ��Ƿ�Ϊ��
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
		a = (char*)calloc(101,sizeof(char)); //Ϊ��ȡ����ָ�붯̬����ռ�,101����Ϊ�����Ľ�����'\0'
		while (1) {
			c = fread(a, sizeof(char), 100, file);//���ļ��ж�ȡ100���ֽڵ����ݣ�����cָ����ָ����ڴ�ռ�
			if (c == 0) { break; }//���Ϊ�㣬˵���Ѿ������ļ�ĩβ���߷����˴�������ѭ��
			a[c] = '\0';
			printf("%s", a);
		}
		end = clock();
		printf("\n\n");
		printf("Generate time:%.6lfms\n\n\n", (((double)(end - start)) / CLOCKS_PER_SEC));
		system("pause");
		free(a);
		fclose(file); //�ر��ļ�	
	}
}


link Random_order_information(int id)
{
	link customer = (order*)malloc(sizeof(order));
	if (customer == NULL) {
		printf("$$$\tWarning! Memory allocation failed!\n");//��ֹ�ڴ����ʧ��
		return NULL;}
	int n = 0;
	for (n = 0; n < MAX_FOOD; n++) {
		customer->food_name[n] = (char*)calloc(50, sizeof(char));//ͨ��ѭ��Ϊָ���ַ�����ָ�������ÿһ��ָ�붯̬�����ڴ�ռ�,��ֹ����,ʹ��calloc�ɷ����ڴ沢��ʼ��ָ��
	}
	memset(customer->food_id, 0, sizeof(customer->food_id));//��ʼ����Ʒ�������Ϊ0,�����������,��ֹ����
	memset(customer->food_quantity, 0, sizeof(customer->food_quantity));//��ʼ����Ʒ��������Ϊ0,�����������,��ֹ����
	int a, b, random1[18] = { 0 };//����ʹ��������ظ�
	for (a = 0; a < 18; a++) {
		random1[a] = rand() % 18;
		for (b = 0; b < a; b++) {
			if (random1[b] == random1[a]) {
				a--;}//���������ͬ,��������ֱ����ͬΪֹ
		}
	}
	customer->id = id;
	char first_names[][10] = { "��","��","Ī","��","��","��","��","��","��","��","��"};
	char last_names[][10] = { "��","��","Խ","��","˴","��","��","��","Ө","ͩ","�","�"};
	//�����ʵ�鹹����...������ͬ,�����ɺ�..
	int longth_first_names = sizeof(first_names) / sizeof(first_names[0]);//���ֽڳ��ȳ��Ե���Ԫ�ص��ֽڳ���,׼ȷ�õ�������Ԫ�صĸ���
	int longth_last_names = sizeof(last_names) / sizeof(last_names[0]);//���ֽڳ��ȳ��Ե���Ԫ�ص��ֽڳ���,׼ȷ�õ�������Ԫ�صĸ���
	char districts[][20] = { "��ɽ��", "������", "�޺���", "������","������","������","������","ƺɽ��","������"};
	char streets[][40] = { "���ڴ�ѧ����У��", "���ڴ�ѧ����У��", "�Ϸ��Ƽ���ѧ", "��������ҵ��ѧ����У��", "��ɽ��ѧ����У��","�廪��ѧ�о���Ժ","������ѧ�о���Ժ" ,"���ڼ�����ѧ","������Ĵ�ѧ������)","���ڱ���Ī˹�ƴ�ѧ","����ְҵ������ѧ","��������ѧ","���ں����ѧ"};
	//�����ʵ�鹹��ַ...����ȫ����..
	int longth_districts = sizeof(districts) / sizeof(districts[0]);//���ֽڳ��ȳ��Ե���Ԫ�ص��ֽڳ���,׼ȷ�õ�������Ԫ�صĸ���
	int longth_streets = sizeof(streets) / sizeof(streets[0]);//���ֽڳ��ȳ��Ե���Ԫ�ص��ֽڳ���,׼ȷ�õ�������Ԫ�صĸ���
	int random_first_names = rand() % longth_first_names;
	int random_last_names = rand() % longth_last_names;
	sprintf(customer->name, "%s%s", first_names[random_first_names], last_names[random_last_names]);
	customer->age = rand() % 13 + 18;//����õ�������18-30��Ĺ˿�
	sprintf(customer->phone, "1%d%d%d%d%d%d%d%d%d%d",//�������11λ�ֻ�����
	rand() % 7 + 3, rand() % 10, rand() % 10, rand() % 10, rand() % 10, rand() % 10,rand() % 10, rand() % 10, rand() % 10,rand() % 10);
	//���������ֻ�����ڶ�λ��3��9
	int random_districts = rand() % longth_districts;
	int random_streets = rand() % longth_streets;
	sprintf(customer->address, "�㶫ʡ������%s%s%d��%d����",districts[random_districts], streets[random_streets],rand() % 10 + 1, rand() % 1800 + 1);
	int num_orders = rand() % 10 + 3;//�������ѭ����ʹ���
	customer->total_price = 0;//��ʼ��Ϊ0,��ֹ�ۼӳ���
	double add=0;
	int i=0;
	for ( i = 0; i < num_orders; i++) {
		customer->food_id[i] = foods[random1[i]].num; // ���������Ʒ���
		strcpy(customer->food_name[i], foods[customer->food_id[i]-1].name); // ���������Ʒ����
		customer->food_quantity[i] = rand() % 5 + 1; // ���������Ʒ����
		customer->total_price+= (customer->food_quantity[i]) * (foods[customer->food_id[i]-1].price);
		add += (customer->food_quantity[i] * 2.5);
		customer->cost = add;
		customer->profit=(customer->total_price - add);
		customer->profit_margin = customer->profit / add;
		// �ڴ˴����Դ���������ɵ�ʳ����Ϣ�����罫����ӵ�������
	}
	customer->next = NULL; //β�巨����ڵ�
	if (order_list == NULL){
			order_list = customer; // �������Ϊ�գ����½ڵ�����Ϊͷ�ڵ�
	}
	else {
			link q = order_list;//���帨��ָ��ͨ��ѭ���ҵ�����β�ڵ�
			while (q->next != NULL) {
				q = q->next;}
			q->next = customer; // ���½ڵ���뵽β�ڵ����
	}
	return customer;
}

link copy_order(link head)//����ԭ����������
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
			p->food_name[n] = (char*)calloc(50, sizeof(char));}//ͨ��ѭ��Ϊָ���ַ�����ָ�������ÿһ��ָ�붯̬�����ڴ�ռ�,��ֹ����,ʹ��calloc�ɷ����ڴ沢��ʼ��ָ��
		memset(p->food_id, 0, sizeof(p->food_id));//��ʼ����Ʒ�������Ϊ0,�����������,��ֹ����
		memset(p->food_quantity, 0, sizeof(p->food_quantity));//��ʼ����Ʒ��������Ϊ0,�����������,��ֹ����
		int elements1 = sizeof(head->food_name) / sizeof(head->food_name[0]);//��food_name�е�Ԫ�ظ���
		//��������
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
			new_tail->next = p;// ���������Ϊ�գ����½ڵ���뵽β��
		}
		new_tail = p;
		head = head->next;	//����ԭ�����ͷָ��Ϊ��һ���ڵ�
	}
	return new_head;
}
void sort_order_by_total_price()//���չ˿����ѽ����С����������
//����Ϊ�����ѵĺ���,�ο��˺ܶ�����,���������ε���,����nullptr�����Լ�Խ�����,��˵����ڴ�й¶,�ҿ���Visual Leak Detector���Զ���ʾ�����ڴ�й¶���������.
// ���������ڶ�,��������������ǳ��鷳,����ѡ�񽻻��ڵ��ָ����,���ڵ�֮�������һ��ͨ��һ�ڽڳ���Ҳ����ָ����������,ʹ��ð�ݷ����������ڵ�,�������ĵ�һ���ڵ�ǰ�滹���нڵ�,�������ĵڶ����ڵ���滹���нڵ�
//��  head -> 1 -> 2 -> 3 -> 4 -> 5 ->NULL Ҫ����3,4�ڵ� ,���û���ж�3,4��ǰ��ڵ����Ӿͻ������ head -> 1 -> 2 -> 3 -> 4 -> 5 ->NULL �����˸���į
//��ȷӦ���������� head -> 1 -> 2 -> 4 -> 3 -> 5 ->NULL ,���ж�����,ʹָ����ȷ����
{
	link q = copy_order(order_list);//����ԭ��������,������ʱ����,��ֹӰ��ԭ��������˳��
	link a = (link)malloc(sizeof(order));
	link b = NULL;
	link tail = NULL;
	for (a->next = q, q = a; q->next != tail; tail = b) {//����ͷ�����ڵ��������,ֱ�ӽ�a��Ϊq��ͷ�ڵ���ӷ���Ƚ�
		for (a = q, b = a->next; b->next != tail; a = a->next, b = a->next) {
			if (a->next->total_price > b->next->total_price) {
				//									   �� -> -> ��
				//����ָ���� 2 -> 3 -> 4 -> 5      2   3 <- 4   5   
				//			 a	  b				   �� -> -> ��
				a->next = b->next; //a->next=3,b->next=4 ����3,4 ��ʹ 4 -> 3
				b->next = b->next->next;//b->next=4,b->next->next=5,��ʹ 3 -> 5
				a->next->next = b;//a->next->next=4,b=3,��ʹ 2 -> 4
			}
		}
	}
	q = q->next;
	free(a);//��ֹ�ڴ�й©,ÿmallocһ�ξ�Ҫ����Ƿ���Ҫfree
	link p = q;
	if (p == NULL) {
		printf("\n\n");
		printf("$$$\t***************************************\n\n");
		printf("$$$\t****** Waring!Order not found! ******\n\n");
		printf("$$$\t***************************************\n");
	}
	while (p != NULL) {//ͨ���ƶ�ָ��ѭ�������ȡ����
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
	p = q; //����pΪq
	while (p != NULL) {
		link temp = p; 
		p = p->next; 
		for (int i = 0; i < MAX_FOOD; i++) {
			free(temp->food_name[i]); //�ͷ�ÿ������food_name����Ŀռ�
		}
		free(temp); //�ͷŵ�ǰ���
	}
}
void profit(int id)
{
	link p = order_list;
	double total_profit = 0;//������
	double total_cost = 0;//�ܳɱ�
	double total_income = 0;//������
	double total_profit_margin=0;//��������
	if (p == NULL) {
		printf("\n\n");
		printf("$$$\t****************************************\n\n");
		printf("$$$\t***** Waring!Order not found! *****\n\n");
		printf("$$$\t****************************************\n");
	}
	else {
		while (p != NULL)//��������
		{
			printf("$$$\t***************************\n\n");
			printf("$$$\tOrder id:%d\n\n", p->id);
			printf("$$$\tIncome:$%.2lf\n\n", p->total_price);
			printf("$$$\tCost:$%.2lf\n\n", p->cost);
			printf("$$$\tProfit:$%.2lf\n\n", p->profit);//��ӡÿ������������
			printf("$$$\tProfit margin:%.3lf\n\n", p->profit_margin);//��ӡÿ��������������
			printf("$$$\t***************************\n\n\n");
			total_income += p->total_price;//����������
			total_cost += p->cost;//�����ܳɱ�
			total_profit += p->profit;//����������
			p = p->next;
		}
		total_profit_margin = (total_income - total_cost) / total_cost;//������������ = ������ / �ܳɱ�
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
	file = fopen("All_orders_information.txt", "w");//ʹҪд����ļ����ֿհ�
	fclose(file);
	clock_t start, end;
	int order_id = 1; int id; int c; char a,b; char password[30] = "0";
	while (1)//ѭ����ʾ���˵�
	{
		a = main_menu();
		switch (a) {//switch����ʱ���ifelse���Ч�ʸ���,��Ϊifelse����Ҫһ�����ж�,��Ȼ��������Դ
		case '1': {//����˿Ͷ���ϵͳ
			system("cls");
			while (1)
			{
				a = Submenu_for_customer();
				b = _getch();//ʹ��getch�������������,���ûس�
				switch (b) {
				case '4': { //�������˵�(����)������switch���
					break; }
				case '1': { //��ʾ��˵�
					system("cls");
					menu();
					system("pause");
					system("cls");
					continue; }
				case '2': {//�˿��µ�
					system("cls");
					char p;
					printf("\n\n");
					printf("$$$\tEnter 1 to continue or enter 0 to quit!\n");
					p = _getch();
					if (p == '1') {
						system("cls");
						printf("\n");
						link new_order = create_order(order_id++);
						if (new_order == NULL) { //��������Ƿ�����,�����Ƿ�����
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
				case '3': {//�˿͸��ݶ���id��ѯ����(���̼Ҳ�ͬ,�˿�ֻ�ܿ��������ܼ�)
					system("cls");
					printf("\n\n");
					printf("$$$\tPlease enter the order id:(Enter 0 to quit)\n");
					scanf("%d", &id);
					link p = order_list;
					if (p == NULL) {//��������Ƿ�Ϊ��
						system("cls");
						printf("\n\n");
						printf("*****************************************************************\n\n");
						printf("$$$\t*******  Order list is empty!  *******\n\n");
						printf("*****************************************************************\n");
						system("pause");
						system("cls");
						continue;}
					if (id > (order_id - 1)) {//��������Ƿ�Ϊ���Լ�����ֵ�Ƿ���ȷ
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
					while (p != NULL) { //ѭ����������,Ѱ�Ҷ�Ӧid�Ķ���
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
				default: {//���ֵ����
					system("cls");
					printf("\n\n");
					printf("*****************************************************************\n\n");
					printf("********\tPlease enter a correct value!\t\t********\n\n");
					printf("*****************************************************************\n");
					system("pause");
					system("cls");
					break;
					if (b == '4') {//�������˵�(����)�������ڶ���while����
						break;}}
					break;
				}
				break;
			}
			system("cls");
			break;//�������˵�(����)���������һ��while�����������˵�while����
		}
		case '2': {//�����̼ҹ���ϵͳ
			system("cls");
			while (1) {
				printf("\n\n");
				printf("$$$\tPleaes enter the password:(Enter 'Q' or 'q' or '0' to quit)\n");
				scanf("%s", password);
				if (strcmp(password, "123456789") == 0) {//��������ϵͳ
					system("cls");
					while (1) {
						a = Submenu_for_vendors();
						b = _getch();
						switch (b) {
						case '8': {//�������˵�(����)������switch���
							break; }
						case '2': {//��ӡȫ������
							system("cls");
							start = clock();
							print_all_orders();
							end = clock();
							printf("\n\n");
							printf("Generate time:%.6lfms\n\n\n", (((double)(end - start)) / CLOCKS_PER_SEC));
							system("pause");
							system("cls");
							continue; }
						case '3': {//���˿����ѽ�����򶩵�
							system("cls");
							start = clock();
							sort_order_by_total_price(order_list);
							end = clock();
							printf("\n\n");
							printf("Generate time:%.6lfms\n\n\n", (((double)(end - start)) / CLOCKS_PER_SEC));
							system("pause");
							system("cls");
							continue; }
						case '4': {//���ж�����Ʒ�����ֲ�����
							system("cls");
							start = clock();
							count_food_distribution();
							end = clock();
							printf("\n\n");
							printf("Generate time:%.6lfms\n\n\n", (((double)(end - start)) / CLOCKS_PER_SEC));
							system("pause");
							system("cls");
							continue; }
						case '5': {//�����ж���д��All_orders_information.txt�ļ�
							system("cls");
							start = clock();
							write_in_order(order_id++);
							end = clock();
							printf("\n\n");
							printf("Generate time:%.6lfms\n\n\n", (((double)(end - start)) / CLOCKS_PER_SEC));
							system("pause");
							system("cls");
							continue; }
						case '6': {//�鿴All_orders_information.txt�ļ�
							system("cls");
							check_information_txt();
							system("cls");
							continue; }
						case '7': {//�鿴���ж�������,�ɱ�,����,�������Լ�������,�ܳɱ�,������,��������
							system("cls");
							start = clock();
							profit(order_id++);
							end = clock();
							printf("\n\n");
							printf("Generate time:%.6lfms\n\n\n", (((double)(end - start)) / CLOCKS_PER_SEC));
							system("pause");
							system("cls");
							continue; }
						case '1': {//�̼Ҹ��ݶ���id�鿴����(��˿Ͳ�ͬ,�̼ҿ��Կ�����������,�ɱ�,����,������)
							system("cls");
							printf("\n\n");
							printf("$$$\tPlease enter the order id:(Enter 0 to quit)\n");
							scanf("%d", &id);
							link p = order_list;
							if (p == NULL) {//��������Ƿ�Ϊ��
								system("cls");
								printf("\n\n");
								printf("*****************************************************************\n\n");
								printf("$$$\t*******  Order list is empty!  *******\n\n");
								printf("*****************************************************************\n");
								system("pause");
								system("cls");
								continue;}
							if ( id > (order_id-1)) {//�������ֵ�Ƿ���ȷ
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
							while (p != NULL) { //ѭ����������,Ѱ�Ҷ�Ӧid�Ķ���
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
						default: {//���ֵ
							system("cls");
							printf("\n\n");
							printf("*****************************************************************\n\n");
							printf("********\tPlease enter a correct value!\t\t********\n\n");
							printf("*****************************************************************\n");
							system("pause");
							system("cls");
							break; }
							   if (b == '8') {//�������˵�(����)�������ڶ���while����
								   break; }}
					 break;
					}
					system("cls");
					break;//�������˵�(����)���������һ��while�����������˵�while����
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
		case '4': {//��ʽ������
			free_all_orders();
			order_id = 1;//���ö���idΪ1,���¿�ʼ����
			system("cls");
			printf("\n\n");
			printf("*****************************************************************\n\n");
			printf("$$$\t**** Successfully refreshed !****\n\n");
			printf("*****************************************************************\n");
			system("pause");
			system("cls");
			break;}
		case '5': {//�˳�ϵͳ
			printf("********\tWelcome your coming again and thanks for your patronizing!!!\t\t********\n");
			free_all_orders();
			exit(0);//�˳�����
			break;}
		default: {//���ֵ
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