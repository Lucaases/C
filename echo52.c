#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct foods {
    int num;         // 餐品编号
    char name[30];   // 餐品名称
    int price;       // 餐品价格
} food;

food foods[18] = {
    {1, "Cappuccino", 2}, {2, "Latte", 2}, {3, "Espresso", 2}, {4, "Americano", 3},
    {5, "Caffè mocha", 3}, {6, "Caffè macchiato", 3}, {7, "Hot tea, HongKong style", 1},
    {8, "Chocolate milk tea", 1}, {9, "Strawberry milk tea", 3}, {10, "Coconut milk tea", 3},
    {11, "Caramel Bubble Milk Tea", 3}, {12, "Honey Boba Frosty Milk", 3},
    {13, "Stinky Tofu", 3}, {14, "French fries", 5}, {15, "Fried Chicken Leg", 3},
    {16, "Cold Rice Noodles", 5}, {17, "Milk Custard", 5}, {18, "Water - lce", 5}
};

void generateRandomOrder() {
    srand(time(NULL));  // 使用当前时间作为随机数种子

    int numOrders = rand() % 5 + 1;  // 随机生成1-5份餐品

    printf("顾客点餐：\n");
    for (int i = 0; i < numOrders; i++) {
        int randomFoodIndex = rand() % 18;  // 随机选择一个餐品
        food randomFood = foods[randomFoodIndex];  // 获取随机选择的餐品信息

        printf("餐品名称： %s\n", randomFood.name);
        printf("餐品价格： %d\n", randomFood.price);
        printf("--------------\n");
    }
}

int main() {
    generateRandomOrder();
    system("pause");
    return 0;
}