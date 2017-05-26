
// QtQtQtView.h : CQtQtQtView Ŭ������ �������̽�
//

#pragma once
#include "atltypes.h"
#include "CEngine.h"


class CQtQtQtView : public CView
{
protected: // serialization������ ��������ϴ�.
	CQtQtQtView();
	DECLARE_DYNCREATE(CQtQtQtView)

// Ư���Դϴ�.
public:
	CQtQtQtDoc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// �����Դϴ�.
public:
	virtual ~CQtQtQtView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnDrawTri();
	int m_flag;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	CPoint m_sPt;
	CPoint m_ePt;
	afx_msg void OnDrawRect();
	afx_msg void OnDrawCircle();
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	CEngine* m_Engine;
	vector<CKey> selected_shape;
};

#ifndef _DEBUG  // QtQtQtView.cpp�� ����� ����
inline CQtQtQtDoc* CQtQtQtView::GetDocument() const
   { return reinterpret_cast<CQtQtQtDoc*>(m_pDocument); }
#endif

