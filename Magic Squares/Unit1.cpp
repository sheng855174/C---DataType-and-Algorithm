//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
int const space=6;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void clear()
{
        Form1->Memo1->Clear();
        Form1->Memo2->Clear();
        Form1->Memo3->Clear();
        Form1->Memo4->Clear();
}
void swap(int &a,int &b)
{
        int tmp=a;a=b;b=tmp;
}
void magicSquares1(int **magic,int n)
{
        int x=n/2;
        int y=0;
        magic[y][x]=1;
        for(int i=2;i<=n*n;i++){//计
                x--;if(x<0) x=n-1;
                y--;if(y<0) y=n-1;
                if(magic[y][x]!=0){
                        x++;if(x==n) x=0;
                        y++;if(y==n) y=0;
                        y++;if(y==n) y=0;
                }
                magic[y][x]=i;
        }
}
void magicSquares2(int **magic,int n)
{
        int x=n/2;
        int y=0;
        magic[y][x]=1;
        for(int i=2;i<=n*n;i++){//计
                x++;if(x>n-1) x=0;
                y--;if(y<0) y=n-1;
                if(magic[y][x]!=0){
                        x--;if(x<0) x=n-1;
                        y++;if(y==n) y=0;
                        y++;if(y==n) y=0;
                }
                magic[y][x]=i;
        }
}
void magicSquares3(int **magic,int n)
{
        int x=n/2;
        int y=0;
        magic[y][x]=1;
        for(int i=2;i<=n*n;i++){//计
                x--;if(x<0) x=n-1;
                y++;y=y%n;
                if(magic[y][x]!=0){
                        x++;x=x%n;
                        y--;if(y<0) y=n-1;
                        x++;x=x%n;
                }
                magic[y][x]=i;
        }
}
void magicSquares4(int **magic,int n)
{
        int x=n/2;
        int y=0;
        magic[y][x]=1;
        for(int i=2;i<=n*n;i++){//计
                x++;x=x%n;
                y++;y=y%n;
                if(magic[y][x]!=0){
                        x--;if(x<0) x=n-1;
                        y--;if(y<0) y=n-1;
                        x--;if(x<0) x=n-1;
                }
                magic[y][x]=i;
        }
}
void magicEvenFour(int **magic,int n)
{
        int count=1;
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        magic[i][j]=count;
                        count++;
                }
        }

        //column单
        for(int i=n/4;i<(3*n/4);i++){
                int *tmp;
                int a=0;
                tmp=new int[n];
                for(int j=n-1;j>=0;j--){
                        tmp[a]=magic[i][j];
                        a++;
                }
                for(int j=0;j<n;j++){
                        magic[i][j]=tmp[j];
                }
                delete []tmp;
        }

        //row单
        for(int i=(n/4);i<((3*n)/4);i++){//
                for(int j=0;j<n/4;j++){
                        swap(magic[j][i],magic[n-1-j][i]);
                }
        }
        for(int i=0;i<n/4;i++){//オ
                for(int j=n/4;j<n/2;j++){
                        swap(magic[j][i],magic[n-j-1][i]);
                }
        }
        for(int i=((3*n)/4);i<n;i++){//
                for(int j=n/4;j<n/2;j++){
                        swap(magic[j][i],magic[n-j-1][i]);
                }
        }

}
void magicEven(int **magic,int n)
{
        int **magic3;
        int m=(n-2)/4;
        magic3=new int*[n/2];
        for(int i=0;i<n/2;i++){
                magic3[i]=new int[n/2];
        }
        for(int i=0;i<n/2;i++){
                for(int j=0;j<n/2;j++){
                        magic3[i][j]=0;
                }
        }
        magicSquares1(magic3,n/2);
        for(int i=0;i<n/2;i++){
                int tmp=(n/2)*(n/2);
                for(int j=0;j<n/2;j++){
                        magic[i][j]=magic3[i][j];//オ
                        magic[i+n/2][j+n/2]=magic3[i][j]+tmp;//
                        magic[i][j+n/2]=magic3[i][j]+2*tmp;//
                        magic[i+n/2][j]=magic3[i][j]+3*tmp;//オ
                }
        }
        for(int i=0;i<m;i++){
                for(int j=0;j<n/2;j++){
                        if(j==n/4){}
                        else swap(magic[j][i],magic[j+n/2][i]);
                }
        }
        swap(magic[n/4][n/4],magic[3*n/4][n/4]);
        for(int i=0;i<m-1;i++){
                swap(magic[n/4][n/4-1-i],magic[3*n/4][n/4-1-i]);
        }

        for(int i=0;i<m-1;i++){
                for(int j=0;j<n/2;j++){
                        swap(magic[j][n-1-i],magic[j+n/2][n-1-i]);
                }
        }

        for(int i=0;i<n/2;i++){
                delete [] magic3[i];
        }
        delete[] magic3;

}
void printListBox(int **magic,int n)
{
        for(int i=0;i<n;i++){
                String row="" ;
                for(int j=0;j<n;j++){
                        row+=IntToStr(magic[i][j])+" ";
                }
                Form1->Memo1->Lines->Add(row);
        }
}
void printFixedSpaceBox(int **magic,int n)
{
        for(int i=0;i<n;i++){
                String row="";
                for(int j=0;j<n;j++){
                        int length=IntToStr(magic[i][j]).Length();
                        for(int h=0;h<(space-length);h++) row+=" ";
                        row+=IntToStr(magic[i][j]);
                }
                Form1->Memo2->Lines->Add(row);
        }
}
void printRichBoxTest(int **magic,int n)
{
        String column="";
        int sumOblique1=0;
        int sumOblique2=0;
        for(int i=0;i<n;i++){
                String row="";
                int length=0;
                int sumRow=0;
                int sumColumn=0;
                for(int j=0;j<n;j++){
                        length=IntToStr(magic[i][j]).Length();
                        for(int h=0;h<(space-length);h++) row+=" ";
                        row+=IntToStr(magic[i][j]);
                        sumRow+=magic[i][j];
                        sumColumn+=magic[j][i];
                        if(i==j) sumOblique1+=magic[i][j];
                        if((i+j)==(n-1)) sumOblique2+=magic[i][j];
                }
                length=IntToStr(sumColumn).Length();
                for(int j=0;j<(space-length-1);j++) column+=" ";
                column+="|";
                column+=IntToStr(sumColumn);
                Form1->Memo3->Lines->Add(row + "" + IntToStr(sumRow));
        }
        column+="  /"+IntToStr(sumOblique1)+"  \\"+IntToStr(sumOblique2);
        Form1->Memo3->Lines->Add(column);
}
void printRichBox(int **magic,int n)
{
        for(int i=0;i<n;i++){
                String row="";
                for(int j=0;j<n;j++){
                        int length=IntToStr(magic[i][j]).Length();
                        for(int h=0;h<(space-length);h++) row+=" ";
                        row+=IntToStr(magic[i][j]);
                }
                Form1->Memo4->Lines->Add(row);
        }
}
void dataGridView(int **magic,int n)
{
        Form1->StringGrid1->RowCount=n;
        Form1->StringGrid1->ColCount=n;
        for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                        Form1->StringGrid1->Cells[j][i]=IntToStr(magic[i][j]);
                }
        }
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        clear();
        int n=StrToInt(Edit1->Text);
        int **magic;
        magic = new int* [n];
        for(int i=0;i<n;i++){//n*n皚
                magic[i]= new int [n];
        }
        for(int i=0;i<n;i++){//0
                for(int j=0;j<n;j++){
                        magic[i][j]=0;
                }
        }
        if(n==2){
                Memo1->Lines->Add("礚臸よ皚");
                Memo2->Lines->Add("礚臸よ皚");
                Memo3->Lines->Add("礚臸よ皚");
                Memo4->Lines->Add("礚臸よ皚");
        }
        else if(n%4==0){
                magicEvenFour(magic,n);
        }
        else if(n%2==0){
                magicEven(magic,n);
        }
        else{
                if(RadioButton1->Checked==true) magicSquares1(magic,n);//オ
                else if(RadioButton2->Checked==true) magicSquares2(magic,n);//
                else if(RadioButton3->Checked==true) magicSquares3(magic,n);//オ
                else if(RadioButton4->Checked==true) magicSquares4(magic,n);//
        }

        printListBox(magic,n);//print ListBox  Memo1
        printFixedSpaceBox(magic,n);//print FixedSpaceBox  Memo2
        printRichBoxTest(magic,n);//print RichBoxTest  Memo3
        printRichBox(magic,n);//print RichBox  Memo4
        dataGridView(magic,n);//DataGridView  StringGrid1

        for(int i=0;i<n;i++){//睲埃
                delete [] magic[i];
        }
        delete magic;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::StringGrid1DrawCell(TObject *Sender, int ACol,
      int ARow, TRect &Rect, TGridDrawState State)
{
StringGrid1->Canvas->FillRect(Rect);    // 睲
DrawText(StringGrid1->Canvas->Handle, StringGrid1->Cells[ACol][ARow].c_str(),
StringGrid1->Cells[ACol][ARow].Length(), &Rect, DT_VCENTER | DT_SINGLELINE | DT_CENTER);
}
//---------------------------------------------------------------------------

