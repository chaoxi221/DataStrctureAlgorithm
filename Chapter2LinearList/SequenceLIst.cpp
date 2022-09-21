#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
#define InitSize 5


//顺序表

//顺序表的静态分配
typedef struct {
	int data[MaxSize];//静态的数组存放数据元素
	int length;//顺序表当前长度
}SqList;
//顺序表的动态分配。注意动态申请与释放内存空间
typedef struct {
	int *data;//静态的数组存放数据元素
	int max;
	int length;//顺序表当前长度
}SeqList;


void InitList(SqList& L);


void InitList(SqList& L) {
	//设为默认值：可以处理脏数据
	for (int i = 0; i < MaxSize; i++) L.data[i] = 0;
	L.length = 0;
}
void InitList(SeqList& L) {
	L.data = (int*)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.max = InitSize;
}

//增加动态数组长度
void IncreaseSize(SeqList& L, int len) {
	//也可使用realloc，但是不太了解还是用malloc吧，保险
	int* p = L.data;

	L.data = (int*)malloc((L.max + len) * sizeof(int));
	for (int i = 0; i < L.length; i++) L.data[i] = p[i];
	
	L.max += len;
	
	free(p);
}


//静态数组插入
bool ListInsert(SqList& L, int i, int e) {
	if (i<1 || i>L.length + 1)//插入的范围是否合法：1、过小2、过大
		return false;
	if (L.length >= MaxSize)
		return false;

	//此处的循环数表示新位置的下标
	//length是位序，而不是下标，length位序对应的下标是length-1
	//j是空出来的新位置，从表尾到第i个元素依次往后移。
	for (int j = L.length; j >= i; j--)//将第i个元素及之后的元素后移
		L.data[j] = L.data[j - 1];//从表尾往后移动
	L.data[i - 1] = e;

	L.length++;
	return true;
}

//静态数组删除
bool ListDelelte(SqList& L, int i, int& e) {
	if (i<1 || i>L.length)//判断i的范围是否有效，i是位序！
		return false;

	e = L.data[i - 1];

	//此处的循环数表示移动的元素的下标
	//i-1是被删除元素的下标，以此作为新位置，将元素前移，直到抵达表尾
	for (int j = i; j < L.length; j++)//将第i个位置后的元素前移
		L.data[j - 1] = L.data[j];

	L.length--;
	return true;

}

//静态数组按位查找
int GetElem(SqList L, int i) {
	return L.data[i - 1];
}
//静态数组按值查找
int LocateElem(SqList L, int e) {
	int i = 0;
	for (i = 0; i < L.length; i++)
		if (L.data[i] == e)//结构体判等又是另外一回事了，但是只有《C语言程序设计》在意这个细节，大概
			return i + 1;
	return 0;
}

int main() {
	//顺序表
	SqList L;//声明顺序表，于是声明了顺序表L的空间
	InitList(L);//初始化顺序表

	return 0;
}