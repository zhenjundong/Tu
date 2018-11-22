#pragma once
class Edge
{
public:
	Edge(int IndexA=0,int IndexB=0,int value=0);
	~Edge();
	int m_iEdgeIndexA;
	int m_iEdgeIndexB;
	int m_iEdgeValue;
	bool m_bIsSelected;
};

