

#include "stdafx.h"
#include "CShape.h"
#include <math.h>
/*CShape*/

bool CShape::select(CPoint position)
{
	return false;
}

void CShape::move(CPoint vec)
{
}

void CShape::redraw(CClientDC & dc, bool selected)
{
}

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

int CShape::calcCrossProductZ(CPoint p1, CPoint p2) {
	return p1.x * p2.y - p1.y * p2.x;
}

double CShape::calcDistance(CPoint p1, CPoint p2) {
	double ret = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
	return ret;
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


CCircle::CCircle(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc){
	m_leftup = lu;
	m_rightdown = rd;
	m_brushColor = bc;
	m_penColor = pc;

	m_a = (m_rightdown.x- m_leftup.x) / 2; //x축방향 반지름
	m_b = (m_leftup.y - m_rightdown.y) / 2; //y축방향 반지름
	m_center = CPoint((m_leftup.x + m_rightdown.x) / 2, (m_leftup.y + m_rightdown.y) / 2); //중심으로부터 두 정점까지의 거리
	
	//c^2 = a^2 - b^2;
	m_c = (int)sqrt((m_leftup.y - m_rightdown.y) / 2) * ((m_leftup.y - m_rightdown.y) / 2) - ((m_rightdown.x - m_leftup.x) / 2) *((m_rightdown.x - m_leftup.x) / 2);
	m_dir = (m_a >= m_b) ? true : false; //타원의 방향, true:x축방향이 더 긴 타원 false: y축방향이 더 긴 타원
	
	if (m_dir == true) {//타원의 방향이 x축이 더 긴
		m_c1 = CPoint(m_center.x + m_c, m_center.y);
		m_c2 = CPoint(m_center.x - m_c, m_center.y);
	}
	else {//타원의 방향이 y축이 더 긴
		m_c1 = CPoint(m_center.x , m_center.y + m_c);
		m_c2 = CPoint(m_center.x , m_center.y - m_c);
	}
	return;
};
CRectangle::CRectangle(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc) {
	m_leftup = lu;
	m_rightdown = rd;
	m_brushColor = bc;
	m_penColor = pc;
};
CTriangle::CTriangle(CPoint p1, CPoint p2, CPoint p3, COLORREF bc, COLORREF pc){
	m_p1 = p1;
	m_p2 = p2;
	m_p3 = p3;
	m_brushColor = bc;
	m_penColor = pc;

	m_leftup.x = (p3.x < ((p1.x < p2.x) ? p1.x : p2.x)) ? p3.x : ((p1.x < p2.x) ? p1.x : p2.x); //제일 작은 x값
	m_rightdown.x = (p3.x > ((p1.x > p2.x) ? p1.x : p2.x)) ? p3.x : ((p1.x > p2.x) ? p1.x : p2.x); //제일 큰 x값
	m_rightdown.y = (p3.y < ((p1.y < p2.y) ? p1.y : p2.y)) ? p3.y : ((p1.y < p2.y) ? p1.y : p2.y); //제일 작은 y값
	m_leftup.y = (p3.y >((p1.y > p2.y) ? p1.y : p2.y)) ? p3.y : ((p1.y > p2.y) ? p1.y : p2.y); //제일 큰 y값
};

bool CCircle::select(CPoint pos) {

	double r2 = calcDistance(m_c1, pos) + calcDistance(m_c2, pos);
	if (m_dir == true) {
		return ((int)r2 <= m_a * 2);
	}
	else{
		return ((int)r2 <= m_b * 2);
	}
	
};
bool CRectangle::select(CPoint pos) {

	if (pos.x >= m_leftup.x && pos.x <= m_rightdown.x && pos.y >= m_rightdown.y && pos.y <= m_leftup.y)
		return 1;
	else return 0;
};
bool CTriangle::select(CPoint pos) {
	CPoint e1, e2, e3;
	e1 = m_p2 - m_p1;
	e2 = m_p3 - m_p2;
	e3 = m_p1 - m_p3;

	if (calcCrossProductZ(e1, pos) >= 0 && calcCrossProductZ(e2, pos) >= 0 && calcCrossProductZ(e3, pos) >= 0) {
		return 1;
	}
	else return 0;
}

void CCircle::move(CPoint vec) {
	m_leftup += vec;
	m_rightdown += vec;
	m_center += vec; //타원의 중심
	m_c1 += vec;
	m_c2 += vec; //두 정점
};
void CRectangle::move(CPoint vec) {
	m_leftup += vec;
	m_rightdown += vec;
};
void CTriangle::move(CPoint vec) {
	m_leftup += vec;
	m_rightdown += vec;
	m_p1 += vec;
	m_p2 += vec;
	m_p3 += vec;
};

void CCircle::redraw(CClientDC & dc, bool selected) {
	CPen MyPen(PS_SOLID, 0, m_penColor);
	CBrush MyBrush(m_brushColor);
	dc.SelectObject(&MyPen);
	dc.SelectObject(&MyBrush);

	dc.Ellipse(m_leftup.x, m_rightdown.y, m_rightdown.x, m_leftup.y);
};
void CRectangle::redraw(CClientDC & dc, bool selected) {
	CPen MyPen(PS_SOLID, 0, m_penColor);
	CBrush MyBrush(m_brushColor);
	dc.SelectObject(&MyPen);
	dc.SelectObject(&MyBrush);

	dc.Rectangle(m_leftup.x, m_rightdown.y, m_rightdown.x, m_leftup.y);
};

void CTriangle::redraw(CClientDC & dc, bool selected) {
	CPen MyPen(PS_SOLID, 0, m_penColor);
	CBrush MyBrush(m_brushColor);
	dc.SelectObject(&MyPen);
	dc.SelectObject(&MyBrush);

	CPoint pArr[3] = { m_p1, m_p2, m_p3 };
	dc.Polygon(pArr,3);
};