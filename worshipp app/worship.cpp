#include <allegro.h>

void init();
void deinit();

int main() {
	init();
	install_sound(DIGI_AUTODETECT,MIDI_AUTODETECT,0);
	install_mouse();
	show_mouse(screen);
int x,y,j=0,i=0;
 BITMAP *welcome=NULL;
          welcome=load_bitmap("welcome.bmp",NULL);
          masked_blit(welcome,screen,0,0,50,0,500,500);
          rest (2000);
	while (!key[KEY_ESC]) {
          BITMAP *god=NULL;
           BITMAP *aarti=NULL;
           BITMAP *flower=NULL;
           BITMAP *exit1=NULL;
           BITMAP *exit2=NULL;
           flower=load_bitmap("flower.bmp",NULL);
           aarti=load_bitmap("aarti.bmp",NULL);
           exit1=load_bitmap("exit1.bmp",NULL);
           exit2=load_bitmap("exit2.bmp",NULL);
         
          god=load_bitmap("god.bmp",NULL);
          blit(god,screen,0,0,75,0,750,750);
          if((mouse_x<=150 && mouse_x>=0)&&(mouse_y<=500 && mouse_y>=400)&& (mouse_b &0x1))
          {
          for(i=0;i<2;i++)
          {
           for(x=70;x<=450;x=x+10)  
           {
            masked_blit(aarti,screen,0,0,x,200,100,100);  
            rest(50);                      
             blit(god,screen,0,0,75,0,750,750); 
           }      
           for(x=450;x>=70;x=x-10)  
           {
            masked_blit(aarti,screen,0,0,x,200,100,100);
            rest(50);                         
             blit(god,screen,0,0,75,0,750,750); 
           }}                        
          }
          if((mouse_x<=300 && mouse_x>=150)&&(mouse_y<=500 && mouse_y>=400)&& (mouse_b &0x1))
          {
           SAMPLE *bhajan;
           bhajan=load_sample("bhajan.wav");
           play_sample(bhajan,255,127,1000,0);
                         
          }
		
         
         if((mouse_x<=450 && mouse_x>=300)&&(mouse_y<=500 && mouse_y>=400)&& (mouse_b &0x1))
         {
                          for(i=0;i<4;i++)
                          {
          y=50;
          for(x=100;x<=300;x=x+10)
          {
           masked_blit(flower,screen,0,0,x,y,100,100);   
           masked_blit(flower,screen,0,0,600-x,y,100,100);
           masked_blit(flower,screen,0,0,100,50,100,100);
           masked_blit(flower,screen,0,0,500,50,100,100);
           int z=0;
           for(j=0;j<i;j++)
           {
              masked_blit(flower,screen,0,0,300+z,350+z,100,100);  
               z=z+10;            
           }
           y=y+15;
           rest(100);  
           blit(god,screen,0,0,75,0,750,750);                      
          }  }         
         }
          if((mouse_x<=600 && mouse_x>=450)&&(mouse_y<=500 && mouse_y>=400)&& (mouse_b &0x1))
          {
                           for(x=0;x<=350;x++)
          {
           masked_blit(exit1,screen,0,0,x,0,300,700);
           masked_blit(exit2,screen,0,0,500-x,0,300,700);
           rest(1);
           
           }
          
             rest(999999);           
          }
          
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

	install_timer();
	install_keyboard();
	install_mouse();
	/* add other initializations here */
}

void deinit() {
	clear_keybuf();
	/* add other deinitializations here */
}
