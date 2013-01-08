#include <wx/wx.h>
#include "wx/wfstream.h"
#include <wx/mstream.h>
#include <wx/sstream.h>
#include <wx/dir.h>
#include "CUIBase.h"
#include "utils.h"
#include "tinyxml.h"
#include "tinystr.h"

#define STR_VERSION "wxVSImport V 0.1"

class MyApp: public wxApp
{
public:
	virtual bool OnInit();
};
wxIMPLEMENT_APP(MyApp);


class CGridInfo
{
public:
	wxString strFilterName;
	wxString strFilterPath;
	TiXmlElement *pElement;
};

class CMainFrame : public CMainFrameBase
{
public:
	wxArrayPtrVoid m_GridInfoPtr;
	int m_iTreeLevel;
	wxString m_strInfo;
public:
	CMainFrame( wxWindow* parent)
		:CMainFrameBase(parent)
	{
		m_textCtrlVSPrjPath->SetLabel("f:\\tmp\\uboot\\uboot.vcproj");
		//m_textCtrlSrcPath->SetLabel("f:\\tmp\\barebox");

		m_grid_dir->SetColLabelValue (0, "Import Name");
		m_grid_dir->SetColLabelValue (1, "Import Path");
		SetLabel(STR_VERSION);
	}

	virtual void OnbtnVSPrjClick( wxCommandEvent& event ) 
	{
		const wxString& str = wxFileSelector("Choose a File", wxEmptyString, wxEmptyString, wxEmptyString, "VC2005 Project|*.vcproj");

		if ( !str.empty() )
			m_textCtrlVSPrjPath->SetLabel(str);
	}


	void treePrint(wxString name, bool bDirs=TRUE)
	{
#if 0
		for (int i=0; i<m_iTreeLevel*5; i++) 
			m_textCtrlInfo->AppendText(" ");

		m_textCtrlInfo->AppendText("|--" + name + "\n");
#else
		for (int i=0; i<m_iTreeLevel*5; i++) 
			m_strInfo.Append(" ");

		if (bDirs)
			m_strInfo.Append("|--" + name + "\n");
		else
			m_strInfo.Append("|--*" + name + "\n");
#endif
	}

	void fileTrace(wxString path, TiXmlElement *pFilter) 
	{
		// todo RelativePath
		TiXmlElement *pNewFile = new TiXmlElement("File");
		pNewFile->SetAttribute("RelativePath", path);
		pFilter->LinkEndChild(pNewFile);
		treePrint(path, false);
	}

	int GetAllFiles(wxString path, wxArrayString *files)
	{
		int num=0;
		wxString filename;
		wxString filepath;
		wxFileName fn(path);
		wxString filedir = fn.GetPath() + "\\" + fn.GetName() + "\\";
		wxDir dir(path);
		bool cont;
		if (!dir.IsOpened())
			return 0;

		cont = dir.GetFirst(&filename, "*.c",  wxDIR_FILES);
		while(cont) {
			num++;
			filepath = filedir + filename;
			files->Add(filepath);
			cont = dir.GetNext(&filename);
		}

		cont = dir.GetFirst(&filename, "*.h",  wxDIR_FILES);
		while(cont) {
			num++;
			filepath = filedir + filename;
			files->Add(filepath);
			cont = dir.GetNext(&filename);
		}

		cont = dir.GetFirst(&filename, "*.S",  wxDIR_FILES);
		while(cont) {
			num++;
			filepath = filedir + filename;
			files->Add(filepath);
			cont = dir.GetNext(&filename);
		}
		return num;
	}

	void dirTrace(wxString path, TiXmlElement *pFilter) 
	{
		wxFileName f(path);

		TiXmlElement *pNewFilter = newFilter(f.GetName());
		treePrint(f.GetName());

		// link dir
		if (pFilter)
			pFilter->LinkEndChild(pNewFilter);

		m_iTreeLevel++;

		// find files first 
		wxArrayString arrayString;
		int num = GetAllFiles(path, &arrayString);
		for (int i=0; i<num; i++)
			fileTrace(arrayString[i], pNewFilter);

		wxDir dir(path);
		if (!dir.IsOpened()) {
			m_iTreeLevel--;
			return;
		}

		// find directory second
		wxString filename;
		bool cont = dir.GetFirst(&filename, wxEmptyString,  wxDIR_DIRS);
		while(cont) {
			wxString strPath = f.GetPath() + "\\" + f.GetName() + "\\" + filename;
			dirTrace(strPath, pNewFilter);
			cont = dir.GetNext(&filename);
		}
		m_iTreeLevel--;
	}

	TiXmlElement *newFilter(wxString name)
	{
		TiXmlElement *pNewFilter = new TiXmlElement("Filter");
		pNewFilter->SetAttribute("Name", name);
		pNewFilter->SetAttribute("Filter", "cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx");
		pNewFilter->SetAttribute("UniqueIdentifier", GetGUIDForVSProj());
		return pNewFilter;
	}

	void DoGetGridInfoString()
	{
		int row, col, i;
		wxString strFilterName, strFilterPath;
		row = m_grid_dir->GetNumberRows();
		col = m_grid_dir->GetNumberCols();
		m_GridInfoPtr.Empty();

		for (i=0; i<row; i++) {
			strFilterName = m_grid_dir->GetCellValue(i, 0);
			strFilterPath = m_grid_dir->GetCellValue(i, 1);
			if (strFilterName.IsEmpty())
				break;
			CGridInfo *pInfo = new CGridInfo;
			pInfo->strFilterName = strFilterName;
			pInfo->strFilterPath = strFilterPath;
			m_GridInfoPtr.Add(pInfo);
		}
	}

	virtual void OnbtnImportClick( wxCommandEvent& event ) 
	{
		wxString strInputPath = m_textCtrlVSPrjPath->GetValue();
		TiXmlDocument doc(strInputPath);
		wxFileName fn(strInputPath);
		int i;

		wxString strSavePath =wxString::Format("%s\\%s.import.vcproj", fn.GetPath(), fn.GetName());
		// 获取多个Filter的信息
		DoGetGridInfoString();
		int num = m_GridInfoPtr.GetCount();
		if (num<=0) {
			wxMessageBox("Not Import Path");
			return;
		}

		m_strInfo.empty();
		for (i=0; i<num; i++) {
			// 多个Filter
			m_iTreeLevel = 0;
			CGridInfo *pInfo = (CGridInfo*)m_GridInfoPtr[i];
			pInfo->pElement = newFilter(pInfo->strFilterName);
			dirTrace(pInfo->strFilterPath, pInfo->pElement);
		}
		m_textCtrlInfo->AppendText(m_strInfo);


		if (!doc.LoadFile()) {
			wxMessageBox(wxT("Load Fail"));
			return;
		}


		// 删除重复的多个Filter
		TiXmlElement* root = doc.FirstChildElement("VisualStudioProject"); 
		if (root) {
			TiXmlElement *files  = root->FirstChildElement("Files");
			if (files) {
				TiXmlElement* filter = files->FirstChildElement("Filter");
				while(filter) {
					wxString str = filter->Attribute("Name");

					for (i=0; i<num; i++) {
						CGridInfo *pInfo = (CGridInfo*)m_GridInfoPtr[i];
						if (str == pInfo->strFilterName) {
							files->RemoveChild(filter);
							break;
						}
					}
					filter = filter->NextSiblingElement("Filter");
				}
				for (i=0; i<num; i++) {
					CGridInfo *pInfo = (CGridInfo*)m_GridInfoPtr[i];
					files->LinkEndChild(pInfo->pElement);
				}
			}
		}

		doc.SaveFile(strSavePath);

		m_textCtrlInfo->AppendText("\n ** Output Project Path:  " + strSavePath);

		/*
		<Files>
			<Filter
			Name="源文件"
			Filter="cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx"
			UniqueIdentifier="{4FC737F1-C7A5-4376-A066-2A32D752A2FF}"
			>
			<File
			RelativePath=".\main.cpp"
			>
			</File>
			</Filter>
			<Filter
			Name="头文件"
			Filter="h;hpp;hxx;hm;inl;inc;xsd"
			UniqueIdentifier="{93995380-89BD-4b04-88EB-625FBE52EBFB}"
			>
			</Filter>
			<Filter
			Name="资源文件"
			Filter="rc;ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe;resx;tiff;tif;png;wav"
			UniqueIdentifier="{67DA6AB6-F800-4c08-8B7A-83BB121AAD01}"
			>
			</Filter>
			</Files>*/
	}

	virtual void OnGridEditorShown( wxGridEvent& event ) 
	{
		int row, col;
		row = event.GetRow(); // 行？
		col = event.GetCol(); // 列?
		if (col==1) {
			const wxString& dir = wxDirSelector("Choose a folder");
			if ( !dir.empty() ) {
				wxFileName f(dir);
				m_grid_dir->SetCellValue(row, col, dir);
				m_grid_dir->SetCellValue(row, 0, "Import." + f.GetName());
			}
		}
	}

};


bool MyApp::OnInit()
{
	CMainFrame *frame = new CMainFrame(NULL);
	frame->Show( true );
	return true;
}
