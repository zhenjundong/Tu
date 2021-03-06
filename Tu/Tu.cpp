// Tu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include "Node.h"
#include "MyTu.h"
using namespace std;

int main()
{
	int capacity = 6;
	MyTu *cMap = new MyTu(capacity);
	Node *nodeA = new Node('A');
	Node *nodeB = new Node('B');
	Node *nodeC = new Node('C');
	Node *nodeD = new Node('D');
	Node *nodeE = new Node('E');
	Node *nodeF = new Node('F');

	cMap->addNode(nodeA);
	cMap->addNode(nodeB);
	cMap->addNode(nodeC);
	cMap->addNode(nodeD);
	cMap->addNode(nodeE);
	cMap->addNode(nodeF);

	cMap->setValueToUndirectionMatrix(0,1,6);
	cMap->setValueToUndirectionMatrix(0, 4, 5);
	cMap->setValueToUndirectionMatrix(0, 5, 1);
	cMap->setValueToUndirectionMatrix(1, 2, 3);
	cMap->setValueToUndirectionMatrix(1, 5, 2);
	cMap->setValueToUndirectionMatrix(2, 5, 8);
	cMap->setValueToUndirectionMatrix(2, 3, 7);
	cMap->setValueToUndirectionMatrix(3, 5, 4);
	cMap->setValueToUndirectionMatrix(3, 4, 2);
	cMap->setValueToUndirectionMatrix(4, 5, 9);

	cMap->PrimeAlgorithm(0);
	system("pause");
	return 0;
}
