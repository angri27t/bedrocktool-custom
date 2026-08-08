#include "bedrocktools/modules/visual/WaypointManager.hpp"
#include <bedrocktools/sdk/actor/LocalPlayer.hpp>

WaypointManager::WaypointManager() 
    : Module("WaypointManager", "Menyimpan koordinat titik kematian dan lokasi waypoint", Category::VISUAL) {}

void WaypointManager::onTick(LocalPlayer* player) {
    if (!player || !isEnabled()) return;

    bool isCurrentlyDead = player->isDead() || player->getHealth() <= 0;

    if (isCurrentlyDead && !wasDead) {
        Vec3 deathPos = player->getPosition();

        for (auto it = waypoints.begin(); it != waypoints.end();) {
            if (it->isDeathMarker) it = waypoints.erase(it);
            else ++it;
        }

        waypoints.push_back({"Titik Kematian", deathPos, true, Color(255, 0, 0)});
    }

    wasDead = isCurrentlyDead;
}

void WaypointManager::onRender(LevelRenderer* renderer) {
    if (!isEnabled() || waypoints.empty() || !renderer) return;

    for (const auto& wp : waypoints) {
        renderer->drawTracerLine(wp.position, wp.color);
        renderer->drawWorldText(wp.position, wp.name, wp.color);
    }
}

void WaypointManager::addWaypoint(const std::string& name, const Vec3& pos, Color color) {
    waypoints.push_back({name, pos, false, color});
}

void WaypointManager::clearWaypoints() {
    waypoints.clear();
}
