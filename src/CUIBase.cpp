///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 30 2011)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "CUIBase.h"

///////////////////////////////////////////////////////////////////////////

CMainFrameBase::CMainFrameBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_hyperlink1 = new wxHyperlinkCtrl( this, wxID_ANY, wxT("Author: http://weibo.com/caicry"), wxT("http://weibo.com/caicry"), wxDefaultPosition, wxDefaultSize, wxHL_ALIGN_CENTRE|wxHL_DEFAULT_STYLE );
	m_hyperlink1->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer1->Add( m_hyperlink1, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("VS PROJECT"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALL, 5 );
	
	m_textCtrlVSPrjPath = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_textCtrlVSPrjPath, 1, wxALL, 5 );
	
	m_btnVSPrj = new wxButton( this, wxID_ANY, wxT("Open"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_btnVSPrj, 0, wxALL, 5 );
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer211;
	bSizer211 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnImport = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer211->Add( m_btnImport, 1, wxALL, 5 );
	
	bSizer1->Add( bSizer211, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2111;
	bSizer2111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_grid_dir = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_grid_dir->CreateGrid( 20, 2 );
	m_grid_dir->EnableEditing( true );
	m_grid_dir->EnableGridLines( true );
	m_grid_dir->EnableDragGridSize( false );
	m_grid_dir->SetMargins( 0, 0 );
	
	// Columns
	m_grid_dir->SetColSize( 0, 115 );
	m_grid_dir->SetColSize( 1, 604 );
	m_grid_dir->EnableDragColMove( false );
	m_grid_dir->EnableDragColSize( true );
	m_grid_dir->SetColLabelSize( 30 );
	m_grid_dir->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_grid_dir->SetRowSize( 0, 18 );
	m_grid_dir->SetRowSize( 1, 18 );
	m_grid_dir->SetRowSize( 2, 18 );
	m_grid_dir->SetRowSize( 3, 18 );
	m_grid_dir->SetRowSize( 4, 18 );
	m_grid_dir->EnableDragRowSize( true );
	m_grid_dir->SetRowLabelSize( 80 );
	m_grid_dir->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_grid_dir->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer2111->Add( m_grid_dir, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer2111, 0, wxEXPAND, 5 );
	
	m_textCtrlInfo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_RICH|wxTE_RICH2 );
	bSizer1->Add( m_textCtrlInfo, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	m_menu3 = new wxMenu();
	wxMenuItem* m_menuItem5;
	m_menuItem5 = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("VC Project Editor") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem5 );
	
	m_menubar1->Append( m_menu3, wxT("Tools") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_btnVSPrj->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase::OnbtnVSPrjClick ), NULL, this );
	m_btnImport->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase::OnbtnImportClick ), NULL, this );
	m_grid_dir->Connect( wxEVT_GRID_EDITOR_SHOWN, wxGridEventHandler( CMainFrameBase::OnGridEditorShown ), NULL, this );
	this->Connect( m_menuItem5->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( CMainFrameBase::OnMenuProjectEditorSelection ) );
}

CMainFrameBase::~CMainFrameBase()
{
	// Disconnect Events
	m_btnVSPrj->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase::OnbtnVSPrjClick ), NULL, this );
	m_btnImport->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase::OnbtnImportClick ), NULL, this );
	m_grid_dir->Disconnect( wxEVT_GRID_EDITOR_SHOWN, wxGridEventHandler( CMainFrameBase::OnGridEditorShown ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( CMainFrameBase::OnMenuProjectEditorSelection ) );
	
}

CMainFrameBase_BACK::CMainFrameBase_BACK( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxVERTICAL );
	
	m_hyperlink1 = new wxHyperlinkCtrl( this, wxID_ANY, wxT("Author: http://weibo.com/caicry"), wxT("http://weibo.com/caicry"), wxDefaultPosition, wxDefaultSize, wxHL_DEFAULT_STYLE );
	m_hyperlink1->SetFont( wxFont( 15, 70, 90, 90, false, wxEmptyString ) );
	
	bSizer1->Add( m_hyperlink1, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText1 = new wxStaticText( this, wxID_ANY, wxT("VS PROJECT"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText1->Wrap( -1 );
	bSizer2->Add( m_staticText1, 0, wxALL, 5 );
	
	m_textCtrlVSPrjPath = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_textCtrlVSPrjPath, 1, wxALL, 5 );
	
	m_btnVSPrj = new wxButton( this, wxID_ANY, wxT("Open"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer2->Add( m_btnVSPrj, 0, wxALL, 5 );
	
	bSizer1->Add( bSizer2, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Source Directory"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText11->Wrap( -1 );
	bSizer21->Add( m_staticText11, 0, wxALL, 5 );
	
	m_textCtrlSrcPath = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_textCtrlSrcPath, 1, wxALL, 5 );
	
	m_btnSrcPath = new wxButton( this, wxID_ANY, wxT("Open"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer21->Add( m_btnSrcPath, 0, wxALL, 5 );
	
	bSizer1->Add( bSizer21, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer2111;
	bSizer2111 = new wxBoxSizer( wxHORIZONTAL );
	
	m_grid11 = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	m_grid11->CreateGrid( 1, 2 );
	m_grid11->EnableEditing( true );
	m_grid11->EnableGridLines( true );
	m_grid11->EnableDragGridSize( false );
	m_grid11->SetMargins( 0, 0 );
	
	// Columns
	m_grid11->SetColSize( 0, 80 );
	m_grid11->SetColSize( 1, 80 );
	m_grid11->SetColSize( 2, 80 );
	m_grid11->SetColSize( 3, 80 );
	m_grid11->SetColSize( 4, 80 );
	m_grid11->EnableDragColMove( false );
	m_grid11->EnableDragColSize( true );
	m_grid11->SetColLabelSize( 30 );
	m_grid11->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	m_grid11->SetRowSize( 0, 18 );
	m_grid11->SetRowSize( 1, 18 );
	m_grid11->SetRowSize( 2, 18 );
	m_grid11->SetRowSize( 3, 18 );
	m_grid11->SetRowSize( 4, 18 );
	m_grid11->EnableDragRowSize( true );
	m_grid11->SetRowLabelSize( 80 );
	m_grid11->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	m_grid11->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer2111->Add( m_grid11, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	bSizer1->Add( bSizer2111, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer211;
	bSizer211 = new wxBoxSizer( wxHORIZONTAL );
	
	m_btnImport = new wxButton( this, wxID_ANY, wxT("Import"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer211->Add( m_btnImport, 1, wxALL, 5 );
	
	bSizer1->Add( bSizer211, 0, wxEXPAND, 5 );
	
	m_textCtrlInfo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_RICH|wxTE_RICH2 );
	bSizer1->Add( m_textCtrlInfo, 1, wxALL|wxEXPAND, 5 );
	
	this->SetSizer( bSizer1 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_btnVSPrj->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase_BACK::OnbtnVSPrjClick ), NULL, this );
	m_btnSrcPath->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase_BACK::OnBtnSrcPathClick ), NULL, this );
	m_btnImport->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase_BACK::OnbtnImportClick ), NULL, this );
}

CMainFrameBase_BACK::~CMainFrameBase_BACK()
{
	// Disconnect Events
	m_btnVSPrj->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase_BACK::OnbtnVSPrjClick ), NULL, this );
	m_btnSrcPath->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase_BACK::OnBtnSrcPathClick ), NULL, this );
	m_btnImport->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase_BACK::OnbtnImportClick ), NULL, this );
	
}

CDialogTreeTestBase::CDialogTreeTestBase( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer12;
	bSizer12 = new wxBoxSizer( wxVERTICAL );
	
	m_treeCtrl1 = new wxTreeCtrl( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxTR_DEFAULT_STYLE );
	bSizer12->Add( m_treeCtrl1, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer121;
	bSizer121 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrlLoadPorject = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer121->Add( m_textCtrlLoadPorject, 1, wxALL|wxEXPAND, 5 );
	
	m_buttonLoad = new wxButton( this, wxID_ANY, wxT("Load VC Poject"), wxDefaultPosition, wxSize( 140,-1 ), 0 );
	bSizer121->Add( m_buttonLoad, 0, wxALL, 5 );
	
	bSizer12->Add( bSizer121, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );
	
	m_textCtrlSaveFile = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_textCtrlSaveFile, 1, wxALL, 5 );
	
	m_buttonSaveToFileBrowser = new wxButton( this, wxID_ANY, wxT("..."), wxDefaultPosition, wxSize( 30,-1 ), 0 );
	m_buttonSaveToFileBrowser->SetDefault(); 
	bSizer13->Add( m_buttonSaveToFileBrowser, 0, wxALL, 5 );
	
	m_buttonSaveToFile1 = new wxButton( this, wxID_ANY, wxT("Save To File"), wxDefaultPosition, wxSize( 100,-1 ), 0 );
	m_buttonSaveToFile1->SetDefault(); 
	bSizer13->Add( m_buttonSaveToFile1, 0, wxALL, 5 );
	
	bSizer12->Add( bSizer13, 0, wxEXPAND, 5 );
	
	this->SetSizer( bSizer12 );
	this->Layout();
	m_menu = new wxMenu();
	wxMenuItem* m_menuItemDelete;
	m_menuItemDelete = new wxMenuItem( m_menu, wxID_ANY, wxString( wxT("Delete") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu->Append( m_menuItemDelete );
	
	wxMenuItem* m_menuItemInster;
	m_menuItemInster = new wxMenuItem( m_menu, wxID_ANY, wxString( wxT("Inster") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu->Append( m_menuItemInster );
	
	this->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CDialogTreeTestBase::CDialogTreeTestBaseOnContextMenu ), NULL, this ); 
	
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( CDialogTreeTestBase::OnInitDialog ) );
	m_treeCtrl1->Connect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CDialogTreeTestBase::OnRightDown ), NULL, this );
	m_buttonLoad->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CDialogTreeTestBase::OnButtonLoadClick ), NULL, this );
	m_buttonSaveToFileBrowser->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CDialogTreeTestBase::OnButtonSaveBrowserClick ), NULL, this );
	m_buttonSaveToFile1->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CDialogTreeTestBase::OnButtonSaveClick ), NULL, this );
	this->Connect( m_menuItemDelete->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( CDialogTreeTestBase::OnMenuItemDel ) );
	this->Connect( m_menuItemInster->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( CDialogTreeTestBase::OnMenuItemInster ) );
}

CDialogTreeTestBase::~CDialogTreeTestBase()
{
	// Disconnect Events
	this->Disconnect( wxEVT_INIT_DIALOG, wxInitDialogEventHandler( CDialogTreeTestBase::OnInitDialog ) );
	m_treeCtrl1->Disconnect( wxEVT_RIGHT_DOWN, wxMouseEventHandler( CDialogTreeTestBase::OnRightDown ), NULL, this );
	m_buttonLoad->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CDialogTreeTestBase::OnButtonLoadClick ), NULL, this );
	m_buttonSaveToFileBrowser->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CDialogTreeTestBase::OnButtonSaveBrowserClick ), NULL, this );
	m_buttonSaveToFile1->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CDialogTreeTestBase::OnButtonSaveClick ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( CDialogTreeTestBase::OnMenuItemDel ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( CDialogTreeTestBase::OnMenuItemInster ) );
	
	delete m_menu; 
}
