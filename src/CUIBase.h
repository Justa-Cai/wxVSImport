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
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/hyperlink.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/stattext.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/sizer.h>
#include <wx/grid.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/menu.h>
#include <wx/frame.h>
#include <wx/treectrl.h>
#include <wx/dialog.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class CMainFrameBase
///////////////////////////////////////////////////////////////////////////////
class CMainFrameBase : public wxFrame 
{
	private:
	
	protected:
		wxHyperlinkCtrl* m_hyperlink1;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrlVSPrjPath;
		wxButton* m_btnVSPrj;
		wxButton* m_btnImport;
		wxTextCtrl* m_textCtrlInfo;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu3;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnbtnVSPrjClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnImportClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnGridEditorShown( wxGridEvent& event ) { event.Skip(); }
		virtual void OnMenuProjectEditorSelection( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxGrid* m_grid_dir;
		
		CMainFrameBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("wxVSImport"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 819,710 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~CMainFrameBase();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CMainFrameBase_BACK
///////////////////////////////////////////////////////////////////////////////
class CMainFrameBase_BACK : public wxFrame 
{
	private:
	
	protected:
		wxHyperlinkCtrl* m_hyperlink1;
		wxStaticText* m_staticText1;
		wxTextCtrl* m_textCtrlVSPrjPath;
		wxButton* m_btnVSPrj;
		wxStaticText* m_staticText11;
		wxTextCtrl* m_textCtrlSrcPath;
		wxButton* m_btnSrcPath;
		wxGrid* m_grid11;
		wxButton* m_btnImport;
		wxTextCtrl* m_textCtrlInfo;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnbtnVSPrjClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnBtnSrcPathClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnbtnImportClick( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CMainFrameBase_BACK( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("wxVSImport"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 935,759 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );
		
		~CMainFrameBase_BACK();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class CDialogTreeTestBase
///////////////////////////////////////////////////////////////////////////////
class CDialogTreeTestBase : public wxDialog 
{
	private:
	
	protected:
		wxTreeCtrl* m_treeCtrl1;
		wxTextCtrl* m_textCtrlLoadPorject;
		wxButton* m_buttonLoad;
		wxTextCtrl* m_textCtrlSaveFile;
		wxButton* m_buttonSaveToFileBrowser;
		wxButton* m_buttonSaveToFile1;
		wxMenu* m_menu;
		
		// Virtual event handlers, overide them in your derived class
		virtual void OnInitDialog( wxInitDialogEvent& event ) { event.Skip(); }
		virtual void OnRightDown( wxMouseEvent& event ) { event.Skip(); }
		virtual void OnButtonLoadClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSaveBrowserClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnButtonSaveClick( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuItemDel( wxCommandEvent& event ) { event.Skip(); }
		virtual void OnMenuItemInster( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		CDialogTreeTestBase( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("VCProject Edit & Source Import"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 800,600 ), long style = wxDEFAULT_DIALOG_STYLE|wxMAXIMIZE_BOX|wxMINIMIZE_BOX ); 
		~CDialogTreeTestBase();
		
		void CDialogTreeTestBaseOnContextMenu( wxMouseEvent &event )
		{
			this->PopupMenu( m_menu, event.GetPosition() );
		}
	
};

#endif //__CUIBASE_H__
