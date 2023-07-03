#pragma once
#include <functional>
#include <array>

namespace sofaraylib::raylib
{

void initWindow(int width, int height, const char *title);
void closeWindow();
void mainLoop(const std::function<void()>& physics, const std::function<void()>& rendering);
void drawTriangle(const std::array<float, 3>& p1, const std::array<float, 3>& p2, const std::array<float, 3>& p3);
void drawTriangle(const std::array<float, 3>& p1, const std::array<float, 3>& p2, const std::array<float, 3>& p3, const std::array<float, 4>& color);
void drawCircle(int centerX, int centerY, float radius);
void drawPoint(const std::array<float, 3>& position);

}
