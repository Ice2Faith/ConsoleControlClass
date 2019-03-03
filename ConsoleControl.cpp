#include"ConsoleControl.h"
namespace ConCI2F
{

char ConsoleControl::Getchif(void)
{
    if(_kbhit())
        return _getch();
    return '\0';
}
void ConsoleControl::ScreenTips(int mode,int time,int BeforeTextColor,int BeforeBackGroundColor)
{
    if(mode==0||mode<-1||mode>1)
        sprintf_s(mind,"color e1\0");
    else if(mode==1)
		sprintf_s(mind, "color 1f\0");
    else if(mode==-1)
		sprintf_s(mind, "color c0\0");
    system(mind);
    if(time<=0)
        time=30;
    Sleep(time);
    SetConsoleColor(BeforeTextColor,BeforeBackGroundColor);
}
char ConsoleControl::Getchf(void)
{
    char ch;
    ch=_getch();
    printf("%c\n",ch);
    return ch;
}
void ConsoleControl::GetHelp()
{
    char help[800]= {"SetColor:\n\
0 = ºÚÉ«       8 = »ÒÉ«\n\
1 = À¶É«       9 = µ­À¶É«\n\
2 = ÂÌÉ«       10 = µ­ÂÌÉ«\n\
3 = Ç³ÂÌÉ«     11 = µ­Ç³ÂÌÉ«\n\
4 = ºìÉ«       12 = µ­ºìÉ«\n\
5 = ×ÏÉ«       13 = µ­×ÏÉ«\n\
6 = »ÆÉ«       14 = µ­»ÆÉ«\n\
7 = °×É«       15 = ÁÁ°×É«\n\
SetGotoxy:\n\
Set display space to lines,cols\n\
SetConsoleSize:\n\
if lines or cols >0 will set,or not set.\n\
SleepPrint:\n\
will one by one print char\n\
ConsoleCls:\n\
will clean console screen\n\
\0"
                    };
	printf("%s", help);
}
void ConsoleControl::SleepPrint(int time,const char * text)
{
    if(time<=0)
        printf("%s",text);
    else
        while(*text)
        {
            printf("%c",*text);
            Sleep(time);
            text++;
        }
}
void ConsoleControl::SetConsoleSize(int lines,int cols)
{
    if(lines>0 && cols>0)
		sprintf_s(mind, "mode con lines=%d cols=%d\0", lines, cols);
    else if(lines <=0 && cols>0)
		sprintf_s(mind, "mode con cols=%d\0", cols);
    else if(lines >0 && cols<=0)
		sprintf_s(mind, "mode con lines=%d\0", lines);
    else if(lines<=0 && cols<=0)
        return;
    system(mind);
}
void ConsoleControl::ConsoleCls(void)
{
    system("cls");
}
void ConsoleControl::SetConsoleTitle(char title[])
{
	sprintf_s(mind, "title %s\0", title);
    system(mind);
}
void ConsoleControl::SetConsoleColor(int TextColor,int BackGroundColor)
{
    if(TextColor<0 ||TextColor>15)
        TextColor=15;
    if(BackGroundColor<0 ||BackGroundColor>15)
        BackGroundColor=0;
    char Model[18]= {"0123456789ABCDEF\0"};
	sprintf_s(mind, "color %c%c\0", Model[BackGroundColor], Model[TextColor]);
    system(mind);
}

void ConsoleControl::SetTextColor(int ForeColor,int BackGroundColor)
{
    if(ForeColor<0 ||ForeColor>15)
        ForeColor=15;
    if(BackGroundColor<0 ||BackGroundColor>15)
        BackGroundColor=0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),ForeColor+BackGroundColor*0x10);
}
void ConsoleControl::SetGotoxy(int lines,int cols)
{
    COORD Go = {cols, lines};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Go);
}
}