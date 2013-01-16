#include "VCProjParse.h"
#include "wx/filename.h"
#include "wx/dir.h"
#include "utils.h"
static wxArrayString g_defaultFilesFilterArray;
static wxArrayString g_newFilesFilterArray;

static int GetAllFiles(wxString path, wxArrayString *files)
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

	for (int i=0; i<(int)g_newFilesFilterArray.GetCount(); i++) {
		cont = dir.GetFirst(&filename, g_newFilesFilterArray[i],  wxDIR_FILES);
		while(cont) {
			num++;
			filepath = filedir + filename;
			files->Add(filepath);
			cont = dir.GetNext(&filename);
		}
	}
	return num;
}

static void fileTrace(wxString path, TiXmlElement *pFilter) 
{
	// todo RelativePath
	TiXmlElement *pNewFile = new TiXmlElement("File");
	pNewFile->SetAttribute("RelativePath", path);
	pFilter->LinkEndChild(pNewFile);
}

static TiXmlElement *newFilter(wxString name)
{
	TiXmlElement *pNewFilter = new TiXmlElement("Filter");
	pNewFilter->SetAttribute("Name", name);
	pNewFilter->SetAttribute("Filter", "cpp;c;cc;cxx;def;odl;idl;hpj;bat;asm;asmx");
	pNewFilter->SetAttribute("UniqueIdentifier", GetGUIDForVSProj());
	return pNewFilter;
}

static void dirTrace(wxString path, TiXmlElement *pFilter) 
{
	wxFileName f(path);

	TiXmlElement *pNewFilter = newFilter(f.GetName());

	// link dir
	if (pFilter)
		pFilter->LinkEndChild(pNewFilter);

	// find files first 
	wxArrayString arrayString;
	int num = GetAllFiles(path, &arrayString);
	for (int i=0; i<num; i++)
		fileTrace(arrayString[i], pNewFilter);

	wxDir dir(path);
	if (!dir.IsOpened()) {
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
}

TiXmlElement * CVCProjParse::dir2Xml( wxString path, wxArrayString *pFilter)
{
	static bool g_bInit = false;
	if (!g_bInit) {
		g_bInit = true;
		g_defaultFilesFilterArray.Add("*.c");
		g_defaultFilesFilterArray.Add("*.h");
		g_defaultFilesFilterArray.Add("*.S");
	}

	if (pFilter==NULL || pFilter->GetCount()==0)
		g_newFilesFilterArray = g_defaultFilesFilterArray;
	else
		g_newFilesFilterArray = *pFilter;

	wxFileName f(path);
	TiXmlElement *pNewFilter = newFilter("Import_" + f.GetName());
	dirTrace(path, pNewFilter);

	return pNewFilter;
}

