///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __CUIBASE_H__
#define __CUIBASE_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class CMainFrameBase
///////////////////////////////////////////////////////////////////////////////
class CMainFrameBase : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrlVSPrjPath;
		wxButton* m_btnVSPrj;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_textCtrlSrcPath;
		wxButton* m_btnSrcPath;
		wxButton* m_btnImport;
		wxTextCtrl* m_textCtrlInfo;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnbtnVSPrjClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnSrcPathClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnImportClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CMainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("wxVSImport"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 935,759 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~CMainFrameBase();
	
};

#endif //__CUIBASE_H__
