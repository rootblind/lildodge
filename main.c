#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

char teren[20][40],caracter;
int l = 20,L = 40;
unsigned gameover = 0,x,y,difficulty = 0,safe_space5 = 20 / 2,safe_space1 = 20 / 2,safe_space2 = 20 / 2,safe_space3 = 20 / 2,safe_space4 = 20 / 2, c1_wall = 37,c2_wall = 37,c3_wall = 37,c4_wall = 37,score = 0;
unsigned c5_wall = 37;
void afisare()
{
    int i,j;
    system("cls");
    for(i = 0; i < l; i++)
    {
        for(j = 0; j < L; j++)
            printf("%c",teren[i][j]);
        printf("\n");
    }
    printf("\n\nSCORE:  %d",score);
}

void setup()
{
    int i,j;
    do{
        system("cls");
        printf("Alege dificultatea: 0 - 100:   ");
        scanf("%u",&difficulty);
    }while(difficulty < 0 || difficulty > 100);
    difficulty = 100 - difficulty;
    printf("Alege-ti caracterul: ");
    scanf("%s",&caracter);
    for(i = 0; i < l; i++)
        for(j = 0; j < L; j++)
            if(i == 0 || j == 0 || i == l - 1 || j == L - 1)
                teren[i][j] = 'O';
            else
                teren[i][j] = ' ';
    teren[l / 2 - 1][4] = caracter;

    y = l / 2 - 1;
    x = 4;

}
//38
void walls()
{
    int i,j;
    for(i = 1; i < l - 1; i++)
        if(teren[i][c1_wall] != caracter)
        {
            teren[i][c1_wall] = 'O';
            if(teren[i][c1_wall + 1] != caracter)
                teren[i][c1_wall + 1] = ' ';
        }

    if(teren[safe_space1][c1_wall] != caracter && c1_wall != 0)
        teren[safe_space1][c1_wall] = ' ';

    if(teren[safe_space1 - 1][c1_wall] != caracter && c1_wall != 0)
        teren[safe_space1 - 1][c1_wall] = ' ';

    if(teren[safe_space1 + 1][c1_wall] != caracter && c1_wall != 0)
        teren[safe_space1 + 1][c1_wall] = ' ';

    if(c1_wall <= L - 12 || c2_wall <= L - 12)
    {
        for(i = 1; i < l - 1; i++)
        if(teren[i][c2_wall] != caracter)
        {
            teren[i][c2_wall] = 'O';
            if(teren[i][c2_wall + 1] != caracter)
                teren[i][c2_wall + 1] = ' ';
        }

    if(teren[safe_space2][c2_wall] != caracter && c2_wall != 0)
        teren[safe_space2][c2_wall] = ' ';

    if(teren[safe_space2 - 1][c2_wall] != caracter && c2_wall != 0)
        teren[safe_space2 - 1][c2_wall] = ' ';

    if(teren[safe_space2 + 1][c2_wall] != caracter && c2_wall != 0)
        teren[safe_space2 + 1][c2_wall] = ' ';
    }
    if(c3_wall <= L - 12 || c4_wall <= L - 12)
    {
        for(i = 1; i < l - 1; i++)
        if(teren[i][c4_wall] != caracter)
        {
            teren[i][c4_wall] = 'O';
            if(teren[i][c4_wall + 1] != caracter)
                teren[i][c4_wall + 1] = ' ';
        }

    if(teren[safe_space4][c4_wall] != caracter && c4_wall != 0)
        teren[safe_space4][c4_wall] = ' ';

    if(teren[safe_space4 - 1][c4_wall] != caracter && c4_wall != 0)
        teren[safe_space4 - 1][c4_wall] = ' ';

    if(teren[safe_space4 + 1][c4_wall] != caracter && c4_wall != 0)
        teren[safe_space4 + 1][c4_wall] = ' ';
    }


    if(c2_wall <= L - 12 || c3_wall <= L - 12)
    {
        for(i = 1; i < l - 1; i++)
        if(teren[i][c3_wall] != caracter)
        {
            teren[i][c3_wall] = 'O';
            if(teren[i][c3_wall + 1] != caracter)
                teren[i][c3_wall + 1] = ' ';
        }

    if(teren[safe_space3][c3_wall] != caracter && c3_wall != 0)
        teren[safe_space3][c3_wall] = ' ';

    if(teren[safe_space3 - 1][c3_wall] != caracter && c3_wall != 0)
        teren[safe_space3 - 1][c3_wall] = ' ';

    if(teren[safe_space3 + 1][c3_wall] != caracter && c3_wall != 0)
        teren[safe_space3 + 1][c3_wall] = ' ';
    }








    if(c1_wall == 0)
    {
        c1_wall = 37;
        safe_space1 = rand() % 10 + 3;
    }
    if(c2_wall == 0)
    {
        c2_wall = 37;
        safe_space2 = safe_space1 + 5;
    }
    if(c3_wall == 0)
    {
        c3_wall = 37;
        safe_space3 = safe_space2 - 3;
    }
    if(c4_wall == 0)
    {
        c4_wall = 37;
        safe_space4 = safe_space3 - 3;
    }



}

void miscare()
{
    char move;
    while(!gameover)
    {

        walls();
        afisare();
        if(_kbhit())
            move = _getch();
        switch(move)
        {
        case 'w':
            if(y != 1 && teren[y - 1][x] != 'O')
                {
                    teren[y - 1][x] = caracter;
                    teren[y][x] = ' ';
                    y--;
                }
            else
                gameover = 1;
            break;
        case 's':
            if(y != l - 2 && teren[y + 1][x] != 'O')
            {
                teren[y + 1][x] = caracter;
                teren[y][x] = ' ';
                y++;
            }
            else
                gameover = 1;
            break;
        case 'a':
            if(x != 1 && teren[y][x - 1] != 'O')
            {
                teren[y][x - 1] = caracter;
                teren[y][x] = ' ';
                x--;
            }
            else
                gameover = 1;
            break;
        case 'd':
            if(x != L - 2 && teren[y][x + 1] != 'O')
            {
                teren[y][x + 1] = caracter;
                teren[y][x] = ' ';
                x++;
            }
            else
                gameover = 1;
            break;
        default:
            break;
        }

          if((x == c1_wall && y != safe_space1 && y != safe_space1 + 1 && y != safe_space1 - 1)||(x == c2_wall && y != safe_space2 && y != safe_space2 + 1 && y != safe_space2 - 1)||(x == c3_wall && y != safe_space3 && y != safe_space3 + 1 && y != safe_space3 - 1)||(x == c4_wall && y != safe_space4 && y != safe_space4 + 1 && y != safe_space4 - 1))
            gameover = 1;
        else
            if((x == c1_wall || x == c2_wall || x == c3_wall || x == c4_wall ) && ((y == safe_space1 || y == safe_space2 || y == safe_space3 || y == safe_space4 ) || (y == safe_space1 + 1  ||  y == safe_space2 + 1  || y == safe_space3 + 1 || y == safe_space4 + 1) || ( y == safe_space1 - 1 || y == safe_space2 - 1 || y == safe_space3 - 1 ||y == safe_space4 - 1)))
                score++;

        if(c1_wall)
            c1_wall--;
        if(c2_wall && c1_wall <= L - 12 || c2_wall <= L - 12)
            c2_wall--;
        if(c3_wall && c2_wall <= L - 12 || c3_wall <= L - 12)
            c3_wall--;
        if(c4_wall && c3_wall <= L - 12 || c4_wall <= L - 12)
            c4_wall--;


        Sleep(difficulty);
    }
}




int main()
{
    printf("W- sus\nA- stanga\nS- jos\nD- dreapta\nOrice tasta pentru a opri caracterul din miscare.\nApasa o tasta pentru a da play!");
    _getch();
    while(1)
    {
        setup();
        miscare();
        c5_wall = 37;
        difficulty = 0,safe_space5 = 20 / 2,safe_space1 = 20 / 2,safe_space2 = 20 / 2,safe_space3 = 20 / 2,safe_space4 = 20 / 2, c1_wall = 37,c2_wall = 37,c3_wall = 37,c4_wall = 37,score = 0;
        printf("\nAi pierdut!\n Apasa pe orice tasta pentru a da replay!");
        gameover = 0;
        _getch();
    }

    return 0;
}
