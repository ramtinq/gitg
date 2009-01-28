#ifndef __GITG_COMMIT_H__
#define __GITG_COMMIT_H__

#include <glib-object.h>

G_BEGIN_DECLS

#define GITG_TYPE_COMMIT			(gitg_commit_get_type ())
#define GITG_COMMIT(obj)			(G_TYPE_CHECK_INSTANCE_CAST ((obj), GITG_TYPE_COMMIT, GitgCommit))
#define GITG_COMMIT_CONST(obj)		(G_TYPE_CHECK_INSTANCE_CAST ((obj), GITG_TYPE_COMMIT, GitgCommit const))
#define GITG_COMMIT_CLASS(klass)	(G_TYPE_CHECK_CLASS_CAST ((klass), GITG_TYPE_COMMIT, GitgCommitClass))
#define GITG_IS_COMMIT(obj)			(G_TYPE_CHECK_INSTANCE_TYPE ((obj), GITG_TYPE_COMMIT))
#define GITG_IS_COMMIT_CLASS(klass)	(G_TYPE_CHECK_CLASS_TYPE ((klass), GITG_TYPE_COMMIT))
#define GITG_COMMIT_GET_CLASS(obj)	(G_TYPE_INSTANCE_GET_CLASS ((obj), GITG_TYPE_COMMIT, GitgCommitClass))

typedef struct _GitgCommit			GitgCommit;
typedef struct _GitgCommitClass		GitgCommitClass;
typedef struct _GitgCommitPrivate	GitgCommitPrivate;

typedef struct _GitgChangedFile		GitgChangedFile;

enum GitgChangedFileStatus
{
	GITG_CHANGED_FILE_STATUS_NEW,
	GITG_CHANGED_FILE_STATUS_MODIFIED,
	GITG_CHANGED_FILE_STATUS_DELETED	
};

struct _GitgChangedFile {
	GFile *file;
	guint status;
	gboolean deleted;
	gboolean cached_changes;
	gboolean unstanged_changes;
	gchar *commit_blob_sha;
	gchar *commit_blob_mode;
};

struct _GitgCommit {
	GObject parent;
  
	GitgCommitPrivate *priv;
};

struct _GitgCommitClass {
	GObjectClass parent_class;
};

GType gitg_commit_get_type(void) G_GNUC_CONST;
GitgCommit *gitg_commit_new(GitgRepository *repository);

void gitg_commit_refresh(GitgCommit *commit);
void gitg_commit_stage(GitgCommit *commit);
void gitg_commit_unstage(GitgCommit *commit);

G_END_DECLS

#endif /* __GITG_COMMIT_H__ */
