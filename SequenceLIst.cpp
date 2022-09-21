#include<stdio.h>
#include<stdlib.h>
#define MaxSize 10
#define InitSize 5


//˳���

//˳���ľ�̬����
typedef struct {
	int data[MaxSize];//��̬������������Ԫ��
	int length;//˳���ǰ����
}SqList;
//˳���Ķ�̬���䡣ע�⶯̬�������ͷ��ڴ�ռ�
typedef struct {
	int *data;//��̬������������Ԫ��
	int max;
	int length;//˳���ǰ����
}SeqList;


void InitList(SqList& L);


void InitList(SqList& L) {
	//��ΪĬ��ֵ�����Դ���������
	for (int i = 0; i < MaxSize; i++) L.data[i] = 0;
	L.length = 0;
}
void InitList(SeqList& L) {
	L.data = (int*)malloc(InitSize * sizeof(int));
	L.length = 0;
	L.max = InitSize;
}

//���Ӷ�̬���鳤��
void IncreaseSize(SeqList& L, int len) {
	//Ҳ��ʹ��realloc�����ǲ�̫�˽⻹����malloc�ɣ�����
	int* p = L.data;

	L.data = (int*)malloc((L.max + len) * sizeof(int));
	for (int i = 0; i < L.length; i++) L.data[i] = p[i];
	
	L.max += len;
	
	free(p);
}


//��̬�������
bool ListInsert(SqList& L, int i, int e) {
	if (i<1 || i>L.length + 1)//����ķ�Χ�Ƿ�Ϸ���1����С2������
		return false;
	if (L.length >= MaxSize)
		return false;

	//�˴���ѭ������ʾ��λ�õ��±�
	//length��λ�򣬶������±꣬lengthλ���Ӧ���±���length-1
	//j�ǿճ�������λ�ã��ӱ�β����i��Ԫ�����������ơ�
	for (int j = L.length; j >= i; j--)//����i��Ԫ�ؼ�֮���Ԫ�غ���
		L.data[j] = L.data[j - 1];//�ӱ�β�����ƶ�
	L.data[i - 1] = e;

	L.length++;
	return true;
}

//��̬����ɾ��
bool ListDelelte(SqList& L, int i, int& e) {
	if (i<1 || i>L.length)//�ж�i�ķ�Χ�Ƿ���Ч��i��λ��
		return false;

	e = L.data[i - 1];

	//�˴���ѭ������ʾ�ƶ���Ԫ�ص��±�
	//i-1�Ǳ�ɾ��Ԫ�ص��±꣬�Դ���Ϊ��λ�ã���Ԫ��ǰ�ƣ�ֱ���ִ��β
	for (int j = i; j < L.length; j++)//����i��λ�ú��Ԫ��ǰ��
		L.data[j - 1] = L.data[j];

	L.length--;
	return true;

}

//��̬���鰴λ����
int GetElem(SqList L, int i) {
	return L.data[i - 1];
}
//��̬���鰴ֵ����
int LocateElem(SqList L, int e) {
	int i = 0;
	for (i = 0; i < L.length; i++)
		if (L.data[i] == e)//�ṹ���е���������һ�����ˣ�����ֻ�С�C���Գ�����ơ��������ϸ�ڣ����
			return i + 1;
	return 0;
}

int main() {
	//˳���
	SqList L;//����˳�������������˳���L�Ŀռ�
	InitList(L);//��ʼ��˳���

	return 0;
}