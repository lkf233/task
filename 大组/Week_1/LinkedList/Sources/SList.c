#include"SList.h"

void menu()
{
	printf("1.β��  2.ͷ��  \n");
	printf("3.βɾ  4.ͷɾ  \n");
	printf("    5.��ӡ����  \n");
	printf("0.���������˳�����\n");

}


SLTNode* BuyListNode(SLTDateType x)//�����½ڵ�
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
	newnode->date = x;
	newnode->next = NULL;
	return newnode;
}







void SLTPushBack(SLTNode** pphead, SLTDateType x)//β��
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
	newnode->date = x;
	newnode->next = NULL;

	if (*pphead == NULL)
		*pphead = newnode;
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}


void SLTPrint(SLTNode* phead)
{
	SLTNode* tail = phead->next;
	while (tail!=NULL)
	{
		printf("%d->", tail -> date);
		tail = tail->next;
	}

	printf("NULL\n");
}

void SLTPopBack(SLTNode** pphead)
{
	assert(*pphead);
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLTNode* tail = *pphead;
		SLTNode* prve = NULL;
		while (tail->next)
		{
			prve = tail;
			tail = tail->next;
		}
		free(tail);
		prve->next = NULL;
		
	}
}

void SLTPushFront(SLTNode** pphead, SLTDateType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	assert(newnode);
	newnode->date = x;

	
	newnode->next = (*pphead)->next;
	(*pphead)->next = newnode;

}

void SLTPopFront(SLTNode** pphead )
{
	assert(*pphead);
	SLTNode* tail = *pphead;
	*pphead = (*pphead)->next;

	free(tail);
	tail = NULL;

}

SLTNode* SLTFind(SLTNode* phead, SLTDateType x)
{
	SLTNode* cur = phead;
	while (cur)
	{
		if (cur->date == x)
			return cur;
		else
			cur = cur->next;
	}

	return NULL;
}


//��posλ��֮ǰ����x
void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x)
{
	SLTNode* newnode = BuyListNode(x);
	if (pos == *pphead)
	{
		newnode->next = *pphead;
		*pphead = newnode;
	}
	else
	{
		SLTNode* posPrev = *pphead;
		while (posPrev->next != pos)
		{
			posPrev = posPrev->next;
		}
		posPrev->next = newnode;
		newnode->next = pos;

	}
}


void SListInsertAfter(SLTNode* pos, SLTDateType x)//��posλ��֮�����
{
	SLTNode* newnode = BuyListNode(x);

	newnode->next = pos->next;
	pos->next = newnode;
}


void SListErase(SLTNode** pphead, SLTNode* pos)//��pos�ڵ�ɾ��
{
	assert(pphead);//����ָ�벻Ϊ��

	assert(pos);
	if (*pphead == pos)
	{
		*pphead = pos->next;
		free(pos);
	}
	else
	{
		SLTNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);

	}


}



void SListEraseAfter(SLTNode** pphead, SLTNode* pos)
{
	assert(pos->next);

	SLTNode* next = pos->next;
	pos->next = next->next;
	free(next);

}

void SListDestory(SLTNode** pphead)
{
	assert(pphead);
	
	SLTNode* cur = *pphead;
	
	while (cur)
	{
		SLTNode* next = cur->next;
		free(cur);

		cur = next;

	}

	*pphead = NULL;





}


SLTNode* SListni(SLTNode*phead)
{
	if (phead == NULL)
		return NULL;


	SLTNode* n1, * n2, * n3;
	n1 = NULL;

	n2 = phead;
	n3 = phead->next;

	while (n2)
	{

		n2->next = n1;

		n1 = n2;
		n2 = n3;
		if (n3)
			n3 = n3->next;

	}


	return n1;
}

SLTNode* SListnizhi(SLTNode* phead)
{
	SLTNode* newhead = NULL;
	SLTNode* cur = phead;

	while (cur)
	{

		SLTNode* next = cur->next;

		cur->next = newhead;

		newhead = cur;

		cur = next;

	}


	return cur;
}






















