#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL2_gfx.h>
#include <string>
#include <math.h>
#include <ctime>
#include <string>
#include <sstream>
#include <fstream>
#include <windows.h>
#include <SDL2/SDL_mixer.h>
//Mohammad Ali Sharifi Mehr And Mohammad Amin Eghlimi Fargoush
using namespace std;
struct ajor_info
{
    int R;
    int G;
    int B;
    int tedad;
    int state;
    int level;
    int x;
    int y;
    int strength;
    int vaziat;
};
void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian );
void tup(SDL_Renderer *m_renderer,int xt,int yt,int ball00);
void ajordata(SDL_Renderer *m_renderer,int level,ajor_info a[][5],int xt,int yt);
void saku(SDL_Renderer *m_renderer,int x,int z,int y,int paddle00);
void ajorax(SDL_Renderer *m_renderer,ajor_info a[][5],int level,int s,int brick00);
void menu(SDL_Renderer *m_renderer,int xm,int ym);
void menuo(SDL_Renderer *m_renderer,int xm,int ym);
void backgrounde(SDL_Renderer *m_renderer,int xg,int yg,int background00);
void tnt(SDL_Renderer *m_renderer,ajor_info a[][5],int level,int s);
void puas(SDL_Renderer *m_renderer,int xp,int yp);
void bomb1(SDL_Renderer *m_renderer,int xb,int yb);
void bomb2(SDL_Renderer *m_renderer,int xb,int yb);
void bomb3(SDL_Renderer *m_renderer,int xb,int yb);
void bomb4(SDL_Renderer *m_renderer,int xb,int yb);
void start(SDL_Renderer *m_renderer,int xp,int yp);
void about(SDL_Renderer *m_renderer,int xp,int yp);
void load(SDL_Renderer *m_renderer,int xp,int yp);
void moshak(SDL_Renderer *m_renderer,double xp,double yp);
void showscore(SDL_Renderer *m_renderer,int x,int y,TTF_Font *serif);
void showscore1(SDL_Renderer *m_renderer,int x,int y,int score,TTF_Font *serif);
void showlives(SDL_Renderer *m_renderer,int x,int y,TTF_Font *serif);
void showlives1(SDL_Renderer *m_renderer,int x,int y,int lives,TTF_Font *serif);
void showlevel(SDL_Renderer *m_renderer,int x,int y,TTF_Font *serif);
void showlevel1(SDL_Renderer *m_renderer,int x,int y,int level,TTF_Font *serif);
void jon(SDL_Renderer *m_renderer,int xp,int yp);
void name(SDL_Renderer *m_renderer,int x,int y,TTF_Font *serif,string namee);
void havapeyma(SDL_Renderer *m_renderer,double xp,double yp);
void gameover(SDL_Renderer *m_renderer,int xp,int yp);
void showscore2(SDL_Renderer *m_renderer,int x,int y,int score,TTF_Font *serif);
void showname(SDL_Renderer *m_renderer,int x,int y,TTF_Font *serif,string s);
int main( int argc, char * argv[] )
{
int W = 800;
int L = 1200;
Uint32 SDL_flags = SDL_INIT_VIDEO | SDL_INIT_TIMER ;
Uint32 WND_flags = SDL_WINDOW_SHOWN;
SDL_Window *m_window;
SDL_Renderer *m_renderer;
SDL_Texture* m_img = NULL;
SDL_Texture *mTexture;
int img_w,img_h;
SDL_Rect img_rect;
SDL_Init( SDL_flags );
TTF_Init();
SDL_CreateWindowAndRenderer( L, W, WND_flags, &m_window, &m_renderer );
SDL_RaiseWindow(m_window);
SDL_DisplayMode DM;
SDL_GetCurrentDisplayMode(0, &DM);
SDL_Event *event = new SDL_Event();
SDL_Event *e = new SDL_Event();
SDL_Event *pa = new SDL_Event();
SDL_Event *ab = new SDL_Event();
SDL_Event *st = new SDL_Event();
SDL_Event *lo = new SDL_Event();
SDL_Event *paddle2 = new SDL_Event();
SDL_Event *ex = new SDL_Event();

mTexture = SDL_CreateTexture( m_renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET , W, L );
TTF_Font* arial=TTF_OpenFont("arial.ttf",28);

SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO );
  Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 );
Mix_Music *backgroundmusic1=Mix_LoadMUS("Classic.mp3");
Mix_Music *backgroundmusic2=Mix_LoadMUS("2019-06-07_-_Chill_Gaming_-_David_Fesliyan.mp3");
Mix_Music *backgroundmusic3=Mix_LoadMUS("NaaAshna.mp3");
Mix_Chunk *bombo=Mix_LoadWAV("bomb.wav");
Mix_Chunk *barkhord=Mix_LoadWAV("collide.wav");
Mix_Chunk *shekastan=Mix_LoadWAV("breakBrick.wav");
Mix_Chunk *click=Mix_LoadWAV("mixkit-arcade-retro-changing-tab-206.wav");
Mix_Chunk *loose=Mix_LoadWAV("mixkit-player-losing-or-failing-2042.wav");

    int xt1=100,yt1=100,xt2=500,yt2=100,xt3=900,yt3=100;
    int dx1=20,dy1=20,dx2=20,dy2=20,dy3=20,dx3=20;
    int x1=250;
    int y1=350;
     int q=1;
     int player=1,sath=1,ahang=0;
    ajor_info a[1001][5];
    int level=0;
    int x=550,y=690,z=15;
    int xt=550,yt=650, dxt=-4,dyt=-7,r=20,tupdamage=1;
    int h,j,ul;
    bool quit=false;
   int counter=0;
   int temp;
   int sp=0;
   int hava=0,ghalb=0,xh=-200,yh=350,xg=800,yg=450;
   int paddle00=1,ball00=2,background00=2,brick00=1;
   bool stop=false;
   bool newe=false;
   bool returnmenu=false;
   bool bazi=false;
   bool aboute=false;
   bool starte=false;
   bool loade=false;
   bool exit=false;
   int bomb=0,moshake=0;
   double xmosh=1;
   double ymosh=800;
   int xb,yb;
   int lives=3;
   int na=0,nal=0;
    int broken_bricks=0;
    int score=0;
int font =2;
int x_p=300;
int y_p=500;
int G=0;
int R=0;
int B=0;
int A=0.5;
int x2,y2;
int hi[5]={0,0,0,0,0};
int he,hes;
string s;
string tqd;
string namee;
string file_name;
for(h=0;h<=1000;h++){
        a[h][0].y=20;
        a[h][1].y=20;
        a[h][2].y=20;
        a[h][3].y=20;
        a[h][4].y=20;
    }
    for(h=0;h<=1000;h++){
        for(j=0;j<5;j++){
            a[h][j].vaziat=1;
        }
    }
    srand(time(0));
    for(h=0;h<=1000;h++){
            a[h][0].x=60;
            a[h][1].x=280;
            a[h][2].x=500;
            a[h][3].x=720;
            a[h][4].x=940;
    }
    for(h=0;h<=1000;h++){
        for(j=0;j<5;j++){
            a[h][j].strength=rand()%(h+1)+1;
        }
    }
   while(!newe){
       menu(m_renderer,0,0);
       tup(m_renderer,xt1,yt1,1);
       tup(m_renderer,xt2,yt2,2);
       tup(m_renderer,xt3,yt3,3);
       saku(m_renderer,xt3,0,740,1);
       saku(m_renderer,xt2,0,740,1);
       saku(m_renderer,xt1,0,740,1);
       xt1+=dx1;
       yt1+=dy1;
       xt2+=dx2;
       yt2+=dy2;
       xt3+=dx3;
       yt3+=dy3;
       if(xt1<=0 || xt1>=1160)
        dx1=-dx1;
        if(xt2<=0 || xt2>=1160)
            dx2=-dx2;
        if(xt3<=0 || xt3>=1160)
        dx3=-dx3;
        if(yt1<=0 || yt1>=695)
            dy1=-dy1;
        if(yt2<=0 || yt2>=695)
            dy2=-dy2;
            if(yt3<=0 || yt3>=695)
            dy3=-dy3;
        SDL_RenderPresent( m_renderer );
        event->type=0;
            SDL_PollEvent(event);

       if( event->type ==  SDL_MOUSEBUTTONDOWN )
       {
           if(event->button.button == SDL_BUTTON_LEFT)
           {
               if(event->motion.x>=13&&event->motion.x<=88&&event->motion.y>=95&&event->motion.y<=155){
                Mix_PlayChannel(-1,click,0);
                ahang=1;
               }

               if(event->motion.x>=13&&event->motion.x<=88&&event->motion.y>=173&&event->motion.y<=233){
                    Mix_PlayChannel(-1,click,0);
                    ahang=2;
               }
               if(event->motion.x>=13&&event->motion.x<=88&&event->motion.y>=251&&event->motion.y<=311){
                Mix_PlayChannel(-1,click,0);
                ahang=3;
               }

               if(event->motion.x>=13&&event->motion.x<=88&&event->motion.y>=329&&event->motion.y<=389){
                ahang=0;
                Mix_PlayChannel(-1,click,0);
               }

               if(event->motion.x>=119&&event->motion.x<=194&&event->motion.y>=95&&event->motion.y<=155)
               {sath=3;
               dyt=-20;
               dxt=10;
               Mix_PlayChannel(-1,click,0);
               }
               if(event->motion.x>=119&&event->motion.x<=194&&event->motion.y>=173&&event->motion.y<=233)
                {sath=2;
                dyt=-20;
                dxt=10;
                Mix_PlayChannel(-1,click,0);
                }
               if(event->motion.x>=119&&event->motion.x<=194&&event->motion.y>=251&&event->motion.y<=311){
                Mix_PlayChannel(-1,click,0);
                sath=1;
               }

               if(event->motion.x>=1013&&event->motion.x<=1088&&event->motion.y>=27&&event->motion.y<=127){
                Mix_PlayChannel(-1,click,0);
                player=1;
               }

               if(event->motion.x>=1100&&event->motion.x<=1175&&event->motion.y>=27&&event->motion.y<=127){
                player=2;
                Mix_PlayChannel(-1,click,0);
               }

             if(event->motion.x>=450&&event->motion.x<=750&&event->motion.y>=125&&event->motion.y<=200)
             {  Mix_PlayChannel(-1,click,0);
                 while(!starte)
                 {
                 start(m_renderer,0,0);
                 if(na!=0)name(m_renderer,400,275,arial,namee);
                SDL_RenderPresent( m_renderer );
                while(na!=1){
                 getline(cin,namee);
                 na++;}
                st->type=0;
                          SDL_PollEvent(st);
                       if( st->type ==  SDL_MOUSEBUTTONDOWN )
                       if(st->button.button == SDL_BUTTON_LEFT)
                        if(st->motion.x>=500&&st->motion.x<=700&&st->motion.y>=615&&st->motion.y<=715)
                       {       tqd=namee;
                             s=namee;
                             s+="histor.txt";
                             ifstream in;
                             in.open(s.c_str());
                             if(in.good())
                             {  int big;
                                 for(he=0;he<5;he++)
                                   {
                                    in>>hi[he];
                                 if(hi[he]!=0)
                                 {
                                     cout<<"your score was  "<<hi[he]<<endl;
                                 }
                                 }

                                 in.close();
                             }
                             else{
                                    ofstream out(s.c_str());
                                    for(int he=0;he<5;he++)
                                    out<<hi[he]<<endl;
                                    out.close();
                                }
                           Mix_PlayChannel(-1,click,0);
                           newe=true;
                           starte=true;
                       }
                 }

             }
             if(event->motion.x>=450&&event->motion.x<=750&&event->motion.y>=243&&event->motion.y<=318)
             {  Mix_PlayChannel(-1,click,0);
                 while(!loade)
                 {
                     load(m_renderer,0,0);
                    SDL_RenderPresent( m_renderer );
                    while(nal!=1){
                 getline(cin,file_name);
                 nal++;}
                    lo->type=0;
                          SDL_PollEvent(lo);
                       if( lo->type ==  SDL_MOUSEBUTTONDOWN )
                       if(lo->button.button == SDL_BUTTON_LEFT)
                       {    Mix_PlayChannel(-1,click,0);
                           if(lo->motion.x>=525&&lo->motion.x<=675&&lo->motion.y>=642&&lo->motion.y<=742)
                           {
                            int pq=0;
                            file_name+=".txt";
                            ifstream in;
                            in.open(file_name.c_str());
                            if(in.good())
                            {
                            in>>level;
                            in>>score;
                            in>>lives;
                            for(int le=0;le<=level;le++)
                            {
                                a[le][0].y+=(level-pq)*70;
                                for(int aj=0;aj<5;aj++){
                                in>>a[le][aj].vaziat;
                                }
                                pq++;
                            }
                    in.close();
                    newe=true;
                    loade=true;
                            }
                            else cout<<"oh bro your name was not found";
                           }
                           if(lo->motion.x>=20&&lo->motion.x<=120&&lo->motion.y>=20&&lo->motion.y<=90){
                            Mix_PlayChannel(-1,click,0);
                            loade=true;
                           }


                       }


                 }
                 loade=false;
             }
               if(event->motion.x>=450&&event->motion.x<=750&&event->motion.y>=600&&event->motion.y<=675)
               {    Mix_PlayChannel(-1,click,0);
                   bazi=true;
                   newe=true;
               }
               if(event->motion.x>=450&&event->motion.x<=750&&event->motion.y>=479&&event->motion.y<=554)
               {    Mix_PlayChannel(-1,click,0);
                   while(!aboute)
                   {
                       about(m_renderer,0,0);
                    SDL_RenderPresent( m_renderer );
                             ab->type=0;
                          SDL_PollEvent(ab);
                       if( ab->type ==  SDL_MOUSEBUTTONDOWN )
                       if(ab->button.button == SDL_BUTTON_LEFT)
                        if(ab->motion.x>=550&&ab->motion.x<=650&&ab->motion.y>=689&&ab->motion.y<=789){
                            Mix_PlayChannel(-1,click,0);
                            aboute=true;
                        }

                   }
                   aboute=false;
               }
               if(event->motion.x>=450&&event->motion.x<=750&&event->motion.y>=360&&event->motion.y<=435)
               {    Mix_PlayChannel(-1,click,0);
                   while(!returnmenu){
                menuo(m_renderer,0,0);
                SDL_RenderPresent( m_renderer );
                 e->type=0;
            SDL_PollEvent(e);
                if( e->type ==  SDL_MOUSEBUTTONDOWN )
                {
                    if(e->button.button == SDL_BUTTON_LEFT)
                    {   Mix_PlayChannel(-1,click,0);
                     if(e->motion.x>=440&&e->motion.x<=510&&e->motion.y>=370&&e->motion.y<=440){
                        ball00=1;
                        Mix_PlayChannel(-1,click,0);
                     }
                     else if(e->motion.x>=560&&e->motion.x<=630&&e->motion.y>=370&&e->motion.y<=440){
                        ball00=2;
                        Mix_PlayChannel(-1,click,0);
                     }
                     else if(e->motion.x>=680&&e->motion.x<=760&&e->motion.y>=370&&e->motion.y<=440){
                        ball00=3;
                        Mix_PlayChannel(-1,click,0);
                     }
                     if(e->motion.x>=467&&e->motion.x<=778&&e->motion.y>=146&&e->motion.y<=270){
                        background00=1;
                        Mix_PlayChannel(-1,click,0);
                     }
                     else if(e->motion.x>=147&&e->motion.x<=395&&e->motion.y>=146&&e->motion.y<=270){
                        background00=2;
                        Mix_PlayChannel(-1,click,0);
                     }
                      else if(e->motion.x>=866&&e->motion.x<=1065&&e->motion.y>=146&&e->motion.y<=270){
                        background00=3;
                        Mix_PlayChannel(-1,click,0);
                      }
                      if(e->motion.x>=370&&e->motion.x<=470&&e->motion.y>=410&&e->motion.y<=450){
                        paddle00=1;
                        Mix_PlayChannel(-1,click,0);
                      }
                      //else if(e->motion.x>=530&&e->motion.x<=630&&e->motion.y>=410&&e->motion.y<=450) paddle00=2;
                      if(e->motion.x>=332&&e->motion.x<=466&&e->motion.y>=675&&e->motion.y<=777){
                        brick00=1;
                        Mix_PlayChannel(-1,click,0);
                      }
                      else if(e->motion.x>=502&&e->motion.x<=691&&e->motion.y>=709&&e->motion.y<=777){
                        brick00=2;
                        Mix_PlayChannel(-1,click,0);
                      }
                      else if(e->motion.x>=727&&e->motion.x<=829&&e->motion.y>=675&&e->motion.y<=777){
                        brick00=3;
                        Mix_PlayChannel(-1,click,0);
                      }
                      if(e->motion.x>=25&&e->motion.x<=175&&e->motion.y>=26&&e->motion.y<=76){
                        returnmenu=true;
                        Mix_PlayChannel(-1,click,0);
                      }
                    }
                }
                }
                returnmenu=false;
               }
           }
       }
   }
   if(ahang>0){
        if(ahang==1){
            Mix_PlayMusic(backgroundmusic1,-1);
        }
        else if(ahang==2){
            Mix_PlayMusic(backgroundmusic2,-1);
        }
        else if(ahang==3){
            Mix_PlayMusic(backgroundmusic3,-1);
        }
    }

  backgrounde(m_renderer,0,0,background00);
        saku(m_renderer,x,z,y,paddle00);
                tup(m_renderer,xt,yt,ball00);
        SDL_RenderPresent( m_renderer );
   while(!bazi)
    while(!quit){
            if(player==2)
            {
    if(event->type == SDL_MOUSEMOTION)
            {
            x2=event->motion.x;
            }
            }
            event->type=0;
            SDL_PollEvent(event);
                 if( event->type == SDL_KEYDOWN ){
                        switch( event->key.keysym.sym ){

                            case SDLK_d:
                                x+=z;
                                if(x>1080){
                                    x=1080;
                                }
                                if(counter==0){
                                    xt+=z;
                                    if(xt>1120){
                                        xt=1120;
                                    }
                                }
                                break;
                            case SDLK_a:
                                x-=z;
                                if(x<0){
                                    x=0;
                                }
                                if(counter==0){
                                    xt-=z;
                                    if(xt<40){
                                        xt=40;
                                    }
                                }
                                break;
                            case SDLK_f:
                                     counter=1;
                                break;
                            case SDLK_m:
                                moshake=1;
                                break;
                               case SDLK_h:
                                hava=1;
                                break;
                                case SDLK_s:
                                    Mix_PlayChannel(-1,click,0);
                                    while(!stop)
                                    {
                            backgrounde(m_renderer,0,0,background00);
                                        saku(m_renderer,x,z,y,paddle00);
                                        tup(m_renderer,xt,yt,ball00);
                                        for(int u=0;u<=level;u++){
                                        for(int h=0;h<5;h++){
                                        if(a[u][h].vaziat==1){
                                        ajorax(m_renderer,a,u,h,brick00);
                                        puas(m_renderer,0,0);
                    }
                }
       }
      SDL_RenderPresent( m_renderer );

                  pa->type=0;
            SDL_PollEvent(pa);
      if( pa->type == SDL_MOUSEBUTTONDOWN)
      {
          if(pa->button.button == SDL_BUTTON_LEFT)
          {
              if(pa->motion.x>=450&&pa->motion.x<=750&&pa->motion.y>=153&&pa->motion.y<=228){
                stop=true;
              }
              else if(pa->motion.x>=450&&pa->motion.x<=750&&pa->motion.y>=286&&pa->motion.y<=361)
                {   namee+=".txt";
                    ofstream out(namee.c_str());
                    out<<level<<endl;
                    out<<score<<endl;
                    out<<lives<<endl;
                    for(int le=0;le<=level;le++)
                    {
                        for(int aj=0;aj<5;aj++)
                    {
                        out<<a[le][aj].vaziat<<endl;
                    }}
                    out.close();
                        bazi=true;
                        quit=true;
                        stop=true;

              }
               else if(pa->motion.x>=450&&pa->motion.x<=750&&pa->motion.y>=419&&pa->motion.y<=494){
                        bazi=true;
                        quit=true;
                        stop=true;

                }
          }

      }

                                    }
                                stop=false;
                                break;

                            case SDLK_ESCAPE:
                                quit=true;
                                break;

                            default:
                                break;
                        }
                }
    if(counter!=0)
                {
                   xt+=dxt;
                   yt+=dyt;
     if(yt<=0){
        dyt=-dyt;
       //PlaySoundA("1612552944113.wav",NULL,SND_FILENAME);
                              Mix_PlayChannel(-1,barkhord,0);

     }
     else if(((xt>=x-40&&xt<=x+120)||(xt>=x2-40&&xt<=x2+120))&&(yt>=650)&&(yt<=690))
     {
        dyt=-dyt;
     // PlaySoundA("1612552944113.wav",NULL,SND_FILENAME);
                            Mix_PlayChannel(-1,barkhord,0);
     }

if(xt>=1160 || xt<=0){
        dxt=-dxt;
//PlaySoundA("1612552944113.wav",NULL,SND_FILENAME);
                       Mix_PlayChannel(-1,barkhord,0);
      }
      if(yt>=800){
            xt=x+50;
            yt=y-45;
            counter=0;
            lives--;
            break;

        }

                }
for(int q=0;q<=level;q++){


                if(a[q][0].vaziat==1){
                     if((yt>=a[q][0].y-40)&&(yt<=a[q][0].y+50)&&(xt<=(a[q][0].x+200))&&(xt>=(a[q][0].x-45))){
                        dyt=-dyt;
                        xt+=dxt;
                        yt+=dyt;

                        //PlaySoundA("1612552944113.wav",NULL,SND_FILENAME);

                        temp=a[q][0].strength;
                        a[q][0].strength-=tupdamage;
                         if(a[q][0].strength>0){
                            Mix_PlayChannel(-1,barkhord,0);
                         }

                        tupdamage-=temp;
                        if(tupdamage<=0){
                            level++;
                            xt=x+40;
                            yt=y-41;
                            counter=0;
                            tupdamage=level*2;
                            for(int u=0;u<level;u++){
                                a[u][0].y+=70;
                            }
                        }
                        if(a[q][0].strength<=0){
                            a[q][0].vaziat=0;
                            Mix_PlayChannel(-1,shekastan,0);
                            broken_bricks++;
                            score+=level*broken_bricks;
                        }
                    }
                }
                 if(a[q][1].vaziat==1){
                     if((yt>=a[q][0].y-40)&&(yt<=a[q][0].y+50)&&(xt<=(a[q][1].x+200))&&(xt>=(a[q][1].x-45))){
                        dyt=-dyt;
                        xt+=dxt;
                        yt+=dyt;
                        //PlaySoundA("1612552944113.wav",NULL,SND_FILENAME);

                        temp=a[q][1].strength;
                        a[q][1].strength-=tupdamage;
                         if(a[q][1].strength>0)
                        Mix_PlayChannel(-1,barkhord,0);
                        tupdamage-=temp;
                        if(tupdamage<=0){
                            level++;
                            xt=x+40;
                            yt=y-41;
                            counter=0;
                            tupdamage=level*2;
                            for(int u=0;u<level;u++){
                                a[u][0].y+=70;
                            }
                        }
                        if(a[q][1].strength<=0){
                            a[q][1].vaziat=0;
                            Mix_PlayChannel(-1,shekastan,0);
                            broken_bricks++;
                            score+=level*broken_bricks;
                        }
                    }
                }
                 if(a[q][2].vaziat==1){
                     if((yt>=a[q][0].y-40)&&(yt<=a[q][0].y+50)&&(xt<=a[q][2].x+200)&&(xt>=a[q][2].x-45)){
                        dyt=-dyt;
                        xt+=dxt;
                        yt+=dyt;
                        //PlaySoundA("1612552944113.wav",NULL,SND_FILENAME);

                        temp=a[q][2].strength;
                        a[q][2].strength-=tupdamage;
                         if(a[q][2].strength>0)
                        Mix_PlayChannel(-1,barkhord,0);
                        tupdamage-=temp;
                        if(tupdamage<=0){
                            level++;
                            xt=x+40;
                            yt=y-41;
                            counter=0;
                            tupdamage=level*2;
                            for(int u=0;u<level;u++){
                                a[u][0].y+=70;
                            }
                        }
                        if(a[q][2].strength<=0){
                            a[q][2].vaziat=0;
                            Mix_PlayChannel(-1,shekastan,0);
                            broken_bricks++;
                            score+=level*broken_bricks;
                             if(q%5==0 && q>4 && sath!=3) bomb=1;
                        }
                    }
                }
                 if(a[q][3].vaziat==1){
                     if((yt>=a[q][0].y-40)&&(yt<=a[q][0].y+50)&&(xt<=a[q][3].x+200)&&(xt>=a[q][3].x-45)){
                        dyt=-dyt;
                        xt+=dxt;
                        yt+=dyt;
                        //PlaySoundA("1612552944113.wav",NULL,SND_FILENAME);

                        temp=a[q][3].strength;
                        a[q][3].strength-=tupdamage;
                         if(a[q][3].strength>0)
                        Mix_PlayChannel(-1,barkhord,0);
                        tupdamage-=temp;
                        if(tupdamage<=0){
                            level++;
                            xt=x+40;
                            yt=y-41;
                            counter=0;
                            tupdamage=level*2;
                            for(int u=0;u<level;u++){
                                a[u][0].y+=70;
                            }
                        }
                        if(a[q][3].strength<=0){
                            a[q][3].vaziat=0;
                            Mix_PlayChannel(-1,shekastan,0);
                            broken_bricks++;
                            score+=level*broken_bricks;
                        }
                    }
                }
                 if(a[q][4].vaziat==1){
                     if((yt>=a[q][0].y-40)&&(yt<=a[q][0].y+50)&&(xt<=a[q][4].x+200)&&(xt>=a[q][4].x-45)){
                        dyt=-dyt;
                        xt+=dxt;
                        yt+=dyt;
                       // PlaySoundA("1612552944113.wav",NULL,SND_FILENAME);

                        temp=a[q][4].strength;
                        a[q][4].strength-=tupdamage;
                        if(a[q][4].strength>0)
                        Mix_PlayChannel(-1,barkhord,0);
                        tupdamage-=temp;
                        if(tupdamage<=0){
                            level++;
                            xt=x+40;
                            yt=y-41;
                            counter=0;
                            tupdamage=level*2;
                            for(int u=0;u<level;u++){
                                a[u][0].y+=70;
                            }
                        }
                        if(a[q][4].strength<=0){
                            a[q][4].vaziat=0;
                            Mix_PlayChannel(-1,shekastan,0);
                            broken_bricks++;
                            score+=level*broken_bricks;
                        }
                        }
                }
           // }
      }
 backgrounde(m_renderer,0,0,background00);
         saku(m_renderer,x,z,y,paddle00);
        if(player==2) saku(m_renderer,x2,690,690,paddle00);
        tup(m_renderer,xt,yt,ball00);
       for(int u=0;u<=level;u++){
            for(int h=0;h<5;h++){
                    if(a[u][h].vaziat==1){
                            ajorax(m_renderer,a,u,h,brick00);
                            if(u%5==0 && u>4 && h==2 && sath!=3)
                            {
                                tnt(m_renderer,a,u,h);
                                xb=a[u][h].x;
                                yb=a[u][h].y;
                                ul=u;
                            }
                    }
                }
       }
       if(moshake==1)
       {
           ymosh=800-0.000007*(xmosh-1)*(xmosh-1)*(xmosh-1)-2;
           moshak(m_renderer,xmosh,ymosh);
           xmosh+=1;
           if(xmosh>470)
           {
                       bomb1(m_renderer,500,250);
    SDL_Delay(250);
        SDL_RenderPresent( m_renderer );
          bomb2(m_renderer,500,250);
          SDL_Delay(250);
          SDL_RenderPresent( m_renderer );
         Mix_PlayChannel(-1,bombo,0);
          bomb3(m_renderer,500,250);
        SDL_Delay(250);
        SDL_RenderPresent( m_renderer );
          bomb4(m_renderer,500,250);
            SDL_Delay(250);
                SDL_RenderPresent( m_renderer );
                moshake=0;
                ymosh=0;
                for(int u=0;u<=level;u++){
            for(int uu=0;uu<5;uu++){
                a[u][uu].vaziat=0;
            }
        }
        level++;
        xmosh=1;
           }
       }
       if(hava==1)
       {
           havapeyma(m_renderer,xh,yh);
           xh+=5;
           if(xh>=800 && yg<=630)
           {
               jon(m_renderer,xg,yg);
               yg+=5;
               if(((xg>=x-40&&xt<=x+120)||(xg>=x2-40&&xg<=x2+120))&&(yg<=630)&&(yg>625))
                  lives++;
           }
       }
       if(xh>=1200)
       {
           hava=0;
           xg=600;
           yg=450;
           xh=-200;
       }
    showscore(m_renderer,700,740,arial);
    showscore1(m_renderer,760,740,score,arial);
    showlevel(m_renderer,900,740,arial);
    showlevel1(m_renderer,960,740,level,arial);
    showlives1(m_renderer,1290,740,lives,arial);
    jon(m_renderer,1060,740);
    showlives1(m_renderer,1120,740,lives,arial);
    showname(m_renderer,10,740,arial,tqd);
     SDL_RenderPresent( m_renderer );


      //SDL_SetRenderTarget( m_renderer, NULL );
             if(bomb==1)
       {
          bomb1(m_renderer,xb,yb);
    SDL_Delay(250);
        SDL_RenderPresent( m_renderer );
          bomb2(m_renderer,xb,yb);
          SDL_Delay(250);
          SDL_RenderPresent( m_renderer );
         Mix_PlayChannel(-1,bombo,0);
          bomb3(m_renderer,xb,yb);
        SDL_Delay(250);
        SDL_RenderPresent( m_renderer );
          bomb4(m_renderer,xb,yb);
            SDL_Delay(250);
                SDL_RenderPresent( m_renderer );
                bomb=0;
                a[ul][1].vaziat=0;
                a[ul][3].vaziat=0;
                a[ul-1][1].vaziat=0;
                a[ul-1][2].vaziat=0;
                a[ul-1][3].vaziat=0;
                a[ul+1][1].vaziat=0;
                a[ul+1][2].vaziat=0;
                a[ul+1][3].vaziat=0;
       }

       if(lives==0)
       {
           quit=true;
           bazi=true;
           Mix_PlayChannel(-1,loose,0);
       }
       for(int u=0;u<=level;u++){
          for(int uu=0;uu<5;uu++){
            if(a[u][uu].vaziat==1&&a[u][uu].y>=660){
                quit=true;
                bazi=true;
                Mix_PlayChannel(-1,loose,0);
            }
          }
       }
            }
int ba=0;
                          ifstream in;
                            in.open(s.c_str());
                            for(he=0;he<5;he++)
                            {
                                in>>hi[he];
                                if(hi[he]==0)
                                {hi[he]=score;
                                hes=he;
                                ba++;}}
                                if(ba==0)
                                {
                                    hi[4]=hi[3];
                                    hi[3]=hi[2];
                                    hi[2]=hi[1];
                                    hi[1]=hi[0];
                                    hi[0]=score;
                                    hes=0;
                                }


                                for(he=0;he<hes;he++)
                                    hi[he]=0;
                            remove(s.c_str());
                            ofstream out(s.c_str());
                            for(he=0;he<5;he++)
                                out<<hi[he]<<endl;
                            in.close();
                            out.close();
            while(!exit)
            {   tup(m_renderer,xt1,yt1,1);
               tup(m_renderer,xt2,yt2,2);
               tup(m_renderer,xt3,yt3,3);
               saku(m_renderer,xt3,0,740,1);
               saku(m_renderer,xt2,0,740,1);
               saku(m_renderer,xt1,0,740,1);
               xt1+=dx1;
               yt1+=dy1;
               xt2+=dx2;
               yt2+=dy2;
               xt3+=dx3;
               yt3+=dy3;
               if(xt1<=0 || xt1>=1160)
                dx1=-dx1;
                if(xt2<=0 || xt2>=1160)
                    dx2=-dx2;
                if(xt3<=0 || xt3>=1160)
                dx3=-dx3;
                if(yt1<=0 || yt1>=695)
                    dy1=-dy1;
                if(yt2<=0 || yt2>=695)
                    dy2=-dy2;
                    if(yt3<=0 || yt3>=695)
                    dy3=-dy3;
                    SDL_RenderPresent( m_renderer );
                gameover(m_renderer,0,0);
                showscore2(m_renderer,488,269,score,arial);
               // SDL_RenderPresent( m_renderer );
                                  ex->type=0;
            SDL_PollEvent(ex);
      if( ex->type == SDL_MOUSEBUTTONDOWN)
          if(ex->button.button == SDL_BUTTON_LEFT)
            if(ex->motion.x>=488&&ex->motion.x<=688&&ex->motion.y>=577&&ex->motion.y<=677){
                Mix_PlayChannel(-1,click,0);
                exit=true;
            }

            }
    SDL_DestroyWindow( m_window );
    SDL_DestroyRenderer( m_renderer );
  Mix_Quit();
  IMG_Quit();
  SDL_Quit();
    return 0;

}
void saku(SDL_Renderer *m_renderer,int x,int z,int y,int paddle00)
{

    if(paddle00==1)
    {
     SDL_Texture *ball1;
        ball1 = IMG_LoadTexture( m_renderer, "paddle1.png");
        int w1, h1;
        SDL_QueryTexture(ball1, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = x;
        texr1.y = y;
        texr1.w = 120;
        texr1.h = 40;
        SDL_RenderCopy( m_renderer, ball1, NULL, &texr1);
        SDL_DestroyTexture(ball1);
    }
    else if (paddle00==2)
    {
         SDL_Texture *ball1;
        ball1 = IMG_LoadTexture( m_renderer, "paddle2.png");
        int w1, h1;
        SDL_QueryTexture(ball1, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = x;
        texr1.y = y;
        texr1.w = 120;
        texr1.h = 40;
        SDL_RenderCopy( m_renderer, ball1, NULL, &texr1);
        SDL_DestroyTexture(ball1);
    }

}
void tup(SDL_Renderer *m_renderer,int xt,int yt,int ball00)
{
    if(ball00==1)
    {
 SDL_Texture *tupe;
        tupe = IMG_LoadTexture( m_renderer, "ball1.png");
        int w1, h1;
        SDL_QueryTexture(tupe, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xt;
        texr1.y = yt;
        texr1.w = 40;
        texr1.h = 40;
        SDL_RenderCopy( m_renderer, tupe, NULL, &texr1);
        SDL_DestroyTexture(tupe);
    }
    else if(ball00==2)
    {
      SDL_Texture *tupe;
        tupe = IMG_LoadTexture( m_renderer, "ball2.png");
        int w1, h1;
        SDL_QueryTexture(tupe, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xt;
        texr1.y = yt;
        texr1.w = 40;
        texr1.h = 40;
        SDL_RenderCopy( m_renderer, tupe, NULL, &texr1);
        SDL_DestroyTexture(tupe);
    }
   else if(ball00==3)
   {
    SDL_Texture *tupe;
        tupe = IMG_LoadTexture( m_renderer, "ball3.png");
        int w1, h1;
        SDL_QueryTexture(tupe, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xt;
        texr1.y = yt;
        texr1.w = 40;
        texr1.h = 40;
        SDL_RenderCopy( m_renderer, tupe, NULL, &texr1);
        SDL_DestroyTexture(tupe);
   }
}

void rect(SDL_Renderer *Renderer, int x,int y,int w,int h,int R, int G, int B, int fill_boolian )
{
SDL_Rect rectangle ;
rectangle.x = x;
rectangle.y = y;
rectangle.w = w;
rectangle.h = h;
SDL_SetRenderDrawColor(Renderer, R, G, B, 255);
if (fill_boolian==1)
SDL_RenderFillRect(Renderer, &rectangle);
SDL_RenderDrawRect(Renderer, &rectangle);
}
 void ajorax(SDL_Renderer *m_renderer,ajor_info a[][5],int level,int s,int brick00)
 {
     if(brick00==1)
     {
     SDL_Texture *ajora;
        ajora = IMG_LoadTexture( m_renderer, "brick1.jpg");
        int w1, h1;
        SDL_QueryTexture(ajora, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = a[level][s].x;
        texr1.y = a[level][0].y;
        texr1.w = 200;
        texr1.h = 50;
        SDL_RenderCopy( m_renderer, ajora, NULL, &texr1);
        SDL_DestroyTexture(ajora);
     }
     else if(brick00==2)
     {
 SDL_Texture *ajora;
        ajora = IMG_LoadTexture( m_renderer, "brick2.jpg");
        int w1, h1;
        SDL_QueryTexture(ajora, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = a[level][s].x;
        texr1.y = a[level][0].y;
        texr1.w = 200;
        texr1.h = 50;
        SDL_RenderCopy( m_renderer, ajora, NULL, &texr1);
        SDL_DestroyTexture(ajora);
     }
     else if(brick00==3)
     {
         SDL_Texture *ajora;
        ajora = IMG_LoadTexture( m_renderer, "brick3.jpg");
        int w1, h1;
        SDL_QueryTexture(ajora, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = a[level][s].x;
        texr1.y = a[level][0].y;
        texr1.w = 200;
        texr1.h = 50;
        SDL_RenderCopy( m_renderer, ajora, NULL, &texr1);
        SDL_DestroyTexture(ajora);
     }
 }
 void menu(SDL_Renderer *m_renderer,int xm,int ym)
 {
    SDL_Texture *menue;
        menue = IMG_LoadTexture( m_renderer, "mainmenu.png");
        int w1, h1;
        SDL_QueryTexture(menue, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xm;
        texr1.y = ym;
        texr1.w = 1200;
        texr1.h = 800;
        SDL_RenderCopy( m_renderer, menue, NULL, &texr1);
        SDL_DestroyTexture(menue);
 }
void menuo(SDL_Renderer *m_renderer,int xm,int ym)
 {
    SDL_Texture *menueo;
        menueo = IMG_LoadTexture( m_renderer, "settingmenu.png");
        int w1, h1;
        SDL_QueryTexture(menueo, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xm;
        texr1.y = ym;
        texr1.w = 1200;
        texr1.h = 800;
        SDL_RenderCopy( m_renderer, menueo, NULL, &texr1);
                SDL_DestroyTexture(menueo);

 }

void backgrounde(SDL_Renderer *m_renderer,int xg,int yg,int background00)
{
if(background00==1)
{
SDL_Texture *backgroundeo;
        backgroundeo = IMG_LoadTexture( m_renderer, "background1.jpg");
        int w1, h1;
        SDL_QueryTexture(backgroundeo, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xg;
        texr1.y = yg;
        texr1.w = 1200;
        texr1.h = 900;
        SDL_RenderCopy( m_renderer, backgroundeo, NULL, &texr1);
                SDL_DestroyTexture(backgroundeo);
}
else if(background00==2)
{
    SDL_Texture *backgroundeo;
        backgroundeo = IMG_LoadTexture( m_renderer, "background2.jpg");
        int w1, h1;
        SDL_QueryTexture(backgroundeo, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xg;
        texr1.y = yg;
        texr1.w = 1200;
        texr1.h = 900;
        SDL_RenderCopy( m_renderer, backgroundeo, NULL, &texr1);
                SDL_DestroyTexture(backgroundeo);

}
 else if(background00==3)
 {
     SDL_Texture *backgroundeo;
        backgroundeo = IMG_LoadTexture( m_renderer, "background3.jpg");
        int w1, h1;
        SDL_QueryTexture(backgroundeo, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xg;
        texr1.y = yg;
        texr1.w = 1200;
        texr1.h = 900;
        SDL_RenderCopy( m_renderer, backgroundeo, NULL, &texr1);
                SDL_DestroyTexture(backgroundeo);
 }
}

void tnt(SDL_Renderer *m_renderer,ajor_info a[][5],int level,int s)
{
    SDL_Texture *tnte;
        tnte = IMG_LoadTexture( m_renderer, "tnt.jpg");
        int w1, h1;
        SDL_QueryTexture(tnte, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = a[level][s].x+50;
        texr1.y = a[level][0].y;
        texr1.w = 100;
        texr1.h = 50;
        SDL_RenderCopy( m_renderer, tnte, NULL, &texr1);
        SDL_DestroyTexture(tnte);
}
void bomb1(SDL_Renderer *m_renderer,int xb,int yb)
{
    SDL_Texture *tnte;
        tnte = IMG_LoadTexture( m_renderer, "bomb1.png");
        int w1, h1;
        SDL_QueryTexture(tnte, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xb-200;
        texr1.y = yb-200;
        texr1.w = 600;
        texr1.h = 600;
        SDL_RenderCopy( m_renderer, tnte, NULL, &texr1);
        SDL_DestroyTexture(tnte);
}
void bomb2(SDL_Renderer *m_renderer,int xb,int yb)
{
    SDL_Texture *tnte;
        tnte = IMG_LoadTexture( m_renderer, "bomb2.png");
        int w1, h1;
        SDL_QueryTexture(tnte, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xb-200;
        texr1.y = yb-200;
        texr1.w = 600;
        texr1.h = 600;
        SDL_RenderCopy( m_renderer, tnte, NULL, &texr1);
        SDL_DestroyTexture(tnte);
}
void bomb3(SDL_Renderer *m_renderer,int xb,int yb)
{
    SDL_Texture *tnte;
        tnte = IMG_LoadTexture( m_renderer, "bomb3.png");
        int w1, h1;
        SDL_QueryTexture(tnte, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xb-200;
        texr1.y = yb-200;
        texr1.w = 600;
        texr1.h = 600;
        SDL_RenderCopy( m_renderer, tnte, NULL, &texr1);
        SDL_DestroyTexture(tnte);
}
void bomb4(SDL_Renderer *m_renderer,int xb,int yb)
{
    SDL_Texture *tnte;
        tnte = IMG_LoadTexture( m_renderer, "bomb4.png");
        int w1, h1;
        SDL_QueryTexture(tnte, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xb-200;
        texr1.y = yb-200;
        texr1.w = 600;
        texr1.h = 600;
        SDL_RenderCopy( m_renderer, tnte, NULL, &texr1);
        SDL_DestroyTexture(tnte);
}
void puas(SDL_Renderer *m_renderer,int xp,int yp)
{

SDL_Texture *puase;
        puase = IMG_LoadTexture( m_renderer, "pausemenu.png");
        int w1, h1;
        SDL_QueryTexture(puase, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = 1200;
        texr1.h = 800;
        SDL_RenderCopy( m_renderer, puase, NULL, &texr1);
                SDL_DestroyTexture(puase);
}
void start(SDL_Renderer *m_renderer,int xp,int yp)
{

SDL_Texture *puase;
        puase = IMG_LoadTexture( m_renderer, "newgame.png");
        int w1, h1;
        SDL_QueryTexture(puase, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = 1200;
        texr1.h = 800;
        SDL_RenderCopy( m_renderer, puase, NULL, &texr1);
                SDL_DestroyTexture(puase);
}
void moshak(SDL_Renderer *m_renderer,double xp,double yp)
{

SDL_Texture *puase;
        puase = IMG_LoadTexture( m_renderer, "moshak1.png");
        int w1, h1;
        SDL_QueryTexture(puase, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = 100;
        texr1.h = 200;
        SDL_RenderCopy( m_renderer, puase, NULL, &texr1);
                SDL_DestroyTexture(puase);
}
void havapeyma(SDL_Renderer *m_renderer,double xp,double yp)
{

SDL_Texture *puase;
        puase = IMG_LoadTexture( m_renderer, "havapeyma.png");
        int w1, h1;
        SDL_QueryTexture(puase, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = 200;
        texr1.h = 150;
        SDL_RenderCopy( m_renderer, puase, NULL, &texr1);
                SDL_DestroyTexture(puase);
}
void about(SDL_Renderer *m_renderer,int xp,int yp)
{

SDL_Texture *puase;
        puase = IMG_LoadTexture( m_renderer, "aboutusmenu.png");
        int w1, h1;
        SDL_QueryTexture(puase, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = 1200;
        texr1.h = 800;
        SDL_RenderCopy( m_renderer, puase, NULL, &texr1);
                SDL_DestroyTexture(puase);
}
void load(SDL_Renderer *m_renderer,int xp,int yp)
{

SDL_Texture *puase;
        puase = IMG_LoadTexture( m_renderer, "loadmenu.png");
        int w1, h1;
        SDL_QueryTexture(puase, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = 1200;
        texr1.h = 800;
        SDL_RenderCopy( m_renderer, puase, NULL, &texr1);
                SDL_DestroyTexture(puase);
}
void gameover(SDL_Renderer *m_renderer,int xp,int yp)
{

SDL_Texture *puase;
        puase = IMG_LoadTexture( m_renderer, "gameover.png");
        int w1, h1;
        SDL_QueryTexture(puase, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = 1200;
        texr1.h = 800;
        SDL_RenderCopy( m_renderer, puase, NULL, &texr1);
                SDL_DestroyTexture(puase);
}
void jon(SDL_Renderer *m_renderer,int xp,int yp)
{

SDL_Texture *puase;
        puase = IMG_LoadTexture( m_renderer, "lives.png");
        int w1, h1;
        SDL_QueryTexture(puase, NULL, NULL, &w1, &h1);
        SDL_Rect texr1;
        texr1.x = xp;
        texr1.y = yp;
        texr1.w = 60;
        texr1.h = 60;
        SDL_RenderCopy( m_renderer, puase, NULL, &texr1);
                SDL_DestroyTexture(puase);
}
void showscore(SDL_Renderer *m_renderer,int x,int y,TTF_Font *serif){

    char *text2 ="Score : ";
    SDL_Color white={255,0,255,255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(serif,text2,white);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = 60;
    Message_rect.h = 50;
    SDL_RenderCopy(m_renderer,Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}
void showscore1(SDL_Renderer *m_renderer,int x,int y,int score,TTF_Font *serif){


    stringstream s;
    s<<score;
    string scoree;
    s>>scoree;

    SDL_Color white={255,0,255,255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(serif,scoree.c_str(),white);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = 50;
    Message_rect.h = 50;
    SDL_RenderCopy(m_renderer,Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}
void showscore2(SDL_Renderer *m_renderer,int x,int y,int score,TTF_Font *serif)
{


    stringstream s;
    s<<score;
    string scoree;
    s>>scoree;

    SDL_Color white={255,0,255,255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(serif,scoree.c_str(),white);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w =200;
    Message_rect.h =100;
    SDL_RenderCopy(m_renderer,Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}
void showlevel(SDL_Renderer *m_renderer,int x,int y,TTF_Font *serif){

    char *text2 ="Level : ";
    SDL_Color white={255,0,255,255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(serif,text2,white);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = 50;
    Message_rect.h = 50;
    SDL_RenderCopy(m_renderer,Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}
void showlevel1(SDL_Renderer *m_renderer,int x,int y,int level,TTF_Font *serif){


    stringstream l;
    l<<level;
    string levele;
    l>>levele;

    SDL_Color white={255,0,255,255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(serif,levele.c_str(),white);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = 50;
    Message_rect.h = 50;
    SDL_RenderCopy(m_renderer,Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}
void showlives(SDL_Renderer *m_renderer,int x,int y,TTF_Font *serif){

    char *text2 ="lives : ";
    SDL_Color white={255,0,255,255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(serif,text2,white);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = 50;
    Message_rect.h = 50;
    SDL_RenderCopy(m_renderer,Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}
void showlives1(SDL_Renderer *m_renderer,int x,int y,int lives,TTF_Font *serif){


    stringstream li;
    li<<lives;
    string livese;
    li>>livese;
    SDL_Color white={255,0,255,255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(serif,livese.c_str(),white);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = 50;
    Message_rect.h = 50;
    SDL_RenderCopy(m_renderer,Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}
void name(SDL_Renderer *m_renderer,int x,int y,TTF_Font *serif,string namee){

    SDL_Color white={255,0,255,255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(serif,namee.c_str(),white);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = 300;
    Message_rect.h = 100;
    SDL_RenderCopy(m_renderer,Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}
void showname(SDL_Renderer *m_renderer,int x,int y,TTF_Font *serif,string s){

   // char *text2 ="lives : ";
    SDL_Color white={255,0,255,255};
    SDL_Surface* surfaceMessage = TTF_RenderText_Solid(serif,s.c_str(),white);
    SDL_Texture* Message = SDL_CreateTextureFromSurface(m_renderer, surfaceMessage);
    SDL_Rect Message_rect;
    Message_rect.x = x;
    Message_rect.y = y;
    Message_rect.w = 50;
    Message_rect.h = 50;
    SDL_RenderCopy(m_renderer,Message, NULL, &Message_rect);
    SDL_FreeSurface(surfaceMessage);
    SDL_DestroyTexture(Message);
}
