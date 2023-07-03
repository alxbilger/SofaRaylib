#pragma once
#include <SofaRaylib/config.h>

#include <sofa/gui/common/BaseGUI.h>
#include <sofa/simulation/Node.h>
#include <sofa/helper/visual/DrawTool.h>

namespace sofaraylib
{

class SOFARAYLIB_API RaylibGUI : public sofa::gui::common::BaseGUI
{
public:
    RaylibGUI() = default;
    ~RaylibGUI() override = default;

    bool init();

    /// BaseGUI API
    int mainLoop() override;
    void redraw() override;
    int closeGUI() override;
    void setScene(sofa::simulation::NodeSPtr groot, const char* filename = nullptr, bool temporaryFile = false) override;
    sofa::simulation::Node* currentSimulation() override;
    void setViewerResolution(int width, int height) override;
    void setViewerConfiguration(sofa::component::setting::ViewerSetting* viewerConf) override;
    void setFullScreen() override;
    void setBackgroundColor(const sofa::type::RGBAColor& color) override;
    void setBackgroundImage(const std::string& image) override;
    static sofa::gui::common::BaseGUI * CreateGUI(const char* name, sofa::simulation::NodeSPtr groot, const char* filename);

protected:

    bool m_bCreateWithFullScreen{ false };

    void rendering();
    void physics();

    sofa::simulation::Node::SPtr m_groot;
    std::unique_ptr<sofa::helper::visual::DrawTool> m_drawTool;
};

} // namespace sofaraylib
