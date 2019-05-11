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
class BTreeNode
{
        public:
                BTreeNode *leftChild;
                int data;
                BTreeNode *rightChild;
};
class StackNode
{
        public:
                BTreeNode *treeNode;
                StackNode *next;
                StackNode()
                {
                        treeNode = NULL;
                        next = NULL;
                }
};
bool bStart=false;
int n,range;
int *number;
int const maxsize = 100000;
int heapNumber[maxsize];
int heapLength=0;
double bubbletime=0;
double selecttime=0;
double heaptime = 0;
double R_BSTtime=0;
double BSTtime=0;
double inserttime=0;
double quicktime = 0;
String output="";
StackNode *top;

BTreeNode *root;
BTreeNode* InsertBST(BTreeNode *node,int x);
BTreeNode* NewBSTNode(int x);
BTreeNode* DeleteNode(BTreeNode *node,int target);
void swap(int &a,int &b);
void insertHeap(int x);
intdDeleteHeap();
void inorder(BTreeNode *root);

void swap(int &a,int &b)
{
        a = a+b;
        b = a-b;
        a = a-b;
}
void insertHeap(int x)
{
        heapNumber[0]++;
        heapLength++;
        heapNumber[heapLength] = x;
        int i = heapLength;
        while((i>1) && (x>heapNumber[i/2]))
        {
                heapNumber[i]=heapNumber[i/2];
                i=i/2;
        }
        heapNumber[i]=x;
}
BTreeNode* NewBSTNode(int x)
{
        BTreeNode *node;
        node = new BTreeNode;
        node->leftChild = NULL;
        node->data = x;
        node->rightChild = NULL;
        return node;
}
BTreeNode* InsertBST(BTreeNode *node,int x)
{
        if(node == NULL) return NewBSTNode(x);
        if(x < node->data)
        {
                node->leftChild = InsertBST(node->leftChild,x);
        }
        else
        {
                node->rightChild = InsertBST(node->rightChild,x);
        }
        return node;
}
BTreeNode* DeleteNode(BTreeNode *node,int target)
{
        BTreeNode *temp;
        if(node == NULL) return node;
        if(node->data > target)
        {
                node->leftChild = DeleteNode(node->leftChild,target);
        }
        else if(node->data < target)
        {
                node->rightChild = DeleteNode(node->rightChild,target);
        }
        else//找到x
        {
                if(node->leftChild==NULL || node->rightChild==NULL)
                {
                        temp = (node->leftChild)?node->leftChild:node->rightChild;
                        if(temp == NULL)
                        {
                                temp = node;
                                node = NULL;
                        }
                        else
                        {
                                *node = *temp;
                        }
                        delete []temp;
                }
                else
                {
                        for(temp=node->rightChild;temp->leftChild!=NULL;temp=temp->leftChild);
                        node->data = temp->data;
                        node->rightChild = DeleteNode(node->rightChild,temp->data);
                }
        }
        return node;
}
int deleteHeap()
{
        if(heapLength == 0) return -1;
        else
        {
                int x = heapNumber[1];
                heapNumber[1] = heapNumber[heapLength];
                heapLength--;
                int i = 1;
                while(i<=(heapLength/2))
                {
                        int cMax;
                        if(heapNumber[2*i]>heapNumber[2*i+1])
                        {
                                cMax = 2*i;
                        }
                        else
                        {
                                cMax = 2*i + 1;
                        }
                        if (heapNumber[i]>heapNumber[cMax]) break;
                        swap(heapNumber[i],heapNumber[cMax]);
                        i=cMax;
                }
                return x;
        }
}
void inorder(BTreeNode *root)
{
        if(root!=NULL)
        {
                inorder(root->leftChild);
                output += IntToStr(root->data) + "_";
                inorder(root->rightChild);
        }
}
void push(BTreeNode *node)
{
        StackNode *old_top;
        old_top = top;
        top = new StackNode;
        top->treeNode = node;
        top->next = old_top;
}
BTreeNode* pop()
{
        BTreeNode *Tnode;
        StackNode *old_top;
        if(top == NULL) return NULL;
        Tnode = top->treeNode;
        old_top = top;
        top = top->next;
        delete []old_top;
        return Tnode;
}
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
int Partition(int *arr, int front, int end){
    int pivot = arr[end];
    int i = front -1;
    for (int j = front; j < end; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    i++;
    swap(&arr[i], &arr[end]);
    return i;
}
void QuickSort(int *arr, int front, int end){
    if (front < end) {
        int pivot = Partition(arr, front, end);
        QuickSort(arr, front, pivot - 1);
        QuickSort(arr, pivot + 1, end);
    }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        Memo1->Clear();
        Memo2->Clear();
        Memo4->Clear();
        srand(time(NULL));
        top = NULL;
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
        Memo2->Clear();
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
                  Memo2->Lines->Add("number["+IntToStr(i)+"]="+IntToStr(tmpNumber[i]));
                }
        }
        Memo2->Lines->Add("選擇排序" + FloatToStr(selecttime) + "秒...");
        delete []tmpNumber;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
        Memo2->Clear();
          Chart1->RemoveAllSeries();
          Chart1->Title->Text->Clear();
          Chart1->Title->Text->Add("排序CPU比較");
          Chart1->BottomAxis->Title->Caption = "Data Number";
          Chart1->LeftAxis->Title->Caption = "CPU Time(s)";
          for (int i=0;i<7;i++){
                TLineSeries *Series=new TLineSeries(Chart1);
                Series->ParentChart=Chart1;
                Chart1->AddSeries(Series);
          }
          Chart1->Series[0]->Title =  "泡沫排序";
          Chart1->Series[1]->Title =  "選擇排序";
          Chart1->Series[2]->Title =  "Heap Sort";
          Chart1->Series[3]->Title =  "中序走訪";
          Chart1->Series[4]->Title =  "中序走訪非遞迴";
          Chart1->Series[5]->Title =  "插入排序法";
          Chart1->Series[6]->Title =  "快速排序法";
          for (int i=0; i<n; i=i+Edit3->Text.ToInt()){

                Memo2->Lines->Add(i);
                bubbletime=0;
                selecttime=0;
                heaptime = 0;
                R_BSTtime=0;
                BSTtime=0;
                inserttime=0;
                quicktime = 0;
                //泡沫排序
                if(CheckBox4->Checked){
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
                }
                //挑選排序
                if(CheckBox5->Checked){
                        int *tmpNumber;
                        tmpNumber=new int [n];
                        for(int h=0;h<i;h++){
                                tmpNumber[h]=number[h];
                        }
                        clock_t start2 = clock();
                        for(int h=0;h<i;h++){
                                int min=h;
                                for(int j=h+1;j<i;j++){
                                        if(tmpNumber[min]>tmpNumber[j]){
                                        min=j;
                                        }
                                }
                                int tmp=tmpNumber[h];
                                tmpNumber[h]=tmpNumber[min];
                                tmpNumber[min]=tmp;
                        }
                        clock_t end2 = clock();
                        selecttime =(double)(end2-start2)/CLK_TCK;
                        delete []tmpNumber;
                }
                //Heap Sort
                if(CheckBox6->Checked){
                        int temp[maxsize];
                        clock_t start = clock();
                        for(int h=0;h<i;h++)
                        {
                                insertHeap(number[h]);
                        }
                        int length = heapLength;
                        for(int h=0;h<i;h++)
                        {
                                int x = deleteHeap();
                                temp[length-h] = x;
                        }
                        clock_t end = clock();
                        heaptime =(double)(end-start)/CLK_TCK;
                }
                //中序走訪
                if(CheckBox2->Checked)
                {
                        output="中序走訪";
                        clock_t start = clock();
                        for(int h=0;h<i;h++)
                        {
                                root = InsertBST(root,rand()%range+1);
                        }
                        inorder(root);
                        clock_t end = clock();
                        R_BSTtime =(double)(end-start)/CLK_TCK;
                        root = NULL;
                        delete[] root;
                }

                //中序走訪非遞迴
                if(CheckBox3->Checked)
                {
                        clock_t start = clock();
                        for(int h=0;h<i;h++)
                        {
                                root = InsertBST(root,number[h]);
                        }
                        BTreeNode *node = root;
                        do
                        {
                                while(node != NULL)
                                {
                                        push(node);
                                        node = node->leftChild;
                                }
                                if(top != NULL)
                                {
                                        node = pop();
                                        output += IntToStr(node->data)+ "_";
                                        node = node->rightChild;
                                }
                        }while(top!=NULL || node!=NULL);
                        clock_t end = clock();
                        BSTtime =(double)(end-start)/CLK_TCK;
                        root = NULL;
                        top = NULL;
                        delete[] root;
                        delete[] top;
                }
                //插入排序法，網路上找來比較(不會寫)
                if(CheckBox7->Checked)
                {
                        int *tmpNumber;
                        tmpNumber=new int [n];
                        for(int h=0;h<i;h++){
                                tmpNumber[h]=number[h];
                        }
                        int target;
                        int j;
                        clock_t start = clock();
                        for(int h=0;h<i;h++)
                        {
                                target = tmpNumber[h];
                                j = h;
                                while((j>0) && (tmpNumber[j-1]>target))
                                {
                                        tmpNumber[j] = tmpNumber[j-1];
                                        j--;
                                }
                        }
                        clock_t end = clock();
                        inserttime=(double)(end-start)/CLK_TCK;
                        delete []tmpNumber;
                }
                //快速排序法，網路上找來比較(不會寫)
                if(CheckBox8->Checked)
                {
                        int *tmpNumber;
                        tmpNumber=new int [n];
                        for(int h=0;h<i;h++){
                                tmpNumber[h]=number[h];
                        }
                        clock_t start = clock();
                        QuickSort(tmpNumber, 0, i-1);
                        clock_t end = clock();
                        quicktime=(double)(end-start)/CLK_TCK;
                }
                Chart1->Series[0]->Add(bubbletime,i,clRed);
                Chart1->Series[1]->Add(selecttime,i,clGreen);
                Chart1->Series[2]->Add(heaptime ,i,clYellow);
                Chart1->Series[3]->Add(R_BSTtime,i,clBlue);
                Chart1->Series[4]->Add(BSTtime,i,clWhite);
                Chart1->Series[5]->Add(inserttime,i,RGB(220,220,220));
                Chart1->Series[6]->Add(quicktime,i,RGB(255, 0, 255));
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

void __fastcall TForm1::Button6Click(TObject *Sender)
{
        Memo2->Clear();
        n= StrToInt(Edit1->Text);
        range = StrToInt(Edit2->Text);
        int temp[maxsize];
        clock_t start = clock();
        for(int i=0;i<n;i++)
        {
                insertHeap(rand()%number[i]);
        }
        int length = heapLength;
        for(int i=0;i<n;i++)
        {
                int x = deleteHeap();
                temp[length-i] = x;
        }
        clock_t end = clock();
        double time =(double)(end-start)/CLK_TCK;
        Memo2->Lines->Add("Heap Sort:");
        for(int i=0;i<length;i++)
        {
                if(!CheckBox1->Checked)
                {
                        Memo2->Lines->Add(temp[i]);
                }
        }
        Memo4->Clear();
        Memo4->Lines->Add("Heap Sort CPU時間=" + FloatToStr(time) + "s");
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button7Click(TObject *Sender)
{
        Memo2->Clear();
        n= StrToInt(Edit1->Text);
        range = StrToInt(Edit2->Text);
        output="中序走訪";
        for(int i=0;i<n;i++)
        {
                root = InsertBST(root,rand()%range+1);
        }
        clock_t start = clock();
        inorder(root);
        clock_t end = clock();
        double time =(double)(end-start)/CLK_TCK;
        if(!CheckBox1->Checked)
        {
                Memo2->Lines->Add(output);
        }
        Memo4->Clear();
        Memo4->Lines->Add("中序走訪CPU時間=" + FloatToStr(time) + "s");
        root = NULL;
        delete[] root;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button8Click(TObject *Sender)
{
        Memo2->Clear();
        output = "中序非遞迴 :";
        n= StrToInt(Edit1->Text);
        range = StrToInt(Edit2->Text);
        for(int i=0;i<n;i++)
        {
                root = InsertBST(root,rand()%range+1);
        }
        BTreeNode *node = root;
        clock_t start = clock();
        do
        {
                while(node != NULL)
                {
                        push(node);
                        node = node->leftChild;
                }
                if(top != NULL)
                {
                        node = pop();
                        output += IntToStr(node->data)+ "_";
                        node = node->rightChild;
                }
        }while(top!=NULL || node!=NULL);
        clock_t end = clock();
        double time =(double)(end-start)/CLK_TCK;
        if(!CheckBox1->Checked)
        {
                Memo2->Lines->Add(output);
        }
        Memo4->Clear();
        Memo4->Lines->Add("中序走訪非遞迴CPU時間=" + FloatToStr(time) + "s");
        root = NULL;
        top = NULL;
        delete[] root;
        delete[] top;
}
//---------------------------------------------------------------------------

