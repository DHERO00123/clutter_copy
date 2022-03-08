#ifndef _HEAD_H
#define _HEAD_H


//普通操作头文件 
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <time.h>
#include <errno.h>

typedef struct node
{
	int data;
	struct node * prev;
	struct node * next;
}NODE, *PNODE;

//创建一个链表
PNODE init_list(void);
//遍历输出
void show(PNODE mylist);
//判断链表是否为空
bool is_empty(PNODE mylist);
//头部插入节点
void insert_prev(PNODE new, PNODE anchor);
//尾部插入节点
void insert_next(PNODE new, PNODE anchor);
//插入节点调用
void inti_prnx(PNODE mylist);
//查找结点
void fine_node(int data, PNODE mylist);














#endif