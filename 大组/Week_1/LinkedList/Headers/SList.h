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


SLTNode* BuyListNode(SLTDateType x);//开辟新节点

void SLTPushBack(SLTNode** pphead, SLTDateType x);//尾插

void SLTPrint(SLTNode* phead);//打印链表

void SLTPopBack(SLTNode** pphead);//尾删

void SLTPushFront(SLTNode** pphead, SLTDateType x);//头插

void SLTPopFront(SLTNode** pphead);//头删
SLTNode* SLTFind(SLTNode* phead, SLTDateType x);//查找


void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDateType x);//插入该节点之前

void SListInsertAfter(SLTNode* pos, SLTDateType x);//插入该节点之后

void SListErase(SLTNode** pphead, SLTNode* pos);//删除该节点之前的节点

void SListEraseAfter(SLTNode** pphead, SLTNode* pos);//删除该节点之后的节点

void SListDestory(SLTNode** pphead);//销毁链表


SLTNode* SListni(SLTNode* phead);//初始化



