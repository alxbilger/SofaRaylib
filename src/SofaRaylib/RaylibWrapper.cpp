#include <SofaRaylib/RaylibWrapper.h>
#include <raylib.h>

namespace sofaraylib::raylib
{

Camera3D camera = { 0 };

void initWindow(int width, int height, const char* title)
{
    InitWindow(width, height, title);
    SetTargetFPS(0);

    camera.position = { 100.0f, 100.0f, 100.0f }; // Camera position
    camera.target = { 0.0f, 0.0f, 0.0f };      // Camera looking at point
    camera.up = { 0.0f, 1.0f, 0.0f };          // Camera up vector (rotation towards target)
    camera.fovy = 45.0f;                                // Camera field-of-view Y
    camera.projection = CAMERA_PERSPECTIVE;             // Camera projection type

    SetCameraMode(camera, CAMERA_ORBITAL);
}

void closeWindow()
{
    CloseWindow();
}

void mainLoop(const std::function<void()>& physics, const std::function<void()>& rendering)
{
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        physics();

        BeginDrawing();

            ClearBackground(RAYWHITE);

            UpdateCamera(&camera);

            BeginMode3D(camera);

                rendering();

            EndMode3D();

            DrawFPS(10, 10);

        EndDrawing();
    }
}

Vector3 toRaylib(const std::array<float, 3>& v)
{
    return { v[0], v[1], v[2] };
}

Color toRaylib(const std::array<float, 4>& v)
{
    return {static_cast<unsigned char>(v[0] * 255.f),
        static_cast<unsigned char>(v[1] * 255.f),
        static_cast<unsigned char>(v[2] * 255.f),
        255};
}

void drawTriangle(const std::array<float, 3>& p1, const std::array<float, 3>& p2, const std::array<float, 3>& p3)
{
    DrawTriangle3D(toRaylib(p1), toRaylib(p2), toRaylib(p3), RED);

}

void drawTriangle(const std::array<float, 3>& p1, const std::array<float, 3>& p2, const std::array<float, 3>& p3, const std::array<float, 4>& color)
{
    DrawTriangle3D(toRaylib(p1), toRaylib(p2), toRaylib(p3), toRaylib(color));
}

void drawCircle(int centerX, int centerY, float radius)
{
    DrawCircle(centerX, centerY, radius, RED);
}

void drawPoint(const std::array<float, 3>& position)
{
    DrawPoint3D(toRaylib(position), RED);
}
}
