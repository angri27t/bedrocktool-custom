#pragma once
#include <bedrocktools/modules/Module.hpp>
#include <bedrocktools/sdk/render/LevelRenderer.hpp>
#include <bedrocktools/math/Vec3.hpp>
#include <vector>
#include <string>

struct Waypoint {
    std::string name;
    Vec3 position;
    bool isDeathMarker;
    Color color;
};

class WaypointManager : public Module {
private:
    std::vector<Waypoint> waypoints;
    bool wasDead = false;

public:
    WaypointManager();

    void onTick(LocalPlayer* player) override;
    void onRender(LevelRenderer* renderer) override;

    void addWaypoint(const std::string& name, const Vec3& pos, Color color = Color(0, 255, 0));
    void clearWaypoints();
};
