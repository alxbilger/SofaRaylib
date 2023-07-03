#include <SofaRaylib/config.h>

#include <sofa/core/ObjectFactory.h>
#include <sofa/gui/common/GUIManager.h>
#include <SofaRaylib/RaylibGUI.h>
using sofa::core::ObjectFactory;

extern "C" {
    SOFARAYLIB_API void initExternalModule();
    SOFARAYLIB_API const char* getModuleName();
    SOFARAYLIB_API const char* getModuleVersion();
    SOFARAYLIB_API const char* getModuleLicense();
    SOFARAYLIB_API const char* getModuleDescription();
    SOFARAYLIB_API const char* getModuleComponentList();
}

void initExternalModule()
{
    static bool first = true;
    if (first)
    {
        first = false;

        sofa::gui::common::GUIManager::RegisterGUI("raylib", &sofaraylib::RaylibGUI::CreateGUI);
    }
}

const char* getModuleName()
{
    return sofa_tostring(SOFA_TARGET);
}

const char* getModuleVersion()
{
    return sofa_tostring(DILIGENTRENDERER_VERSION);
}

const char* getModuleLicense()
{
    return "MIT";
}

const char* getModuleDescription()
{
    return "SOFA plugin containing a SOFA GUI based on Raylib";
}

const char* getModuleComponentList()
{
    /// string containing the names of the classes provided by the plugin
    static std::string classes = ObjectFactory::getInstance()->listClassesFromTarget(sofa_tostring(SOFA_TARGET));
    return classes.c_str();
}
