#include "head.h"

PNODE init_list(void)
{
	
	int i, j, val;
	PNODE mylist = (PNODE)malloc(sizeof(NODE));//创建头节点
	if(NULL != mylist)
	{
		mylist->prev = mylist->next = mylist;
	}
	PNODE ptiao = mylist;
	//ptiao->next = mylist;

	printf("请输入要生成的链表节点个数\n");
	scanf("%d",&i);
	while(getchar() != '\n');
	
	for(j=0; j<i; ++j)
	{
		PNODE new = (PNODE)malloc(sizeof(NODE));//生成新节点
		if(NULL == new)
		{
			printf("Memory allocation failed\n");
			exit(-1);
		}
		printf("请输入第%d个节点的值\n",j+1);
		scanf("%d",&val);
		while(getchar() != '\n');
		new->data = val;
		ptiao->next = new;
		new->prev = ptiao;
		new->next = mylist;
		ptiao = new;
		mylist->prev = new;
	}

	
	return mylist;
}

void show(PNODE mylist)
{
	PNODE tmp = mylist->next;
	int flag = 0;
	//tmp->next = mylist;
	//正序遍历
	while(mylist != tmp)
	{
		printf("%s",flag==0 ? "" : "-->");
		printf("%d",tmp->data);
		tmp = tmp->next;
		flag = 1;
	}
	printf("\n");
	tmp = mylist->prev;
	
	flag = 0;
	//逆序遍历
	while(mylist != tmp)
	{
		printf("%s",flag==0 ? "" : "-->");
		printf("%d",tmp->data);
		tmp = tmp->prev;
		flag = 1;
	}
	printf("\n");
}

//判断链表是否为空
bool is_empty(PNODE mylist)
{
	return mylist->next == mylist->prev;
}

//头部插入节点
void insert_prev(PNODE new, PNODE anchor)
{
	if(new == NULL || anchor == NULL)
	{
		return;
	}
	
	new->prev = anchor;
	new->next = anchor->next;
	
	anchor->next = new;
	new->next->prev = new;
}

//尾部插入节点
void insert_next(PNODE new, PNODE anchor)
{
	if(new == NULL || anchor == NULL)
	{
		return;
	}
	
	new->prev = anchor->prev;
	new->next = anchor;
	
	anchor->prev = new;
	new->prev->next = new;
}

//插入节点调用
void inti_prnx(PNODE mylist)
{
	int i, j, r, val;
	printf("1为头差法，2为尾插法：");
	scanf("%d",&r);
	while(getchar() != '\n');
	switch(r)
	{
		case 1:
			printf("请输入插入节点数\n");
			scanf("%d",&i);
			while(getchar() != '\n');
			
			for(j=0; j<i; ++j)
			{
				PNODE new = (PNODE)malloc(sizeof(NODE));//创建新节点
				if(NULL != new)
				{
					new->prev = new->next = NULL;
				}
				printf("输入新节点的值\n");
				scanf("%d",&val);
				while(getchar() != '\n');
				new->data = val;
				insert_prev(new, mylist);
			}
			break;
			
		case 2:
			printf("请输入插入节点数\n");
			scanf("%d",&i);
			while(getchar() != '\n');
			
			for(j=0; j<i; ++j)
			{
				PNODE new = (PNODE)malloc(sizeof(NODE));//创建新节点
				if(NULL != new)
				{
					new->prev = new->next = NULL;
				}
				printf("输入新节点的值\n");
				scanf("%d",&val);
				while(getchar() != '\n');
				new->data = val;
				insert_next(new, mylist);
			}
			break;
		default:
			return;
		
		
	}
}


//查找节点
void fine_node(int data, PNODE mylist)
{
	int i = 1;
	PNODE tmp = mylist->next;
	while(tmp != mylist && data != tmp->data)
	{
		tmp = tmp->next;
		++i;
	}
	if(data == tmp->data)
	{
		printf("该节点为第%d个节点\n",i);
		return;
	}
	if(data != tmp->data && tmp == mylist)
	{
		printf("链表没有该节点\n");
		return;
	}
}

































