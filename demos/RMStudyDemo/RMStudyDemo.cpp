
// RMStudyDemo.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "RMStudyDemo.h"
#include "RMStudyDemoDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRMStudyDemoApp

BEGIN_MESSAGE_MAP(CRMStudyDemoApp, CWinAppEx)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CRMStudyDemoApp construction

CRMStudyDemoApp::CRMStudyDemoApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}


// The one and only CRMStudyDemoApp object

CRMStudyDemoApp theApp;


// CRMStudyDemoApp initialization

BOOL CRMStudyDemoApp::InitInstance()
{
	// InitCommonControlsEx() is required on Windows XP if an application
	// manifest specifies use of ComCtl32.dll version 6 or later to enable
	// visual styles.  Otherwise, any window creation will fail.
	INITCOMMONCONTROLSEX InitCtrls;
	InitCtrls.dwSize = sizeof(InitCtrls);
	// Set this to include all the common control classes you want to use
	// in your application.
	InitCtrls.dwICC = ICC_WIN95_CLASSES;
	InitCommonControlsEx(&InitCtrls);

	CWinAppEx::InitInstance();

	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	// of your final executable, you should remove from the following
	// the specific initialization routines you do not need
	// Change the registry key under which our settings are stored
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization
	SetRegistryKey(_T("Develop By RuralMouse"));

    CR_INSTALL_INFO info;
    memset(&info, 0, sizeof(CR_INSTALL_INFO));
    info.cb = sizeof(CR_INSTALL_INFO);  
    info.pszAppName = _T("RMStudyDemo"); // Define application name.
    info.pszAppVersion = _T("6.0.9"); // Define application version.
    // URL for sending error reports over HTTP.
    info.pszUrl = _T("http://someserver.com/crashrpt.php");
    // Install all available exception handlers.
    info.dwFlags |= CR_INST_ALL_POSSIBLE_HANDLERS; 
    // Provide privacy policy URL
    //info.pszPrivacyPolicyURL = _T("http://someserver.com/privacy.html");

    int nResult = crInstall(&info);
    if(nResult!=0)
    {
        TCHAR buff[256];
        crGetLastErrorMsg(buff, 256);
        MessageBox(NULL, buff, _T("crInstall error"), MB_OK);
        exit(0);
    }

    // Take screenshot of the app window at the moment of crash
    crAddScreenshot2(CR_AS_MAIN_WINDOW|CR_AS_USE_JPEG_FORMAT, 95);


	CRMStudyDemoDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CRMStudyDemoApp::ExitInstance()
{
    // Uninstall crash reporting
    crUninstall();

    return CWinAppEx::ExitInstance();
}
