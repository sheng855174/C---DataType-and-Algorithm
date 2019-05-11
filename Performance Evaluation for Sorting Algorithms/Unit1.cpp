//---------------------------------------------------------------------------

#include <vcl.h>
#include <time.h>
#include <stdlib.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
class StackNode
{
    public:
    int data;
    StackNode *link;
};
StackNode *top;
int *data;
void swap(int &a,int &b);
void selection_sort(int *data,int index);
void bubble_sort(int *data,int index);
void insertion_sort(int *data,int index);
void quick_recursive_sort(int *data,int left,int right);
void quick_sort(int *data,int index);
StackNode* NewNode(int element);
void push(int element);
int pop();
void merge(int c[],int k,int a[],int i,int m,int b[],int j,int n);
merge_recursive_sort(int a[],int left,int right);
void merge_sort(int *data,int index);
void restore(int s,int t);
void heap_sort(int *data,int index);
void radix_sort(int *data,int index);
void counting_sort(int *data,int index);
void restore(int *data,int s,int t)
{
    while(s<=t/2)
    {
        int j;
        if(data[2*s]<data[2*s+1]) j = 2*s;
        else j = 2*s+1;
        if(data[s]<data[j]) break;
        swap(data[s],data[j]);
        s = j;
    }
}
void merge(int c[],int k,int a[],int i,int m,int b[],int j,int n)
{
    while((i<=m) && (j<=n))
    {
        if(a[i]<=b[j]) c[k++] = a[i++];
        else c[k++] = b[j++];
    }
    while(i<=m) c[k++] = a[i++];
    while(j<=n) c[k++] = b[j++];
}
void push(int element)
{
    StackNode *x;
    x = NewNode(element);
    if(top == NULL) top = x;
    else
    {
        x->link = top;
        top = x;
    }
}
int pop()
{
    StackNode *p;
    if(top==NULL) return NULL;
    else
    {
        p = top;
        top = top->link;
        int data = p->data;
        delete[] p;
        return data;
    }
}
StackNode* NewNode(int element)
{
    StackNode *p = new StackNode;
    if(p==NULL) return NULL;
    p->data = element;
    p->link = NULL;
    return p;
}
void swap(int &a,int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void selection_sort(int *data,int index)
{
    for(int i=0;i<index;i++)
    {
        int min = i;
        for(int j=i+1;j<index;j++)
        {
            if(data[j]<data[min])
            {
                min = j;
            }
        }
        swap(data[i],data[min]);
    }
}
void bubble_sort(int *data,int index)
{
    for(int i=0;i<index;i++)
    {
        for(int j=i+1;j<index;j++)
        {
            if(data[i]>data[j])
            {
                swap(data[i],data[j]);
            }
        }
    }
}
void insertion_sort(int *data,int index)
{
    for(int i=1;i<index;i++)
    {
        int target = data[i];
        int j = i;
        while((j>0) && (data[j-1]>target))
        {
            data[j] = data[j-1];
            j--;
        }
        data[j] = target;
    }
}
void quick_recursive_sort(int *data,int left,int right)
{
    if(left<right)
    {
        int i = left+1;
        int j = right;
        int target = data[left];
        do{
            while(data[i]<target && i<=j) {i++;}
            while(data[j]>=target && i<=j) {j--;}
            if(i<j) swap(data[i],data[j]);
        }while(i<j);
        if(left<j) swap(data[left],data[j]);
        quick_recursive_sort(data,left,j-1);
        quick_recursive_sort(data,j+1,right);
    }
}
void quick_sort(int *data,int index)
{
    int left = 0;
    int right = index-1;
    push(left);
    push(right);
    while(top!=NULL)
    {
        right = pop();
        left = pop();
        int target = data[left];
        int i = left+1;
        int j = right;
        do{
           while(data[i]<target && i<=j) i++;
           while(data[j]>=target && i<=j) j--;
           if(i<j) swap(data[i],data[j]);
        }while(i<j);
        if(left<j) swap(data[left],data[j]);
        if(j+1<right)
        {
            push(j+1);
            push(right);
        }
        if(left<j-1)
        {
            push(left);
            push(j-1);
        }
    }
}
merge_recursive_sort(int a[],int left,int right)
{
    if(left<right)
    {
        int m = (left+right)/2;
        merge_recursive_sort(a,left,m);
        merge_recursive_sort(a,m+1,right);
        int *b = new int[right/2+1];
        int *c = new int[right/2+1];
        int x = 0;
        int y = 0;
        for(int i=left;i<=m;i++)
        {
           b[x++] = a[i];
        }
        for(int i=m+1;i<=right;i++)
        {
           c[y++] = a[i];
        }
        merge(a,left,b,0,x-1,c,0,y-1);
        delete[] b;
        delete[] c;
    }
}
void merge_sort(int *data,int index)
{
    int len = 2;
    while(len<index)
    {
        for(int i=0;i<index;i+=len)
        {
            int *b = new int[index];
            int *c = new int[index];
            int m = 0;
            int n = 0;
            int min = 0;
            for(int j=i;j<=(i+len/2-1);j++) b[m++] = data[j];
            if((i+len-1)<(index-1)) min = (i+len-1);
            else min = index-1;
            for(int j=i+len/2;j<=min;j++) c[n++] = data[j];
            merge(data,i,b,0,m-1,c,0,n-1);
            delete[] b;
            delete[] c;
        }
        len*=2;
    }
    if(len/2<index)
    {
        int *b = new int[index];
        int *c = new int[index];
        int m = 0;
        int n = 0;
        for(int i=0;i<(len/2-1);i++) b[m++] = data[i];
        for(int i=len/2;i<index-1;i++) c[n++] = data[i];
        merge(data,0,b,0,m-1,c,0,n-1);
        delete[] b;
        delete[] c;
    }
}
void heap_sort(int *data,int index)
{
    int *temp = new int[index+1];
    int count = 0;
    for(int i=1;i<=index;i++) temp[i] = data[i-1];
    for(int i=(index-1)/2;i>=1;i--)
    {
        restore(temp,i,index);
    }
    for(int i=index;i>=1;i--)
    {
        data[count++] = temp[1];
        temp[1] = temp[i];
        restore(temp,1,i-1);
    }
    delete[] temp;
}
int maxbit(int data[], int n)
{
    int maxData = data[0];
    for (int i=1;i<n;i++)
    {
        if (maxData < data[i]) maxData = data[i];
    }
    int d = 1;
    int p = 10;
    while (maxData >= p)
    {
        maxData/=10;
        d++;
    }
    return d;
}
void radix_sort(int *data,int n)
{
    int d = maxbit(data, n);
    int *tmp = new int[n];
    int *count = new int[10];
    int i,j,k;
    int radix = 1;
    for(i=1;i<=d;i++)
    {
        for(j=0;j<10;j++)
            count[j] = 0;
        for(j=0;j<n;j++)
        {
            k = (data[j]/radix)%10;
            count[k]++;
        }
        for(j=1;j<10;j++)
            count[j] = count[j-1] + count[j];
        for(j=n-1;j>=0;j--)
        {
            k = (data[j]/radix)%10;
            tmp[count[k]-1] = data[j];
            count[k]--;
        }
        for(j=0;j<n;j++)
            data[j] = tmp[j];
        radix = radix * 10;
    }
    delete []tmp;
    delete []count;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
    srand(time(NULL));
    Memo1->Clear();
    top = NULL;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button1Click(TObject *Sender)
{
    delete[] data;
    int number = StrToInt(Edit1->Text);
    int range = StrToInt(Edit2->Text);
    data = new int[number];
    for(int i=0;i<number;i++)
    {
        data[i] = rand()%range+1;
        if(CheckBox1->Checked)
        {
            Memo1->Lines->Add("data[" + IntToStr(i) + "]=" + IntToStr(data[i]));
        }
    }
    Memo1->Lines->Add("亂數成功!!");
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
    int number = StrToInt(Edit1->Text);
    const int max = 9999999;
    int *temp = new int[number+1];
    float costTime = 0;
    for(int i=0;i<number;i++)
    {
        temp[i] = data[i];
    }
    temp[number] = max;
    if(RadioButton1->Checked)//挑選排序法
    {
        clock_t start = clock();
        selection_sort(temp,number);
        clock_t end = clock();
        costTime = (float)(end - start)/CLK_TCK;
    }
    if(RadioButton2->Checked)//泡沫排序法
    {
        clock_t start = clock();
        bubble_sort(temp,number);
        clock_t end = clock();
        costTime = (float)(end - start)/CLK_TCK;
    }
    if(RadioButton3->Checked)//插入排序法
    {
        clock_t start = clock();
        insertion_sort(temp,number);
        clock_t end = clock();
        costTime = (float)(end - start)/CLK_TCK;
    }
    if(RadioButton4->Checked)//快速排序法遞迴
    {
        clock_t start = clock();
        quick_recursive_sort(temp,0,number-1);
        clock_t end = clock();
        costTime = (float)(end - start)/CLK_TCK;
    }
    if(RadioButton5->Checked)//快速排序法非遞迴
    {
        clock_t start = clock();
        quick_sort(temp,number);
        clock_t end = clock();
        costTime = (float)(end - start)/CLK_TCK;
    }
    if(RadioButton6->Checked)//合併排序法遞迴
    {
        clock_t start = clock();
        merge_recursive_sort(temp,0,number-1);
        clock_t end = clock();
        costTime = (float)(end - start)/CLK_TCK;
    }
    if(RadioButton7->Checked)//合併排序法非遞迴
    {
        clock_t start = clock();
        merge_sort(temp,number);
        clock_t end = clock();
        costTime = (float)(end - start)/CLK_TCK;
    }
    if(RadioButton8->Checked)//堆積排序法
    {
        clock_t start = clock();
        heap_sort(temp,number);
        clock_t end = clock();
        costTime = (float)(end - start)/CLK_TCK;
    }
    if(RadioButton9->Checked)//基數排序法
    {
        clock_t start = clock();
        radix_sort(temp,number);
        clock_t end = clock();
        costTime = (float)(end - start)/CLK_TCK;
    }
    if(CheckBox1->Checked)
    {
        for(int i=0;i<number;i++)
        {
            Memo1->Lines->Add("data[" + IntToStr(i) + "]=" + IntToStr(temp[i]));
        }
    }
    Memo1->Lines->Add("排序成功,排序時間：" + FloatToStr(costTime) + "s");
    delete[] temp;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
    Chart1->RemoveAllSeries();
    Chart1->Title->Text->Clear();
    Chart1->Title->Text->Add("Sorting Alg");
    Chart1->BottomAxis->Title->Caption = "Data";
    Chart1->LeftAxis->Title->Caption = "CPU Time";
    for (int i=1;i<=9;i++)
    {
        TLineSeries *Series=new TLineSeries(Chart1);
        Series->ParentChart=Chart1;
        Chart1->AddSeries(Series);
    }
    int n = this->Edit3->Text.ToInt();
    for (int i=0;i<n;i++)
    {
        int number = StrToInt(Edit1->Text);
        int *temp = new int[number+1];
        int max = 9999999;
        Chart1->Series[0]->Title =  "Selection sort";
        Chart1->Series[1]->Title =  "Bubble sort";
        Chart1->Series[2]->Title =  "Insertion sort";
        Chart1->Series[3]->Title =  "Quick sort(recursive)";
        Chart1->Series[4]->Title =  "Quick Sort";
        Chart1->Series[5]->Title =  "Merge sort(recursive)";
        Chart1->Series[6]->Title =  "Merge sort";
        Chart1->Series[7]->Title =  "Heap sort";
        Chart1->Series[8]->Title =  "Radix sort";
        if(CheckBox2->Checked)
        {
            float costTime = 0;
            for(int i=0;i<number;i++)
            {
                temp[i] = data[i];
            }
            temp[number] = max;
            clock_t start = clock();
            selection_sort(temp,number);
            clock_t end = clock();
            costTime = (float)(end - start)/CLK_TCK;
            Chart1->Series[0]->Add(costTime,i,RGB(255,0,0));
        }
        if(CheckBox3->Checked)
        {
            float costTime = 0;
            for(int i=0;i<number;i++)
            {
                temp[i] = data[i];
            }
            temp[number] = max;
            clock_t start = clock();
            bubble_sort(temp,number);
            clock_t end = clock();
            costTime = (float)(end - start)/CLK_TCK;
            Chart1->Series[1]->Add(costTime,i,RGB(0,255,0));
        }
        if(CheckBox4->Checked)
        {
            float costTime = 0;
            for(int i=0;i<number;i++)
            {
                temp[i] = data[i];
            }
            temp[number] = max;
            clock_t start = clock();
            insertion_sort(temp,number);
            clock_t end = clock();
            costTime = (float)(end - start)/CLK_TCK;
            Chart1->Series[2]->Add(costTime,i,RGB(255,255,0));
        }
        if(CheckBox5->Checked)
        {
            float costTime = 0;
            for(int i=0;i<number;i++)
            {
                temp[i] = data[i];
            }
            temp[number] = max;
            clock_t start = clock();
            quick_recursive_sort(temp,0,number-1);
            clock_t end = clock();
            costTime = (float)(end - start)/CLK_TCK;
            Chart1->Series[3]->Add(costTime,i,RGB(0,0,255));
        }
        if(CheckBox6->Checked)
        {
            float costTime = 0;
            for(int i=0;i<number;i++)
            {
                temp[i] = data[i];
            }
            temp[number] = max;
            clock_t start = clock();
            quick_sort(temp,number);
            clock_t end = clock();
            costTime = (float)(end - start)/CLK_TCK;
            Chart1->Series[4]->Add(costTime,i,RGB(255,255,255));
        }
        if(CheckBox7->Checked)
        {
            float costTime = 0;
            for(int i=0;i<number;i++)
            {
                temp[i] = data[i];
            }
            temp[number] = max;
            clock_t start = clock();
            merge_recursive_sort(temp,0,number-1);
            clock_t end = clock();
            costTime = (float)(end - start)/CLK_TCK;
            Chart1->Series[5]->Add(costTime,i,RGB(211,211,211));
        }
        if(CheckBox8->Checked)
        {
            float costTime = 0;
            for(int i=0;i<number;i++)
            {
                temp[i] = data[i];
            }
            temp[number] = max;
            clock_t start = clock();
            merge_sort(temp,number);
            clock_t end = clock();
            costTime = (float)(end - start)/CLK_TCK;
            Chart1->Series[6]->Add(costTime,i,RGB(160,32,240));
        }
        if(CheckBox9->Checked)
        {
            float costTime = 0;
            for(int i=0;i<number;i++)
            {
                temp[i] = data[i];
            }
            temp[number] = max;
            clock_t start = clock();
            heap_sort(temp,number);
            clock_t end = clock();
            costTime = (float)(end - start)/CLK_TCK;
            Chart1->Series[7]->Add(costTime,i,RGB(141,238,238));
        }
        if(CheckBox10->Checked)
        {
            float costTime = 0;
            for(int i=0;i<number;i++)
            {
                temp[i] = data[i];
            }
            temp[number] = max;
            clock_t start = clock();
            radix_sort(temp,number);
            clock_t end = clock();
            costTime = (float)(end - start)/CLK_TCK;
            Chart1->Series[8]->Add(costTime,i,RGB(0,0,0));
        }
    }
}
//---------------------------------------------------------------------------
