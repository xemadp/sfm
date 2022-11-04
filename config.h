/* See LICENSE file for copyright and license details.*/

#ifndef CONFIG_H
#define CONFIG_H

/* colors                      fg,  bg */
static const Cpair cdir    = { 12, 0 };
static const Cpair cfile   = { 15, 0 };
static const Cpair clnk    = { 17, 0 };
static const Cpair cblk    = { 20, 0 };
static const Cpair cchr    = { 21, 0 };
static const Cpair cifo    = { 22, 0 };
static const Cpair csock   = { 23, 0 };
static const Cpair cexec   = { 15, 0 };
static const Cpair cother  = { 25, 0 };

static const Cpair cframe  = { 1 , 0 };
static const Cpair cpanell = { 2 , 0 }; // Left panel top text color
static const Cpair cpanelr = { 2 , 0 }; // Right panel top text color
static const Cpair cerr    = { 0 , 0 };
static const Cpair cprompt = { 12, 0 };
static const Cpair csearch = { 12, 0 };
static const Cpair cstatus = { 12, 0 };

/* commands */
#if defined(__linux__)
#define CHFLAG "chattr"
#else
#define CHFLAG "chflags"
#endif
static const char *rm_cmd[]      = { "rm", "-rf" }; /* delete */
static const char *cp_cmd[]      = { "cp", "-r" }; /* copy */
static const char *chown_cmd[]   = { "chown", "-R" }; /* change file owner and group */
static const char *chmod_cmd[]   = { "chmod" }; /* change file mode bits */
static const char *chflags_cmd[] = { CHFLAG }; /* change file flags */
static const char *mv_cmd[]      = { "mv" }; /* move */
static const char delconf[]      = "yes";

static const size_t rm_cmd_len      = LEN(rm_cmd);
static const size_t cp_cmd_len      = LEN(cp_cmd);
static const size_t chown_cmd_len   = LEN(chown_cmd);
static const size_t chmod_cmd_len   = LEN(chmod_cmd);
static const size_t chflags_cmd_len = LEN(chflags_cmd);
static const size_t mv_cmd_len      = LEN(mv_cmd);
static const size_t delconf_len     = LEN(delconf);

/* bookmarks */
static const char root[]   = "/";
static const char home[]   = "/home/xemadp";
static const char media[]   = "/home/xemadp/Media";
static const char foobar[]   = "/home/xemadp/Media/.Foobar";
static const char torrents[]   = "/home/xemadp/Media/Torrents";
static const char website[]   = "/home/xemadp/Media/Website/";
static const char kntu[]   = "/home/xemadp/Media/KNTUFILES/";

/* first and second pane */
static const char paneone[]   = "/home/xemadp/Media";
static const char panetwo[]   = "/home/xemadp/Media/KNTUFILES/";

/* software */
static const char *mpv[]          = { "mpvs"}; // dwmswallow + mpv
static const char *nsxiv[]         = { "nsxiv.sh" };
static const char *zathura[]        = { "zathuras" };// dwmswallow + zathura
static const char *libreoffice[]  = { "libreoffice" };
static const char *gimp[]         = { "gimp" };
static const char *r2[]           = { "r2", "-c", "vv" };
static const char *browser[]      = { "firefox" };

/* extensions*/
static const char *images[]    = { "bmp", "jpg", "jpeg", "png", "gif", "webp", "xpm" };
static const char *pdf[]       = { "epub", "pdf" };
static const char *arts[]      = { "xcf" };
static const char *obj[]       = { "o", "a", "so" };
static const char *videos[]    = { "avi", "flv", "wav", "webm", "wma", "wmv",
				   "m2v", "m4a", "m4v", "mkv", "mov", "mp3",
				   "mp4", "mpeg", "mpg" };
static const char *documents[] = { "odt", "doc", "docx", "xls", "xlsx", "odp" } ;
static const char *webpage[] = { "html" };

static Rule rules[] = {
	{videos,    LEN(videos),    mpv,         LEN(mpv)         },
	{images,    LEN(images),    nsxiv,       LEN(nsxiv)        },
	{pdf,       LEN(pdf),       zathura,     LEN(zathura)       },
	{documents, LEN(documents), libreoffice, LEN(libreoffice) },
	{arts,      LEN(arts),      gimp,        LEN(gimp)        },
	{obj,       LEN(obj),       r2,          LEN(r2)          },
	{webpage,   LEN(webpage),   browser,     LEN(browser)     },
};

/* normal keys */
static Key nkeys[] = {
	/* keyval                      function      arg */
	{ {.ch = 'j'},                 mv_ver,       {.i = -1}       },
	{ {.key = TB_KEY_ARROW_DOWN},  mv_ver,       {.i = -1}       },
	{ {.ch = 'k'},                 mv_ver,       {.i = +1}       },
	{ {.key = TB_KEY_ARROW_UP},    mv_ver,       {.i = +1}       },
	{ {.key = TB_KEY_CTRL_U},      mv_ver,       {.i = +3}       },
	{ {.key = TB_KEY_CTRL_D},      mv_ver,       {.i = -3}       },
	{ {.ch = 'l'},                 mvfwd,        {.i = 0}        },
	{ {.key = TB_KEY_ARROW_RIGHT}, mvfwd,        {.i = 0}        },
	{ {.ch = 'h'},                 mvbk,         {.i = 0}        },
	{ {.key = TB_KEY_ARROW_LEFT},  mvbk,         {.i = 0}        },
	{ {.ch = 'g'},                 mvtop,        {.i = 0}        },
	{ {.ch = 'G'},                 mvbtm,        {.i = 0}        },
 	{ {.ch = 'o'},                 dragon,       {0}             },
	{ {.ch = 'n'},                 crnf,         {0}             },
	{ {.ch = 'N'},                 crnd,         {0}             },
	{ {.ch = 'd'},                 delent,       {0}             },
	{ {.ch = 'D'},                 dupl,         {0}             },
	{ {.ch = 'x'},                 calcdir,      {0}             },
	{ {.ch = '/'},                 start_filter, {0}             },
	{ {.ch = 'q'},                 quit,         {0}             },
	{ {.ch = 'v'},                 start_vmode,  {0}             },
	{ {.ch = 'y'},                 yank,         {0}             },
	{ {.ch = 'p'},                 paste,        {0}             },
	{ {.ch = 'P'},                 selmv,        {0}             },
	{ {.ch = 'c'},                 start_change, {0}             },
	{ {.ch = 'b'},                 opnsh,        {0}             },
	{ {.key = TB_KEY_SPACE},       switch_pane,  {0}             },
	{ {.key = TB_KEY_CTRL_R},      refresh,      {0}             },
	{ {.ch = '\\'},                bkmrk,        {.v = root}     },
	{ {.ch = 'H'},                 bkmrk,        {.v = home}     },
	{ {.ch = 'f'},                 bkmrk,        {.v = foobar}   },
	{ {.ch = 'm'},                 bkmrk,        {.v = media} },
	{ {.ch = 't'},                 bkmrk,        {.v = torrents} },
	{ {.ch = 'w'},                 bkmrk,        {.v = website} },
	{ {.ch = 'K'},                 bkmrk,        {.v = kntu}     },
	{ {.ch = '.'},                 toggle_df,    {0}             },
};

/* change keys */
static Key ckeys[] = {
	/* keyval                      function         arg */
	{ {.ch = 'w'},                 rname,            {0}            },
	{ {.ch = 'o'},                 chngo,            {0}            },
	{ {.ch = 'm'},                 chngm,            {0}            },
	{ {.ch = 'f'},                 chngf,            {0}            },
	{ {.ch = 'q'},                 exit_change,      {0}            },
	{ {.ch = 'c'},                 exit_change,      {0}            },
	{ {.key = TB_KEY_ESC},         exit_change,      {0}            },
};

/* visual keys */
static Key vkeys[] = {
	/* keyval                      function         arg */
	{ {.ch = 'j'},                 seldwn,          {.i = -1}      },
	{ {.key = TB_KEY_ARROW_DOWN},  seldwn,          {.i = -1}      },
	{ {.ch = 'k'},                 selup,           {.i = +1}      },
	{ {.key = TB_KEY_ARROW_UP},    selup,           {.i = +1}      },
	{ {.ch = 'a'},                 selall,          {0}            },
	{ {.ch = 'y'},                 selynk,          {0}            },
	{ {.ch = 'd'},                 seldel,          {.v = delconf} },
 	{ {.ch = 'o'},                 seldragon,       {0}            },
	{ {.ch = 'q'},                 exit_vmode,      {0}            },
	{ {.ch = 'v'},                 exit_vmode,      {0}            },
	{ {.key = TB_KEY_ESC},         exit_vmode,      {0}            },
};

static const size_t nkeyslen = LEN(nkeys);
static const size_t vkeyslen = LEN(vkeys);
static const size_t ckeyslen = LEN(ckeys);

/* permissions */
static const mode_t ndir_perm = S_IRWXU;
static const mode_t nf_perm   = S_IRUSR | S_IWUSR;

/* dotfiles */
static int show_dotfiles = 1;

/* statusbar */
static const char dtfmt[] = "%F %R"; /* date time format */

/* unicode chars */
#define u_hl  0x2500 /* ─ */
#define u_vl  0x2502 /* │ */
#define u_cnw 0x250C /* ┌ */
#define u_cne 0x2510 /* ┐ */
#define u_csw 0x2514 /* └ */
#define u_cse 0x2518 /* ┘ */
#define u_mn  0x252C /* ┬ */
#define u_ms  0x2534 /* ┴ */

#endif /* CONFIG_H */
