
// Ex1View.h : interface of the CEx1View class
//

#pragma once


class CEx1View : public CView
{
protected: // create from serialization only
	CEx1View();
	DECLARE_DYNCREATE(CEx1View)

// Attributes
public:
	CEx1Doc* GetDocument() const;

// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	BOOL SetWindowPixelFormat(HDC dDC);
	BOOL CEx1View::CreateViewGLContext(HDC hDC);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CEx1View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:
	int m_GLPixelIndex;
	HGLRC m_hGLContext;
	CPoint m_RightDownPos;
	CPoint m_LeftDownPos;
	BOOL m_RightButtonDown;
	BOOL m_LEFTButtonDown;
// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnDestroy();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // debug version in Ex1View.cpp
inline CEx1Doc* CEx1View::GetDocument() const
   { return reinterpret_cast<CEx1Doc*>(m_pDocument); }
#endif

