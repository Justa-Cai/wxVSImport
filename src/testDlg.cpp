#include "testDlg.h"
#include "VCProjParse.h"

CDialogTreeTest::CDialogTreeTest( wxWindow* parent )
:CDialogTreeTestBase(parent),
m_pDoc(NULL),
m_pData(NULL)
{

}
//#define _MYTEST_
void CDialogTreeTest::OnInitDialog( wxInitDialogEvent& event )
{
#ifdef _MYTEST_
#define FILE_PATH "f:\\tmp\\uboot\\uboot.import.vcproj"

	m_pDoc = new TiXmlDocument(FILE_PATH);
	if (m_pDoc->LoadFile())
		ReLoadXmlToTree();
	else {
		delete m_pDoc;
		m_pDoc = NULL;
	}
//	delete doc;
#endif
}

void CDialogTreeTest::xml2Tree( wxTreeItemId idParent, TiXmlElement *root )
{
	TiXmlElement *pChild = root->FirstChildElement();
	while(pChild) {
		wxString str = pChild->Value();
		CTreeCtrlXMLData *data = NULL;
		if (str == "Filter")  {
			str = wxString::Format("%s_%s", str, pChild->Attribute("Name"));
			data = new CTreeCtrlXMLData(idParent, root, pChild);
		}
		wxTreeItemId idChild = m_treeCtrl1->AppendItem(idParent, str, -1, -1, data);
		xml2Tree(idChild, pChild);
		pChild = pChild->NextSiblingElement();
	}
}

void CDialogTreeTest::OnRightDown( wxMouseEvent& event )
{
	m_pData = (CTreeCtrlXMLData*)m_treeCtrl1->GetItemData(m_treeCtrl1->GetSelection());
	if (!m_pData)
		return;

	PopupMenu(m_menu);
}

void CDialogTreeTest::OnMenuItemDel( wxCommandEvent& event )
{
	if (!m_pData)
		return;
	m_pData->m_pRoot->RemoveChild(m_pData->m_pElement);
	m_treeCtrl1->Delete(m_pData->GetId());
	//m_treeCtrl1->DeleteAllItems();
	//ReLoadXmlToTree();
}

void CDialogTreeTest::OnMenuItemInster( wxCommandEvent& event )
{
	if (!m_pData)
		return;

	wxString path = wxDirSelector("Choose a folder");

	if (path.IsEmpty())
		return;

	TiXmlElement *pRoot = m_vcParse.dir2Xml(path, NULL);
	if (pRoot) {
		m_pData->m_pRoot->LinkEndChild(pRoot);
		xml2Tree(m_pData->m_idParent, pRoot);
#ifdef _MYTEST_
#define FILE_PATH_NEW "f:\\tmp\\uboot\\uboot.import.new.vcproj"
		if (wxFileExists(FILE_PATH_NEW))
			wxRemoveFile(FILE_PATH_NEW);
		m_pDoc->SaveFile(FILE_PATH_NEW);
#endif
	}
}

CDialogTreeTest::~CDialogTreeTest()
{
	if (m_pDoc)
		delete m_pDoc;
}

void CDialogTreeTest::ReLoadXmlToTree()
{
	if (!m_pDoc)
		return;
	// root
	TiXmlElement *pRoot = m_pDoc->RootElement();
	wxTreeItemId idRoot = m_treeCtrl1->AddRoot(pRoot->Value());

	xml2Tree(idRoot, pRoot);
}

void CDialogTreeTest::OnButtonLoadClick( wxCommandEvent& event )
{
	const wxString& str = wxFileSelector("Choose a File", wxEmptyString, wxEmptyString, wxEmptyString, "VC2005 Project|*.vcproj");
	if (!str.IsEmpty()) {

		m_textCtrlLoadPorject->SetLabel(str);
		if (m_pDoc) {
			m_treeCtrl1->DeleteAllItems();
			delete m_pDoc;
		}

		m_pDoc = new TiXmlDocument(str);
		if (m_pDoc->LoadFile())
			ReLoadXmlToTree();
		else {
			wxMessageBox(wxString::Format("Load File(%s) Fail", str));
			delete m_pDoc;
			m_pDoc = NULL;
		}
	}
}

void CDialogTreeTest::OnButtonSaveBrowserClick( wxCommandEvent& event )
{
	const wxString& str = wxFileSelector("Choose a File", wxEmptyString, wxEmptyString, wxEmptyString, "VC2005 Project|*.vcproj");
	if (!str.IsEmpty()) 
		m_textCtrlSaveFile->SetLabel(str);
}

void CDialogTreeTest::OnButtonSaveClick( wxCommandEvent& event )
{
	wxString str = m_textCtrlSaveFile->GetLabel();
	if (!str.IsEmpty()) {
		if (wxFileExists(str))
			wxRemoveFile(str);
		m_pDoc->SaveFile(str);
	}
}
