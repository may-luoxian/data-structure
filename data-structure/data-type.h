#pragma once
#define MAX_SIZE 10 // 静态分配最大长度
#define INIT_SIZE 10 // 动态分配初始长度
// 顺序表结构—静态分配
typedef struct {
	int data[MAX_SIZE]; // 顺序表数据
	int length; // 顺序表长度
} StaticSeqList;

/*
	通过mallic和free函数动态申请和释放空间
*/
// 顺序表结构—动态分配
typedef struct {
	int* data; // 动态分配数组指针
	int MaxSize; // 顺序表最大容量
	int length; // 顺序表长度
} DynamicSeqList;

