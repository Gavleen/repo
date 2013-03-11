#include <allegro.h>

void init();
void deinit();

int main() 
	{
         
           
        
	    int audio, working_format, bitcap,stereocap,ratecap;
	  int ofs = 0;
	    int len;
	    int interval;
	  SAMPLE *sample;
	    int foo;
	    int size = 1024*1024;
	    unsigned char *buf;
	    init();
	       show_mouse(screen);
	  bitcap = get_sound_input_cap_bits();
	    if (bitcap == 0) 
	        allegro_message("No Audio input capabilty?");
	    stereocap = get_sound_input_cap_stereo();
	  if (stereocap == 0) 
	    allegro_message("No Sterecordingreo ");
	    ratecap = get_sound_input_cap_rate(bitcap, 0);
	    working_format = get_sound_input_cap_parm(ratecap, bitcap, 0);
	    if (working_format == 0) 
	        allegro_message("We Are not a go!"); 
	    else if (working_format == 1) 
	    allegro_message("We Are a go but can't record and playback at the same time!");
	    else if (working_format == 2) 
	    allegro_message("We Are a go!");
	    BITMAP *catli=NULL,*catmo=NULL,*catmc=NULL;
	    catli=load_bitmap("listen.bmp",NULL);
	    catmo=load_bitmap("mo.bmp",NULL);
	    catmc=load_bitmap("mc.bmp",NULL);
	  
	    sample = create_sample(bitcap, 0, ratecap, size);
	    buf=(unsigned char*)(sample->data);

	    allegro_message("Start Recording");
	    len = start_sound_input(ratecap, 16, 0);
	     masked_blit(catli,screen,0,0,200,50,500,500);
	    
	    interval = 1000 / ((len / 2) / ratecap);
	    
	    interval *= 9;
	    interval /= 10;
 	  
	    
	   
	    while (!keypressed() && ofs < size) 
	    {
	        foo = read_sound_input(buf);        
	        if (foo > 0) 
	        {
	            ofs += len;
	            buf += len;
	        }
	        rest(interval);
	    }
	 if (keypressed()) 
	    {
	        foo = read_sound_input(buf);        
	        if (foo > 0) 
	        {
	            ofs += len;
	            buf += len;
	        }
	    }
	    
	   
       	    stop_sound_input();
	     BITMAP *bit=NULL,*bit2=NULL;
	    bit=load_bitmap("play.bmp",NULL);
	   masked_blit(bit,screen,0,0,100,100,400,400);
bit2=load_bitmap("pause.bmp",NULL);
	   masked_blit(bit2,screen,0,0,100,200,400,400);
	audio= allocate_voice(sample);
int u=0;
	  while (!key[KEY_ESC]) {
          	if((mouse_x>=100 && mouse_x<=200)&&(mouse_y>=100 && mouse_y<=200)&& mouse_b&0x1)
	{ play_sample(sample,255,128,1400,0);
         //voice_start(audio);
           while(!((mouse_x>=100 && mouse_x<=200)&&(mouse_y>=200 && mouse_y<=300)&& mouse_b&0x1u<=10)&& u<size)
          { masked_blit(catmo,screen,0,0,200,100,500,500);
            rest(300);
             masked_blit(catmc,screen,0,0,200,100,500,500);
             rest(300);
             u++;
             }
}
    if((mouse_x>=100 && mouse_x<=200)&&(mouse_y>=200 && mouse_y<=300)&& mouse_b&0x1)
	  {
                     voice_stop(audio);
                      masked_blit(catmc,screen,0,0,200,100,500,500);}
    /* put your code here */
	  }
	 
	  deinit();
	  return 0;
	}
END_OF_MAIN()

void init() {
	int depth, res;
	allegro_init();
	depth = desktop_color_depth();
	if (depth == 0) depth = 32;
	set_color_depth(depth);
	res = set_gfx_mode(GFX_AUTODETECT_WINDOWED, 640, 480, 0, 0);
	if (res != 0) {
		allegro_message(allegro_error);
		exit(-1);
	}
 install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT, NULL);
	  install_sound_input(DIGI_AUTODETECT,MIDI_NONE);
	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}
