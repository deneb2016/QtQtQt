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
	
	static double calcDistance(CPoint p1, CPoint p2); // �� �� ������ �Ÿ�
};

class CCircle : public CShape {
private:
	int m_a; //x����� ������
	int m_b; //y����� ������
	int m_c; //�߽����κ��� �� ���������� �Ÿ�
	bool m_dir; //Ÿ���� ����, true:x������� �� �� Ÿ�� false: y������� �� �� Ÿ��
	CPoint m_center; //Ÿ���� �߽�
	CPoint m_c1, m_c2; //�� ����
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