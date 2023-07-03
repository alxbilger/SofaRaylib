#include <SofaRaylib/DrawToolRaylib.h>
#include <SofaRaylib/RaylibGUI.h>
#include <SofaRaylib/RaylibWrapper.h>

namespace sofaraylib
{
DrawToolRaylib::~DrawToolRaylib()
{}

void DrawToolRaylib::init()
{}

std::array<float, 3> toStd(const sofa::type::Vec3& v)
{
    return { static_cast<float>(v[0]), static_cast<float>(v[1]), static_cast<float>(v[2])};
}

std::array<float, 4> toStd(const sofa::type::RGBAColor& v)
{
    return { static_cast<float>(v[0]), static_cast<float>(v[1]), static_cast<float>(v[2]), static_cast<float>(v[3])};
}

void DrawToolRaylib::drawPoints(const std::vector<Vec3>& points, float size, const RGBAColor& color)
{
    for (const auto& p : points)
    {
        raylib::drawPoint(toStd(p));
    }
}

void DrawToolRaylib::drawPoints(const std::vector<Vec3>& points, float size, const std::vector<RGBAColor>& color)
{}

void DrawToolRaylib::drawLine(const Vec3& p1, const Vec3& p2, const RGBAColor& color)
{}

void DrawToolRaylib::drawInfiniteLine(const Vec3& point, const Vec3& direction, const RGBAColor& color)
{}

void DrawToolRaylib::drawLines(const std::vector<Vec3>& points, float size, const RGBAColor& color)
{}

void DrawToolRaylib::drawLines(const std::vector<Vec3>& points, float size, const std::vector<RGBAColor>& colors)
{}

void DrawToolRaylib::drawLines(const std::vector<Vec3>& points, const std::vector<Vec2i>& index, float size, const RGBAColor& color)
{}

void DrawToolRaylib::drawLineStrip(const std::vector<Vec3>& points, float size, const RGBAColor& color)
{}

void DrawToolRaylib::drawLineLoop(const std::vector<Vec3>& points, float size, const RGBAColor& color)
{}

void DrawToolRaylib::drawDisk(float radius, double from, double to, int resolution, const RGBAColor& color)
{}

void DrawToolRaylib::drawCircle(float radius, float lineThickness, int resolution, const RGBAColor& color)
{}

void DrawToolRaylib::drawTriangles(const std::vector<Vec3>& points, const RGBAColor& color)
{}

void DrawToolRaylib::drawTriangles(const std::vector<Vec3>& points, const Vec3& normal, const RGBAColor& color)
{}

void DrawToolRaylib::drawTriangles(const std::vector<Vec3>& points, const std::vector<Vec3i>& index, const std::vector<Vec3>& normal, const RGBAColor& color)
{}

void DrawToolRaylib::drawTriangles(const std::vector<Vec3>& points, const std::vector<Vec3i>& index, const std::vector<Vec3>& normal, const std::vector<RGBAColor>& color)
{}

void DrawToolRaylib::drawTriangles(const std::vector<Vec3>& points, const std::vector<RGBAColor>& color)
{}

void DrawToolRaylib::drawTriangles(const std::vector<Vec3>& points, const std::vector<Vec3>& normal, const std::vector<RGBAColor>& color)
{}

void DrawToolRaylib::drawTriangleStrip(const std::vector<Vec3>& points, const std::vector<Vec3>& normal, const RGBAColor& color)
{}

void DrawToolRaylib::drawTriangleFan(const std::vector<Vec3>& points, const std::vector<Vec3>& normal, const RGBAColor& color)
{}

void DrawToolRaylib::drawFrame(const Vec3& position, const Quaternion& orientation, const Vec3f& size)
{}

void DrawToolRaylib::drawFrame(const Vec3& position, const Quaternion& orientation, const Vec3f& size, const RGBAColor& color)
{}

void DrawToolRaylib::drawSpheres(const std::vector<Vec3>& points, const std::vector<float>& radius, const RGBAColor& color)
{}

void DrawToolRaylib::drawSpheres(const std::vector<Vec3>& points, float radius, const RGBAColor& color)
{}

void DrawToolRaylib::drawFakeSpheres(const std::vector<Vec3>& points, const std::vector<float>& radius, const RGBAColor& color)
{}

void DrawToolRaylib::drawFakeSpheres(const std::vector<Vec3>& points, float radius, const RGBAColor& color)
{}

void DrawToolRaylib::drawCone(const Vec3& p1, const Vec3& p2, float radius1, float radius2, const RGBAColor& color, int subd)
{}

void DrawToolRaylib::drawCube(const float& radius, const RGBAColor& color, const int& subd)
{}

void DrawToolRaylib::drawCylinder(const Vec3& p1, const Vec3& p2, float radius, const RGBAColor& color, int subd)
{}

void DrawToolRaylib::drawCapsule(const Vec3& p1, const Vec3& p2, float radius, const RGBAColor& color, int subd)
{}

void DrawToolRaylib::drawArrow(const Vec3& p1, const Vec3& p2, float radius, const RGBAColor& color, int subd)
{}

void DrawToolRaylib::drawArrow(const Vec3& p1, const Vec3& p2, float radius, float coneLength, const RGBAColor& color, int subd)
{}

void DrawToolRaylib::drawArrow(const Vec3& p1, const Vec3& p2, float radius, float coneLength, float coneRadius, const RGBAColor& color, int subd)
{}

void DrawToolRaylib::drawCross(const Vec3& p, float length, const RGBAColor& color)
{}

void DrawToolRaylib::drawPlus(const float& radius, const RGBAColor& color, const int& subd)
{}

void DrawToolRaylib::drawPoint(const Vec3& p, const RGBAColor& c)
{}

void DrawToolRaylib::drawPoint(const Vec3& p, const Vec3& n, const RGBAColor& c)
{}

void DrawToolRaylib::drawTriangle(const Vec3& p1, const Vec3& p2, const Vec3& p3, const Vec3& normal)
{
    raylib::drawTriangle(toStd(p1), toStd(p2), toStd(p3));
}

void DrawToolRaylib::drawTriangle(const Vec3& p1, const Vec3& p2, const Vec3& p3, const Vec3& normal, const RGBAColor& c)
{}

void DrawToolRaylib::drawTriangle(const Vec3& p1, const Vec3& p2, const Vec3& p3, const Vec3& normal, const RGBAColor& c1, const RGBAColor& c2, const RGBAColor& c3)
{}

void DrawToolRaylib::drawTriangle(const Vec3& p1, const Vec3& p2, const Vec3& p3, const Vec3& normal1, const Vec3& normal2, const Vec3& normal3, const RGBAColor& c1, const RGBAColor& c2, const RGBAColor& c3)
{}

void DrawToolRaylib::drawQuad(const Vec3& p1, const Vec3& p2, const Vec3& p3, const Vec3& p4, const Vec3& normal)
{}

void DrawToolRaylib::drawQuad(const Vec3& p1, const Vec3& p2, const Vec3& p3, const Vec3& p4, const Vec3& normal, const RGBAColor& c)
{}

void DrawToolRaylib::drawQuad(const Vec3& p1, const Vec3& p2, const Vec3& p3, const Vec3& p4, const Vec3& normal, const RGBAColor& c1, const RGBAColor& c2, const RGBAColor& c3, const RGBAColor& c4)
{}

void DrawToolRaylib::drawQuad(const Vec3& p1, const Vec3& p2, const Vec3& p3, const Vec3& p4, const Vec3& normal1, const Vec3& normal2, const Vec3& normal3, const Vec3& normal4, const RGBAColor& c1, const RGBAColor& c2, const RGBAColor& c3, const RGBAColor& c4)
{}

void DrawToolRaylib::drawQuads(const std::vector<Vec3>& points, const RGBAColor& color)
{}

void DrawToolRaylib::drawQuads(const std::vector<Vec3>& points, const std::vector<RGBAColor>& colors)
{
    for (std::size_t i = 0; i < points.size(); i += 4)
    {
        raylib::drawTriangle(toStd(points[i]), toStd(points[i + 1]), toStd(points[i + 2]), toStd(colors[i]));
        raylib::drawTriangle(toStd(points[i]), toStd(points[i + 2]), toStd(points[i + 3]), toStd(colors[i]));
    }
}

void DrawToolRaylib::drawTetrahedron(const Vec3& p0, const Vec3& p1, const Vec3& p2, const Vec3& p3, const RGBAColor& color)
{}

void DrawToolRaylib::drawScaledTetrahedron(const Vec3& p0, const Vec3& p1, const Vec3& p2, const Vec3& p3, const RGBAColor& color, const float scale)
{}

void DrawToolRaylib::drawTetrahedra(const std::vector<Vec3>& points, const RGBAColor& color)
{}

void DrawToolRaylib::drawScaledTetrahedra(const std::vector<Vec3>& points, const RGBAColor& color, const float scale)
{}

void DrawToolRaylib::drawHexahedron(const Vec3& p0, const Vec3& p1, const Vec3& p2, const Vec3& p3, const Vec3& p4, const Vec3& p5, const Vec3& p6, const Vec3& p7, const RGBAColor& color)
{}

void DrawToolRaylib::drawHexahedra(const std::vector<Vec3>& points, const RGBAColor& color)
{}

void DrawToolRaylib::drawScaledHexahedra(const std::vector<Vec3>& points, const RGBAColor& color, const float scale)
{}

void DrawToolRaylib::drawSphere(const Vec3& p, float radius)
{}

void DrawToolRaylib::drawSphere(const Vec3& p, float radius, const RGBAColor& color)
{}

void DrawToolRaylib::drawEllipsoid(const Vec3& p, const Vec3& radii)
{}

void DrawToolRaylib::drawBoundingBox(const Vec3& min, const Vec3& max, float size)
{}

void DrawToolRaylib::draw3DText(const Vec3& p, float scale, const RGBAColor& color, const char* text)
{}

void DrawToolRaylib::draw3DText_Indices(const std::vector<Vec3>& positions, float scale, const RGBAColor& color)
{}

void DrawToolRaylib::pushMatrix()
{}

void DrawToolRaylib::popMatrix()
{}

void DrawToolRaylib::multMatrix(float*)
{}

void DrawToolRaylib::scale(float)
{}

void DrawToolRaylib::translate(float x, float y, float z)
{}

void DrawToolRaylib::setMaterial(const RGBAColor& color)
{}

void DrawToolRaylib::resetMaterial(const RGBAColor& color)
{}

void DrawToolRaylib::resetMaterial()
{}

void DrawToolRaylib::setPolygonMode(int _mode, bool _wireframe)
{}

void DrawToolRaylib::setLightingEnabled(bool _isAnabled)
{}

void DrawToolRaylib::enableBlending()
{}

void DrawToolRaylib::disableBlending()
{}

void DrawToolRaylib::enableLighting()
{}

void DrawToolRaylib::disableLighting()
{}

void DrawToolRaylib::enableDepthTest()
{}

void DrawToolRaylib::disableDepthTest()
{}

void DrawToolRaylib::saveLastState()
{}

void DrawToolRaylib::restoreLastState()
{}

void DrawToolRaylib::writeOverlayText(int x, int y, unsigned fontSize, const RGBAColor& color, const char* text)
{}

void DrawToolRaylib::enablePolygonOffset(float factor, float units)
{}

void DrawToolRaylib::disablePolygonOffset()
{}

void DrawToolRaylib::readPixels(int x, int y, int w, int h, float* rgb, float* z)
{}

void DrawToolRaylib::clear()
{
    DrawTool::clear();
}
}
