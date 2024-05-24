#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define MAX 20

/**
 * Struktur data stack
 * stackk: struktur data stack
 * s: array of stackk
 * top: indeks top dari stack
*/
struct stackk{
    char stack[MAX];
};

struct stackk s[MAX];
int top=-1;

/**
 * Fungsi untuk mengosongkan stack
*/
void clearStack(){
    top = -1;
}


/**
 * Fungsi untuk mengecek apakah stack penuh
 * return 1 jika penuh, 0 jika tidak
*/
int isFull(){
    if(top==MAX-1){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Fungsi untuk mengecek apakah stack kosong
 * return 1 jika kosong, 0 jika tidak
*/
int isEmpty(){
    if(top==-1){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Fungsi untuk menambahkan item ke dalam stack
 * item: item yang akan ditambahkan
*/
void push(char *item){
    if(isFull()){
        printf("Overflow detected!\n");
    }else{
        top++;
        strcpy(s[top].stack,item);
    }
}

/**
 * Fungsi untuk menghapus item dari stack
 * return item yang dihapus
*/
char *pop(){
    if(isEmpty()){
        printf("Underflow detected!\n");
        return NULL;
    }else{
        return s[top--].stack;
    }
}

/**
 * Fungsi untuk mengecek apakah karakter adalah operator
 * return 1 jika operator, 0 jika tidak
 * c: karakter yang akan dicek
 * 
*/
int isOperator(char c){
    if(c=='+' || c=='-' || c=='*' || c=='/' || c=='^'){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Fungsi untuk mengecek prioritas operator
 * return prioritas operator
 * c: operator yang akan dicek
 * prcd = precedence = prioritas
*/
int prcd(char c){
    if(c==')'){
        return 0;
    }else if(c=='+' || c=='-'){
        return 1;
    }else if(c=='*' || c=='/'){
        return 2;
    }else{
        return -1;
    }
}

/**
 * Fungsi untuk mengecek apakah karakter adalah operand
 * return 1 jika operand, 0 jika tidak
 * c: karakter yang akan dicek
*/
int isOperand(char c){
    if(c>='0' && c<='9'){
        return 1;
    }else if(c>='a' && c<='z'){
        return 1;
    }else if(c>='A' && c<='Z'){
        return 1;
    }else{
        return 0;
    }
}

/**
 * Fungsi untuk mengkonversi postfix ke infix
 * postfix: postfix yang akan dikonversi
*/
void convertToInfix(char *postfix){
    int i=0; // indeks
    while(postfix[i]!='\0'){ // looping sampai karakter terakhir dari postfix 
        char exp[MAX]={'\0'},op1[MAX]={'\0'},op2[MAX]={'\0'}; // inisialisasi string
        char temp[2] = {postfix[i], '\0'}; // temp = karakter
        if(isOperand(temp[0])){ // jika karakter adalah operand, maka push ke dalam stack
            push(temp);
        }else if(isOperator(temp[0])){ // jika karakter adalah operator, maka pop 2 kali dari stack, lalu gabungkan dengan operator, lalu push ke dalam stack
            strcpy(op2,pop()); // pop dari stack
            strcpy(op1,pop()); // pop dari stack
            char op[2] = {'(', '\0'}; // op = kurung buka
            char cl[2] = {')', '\0'}; // cl = kurung tutup
            strcat(exp,op); // gabungkan kurung buka
            strcat(exp,op1); // gabungkan operand 1
            strcat(exp,temp); // gabungkan operator
            strcat(exp,op2); // gabungkan operand 2
            strcat(exp,cl); // gabungkan kurung tutup
            push(exp); // push ke dalam stack
        }else{
            printf("Invalid Arithmetic expression!\n");
            exit(0);
        }
        i++; // increment indeks
    }
    printf("The infix expression is: ");
    puts(s[0].stack); // tampilkan infix
    clearStack(); // kosongkan stack
}

/**
 * Fungsi untuk mengkonversi prefix ke postfix
 * prefix: prefix yang akan dikonversi
*/
void convertToPostfix(char *prefix){
    int i = strlen(prefix) - 1; // indeks
    while(i >= 0){ // looping sampai karakter pertama dari prefix
        char exp[MAX]={'\0'},op1[MAX]={'\0'},op2[MAX]={'\0'}; // inisialisasi string
        char temp[2] = {prefix[i], '\0'}; // temp = karakter
        if(isOperand(temp[0])){ // jika karakter adalah operand, maka push ke dalam stack
            push(temp); // push ke dalam stack
        }else if(isOperator(temp[0])){  // jika karakter adalah operator, maka pop 2 kali dari stack, lalu gabungkan dengan operator, lalu push ke dalam stack
            strcpy(op1,pop()); // pop dari stack
            strcpy(op2,pop()); // pop dari stack
            strcat(exp,op1); // gabungkan operand 1
            strcat(exp,op2); // gabungkan operand 2
            strcat(exp,temp); // gabungkan operator
            push(exp); // push ke dalam stack
        }else{
            printf("Invalid Arithmetic expression!\n"); // jika karakter bukan operator atau operand, maka keluar dari program
            exit(0);
        }
        i--; // decrement indeks
    }
    printf("The postfix expression is: "); // tampilkan postfix
    puts(s[0].stack); // tampilkan postfix
    clearStack(); // kosongkan stack
}


/**
 * Fungsi untuk membalikkan string
 * str: string yang akan dibalik
*/
void reverseString(char *str){
    int i, j; // indeks
    char temp; // karakter sementara
    for(i = 0, j = strlen(str) - 1; i < j; i++, j--){ // looping untuk setiap karakter dari string
        temp = str[i]; // temp = karakter
        str[i] = str[j]; // karakter pertama = karakter terakhir
        str[j] = temp; // karakter terakhir = karakter pertama
    }
}

/**
 * Fungsi untuk mengkonversi infix ke prefix
 * infix: infix yang akan dikonversi
*/
void convertToPrefix(char *infix){
    int i, top = -1; // initialisasi top = -1
    char stack[MAX]; // stack
    char prefix[MAX] = ""; // prefix kosong
    for(i = strlen(infix) - 1; i >= 0; i--){ // looping untuk setiap karakter dari infix
        if(isOperand(infix[i])){ // jika karakter adalah operand, maka tambahkan ke dalam prefix
            char temp[2] = {infix[i], '\0'}; // temp = karakter
            strcat(prefix, temp); // tambahkan karakter ke dalam prefix
        }else if(infix[i] == ')'){ // jika karakter adalah kurung tutup, maka push ke dalam stack
            stack[++top] = infix[i]; // push ke dalam stack
        }else if(infix[i] == '('){ // jika karakter adalah kurung buka, maka pop dari stack sampai menemukan kurung tutup
            while(top != -1 && stack[top] != ')'){ // looping sampai stack kosong atau menemukan kurung tutup
                char temp[2] = {stack[top--], '\0'}; // temp = karakter
                strcat(prefix, temp); // tambahkan karakter ke dalam prefix
            } 
            if(top != -1){ // jika stack tidak kosong, maka pop kurung tutup
                top--; 
            }
        }else if(isOperator(infix[i])){ // jika karakter adalah operator, maka pop dari stack sampai menemukan operator dengan prioritas lebih rendah
            while(top != -1 && prcd(stack[top]) > prcd(infix[i])){ // looping sampai stack kosong atau menemukan operator dengan prioritas lebih rendah
                char temp[2] = {stack[top--], '\0'}; // temp = karakter
                strcat(prefix, temp); // tambahkan karakter ke dalam prefix
            }
            stack[++top] = infix[i]; // push operator ke dalam stack
        }
    }
    while(top != -1){
        char temp[2] = {stack[top--], '\0'};
        strcat(prefix, temp);
    }
    reverseString(prefix);
    printf("The prefix expression is: %s\n", prefix);
    clearStack(); // kosongkan stack
}

/**
 * Fungsi untuk menampilkan menu
*/
void menu(){
    printf("|-----------------------------------|\n");
    printf("| Arithmetic Expression Conversion  |\n");
    printf("|-----------------------------------|\n");
    printf("| 1. Convert Postfix to Infix       |\n");
    printf("| 2. Convert Prefix to Postfix      |\n");
    printf("| 3. Convert Infix to Prefix        |\n");
    printf("|-----------------------------------|\n");
    printf("| 0. Exit                           |\n");
    printf("|-----------------------------------|\n");

    int choice;
    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice){
        case 1:{
            char postfix[MAX];
            printf("Enter the postfix expression: ");
            scanf("%s",postfix);
            convertToInfix(postfix);
            break;
        }
        case 2:{
            char prefix[MAX];
            printf("Enter the prefix expression: ");
            scanf("%s",prefix);
            convertToPostfix(prefix);
            break;
        }
        case 3:{
            char infix[MAX];
            printf("Enter the infix expression: ");
            scanf("%s",infix);
            convertToPrefix(infix);
            break;
        }
        case 0:{
            exit(0);
        }
        default:{
            printf("Invalid choice!\n");
        }
    }
}

/**
 * Fungsi utama
*/
int main(){
    while(1){
        menu();
    }
    return 0;
}
