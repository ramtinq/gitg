#include "gitg-revision-panel.h"

G_DEFINE_INTERFACE (GitgRevisionPanel, gitg_revision_panel, G_TYPE_INVALID)

/* Default implementation */
static gchar *
gitg_revision_panel_get_label_default (GitgRevisionPanel *panel)
{
	g_return_val_if_reached (NULL);
}

static GtkWidget *
gitg_revision_panel_get_panel_default (GitgRevisionPanel *panel)
{
	g_return_val_if_reached (NULL);
}

static void
gitg_revision_panel_update_default (GitgRevisionPanel *panel,
                                    GitgRepository    *repository,
                                    GitgRevision      *revision)
{
	/* No default implementation */
}

static void
gitg_revision_panel_default_init (GitgRevisionPanelInterface *iface)
{
	static gboolean initialized = FALSE;

	iface->get_label = gitg_revision_panel_get_label_default;
	iface->get_panel = gitg_revision_panel_get_panel_default;
	iface->update = gitg_revision_panel_update_default;

	if (!initialized)
	{
		initialized = TRUE;
	}
}

gchar *
gitg_revision_panel_get_label (GitgRevisionPanel *panel)
{
	g_return_val_if_fail (GITG_IS_REVISION_PANEL (panel), NULL);

	return GITG_REVISION_PANEL_GET_INTERFACE (panel)->get_label (panel);
}

GtkWidget *
gitg_revision_panel_get_panel (GitgRevisionPanel *panel)
{
	g_return_val_if_fail (GITG_IS_REVISION_PANEL (panel), NULL);

	return GITG_REVISION_PANEL_GET_INTERFACE (panel)->get_panel (panel);
}

void
gitg_revision_panel_update (GitgRevisionPanel *panel,
                            GitgRepository    *repository,
                            GitgRevision      *revision)
{
	g_return_if_fail (GITG_IS_REVISION_PANEL (panel));

	GITG_REVISION_PANEL_GET_INTERFACE (panel)->update (panel,
	                                                  repository,
	                                                  revision);
}
