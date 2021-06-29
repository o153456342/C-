#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//˳�����Ч�����������б�������
//��̬˳�����ƣ��̶���С��
//��̬˳�����ƣ���С�ɱ䣩
typedef int SLDataTypt;
#define N 10

typedef struct SeqList
{
	SLDataTypt* a;//ָ��̬���ٵ�����
	int size;//��Ч���ݸ���
	int capacity;//����
} SL,SeqList;

//β��βɾ ͷ��ͷɾ
void SeqListPushBack(SL* ps, SLDataTypt x);
void SeqListPopBack( SL* ps);
void SeqListCheckCapacity(SL* ps);
void SeqListPushFront( SL* ps , SLDataTypt x);
void SeqListPopFront( SL* ps);
//����λ�õĲ���ɾ��
void SeqListPushInsert( SL* ps, int pos, SLDataTypt x);
void SeqListErase( SL* ps, int pos);
//����
int SeqListFine(SL* ps, SLDataTypt x);
// ����
void SeqListSort(SL* ps, SLDataTypt x);
//���ֲ���
void SeqListBinaryFind(SL* ps, SLDataTypt x);
//��ʼ��
void SeqListInit(SL* ps);
//���ٶ�̬���ٵĿռ�
void SeqListDestroy(SL* ps);

void SeqListPrint(SL* ps);