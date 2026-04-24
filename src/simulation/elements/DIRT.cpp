#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_DIRT() {
	Identifier = "DEFAULT_PT_DIRT";
	Name = "DIRT";
	Colour = 0x8f6d43_rgb;
	MenuVisible = 1;
	MenuSection = SC_POWDERS;
	Enabled = 1;

	Advection = 0.4f;
	AirDrag = 0.04f * CFDS;
	AirLoss = 0.94f;
	Loss = 0.95f;
	Collision = -0.1f;
	Gravity = 0.3f;
	Diffusion = 0.00f;
	HotAir = 0.000f	* CFDS;
	Falldown = 1;

	Flammable = 0;
	Explosive = 0;
	Meltable = 5;
	Hardness = 1;

	Weight = 55;

	HeatConduct = 150;
	Description = "Dirt. Soil. Creates MUD when mixed with WATR.";

	Properties = TYPE_PART;

	HighTemperature = 1835.0f;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS) {
	// transition code:
	for (int rx = -2; rx <= 2; rx++) {
		for (int ry = -2; ry <= 2; ry++) {
			if (rx || ry) {
				auto r = pmap[y + ry][x + rx];
				if (!r) continue;
				if (!sim->rng.chance(1, 10)) continue;
				if (TYP(r) == PT_WATR || TYP(r) == PT_SLTW || TYP(r) == PT_DSTW) {
					sim->part_change_type(i, x, y, PT_MUD);
					sim->kill_part(ID(r));
					return 1;
				}
			}
		}
	}
	return 0;
}
