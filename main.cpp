#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#include<conio.h>
#include<graphics.h>
char p1[20];
char p2[20];
void setColor(int ForgC)
{
    WORD wColor;

    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
    {
        wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
        SetConsoleTextAttribute(hStdOut, wColor);
    }

    return;
}

void gotoxy(int x, int y)
{
    static HANDLE h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = { x, y };
    SetConsoleCursorPosition(h,c);
}
struct history
{
    char id[20];
    int match_played,match_won;
};
typedef struct history his;
int members;
his data[5000];
int pnum;
char g;
void read()
{

    FILE*fr;
    fr = fopen("players_history.txt","r");
    if(fr==0)
    {
        fr = fopen("players_history.txt","w");

        fprintf(fr,"1\n");
    }
    fscanf(fr,"%d\n",&members);
    ///printf("members : %d\n",members);
    for(int i=0; i<members; i++)
    {
        ///printf("reading\n");
        fscanf(fr,"%s%d%d",data[i].id,&data[i].match_played,&data[i].match_won);
    }
    fclose(fr);
}
void write()
{
    FILE* fr;
    fr = fopen("players_history.txt","w");
    fprintf(fr,"%d\n",members);
    ///printf("members : %d\n",members);
    for(int i=0; i<members; i++)
    {
        fprintf(fr,"%s %d %d\n",data[i].id,data[i].match_played,data[i].match_won);
        /// printf("%s %d %d\n",data[i].id,data[i].match_played,data[i].match_won);
    }
    fclose(fr);
}
void srch()
{
    system("cls");
    int f=0;
    read();
    char name[20];
    printf("Please Enter Your ID : ");
    scanf("%s",name);
    for(int i=0; i<members; i++)
    {
        if(strcmp(name,data[i].id)==0)
        {
            printf("ID : %s  Match played : %d   Match won : %d\n",data[i].id,data[i].match_played,data[i].match_won);
        }
        else
            f++;

    }
    if(f==members)
        printf("Didn't find your id!\n");
    f=0;
    printf("Press any button to continue..");
    _getch();
}
void gk()
{

    FILE*kk = fopen("gk.txt","r");
    if(kk==0)
    {
        kk = fopen("gk.txt","w");
        g = '1';
        fprintf(kk,"%c",g);
    }
    fscanf(kk,"%c",&g);
    fclose(kk);
}
void gkselect()
{
    system("cls");
    printf("1. Animated\n");
    printf("2. E. Martinez\n");
    printf("3. Allison\n");
    printf("Enter Your choice : ");
    for(int i=0; 1; i++)
    {
        scanf(" %c",&g);
        if(g>='1' && g<='3') break;
        else
            printf("Invalid selection... Try again\n");
    }
    FILE*kk = fopen("gk.txt","w");
    fprintf(kk,"%c",g);
    fclose(kk);
    printf("Selected...!\n");
    printf("Press any button to continue..");
    _getch();
}
void pnlty_number ()
{
    system("cls");
    FILE * pp;
    pp = fopen("pnum.txt","r");
    if(pp==0)
    {
        pp = fopen("pnum.txt","w");
    }
    printf("Please enter penalty numbers in each round : ");
    scanf("%d",&pnum);
    pp = fopen("pnum.txt","w");
    fprintf(pp,"%d",pnum);
    fclose(pp);
    printf("DONE...\n");
    printf("Press any button to continue...");
    _getch();
}
void settings()
{
    system("cls");
    int choice;
    printf("1.Search Your Records\n");
    printf("2.Select Gk\n");
    printf("3.Select Penalty numbers\n");
    printf("Enter Your Choice : ",choice);
    scanf("%d",&choice);
    if(choice==1)
    {
        srch();
    }
    else if(choice==2)
    {
        gkselect();
    }
    else if(choice==3)
    {
        pnlty_number();
    }
    printf("Press any button to continue");
    _getch;
}
void DevelopedBy()
{
    system("cls");
    printf("....Developed By....\n\n");
    printf("1.MOHAMMAD TANIM TAHMID-C223130\n\n");
    printf("2.PRASENJIT CHOWDHURY-C231028\n\n");
    printf("3.PARTHA GOSWAMI-C231010\n\n");
    printf("4.SHANJID MOHAMMAD-C231007\n\n");
    printf("Press any button to continue..");
    _getch();
}
int MENU()
{
    system("cls");
    printf("\n_____PENALTY SHOOTOUT_____\n");
    printf("1. Start Game\n");
    printf("2. Settings\n");
    printf("3. Developed By\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    char input[20];
    scanf("%s", input);

    if (strcmp(input, "1") == 0)
    {
        return 1;
    }
    else if (strcmp(input, "2") == 0)
    {
        return 2;
    }
    else if (strcmp(input, "3") == 0)
    {
        return 3;
    }
    else if (strcmp(input, "4") == 0)
    {
        return 4;
    }
    else
    {
        printf("Invalid input. Please try again.\n");
        return -1;
    }
}
void Start_Game()
{
    system("cls");
    int z;
    char input[20];

    printf("Name Of Player 1: ");
    scanf("%s", p1);
    printf("Name Of Player 2: ");
    scanf(" %s", p2);
    int post,post2,post3,post4,post5,e,f,g,h,score1=0,score2=0,player_1,player_2,number;
    ///Sleep(2000);
    initwindow(600,600,"");
    settextstyle(EUROPEAN_FONT,HORIZ_DIR,3);
    outtextxy(100,300,"PRESS ANY KEY TO SEE\n");
    outtextxy(100,400,"THE GOALBAR TARGET\n");
    _getch();
    closegraph();
    initwindow(1900,900,"");
    readimagefile("marked post.jpg",0,0,1600,900);
    Sleep(5000);
    closegraph();
    FILE *pp;
    pp = fopen("pnum.txt","r");
    fscanf(pp,"%d",&number);
    fclose(pp);
    int j;
    FILE * kk;
    kk = fopen("gk.txt","r");
    fscanf(kk,"%d ",&j);
    if(j==1)
    {
        for(int k=0; k<number; k++)
        {
            if(k==0)
            {
                printf("%s : TAKER\n",p1);
                printf("%s : SAVER\n",p2);
            }
            char taker[10],saver[10];
            printf("Penalty took %d times\n",k);

            for(int i=0; 1; i++)
            {
                printf("Enter Your Target : ");
                taker[0] = _getch();
                if(taker[0]<'1'|| taker[0]>'5')
                {
                    printf("Invalid Selection.. Please try again\n");
                    continue;
                }
                else if(taker[0]>='1'&& taker[0]<='5')
                {
                    printf("*\n");
                    break;
                }
            }
            for(int i=0; 1; i++)
            {
                printf("Save The Ball : ");
                saver[0] = _getch();
                if(saver[0]<'1'|| saver[0]>'5')
                {
                    printf("Invalid Selection.. Please try again\n");
                    continue;
                }
                else if(saver[0]>='1'&& saver[0]<='5')
                {
                    printf("*\n");
                    break;
                }
            }
            initwindow(1900,900,"TIE BREAKER");
            ///LEFT CORNER*///

            if(taker[0]=='2')
            {
                for(int i=620,j=540,k=540,m=620; i>=240; i-=10, j-=10,k-=10,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i>300)

                        readimagefile("STANDING GK.jpg",700,300,500,500);
                }
            }

            ///RIGHT CORNER
            if(taker[0]=='4')
            {

                for(int i=800,j=700,k=700,m=800; i<=1300; i+=10, j-=10,k+=10,m-=10)
                {

                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i<1200)
                        readimagefile("STANDING GK.jpg",700,300,500,500);
                }
            }
            /// STRAIGHT UP
            if(taker[0]=='3')
            {
                for(int i=700,j=620,k=620,m=700; j>=200; j-=10,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    ///readimagefile("IMAGES/Football3.jpg",620,540,540,620);
                    if(j>250)
                        readimagefile("STANDING GK.jpg",700,300,500,500);
                }
            }
            ///RIGHT LOW CORNER
            if(taker[0]=='5')
            {
                for(int i=700,j=620,k=620,m=700; i<=1350; i+=20,j-=5,k+=20,m-=5)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i<1250)
                        readimagefile("STANDING GK.jpg",700,300,500,500);
                }
            }
            ///LEFT LOW CORNER
            if(taker[0]=='1')
            {
                for(int i=700,j=620,k=620,m=700; i>=200; i-=20,j-=10,k-=20,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i>220)
                    {

                        readimagefile("STANDING GK.jpg",700,300,500,500);
                    }
                }
            }
            ///left low corner gk
            if(saver[0]=='1')
            {
                readimagefile("LEFT GK.jpg",200,370,450,450);
                ///printf("1\n");
            }
            /// left corner gk
            if(saver[0]=='2')
            {
                readimagefile("LEFT GK.jpg",240,160,160,400);
                ///printf("2\n");
            }
            /// straight up
            if(saver[0]=='3')
            {
                readimagefile("UP GK.jpg",700,200,620,380);
                ///printf("3\n");
            }
            ///right corner
            if(saver[0]=='4')
            {
                readimagefile("RIGHT GK.jpg",1300,200,1500,300);
                ///printf("4\n");
            }
            ///right low corner gk
            if(saver[0]=='5')
            {
                readimagefile("RIGHT GK.jpg",1300,370,1120,500);
                ///printf("5\n");


            }
            Sleep(3000);
            closegraph();
            if(taker[0]==saver[0])
            {
                initwindow(1900,900,"");
                setcolor(YELLOW);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(300,300,"SAVED!!!");
                Sleep(3000);
                closegraph();

            }
            if(taker[0]!=saver[0])
            {
                initwindow(1900,900,"");
                setcolor(YELLOW);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(300,300,"GOAL!!!");
                Sleep(3000);
                closegraph();
                score1++;
            }
        }
        for(int m=0; m<number; m++)
        {
            if(m==0)
            {
                printf("%s : TAKER\n",p2);
                printf("%s : SAVER\n",p1);
            }
            printf("Penalty took %d times\n",m);
            char taker[10],saver[10];
            for(int i=0; 1; i++)
            {
                printf("Enter Your Target : ");
                taker[0] = _getch();
                if(taker[0]<'1'|| taker[0]>'5')
                {
                    printf("Invalid Selection.. Please try again\n");
                    continue;
                }
                else if(taker[0]>='1'&& taker[0]<='5')
                {
                    printf("*\n");
                    break;
                }
            }
            for(int i=0; 1; i++)
            {
                printf("Save The Ball : ");
                saver[0] = _getch();
                if(saver[0]<'1'|| saver[0]>'5')
                {
                    printf("Invalid Selection.. Please try again\n");
                    continue;
                }
                else if(saver[0]>='1'&& saver[0]<='5')
                {
                    printf("*\n");
                    break;
                }
            }

            ///LEFT CORNER*/

            initwindow(1900,900,"TIE BREAKER");


            if(taker[0]=='2')
            {
                for(int i=620,j=540,k=540,m=620; i>=240; i-=10, j-=10,k-=10,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i>300)

                        readimagefile("STANDING GK.jpg",700,300,500,500);
                }
            }

            ///RIGHT CORNER
            if(taker[0]=='4')
            {

                for(int i=800,j=700,k=700,m=800; i<=1300; i+=10, j-=10,k+=10,m-=10)
                {

                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i<1200)
                        readimagefile("STANDING GK.jpg",700,300,500,500);
                }
            }
            /// STRAIGHT UP
            if(taker[0]=='3')
            {
                for(int i=700,j=620,k=620,m=700; j>=200; j-=10,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);

                    if(j>250)
                        readimagefile("STANDING GK.jpg",700,300,500,500);
                }
            }
            ///RIGHT LOW CORNER
            if(taker[0]=='5')
            {
                for(int i=700,j=620,k=620,m=700; i<=1350; i+=20,j-=5,k+=20,m-=5)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i<1250)
                        readimagefile("STANDING GK.jpg",700,300,500,500);
                }
            }
            ///LEFT LOW CORNER
            if(taker[0]=='1')
            {
                for(int i=700,j=620,k=620,m=700; i>=200; i-=20,j-=10,k-=20,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i>220)
                    {

                        readimagefile("STANDING GK.jpg",700,300,500,500);
                    }
                }
            }
            ///left low corner gk
            if(saver[0]=='1')
            {
                readimagefile("LEFT GK.jpg",200,370,450,450);
                ///printf("1\n");
            }
            /// left corner gk
            if(saver[0]=='2')
            {
                readimagefile("LEFT GK.jpg",240,160,160,400);
                ///printf("2\n");
            }
            /// straight up
            if(saver[0]=='3')
            {
                readimagefile("UP GK.jpg",700,200,620,380);
                ///printf("3\n");
            }
            ///right corner
            if(saver[0]=='4')
            {
                readimagefile("RIGHT GK.jpg",1300,200,1500,300);
                ///printf("4\n");
            }
            ///right low corner gk
            if(saver[0]=='5')
            {
                readimagefile("RIGHT GK.jpg",1300,370,1120,500);
                ///printf("5\n");
            }
            Sleep(3000);
            closegraph();
            if(taker[0]==saver[0])
            {
                initwindow(1900,900,"");
                setcolor(YELLOW);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(300,300,"SAVED!!!");
                Sleep(3000);
                closegraph();

            }
            if(taker[0]!=saver[0])
            {
                initwindow(1900,900,"");
                setcolor(YELLOW);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(300,300,"GOAL!!!");
                Sleep(3000);
                closegraph();
                score2++;
            }
        }

        printf("%s  : %d - %d : %s \n",p1,score1,score2,p2);
        if(score1>score2)
        {
            printf("%s WINS\n",p1);
            read();
            int v=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p1,data[i].id)==0)
                {
                    ///printf("q1\n");
                    data[i].match_played++;
                    data[i].match_won++;
                }
                else v++;
            }
            if(v==members)
            {
                strcpy(data[members].id,p1);
                ///printf("%s",data[i].id);
                data[members].match_played = 1;
                data[members].match_won = 1;
                members++;
            }
            int u =0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p2,data[i].id)==0)
                {
                    ///printf("q3\n");
                    data[i].match_played++;
                }
                else u++;
            }
            if(u==members)
            {
                strcpy(data[members].id,p2);
                data[members].match_played = 1;
                data[members].match_won = 0;
                members++;
            }
            write();
        }

        else if(score1<score2)
        {
            printf("%s WINS\n",p2);
            read();
            int v=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p2,data[i].id)==0)
                {
                    ///printf("q5\n");
                    data[i].match_played++;
                    data[i].match_won++;
                }
                else v++;
            }
            if(v==members)
            {
                strcpy(data[members].id,p2);
                data[members].match_played = 1;
                data[members].match_won = 1;
                members++;
            }
            int u=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p1,data[i].id)==0)
                {
                    ///printf("q7\n");
                    data[i].match_played++;
                }
                else u++;
            }
            if(u==members)
            {
                strcpy(data[members].id,p1);
                data[members].match_played = 1;
                data[members].match_won = 0;
                members++;
            }
            write();
        }


        else if(score1==score2)
        {
            printf("MATCH DRAW\n");
            read();
            int v=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p1,data[i].id)==0)
                {
                    ///printf("q9\n");
                    data[i].match_played++;
                }
                else v++;
            }
            if(v==members)
            {
                strcpy(data[members].id,p1);
                data[members].match_played = 1;
                data[members].match_won = 0;
                members++;
            }

            int u=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p2,data[i].id)==0)
                {
                    ///printf("q11\n");
                    data[i].match_played++;
                }
                else u++;
            }
            if(u==members)
            {
                strcpy(data[members].id,p2);
                data[members].match_played = 1;
                data[members].match_won = 0;
                members++;
            }
            write();
        }

        printf("Press any button to continue..\n");
        _getch();
    }
        if(j==2)
    {
        for(int k=0; k<number; k++)
        {
            if(k==0)
            {
                printf("%s : TAKER\n",p1);
                printf("%s : SAVER\n",p2);
            }
            char taker[10],saver[10];
            printf("Penalty took %d times\n",k);

            for(int i=0; 1; i++)
            {
                printf("Enter Your Target : ");
                taker[0] = _getch();
                if(taker[0]<'1'|| taker[0]>'5')
                {
                    printf("Invalid Selection.. Please try again\n");
                    continue;
                }
                else if(taker[0]>='1'&& taker[0]<='5')
                {
                    printf("*\n");
                    break;
                }
            }
            for(int i=0; 1; i++)
            {
                printf("Save The Ball : ");
                saver[0] = _getch();
                if(saver[0]<'1'|| saver[0]>'5')
                {
                    printf("Invalid Selection.. Please try again\n");
                    continue;
                }
                else if(saver[0]>='1'&& saver[0]<='5')
                {
                    printf("*\n");
                    break;
                }
            }
            initwindow(1900,900,"TIE BREAKER");
            ///LEFT CORNER*///

            if(taker[0]=='2')
            {
                for(int i=620,j=540,k=540,m=620; i>=240; i-=10, j-=10,k-=10,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i>300)
                        readimagefile("STANDING MARTINEZ.jpg",700,300,500,500);
                    ///700,300,500,500
                }
            }

            ///RIGHT CORNER
            if(taker[0]=='4')
            {

                for(int i=800,j=700,k=700,m=800; i<=1300; i+=10, j-=10,k+=10,m-=10)
                {

                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i<1200)
                        readimagefile("STANDING MARTINEZ.jpg",700,300,500,500);
                }
            }
            /// STRAIGHT UP
            if(taker[0]=='3')
            {
                for(int i=700,j=620,k=620,m=700; j>=200; j-=10,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    ///readimagefile("IMAGES/Football3.jpg",620,540,540,620);
                    if(j>250)
                        readimagefile("STANDING MARTINEZ.jpg",700,300,500,500);
                }
            }
            ///RIGHT LOW CORNER
            if(taker[0]=='5')
            {
                for(int i=700,j=620,k=620,m=700; i<=1350; i+=20,j-=5,k+=20,m-=5)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i<1250)
                        readimagefile("STANDING MARTINEZ.jpg",700,300,500,500);
                }
            }
            ///LEFT LOW CORNER
            if(taker[0]=='1')
            {
                for(int i=700,j=620,k=620,m=700; i>=200; i-=20,j-=10,k-=20,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i>220)
                    {

                        readimagefile("STANDING MARTINEZ.jpg",700,300,500,500);
                    }
                }
            }
            ///left low corner gk
            if(saver[0]=='1')
            {
                readimagefile("LEFT MARTINEZ.jpg",200,370,450,450);
                ///printf("1\n");
            }
            /// left corner gk
            if(saver[0]=='2')
            {
                readimagefile("LEFT MARTINEZ.jpg",240,160,160,400);
                ///printf("2\n");
            }
            /// straight up
            if(saver[0]=='3')
            {
                readimagefile("UP MARTINEZ.jpg",700,200,620,380);
                ///printf("3\n");
            }
            ///right corner
            if(saver[0]=='4')
            {
                readimagefile("RIGHT MARTINEZ.jpg",1300,200,1500,300);
                ///printf("4\n");
            }
            ///right low corner gk
            if(saver[0]=='5')
            {
                readimagefile("RIGHT MARTINEZ.jpg",1300,370,1120,500);
                ///printf("5\n");


            }
            Sleep(3000);
            closegraph();
            if(taker[0]==saver[0])
            {
                initwindow(1900,900,"");
                setcolor(YELLOW);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(300,300,"SAVED!!!");
                Sleep(3000);
                closegraph();

            }
            if(taker[0]!=saver[0])
            {
                initwindow(1900,900,"");
                setcolor(YELLOW);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(300,300,"GOAL!!!");
                Sleep(3000);
                closegraph();
                score1++;
            }
        }
        for(int m=0; m<number; m++)
        {
            if(m==0)
            {
                printf("%s : TAKER\n",p2);
                printf("%s : SAVER\n",p1);
            }
            printf("Penalty took %d times\n",m);
            char taker[10],saver[10];
            for(int i=0; 1; i++)
            {
                printf("Enter Your Target : ");
                taker[0] = _getch();
                if(taker[0]<'1'|| taker[0]>'5')
                {
                    printf("Invalid Selection.. Please try again\n");
                    continue;
                }
                else if(taker[0]>='1'&& taker[0]<='5')
                {
                    printf("*\n");
                    break;
                }
            }
            for(int i=0; 1; i++)
            {
                printf("Save The Ball : ");
                saver[0] = _getch();
                if(saver[0]<'1'|| saver[0]>'5')
                {
                    printf("Invalid Selection.. Please try again\n");
                    continue;
                }
                else if(saver[0]>='1'&& saver[0]<='5')
                {
                    printf("*\n");
                    break;
                }
            }

            ///LEFT CORNER*/

            initwindow(1900,900,"TIE BREAKER");


            if(taker[0]=='2')
            {
                for(int i=620,j=540,k=540,m=620; i>=240; i-=10, j-=10,k-=10,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i>300)

                        readimagefile("STANDING MARTINEZ.jpg",700,300,500,500);
                }
            }

            ///RIGHT CORNER
            if(taker[0]=='4')
            {

                for(int i=800,j=700,k=700,m=800; i<=1300; i+=10, j-=10,k+=10,m-=10)
                {

                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i<1200)
                        readimagefile("STANDING MARTINEZ.jpg",700,300,500,500);
                }
            }
            /// STRAIGHT UP
            if(taker[0]=='3')
            {
                for(int i=700,j=620,k=620,m=700; j>=200; j-=10,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);

                    if(j>250)
                        readimagefile("STANDING MARTINEZ.jpg",700,300,500,500);
                }
            }
            ///RIGHT LOW CORNER
            if(taker[0]=='5')
            {
                for(int i=700,j=620,k=620,m=700; i<=1350; i+=20,j-=5,k+=20,m-=5)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i<1250)
                        readimagefile("STANDING MARTINEZ.jpg",700,300,500,500);
                }
            }
            ///LEFT LOW CORNER
            if(taker[0]=='1')
            {
                for(int i=700,j=620,k=620,m=700; i>=200; i-=20,j-=10,k-=20,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i>220)
                    {

                        readimagefile("STANDING MARTINEZ.jpg",700,300,500,500);
                    }
                }
            }
            ///left low corner gk
            if(saver[0]=='1')
            {
                readimagefile("LEFT MARTINEZ.jpg",200,370,450,450);
                ///printf("1\n");
            }
            /// left corner gk
            if(saver[0]=='2')
            {
                readimagefile("LEFT MARTINEZ.jpg",240,160,160,400);
                ///printf("2\n");
            }
            /// straight up
            if(saver[0]=='3')
            {
                readimagefile("UP MARTINEZ.jpg",700,200,620,380);
                ///printf("3\n");
            }
            ///right corner
            if(saver[0]=='4')
            {
                readimagefile("RIGHT MARTINEZ.jpg",1300,200,1500,300);
                ///printf("4\n");
            }
            ///right low corner gk
            if(saver[0]=='5')
            {
                readimagefile("RIGHT MARTINEZ.jpg",1300,370,1120,500);
                ///printf("5\n");
            }
            Sleep(3000);
            closegraph();
            if(taker[0]==saver[0])
            {
                initwindow(1900,900,"");
                setcolor(YELLOW);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(300,300,"SAVED!!!");
                Sleep(3000);
                closegraph();

            }
            if(taker[0]!=saver[0])
            {
                initwindow(1900,900,"");
                setcolor(YELLOW);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(300,300,"GOAL!!!");
                Sleep(3000);
                closegraph();
                score2++;
            }
        }

        printf("%s  : %d - %d : %s \n",p1,score1,score2,p2);
        if(score1>score2)
        {
            printf("%s WINS\n",p1);
            read();
            int v=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p1,data[i].id)==0)
                {
                    ///printf("q1\n");
                    data[i].match_played++;
                    data[i].match_won++;
                }
                else v++;
            }
            if(v==members)
            {
                strcpy(data[members].id,p1);
                ///printf("%s",data[i].id);
                data[members].match_played = 1;
                data[members].match_won = 1;
                members++;
            }
            int u =0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p2,data[i].id)==0)
                {
                    ///printf("q3\n");
                    data[i].match_played++;
                }
                else u++;
            }
            if(u==members)
            {
                strcpy(data[members].id,p2);
                data[members].match_played = 1;
                data[members].match_won = 0;
                members++;
            }
            write();
        }

        else if(score1<score2)
        {
            printf("%s WINS\n",p2);
            read();
            int v=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p2,data[i].id)==0)
                {
                    ///printf("q5\n");
                    data[i].match_played++;
                    data[i].match_won++;
                }
                else v++;
            }
            if(v==members)
            {
                strcpy(data[members].id,p2);
                data[members].match_played = 1;
                data[members].match_won = 1;
                members++;
            }
            int u=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p1,data[i].id)==0)
                {
                    ///printf("q7\n");
                    data[i].match_played++;
                }
                else u++;
            }
            if(u==members)
            {
                strcpy(data[members].id,p1);
                data[members].match_played = 1;
                data[members].match_won = 0;
                members++;
            }
            write();
        }


        else if(score1==score2)
        {
            printf("MATCH DRAW\n");
            read();
            int v=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p1,data[i].id)==0)
                {
                    ///printf("q9\n");
                    data[i].match_played++;
                }
                else v++;
            }
            if(v==members)
            {
                strcpy(data[members].id,p1);
                data[members].match_played = 1;
                data[members].match_won = 0;
                members++;
            }

            int u=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p2,data[i].id)==0)
                {
                    ///printf("q11\n");
                    data[i].match_played++;
                }
                else u++;
            }
            if(u==members)
            {
                strcpy(data[members].id,p2);
                data[members].match_played = 1;
                data[members].match_won = 0;
                members++;
            }
            write();
        }

        printf("Press any button to continue..\n");
        _getch();
    }
        if(j==3)
    {
        for(int k=0; k<number; k++)
        {
            if(k==0)
            {
                printf("%s : TAKER\n",p1);
                printf("%s : SAVER\n",p2);
            }
            char taker[10],saver[10];
            printf("Penalty took %d times\n",k);

            for(int i=0; 1; i++)
            {
                printf("Enter Your Target : ");
                taker[0] = _getch();
                if(taker[0]<'1'|| taker[0]>'5')
                {
                    printf("Invalid Selection.. Please try again\n");
                    continue;
                }
                else if(taker[0]>='1'&& taker[0]<='5')
                {
                    printf("*\n");
                    break;
                }
            }
            for(int i=0; 1; i++)
            {
                printf("Save The Ball : ");
                saver[0] = _getch();
                if(saver[0]<'1'|| saver[0]>'5')
                {
                    printf("Invalid Selection.. Please try again\n");
                    continue;
                }
                else if(saver[0]>='1'&& saver[0]<='5')
                {
                    printf("*\n");
                    break;
                }
            }
            initwindow(1900,900,"TIE BREAKER");
            ///LEFT CORNER*///

            if(taker[0]=='2')
            {
                for(int i=620,j=540,k=540,m=620; i>=240; i-=10, j-=10,k-=10,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i>300)

                        readimagefile("STANDING ALLISON.jpg",700,300,500,500);
                }
            }

            ///RIGHT CORNER
            if(taker[0]=='4')
            {

                for(int i=800,j=700,k=700,m=800; i<=1300; i+=10, j-=10,k+=10,m-=10)
                {

                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i<1200)
                        readimagefile("STANDING ALLISON.jpg",700,300,500,500);
                }
            }
            /// STRAIGHT UP
            if(taker[0]=='3')
            {
                for(int i=700,j=620,k=620,m=700; j>=200; j-=10,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    ///readimagefile("IMAGES/Football3.jpg",620,540,540,620);
                    if(j>250)
                        readimagefile("STANDING ALLISON.jpg",700,300,500,500);
                }
            }
            ///RIGHT LOW CORNER
            if(taker[0]=='5')
            {
                for(int i=700,j=620,k=620,m=700; i<=1350; i+=20,j-=5,k+=20,m-=5)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i<1250)
                        readimagefile("STANDING ALLISON.jpg",700,300,500,500);
                }
            }
            ///LEFT LOW CORNER
            if(taker[0]=='1')
            {
                for(int i=700,j=620,k=620,m=700; i>=200; i-=20,j-=10,k-=20,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i>220)
                    {

                        readimagefile("STANDING ALLISON.jpg",700,300,500,500);
                    }
                }
            }
            ///left low corner gk
            if(saver[0]=='1')
            {
                readimagefile("LEFT ALLISON.jpg",200,370,450,450);
                ///printf("1\n");
            }
            /// left corner gk
            if(saver[0]=='2')
            {
                readimagefile("LEFT ALLISON.jpg",240,160,160,400);
                ///printf("2\n");
            }
            /// straight up
            if(saver[0]=='3')
            {
                readimagefile("UP ALLISON.jpg",700,200,620,380);
                ///printf("3\n");
            }
            ///right corner
            if(saver[0]=='4')
            {
                readimagefile("RIGHT ALLISON.jpg",1300,200,1500,300);
                ///printf("4\n");
            }
            ///right low corner gk
            if(saver[0]=='5')
            {
                readimagefile("RIGHT ALLISON.jpg",1300,370,1120,500);
                ///printf("5\n");


            }
            Sleep(3000);
            closegraph();
            if(taker[0]==saver[0])
            {
                initwindow(1900,900,"");
                setcolor(YELLOW);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(300,300,"SAVED!!!");
                Sleep(3000);
                closegraph();

            }
            if(taker[0]!=saver[0])
            {
                initwindow(1900,900,"");
                setcolor(YELLOW);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(300,300,"GOAL!!!");
                Sleep(3000);
                closegraph();
                score1++;
            }
        }
        for(int m=0; m<number; m++)
        {
            if(m==0)
            {
                printf("%s : TAKER\n",p2);
                printf("%s : SAVER\n",p1);
            }
            printf("Penalty took %d times\n",m);
            char taker[10],saver[10];
            for(int i=0; 1; i++)
            {
                printf("Enter Your Target : ");
                taker[0] = _getch();
                if(taker[0]<'1'|| taker[0]>'5')
                {
                    printf("Invalid Selection.. Please try again\n");
                    continue;
                }
                else if(taker[0]>='1'&& taker[0]<='5')
                {
                    printf("*\n");
                    break;
                }
            }
            for(int i=0; 1; i++)
            {
                printf("Save The Ball : ");
                saver[0] = _getch();
                if(saver[0]<'1'|| saver[0]>'5')
                {
                    printf("Invalid Selection.. Please try again\n");
                    continue;
                }
                else if(saver[0]>='1'&& saver[0]<='5')
                {
                    printf("*\n");
                    break;
                }
            }

            ///LEFT CORNER*/

            initwindow(1900,900,"TIE BREAKER");


            if(taker[0]=='2')
            {
                for(int i=620,j=540,k=540,m=620; i>=240; i-=10, j-=10,k-=10,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i>300)

                        readimagefile("STANDING ALLISON.jpg",700,300,500,500);
                }
            }

            ///RIGHT CORNER
            if(taker[0]=='4')
            {

                for(int i=800,j=700,k=700,m=800; i<=1300; i+=10, j-=10,k+=10,m-=10)
                {

                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i<1200)
                        readimagefile("STANDING ALLISON.jpg",700,300,500,500);
                }
            }
            /// STRAIGHT UP
            if(taker[0]=='3')
            {
                for(int i=700,j=620,k=620,m=700; j>=200; j-=10,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);

                    if(j>250)
                        readimagefile("STANDING ALLISON.jpg",700,300,500,500);
                }
            }
            ///RIGHT LOW CORNER
            if(taker[0]=='5')
            {
                for(int i=700,j=620,k=620,m=700; i<=1350; i+=20,j-=5,k+=20,m-=5)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i<1250)
                        readimagefile("STANDING ALLISON.jpg",700,300,500,500);
                }
            }
            ///LEFT LOW CORNER
            if(taker[0]=='1')
            {
                for(int i=700,j=620,k=620,m=700; i>=200; i-=20,j-=10,k-=20,m-=10)
                {
                    readimagefile("marked post.jpg",0,0,1600,900);
                    readimagefile("Orginal ball.jpg",i,j,k,m);
                    if(i>220)
                    {

                        readimagefile("STANDING ALLISON.jpg",700,300,500,500);
                    }
                }
            }
            ///left low corner gk
            if(saver[0]=='1')
            {
                readimagefile("LEFT ALLISON.jpg",200,370,450,450);
                ///printf("1\n");
            }
            /// left corner gk
            if(saver[0]=='2')
            {
                readimagefile("LEFT ALLISON.jpg",240,160,160,400);
                ///printf("2\n");
            }
            /// straight up
            if(saver[0]=='3')
            {
                readimagefile("UP ALLISON.jpg",700,200,620,380);
                ///printf("3\n");
            }
            ///right corner
            if(saver[0]=='4')
            {
                readimagefile("RIGHT ALLISON.jpg",1300,200,1500,300);
                ///printf("4\n");
            }
            ///right low corner gk
            if(saver[0]=='5')
            {
                readimagefile("RIGHT ALLISON.jpg",1300,370,1120,500);
                ///printf("5\n");
            }
            Sleep(3000);
            closegraph();
            if(taker[0]==saver[0])
            {
                initwindow(1900,900,"");
                setcolor(YELLOW);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(300,300,"SAVED!!!");
                Sleep(3000);
                closegraph();

            }
            if(taker[0]!=saver[0])
            {
                initwindow(1900,900,"");
                setcolor(YELLOW);
                settextstyle(EUROPEAN_FONT,HORIZ_DIR,5);
                outtextxy(300,300,"GOAL!!!");
                Sleep(3000);
                closegraph();
                score2++;
            }
        }

        printf("%s  : %d - %d : %s \n",p1,score1,score2,p2);
        if(score1>score2)
        {
            printf("%s WINS\n",p1);
            read();
            int v=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p1,data[i].id)==0)
                {
                    ///printf("q1\n");
                    data[i].match_played++;
                    data[i].match_won++;
                }
                else v++;
            }
            if(v==members)
            {
                strcpy(data[members].id,p1);
                ///printf("%s",data[i].id);
                data[members].match_played = 1;
                data[members].match_won = 1;
                members++;
            }
            int u =0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p2,data[i].id)==0)
                {
                    ///printf("q3\n");
                    data[i].match_played++;
                }
                else u++;
            }
            if(u==members)
            {
                strcpy(data[members].id,p2);
                data[members].match_played = 1;
                data[members].match_won = 0;
                members++;
            }
            write();
        }

        else if(score1<score2)
        {
            printf("%s WINS\n",p2);
            read();
            int v=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p2,data[i].id)==0)
                {
                    ///printf("q5\n");
                    data[i].match_played++;
                    data[i].match_won++;
                }
                else v++;
            }
            if(v==members)
            {
                strcpy(data[members].id,p2);
                data[members].match_played = 1;
                data[members].match_won = 1;
                members++;
            }
            int u=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p1,data[i].id)==0)
                {
                    ///printf("q7\n");
                    data[i].match_played++;
                }
                else u++;
            }
            if(u==members)
            {
                strcpy(data[members].id,p1);
                data[members].match_played = 1;
                data[members].match_won = 0;
                members++;
            }
            write();
        }


        else if(score1==score2)
        {
            printf("MATCH DRAW\n");
            read();
            int v=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p1,data[i].id)==0)
                {
                    ///printf("q9\n");
                    data[i].match_played++;
                }
                else v++;
            }
            if(v==members)
            {
                strcpy(data[members].id,p1);
                data[members].match_played = 1;
                data[members].match_won = 0;
                members++;
            }

            int u=0;
            for(int i=0; i<members; i++)
            {

                if(strcmp(p2,data[i].id)==0)
                {
                    ///printf("q11\n");
                    data[i].match_played++;
                }
                else u++;
            }
            if(u==members)
            {
                strcpy(data[members].id,p2);
                data[members].match_played = 1;
                data[members].match_won = 0;
                members++;
            }
            write();
        }

        printf("Press any button to continue..\n");
        _getch();
    }
}

int main()
{

    setColor(11);
    int i, j;

    ///TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT
    for( i = 47 ; i <= 57 ; i++ )
    {
        gotoxy(i, 9);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 10 ; i <= 13 ; i++ )
    {
        gotoxy(52, i);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }


    ///IIIIIIIIIIIIIIIIIIIIIIIIIIIIII
    for( i = 61 ; i <= 63 ; i++ )
    {
        gotoxy(i, 9);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 10 ; i <= 12 ; i++ )
    {
        gotoxy(62, i);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 61 ; i <= 63 ; i++ )
    {
        gotoxy(i, 13);
        printf("*");
        fflush(stdout);
        //sleep(1);

    }
    ///EEEEEEEEEEEEEEEEEEEEEEEEEEE
    for( i = 9 ; i <= 13 ; i++ )
    {
        gotoxy(67, i);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 68 ; i <= 72 ; i++ )
    {
        gotoxy(i, 9);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 68 ; i <= 72 ; i++ )
    {
        gotoxy(i, 11);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 68 ; i <= 72 ; i++ )
    {
        gotoxy(i, 13);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }

    ///BBBBBBBBBBBBBBBBBBBBBBBBBBBBB
    for( i = 16 ; i <= 20 ; i++ )
    {
        gotoxy(29, i);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 30 ; i <= 32 ; i++ )
    {
        gotoxy(i, 16);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    gotoxy(33, 17);
    printf("*");
    fflush(stdout);
    //sleep(1);
    for( i = 30 ; i <= 32 ; i++ )
    {
        gotoxy(i, 18);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    gotoxy(33, 19);
    printf("*");
    fflush(stdout);
    //sleep(1);
    for( i = 30 ; i <= 32 ; i++ )
    {
        gotoxy(i, 20);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }

    ///RRRRRRRRRRRRR
    for( i = 16 ; i <= 20 ; i++ )
    {
        gotoxy(37, i);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 38 ; i <= 40 ; i++ )
    {
        gotoxy(i, 16);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    gotoxy(41, 17);
    printf("*");
    fflush(stdout);
    //sleep(1);
    for( i = 38 ; i <= 40 ; i++ )
    {
        gotoxy(i, 18);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 19 ; i <= 20 ; i++ )
    {
        gotoxy(41, i);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }

    ///EEEEEEEEEEEEE
    for( i = 16 ; i <= 20 ; i++ )
    {
        gotoxy(45, i);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 46 ; i <= 50 ; i++ )
    {
        gotoxy(i, 16);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 46 ; i <= 50 ; i++ )
    {
        gotoxy(i, 18);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 46 ; i <= 50 ; i++ )
    {
        gotoxy(i, 20);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    ///AAAAAAAAAA
    for( i = 58, j = 16 ; i >= 54 ; i--, j++ )
    {
        gotoxy(i, j);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 59, j = 17 ; i <= 62 ; i++, j++ )
    {
        gotoxy(i, j);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 57 ; i <= 59 ; i++ )
    {
        gotoxy(i, 18);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }

    ///KKKKKKKKKK
    for( i = 16 ; i <= 20 ; i++ )
    {
        gotoxy(66, i);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 67, j = 18 ; j <= 20 ; i += 2, j++ )
    {
        gotoxy(i, j);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 69, j = 17 ; j >= 16 ; i += 2, j-- )
    {
        gotoxy(i, j);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }

    ///EEEEEEEE
    for( i = 16 ; i <= 20 ; i++ )
    {
        gotoxy(75, i);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 76 ; i <= 79 ; i++ )
    {
        gotoxy(i, 16);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 76 ; i <= 79 ; i++ )
    {
        gotoxy(i, 18);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 76 ; i <= 79 ; i++ )
    {
        gotoxy(i, 20);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    ///RRRRRRRRRR
    for( i = 16 ; i <= 20 ; i++ )
    {
        gotoxy(83, i);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 84 ; i <= 86 ; i++ )
    {
        gotoxy(i, 16);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    gotoxy(87, 17);
    printf("*");
    fflush(stdout);
    //sleep(1);
    for( i = 84 ; i <= 86 ; i++ )
    {
        gotoxy(i, 18);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    for( i = 19 ; i <= 20 ; i++ )
    {
        gotoxy(87, i);
        printf("*");
        fflush(stdout);
        //sleep(1);
    }
    printf("\nPress any button to continue..\n");
    _getch();





    /* setColor(14);
     gotoxy(65, 22);
     printf("CLICK TO START THE GAME"); fflush(stdout);
     //sleep(1);**/

    int x;
    do
    {
        x = MENU();
        switch (x)
        {
        case 1:
            Start_Game();
            break;
        case 2:
            settings();
            break;
        case 3:
            DevelopedBy();
            break;
        case 4:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
    while (x != 4);

    return 0;


}
