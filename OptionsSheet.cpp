// OptionsSheet.cpp : implementation file
//

#include "stdafx.h"
#include "CP_Main.h"
#include "OptionsSheet.h"
#include "OptionsKeyBoard.h"
#include "OptionsGeneral.h"
#include "OptionsQuickPaste.h"
#include "OptionsUtilities.h"
#include "OptionsStats.h"
#include "OptionsTypes.h"
#include "About.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define DELETE_PTR(ptr)	if(ptr) { delete ptr; ptr = NULL;	}

/////////////////////////////////////////////////////////////////////////////
// COptionsSheet

IMPLEMENT_DYNAMIC(COptionsSheet, CPropertySheet)

COptionsSheet::COptionsSheet(LPCTSTR pszCaption, CWnd* pParentWnd, UINT iSelectPage)
	:CPropertySheet(pszCaption, pParentWnd, iSelectPage)
{
	m_pKeyBoardOptions = NULL;
	m_pGeneralOptions = NULL;
	m_pQuickPasteOptions = NULL;
	m_pUtilites = NULL;
	m_pStats = NULL;
	m_pTypes = NULL;
	m_pAbout = NULL;
}

COptionsSheet::~COptionsSheet()
{
	DELETE_PTR(m_pKeyBoardOptions);
	DELETE_PTR(m_pGeneralOptions);
	DELETE_PTR(m_pQuickPasteOptions);
	DELETE_PTR(m_pUtilites);
	DELETE_PTR(m_pStats);
	DELETE_PTR(m_pTypes);
	DELETE_PTR(m_pAbout);
}

BEGIN_MESSAGE_MAP(COptionsSheet, CPropertySheet)
	//{{AFX_MSG_MAP(COptionsSheet)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// COptionsSheet message handlers

int COptionsSheet::DoModal() 
{
	EnableStackedTabs(TRUE);

	m_pGeneralOptions = new COptionsGeneral;
	m_pKeyBoardOptions = new COptionsKeyBoard;
	m_pQuickPasteOptions = new COptionsQuickPaste;
	m_pStats = new COptionsStats;
	m_pTypes = new COptionsTypes;
	m_pAbout = new CAbout;

	AddPage(m_pGeneralOptions);
	AddPage(m_pTypes);
	AddPage(m_pKeyBoardOptions);
	AddPage(m_pQuickPasteOptions);
	AddPage(m_pStats);
	AddPage(m_pAbout);
	
	return CPropertySheet::DoModal();
}

BOOL COptionsSheet::OnInitDialog() 
{
	BOOL bResult = CPropertySheet::OnInitDialog();
	
	SetWindowPos(&CWnd::wndTopMost, 0, 0, 0, 0, SWP_NOMOVE|SWP_NOSIZE);

	SetWindowText("Ditto");
	
	return bResult;
}