#include <iostream>
#include <winbgim.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
using namespace std;

#define MAX 20
#define FUNDAL CYAN
bool gata;
int stanga,sus,width,height,latura, nrLinii, nrColoane;
int i, j,aux;
char TablaDeJoc[MAX][MAX], corect[MAX][MAX], copie[MAX][MAX];;
char linie[11];
char rezolvare[9][10];
FILE* f;
FILE* r;


struct punct
{
    int x, y;
};

struct dreptunghi
{
    punct SS, DJ;
};

bool apartine(punct P, dreptunghi D)
{
    return D.SS.x<=P.x && P.x<=D.DJ.x && D.SS.y<=P.y && P.y<=D.DJ.y;

}

struct buton
{
    dreptunghi D;
    int culoare;
    char text[20];
};

bool verificare()
{
    for (int i=1; i<=2*nrLinii-1; i++)
    {
        for (int j=1; j<=2*nrColoane-1; j++)
        {
            if(TablaDeJoc[i][j]!=corect[i][j])
                return 0;
        }

    }
    return 1;
}
void puneGard()
{
    int linia,coloana,x,y,t=13 ;
    int x1, y1, x2, y2;
    int xmijloc, ymijloc;

    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        x=mousex();
        y=mousey();


        if (x>=stanga+latura && x<=stanga+width+latura && y>=sus+latura && y<=sus+height+latura)
        {
            linia=(y-sus)/latura+1;
            coloana=(x-stanga)/latura+1;
            if (linia %2 ==1 || coloana %2 ==1)
            {
                // stergere
                setcolor(FUNDAL);
                setfillstyle(SOLID_FILL,FUNDAL);

                if(x>=160 && x<=239 && y>=80 && y<=159)
                {
                    x1=160;
                    x2=239;
                    y1=80;
                    y2=159;
                    TablaDeJoc[2][3]='#';

                }
                if(x>=320 && x<=399 && y>=80 && y<=159)
                {
                    x1=320;
                    x2=399;
                    y1=80;
                    y2=159;
                    TablaDeJoc[2][5]='#';

                }
                if(x>=480 && x<=559 && y>=80 && y<=159)
                {
                    x1=480;
                    x2=559;
                    y1=80;
                    y2=159;
                    TablaDeJoc[2][7]='#';

                }
                if(x>=80 && x<=159 && y>=160 && y<=239)
                {
                    x1=80;
                    x2=159;
                    y1=160;
                    y2=239;
                    TablaDeJoc[3][2]='#';

                }
                if(x>=160 && x<=239 && y>=160 && y<=239)
                {
                    x1=160;
                    x2=239;
                    y1=160;
                    y2=239;
                    TablaDeJoc[3][3]='#';
                }
                if(x>=240 && x<=319 && y>=160 && y<=239)
                {
                    x1=240;
                    x2=319;
                    y1=160;
                    y2=239;
                    TablaDeJoc[3][4]='#';
                }
                if(x>=320 && x<=399 && y>=160 && y<=239)
                {
                    x1=320;
                    x2=399;
                    y1=160;
                    y2=239;
                    TablaDeJoc[3][5]='#';
                }
                if(x>=400 && x<=479 && y>=160 && y<=239)
                {
                    x1=400;
                    x2=479;
                    y1=160;
                    y2=239;
                    TablaDeJoc[3][6]='#';
                }
                if(x>=480 && x<=559 && y>=160 && y<=239)
                {
                    x1=480;
                    x2=559;
                    y1=160;
                    y2=239;
                    TablaDeJoc[3][7]='#';
                }
                if(x>=560 && x<=639 && y>=160 && y<=239)
                {
                    x1=560;
                    x2=639;
                    y1=160;
                    y2=239;
                    TablaDeJoc[3][8]='#';
                }
                if(x>=160 && x<=239 && y>=240 && y<=319)
                {
                    x1=160;
                    x2=239;
                    y1=240;
                    y2=319;
                    TablaDeJoc[4][3]='#';
                }
                if(x>=320 && x<=399 && y>=240 && y<=319)
                {
                    x1=320;
                    x2=399;
                    y1=240;
                    y2=319;
                    TablaDeJoc[4][5]='#';
                }
                if(x>=480 && x<=559 && y>=240 && y<=319)
                {
                    x1=480;
                    x2=559;
                    y1=240;
                    y2=319;
                    TablaDeJoc[4][7]='#';
                }
                if(x>=80 && x<=159 && y>=320 && y<=399)
                {
                    x1=80;
                    x2=159;
                    y1=320;
                    y2=399;
                    TablaDeJoc[5][2]='#';
                }
                if(x>=160 && x<=239 && y>=320 && y<=399)
                {
                    x1=160;
                    x2=239;
                    y1=320;
                    y2=399;
                    TablaDeJoc[5][3]='#';
                }
                if(x>=240 && x<=319 && y>=320 && y<=399)
                {
                    x1=240;
                    x2=319;
                    y1=320;
                    y2=399;
                    TablaDeJoc[5][4]='#';
                }
                if(x>=320 && x<=399 && y>=320 && y<=399)
                {
                    x1=320;
                    x2=399;
                    y1=320;
                    y2=399;
                    TablaDeJoc[5][5]='#';
                }
                if(x>=400 && x<=479 && y>=320 && y<=399)
                {
                    x1=400;
                    x2=479;
                    y1=320;
                    y2=399;
                    TablaDeJoc[5][6]='#';
                }
                if(x>=480 && x<=559 && y>=320 && y<=399)
                {
                    x1=480;
                    x2=559;
                    y1=320;
                    y2=399;
                    TablaDeJoc[5][7]='#';
                }
                if(x>=560 && x<=639 && y>=320 && y<=399)
                {
                    x1=560;
                    x2=639;
                    y1=320;
                    y2=399;
                    TablaDeJoc[5][8]='#';
                }
                if(x>=160 && x<=239 && y>=400 && y<=479)
                {
                    x1=160;
                    x2=239;
                    y1=400;
                    y2=479;
                    TablaDeJoc[6][3]='#';
                }
                if(x>=320 && x<=399 && y>=400 && y<=479)
                {
                    x1=320;
                    x2=399;
                    y1=400;
                    y2=479;
                    TablaDeJoc[6][5]='#';
                }
                if(x>=480 && x<=559 && y>=400 && y<=479)
                {
                    x1=480;
                    x2=559;
                    y1=400;
                    y2=479;
                    TablaDeJoc[6][7]='#';
                }
                readimagefile("gard.bmp",x1,y1,x2,y2);
                cout<<endl;
            }
        }
        cout<<endl;

        if(verificare())
        {

            exit;
            closegraph();
            initwindow(1535,800,"felicitari");
            readimagefile("levelcomplete.jpg",0,0, 1535, 800);

            // settextstyle(SCRIPT_FONT,HORIZ_DIR,20);
            //outtextxy(x,y,"FELICITARI!");
        }
        else
        {
            for (int i=1; i<=2*nrLinii-1; i++)
            {
                for (int j=1; j<=2*nrColoane-1; j++)
                {
                    if(TablaDeJoc[i][j]=='#' && corect[i][j]=='.')
                    {
                        exit;
                        closegraph();
                        initwindow(1535,800,"ghinion");
                        readimagefile("gameover.jpg",0,0, 1535, 800);
                        //settextstyle(SCRIPT_FONT,HORIZ_DIR,20);
                        //outtextxy(x,y,"Incearca din nou");
                    }
                }

            }
        }



    }


}

void desen()
{
    int i,j;
    char caracter;
    width=720;
    height=400;
    latura=80;
    sus=0;
    stanga=0;
    readimagefile("fundal.jpg",0,0,1535,850);
    for (i=1; i<=2*nrLinii-1; i++)
        for (j=1; j<=2*nrColoane-1; j++)
        {
            rectangle(stanga+latura*(j-1),sus+latura*(i-1),stanga+latura*j,sus+latura*i);
            caracter=TablaDeJoc[i][j];
            switch(caracter)
            {
            case 'v':
                readimagefile("vaca.bmp",stanga+latura*(j-1),sus+latura*(i-1),stanga+latura*j,sus+latura*i);
                break;
            case '#':
                readimagefile("gard.bmp",stanga+latura*(j-1),sus+latura*(i-1),stanga+latura*j,sus+latura*i);
                break;
            case 'o':
                readimagefile("oaie.bmp",stanga+latura*(j-1),sus+latura*(i-1),stanga+latura*j,sus+latura*i);
                break;
            case 'c':
                readimagefile("cal.bmp",stanga+latura*(j-1),sus+latura*(i-1),stanga+latura*j,sus+latura*i);
                break;
            case 'p':
                readimagefile("porc.bmp",stanga+latura*(j-1),sus+latura*(i-1),stanga+latura*j,sus+latura*i);
                break;
            case 'a':
                readimagefile("apa.bmp",stanga+latura*(j-1),sus+latura*(i-1),stanga+latura*j,sus+latura*i);
                break;
            }
        }
}

buton B[61];
int nrButoane=61;

void deseneazaMeniul()
{
    //setcolor(WHITE);
    //rectangle(0,150,getmaxx(),getmaxy());
    readimagefile("fundalnivele.jpg",0,0,1535,800);
    setfillstyle(SOLID_FILL,LIGHTGREEN);
    int i;
    for (i=1; i<=60; i++)
    {
        if(i<15)
        {
            setfillstyle(SOLID_FILL,LIGHTGREEN);
            setbkcolor(LIGHTGREEN);
            B[i].D.SS.x=100*i;
            B[i].D.DJ.x=100*(i+1)-10;
            B[i].D.SS.y=50;
            B[i].D.DJ.y=80;
            switch(i)
            {
            case 1:
                strcpy(B[i].text,"Joc1");
                break;
            case 2:
                strcpy(B[i].text,"Joc2");
                break;
            case 3:
                strcpy(B[i].text,"Joc3");
                break;
            case 4:
                strcpy(B[i].text,"Joc4");
                break;
            case 5:
                strcpy(B[i].text,"Joc5");
                break;
            case 6:
                strcpy(B[i].text,"Joc6");
                break;
            case 7:
                strcpy(B[i].text,"Joc7");
                break;
            case 8:
                strcpy(B[i].text,"Joc8");
                break;
            case 9:
                strcpy(B[i].text,"Joc9");
                break;
            case 10:
                strcpy(B[i].text,"Joc10");
                break;
            case 11:
                strcpy(B[i].text,"Joc11");
                break;
            case 12:
                strcpy(B[i].text,"Joc12");
                break;
            }

        }
        if(i<15 && i>=13)
        {
            setfillstyle(SOLID_FILL,YELLOW);
            setbkcolor(YELLOW);
            B[i].D.SS.x=100*i;
            B[i].D.DJ.x=100*(i+1)-10;
            B[i].D.SS.y=50;
            B[i].D.DJ.y=80;
            switch(i)
            {
            case 13:
                strcpy(B[i].text,"Joc13");
                break;
            case 14:
                strcpy(B[i].text,"Joc14");
                break;
            }
        }
        if(i>=15 && i<25)
        {
            setfillstyle(SOLID_FILL,YELLOW);
            setbkcolor(YELLOW);
            int j;
            j=i-14;
            B[i].D.SS.x=100*(j);
            B[i].D.DJ.x=100*(j+1)-10;
            B[i].D.SS.y=100;
            B[i].D.DJ.y=130;
            switch(i)
            {
            case 15:
                strcpy(B[i].text,"Joc15");
                break;
            case 16:
                strcpy(B[i].text,"Joc16");
                break;
            case 17:
                strcpy(B[i].text,"Joc17");
                break;
            case 18:
                strcpy(B[i].text,"Joc18");
                break;
            case 19:
                strcpy(B[i].text,"Joc19");
                break;
            case 20:
                strcpy(B[i].text,"Joc20");
                break;
            case 21:
                strcpy(B[i].text,"Joc21");
                break;
            case 22:
                strcpy(B[i].text,"Joc22");
                break;
            case 23:
                strcpy(B[i].text,"Joc23");
                break;
            case 24:
                strcpy(B[i].text,"Joc24");
                break;

            }

        }
        if(i>=25 && i<29)
        {
            setfillstyle(SOLID_FILL,LIGHTRED);
            setbkcolor(LIGHTRED);
            int j;
            j=i-14;
            B[i].D.SS.x=100*(j);
            B[i].D.DJ.x=100*(j+1)-10;
            B[i].D.SS.y=100;
            B[i].D.DJ.y=130;
            switch(i)
            {
            case 25:
                strcpy(B[i].text,"Joc25");
                break;
            case 26:
                strcpy(B[i].text,"Joc26");
                break;
            case 27:
                strcpy(B[i].text,"Joc27");
                break;
            case 28:
                strcpy(B[i].text,"Joc28");
                break;

            }

        }
        if(i>=29 && i<37)
        {
            setfillstyle(SOLID_FILL,LIGHTRED);
            setbkcolor(LIGHTRED);
            int j;
            j=i-28;
            cout<<j;
            B[i].D.SS.x=100*(j);
            B[i].D.DJ.x=100*(j+1)-10;
            B[i].D.SS.y=150;
            B[i].D.DJ.y=170;
            switch(i)
            {
            case 29:
                strcpy(B[i].text,"Joc29");
                break;
            case 30:
                strcpy(B[i].text,"Joc30");
                break;
            case 31:
                strcpy(B[i].text,"Joc31");
                break;
            case 32:
                strcpy(B[i].text,"Joc32");
                break;
            case 33:
                strcpy(B[i].text,"Joc33");
                break;
            case 34:
                strcpy(B[i].text,"Joc34");
                break;
            case 35:
                strcpy(B[i].text,"Joc35");
                break;
            case 36:
                strcpy(B[i].text,"Joc36");
                break;
            }
        }
        if(i>=37 && i<43)
        {
            setfillstyle(SOLID_FILL,LIGHTRED);
            setbkcolor(LIGHTRED);
            int j;
            j=i-28;
            cout<<j;
            B[i].D.SS.x=100*(j);
            B[i].D.DJ.x=100*(j+1)-10;
            B[i].D.SS.y=150;
            B[i].D.DJ.y=170;
            switch(i)
            {
            case 37:
                strcpy(B[i].text,"Joc37");
                break;
            case 38:
                strcpy(B[i].text,"Joc38");
                break;
            case 39:
                strcpy(B[i].text,"Joc39");
                break;
            case 40:
                strcpy(B[i].text,"Joc40");
                break;
            case 41:
                strcpy(B[i].text,"Joc41");
                break;
            case 42:
                strcpy(B[i].text,"Joc42");
                break;
            }
        }
        if(i>=43 && i<57)
        {
            setfillstyle(SOLID_FILL,LIGHTMAGENTA);
            setbkcolor(LIGHTMAGENTA);
            int j;
            j=i-42;
            B[i].D.SS.x=100*(j);
            B[i].D.DJ.x=100*(j+1)-10;
            B[i].D.SS.y=190;
            B[i].D.DJ.y=210;
            switch(i)
            {
            case 43:
                strcpy(B[i].text,"Joc43");
                break;
            case 44:
                strcpy(B[i].text,"Joc44");
                break;
            case 45:
                strcpy(B[i].text,"Joc45");
                break;
            case 46:
                strcpy(B[i].text,"Joc46");
                break;
            case 47:
                strcpy(B[i].text,"Joc47");
                break;
            case 48:
                strcpy(B[i].text,"Joc48");
                break;
            case 49:
                strcpy(B[i].text,"Joc49");
                break;
            case 50:
                strcpy(B[i].text,"Joc50");
                break;
            case 51:
                strcpy(B[i].text,"Joc51");
                break;
            case 52:
                strcpy(B[i].text,"Joc52");
                break;
            case 53:
                strcpy(B[i].text,"Joc53");
                break;
            case 54:
                strcpy(B[i].text,"Joc54");
                break;
            case 55:
                strcpy(B[i].text,"Joc55");
                break;
            case 56:
                strcpy(B[i].text,"Joc56");
                break;

            }

        }
        if(i>=57 && i<61)
        {
            setfillstyle(SOLID_FILL,LIGHTMAGENTA);
            setbkcolor(LIGHTMAGENTA);
            int j;
            j=i-56;
            B[i].D.SS.x=100*(j);
            B[i].D.DJ.x=100*(j+1)-10;
            B[i].D.SS.y=230;
            B[i].D.DJ.y=250;
            switch(i)
            {
            case 57:
                strcpy(B[i].text,"Joc57");
                break;
            case 58:
                strcpy(B[i].text,"Joc58");
                break;
            case 59:
                strcpy(B[i].text,"Joc59");
                break;
            case 60:
                strcpy(B[i].text,"Joc60");
                break;
            }

        }
        rectangle(B[i].D.SS.x, B[i].D.SS.y,B[i].D.DJ.x,B[i].D.DJ.y);
        bar(B[i].D.SS.x, B[i].D.SS.y+30, B[i].D.DJ.x, B[i].D.SS.y);
        outtextxy(B[i].D.SS.x+25,B[i].D.SS.y+10,B[i].text);
    }
}

int butonAles()
{
    int i;
    punct p;
    if (ismouseclick(WM_LBUTTONDOWN))
    {
        clearmouseclick(WM_LBUTTONDOWN);
        p.x=mousex();
        p.y=mousey();
        for (i=1; i<=nrButoane; i++)
            if (apartine(p,B[i].D))
            {
                if(i<61)
                {
                    initwindow(1535,900);
                    if(i==1)
                    {
                        f=fopen("nivel1.txt","r");
                        r=fopen("rezolvare1.txt","r");
                    }
                    if(i==2)
                    {
                        f=fopen("nivel2.txt","r");
                        r=fopen("rezolvare2.txt","r");
                    }
                    if(i==3)
                    {
                        f=fopen("nivel3.txt","r");
                        r=fopen("rezolvare3.txt","r");
                    }
                    if(i==4)
                    {
                        f=fopen("nivel4.txt","r");
                        r=fopen("rezolvare4.txt","r");
                    }
                    if(i==5)
                    {
                        f=fopen("nivel5.txt","r");
                        r=fopen("rezolvare5.txt","r");
                    }
                    if(i==6)
                    {
                        f=fopen("nivel6.txt","r");
                        r=fopen("rezolvare6.txt","r");
                    }
                    if(i==7)
                    {
                        f=fopen("nivel7.txt","r");
                        r=fopen("rezolvare7.txt","r");
                    }
                    if(i==8)
                    {
                        f=fopen("nivel8.txt","r");
                        r=fopen("rezolvare8.txt","r");
                    }
                    if(i==9)
                    {
                        f=fopen("nivel9.txt","r");
                        r=fopen("rezolvare9.txt","r");
                    }
                    if(i==10)
                    {
                        f=fopen("nivel10.txt","r");
                        r=fopen("rezolvare10.txt","r");
                    }
                    if(i==11)
                    {
                        f=fopen("nivel11.txt","r");
                        r=fopen("rezolvare11.txt","r");
                    }
                    if(i==12)
                    {
                        f=fopen("nivel12.txt","r");
                        r=fopen("rezolvare12.txt","r");
                    }
                    if(i==13)
                    {
                        f=fopen("nivel13.txt","r");
                        r=fopen("rezolvare13.txt","r");
                    }
                    if(i==14)
                    {
                        f=fopen("nivel14.txt","r");
                        r=fopen("rezolvare14.txt","r");
                    }
                    if(i==15)
                    {
                        f=fopen("nivel15.txt","r");
                        r=fopen("rezolvare15.txt","r");
                    }
                    if(i==16)
                    {
                        f=fopen("nivel16.txt","r");
                        r=fopen("rezolvare16.txt","r");
                    }
                    if(i==17)
                    {
                        f=fopen("nivel17.txt","r");
                        r=fopen("rezolvare17.txt","r");
                    }
                    if(i==18)
                    {
                        f=fopen("nivel18.txt","r");
                        r=fopen("rezolvare18.txt","r");
                    }
                    if(i==19)
                    {
                        f=fopen("nivel19.txt","r");
                        r=fopen("rezolvare19.txt","r");
                    }
                    if(i==20)
                    {
                        f=fopen("nivel20.txt","r");
                        r=fopen("rezolvare20.txt","r");
                    }
                    if(i==21)
                    {
                        f=fopen("nivel21.txt","r");
                        r=fopen("rezolvare21.txt","r");
                    }
                    if(i==22)
                    {
                        f=fopen("nivel22.txt","r");
                        r=fopen("rezolvare22.txt","r");
                    }
                    if(i==23)
                    {
                        f=fopen("nivel23.txt","r");
                        r=fopen("rezolvare23.txt","r");
                    }
                    if(i==24)
                    {
                        f=fopen("nivel24.txt","r");
                        r=fopen("rezolvare24.txt","r");
                    }
                    if(i==25)
                    {
                        f=fopen("nivel25.txt","r");
                        r=fopen("rezolvare25.txt","r");
                    }
                    if(i==26)
                    {
                        f=fopen("nivel26.txt","r");
                        r=fopen("rezolvare26.txt","r");
                    }
                    if(i==27)
                    {
                        f=fopen("nivel27.txt","r");
                        r=fopen("rezolvare27.txt","r");
                    }
                    if(i==28)
                    {
                        f=fopen("nivel28.txt","r");
                        r=fopen("rezolvare28.txt","r");
                    }
                    if(i==29)
                    {
                        f=fopen("nivel29.txt","r");
                        r=fopen("rezolvare29.txt","r");
                    }
                    if(i==30)
                    {
                        f=fopen("nivel30.txt","r");
                        r=fopen("rezolvare30.txt","r");
                    }
                    if(i==31)
                    {
                        f=fopen("nivel31.txt","r");
                        r=fopen("rezolvare31.txt","r");
                    }
                    if(i==32)
                    {
                        f=fopen("nivel32.txt","r");
                        r=fopen("rezolvare32.txt","r");
                    }
                    if(i==33)
                    {
                        f=fopen("nivel33.txt","r");
                        r=fopen("rezolvare33.txt","r");
                    }
                    if(i==34)
                    {
                        f=fopen("nivel34.txt","r");
                        r=fopen("rezolvare34.txt","r");
                    }
                    if(i==35)
                    {
                        f=fopen("nivel35.txt","r");
                        r=fopen("rezolvare35.txt","r");
                    }
                    if(i==36)
                    {
                        f=fopen("nivel36.txt","r");
                        r=fopen("rezolvare36.txt","r");
                    }
                    if(i==37)
                    {
                        f=fopen("nivel37.txt","r");
                        r=fopen("rezolvare37.txt","r");
                    }
                    if(i==38)
                    {
                        f=fopen("nivel38.txt","r");
                        r=fopen("rezolvare38.txt","r");
                    }
                    if(i==39)
                    {
                        f=fopen("nivel39.txt","r");
                        r=fopen("rezolvare39.txt","r");
                    }
                    if(i==40)
                    {
                        f=fopen("nivel40.txt","r");
                        r=fopen("rezolvare40.txt","r");
                    }
                    if(i==41)
                    {
                        f=fopen("nivel41.txt","r");
                        r=fopen("rezolvare41.txt","r");
                    }
                    if(i==42)
                    {
                        f=fopen("nivel42.txt","r");
                        r=fopen("rezolvare42.txt","r");
                    }
                    if(i==43)
                    {
                        f=fopen("nivel43.txt","r");
                        r=fopen("rezolvare43.txt","r");
                    }
                    if(i==44)
                    {
                        f=fopen("nivel44.txt","r");
                        r=fopen("rezolvare44.txt","r");
                    }
                    if(i==45)
                    {
                        f=fopen("nivel45.txt","r");
                        r=fopen("rezolvare45.txt","r");
                    }
                    if(i==46)
                    {
                        f=fopen("nivel46.txt","r");
                        r=fopen("rezolvare46.txt","r");
                    }
                    if(i==47)
                    {
                        f=fopen("nivel47.txt","r");
                        r=fopen("rezolvare47.txt","r");
                    }
                    if(i==48)
                    {
                        f=fopen("nivel48.txt","r");
                        r=fopen("rezolvare48.txt","r");
                    }
                    if(i==49)
                    {
                        f=fopen("nivel49.txt","r");
                        r=fopen("rezolvare49.txt","r");
                    }
                    if(i==50)
                    {
                        f=fopen("nivel50.txt","r");
                        r=fopen("rezolvare50.txt","r");
                    }
                    if(i==51)
                    {
                        f=fopen("nivel51.txt","r");
                        r=fopen("rezolvare51.txt","r");
                    }
                    if(i==52)
                    {
                        f=fopen("nivel52.txt","r");
                        r=fopen("rezolvare52.txt","r");
                    }
                    if(i==53)
                    {
                        f=fopen("nivel53.txt","r");
                        r=fopen("rezolvare53.txt","r");
                    }
                    if(i==54)
                    {
                        f=fopen("nivel54.txt","r");
                        r=fopen("rezolvare54.txt","r");
                    }
                    if(i==55)
                    {
                        f=fopen("nivel55.txt","r");
                        r=fopen("rezolvare55.txt","r");
                    }
                    if(i==56)
                    {
                        f=fopen("nivel56.txt","r");
                        r=fopen("rezolvare56.txt","r");
                    }
                    if(i==57)
                    {
                        f=fopen("nivel57.txt","r");
                        r=fopen("rezolvare57.txt","r");
                    }
                    if(i==58)
                    {
                        f=fopen("nivel58.txt","r");
                        r=fopen("rezolvare58.txt","r");
                    }
                    if(i==59)
                    {
                        f=fopen("nivel59.txt","r");
                        r=fopen("rezolvare59.txt","r");
                    }
                    if(i==60)
                    {
                        f=fopen("nivel60.txt","r");
                        r=fopen("rezolvare60.txt","r");
                    }

                    fscanf(f, "%d %d",&nrLinii,&nrColoane);
                    char caracter;
                    fscanf(f,"%c",&caracter);
                    for (int i=1; i<=2*nrLinii-1; i++)
                    {
                        for (int j=1; j<=2*nrColoane-1; j++)
                        {
                            fscanf(f,"%c",&caracter);
                            TablaDeJoc[i][j]=caracter;
                            copie[i][j]=caracter;
                            cout<<caracter<<" ";
                        }
                        fscanf(f,"%c",&caracter);
                        cout<<endl;
                    }

                    cout<<endl;
                    fscanf(r, "%d %d",&nrLinii,&nrColoane);

                    fscanf(r,"%c",&caracter);
                    for (int i=1; i<=2*nrLinii-1; i++)
                    {
                        for (int j=1; j<=2*nrColoane-1; j++)
                        {
                            fscanf(r,"%c",&caracter);
                            corect[i][j]=caracter;
                            cout<<caracter<<" ";
                        }
                        fscanf(r,"%c",&caracter);
                        cout<<endl;
                    }
                    cout<<endl;
                    fclose(f);

                    desen();

                    gata=false;

                    do
                    {
                        puneGard();
                    }
                    while (!gata);

                    getch();
                    closegraph();
                    return 0;

                }


            }
        return i;

    }
    return 0;
}
void deseneazaFereastra()
{
    // Initialize graphics window
    int width = 1530, height = 800;
    initwindow(width, height, "SMART FARMER");
    readimagefile("fundalnivele.jpg",0,0, 1535, 800);

    setbkcolor(LIGHTBLUE);
    // Draw the title "SMART FARMER" in the middle of the window
    int titleX = 300, titleY =200;
    settextstyle(BOLD_FONT, HORIZ_DIR, 10);
    outtextxy(titleX, titleY, "SMART FARMER");


    //setfillstyle(SOLID_FILL, GREEN);
    //bar(840, 490, 1080, 590);
    settextstyle(BOLD_FONT, HORIZ_DIR, 7);
    outtextxy(650, 520, "START");

    //bar(1500, 800, 1880, 1040);
    settextstyle(BOLD_FONT, HORIZ_DIR, 5);
    outtextxy(1450, 750, "?");
}
void deseneazaFereastraReguli()
{
    int width = 1535, height = 800;
    initwindow(width, height, "RULES");
    setbkcolor(GREEN);
    readimagefile("image.jpg",0,0, 1535, 800);
    settextstyle(BOLD_FONT, HORIZ_DIR, 7);
    outtextxy(20, 20, "RULES");
    settextstyle(BOLD_FONT, HORIZ_DIR, 4);
    outtextxy(1410, 760, "BACK");
    settextstyle(BOLD_FONT, HORIZ_DIR, 5);
    outtextxy(20, 100, "Regulile jocului SMART FARMER sunt foarte simple.");
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(20, 160, "Animalele nu se inteleg intre ele,");
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(20, 200, "iar tu trebuie sa le separi.");
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(20, 220, "Pune garduri astfel incat porcii sa stea cu porcii,");
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(20, 240, "vacile cu vacile, oile cu oile, caii cu caii.");
    settextstyle(BOLD_FONT, HORIZ_DIR, 6);
    outtextxy(20, 280, "Atentie!!!");
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(20, 340, "Trebuie sa gasesti cea mai avantajoasa varianta de a pune gradurile.");
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(20, 380, "Cand vei avansa vei ajunge la niveluri in care animalele se cearta de la apa.");
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(20, 420, "Trebuie sa separi animalele din nou, dar acum ai grija ca fiecare sa aiba apa.");
    settextstyle(BOLD_FONT, HORIZ_DIR, 3);
    outtextxy(20, 460, "Pentru a pune garduri trebuie doar sa dai un click pe locul unde vrei sa pui gardul.");
    settextstyle(BOLD_FONT, HORIZ_DIR, 7);
    outtextxy(550, 500, "SUCCES!!!");
}
int main()
{
    deseneazaFereastra();

    int clickX1, clickY1;
    while (true)
    {
        if (ismouseclick(WM_LBUTTONDOWN))
        {
            getmouseclick(WM_LBUTTONDOWN, clickX1, clickY1);
            if (clickX1 >= 650 && clickX1 <= 800 && clickY1 >= 520 && clickY1 <= 600)
            {
                closegraph();
                initwindow(1535,800);
                deseneazaMeniul();

                int comanda, butonul_apasat;
                do
                {
                    butonul_apasat=butonAles();
                    if (butonul_apasat!=0)
                    {
                        comanda=butonul_apasat;
                        cout<<"Comanda "<<comanda<<endl;
                    }
                }
                while (comanda!=61);
                closegraph();
            }
            if (clickX1 >= 1450 && clickX1 <= 1500 && clickY1 >= 700 && clickY1 <= 800)
            {
                closegraph();
                deseneazaFereastraReguli();

                int clickX2, clickY2;
                while (true)
                {
                    if (ismouseclick(WM_LBUTTONDOWN))
                    {
                        getmouseclick(WM_LBUTTONDOWN, clickX2, clickY2);
                        if (clickX2 >= 1450 && clickX2 <= 1500 && clickY2 >= 700 && clickY2 <= 800)
                        {
                            closegraph();
                            deseneazaFereastra();
                            break;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
