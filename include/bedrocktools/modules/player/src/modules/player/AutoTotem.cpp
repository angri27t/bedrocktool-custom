#include "bedrocktools/modules/player/AutoTotem.hpp"
#include <bedrocktools/sdk/inventory/PlayerInventory.hpp>

AutoTotem::AutoTotem() 
    : Module("AutoTotem", "Otomatis memasang Totem of Undying ke slot offhand", Category::PLAYER) {}

void AutoTotem::onTick(LocalPlayer* player) {
    if (!player || !isEnabled()) return;

    auto inventory = player->getSupplies();
    if (!inventory) return;

    ItemStack* offhandItem = player->getOffhandSlot();

    if (offhandItem && offhandItem->getId() == totemItemId) {
        return;
    }

    for (int slot = 0; slot < 36; ++slot) {
        ItemStack* currentItem = inventory->getItem(slot);

        if (currentItem && currentItem->getId() == totemItemId) {
            inventory->swapSlots(slot, OFFHAND_SLOT_INDEX);
            break;
        }
    }
}
