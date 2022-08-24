#ifndef _LINKLIST_H_
#define _LINKLIST_H_
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

//定义相关量的宏
#define MAX_ID 16
#define MAX_NAME 16
#define MAX 64
#define MAX_TELNUM 12

typedef struct //声明一个结构体
{
	char id[MAX_ID];//ID
	char name[MAX_NAME];//姓名
	char telnum[MAX_TELNUM];//手机号码

}DataType;

//定义结构体
typedef struct node
{
    DataType data;  //数据域
    struct node *next;  //指针域

}linklist;

//欢迎
void welcome();

//目录
void menu();

//通讯录链表的建立
void *LinklistCreate();

//数据的插入（尾插法）
void LinklistInsertTail(linklist *contact);

//删除
void LinklistDelete(linklist *contact);

//遍历通讯录
void LinklistPrint(linklist *contact);

//查找
void SearchContact(linklist *contact);

//修改
void ModifyContact(linklist *contact);

//清空
void ContactClear(linklist *contact);

//联系人排序
void SortContact(linklist *contact);

//通讯录信息保存
void SaveContact(linklist *contact);

//通讯录信息读取
void LoadContact(linklist *contact);

//音乐
void Music();

//vip
void VIP();
#endif