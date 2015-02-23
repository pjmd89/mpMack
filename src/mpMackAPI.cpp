/**********************************************************\

  Auto-generated mpMackAPI.cpp

\**********************************************************/

#include "JSObject.h"
#include "variant_list.h"
#include "DOM/Document.h"
#include "global/config.h"
#include "DOM/Window.h"

#include "mpMackAPI.h"

#include <regex>

#define WIN32_LEAN_AND_MEAN		// Exclude rarely-used stuff from Windows headers
#include <stdio.h>
#include <tchar.h>

#include <Windows.h>
#include <Iphlpapi.h>
#include <Assert.h>
#pragma comment(lib, "iphlpapi.lib")

#include <sstream>
///////////////////////////////////////////////////////////////////////////////
/// @fn FB::variant mpMackAPI::echo(const FB::variant& msg)
///
/// @brief  Echos whatever is passed from Javascript.
///         Go ahead and change it. See what happens!
///////////////////////////////////////////////////////////////////////////////
/*
FB::variant mpMackAPI::echos(const FB::variant& msg)
{
    static int n(0);
    fire_echo("So far, you clicked this many times: ", n++);

    // return "foobar";
    return msg;
}
*/
///////////////////////////////////////////////////////////////////////////////
/// getUrl
std::string mpMackAPI::_getUrl(){

	return m_host->getDOMWindow()->getLocation();
}
std::string mpMackAPI::_getHost(){
	
	std::tr1::cmatch res;

	std::string url = m_host->getDOMWindow()->getLocation();

	std::tr1::regex rx("[http|https]://([^/]+)");

	std::tr1::regex_search( url.c_str() , res , rx );

	return res[1];
}

FB::VariantMap mpMackAPI::getMac(){

	FB::VariantMap str;

	str["err"] = true;

	str["msg"] = "do not permisions";

	if(_domainApply()){

		str = _setMACVar();

		str["err"] = false;

		str["msg"] = "";
	}
	return str;
}

bool mpMackAPI::_domainApply(){

	char* domains[] = {"munoz.org.ve","prueba.munoz.org.ve"};

	int totalDomains = (sizeof(domains) / sizeof(*domains));

	bool apply = false;

	for( int i = 0; i < totalDomains ; i++ ){

		if( _getHost() == domains[i]){

			apply = true;
		}
	}

	return apply;
}
FB::VariantMap mpMackAPI::_setMACVar(){

	IP_ADAPTER_INFO AdapterInfo[16];

	short int i = 0;

	using std::to_string;

	using std::hex;

	using std::string;

	using std::stoi;

	FB::VariantMap allMacs,subMap;

	DWORD dwBufLen = sizeof(AdapterInfo);

	DWORD dwStatus = GetAdaptersInfo(
		AdapterInfo,
		&dwBufLen);
	assert(dwStatus == ERROR_SUCCESS);

	PIP_ADAPTER_INFO pAdapterInfo = AdapterInfo;

	do {

		std::string s("MAC_");

		s += to_string(i);

		std::stringstream stream0,stream1,stream2,stream3,stream4,stream5;

		stream0 << hex << stoi(to_string(pAdapterInfo->Address[0]));

		stream1 << hex << stoi(to_string(pAdapterInfo->Address[1]));

		stream2 << hex << stoi(to_string(pAdapterInfo->Address[2]));

		stream3 << hex << stoi(to_string(pAdapterInfo->Address[3]));

		stream4 << hex << stoi(to_string(pAdapterInfo->Address[4]));

		stream5 << hex << stoi(to_string(pAdapterInfo->Address[5]));

		subMap[s] = string(stream0.str()) + "-" + string(stream1.str()) + "-" +
			string(stream2.str()) + "-" + string(stream3.str()) + "-" +
			string(stream4.str()) + "-" + string(stream5.str());
		
		pAdapterInfo = pAdapterInfo->Next;

		i++;
	}
	while(pAdapterInfo);

	allMacs["mac"] = subMap;

	return allMacs;
}
///////////////////////////////////////////////////////////////////////////////
/// @fn mpMackPtr mpMackAPI::getPlugin()
///
/// @brief  Gets a reference to the plugin that was passed in when the object
///         was created.  If the plugin has already been released then this
///         will throw a FB::script_error that will be translated into a
///         javascript exception in the page.
///////////////////////////////////////////////////////////////////////////////
mpMackPtr mpMackAPI::getPlugin()
{
    mpMackPtr plugin(m_plugin.lock());
    if (!plugin) {
        throw FB::script_error("The plugin is invalid");
    }
    return plugin;
}

// Read/Write property testString
std::string mpMackAPI::get_testString()
{
    return m_testString;
}

void mpMackAPI::set_testString(const std::string& val)
{
    m_testString = val;
}

// Read-only property version
std::string mpMackAPI::get_version()
{
    return FBSTRING_PLUGIN_VERSION;
}
