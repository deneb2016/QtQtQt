#pragma once

class CShape {
private:
	CPoint m_leftup, m_rightdown; 
	COLORREF m_brushColor, m_penColor; // �׵θ� ��, ���� ��, ����

public:
	CShape(CPoint lu, CPoint rd, COLORREF bc, COLORREF pc);
	virtual bool select(CPoint position) ; // ��ǥ�� ���� �ȿ� ������ true, �ƴϸ� false
	virtual void move(CPoint vec) ; // vec��ŭ - �̵�
	void setLeftUp(CPoint pos) ; // m_leftup ������ �ٲٴµ�, m_rightdown���� �������̰ų� ������ �˻�
	void setRightDown(CPoint pos) ; // m_rightdown ������ �ٲٴµ�, m_leftup���� �����̰ų� ������ �˻�
	void setBrushColor(COLORREF color) ; // ���λ� �ٲٱ�
	void setPenColor(COLORREF color) ; // �׵θ��� �ٲٱ�
	virtual void redraw(CClientDC & dc, bool selected) ; // �ڱ��ڽ� �׸���, selected�̸� ����
	bool edgeCheck(CPoint pos) ; // �����ڸ� �αٿ� �ִ��� üũ
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