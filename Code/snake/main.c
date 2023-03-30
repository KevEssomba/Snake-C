#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#define FALSE 0
#define TRUE 1
void color(int couleurDuTexte,int couleurDeFond) // fonction d'affichage de couleurs
{
        HANDLE H=GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(H,couleurDeFond*16+couleurDuTexte);
}

void gotoxy(int x, int y)
{
   HANDLE hConsoleOutput;
   COORD dwCursorPosition;
   //cout.flush();
   dwCursorPosition.X = x;
   dwCursorPosition.Y = y;
   hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
   SetConsoleCursorPosition(hConsoleOutput,dwCursorPosition);
}
void snake_menu()
{
    int a;

    for(int i=2;i<40;i++)
    {printf("%c",220);gotoxy(i,9);color(1,1);printf("%c",220);gotoxy(i,8);color(1,1);printf("%c",220);}

     for(int i=40;i<53;i++)
    {printf("%c",220);gotoxy(i,9);color(1,1);printf("%c",220);gotoxy(i,8);color(1,1);printf("%c",220);
    gotoxy(i,7);color(1,1);printf("%c",220);gotoxy(i,6);color(1,1);printf("%c",220);gotoxy(i,5);color(1,1);
    printf("%c",220);gotoxy(i,4);color(1,1);printf("%c",220);}
      for (int i=53;i<58;i++)
      {gotoxy(i,9);printf("%c",220);color(1,1);printf("%c",220);gotoxy(i,8);color(1,1);printf("%c",220);
        gotoxy(i,7);color(1,1);printf("%c",220);
      }
      gotoxy(58,7);color(1,1);printf("%c",220);
    for(int i=51;i<53;i++)
    {gotoxy(i,6);color(6,6);printf("%c",219);gotoxy(i,5);color(6,6);printf("%c",219);}

    for(int i=58;i<70;i++)
    {gotoxy(i,8);color(13,13);printf("%c",219);}

    for(int i=74;i<82;i++)
    {
        gotoxy(i,9);color(1,1);printf("%c",220);gotoxy(i,9);color(13,13);printf("%c",220);gotoxy(i,8);color(13,13);printf("%c",220);
    gotoxy(i,7);color(13,13);printf("%c",220);gotoxy(i,6);color(13,13);printf("%c",220);gotoxy(i,5);
    }
     for(int i=93;i<118;i++)
    {
        gotoxy(i,9);color(1,1);printf("%c",220);gotoxy(i,8);color(1,1);printf("%c",220);
    }
    gotoxy(11,12);color(0,2); printf("S          N            A         K         E");
    gotoxy(66,12);color(0,11);  printf("G         A            M         E");
}
int menu(int x, int y, int c)
{
    snake_menu();
	char m[4][30]={"PLAY SNAKE","HIGH SCORE","INSTRUCTION","QUITTER"};
	int i,k=0,j;
	color (c,0);
	gotoxy(40,22); color(9,0);printf("By Sharon TAKOUDJOU && KEVIN ESSOMBA  Corp");color(0,9);
	do
	{
	for(i=0;i<4;i++)
	{
		if(i==k)
		color(0,12);
		else color(12,0);
		gotoxy(x+2,y+1+i);
		puts(m[i]);
	}
		j=getch();
		if(j==80)
		{
			k++;
			k=k%4;
		}
		else
		if(j==72)
		{
			k--;
		}
		if(k<0)
		{
			k=3;
		}

}
	while(j!=13);
	return k+1;
}
typedef struct
{
    int x,y;
}serp;
/*structure du serpent*/

typedef struct{
     serp corp[200];
     int longueur;
     int score;
}serpent;

/*structure pomme*/

typedef struct{
    int x;
    int y;
}pomme;
void cadre(int x1,int x2,int y1,int y2,int c )
{
    int i;
    color(c,15);
    for(i=x1;i<=x2;i++)
    {
        gotoxy(i,y1);
        printf("%c", 219);
        gotoxy(i,y2);
        printf("%c", 219);
    }
    for(i=y1;i<=y2;i++)
    {
        gotoxy(x1,i);
        printf("%c", 219);
        gotoxy(x2,i);
        printf("%c", 219);
    }
    gotoxy(x1,y1);printf("%c", 219);
    gotoxy(x2,y1);printf("%c", 219);
    gotoxy(x1,y2);printf("%c", 219);
    gotoxy(x2,y2);printf("%c", 219);

}
void remplimur(int x1,int x2,int y1,int y2,int c){
 int i,j;
 color(c,15);
 for(j=y1;j<=y2;j++){
 for(i=x1;i<=x2;i++)
    {
        gotoxy(i,j);
        printf("%c", 219);
 }              }}
void affiche_serpent(serpent s)
{
    int l;
    for(l=0;l<s.longueur;l++)
    {
        gotoxy(s.corp[l].x, s.corp[l].y);
        color(9,15);
        if(l==0)
        printf("%c",177);
        else printf("%c",219);
    }}
    void affiche_pomme(pomme *t,serpent *s)
{
    int i =0;
    time_t v_time;
    time(&v_time);srand(v_time);
    t->x = s->corp[0].x+1;//rand()%70 + 11;
    t->y = s->corp[0].y;//rand()%48 + 6;
    for(i=0;i<s->longueur;i++){
    if(s->corp[i].x == t->x) t->x++;
    if(s->corp[i].y == t->y) t->y++;}
    if(t->x >=70 || t->x <= 11)t->x= 35;
    if(t->y >=48|| t->y <= 6)t->y= 24;
    gotoxy(t->x,t->y);color(12,2);printf("%c",6);

}

void deplacement(serpent *s,pomme *t)
{
    int d,a,c,e,i,k=0,score,j,chx=4,z,level=1;
    int vie=3;
    do
    {    if(s->score<50)
            Sleep(100);
         if((s->score>=50)||(s->score<100))
            Sleep(50);
         if(s->score>=100)
            Sleep(25);
            if(s->corp[s->longueur-1].x%2==0){
                 if(s->corp[s->longueur-1].y%2==0){
                  remplimur(s->corp[s->longueur-1].x,s->corp[s->longueur-1].x,s->corp[s->longueur-1].y,s->corp[s->longueur-1].y,10);}
                else {remplimur(s->corp[s->longueur-1].x,s->corp[s->longueur-1].x,s->corp[s->longueur-1].y,s->corp[s->longueur-1].y,2);}
            }
            else{
                 if(s->corp[s->longueur-1].y%2==0){
                  remplimur(s->corp[s->longueur-1].x,s->corp[s->longueur-1].x,s->corp[s->longueur-1].y,s->corp[s->longueur-1].y,2);}
                 else {remplimur(s->corp[s->longueur-1].x,s->corp[s->longueur-1].x,s->corp[s->longueur-1].y,s->corp[s->longueur-1].y,10);}

            }
            a=chx;
             c= s->corp[0].x;
             e= s->corp[0].y;
            if((chx==1)&&(a!=2))s->corp[0].y--;
            else if((chx==2)&&(a!=1))s->corp[0].y++;
            else if((chx==3)&&(a!=4))s->corp[0].x--;
            else if((chx==4)&&(a!=3))s->corp[0].x++;
            for (j=s->longueur-1;j>=2;j--){
                s->corp[j].x= s->corp[j-1].x;
                s->corp[j].y= s->corp[j-1].y;}
                s->corp[1].x= c;
                s->corp[1].y= e;
            for(i=0;i<s->longueur;i++){
            remplimur(s->corp[i].x,s->corp[i].x,s->corp[i].y,s->corp[i].y,9);
            }
            remplimur(s->corp[0].x,s->corp[0].x,s->corp[0].y,s->corp[0].y,5);
            if(kbhit()!=0)
            {
                d=getch();
                if((d==72)&&(chx!=2)){chx=1;}
                if((d==80)&&(chx!=1)){chx=2;}
                if((d==75)&&(chx!=4)){chx=3;}
                if((d==77)&&(chx!=3)){chx=4;}

            }
            /*test pomme*/
           if((s->corp[0].x==t->x)&&(s->corp[0].y==t->y)){
                    int i =0;
    time_t v_time;
   time(&v_time);srand(v_time);
    t->x = rand()%70 + 11;
    t->y = rand()%48 + 6;
    for(i=0;i<s->longueur;i++){
    if(s->corp[i].x == t->x) t->x++;
    if(s->corp[i].y == t->y) t->y++;}
    if(t->x >=70 || t->x <= 11)t->x= 35;
    if(t->y >=48|| t->y <= 6)t->y= 24;
    gotoxy(t->x,t->y);color(12,2);printf("%c",6);
                    s->longueur++;s->score=s->score+10;}
                    color(15,0);
                    gotoxy(47,2);
                printf("%d",s->score);
                /*test murs*/
           if((s->corp[0].x==11)||(s->corp[0].y==6)||(s->corp[0].x==70)||(s->corp[0].y==48)){
                    vie--;
                    color(0,0);
                 gotoxy(18+2*k,2);
                 printf("%c",219);
                 k++;
                    sleep(1);
                    for(i=0;i<s->longueur;i++){
                       if(s->corp[i].x%2==0){
                 if(s->corp[i].y%2==0){
                  remplimur(s->corp[i].x,s->corp[i].x,s->corp[i].y,s->corp[i].y,10);}
                 else {remplimur(s->corp[i].x,s->corp[i].x,s->corp[i].y,s->corp[i].y,2);}}
                       else{
                 if(s->corp[i].y%2==0){
                  remplimur(s->corp[i].x,s->corp[i].x,s->corp[i].y,s->corp[i].y,2);}
                 else {remplimur(s->corp[i].x,s->corp[i].x,s->corp[i].y,s->corp[i].y,10);}}
                                             }
                     int m=19,b=18,i;
                     for(i=3;i>=0;i--){
                         s->corp[i].x = b+1;
                         b++;
                        s->corp[i].y = m+1;}
                        chx=4;}
                        /*test corps*/
        for(i=1;i<s->longueur;i++){
                 if((s->corp[0].x==s->corp[i].x)&&(s->corp[0].y==s->corp[i].y)){
                 vie--;
                 color(0,0);
                 gotoxy(18+2*k,2);
                 printf("%c",219);
                 k++;
                 sleep(1);
                    for(i=0;i<s->longueur;i++){
                       if(s->corp[i].x%2==0){
                 if(s->corp[i].y%2==0){
                  remplimur(s->corp[i].x,s->corp[i].x,s->corp[i].y,s->corp[i].y,10);}
                 else {remplimur(s->corp[i].x,s->corp[i].x,s->corp[i].y,s->corp[i].y,2);}}
                       else{
                 if(s->corp[i].y%2==0){
                  remplimur(s->corp[i].x,s->corp[i].x,s->corp[i].y,s->corp[i].y,2);}
                 else {remplimur(s->corp[i].x,s->corp[i].x,s->corp[i].y,s->corp[i].y,10);}}
                                             }
                 int m=9,b=18,i;
                 for(i=3;i>=0;i--){
                   s->corp[i].x = b+1;
                   b++;
                     s->corp[i].y = m+1;}
                     chx=4;}

            }
        /*variation niveau*/
        if(s->score==50){
            color(15,0);
            gotoxy(35,2);
            printf("%d",2);}
        if(s->score==100){
            color(15,0);
            gotoxy(35,2);
            printf("%d",3);}
    }while(vie!=0);
}
void replace_high_score(serpent*s){
FILE *f;
int k,t=0;
f=fopen("highscore.pre","r+");
if (f==NULL){
    f=fopen("highscore.pre","a+");
    fwrite(&t,sizeof(t),1,f);
    fclose(f);
}else{
   fread(&k,sizeof(k),1,f);
   if (s->score>k){
    rewind(f);
    fwrite(&s->score,sizeof(s->score),1,f);
   }
   fclose(f);
}


}
void affiche_high_score(){
    FILE *f;int k;
 f=fopen("highscore.pre","r");
    fread(&k,sizeof(k),1,f);
    color(15,0);
    gotoxy(63,2);
printf("%d",k);
fclose(f);
}
 main()
{
    system("mode con: LINES=100 COLS=100");
       /*affichage cadre*/
    int i,a,b;
    FILE *f;int k;
    int x1=55,x2=40,y1=14,y2=25,h=13,t,j,test=0;
    do{
    system("cls");
 system("color 0F");
 t=menu(x1,y1,4);

  switch (t)
  {
  case (1):
      system("cls");
/*affichage cadre*/
 cadre(10,71,5,49,4);
remplimur(11,70,6,48,2);

a=1;
j=6;
i=11;
while(i<=70){
  while(j<=48){
        if(a%2==0){
    remplimur(i,i,j,j,10);}
    j=j+1;
    a++;
   }
j=6;
i=i+1;
}
 pomme p;
serpent s;
s.longueur=4;
s.score=0;
int m;
b=18;
m=9;
for(i=3;i>=0;i--){
    s.corp[i].x = b+1;
    b++;
    s.corp[i].y = m+1;}
    affiche_serpent(s);
cadre(10,71,0,4,2);
remplimur(27,27,0,4,2);
remplimur(39,39,0,4,2);
remplimur(55,55,0,4,2);
color(15,0);
gotoxy(11,2);
printf("LIVES: ");
gotoxy(28,2);
printf("LEVEL: 1");
gotoxy(40,2);
printf("SCORE: ");
gotoxy(57,2);
printf("HIGH: 0");
gotoxy(35,0);
printf("SNAKE ");
gotoxy(41,0);
printf("GAME");
color(12,0);
gotoxy(18,2);
printf("%c %c %c",3,3,3);
affiche_high_score();
affiche_pomme(&p,&s);
deplacement(&s,&p);
replace_high_score(&s);
system("cls");
system("color 0F");
remplimur(20,60,20,40,2);
      color(15,2);
      gotoxy(30,30);
      printf("OUSHH.....");
      sleep(1);
      printf("GAME   ");
      sleep(1);
      printf("OVER");
      gotoxy(30,62);
system("pause");
break;
case (2):
          system("cls");
      remplimur(20,60,20,40,2);
      color(15,2);
      gotoxy(30,30);
      printf("LE MEILEUR SCORE EST:");
      f=fopen("highscore.pre","r");
    fread(&k,sizeof(k),1,f);
    color(15,2);
    gotoxy(40,33);
printf("%d",k);
fclose(f);
gotoxy(30,62);
system("pause");
break;
  case (3):
    system("cls");
    system("color 0F");
    gotoxy(15,6);
    printf("INSTRUCTION");
    gotoxy(15,10);printf("->Les fleches directionelles vous permettent de vous mouvoir dans le cadre");
    gotoxy(15,12);printf("->Vous ne disposez que de 3 vie sinon vous mourez");
    gotoxy(15,14);printf("->Evitez donc de vous mordre la queu ou de rencontrer un mur de la barriere");
    gotoxy(15,16);printf("->Le niveau augmente a chaque fois que votre score croit de 50");
    gotoxy(15,18);printf("->Essayez de faire le meilleur score et gravez votre nom dans l'histoire,AMUSEZ-VOUS BIEN!!!!\n\n\n");
    system("pause");
  break;
    case(4): return 0;
  }
 }while (1);

}
