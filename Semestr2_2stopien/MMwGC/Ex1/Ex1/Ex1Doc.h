
// Ex1Doc.h : interface of the CEx1Doc class
//


#pragma once


class CEx1Doc : public CDocument
{
protected: // create from serialization only
	CEx1Doc();
	DECLARE_DYNCREATE(CEx1Doc)

// Attributes
public:
	enum GLDiscplayListNames {
		ArmPart=1
	};
	double m_transY;
	double m_transX;
	double m_angle2;
	double m_angle1;

// Operations
public:

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	void RenderScene(void);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CEx1Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
};
