#include <SofaRaylib/RaylibGUI.h>

#include <sofa/simulation/Node.h>
#include <sofa/simulation/Simulation.h>
#include <sofa/component/setting/ViewerSetting.h>
#include <sofa/core/visual/VisualParams.h>
#include <SofaRaylib/DrawToolRaylib.h>
#include <SofaRaylib/RaylibWrapper.h>

using namespace sofa;

namespace sofaraylib
{

bool RaylibGUI::init()
{
    constexpr int screenWidth = 800;
    constexpr int screenHeight = 450;
    raylib::initWindow(screenWidth, screenHeight, "SOFA");
    m_drawTool = std::make_unique<DrawToolRaylib>();
    return true;
}

int RaylibGUI::mainLoop()
{
    raylib::mainLoop([this](){this->physics();}, [this](){this->rendering();});
    return 0;
}

void RaylibGUI::redraw() 
{

}

int RaylibGUI::closeGUI()
{
    raylib::closeWindow();
    return 0;
}

void RaylibGUI::setScene(sofa::simulation::NodeSPtr groot, const char* filename, bool temporaryFile)
{
    std::string strFilename;
    if (filename)
    {
        strFilename = filename;
    }

    m_groot = groot;

    // needs to be done after for background
    this->configureGUI(groot);
}

sofa::simulation::Node* RaylibGUI::currentSimulation()
{ 
    return nullptr;
}

void RaylibGUI::setViewerResolution(int width, int height)
{
}

void RaylibGUI::setViewerConfiguration(sofa::component::setting::ViewerSetting* viewerConf)
{
    const type::Vec<2, int>& res = viewerConf->resolution.getValue();

    if (viewerConf->fullscreen.getValue())
    {
        m_bCreateWithFullScreen = true;
    }
    else
    {
        setViewerResolution(res[0], res[1]);
    }
}

void RaylibGUI::setFullScreen()
{
}

void RaylibGUI::setBackgroundColor(const sofa::type::RGBAColor& color)
{
}

void RaylibGUI::setBackgroundImage(const std::string& image)
{

}

sofa::gui::common::BaseGUI* RaylibGUI::CreateGUI(const char* name, sofa::simulation::NodeSPtr groot, const char* filename)
{
    RaylibGUI::mGuiName = name;
    auto* gui = new RaylibGUI();
    if (!gui->init())
    {
        return nullptr;
    }
    return gui;
}

void RaylibGUI::rendering()
{
    const auto vparams = sofa::core::visual::VisualParams::defaultInstance();
    vparams->drawTool() = m_drawTool.get();
    sofa::simulation::getSimulation()->draw(vparams, m_groot.get());
}

void RaylibGUI::physics()
{
    simulation::getSimulation()->animate(m_groot.get(), m_groot->getDt());
    simulation::getSimulation()->updateVisual(m_groot.get());
}

} // namespace sofaraylib
