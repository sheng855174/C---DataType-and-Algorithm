//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <time.h>
#include <stdlib.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int **graph;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        srand(time(NULL));
        Memo1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Memo1->Clear();
        int weightsRange = StrToInt(Edit2->Text);
        int weightsJudge = StrToInt(Edit3->Text);
        int v = StrToInt(Edit1->Text);
        const int maxInt = StrToInt(Edit4->Text);
        graph = new int*[v];
        for(int i=0;i<v;i++)
        {
            graph[i] = new int[v];
        }
        if(CheckBox1->Checked == true)
        {
            StringGrid1->RowCount = v;
            StringGrid1->ColCount = v;
        }
        if(RadioButton2->Checked == true)
        {
            for(int i=0;i<v;i++)
            {
                for(int j=0+i;j<v;j++)
                {
                    if(i==j)
                    {
                        graph[i][j] = maxInt;
                    }
                    else
                    {
                        int random = rand()%weightsRange+1;
                        if(random > weightsJudge)
                        {
                            graph[i][j] = maxInt;
                            graph[j][i] = maxInt;
                        }
                        else
                        {
                            graph[i][j] = random;
                            graph[j][i] = random;
                        }
                    }
                    if(CheckBox1->Checked == true)
                    {
                        StringGrid1->Cells[j][i] = IntToStr(graph[i][j]);
                        StringGrid1->Cells[i][j] = IntToStr(graph[j][i]);
                    }
                }
            }
        }
        if(RadioButton1->Checked == true)
        {
            for(int i=0;i<v;i++)
            {
                for(int j=0;j<v;j++)
                {
                     int random = rand()%weightsRange+1;
                     if(random > weightsJudge)
                     {
                         graph[i][j] = maxInt;
                     }
                     else
                     {
                         graph[i][j] = random;
                     }
                     if(CheckBox1->Checked == true)
                     {
                        StringGrid1->Cells[j][i] = IntToStr(graph[i][j]);
                     }
                }
            }
        }
        Memo1->Lines->Add("畫圖成功");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    StringGrid1->Canvas->FillRect(Rect);
    DrawText(StringGrid1->Canvas->Handle,
    StringGrid1->Cells[ACol][ARow].c_str(),
    StringGrid1->Cells[ACol][ARow].Length(),
    &Rect,DT_VCENTER | DT_SINGLELINE | DT_CENTER);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Memo1->Clear();
        Memo1->Lines->Add("Source最短路徑:");
        int *distance;
        int *found;
        int v = StrToInt(Edit1->Text);
        int source = StrToInt(Edit5->Text);
        String *output;
        distance = new int[v];
        found = new int[v];
        output = new String[v];
        for(int i=0;i<v;i++)
        {
            found[i] = false;
            distance[i] = graph[source][i];
            output[i]=IntToStr(source)+"->";
        }
        found[source] = true;
        for(int i=0;i<v;i++)
        {
            int min = source;
            int k = 0;
            for(int j=0;j<v;j++)
            {
                if(found[j])
                {
                    continue;
                }
                if(distance[j]<distance[min])
                {
                    min = j;
                }
            }
            k = distance[min];
            found[min] = true;
            for(int j=0;j<v;j++)
            {
                if((k+graph[min][j])<distance[j] && !found[j])
                {
                    distance[j] = (k+graph[min][j]);
                    output[j]+=IntToStr(min)+"->";
                }
            }
        }
        if(CheckBox2->Checked == true)
        {
            for(int i=0;i<v;i++)
            {
                output[i] += IntToStr(i) + ":" + IntToStr(distance[i]);
                Memo1->Lines->Add(output[i]);
           }
        }
        Memo1->Lines->Add("最短路徑找到!!");
        delete[] distance;
        delete[] found;
        delete[] output;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Memo1->Clear();
        Memo1->Lines->Add("所有最短路徑:");
        int *distance;
        int *found;
        int v = StrToInt(Edit1->Text);
        int source = StrToInt(Edit5->Text);
        String *output;
        distance = new int[v];
        found = new int[v];
        output = new String[v];
        for(int h=0;h<v;h++)
        {
            source = h;
            for(int i=0;i<v;i++)
            {
                found[i] = false;
                distance[i] = graph[source][i];
                output[i]=IntToStr(source)+"->";
            }
            found[source] = true;
            for(int i=0;i<v;i++)
            {
                int min = source;
                int k = 0;
                for(int j=0;j<v;j++)
                {
                    if(found[j])
                    {
                        continue;
                    }
                    if(distance[j] < distance[min])
                    {
                        min = j;
                    }
                }
                if(min == source) break;
                k = distance[min];
                found[min] = true;
                for(int j=0;j<v;j++)
                {
                    if((k+graph[min][j])<distance[j] && !found[j])
                    {
                        distance[j] = (k+graph[min][j]);
                        output[j]+=IntToStr(min)+"->";
                    }
                }
            }
            if(CheckBox2->Checked == true)
            {
                for(int i=0;i<v;i++)
                {
                    output[i] += IntToStr(i) + ":" + IntToStr(distance[i]);
                    Memo1->Lines->Add(output[i]);
                }
            }
        }
        Memo1->Lines->Add("最短路徑找到!!");
        delete[] distance;
        delete[] found;
        delete[] output;
}
//---------------------------------------------------------------------------





void __fastcall TForm1::Button4Click(TObject *Sender)
{
        int v = StrToInt(Edit1->Text);
        int maxsize = StrToInt(Edit4->Text);
        if(CheckBox1->Checked == true)
        {
            StringGrid2->RowCount = v;
            StringGrid2->ColCount = v;
        }
        if(CheckBox1->Checked == true)
        {
            for(int k=0;k<v;k++)
            {
                for(int i=0;i<v;i++)
                {
                    for(int j=0;j<v;j++)
                    {
                        int a=1,b=1,c=1;
                        if(graph[i][j] == maxsize) a = 0;
                        if(graph[i][k] == maxsize) b = 0;
                        if(graph[k][j] == maxsize) c = 0;
                        StringGrid2->Cells[j][i] = IntToStr(a || (b && c));
                    }
                }
            }
        }
        Memo1->Lines->Add("畫圖成功");
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid2DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
    StringGrid2->Canvas->FillRect(Rect);
    DrawText(StringGrid2->Canvas->Handle,
    StringGrid2->Cells[ACol][ARow].c_str(),
    StringGrid2->Cells[ACol][ARow].Length(),
    &Rect,DT_VCENTER | DT_SINGLELINE | DT_CENTER);
}
//---------------------------------------------------------------------------

