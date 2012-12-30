#include <objbase.h>
#include "utils.h"

wxString GetGUIDForVSProj()
{
	wxString str;
	str.Printf("{%s}", GetGUID());
	return str;
};
wxString GetGUID()
{
	wxString str;
	GUID guid;
	CoInitialize(NULL);
	if (S_OK == CoCreateGuid(&guid))
	{
		str.Printf("%08X-%04X-%04X-%02X%02X-%02X%02X%02X%02X%02X%02X",
			guid.Data1,
			guid.Data2,
			guid.Data3,
			guid.Data4[0],
			guid.Data4[1],
			guid.Data4[2], 
			guid.Data4[3],
			guid.Data4[4],
			guid.Data4[5],
			guid.Data4[6],
			guid.Data4[7]);
	}
	CoUninitialize();
	return str;
}