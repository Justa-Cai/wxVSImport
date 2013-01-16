#ifndef _VCPROJPARSE_H_
#define _VCPROJPARSE_H_
#include "tinyxml.h"
#include "wx/wx.h"
class CVCProjParse
{
public:
	/** @brief 扫描目录，转换成dir2Xml结构(vcproj存储结构) 

	*   @param[in] pFilter 文件匹配 ,NULL 则使用默认("*.cpp" "*.h" "*.S")
	*/
	TiXmlElement *dir2Xml(wxString path, wxArrayString *pFilter);
};
#endif