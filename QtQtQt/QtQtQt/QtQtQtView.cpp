
// QtQtQtView.cpp : CQtQtQtView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
#ifndef SHARED_HANDLERS
#include "QtQtQt.h"
#endif

#include "QtQtQtDoc.h"
#include "QtQtQtView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CQtQtQtView

IMPLEMENT_DYNCREATE(CQtQtQtView, CView)

BEGIN_MESSAGE_MAP(CQtQtQtView, CView)
	// ǥ�� �μ� ����Դϴ�.
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// CQtQtQtView ����/�Ҹ�

CQtQtQtView::CQtQtQtView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CQtQtQtView::~CQtQtQtView()
{
}

BOOL CQtQtQtView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CQtQtQtView �׸���

void CQtQtQtView::OnDraw(CDC* pDC)
{
	CQtQtQtDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
	pDC->TextOutW(100, 200, _T("QtQt ZZange!"));
}


// CQtQtQtView �μ�

BOOL CQtQtQtView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// �⺻���� �غ�
	return DoPreparePrinting(pInfo);
}

void CQtQtQtView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ��ϱ� ���� �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
}

void CQtQtQtView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: �μ� �� ���� �۾��� �߰��մϴ�.
}


// CQtQtQtView ����

#ifdef _DEBUG
void CQtQtQtView::AssertValid() const
{
	CView::AssertValid();
}

void CQtQtQtView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CQtQtQtDoc* CQtQtQtView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CQtQtQtDoc)));
	return (CQtQtQtDoc*)m_pDocument;
}
#endif //_DEBUG


// CQtQtQtView �޽��� ó����
