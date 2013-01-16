#ifndef _VCPROJPARSE_H_
#define _VCPROJPARSE_H_
#include "tinyxml.h"
#include "wx/wx.h"
class CVCProjParse
{
public:
	/** @brief ɨ��Ŀ¼��ת����dir2Xml�ṹ(vcproj�洢�ṹ) 

	*   @param[in] pFilter �ļ�ƥ�� ,NULL ��ʹ��Ĭ��("*.cpp" "*.h" "*.S")
	*/
	TiXmlElement *dir2Xml(wxString path, wxArrayString *pFilter);
};
#endif