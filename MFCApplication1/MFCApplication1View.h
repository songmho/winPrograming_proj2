
// MFCApplication1View.h : CMFCApplication1View Ŭ������ �������̽�
//

#pragma once
#include "Point.h"
#include "Line.h"
#include "AEllipse.h"
#include "ARectangle.h"
#include "Text.h"

class CMFCApplication1View : public CView
{
protected: // serialization������ ��������ϴ�.
	CMFCApplication1View();
	DECLARE_DYNCREATE(CMFCApplication1View)

// Ư���Դϴ�.
public:
	CMFCApplication1Doc* GetDocument() const;
	BOOL bline_status = false;
	BOOL brect_status = false;
	BOOL bellipse_status = false;
	BOOL btext_status = false;
	BOOL bpoly_status = false;

	int current_l;		//Line ���� �迭��ȣ
	int current_r;		//Rect ���� �迭��ȣ
	int current_e;		//Ellipse ���� �迭��ȣ
	bool move;

	Line line;
	ARectangle rect;
	AEllipse ell;
	//APolyline poly;

	CArray<Line, Line&> figure;							//��� ��ü�� ������ �迭 
	CArray<Line, Line&> Line_array;						//Line ��ü�� �����ҹ迭
	CArray<ARectangle, ARectangle&> ARect_array;		//Rect ��ü�� �����ҹ迭
	CArray<AEllipse, AEllipse&> AEll_array;				//Ellipse ��ü�� �����ҹ迭
	//CArray<APolyline, APolyline&> APolyline_array;		//PolyLine ��ü�� �����ҹ迭

// �۾��Դϴ�.
public:
	int mode;
	CPoint m_ptPrev;

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
	virtual ~CMFCApplication1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnPaint();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // MFCApplication1View.cpp�� ����� ����
inline CMFCApplication1Doc* CMFCApplication1View::GetDocument() const
   { return reinterpret_cast<CMFCApplication1Doc*>(m_pDocument); }
#endif
