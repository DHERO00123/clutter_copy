#include "head.h"

int main(int argc, char const ** arrv)
{
	int i;
	PNODE mylist = init_list();//生成头节点
	show(mylist);		//遍历输出
	inti_prnx(mylist);// 插入新节点gai
	show(mylist);
	printf("请输入要查找结点的值:");
	scanf("%d",&i);
	while(getchar() != '\n');
	fine_node(i, mylist);
	
	return 0;
}