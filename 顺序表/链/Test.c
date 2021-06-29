#include "SeqList.h"

//≤‚ ‘Õ∑Œ≤≤Â»Î…æ≥˝
void TestSeqList1()
{
	SL s = { 0 };
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPushBack(&s, 7);
	SeqListPushBack(&s, 8);
	SeqListPushBack(&s, 9);
	SeqListPrint(&s);

	//SeqListPopBack(&s); 
	//SeqListPopBack(&s);
	//SeqListPrint(&s);

	//SeqListPushFront(&s, -1);
	//SeqListPushFront(&s, -2);
	//SeqListPushFront(&s, -3);
	//SeqListPrint(&s);

	//SeqListPopFront(&s);
	//SeqListPopFront(&s);
	//SeqListPrint(&s);

	SeqListPushInsert(&s, 3, 5);
	SeqListPrint(&s);

	SeqListErase(&s, 3);
	SeqListPrint(&s);

	int pos = SeqListFine(&s, 6);
	if (pos != -1)
	{
		SeqListErase(&s, pos);
	}

	SeqListDestroy(&s);
}

int main()
{
	TestSeqList1();
	return 0;
}