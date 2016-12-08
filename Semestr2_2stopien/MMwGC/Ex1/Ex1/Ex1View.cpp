
// Ex1View.cpp : implementation of the CEx1View class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Ex1.h"
#endif

#include "Ex1Doc.h"
#include "Ex1View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CEx1View

IMPLEMENT_DYNCREATE(CEx1View, CView)

BEGIN_MESSAGE_MAP(CEx1View, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_CREATE()
	ON_WM_DESTROY()
	ON_WM_SIZE()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// CEx1View construction/destruction

CEx1View::CEx1View()
{
	// TODO: add construction code here
	m_hGLContext = NULL;
	m_GLPixelIndex = 0;

}

CEx1View::~CEx1View()
{
}

BOOL CEx1View::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.style |= (WS_CLIPCHILDREN | WS_CLIPSIBLINGS);
	return CView::PreCreateWindow(cs);
}

// CEx1View drawing

void CEx1View::OnDraw(CDC* /*pDC*/)
{
	CEx1Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: add draw code for native data here
}


// CEx1View printing

BOOL CEx1View::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CEx1View::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CEx1View::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}


// CEx1View diagnostics

#ifdef _DEBUG
void CEx1View::AssertValid() const
{
	CView::AssertValid();
}

void CEx1View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CEx1Doc* CEx1View::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CEx1Doc)));
	return (CEx1Doc*)m_pDocument;
}
#endif //_DEBUG


// CEx1View message handlers
BOOL CEx1View::SetWindowPixelFormat(HDC hDC) {
	PIXELFORMATDESCRIPTOR pixelDesc;

	pixelDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelDesc.nVersion = 1;
	pixelDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_STEREO_DONTCARE;
	pixelDesc.iPixelType = PFD_TYPE_RGBA;
	pixelDesc.cColorBits = 32;
	pixelDesc.cRedBits = 8; pixelDesc.cRedShift = 16;
	pixelDesc.cGreenBits = 8; pixelDesc.cGreenShift = 8;
	pixelDesc.cBlueBits = 8; pixelDesc.cBlueShift = 0;
	pixelDesc.cAlphaBits = 0; pixelDesc.cAlphaShift = 0;
	pixelDesc.cAccumBits = 64;
	pixelDesc.cAccumRedBits = 16;
	pixelDesc.cAccumGreenBits = 16;
	pixelDesc.cAccumBlueBits = 16;
	pixelDesc.cAccumAlphaBits = 0;
	pixelDesc.cDepthBits = 32;
	pixelDesc.cStencilBits = 8;
	pixelDesc.cAuxBuffers = 0;
	pixelDesc.iLayerType = PFD_MAIN_PLANE;
	pixelDesc.bReserved = 0; pixelDesc.dwLayerMask = 0;
	pixelDesc.dwVisibleMask = 0; pixelDesc.dwDamageMask = 0;
	m_GLPixelIndex = ChoosePixelFormat(hDC, &pixelDesc);
	if (m_GLPixelIndex == 0) {
		m_GLPixelIndex = 1;
		if (DescribePixelFormat(hDC, m_GLPixelIndex, sizeof(PIXELFORMATDESCRIPTOR), &pixelDesc) == 0)
			return FALSE;
	}
	if (SetPixelFormat(hDC, m_GLPixelIndex, &pixelDesc) == FALSE)
		return FALSE;
	return TRUE;
}






int CEx1View::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	HWND hWnd = GetSafeHwnd();
	HDC hDC = ::GetDC(hWnd);

	if (SetWindowPixelFormat(hDC) == FALSE)
		return 0;
	if (CreateViewGLContext(hDC) == FALSE)
		return 0;
	return 0;
}

BOOL CEx1View::CreateViewGLContext(HDC hDC)
{
	m_hGLContext = wglCreateContext(hDC);
	if (m_hGLContext == NULL)
		return FALSE;
	if (wglMakeCurrent(hDC, m_hGLContext) == FALSE)
		return FALSE;
	return TRUE;
}




void CEx1View::OnDestroy()
{
	if (wglGetCurrentContext() != NULL)
		wglMakeCurrent(NULL, NULL);
	if (m_hGLContext != NULL)
	{
		wglDeleteContext(m_hGLContext);
		m_hGLContext = NULL;
	}
	CView::OnDestroy();
}


void CEx1View::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	GLsizei width, height;
	GLdouble aspect;

	width = cx;
	height = cy;
	if (cy == 0)
		aspect = (GLdouble)width;
	else
		aspect = (GLdouble)width / (GLdouble)height;
	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 500.0*aspect, 0.0, 500.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}


void CEx1View::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	
	CEx1Doc* pDoc = GetDocument();
	pDoc->RenderScene();
}