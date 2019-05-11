//---------------------------------------------------------------------------
#include <time.h>
#include <cstdlib>
#include <vcl.h>
#pragma hdrstop

#include "HW1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
bool bStart=false;
int n,range;
int *number;
double bubbletime=0;
double selecttime=0;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        if(bStart) delete []number;
        srand(time(NULL));
        Memo1->Clear();
        n=Edit1->Text.ToInt();
        range=Edit2->Text.ToInt();
        number=new int [n];
        for(int i=0;i<n;i++){
                number[i]=rand()%range+1;
                if(!CheckBox1->Checked){
                  Memo1->Lines->Add("number["+IntToStr(i)+"]="+IntToStr(number[i]));
                }
        }
        Memo1->Lines->Add("已產生" + IntToStr(n) + "個亂數");
        bStart=true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Memo2->Clear();
        int *tmpNumber;
        tmpNumber=new int [n];
        for(int i=0;i<n;i++){
                tmpNumber[i]=number[i];
        }
        clock_t start = clock();
        for(int i=0;i<n;i++){
                for(int j=i+1;j<n;j++){
                        if(tmpNumber[i]>tmpNumber[j]){
                                int tmp=tmpNumber[i];
                                tmpNumber[i]=tmpNumber[j];
                                tmpNumber[j]=tmp;
                        }
                }
        }
        clock_t end = clock();
        bubbletime =(double)(end-start)/CLK_TCK;
        Memo4->Clear();
        Memo4->Lines->Add("泡沫排序CPU時間=" + FloatToStr(bubbletime) + "s");
        for(int i=0;i<n;i++){
                if(!CheckBox1->Checked){
                  Memo2->Lines->Add("number["+IntToStr(i)+"]="+IntToStr(tmpNumber[i]));
                }
        }
        Memo2->Lines->Add("泡沫排序" + FloatToStr(bubbletime) + "秒...");
        delete []tmpNumber;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Memo3->Clear();
        int *tmpNumber;
        tmpNumber=new int [n];
        for(int i=0;i<n;i++){
                tmpNumber[i]=number[i];
        }
        clock_t start = clock();
        for(int i=0;i<n;i++){
                int min=i;
                for(int j=i+1;j<n;j++){
                        if(tmpNumber[min]>tmpNumber[j]){
                                min=j;
                        }
                }
                int tmp=tmpNumber[i];
                tmpNumber[i]=tmpNumber[min];
                tmpNumber[min]=tmp;

        }
        clock_t end = clock();
        selecttime =(double)(end-start)/CLK_TCK;
        Memo4->Clear();
        Memo4->Lines->Add("選擇排序CPU時間=" + FloatToStr(selecttime) + "s");
        for(int i=0;i<n;i++){
                if(!CheckBox1->Checked){
                  Memo3->Lines->Add("number["+IntToStr(i)+"]="+IntToStr(tmpNumber[i]));
                }
        }
        Memo3->Lines->Add("選擇排序" + FloatToStr(selecttime) + "秒...");
        delete []tmpNumber;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
          Chart1->RemoveAllSeries();
          Chart1->Title->Text->Clear();
          Chart1->Title->Text->Add("泡沫和選擇排序CPU比較");
          Chart1->BottomAxis->Title->Caption = "Data Number";
          Chart1->LeftAxis->Title->Caption = "CPU Time(s)";
          for (int i=0;i<2;i++){
                TLineSeries *Series=new TLineSeries(Chart1);
                Series->ParentChart=Chart1;
                Chart1->AddSeries(Series);
          }
          Chart1->Series[0]->Title =  "泡沫排序";
          Chart1->Series[1]->Title =  "選擇排序";
          for (int i=0; i<n; i=i+Edit3->Text.ToInt()){

                int *tmpNumber;
                tmpNumber=new int [n];
                for(int h=0;h<i;h++){
                        tmpNumber[h]=number[h];
                }
                clock_t start = clock();
                for(int h=0;h<i;h++){
                        for(int j=h+1;j<i;j++){
                                if(tmpNumber[h]>tmpNumber[j]){
                                        int tmp=tmpNumber[h];
                                        tmpNumber[h]=tmpNumber[j];
                                        tmpNumber[j]=tmp;
                                }
                        }
                }
                clock_t end = clock();
                bubbletime =(double)(end-start)/CLK_TCK;
                delete []tmpNumber;

                int *tmpNumber2;
                tmpNumber2=new int [i];
                for(int h=0;h<i;h++){
                        tmpNumber2[h]=number[h];
                }
                clock_t start2 = clock();
                for(int h=0;h<i;h++){
                        int min=h;
                        for(int j=h+1;j<i;j++){
                                if(tmpNumber2[min]>tmpNumber2[j]){
                                min=j;
                        }
                }
                int tmp=tmpNumber2[h];
                tmpNumber2[h]=tmpNumber2[min];
                tmpNumber2[min]=tmp;
                }
                clock_t end2 = clock();
                selecttime =(double)(end2-start2)/CLK_TCK;
                delete []tmpNumber2;
                Chart1->Series[0]->Add( bubbletime , i , clBlue );
                Chart1->Series[1]->Add( selecttime , i , clRed );
          }

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button5Click(TObject *Sender)
{
        int *tmpNumber;
        int  target=Edit4->Text.ToInt();
        int lower=0;
        int upper=n-1;
        bool ans=false;
        tmpNumber=new int [n];
        for(int i=0;i<n;i++){
                tmpNumber[i]=number[i];
        }
        for(int i=0;i<n;i++){
                int min=i;
                for(int j=i+1;j<n;j++){
                        if(tmpNumber[min]>tmpNumber[j]){
                                min=j;
                        }
                }
                int tmp=tmpNumber[i];
                tmpNumber[i]=tmpNumber[min];
                tmpNumber[min]=tmp;

        }
        while(upper>=lower){
                int mid=(lower+upper)/2;
                if(tmpNumber[mid] == target){
                        Memo1->Lines->Add("number[" + IntToStr(mid) + "]=" + IntToStr(target));
                        ans=true;
                        break;
                }
                else{
                        if(tmpNumber[mid]<target){
                                lower=mid+1;
                        }
                        else{
                                upper=mid-1;
                        }
                }
        }
        if(!ans) Memo1->Lines->Add("沒有此目標");
        delete []tmpNumber;
}
//---------------------------------------------------------------------------

