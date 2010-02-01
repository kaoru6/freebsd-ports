*** apps/app_voicemail.c.org	2009-12-05 02:39:32.000000000 +0900
--- apps/app_voicemail.c	2009-12-27 03:47:42.000000000 +0900
***************
*** 5423,5435 ****
  		return d;
  	}
  
  	static int get_folder2(struct ast_channel *chan, char *fn, int start)
  	{
  		int res = 0;
  		res = ast_play_and_wait(chan, fn);	/* Folder name */
  		while (((res < '0') || (res > '9')) &&
  				(res != '#') && (res >= 0)) {
! 			res = get_folder(chan, 0);
  		}
  		return res;
  	}
--- 5423,5466 ----
  		return d;
  	}
  
+ 	/* Japanese Syntax */
+ 	static int get_folder_ja(struct ast_channel *chan, int start)
+ 	{
+ 		int x;
+ 		int d;
+ 		char fn[256];
+ 		for (x = start; x< 5; x++) {	/* For all folders */
+ 			if ((d = ast_say_number(chan, x, AST_DIGIT_ANY, chan->language, (char *) NULL)))
+ 				return d;
+ 			snprintf(fn, sizeof(fn), "vm-%s", mbox(x));     /* Folder name */
+ 			d = vm_play_folder_name(chan, fn);
+ 			if (d)
+ 				return d;
+ 			d = ast_waitfordigit(chan, 500);
+ 			if (d)
+ 				return d;
+ 		}
+ 		d = ast_play_and_wait(chan, "vm-tocancel"); /* "or pound to cancel" */
+ 		if (d)
+ 			return d;
+ 		d = ast_play_and_wait(chan, "jp-oshitekudasai");
+ 		if (d)
+ 			return d;
+ 		d = ast_waitfordigit(chan, 4000);
+ 		return d;
+ 	}
+ 
  	static int get_folder2(struct ast_channel *chan, char *fn, int start)
  	{
  		int res = 0;
  		res = ast_play_and_wait(chan, fn);	/* Folder name */
  		while (((res < '0') || (res > '9')) &&
  				(res != '#') && (res >= 0)) {
! 			/* res = get_folder(chan, 0); */
! 			if (!strcasecmp(chan->language,"ja"))	/* Japanese syntax */
!  				res = get_folder_ja(chan, 0);
!  			else /* Default syntax */
!  				res = get_folder(chan, 0);
  		}
  		return res;
  	}
***************
*** 5935,5940 ****
--- 5966,5973 ----
  		res = ast_say_date_with_format(chan, t, AST_DIGIT_ANY, chan->language, "'vm-received' q  H 'digits/kai' M ", NULL);
  	} else if (!strncasecmp(chan->language, "it", 2)) {     /* ITALIAN syntax */
  		res = ast_say_date_with_format(chan, t, AST_DIGIT_ANY, chan->language, "'vm-received' q 'digits/at' 'digits/hours' k 'digits/e' M 'digits/minutes'", NULL);
+ 	} else if (!strcasecmp(chan->language, "ja")) {		/* Japanese syntax */
+ 		res = ast_say_date_with_format(chan, t, AST_DIGIT_ANY, chan->language, "PHM q 'jp-ni' 'vm-received'", NULL);
  	} else if (!strncasecmp(chan->language, "nl", 2)) {     /* DUTCH syntax */
  		res = ast_say_date_with_format(chan, t, AST_DIGIT_ANY, chan->language, "'vm-received' q 'digits/nl-om' HM", NULL);
  	} else if (!strncasecmp(chan->language, "no", 2)) {     /* NORWEGIAN syntax */
***************
*** 6519,6524 ****
--- 6552,6601 ----
  	return res;
  }
  
+ /* Japanese syntax */
+ static int vm_intro_ja(struct ast_channel *chan,struct vm_state *vms)
+ {
+       /* Introduce messages they have */
+       int res;
+       res = ast_play_and_wait(chan, "vm-youhave");
+       if (!res) {
+               if (vms->newmessages) {
+                       res = ast_play_and_wait(chan, "vm-INBOX");
+                       if (!res)
+                               res = ast_play_and_wait(chan, "vm-message");
+                       if (!res)
+                               res = ast_play_and_wait(chan, "jp-ga");
+                       if (!res)
+                               res = say_and_wait(chan, vms->newmessages, chan->language);
+                       if (vms->oldmessages && !res)
+                               res = ast_play_and_wait(chan, "vm-and");
+ 
+               }
+               if (!res && vms->oldmessages) {
+                       res = ast_play_and_wait(chan, "vm-Old");
+                       if (!res)
+                               res = ast_play_and_wait(chan, "vm-message");
+                       if (!res)
+                               res = ast_play_and_wait(chan, "jp-ga");
+                       if (!res)
+                               res = say_and_wait(chan, vms->oldmessages, chan->language);
+               }
+               if (!res) {
+                       if (!vms->oldmessages && !vms->newmessages) {
+                               res = ast_play_and_wait(chan, "vm-messages");
+                               if (!res)
+                                       res = ast_play_and_wait(chan, "jp-wa");
+                               if (!res)
+                                       res = ast_play_and_wait(chan, "vm-no");
+                       }
+                       else if (!res) {
+                               res = ast_play_and_wait(chan, "jp-arimasu");
+                       }
+               }
+       }
+       return res;
+ } /* Japanese */
+ 
  /* Version of vm_intro() designed to work for many languages.
   *
   * It is hoped that this function can prevent the proliferation of 
***************
*** 7360,7365 ****
--- 7437,7444 ----
  		return vm_intro_he(chan, vms);
  	} else if (!strncasecmp(chan->language, "it", 2)) {  /* ITALIAN syntax */
  		return vm_intro_it(chan, vms);
+ 	} else if (!strcasecmp(chan->language, "ja")) { /* Japanese syntax */
+ 		return vm_intro_ja(chan, vms);
  	} else if (!strncasecmp(chan->language, "nl", 2)) {  /* DUTCH syntax */
  		return vm_intro_nl(chan, vms);
  	} else if (!strncasecmp(chan->language, "no", 2)) {  /* NORWEGIAN syntax */
