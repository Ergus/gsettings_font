

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
