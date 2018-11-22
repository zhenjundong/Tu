#include "pch.h"
#include "Edge.h"


Edge::Edge(int IndexA, int IndexB,int value)
{
	m_iEdgeIndexA = IndexA;
	m_iEdgeIndexB = IndexB;
	m_iEdgeValue = value;
	m_bIsSelected = false;
}


Edge::~Edge()
{
}
