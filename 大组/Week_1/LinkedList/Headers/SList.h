#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDateType;

typedef struct SListNode
{
	SLTDateType date;
	struct SListNode* next;
}SLTNode;

void menu();


SLTNode* BuyListNode(SLTDateType x);//�����½ڵ�

void SLTPushBack(SLTNode** pphead, SLTDateType x);//β��

void SLTPrint(SLTNode* phead);//��ӡ����

void SLTPopBack(SLTNode** pphead);//βɾ

void SLTPushFront(SLTNode** pphead, SLTDateType x);//ͷ��

void SLTPopFront(SLTNode** pphead);//ͷɾ
SLTNode* SLTFind(SLTNode* phead, SLTDateType x);//����


void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);//����ýڵ�֮ǰ

void SListInsertAfter(SLTNode* pos, SLTDateType x);//����ýڵ�֮��

void SListErase(SLTNode** pphead, SLTNode* pos);//ɾ���ýڵ�֮ǰ�Ľڵ�

void SListEraseAfter(SLTNode** pphead, SLTNode* pos);//ɾ���ýڵ�֮��Ľڵ�

void SListDestory(SLTNode** pphead);//��������


SLTNode* SListni(SLTNode* phead);//��ʼ��



