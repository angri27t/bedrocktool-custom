#pragma once
#include <bedrocktools/modules/Module.hpp>
#include <bedrocktools/sdk/actor/LocalPlayer.hpp>

class AutoTotem : public Module {
private:
    int totemItemId = 568;

public:
    AutoTotem();
    void onTick(LocalPlayer* player) override;
};
