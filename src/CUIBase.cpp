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
	
	this->Centre( wxBOTH );
	
	// Connect Events
	m_btnVSPrj->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase::OnbtnVSPrjClick ), NULL, this );
	m_btnImport->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase::OnbtnImportClick ), NULL, this );
	m_grid_dir->Connect( wxEVT_GRID_EDITOR_SHOWN, wxGridEventHandler( CMainFrameBase::OnGridEditorShown ), NULL, this );
}

CMainFrameBase::~CMainFrameBase()
{
	// Disconnect Events
	m_btnVSPrj->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase::OnbtnVSPrjClick ), NULL, this );
	m_btnImport->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( CMainFrameBase::OnbtnImportClick ), NULL, this );
	m_grid_dir->Disconnect( wxEVT_GRID_EDITOR_SHOWN, wxGridEventHandler( CMainFrameBase::OnGridEditorShown ), NULL, this );
	
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
