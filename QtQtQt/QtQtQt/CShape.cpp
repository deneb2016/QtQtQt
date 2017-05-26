#include "CShape.h"
#include <math.h>
/*CShape*/
CShape::CShape(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc) : m_leftup(lu), m_rightdown(rd), m_brushColor(bc), m_penColor(pc) {};

void CShape::setLeftUp(CPoint pos){ 
	if (pos.x >= m_rightdown.x || pos.y <= m_rightdown.y) return; //유효하지 않은 경우 그냥 리턴

	m_leftup = pos;
}

void CShape::setRightDown(CPoint pos) {
	if (pos.x <= m_leftup.x || pos.y >= m_leftup.y) return;//유효하지 않은 경우 그냥 리턴
	m_rightdown = pos;
}
void CShape::setBrushColor(COLORREF color) {
	m_brushColor = color;
}
void CShape::setPenColor(COLORREF color) {
	m_penColor = color;
}

bool CShape::edgeCheck(CPoint pos) {
	if ((pos.x >= m_leftup.x && pos.x <= m_rightdown.x) //x 영역 안
		&& (pos.y == m_leftup.y || pos.y == m_leftup.y)) //y좌표 위
		return 1;
	if ((pos.y <= m_leftup.y && pos.y >= m_rightdown.y) //y 영역 안
		&& (pos.x == m_leftup.x || pos.x == m_leftup.x)) //x좌표 위
		return 1;

	return 0;
}



CCircle::CCircle(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc) :CShape(lu, rd, bc, pc) {};
CRect::CRect(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc) :CShape(lu, rd, bc, pc) {};
CTriangle::CTriangle(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc) :CShape(lu, rd, bc, pc) {};

bool CCircle::select(CPoint pos) {
	//c^2 = a^2 - b^2;
	CPoint center((m_leftup.x + m_rightdown.x) / 2, (m_leftup.y + m_rightdown.y) / 2);
	int cSquare = ((m_leftup.y - m_rightdown.y) / 2) * ((m_leftup.y - m_rightdown.y) / 2) - ((m_rightdown.x - m_leftup.x) / 2) *((m_rightdown.x - m_leftup.x ) /2 );
	double c = sqrt(cSquare);
		

	
};
bool CRect::select(CPoint pos) {
	if (pos.x >= m_leftup.x && pos.x <= m_rightdown.x && pos.y >= m_rightdown.y && pos.y <= m_leftup.y)
		return 1;
	else return 0;
};