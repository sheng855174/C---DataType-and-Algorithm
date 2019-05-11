//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
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
class   StackData
{
        public:
                int data;
                StackData *next;
                StackData()
                {
                        data = NULL;
                        next = NULL;
                }
};
class QNode
{
        public:
                BTreeNode *data;
                QNode *next;
                QNode()
                {
                        data = NULL;
                        next = NULL;
                }
};
BTreeNode *root;
StackNode *top;
StackData *top_data;
QNode *rear;
QNode *front;
String output="";
void inorder(BTreeNode *root);
void preoder(BTreeNode *root);
void postorder(BTreeNode *root);
void levelOrder(BTreeNode *node);
BTreeNode* Search(BTreeNode *root,int target);
BTreeNode* InsertBST(BTreeNode *node,int x);
BTreeNode* NewBSTNode(int x);
BTreeNode* DeleteNode(BTreeNode *node,int target);
void push(BTreeNode *node);
BTreeNode* pop();
void push_data(int data);
int pop_data();
void AddQueue(BTreeNode *node);
BTreeNode* DeleteQueue();

void inorder(BTreeNode *root)
{
        if(root!=NULL)
        {
                inorder(root->leftChild);
                output += IntToStr(root->data) + "_";
                inorder(root->rightChild);
        }
}
void preorder(BTreeNode *root)
{
        if(root != NULL)
        {
                output += IntToStr(root->data)+ "_";
                preorder(root->leftChild);
                preorder(root->rightChild);
        }
}
void postorder(BTreeNode *root)
{
        if(root != NULL)
        {
                postorder(root->leftChild);
                postorder(root->rightChild);
                output += IntToStr(root->data) + "_";
        }
}
void levelOrder(BTreeNode *node)
{
        AddQueue(node);
        while(front != NULL)
        {
                node = DeleteQueue();
                output += IntToStr(node->data) + "_";
                if(node->leftChild != NULL) AddQueue(node->leftChild);
                if(node->rightChild != NULL) AddQueue(node->rightChild);
        }
}
BTreeNode* Search(BTreeNode *root,int target)
{
        if(root==NULL) return root;//�S���
        else if(root->data == target) return root;//���
        else if(root->data > target) return Search(root->leftChild,target);
        else if(root->data < target) return Search(root->rightChild,target);
}
BTreeNode* NewBSTNode(int x)
{
        BTreeNode *node = new BTreeNode;
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
        else//���x
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
void push_data(int data)
{
        StackData *old_top;
        old_top = top_data;
        top_data = new StackData;
        top_data->data = data;
        top_data->next = old_top;
}
int pop_data()
{
        int temp;
        StackData *old_top;
        if(top_data == NULL) return NULL;
        temp = top_data->data;
        old_top = top_data;
        top_data = top_data->next;
        delete []old_top;
        return temp;
}
void AddQueue(BTreeNode *node)
{
        QNode *p;
        p = new QNode;
        p->data = node;
        p->next = NULL;
        if(front == NULL) front = p;
        else rear->next = p;
        rear = p;
}
BTreeNode* DeleteQueue()
{
        BTreeNode *node;
        QNode *p;
        if(rear == NULL){}
        else
        {
                node = front->data;
                p = front;
                front = front->next;
                delete[] p;
                return node;
        }
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
        Form1->Memo1->Clear();
        srand(time(NULL));
        root = new BTreeNode;
        root = NULL;
        top = NULL;
        top_data = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        int number = StrToInt(Edit2->Text);
        int range = StrToInt(Edit3->Text);
        output = "�üƦ��\ :";
        for(int i=0;i<number;i++)
        {
                root = InsertBST(root,rand()%range+1);
        }
        inorder(root);
        Memo1->Lines->Add(output);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        int target = StrToInt(Edit1->Text);
        if(RadioButton4->Checked == true)
        {//���j
                BTreeNode *p = Search(root,target);
                if(p == NULL) Memo1->Lines->Add("(���j)�S��� :" + Edit1->Text);
                else if(p->data == target) Memo1->Lines->Add("(���j)��� :" + Edit1->Text);
        }
        if(RadioButton5->Checked == true)
        {//�D���j
                BTreeNode *node = root;
                while(node != NULL)
                {
                        if(node->data == target)
                        {
                                Memo1->Lines->Add("(�D���j)��� :" + Edit1->Text);
                                break;
                        }
                        else if(target < node->data) node = node->leftChild;
                        else if(target > node->data) node = node->rightChild;
                }
                if(node == NULL)
                {
                        Memo1->Lines->Add("(�D���j)�S��� :" + Edit1->Text);
                }
        }
}
//---------------------------------------------------------------------------




void __fastcall TForm1::Button3Click(TObject *Sender)
{
        if(RadioButton2->Checked == true)
        {//����
                if(RadioButton4->Checked == true)
                {//���j
                        output = "���ǻ��j :";
                        inorder(root);
                        Memo1->Lines->Add(output);
                }
                if(RadioButton5->Checked == true)
                {//�D���j
                        BTreeNode *node = root;
                        output = "���ǫD���j :";
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
                        Memo1->Lines->Add(output);
                }
        }
        if(RadioButton1->Checked == true)
        {//�e��
                if(RadioButton4->Checked == true)
                {//���j
                        output = "�e�ǻ��j :";
                        preorder(root);
                        Memo1->Lines->Add(output);
                }
                if(RadioButton5->Checked == true)
                {//�D���j
                        BTreeNode *node = root;
                        output = "�e�ǫD���j :";
                        do
                        {
                                while(node != NULL)
                                {
                                        output += IntToStr(node->data) + "_";
                                        push(node);
                                        node = node->leftChild;
                                }
                                if(top != NULL)
                                {
                                        node = pop();
                                        node = node->rightChild;
                                }
                        }while(top!=NULL || node!=NULL);
                        Memo1->Lines->Add(output);
                }
        }
        if(RadioButton3->Checked == true)
        {//���
                if(RadioButton4->Checked == true)
                {//���j
                        output = "��ǻ��j :";
                        postorder(root);
                        Memo1->Lines->Add(output);
                }
                if(RadioButton5->Checked == true)
                {//�D���j
                        BTreeNode *node = root;
                        output = "��ǫD���j :";
                        do
                        {
                                while(node != NULL)
                                {
                                        push_data(node->data);
                                        push(node);
                                        node = node->rightChild;
                                }
                                if(top != NULL)
                                {
                                        node = pop();
                                        node = node->leftChild;
                                }
                        }while(top!=NULL || node!=NULL);
                        while(top_data != NULL) output += IntToStr(pop_data()) + "_";
                        Memo1->Lines->Add(output);
                }
        }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
        int data = StrToInt(Edit4->Text);
        output = "�s�W���\ :";
        if(RadioButton4->Checked == true)
        {//���j
                root = InsertBST(root,data);
        }
        if(RadioButton5->Checked == true)
        {//�D���j
                BTreeNode *p;
                BTreeNode *node = root;
                node = p = root;
                while(node != NULL)
                {
                        p = node;
                        if(node->data == data) break;
                        else if(node->data > data) node = node->leftChild;
                        else if(node->data < data) node = node->rightChild;
                }
                if(root == NULL) root = NewBSTNode(data);
                else if(p->data > data)
                {
                        p->leftChild = NewBSTNode(data);
                }
                else if(p->data < data)
                {
                        p->rightChild = NewBSTNode(data);
                }
        }
        inorder(root);
        Memo1->Lines->Add(output);
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button5Click(TObject *Sender)
{
        int target = StrToInt(Edit1->Text);
        output = "�R�����\ :";
        if(RadioButton4->Checked == true)//���j
        {
                root = DeleteNode(root,target);
        }
        if(RadioButton5->Checked == true)//�D���j
        {
                BTreeNode *node = root;
                BTreeNode *father = root;
                while(node != NULL)
                {
                        if(node->data == target)
                        {
                                break;
                        }
                        else if(target < node->data)
                        {
                                father = node;
                                node = node->leftChild;
                        }
                        else if(target > node->data)
                        {
                                father = node;
                                node = node->rightChild;
                        }
                }
                if(node == NULL)//�S��줣�B�z
                {
                        output = "�R������ :";
                }
                else if(node->leftChild==NULL && node->rightChild==NULL)//��
                { 
                        if(node == root)
                        {
                                delete[] root;
                                root = new BTreeNode;
                                root = NULL;
                        }
                        else if(father->data < node->data)
                        {
                                father->rightChild = NULL;
                                delete[] node;
                        }
                        else
                        {
                                father->leftChild = NULL;
                                delete[] node;
                        }
                }
                else if(node->leftChild==NULL || node->rightChild==NULL)//�u���@�Ӥl��
                {
                        BTreeNode *temp;
                        if(node->leftChild == NULL)
                        {
                                temp = node->rightChild;
                                *(node) = *(node->rightChild);
                                delete[] temp;
                        }
                        else
                        {
                                temp = node->leftChild;
                                *(node) = *(node->leftChild);
                                delete[] temp;
                        }
                }
                else if(node->rightChild!=NULL && node->leftChild!=NULL)//���l��
                {
                        BTreeNode *temp = node->rightChild;
                        BTreeNode *tempFather = node;
                        for(temp;temp->leftChild!=NULL;tempFather=temp,temp=temp->leftChild);
                        node->data = temp->data;
                        if(temp->rightChild != NULL)
                        {
                                BTreeNode *p = temp->rightChild;
                                *(temp) = *(temp->rightChild);
                                delete[] p;
                        }
                        else
                        {
                                if(tempFather == node) tempFather->rightChild = NULL;
                                else tempFather->leftChild = NULL;
                                delete[] temp;
                        }
                }
        }
        inorder(root);
        Memo1->Lines->Add(output);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button6Click(TObject *Sender)
{
        output = "���h�L�X :";
        levelOrder(root);
        Memo1->Lines->Add(output);
}
//---------------------------------------------------------------------------

