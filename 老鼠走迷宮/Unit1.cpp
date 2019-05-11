#include <stdio.h>
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
enum directions {N=0,NE,E,SE,S,SW,W,NW};
class offset
{
        private:
                int dx;
                int dy;
        public:
                void setDx(int dx);
                void setDy(int dy);
                int getDx(void);
                int getDy(void);
};
void offset::setDx(int dx)
{
        this->dx=dx;
}
void offset::setDy(int dy)
{
        this->dy=dy;
}
int offset::getDx(void)
{
        return dx;
}
int offset::getDy(void)
{
        return dy;
}
class position
{
        private:
                int x;
                int y;
                directions dir;
        public:
                void setX(int x);
                void setY(int y);
                void setDir(directions dir);
                int getX(void);
                int getY(void);
                directions getDir(void);
};
void position::setX(int x)
{
        this->x=x;
}
void position::setY(int y)
{
        this->y=y;
}
void position::setDir(directions dir)
{
        this->dir=dir;
}
int position::getX(void)
{
        return x;
}
int position::getY(void)
{
        return y;
}
directions position::getDir(void)
{
        return dir;
}
//---------------------------------------------------------------------------
const int possible_direction=8;
const int max=1000;//stack max and mark max/10
int **maze;
int mark[max/10][max/10];
int map[max/10][max/10];
int m,n;//m is height,n is width
int top=-1;
offset move[possible_direction];
position stack[max];
void setDirection()
{
        move[N].setDx(-1);move[N].setDy(0);
        move[NE].setDx(-1);move[NE].setDy(1);
        move[E].setDx(0);move[E].setDy(1);
        move[SE].setDx(1);move[SE].setDy(1);
        move[S].setDx(1);move[S].setDy(0);
        move[SW].setDx(1);move[SW].setDy(-1);
        move[W].setDx(0);move[W].setDy(-1);
        move[NW].setDx(-1);move[NW].setDy(-1);
}
void setMark()
{
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        mark[i][j]=maze[i][j];
                        map[i][j]=maze[i][j];
                }
        }
}
void push(position data)
{
        if(top==max)
        {
                Form1->Memo1->Lines->Add("超過堆疊最大值");
        }
        else
        {
                stack[++top]=data;
        }
}
position pop(void)
{
        if(top==-1)
        {
                Form1->Memo1->Lines->Add("堆疊已經沒有東西了");
                return stack[0];
        }
        return stack[top--];
}
void generateMaze(int x,int y)
{
        maze[x][y]=0;
        while(maze[x+2][y]==1 || maze[x-2][y]==1 ||
              maze[x][y+2]==1 || maze[x][y-2]==1)
        {
                int dir=rand()%4+1;
                if(dir==1 && maze[x+2][y]==1)
                {
                        maze[x+1][y]=0;
                        generateMaze(x+2,y);
                }
                else if(dir==2 && maze[x-2][y]==1)
                {
                        maze[x-1][y]=0;
                        generateMaze(x-2,y);
                }
                else if(dir==3 && maze[x][y+2]==1)
                {
                        maze[x][y+1]=0;
                        generateMaze(x,y+2);
                }
                else if(dir==4 && maze[x][y-2]==1)
                {
                        maze[x][y-1]=0;
                        generateMaze(x,y-2);
                }
        }
}
void randMaze()
{
        m=StrToInt(Form1->Edit1->Text)+2;
        n=StrToInt(Form1->Edit2->Text)+2;
        maze=new int*[m+2];
        for(int i=0;i<m+2;i++)
        {
                maze[i]=new int [n+2];
        }
        for (int i=0;i<m+2;i++)
        {
                for (int j=0;j<n+2;j++)
                {
                        if (i==0 || j==0 || i==m || j==n ||
                            i==1 || j==1 || i==m+1 || j==n+1)
                        {
                                maze[i][j]=2;
                        }
                        else
                        {
                                maze[i][j] = 1;
                        }
                }
        }
        generateMaze(m-1,n-1);
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        maze[i][j]=maze[i+1][j+1];
                }
        }
        maze[1][0]=0;//start
        maze[1][1]=0;
        int r1=rand()%2+1;
        int r2;
        if(r1==1) r2=2;
        else r2=1;
        maze[r1][r2]=0;
        maze[m-2][n-1]=0;//end
        setMark();
}
void readFile()
{
        if(Form1->OpenDialog1->Execute())
        {
                FILE *fp;
                fp=fopen(Form1->OpenDialog1->FileName.c_str(),"r+");
                fscanf(fp,"%d %d",&m,&n);
                m=m+2;
                n=n+2;
                maze=new int* [m];
                for(int i=0;i<m;i++) maze[i]=new int [n];
                for(int i=1;i<m-1;i++)
                {
                        for(int j=1;j<n-1;j++)
                        {
                                fscanf(fp,"%d ",&maze[i][j]);
                        }
                }
                for(int i=0;i<m;i++)
                {
                        for(int j=0;j<n;j++)
                        {
                                if(i==0 || j==0 || i==m-1 || j==n-1)
                                {
                                        maze[i][j]=2;
                                }
                        }
                }
                maze[1][0]=0;//start
                maze[1][1]=0;//start
                maze[m-2][n-1]=0;//end
                setMark();
                fclose(fp);
        }
        else  Form1->Memo1->Lines->Add("讀檔失敗");
}
void saveFile()
{
        if(Form1->SaveDialog1->Execute())
        {
                FILE *fp;
                String name=Form1->SaveDialog1->FileName+".txt";
                fp=fopen(name.c_str(),"w");
                fprintf(fp,"%d %d\n",m-2,n-2);
                for(int i=1;i<m-1;i++)
                {
                        for(int j=1;j<n-1;j++)
                        {
                                if(maze[i][j]==3)
                                {
                                        int tmp=0;
                                        fprintf(fp,"%d ",tmp);
                                }
                                else
                                {
                                        fprintf(fp,"%d ",maze[i][j]);
                                }
                        }
                         fprintf(fp,"\n");
                }
                fclose(fp);
        }
        else  Form1->Memo1->Lines->Add("存檔失敗");
}
int pathMaze()
{      
        int delay=(Form1->TrackBar1->Position)*20;
        position data;
        top=-1;
        data.setX(1);
        data.setY(0);
        data.setDir(N);
        maze[1][0]=3;
        push(data);
        bool into=false;
        while(top>-1)
        {
                if(Form1->CheckBox1->Checked)
                {
                        if(into==false)
                        {
                                Sleep(delay);
                                Form1->StringGrid2->Cells[data.getY()][data.getX()]="＠";
                                Form1->StringGrid2->Refresh();
                        }
                        else
                        {
                                Sleep(delay);
                                Form1->StringGrid2->Cells[data.getY()][data.getX()]="。";
                                Form1->StringGrid2->Refresh();
                        }
                }
                data=pop();
                directions d=N;
                while(d<=NW)
                {
                        int u=data.getX()+move[d].getDx();
                        int v=data.getY()+move[d].getDy();
                        if(u==m-2 && v==n-1)//終點
                        {
                                maze[u][v]=3;
                                push(data);
                                if(Form1->CheckBox1->Checked)
                                {
                                        Sleep(delay);
                                        Form1->StringGrid2->Cells[data.getY()][data.getX()]="＠";
                                        Form1->StringGrid2->Refresh();
                                }
                                data.setX(u);
                                data.setY(v);
                                data.setDir(d);
                                push(data);
                                if(Form1->CheckBox1->Checked)
                                {
                                        Sleep(delay);
                                        Form1->StringGrid2->Cells[data.getY()][data.getX()]="＠";
                                        Form1->StringGrid2->Refresh();
                                }
                                return 1;
                        }
                        else if(maze[u][v]==0)
                        {
                                maze[u][v]=3;
                                if(into==true)
                                {
                                        if(Form1->CheckBox1->Checked)
                                        {
                                                Sleep(delay);
                                                Form1->StringGrid2->Cells[data.getY()][data.getX()]="＠";
                                                Form1->StringGrid2->Refresh();
                                        }
                                        push(data);
                                }
                                into=true;
                                data.setX(u);
                                data.setY(v);
                                data.setDir(d);
                                d=N;
                        }
                        else
                        {
                                d=d+1;
                        }
                }
        }
        return -1;
}
void printMemo()
{
        Form1->Memo1->Lines->Add("m=" + IntToStr(m-2));
        Form1->Memo1->Lines->Add("n=" + IntToStr(n-2));
        for(int i=0;i<m;i++)
        {
                String out="";
                for(int j=0;j<n;j++)
                {
                        out+=IntToStr(maze[i][j]) + " ";

                }
                Form1->Memo1->Lines->Add(out);
        }
}
void printMark()
{
        mark[1][0]=3;
        for(int i=0;i<=top;i++)
        {
                mark[stack[i].getX()][stack[i].getY()]=3;
        }
        for(int i=0;i<m;i++)
        {
                String out="";
                for(int j=0;j<n;j++)
                {
                        out+=IntToStr(mark[i][j]) + " ";

                }
                Form1->Memo1->Lines->Add(out);
        }
}
void printStack()
{
        String s="";
        for(int i=0;i<=top;i++)
        {
                position data=stack[i];
                String d[8]={"N","NE","E","SE","S","SW","W","NW"};
                s+="("+IntToStr(data.getY())+","+IntToStr(data.getX())+","+ d[data.getDir()] +")->";
        }
        Form1->Memo1->Lines->Add(s);
}
void seekMazeGrid1()
{
        Form1->StringGrid1->RowCount = m;
        Form1->StringGrid1->ColCount = n;
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        if(mark[i][j]==3)
                        {
                                Form1->StringGrid1->Cells[j][i] ="＠";
                        }
                        else if(maze[i][j]==3 && mark[i][j]!=3)
                        {
                                Form1->StringGrid1->Cells[j][i] ="。";
                        }
                }
        }
        Form1->StringGrid1->Refresh();
}
void printStringGrid1()
{
        Form1->StringGrid1->RowCount = m;
        Form1->StringGrid1->ColCount = n;
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        Form1->StringGrid1->Cells[j][i] = maze[i][j];
                }
        }
        Form1->StringGrid1->Refresh();
}
void printStringGrid2()
{
        Form1->StringGrid2->RowCount = m;
        Form1->StringGrid2->ColCount = n;
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        Form1->StringGrid2->Cells[j][i] = maze[i][j];
                }
        }
        Form1->StringGrid2->Refresh();
}
void printDrawGrid1()
{
        Form1->DrawGrid1->DoubleBuffered=true;
        Form1->DrawGrid1->ColCount=n;
        Form1->DrawGrid1->RowCount=m;
        Form1->Image1->Picture->LoadFromFile("Wall.bmp");
        Form1->Image2->Picture->LoadFromFile("Flame.bmp");
        Form1->Image3->Picture->LoadFromFile("mouse.bmp");
        Form1->Image4->Picture->LoadFromFile("food.bmp");
        Form1->DrawGrid1->Refresh();
}
void deleteMaze()
{
        for(int i= 0;i<m;i++)
        {
                delete[] maze[i];
        }
        delete[] maze;
}

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        deleteMaze();
        Form1->Memo1->Clear();
        srand(time(NULL));
        readFile();
        setDirection();
        printMemo();
        printStringGrid1();
        printStringGrid2();
        printDrawGrid1();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        deleteMaze();
        srand(time(NULL));
        Form1->Memo1->Clear();
        setDirection();
        randMaze();
        printMemo();
        printStringGrid1();
        printStringGrid2();
        printDrawGrid1();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
        AnsiString text = StringGrid1->Cells[ACol][ARow];
        if (text == "2")
        {
                StringGrid1->Canvas->Brush->Color = (RGB(0,0,0));
                StringGrid1->Canvas->Font->Color = RGB(0,0,0);
        }
        else if(text == "1")
        {
                StringGrid1->Canvas->Brush->Color = (RGB(119,136,153));
                StringGrid1->Canvas->Font->Color = (RGB(119,136,153));
        }
        else if(text == "＠")
        {
                StringGrid1->Canvas->Brush->Color = (RGB(0, 255, 0));
        }
        else if(text == "。")
        {
                StringGrid1->Canvas->Brush->Color = (RGB(127,255,212));
        }
        else if(text == "0")
        {
                StringGrid1->Canvas->Font->Color = (RGB(255, 255, 0));
        }
        StringGrid1->Canvas->FillRect(Rect);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        if(pathMaze()==1)
        {
                Memo1->Lines->Add("-----------------------");
                Memo1->Lines->Add("找到出口了!");
                printStack();
        }
        else
        {
                Memo1->Lines->Add("-----------------------");
                Memo1->Lines->Add("沒有出口...");
                printStack();
        }
        printMark();
        seekMazeGrid1();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        saveFile();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid2DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
        AnsiString text = StringGrid2->Cells[ACol][ARow];
        if (text == "2")
        {
                StringGrid2->Canvas->Brush->Color = (RGB(0, 0, 0));
                StringGrid2->Canvas->Font->Color = RGB(0, 0, 0);
        }
        else if(text == "1")
        {
                StringGrid2->Canvas->Brush->Color = (RGB(0, 0, 0));
                StringGrid2->Canvas->Font->Color = (RGB(0, 0, 0));
        }
        else if(text == "＠")
        {
                StringGrid2->Canvas->Font->Color = (RGB(255,0,0));
        }
        else if(text == "。")
        {
                StringGrid2->Canvas->Font->Color = (RGB(255,99,71));
        }
        else if(text == "0")
        {
                StringGrid2->Canvas->Font->Color = (RGB(244, 247, 252));
        }
        StringGrid2->Canvas->TextRect(Rect, Rect.Left+15, Rect.Top+15, text);
}
//---------------------------------------------------------------------------

int u,v;
void __fastcall TForm1::DrawGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
        Graphics::TBitmap *bmp_temp=new Graphics::TBitmap;
        for(int i=0;i<m;i++)
        {
                for(int j=0;j<n;j++)
                {
                        TRect R1;
                        R1.left=0;
                        R1.top =0;
                        R1.right=25;
                        R1.bottom =25;
                        if(map[i][j]==2)
                        {
                                bmp_temp=Form1->Image1->Picture->Bitmap;
                                Form1->DrawGrid1->Canvas->CopyRect(Form1->DrawGrid1->CellRect(j,i), bmp_temp->Canvas,R1);
                        }
                        else if(map[i][j]==1)
                        {
                                bmp_temp=Form1->Image2->Picture->Bitmap;
                                Form1->DrawGrid1->Canvas->CopyRect(Form1->DrawGrid1->CellRect(j,i), bmp_temp->Canvas,R1);
                        }
                        else if (i==m-2 && j==n-1)
                        {
                                bmp_temp=Form1->Image4->Picture->Bitmap;
                                Form1->DrawGrid1->Canvas->CopyRect(Form1->DrawGrid1->CellRect(j,i), bmp_temp->Canvas,R1);
                        }
                        else if(map[i][j]==3)
                        {
                                bmp_temp=Form1->Image3->Picture->Bitmap;
                                Form1->DrawGrid1->Canvas->CopyRect(Form1->DrawGrid1->CellRect(j,i), bmp_temp->Canvas,R1);
                        }
                        else if(u==m-2 && v==n-1)
                        {
                                ShowMessage("恭喜過關!!!");
                                map[u][v]=0;u=1;v=0;
                                MediaPlayer1->Close();
                        }
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::DrawGrid1KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        switch(Key)
        {
                 case VK_LEFT:
                        if(map[u][v-1]==0 && v>0)
                        {
                                map[u][v]=0;
                                v=v-1;
                                map[u][v]=3;
                                DrawGrid1->Refresh();
                        }
                 break;

                 case VK_RIGHT:
                        if(map[u][v+1]==0 && v<n)
                        {
                                map[u][v]=0;
                                v=v+1;
                                map[u][v]=3;
                                DrawGrid1->Refresh();
                        }
                 break;

                 case VK_UP:
                        if(map[u-1][v]==0 && u>0)
                        {
                                map[u][v]=0;
                                u=u-1;
                                map[u][v]=3;
                                DrawGrid1->Refresh();
                        }
                 break;

                 case VK_DOWN:
                        if(map[u+1][v]==0 && u<m)
                        {
                                map[u][v]=0;
                                u=u+1;
                                map[u][v]=3;
                                DrawGrid1->Refresh();
                        }
                 break;
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
        MediaPlayer1->FileName="music.mp3";
        MediaPlayer1->Open();
        MediaPlayer1->Play();
        u=1;v=0;
        map[u][v]=3;
        DrawGrid1->Refresh();
}
//---------------------------------------------------------------------------


