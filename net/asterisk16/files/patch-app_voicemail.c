*** apps/app_voicemail.c.org	Tue Aug 11 04:25:03 2009
--- apps/app_voicemail.c	Mon Aug 31 03:28:27 2009
***************
*** 5346,5358 ****
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
--- 5346,5389 ----
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
*** 5871,5876 ****
--- 5902,5909 ----
  			res = ast_say_date_with_format(chan, t, AST_DIGIT_ANY, chan->language, "'vm-received' Ad 'digits/pt-de' B 'digits/pt-de' Y 'digits/pt-as' HM ", NULL);
  		else if (!strncasecmp(chan->language, "zh", 2)) /* CHINESE (Taiwan) syntax */
  			res = ast_say_date_with_format(chan, t, AST_DIGIT_ANY, chan->language, "qR 'vm-received'", NULL);		
+ 		else if (!strcasecmp(chan->language, "ja"))      /* Japanese syntax */
+ 			res = ast_say_date_with_format(chan, t, AST_DIGIT_ANY, chan->language, "PHM q 'jp-ni' 'vm-received'", NULL);		
  		else {
  			res = ast_say_date_with_format(chan, t, AST_DIGIT_ANY, chan->language, "'vm-received' q 'digits/at' IMp", NULL);
  		}
***************
*** 6414,6419 ****
--- 6447,6496 ----
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
*** 7197,7202 ****
--- 7274,7281 ----
  		return vm_intro_zh(chan, vms);
  	} else if (!strcasecmp(chan->language, "ua")) { /* UKRAINIAN syntax */
  		return vm_intro_multilang(chan, vms, "n");
+ 	} else if (!strcasecmp(chan->language, "ja")) { /* Japanese syntax */
+ 		return vm_intro_ja(chan, vms);
  	} else {					/* Default to ENGLISH */
  		return vm_intro_en(chan, vms);
  	}
