#ifndef _TEST_DLG_H_
#define _TEST_DLG_H_

#include "wx/wx.h"
#include "CUIBase.h"
#include "tinyxml.h"
#include "VCProjParse.h"
/** @brief XML bind Tree Data */
class CTreeCtrlXMLData:public wxTreeItemData
{
public:
	CTreeCtrlXMLData::CTreeCtrlXMLData( wxTreeItemId idParent, TiXmlElement *root, TiXmlElement *element )
		:m_idParent(idParent),
		m_pRoot(root),
		m_pElement(element)
	{
	}

public:
	wxTreeItemId m_idParent;
	TiXmlElement *m_pRoot;
	TiXmlElement *m_pElement;
};


class CDialogTreeTest:public CDialogTreeTestBase
{
public:
	CDialogTreeTest(wxWindow* parent);
	~CDialogTreeTest();

	virtual void OnInitDialog( wxInitDialogEvent& event );

	void xml2Tree(wxTreeItemId idParent, TiXmlElement *root);

	virtual void OnRightDown( wxMouseEvent& event );

	virtual void OnMenuItemDel( wxCommandEvent& event );

	virtual void OnMenuItemInster( wxCommandEvent& event );

	virtual void OnButtonLoadClick( wxCommandEvent& event );

	virtual void OnButtonSaveClick( wxCommandEvent& event );

	virtual void OnButtonSaveBrowserClick( wxCommandEvent& event );
public:
	void ReLoadXmlToTree();




public:
	TiXmlDocument *m_pDoc;
	CTreeCtrlXMLData *m_pData;
	CVCProjParse m_vcParse;

};

#endif