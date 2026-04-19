#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_MUD() {
	Identifier = "DEFAULT_PT_MUD";
	Name = "MUD";
	Colour = 0x4a3703_rgb;
	MenuVisible = 1;
	MenuSection = SC_POWDERS;
	Enabled = 1;

	Advection = 0.7f;
	AirDrag = 0.02f * CFDS;
	AirLoss = 0.94f;
	Loss = 0.95f;
	Collision = 0.0f;
	Gravity = 0.2f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 1;

	Flammable = 0;
	Explosive = 0;
	Meltable = 0;
	Hardness = 2;

	Weight = 55;

	HeatConduct = 70;
	Description = "Mud. Made with DIRT and WATR.";

	Properties = TYPE_PART;

	HighTemperature = 383.15f;
	HighTemperatureTransition = PT_DIRT;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS) {
	// clumping code:
	for (auto rx = -2; rx <= 2; rx++) {
		for (auto ry = -2; ry <= 2; ry++) {
			if (rx || ry) {
				auto r = pmap[y+ry][x+rx];
				if (!r) continue;
				if (TYP(r) == PT_MUD) {
					float cxy = 0.01f;
					parts[i].vx += cxy * rx;
					parts[i].vy += cxy * ry;
				}
			}
		}
	}
	return 0;
}