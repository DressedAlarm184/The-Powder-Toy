#include "simulation/ElementCommon.h"

static int update(UPDATE_FUNC_ARGS);

void Element::Element_SHDR() {
	Identifier = "DEFAULT_PT_SHDR";
	Name = "SHDR";
	Colour = 0x0d181a_rgb;
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

	Flammable = 7;
	Explosive = 0;
	Meltable = 0;
	Hardness = 2;

	Weight = 40;

	HeatConduct = 35;
	Description = "Shredded rubber. Very interesting element indeed.";

	Properties = TYPE_PART;

	HighTemperature = 443.15;
	HighTemperatureTransition = PT_LAVA;

	Update = &update;
}

static int update(UPDATE_FUNC_ARGS) {
	// clumping code:
	for (auto rx = -2; rx <= 2; rx++) {
		for (auto ry = -2; ry <= 2; ry++) {
			if (rx || ry) {
				auto r = pmap[y+ry][x+rx];
				if (!r) continue;
				if (TYP(r) == PT_SHDR) {
					float cxy = 0.005f;
					parts[i].vx += cxy * rx;
					parts[i].vy += cxy * ry;
				}
			}
		}
	}
	return 0;
}