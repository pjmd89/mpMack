#/**********************************************************\ 
#
# Auto-Generated Plugin Configuration file
# for mpMack
#
#\**********************************************************/

set(PLUGIN_NAME "mpMack")
set(PLUGIN_PREFIX "MPMK")
set(COMPANY_NAME "mp_s")

# ActiveX constants:
set(FBTYPELIB_NAME mpMackLib)
set(FBTYPELIB_DESC "mpMack 1.0 Type Library")
set(IFBControl_DESC "mpMack Control Interface")
set(FBControl_DESC "mpMack Control Class")
set(IFBComJavascriptObject_DESC "mpMack IComJavascriptObject Interface")
set(FBComJavascriptObject_DESC "mpMack ComJavascriptObject Class")
set(IFBComEventSource_DESC "mpMack IFBComEventSource Interface")
set(AXVERSION_NUM "1")

# NOTE: THESE GUIDS *MUST* BE UNIQUE TO YOUR PLUGIN/ACTIVEX CONTROL!  YES, ALL OF THEM!
set(FBTYPELIB_GUID ce1fc503-c3f3-5952-afef-447aba130815)
set(IFBControl_GUID 0cc07918-b214-5bb9-a30d-03d828337ad5)
set(FBControl_GUID f4194efd-fe8e-5799-ad81-1b28c7f9055a)
set(IFBComJavascriptObject_GUID 8815816e-faff-5b2e-89ca-02be3f49d796)
set(FBComJavascriptObject_GUID 56ab7ff6-ebb5-566c-be5f-489a3cda8b64)
set(IFBComEventSource_GUID 02d067e6-cc06-523d-87a1-c4de65017c0c)
if ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID c34389c1-a3ee-5310-8a52-4c2e966a1464)
else ( FB_PLATFORM_ARCH_32 )
    set(FBControl_WixUpgradeCode_GUID 859ab25d-cb7a-5be1-bd22-83dd13f6d287)
endif ( FB_PLATFORM_ARCH_32 )

# these are the pieces that are relevant to using it from Javascript
set(ACTIVEX_PROGID "mp_s.mpMack")
if ( FB_PLATFORM_ARCH_32 )
    set(MOZILLA_PLUGINID "munoz.org.ve/mpMack")  # No 32bit postfix to maintain backward compatability.
else ( FB_PLATFORM_ARCH_32 )
    set(MOZILLA_PLUGINID "munoz.org.ve/mpMack_${FB_PLATFORM_ARCH_NAME}")
endif ( FB_PLATFORM_ARCH_32 )

# strings
set(FBSTRING_CompanyName "mp")
set(FBSTRING_PluginDescription "Get mac from a PC")
set(FBSTRING_PLUGIN_VERSION "1.0.0.0")
set(FBSTRING_LegalCopyright "Copyright 2014 mp")
set(FBSTRING_PluginFileName "np${PLUGIN_NAME}")
set(FBSTRING_ProductName "mpMack")
set(FBSTRING_FileExtents "")
if ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "mpMack")  # No 32bit postfix to maintain backward compatability.
else ( FB_PLATFORM_ARCH_32 )
    set(FBSTRING_PluginName "mpMack_${FB_PLATFORM_ARCH_NAME}")
endif ( FB_PLATFORM_ARCH_32 )
set(FBSTRING_MIMEType "application/x-mpmack")

# Uncomment this next line if you're not planning on your plugin doing
# any drawing:

#set (FB_GUI_DISABLED 1)

# Mac plugin settings. If your plugin does not draw, set these all to 0
set(FBMAC_USE_QUICKDRAW 0)
set(FBMAC_USE_CARBON 1)
set(FBMAC_USE_COCOA 1)
set(FBMAC_USE_COREGRAPHICS 1)
set(FBMAC_USE_COREANIMATION 0)
set(FBMAC_USE_INVALIDATINGCOREANIMATION 0)

# If you want to register per-machine on Windows, uncomment this line
#set (FB_ATLREG_MACHINEWIDE 1)
