#include <stdio.h>

int main()

{

 char c;
 int letters=0,space=0,digit=0,other=0;
 while ((c=getchar())!='\n')
 {
    if (c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z'){
         letters++;}
    else if (c == ' '){
    space++;}
    else if (c >= '0'&&c <= '9'){
    digit++;}
    else{
    other++;}
}

 printf("%d %d %d %d",letters,space,digit,other);
system("pause");
 return 0;

}
