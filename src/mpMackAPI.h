/**********************************************************\

  Auto-generated mpMackAPI.h

\**********************************************************/

#include <string>
#include <sstream>
#include <boost/weak_ptr.hpp>
#include "JSAPIAuto.h"
#include "BrowserHost.h"
#include "mpMack.h"

#ifndef H_mpMackAPI
#define H_mpMackAPI

class mpMackAPI : public FB::JSAPIAuto
{
public:
    ////////////////////////////////////////////////////////////////////////////
    /// @fn mpMackAPI::mpMackAPI(const mpMackPtr& plugin, const FB::BrowserHostPtr host)
    ///
    /// @brief  Constructor for your JSAPI object.
    ///         You should register your methods, properties, and events
    ///         that should be accessible to Javascript from here.
    ///
    /// @see FB::JSAPIAuto::registerMethod
    /// @see FB::JSAPIAuto::registerProperty
    /// @see FB::JSAPIAuto::registerEvent
    ////////////////////////////////////////////////////////////////////////////
    mpMackAPI(const mpMackPtr& plugin, const FB::BrowserHostPtr& host) :
        m_plugin(plugin), m_host(host)
    {
		registerMethod("getMac",      make_method(this, &mpMackAPI::getMac));
    }

    ///////////////////////////////////////////////////////////////////////////////
    /// @fn mpMackAPI::~mpMackAPI()
    ///
    /// @brief  Destructor.  Remember that this object will not be released until
    ///         the browser is done with it; this will almost definitely be after
    ///         the plugin is released.
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~mpMackAPI() {};

    mpMackPtr getPlugin();

	FB::VariantMap getMac();

    // Read/Write property ${PROPERTY.ident}
    std::string get_testString();
    void set_testString(const std::string& val);

    // Read-only property ${PROPERTY.ident}
    std::string get_version();

    // Event helpers
    FB_JSAPI_EVENT(test, 0, ());
    FB_JSAPI_EVENT(echo, 2, (const FB::variant&, const int));

    // Method test-event
    void testEvent();

private:
	FB::VariantMap _setMACVar();
	std::string _getUrl();
	std::string _getHost();
    mpMackWeakPtr m_plugin;
	bool mpMackAPI::_domainApply();
    FB::BrowserHostPtr m_host;

    std::string m_testString;
};

#endif // H_mpMackAPI

