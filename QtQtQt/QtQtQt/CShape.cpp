

#include "stdafx.h"
#include "CShape.h"
#include <math.h>
///*CShape*/
//CShape::CShape(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc) : m_leftup(lu), m_rightdown(rd), m_brushColor(bc), m_penColor(pc) {};
//
//void CShape::setLeftUp(CPoint pos){ 
//	if (pos.x >= m_rightdown.x || pos.y <= m_rightdown.y) return; //유효하지 않은 경우 그냥 리턴
//
//	m_leftup = pos;
//}
//
//void CShape::setRightDown(CPoint pos) {
//	if (pos.x <= m_leftup.x || pos.y >= m_leftup.y) return;//유효하지 않은 경우 그냥 리턴
//	m_rightdown = pos;
//}
//void CShape::setBrushColor(COLORREF color) {
//	m_brushColor = color;
//}
//void CShape::setPenColor(COLORREF color) {
//	m_penColor = color;
//}
//
//
//static double calcDistance(CPoint p1, CPoint p2) {
//	double ret = sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
//	return ret;
//}
//bool CShape::edgeCheck(CPoint pos) {
//	if ((pos.x >= m_leftup.x && pos.x <= m_rightdown.x) //x 영역 안
//		&& (pos.y == m_leftup.y || pos.y == m_leftup.y)) //y좌표 위
//		return 1;
//	if ((pos.y <= m_leftup.y && pos.y >= m_rightdown.y) //y 영역 안
//		&& (pos.x == m_leftup.x || pos.x == m_leftup.x)) //x좌표 위
//		return 1;
//
//	return 0;
//}
//
//
//
//CCircle::CCircle(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc) :CShape(lu, rd, bc, pc) {
//	m_a = (m_rightdown.x- m_leftup.x) / 2; //x축방향 반지름
//	m_b = (m_leftup.y - m_rightdown.y) / 2; //y축방향 반지름
//	m_center = CPoint((m_leftup.x + m_rightdown.x) / 2, (m_leftup.y + m_rightdown.y) / 2)); //중심으로부터 두 정점까지의 거리
//	
//	//c^2 = a^2 - b^2;
//	m_c = sqrt((m_leftup.y - m_rightdown.y) / 2) * ((m_leftup.y - m_rightdown.y) / 2) - ((m_rightdown.x - m_leftup.x) / 2) *((m_rightdown.x - m_leftup.x) / 2);
//	m_dir = (m_a >= m_b) ? true : false; //타원의 방향, true:x축방향이 더 긴 타원 false: y축방향이 더 긴 타원
//	
//	if (m_dir == true) {//타원의 방향이 x축이 더 긴
//		m_c1 = CPoint(m_center.x + m_c, m_center.y);
//		m_c2 = CPoint(m_center.x - m_c, m_center.y);
//	}
//	else {//타원의 방향이 y축이 더 긴
//		m_c1 = CPoint(m_center.x , m_center.y + m_c);
//		m_c2 = CPoint(m_center.x , m_center.y - m_c);
//	}
//	return;
//};
//CRectangle::CRectangle(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc) :CShape(lu, rd, bc, pc) {};
//CTriangle::CTriangle(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc) :CShape(lu, rd, bc, pc) {};
//
//bool CCircle::select(CPoint pos) {
//	int r2 = (m_c1, pos)
//
//	
//
//
//	
//};
//bool CRectangle::select(CPoint pos) {
//
//	if (pos.x >= m_leftup.x && pos.x <= m_rightdown.x && pos.y >= m_rightdown.y && pos.y <= m_leftup.y)
//		return 1;
//	else return 0;
//};