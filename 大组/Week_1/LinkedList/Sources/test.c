#include"SList.h"

int main()
{
	menu();
	
	//ͷ�ڵ㲻�����Ч����
	SLTNode* phead = BuyListNode(0);

	int input;

	do {
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			printf("������Ҫ���������\n");
			SLTDateType x;
			scanf("%d", &x);
			SLTPushBack(&phead, x);//β��
			SLTPrint(phead);
			break;
		case 2:
			printf("������Ҫ���������\n");
			SLTDateType x1;
			scanf("%d", &x1);
			SLTPushFront(&phead, x1);//ͷ��
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
			printf("����Ƿ�,����������\n");
		}
	} while (input != 0);



	system("pause");


	return 0;
}