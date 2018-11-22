#include "pch.h"
#include "MyTu.h"
#include "Node.h"
#include<vector>
#include <iostream>
#include "Edge.h"
using namespace std;

MyTu::MyTu(int capacity)
{
	m_iCapacity = capacity;
	m_iCount = 0;
	m_NodeArr = new Node[m_iCapacity];
	m_iMatrix = new int[m_iCapacity*m_iCapacity];
	for (int i = 0;i < m_iCapacity*m_iCapacity;i++)
	{
		m_iMatrix[i] = 0;
	}
	m_EdgeMinTree = new Edge[m_iCapacity - 1];
}


MyTu::~MyTu()
{
	delete[]m_NodeArr;
	delete[]m_iMatrix;
}

bool MyTu::addNode(Node *p)
{
	if (p == NULL)
	{
		return false;
	}
	m_NodeArr[m_iCount].m_iData = p->m_iData;
	m_iCount++;
	return true;
}

void MyTu::resetNode()
{
	for (int i = 0;i < m_iCount;i++)
	{
		m_NodeArr[i].bIsVisited = false;
	}
}

bool MyTu::setValueToDirectionMatrix(int col, int row, int val)
{
	if (col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	if (row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	m_iMatrix[col*m_iCapacity + row] = val;
	return true;
}
bool MyTu::setValueToUndirectionMatrix(int col, int row, int val)
{
	if (col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	if (row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	m_iMatrix[col*m_iCapacity + row] = val;
	m_iMatrix[row*m_iCapacity + col] = val;
	return true;
}


bool MyTu::getValue(int col, int row, int &val)
{
	if (col < 0 || col >= m_iCapacity)
	{
		return false;
	}
	if (row < 0 || row >= m_iCapacity)
	{
		return false;
	}
	val=m_iMatrix[col*m_iCapacity + row];
	return true;
}

void MyTu::MatrixTranverse()
{
	for (int i = 0;i < m_iCapacity;i++)
	{
		for (int k = 0;k < m_iCapacity;k++)
		{
			cout << m_iMatrix[i*m_iCapacity + k] << " ";
		}
		cout << endl;
	}
}

void MyTu::deapthFirstTranverse(int index)//������ȱ���
{
	cout << m_NodeArr[index].m_iData << " ";
	m_NodeArr[index].bIsVisited = true;
	int val = 0;
	for (int i = 0;i < m_iCapacity;i++)
	{
		getValue(index, i, val);
		if (val == 1)
		{
			if (m_NodeArr[i].bIsVisited)
			{
				continue;
			}
			else
			{
				deapthFirstTranverse(i);
			}
		}
		else
		{
			continue;
		}
	}
}
void MyTu::breathFirstTranverse(int index)//������ȱ���,����Ҫһ������
{
	cout << m_NodeArr[index].m_iData << " ";
	m_NodeArr[index].bIsVisited = true;
	vector<int> vec;
	vec.push_back(index);
	arrayBreathFirst(vec);
}

void MyTu::arrayBreathFirst(vector<int> preArray)
{
	vector<int> vec;
	int val = 0;
	for (int i = 0;i < m_iCapacity;i++)
	{
		for (int j = 0;j < (int)preArray.size();j++)
		{
			getValue(preArray[j], i, val);
			if (val == 1)
			{
				if (m_NodeArr[i].bIsVisited)
				{
					continue;
				}
				else
				{
					cout << m_NodeArr[i].m_iData << " ";
					m_NodeArr[i].bIsVisited = true;
					vec.push_back(i);
				}
			}
			else
			{
				continue;
			}
		}
	}
	if (vec.size() == 0)
	{
		return;
	}
	else
	{
		arrayBreathFirst(vec);
	}
}

void MyTu::PrimeAlgorithm(int index)//Prime�㷨
{
	cout << m_NodeArr[index].m_iData << "---";
	m_NodeArr[index].bIsVisited = true;
	vector<int> NodeArr;//�㼯��
	vector<Edge> EdgeArr;//��ѡ�߼���
	NodeArr.push_back(index);
	int temp = 0;
	int count = 0;
	int val = 0;
	int edgeIndex = 0;
	while (count<m_iCapacity-1)//��С�������ı�==�ܵ���-1
	{
		temp = NodeArr.back();//�ص��㼯�ϵ����һ����
		for (int i = 0;i < m_iCapacity;i++)//��ѡ�߼���
		{
			getValue(temp, i, val);
			if (val != 0)
			{
				//�жϵ�i�Ƿ��ù�
				if (m_NodeArr[i].bIsVisited)
				{
					continue;
				}
				else
				{
					Edge edge(temp, i, val);
					EdgeArr.push_back(edge);
				}
			}
		}
		edgeIndex=getMinEdge(EdgeArr);//�ҵ���С�ߵĵ�
		if (edgeIndex != -1)
		{
			EdgeArr[edgeIndex].m_bIsSelected = true;
			m_EdgeMinTree[count] = EdgeArr[edgeIndex];
			count++;
			int nextNodeIndex = EdgeArr[edgeIndex].m_iEdgeIndexB;//�߿����ҵ�
			NodeArr.push_back(nextNodeIndex);
			cout << m_NodeArr[nextNodeIndex].m_iData << "---";
			m_NodeArr[nextNodeIndex].bIsVisited = true;
		}
	}
}

int MyTu::getMinEdge(vector<Edge> EdgeArr)
{
	int Index = -1;
	int NextNodeIndex = 0;

	for (int i = 0;i < EdgeArr.size();i++)
	{
		if (EdgeArr[i].m_bIsSelected == true)
		{
			continue;
		}
		else
		{
			NextNodeIndex = EdgeArr[i].m_iEdgeIndexB;
			Index = i;
			break;
		}
	}
	if (Index == -1)//����������߶���ѡ����
	{
		return -1;
	}
	for (int i = 0;i < EdgeArr.size();i++)
	{
		if (EdgeArr[Index].m_iEdgeValue > EdgeArr[i].m_iEdgeValue)
		{
			if (EdgeArr[i].m_bIsSelected)
			{
				continue;
			}
			else
			{
				NextNodeIndex = EdgeArr[i].m_iEdgeIndexB;
				Index = i;
			}
		}
	}
	return Index;
}