#include "simulation/ElementCommon.h"

void Element::Element_RUBR() {
	Identifier = "DEFAULT_PT_RUBR";
	Name = "RUBR";
	Colour = 0x112224_rgb;
	MenuVisible = 1;
	MenuSection = SC_SOLIDS;
	Enabled = 1;

	Falldown = 0;

	Flammable = 3;
	Explosive = 0;
	Meltable = 0;
	Hardness = 2;

	HeatConduct = 20;
	Description = "Rubber. Insulating. Can melt. Tears under pressure.";

	Properties = TYPE_PART;

	HighTemperature = 453.15;
	HighTemperatureTransition = PT_LAVA;

	HighPressure = 64;
	HighPressureTransition = PT_SHDR;
}