#include"SList.h"

int main()
{
	menu();
	
	//头节点不存放有效数据
	SLTNode* phead = BuyListNode(0);

	int input;

	do {
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			printf("请输入要插入的数据\n");
			SLTDateType x;
			scanf("%d", &x);
			SLTPushBack(&phead, x);//尾插
			SLTPrint(phead);
			break;
		case 2:
			printf("请输入要插入的数据\n");
			SLTDateType x1;
			scanf("%d", &x1);
			SLTPushFront(&phead, x1);//头插
			SLTPrint(phead);
			break;
		case 3:
			SLTPopBack(&phead);
			SLTPrint(phead);
			break;
		case 4:
			SLTPopFront(&phead);
			break;
		case 5:
			SLTPrint(phead);
			break;
		case 0:
			SListDestory(phead);
			break;
		default:
			printf("输入非法,请重新输入\n");
		}
	} while (input != 0);



	system("pause");


	return 0;
}