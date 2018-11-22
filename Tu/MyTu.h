#pragma once
#include "Node.h"
#include<vector>
#include <iostream>
#include "Edge.h"
using namespace std;

class MyTu
{
public:
	MyTu(int capacity);
	~MyTu();
	bool addNode(Node *p);
	void resetNode();
	bool setValueToDirectionMatrix(int col, int row, int val);
	bool setValueToUndirectionMatrix(int col, int row, int val);
	bool getValue(int col, int row, int &val);
	void MatrixTranverse();
	void deapthFirstTranverse(int index);//深度优先遍历
	void breathFirstTranverse(int index);//广度优先遍历
	void arrayBreathFirst(vector<int> preArray);
	void PrimeAlgorithm(int index);//Prime算法
	int getMinEdge(vector<Edge> EdgeArr);
private:
	int m_iCapacity;
	int m_iCount;
	Node *m_NodeArr;
	int *m_iMatrix;
	Edge *m_EdgeMinTree;
};

