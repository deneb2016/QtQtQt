#pragma once

class CShape {
private:
	CPoint m_leftup, m_rightdown; 
	COLORREF m_brushColor, m_penColor; // 테두리 색, 내부 색, 투명도

public:
	CShape(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc);
	virtual bool select(CPoint position) ; // 좌표가 도형 안에 있으면 true, 아니면 false
	virtual void move(CPoint vec) ; // vec만큼 - 이동
	void setLeftUp(CPoint pos) ; // m_leftup 변수를 바꾸는데, m_rightdown보다 오른쪽이거나 밑인지 검사
	void setRightDown(CPoint pos) ; // m_rightdown 변수를 바꾸는데, m_leftup보다 왼쪽이거나 위인지 검사
	void setBrushColor(COLORREF color) ; // 내부색 바꾸기
	void setPenColor(COLORREF color) ; // 테두리색 바꾸기
	virtual void redraw(CClientDC & dc, bool selected) ; // 자기자신 그리기, selected이면 강조
	bool edgeCheck(CPoint pos) ; // 가장자리 부근에 있는지 체크
};

class CCircle : public CShape {
private:
public:
	CCircle(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc);
};

class CRectangle : public CShape {
private:
public:
	CRectangle(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc);
};

class CTriangle : public CShape {
private:
public:
	CTriangle(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc);
};