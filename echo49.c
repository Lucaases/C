#include <stdio.h>
#include <string.h>
// 定义一个交换两个字符串的函数
void swap_strings(char *a, char *b) {
  // 用一个临时变量存储一个字符串的值
  char temp[20];
  strcpy(temp, a);
  // 将另一个字符串的值赋给第一个字符串
  strcpy(a, b);
  // 将临时变量的值赋给第二个字符串
  strcpy(b, temp);
}

// 定义一个用冒泡法对字符串进行排序的函数
void bubble_sort_strings(char strings[][20], int n) {
  // 外层循环控制比较的轮数，每一轮都会将最大的字符串放到最后
  for (int i = 0; i < n - 1; i++) {
    // 内层循环控制每一轮比较的次数，每一次都会比较相邻的两个字符串
    for (int j = 0; j < n - 1 - i; j++) {
      // 如果前一个字符串大于后一个字符串，就交换它们的位置
      if (strcmp(strings[j], strings[j + 1]) > 0) {
        swap_strings(strings[j], strings[j + 1]);
      }
    }
  }
}

// 测试代码
int main() {
  char strings[5][20] = {"apple", "dragonfruit", "elderberry", "banana", "cherry"};
  int n = sizeof(strings) / sizeof(strings[0]);
  printf("排序前的字符串列表：\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", strings[i]);
  }
  bubble_sort_strings(strings, n);
  printf("排序后的字符串列表：\n");
  for (int i = 0; i < n; i++) {
    printf("%s\n", strings[i]);
  }
    system("pause");
  return 0;
}