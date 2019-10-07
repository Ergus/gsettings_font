/*
 * Copyright (C) 2019  Jimmy Aguilar Mena
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <stdio.h>
#include <glib-object.h>
#include <gio/gio.h>

#define GSETTINGS_SCHEMA     "org.gnome.desktop.interface"
#define GSETTINGS_MONO_FONT  "monospace-font-name"
#define GSETTINGS_FONT_NAME  "font-name"


int main(int argc, char *argv[])
{
	GVariant *val;
	const char *current_mono_font;
	const char *current_font;
	GSettings *gsettings_client = g_settings_new (GSETTINGS_SCHEMA);


	val = g_settings_get_value (gsettings_client, GSETTINGS_MONO_FONT);
	if (val) {
		if (g_variant_is_of_type (val, G_VARIANT_TYPE_STRING))
			current_mono_font = g_variant_get_string (val, NULL);
	}

	val = g_settings_get_value (gsettings_client, GSETTINGS_FONT_NAME);
	if (val) {
		if (g_variant_is_of_type (val, G_VARIANT_TYPE_STRING))
			current_font = g_variant_get_string (val, NULL);
	}

	printf ("Mono Font: %s Normal Font: %s\n", current_mono_font, current_font);
	return 0;
}
