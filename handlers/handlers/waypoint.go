package handlers

import (
	"fmt"
	"github.com/sandertv/gophertunnel/minecraft/protocol/packet"
)

type WaypointHandler struct {
	DeathPos [3]float32
	HasDeath bool
}

func NewWaypointHandler() *WaypointHandler {
	return &WaypointHandler{}
}

// HandleServerPacket mencegat paket kematian dari server
func (w *WaypointHandler) HandleServerPacket(pk packet.Packet) bool {
	switch p := pk.(type) {
	case *packet.Text:
		// Memantau pesan kematian di obrolan server
		if p.TextType == packet.TextTypeTranslation && p.Message == "death.attack.player" {
			w.HasDeath = true
		}
	}
	return true
}

func (w *WaypointHandler) PrintDeathMarker() string {
	if !w.HasDeath {
		return "Belum ada titik kematian tercatat."
	}
	return fmt.Sprintf("Titik Kematian: X:%.1f Y:%.1f Z:%.1f", w.DeathPos[0], w.DeathPos[1], w.DeathPos[2])
}
