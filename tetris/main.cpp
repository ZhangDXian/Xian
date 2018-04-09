#include<windows.h>
#include<time.h>
#include<stdlib.h>

#define W 14 //��Ϸ������
#define H 20 //��Ϸ����߶�
#define W1 6 //�ұ�״̬�����
#define BSIZE 25 //��Ϸ����߳�
#define Y1 6 //������Ƭ��������
#define Y2 12 //������ʾ������������
#define Y3 15 //�ȼ���ʾ������������
#define Y4 21 //����������������
#define Cur_x W/2-1 //��Ϸ�����ʼ״̬���ϽǺ�����
#define Cur_y 1 //��ʼ״̬���Ͻ�������
#define BgColor RGB(0xF5,0xF5,0xDC) //��ɫ
#define FgColor RGB(255,153,204) //�ۺ�
#define RED RGB(255,0,0)
#define ORANGE RGB(250,128,10)
#define YELLOW RGB(255,255,0)
#define GREEN RGB(0,255,0)
#define CYAN RGB(0,255,255)
#define LIGHT_BLUE RGB(0xA6,0xCA,0xF0) //����ɫ
#define PURPLE RGB(255,0,255)
#define MS_NEWBLOCK WM_USER+1  // ��ϢID�������µġ����顿

int score=0,level=0,level_step=100; //�����ȼ��Լ�ÿ�ȼ���������Ķ��弰��ʼ��
int top=H-1; //��˵�������
int x,y; //���鵱ǰλ�õĺ����꼰������
int cur_boxnum,next_boxnum; //cur_boxnum�ǵ�ǰ�����ţ�next_boxnum����һ��������

struct BOARD
{
    int var; //״̬��1�����ѱ�ռ�ã�0����δ��ռ��
    int color; //��ɫ
}board[H][W]; //������Ϸ���壬H��N��

struct BLOCK
{
    int a[4][2]; //���巽����״������
    int color; //������ɫ
    int next; //��һ������ĺ���
};

struct BLOCK block[19]=
{  //��ʼ��������Ϸ����
    {1,1,1,2,1,3,2,3,RED,1},
    {0,2,1,2,2,2,0,3,RED,2},
    {0,1,1,1,1,2,1,3,RED,3},
    {2,1,0,2,1,2,2,2,RED,0},
    {1,1,1,2,0,3,1,3,ORANGE,5},
    {0,1,0,2,1,2,2,2,ORANGE,6},
    {1,1,2,1,1,2,1,3,ORANGE,7},
    {0,2,1,2,2,2,2,3,ORANGE,4},
    {1,1,0,2,1,2,2,2,YELLOW,9},
    {1,1,1,2,2,2,1,3,YELLOW,10},
    {0,2,1,2,2,2,1,3,YELLOW,11},
    {1,1,0,2,1,2,1,3,YELLOW,8},
    {1,1,1,2,2,2,2,3,GREEN,13},
    {1,2,2,2,0,3,1,3,GREEN,12},
    {2,1,1,2,2,2,1,3,CYAN,15},
    {0,2,1,2,1,3,2,3,CYAN,14},
    {1,0,1,1,1,2,1,3,LIGHT_BLUE,17},
    {0,2,1,2,2,2,3,2,LIGHT_BLUE,16},
    {1,1,2,1,1,2,2,2,PURPLE,18},
};

void Paint(HDC hdc,HPEN hpen) //�˺������ڳ�ʼ������
{
    int i,j;
    HPEN hpen1; //���廭�ʣ����ڻ��Ʒָ���
    HBRUSH hbrush=CreateSolidBrush(BgColor); //���廭ˢ������ֵ����ˢ��ɫ���ñ���ɫ

    hpen1=CreatePen(PS_DASHDOTDOT,3,FgColor); //�����ʸ���ֵ����ɫΪǰ��ɫ���߿�Ϊ3��˫�㻮��
    SelectObject(hdc,hpen1); //ѡ�񻭱�
    MoveToEx(hdc,W*BSIZE,0,NULL); //������ƶ���(W*BSIZE,0)��
    LineTo(hdc,W*BSIZE,H*BSIZE); //�ӹ������λ�û��ߵ�(W*BSIZE,H*BSIZE)��
    DeleteObject(hpen1); //ɾ��֮ǰ��ѡ�õĻ���
    SelectObject(hdc,hpen); //����ѡ�񻭱�
    SelectObject(hdc,hbrush); //ѡ��ˢ

    for(i=1;i<H-1;i++)  //������Ϸ���򷽸���
        for(j=1;j<W-1;j++)
            Rectangle(hdc,j*BSIZE,i*BSIZE,(j+1)*BSIZE,(i+1)*BSIZE);

    for(i=1;i<5;i++)  //�����ұ�״̬����ϷԤ�����򷽸���
        for(j=W+1;j<W+W1-1;j++)
            Rectangle(hdc,j*BSIZE,i*BSIZE,(j+1)*BSIZE,(i+1)*BSIZE);

    Rectangle(hdc,(W+1)*BSIZE,Y2*BSIZE,(W+W1-1)*BSIZE,(Y2+2)*BSIZE); //���Ʒ�����������
    Rectangle(hdc,(W+1)*BSIZE,Y3*BSIZE,(W+W1-1)*BSIZE,(Y3+2)*BSIZE); //���Ƶȼ���������
    Rectangle(hdc,(W+1)*BSIZE,Y4*BSIZE,(W+W1-1)*BSIZE,(Y4+4)*BSIZE); //���ư�����������

    TextOut(hdc,(W+2)*BSIZE,(Y2+0.2)*BSIZE,"��    ��",8); //�������
    TextOut(hdc,(W+2)*BSIZE,(Y3+0.2)*BSIZE,"��    ��",8); //ͬ��

    DeleteObject(hpen); //ɾ������
    DeleteObject(hbrush); //ɾ����ˢ
}

void ShowScore(HDC hdc) //��ʾ�����ĺ���
{
    char score_str[4]; //�����ַ������ڱ������ֵ
    wsprintf(score_str,"%3d",score); //������scoreת�����ַ����󱣴浽score_str֮��
    TextOut(hdc,(W+2.5)*BSIZE,(Y2+1.2)*BSIZE,score_str,3); //����Ϸ������ʾ����
}

void ShowLevel(HDC hdc) //��ʾ�ȼ��ģ�����ͬ��
{
    char level_str[4];
    wsprintf(level_str,"%3d",level);
    TextOut(hdc,(W+2.5)*BSIZE,(Y3+1.2)*BSIZE,level_str,3);
}

void ShowHelp(HDC hdc) //��ʾ�����ģ��ú���ֻ�ڳ�ʼ������ʱ����
{
    char help1[]="�� - ��ת",
    help2[]="�� - ����",
    help3[]="�� - ����",
    help4[]="�� - ����";
    TextOut(hdc,(W+1.8)*BSIZE,(Y4+0.2)*BSIZE,help1,9);
    TextOut(hdc,(W+1.8)*BSIZE,(Y4+1.2)*BSIZE,help2,9);
    TextOut(hdc,(W+1.8)*BSIZE,(Y4+2.2)*BSIZE,help3,9);
    TextOut(hdc,(W+1.8)*BSIZE,(Y4+3.2)*BSIZE,help4,9);
}

void EraseBox(HDC hdc,HPEN hpen,int x,int y,int num) //���(x,y)�����Ϊnum���ķ���
{
    int i;
    HBRUSH hbrush=CreateSolidBrush(BgColor);
    SelectObject(hdc,hpen);
    SelectObject(hdc,hbrush);

    for(i=0;i<4;i++)//�ñ���ɫ��䷽����������ʹ��������
        Rectangle(hdc,
        (x+block[num].a[i][0])*BSIZE,
        (y+block[num].a[i][1])*BSIZE,
        (x+block[num].a[i][0]+1)*BSIZE,
        (y+block[num].a[i][1]+1)*BSIZE);

    DeleteObject(hpen);
    DeleteObject(hbrush);
}

void ShowBox(HDC hdc,HPEN hpen,int x,int y,int num) //��ʾ(x,y)�����Ϊnum���ķ���
{
    int i;
    HBRUSH hbrush;

    hbrush=CreateSolidBrush(block[num].color); //������ˢ����ɫ�ͷ�����ɫ��ͬ
    SelectObject(hdc,hpen);
    SelectObject(hdc,hbrush);

    for(i=0;i<4;i++) //��ʾ����Ĺ���
        Rectangle(hdc,
        (x+block[num].a[i][0])*BSIZE,
        (y+block[num].a[i][1])*BSIZE,
        (x+block[num].a[i][0]+1)*BSIZE,
        (y+block[num].a[i][1]+1)*BSIZE);

    DeleteObject(hpen);
    DeleteObject(hbrush);
}

void SetFullRow(HDC hdc,HPEN hpen) //���д�����
{
    int i,ii,j;
    int org_top=top;
    int flag=0;
    HBRUSH hbrush;
    SelectObject(hdc,hpen);
    for(i=y;i<y+4;i++) //��y�п�ʼ�����ϵ��±�����Ϸ����
    {
        if(i<=0||i>=H-1) continue; //Խ���ˣ�����������ѭ��

        for(j=1;j<W-1;j++)
            if(!board[i][j].var) break; //һ��������һ��Ϊ�գ�������

        if(j==W-1) //�ҵ�������
        {
            for(ii=i;ii>=top;ii--) //������Ϸ������������״̬��topΪ��ˣ�iΪ�ҵ�������
                for(j=1;j<W-1;j++)
                    board[ii][j]=board[ii-1][j];

            top++;
            score+=10; //������10
            flag=1; //��־��
        }
    }

    if(flag) //��������У����ػ�����
    {
        for(i=org_top;i<y+4;i++) //ԭ�������
        {
            if(i<=0||i>=H-1) continue; //Խ���ˣ�����������ѭ��
            for(j=1;j<W-1;j++)
            { //ע�������������ʱ��ÿ�ζ�Ҫѡ��ͬ�Ļ�ˢ�������һ��Ҫɾ��
                hbrush=CreateSolidBrush(board[i][j].color);
                SelectObject(hdc,hbrush);
                Rectangle(hdc,j*BSIZE,i*BSIZE,(j+1)*BSIZE,(i+1)*BSIZE);
                DeleteObject(hbrush);
            }
        }
        if(level!=score/level_step) //�����ǳ����Ż����֣�Ҳ��ʡ��
        level=score/level_step;
        ShowScore(hdc); //���·���
        ShowLevel(hdc); //���µȼ�
    }
    DeleteObject(hpen);
}

void ChangeVar(void) //�ı���Ϸ�����״̬
{
    int i;
    for(i=0;i<4;i++)
    {
        board[y+block[cur_boxnum].a[i][1]][x+block[cur_boxnum].a[i][0]].var=1; //״̬��1,��ʾ�з������
        board[y+block[cur_boxnum].a[i][1]][x+block[cur_boxnum].a[i][0]].color=block[cur_boxnum].color;
    }
}

BOOL CanMove(void) //�жϷ����Ƿ����ƶ�
{
    int i;
    for(i=0;i<4;i++)
        if(board[y+block[cur_boxnum].a[i][1]][x+block[cur_boxnum].a[i][0]].var) //�����λ���Լ��з�����䣬�����ƶ�
            return FALSE;
    return TRUE;
}

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM); //���ڹ��̺���������
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hprevInstance,PSTR szCmdLine,int iCmdShow) //��ں�������������
{ //�����β����������˼�����в�������
    int screenwide,screenhight; //���������������Ļ��Ⱥ͸߶�
    char AppName[]="Tetris"; //���岢��ʼ����������

    HWND hwnd; //���崰�ھ��
    MSG msg; //������Ϣ�ṹ��
    WNDCLASSEX wndclass; //���崰����

    wndclass.cbSize=sizeof(wndclass); //�������С
    wndclass.style=CS_HREDRAW|CS_VREDRAW; //��������
    wndclass.lpfnWndProc=WndProc; //���ڹ��̺���ΪWndProc
    wndclass.cbClsExtra=0; //����������չ
    wndclass.cbWndExtra=0; //����ʵ������չ
    wndclass.hInstance=hInstance; //��ǰʵ�����ΪhInstance
    wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION); //����Ĭ��ͼ��
    wndclass.hCursor=LoadCursor(NULL,IDC_ARROW); //Ĭ�Ϲ�꣬�����봰������ʱ������ʾΪ��ͷ
    wndclass.hbrBackground=CreateSolidBrush(BgColor); //���ڱ���ɫ
    wndclass.lpszMenuName=NULL; //�������޲˵�
    wndclass.lpszClassName=AppName; //��������
    wndclass.hIconSm=LoadIcon(NULL,IDI_APPLICATION); //����Ĭ��Сͼ��

    if(!RegisterClassEx(&wndclass)) //�������ע��
    {
        MessageBeep(0);
        return FALSE;
    }

    screenwide=GetSystemMetrics(SM_CXFULLSCREEN); //��ȡ��Ļ��ȣ�������ֱ���
    screenhight=GetSystemMetrics(SM_CYFULLSCREEN); //��ȡ��Ļ�߶�

    hwnd=CreateWindow( //��������
        AppName, //��������
        "����˹����", //����ʵ��������
        WS_OVERLAPPEDWINDOW,
        (screenwide-(W+W1)*BSIZE)/2, //�������ϽǺ�����
        (screenhight-H*BSIZE)/2, //���Ͻ�������
        (W+W1)*BSIZE, //���ڿ��
        (H+1)*BSIZE, //���ڸ߶ȣ�ע������˱�����
        NULL, //�����޸�����
        NULL, //������ס�˵�
        hInstance, //��ǰӦ�ó���ʵ�����
        NULL //���ֵһ����NULL�����������в�ѯ
        );

    if(!hwnd) return FALSE; //����ʧ�����˳�����

    ShowWindow(hwnd,iCmdShow); //��ʾ����
    UpdateWindow(hwnd); //ˢ�´���
    MessageBox(hwnd," ��������","��ʼ",MB_OK); //������
    SetTimer(hwnd,1,500,NULL); //����һ��500���봥��һ�εĶ�ʱ��������������������������в�ѯ

    while(GetMessage(&msg,NULL,0,0)) //��Ϣѭ�������ڴ���Ϣ�����л�ȡ��Ϣ
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam; //ע����һ��������
}

LRESULT CALLBACK WndProc(HWND hwnd,UINT iMsg,WPARAM wParam,LPARAM lParam)
{ //���崰�ڹ��̺���
    int i,j;
    int old_boxnum; //���ڱ���֮ǰ�ķ����
    HDC hdc; //����DC�����DC�������ͼĬ�ϵ�һЩ����
    PAINTSTRUCT ps; //�����ͼ�ṹ���˽ṹ��������ϢӦ�ó���ʹ��������һ��ӵ�и�Ӧ�ô��ڿͻ���
    HPEN hpen=CreatePen(PS_SOLID,1,FgColor); //ѡ��ˢ���ñ���ɫ����ˢ
    switch(iMsg) //��Ϣ����Ĺ���
    {
        case WM_CREATE: ////��һ��Ӧ�ó���ʹ�ú���CreateWindow��CreateWindowEx������һ������ʱ��
                        //ϵͳ�����͸���Ϣ�����½����ڹ��̡�����Ϣ���ڴ�������֮����ʾ����
                        //֮ǰ���͸���Ϣ������Ϣ����CreateWindow��CreateWindowEx��������֮ǰ���͡�
                        for(i=1;i<H;i++) //��ʼ��״̬����������״̬��ʼ��Ϊ1
                            board[i][0].var=board[i][W-1].var=1;
                        for(j=1;j<W-1;j++) //����ײ�״̬��1
                            board[H-1][j].var=1;
                        for(i=1;i<H-1;i++) //����Ϸ����״̬��0
                            for(j=1;j<W-1;j++)
                            {
                                board[i][j].var=0;
                                board[i][j].color=BgColor;
                            }
                        srand((unsigned)time(NULL)); //��ʼ�������������
                        cur_boxnum=rand()%19; //����ֵ
                        next_boxnum=rand()%19; //����ֵ
                        x=Cur_x; //��ʼ�����������
                        y=Cur_y; //��ʼ������������
                        return 0; //ֱ���˳����ڹ��̺���
        case WM_PAINT: //���ƽ��棬��Ӧ�ó�������UpdateWindowˢ�´���ʱ����һ�η��͸���Ϣ
                        hdc=BeginPaint(hwnd,&ps); //��DC�������ֵ
                        Paint(hdc,hpen); //����Paint�������ƽ���
                        ShowScore(hdc); //��ʾ����
                        ShowLevel(hdc); //��ʾ�ȼ�
                        ShowHelp(hdc); //��ʾ������
                        ShowBox(hdc,hpen,x,y,cur_boxnum); //��ʾ��Ϸ�����е���Ϸ����
                        ShowBox(hdc,hpen,W+1,1,next_boxnum); //��ʾ�ұ�״̬������Ϸ����
                        EndPaint(hwnd,&ps); //EndPaint�������ָ�����ڵĻ滭���̽��������������ÿ�ε���BeginPaint����֮�����󣬵������ڻ滭����Ժ�
                        return 0;
        case WM_TIMER: //��ʱ����Ϣ��ÿ0.5����ܵ�һ��
                        hdc=GetDC(hwnd); //�ú�������һָ�����ڵĿͻ������������Ļ����ʾ�豸�����Ļ����ľ�����Ժ������GDI������ʹ�øþ�������豸�����Ļ����л�ͼ��
                        y++; //y��1
                        if(CanMove()) //������ƶ��������ԭ��λ�÷��飬��ʾ��λ�÷��飬�൱���Ƿ�������
                        {
                            EraseBox(hdc,hpen,x,y-1,cur_boxnum);
                            ShowBox(hdc,hpen,x,y,cur_boxnum);
                        }
                        else //��������ƶ����򵽵��ˣ�y�ָ�֮ǰ��ֵ��������MS_NEWBLOCK�����µķ���
                        {
                            y--;
                            SendMessage(hwnd,MS_NEWBLOCK,0,0);
                        }

                        ReleaseDC(hwnd,hdc); //���ͷ��豸�����Ļ�����DC��������Ӧ�ó���ʹ��
                        return 0;
        case WM_KEYDOWN: //�����¼�ʱ���ᷢ�͸���Ϣ
                        hdc=GetDC(hwnd);
                        switch((int)wParam) //�жϾ��尴�µļ�
                        {
                            case VK_UP:
                                        old_boxnum=cur_boxnum; //���浱ǰ�����
                                        cur_boxnum=block[cur_boxnum].next; //����ű�Ϊ��һ�������
                                        if(CanMove())
                                        {
                                            EraseBox(hdc,hpen,x,y,old_boxnum);
                                            ShowBox(hdc,hpen,x,y,cur_boxnum);
                                        }
                                        else
                                            cur_boxnum=old_boxnum; //�ָ�֮ǰ��ֵ
                                        break;
                            case VK_DOWN:
                                        y++;
                                        if(CanMove())
                                        {
                                            EraseBox(hdc,hpen,x,y-1,cur_boxnum);
                                            ShowBox(hdc,hpen,x,y,cur_boxnum);
                                        }
                                        else
                                        {
                                            y--;
                                            SendMessage(hwnd,MS_NEWBLOCK,0,0); //�������ƣ��͵����ˣ������µķ���
                                        }
                                        break;
                            case VK_LEFT:
                                        x--; //�������С1
                                        if(CanMove()) //������ƶ��������ƣ������ƶ���ָ�֮ǰ����
                                        {
                                            EraseBox(hdc,hpen,x+1,y,cur_boxnum);
                                            ShowBox(hdc,hpen,x,y,cur_boxnum);
                                        }
                                        else
                                            x++;
                                        break;
                            case VK_RIGHT: //ͬ��
                                        x++;
                                        if(CanMove())
                                        {
                                            EraseBox(hdc,hpen,x-1,y,cur_boxnum);
                                            ShowBox(hdc,hpen,x,y,cur_boxnum);
                                        }
                                        else
                                            x--;
                                        break;
                        }

                        ReleaseDC(hwnd,hdc);
                        return 0;
        case MS_NEWBLOCK:
                        hdc=GetDC(hwnd);
                        if(top>y+block[cur_boxnum].a[0][1])
                            top=y+block[cur_boxnum].a[0][1]; //ȷ����ߵ�
                        ChangeVar(); //�ı���Ϸ����״̬
                        SetFullRow(hdc,hpen); //���д���
                        cur_boxnum=next_boxnum;
                        x=Cur_x; //���÷�������
                        y=Cur_y;
                        hpen=CreatePen(PS_SOLID,1,FgColor);
                        srand((unsigned)time(NULL)); //��ʼ�������������
                        next_boxnum=rand()%19;
                        EraseBox(hdc,hpen,W+1,1,cur_boxnum); //����ұ�״̬���ķ���
                        ShowBox(hdc,hpen,W+1,1,next_boxnum); //��ʾ�ұ�״̬���ķ���
                        ShowBox(hdc,hpen,Cur_x,Cur_y,cur_boxnum); //��ʾ��Ϸ���嶥������

                        if(!CanMove()) //���ƿ�ʼ�Ͳ����ƶ�������������˳�
                        {
                            KillTimer(hwnd,1);
                            MessageBox(hwnd,"  �˳���Ϸ","�˳�",MB_OK);
                            PostQuitMessage(0);
                        }

                        ReleaseDC(hwnd,hdc);
                        return 0;
        case WM_DESTROY: //�˳���Ϸ
                        KillTimer(hwnd,1);
                        PostQuitMessage(0);
                        return 0;
    }
    return DefWindowProc(hwnd,iMsg,wParam,lParam); //����Ĭ�ϴ�������Ϣ������δ������Ϣʱ�͵��øú������д���
}
