#pragma once


class CShape {
protected:
	CPoint m_leftup, m_rightdown; 
	COLORREF m_brushColor, m_penColor; // 테두리 색, 내부 색, 투명도

public:
	virtual bool select(CPoint position); // 좌표가 도형 안에 있으면 true, 아니면 false
	virtual void move(CPoint vec); // vec만큼 - 이동
	virtual void redraw(CClientDC & dc, bool selected); // 자기자신 그리기, selected이면 강조
	void setLeftUp(CPoint pos) ; // m_leftup 변수를 바꾸는데, m_rightdown보다 오른쪽이거나 밑인지 검사
	void setRightDown(CPoint pos) ; // m_rightdown 변수를 바꾸는데, m_leftup보다 왼쪽이거나 위인지 검사
	void setBrushColor(COLORREF color) ; // 내부색 바꾸기
	void setPenColor(COLORREF color) ; // 테두리색 바꾸기
	bool edgeCheck(CPoint pos) ; // 가장자리 부근에 있는지 체크
	
	static double calcDistance(CPoint p1, CPoint p2); // 두 점 사이의 거리
};

class CCircle : public CShape {
private:
	int m_a; //x축방향 반지름
	int m_b; //y축방향 반지름
	int m_c; //중심으로부터 두 정점까지의 거리
	bool m_dir; //타원의 방향, true:x축방향이 더 긴 타원 false: y축방향이 더 긴 타원
	CPoint m_center; //타원의 중심
	CPoint m_c1, m_c2; //두 정점
public:
	CCircle(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc);
	bool select(CPoint pos);
	void move(CPoint vec);
	void redraw(CClientDC & dc, bool selected);
};

class CRectangle : public CShape {
private:
public:
	CRectangle(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc);
	bool select(CPoint pos);
	void move(CPoint vec);
	void redraw(CClientDC & dc, bool selected);
};

class CTriangle : public CShape {
private:
	CPoint m_p1, m_p2, m_p3;
	CPoint m_center;
public:
	CTriangle(CPoint p1, CPoint p2, CPoint p3, COLORREF bc, COLORREF pc);
	bool select(CPoint pos);
	void move(CPoint vec);
	void redraw(CClientDC & dc, bool selected);
};