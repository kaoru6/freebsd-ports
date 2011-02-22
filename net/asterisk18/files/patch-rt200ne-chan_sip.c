*** channels/chan_sip.c.org	2010-10-16 05:12:04.000000000 +0900
--- channels/chan_sip.c	2010-10-24 15:37:04.000000000 +0900
***************
*** 750,755 ****
--- 750,759 ----
   */
  static int can_parse_xml;
  
+ /* RT-200NE HACK */
+ static char global_rt200ne[MAX_RT200NE][20];
+ static int  global_rt200ne_cnt = 0;
+ 
  /*! \name Object counters @{
   *  \bug These counters are not handled in a thread-safe way ast_atomic_fetchadd_int()
   *  should be used to modify these values. */
***************
*** 1359,1364 ****
--- 1363,1369 ----
  static char *sip_show_registry(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a);
  static char *sip_unregister(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a);
  static char *sip_show_settings(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a);
+ static char *sip_show_rt200ne(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a);
  static char *sip_show_mwi(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a);
  static const char *subscription_type2str(enum subscriptiontype subtype) attribute_pure;
  static const struct cfsubscription_types *find_subscription_type(enum subscriptiontype subtype);
***************
*** 17061,17066 ****
--- 17066,17100 ----
  #undef FORMAT
  }
  
+ /*! \brief Show registered RT-200NEs */
+ static char *sip_show_rt200ne(struct ast_cli_entry *e, int cmd, struct ast_cli_args *a)
+ {
+ 	int	tmp_i;
+  
+ 	switch (cmd) {
+          case CLI_INIT:
+                  e->command = "sip show rt200ne";
+                  e->usage =
+                          "Usage: sip show rt200ne\n"
+                          "       List RT-200NE(s) settings.\n";
+                  return NULL;
+          case CLI_GENERATE:
+                  return NULL;
+          }
+  
+        if (a->argc != 3)
+                return CLI_SHOWUSAGE;
+        if (global_rt200ne_cnt == 0){
+                ast_cli(a->fd,"No RT-200NE(s)\n");
+        } else {
+                ast_cli(a->fd,"RT-200NE at ..\n");
+                for (tmp_i=0;tmp_i<global_rt200ne_cnt;tmp_i++){
+                        ast_cli(a->fd, "- %-16.16s\n", global_rt200ne[tmp_i]);
+                }
+        }
+  
+        return CLI_SUCCESS;
+ }
  
  /*! \brief Show subscription type in string format */
  static const char *subscription_type2str(enum subscriptiontype subtype)
***************
*** 18046,18051 ****
--- 18080,18090 ----
  	const char *md5secret;
  	struct sip_auth *auth = NULL;	/* Realm authentication */
  
+ 	/* RT-200NE HACK */
+ 	char tmp_addr[20];
+ 	char tmp_uri[256];
+ 	int tmp_i;
+ 
  	if (!ast_strlen_zero(p->domain))
  		ast_copy_string(uri, p->domain, sizeof(uri));
  	else if (!ast_strlen_zero(p->uri))
***************
*** 18053,18058 ****
--- 18092,18119 ----
  	else
  		snprintf(uri, sizeof(uri), "sip:%s@%s", p->username, ast_sockaddr_stringify_host(&p->sa));
  
+  	/* RT-200NE HACK */
+  	strcpy(tmp_addr, ast_sockaddr_stringify_host(&p->sa));
+  	/* ast_verbose(VERBOSE_PREFIX_3 "inet is  %s \n", tmp_addr); */
+  	for (tmp_i=0;tmp_i<global_rt200ne_cnt;tmp_i++){
+  		if(strcmp(tmp_addr, global_rt200ne[tmp_i]) == 0){
+  			/* ast_verbose(VERBOSE_PREFIX_3 "Peer is RT-200NE\n"); */
+  			if (strcmp(uri, "domain") == 0) {
+  				strncpy(tmp_uri, p->uri, sizeof(tmp_uri));
+  				switch (method) {
+  				case    SIP_REGISTER:
+  					sprintf(uri, "sip:%s",tmp_addr);
+  					break;
+  				default:
+  					*strchr(tmp_uri, '@') = '\0';
+ 					 snprintf(uri, sizeof(uri), "%s@%s",tmp_uri,tmp_addr);
+  					break;
+  				}
+  			}
+  		}
+  	}
+  	/* RT-200NE HACK END */
+ 
  	snprintf(cnonce, sizeof(cnonce), "%08lx", ast_random());
  
   	/* Check if we have separate auth credentials */
***************
*** 26539,26544 ****
--- 26600,26609 ----
  
  	sip_cfg.matchexternaddrlocally = DEFAULT_MATCHEXTERNADDRLOCALLY;
  
+  	/* RT-200NE HACK */
+  	memset(global_rt200ne, 0, sizeof(global_rt200ne));
+  	global_rt200ne_cnt = 0;
+ 
  	/* Copy the default jb config over global_jbconf */
  	memcpy(&global_jbconf, &default_jbconf, sizeof(struct ast_jb_conf));
  
***************
*** 26961,26966 ****
--- 27026,27036 ----
  				default_maxcallbitrate = DEFAULT_MAX_CALL_BITRATE;
  		} else if (!strcasecmp(v->name, "matchexternaddrlocally") || !strcasecmp(v->name, "matchexterniplocally")) {
  			sip_cfg.matchexternaddrlocally = ast_true(v->value);
+  		} else if (!strcasecmp(v->name, "rt200ne")) { /*RT-200NE HACK*/
+  			if (global_rt200ne_cnt < MAX_RT200NE) {
+  				ast_copy_string(global_rt200ne[global_rt200ne_cnt], v->value, sizeof(global_rt200ne));
+  			global_rt200ne_cnt++;
+  			}
  		} else if (!strcasecmp(v->name, "session-timers")) {
  			int i = (int) str2stmode(v->value);
  			if (i < 0) {
***************
*** 28162,28167 ****
--- 28232,28238 ----
  	AST_CLI_DEFINE(sip_show_registry, "List SIP registration status"),
  	AST_CLI_DEFINE(sip_unregister, "Unregister (force expiration) a SIP peer from the registry"),
  	AST_CLI_DEFINE(sip_show_settings, "Show SIP global settings"),
+  	AST_CLI_DEFINE(sip_show_rt200ne, "Show RT-200NE settings"),
  	AST_CLI_DEFINE(sip_show_mwi, "Show MWI subscriptions"),
  	AST_CLI_DEFINE(sip_cli_notify, "Send a notify packet to a SIP peer"),
  	AST_CLI_DEFINE(sip_show_channel, "Show detailed SIP channel info"),




*** channels/sip/include/sip.h.org	2010-09-16 04:22:15.000000000 +0900
--- channels/sip/include/sip.h	2010-10-24 03:31:11.000000000 +0900
***************
*** 98,103 ****
--- 98,106 ----
  
  #define INITIAL_CSEQ              101    /*!< Our initial sip sequence number */
  
+ /* RT-200NE HACK */
+ #define MAX_RT200NE			4	/* Number of RT-200NEs */
+ 
  #define DEFAULT_MAX_SE            1800   /*!< Session-Timer Default Session-Expires period (RFC 4028) */
  #define DEFAULT_MIN_SE            90     /*!< Session-Timer Default Min-SE period (RFC 4028) */
  
