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
        Memo1->Clear();
}
//---------------------------------------------------------------------------
/*
運算式可用(、)、+、-、*、/、^運算子
*/
String infixChange(String,int);//中序轉換，1後續2前序
String postfixToPrefix(String);//後序轉前序
String postfixToInfix(String);//後序轉中序
String prefixToPostfix(String);//前序轉後序
String prefixToInfix(String);//前序轉中序
String getFix(String,String,String,int);//轉換判斷
void push(String*,int&,String);
String pop(String*,int&);
int beforeStack(String);
int afterStack(String);
int Is_operand(char);

String infixChange(String infix,int change)
{
        const int max=100;//stack最大值
        int length=infix.Length();
        int topStack=0;
        int topOutput=0;
        String stack[max];//放運算子
        String output[max];//放運算元
        push(stack,topStack,'#');//方便判斷用，最低優先順序
        for(int i=1;i<=length;i++)
        {
                if(!Is_operand(infix[i]))
                {//如果是運算子
                        if(infix[i]==')')
                        {
                                while(stack[topStack]!='(')
                                {
                                        String op=pop(stack,topStack);
                                        String a=pop(output,topOutput);
                                        String b=pop(output,topOutput);
                                        String tmp=getFix(a,b,op,change);
                                        push(output,topOutput,tmp);
                                }
                                pop(stack,topStack);//左括號丟出
                        }
                        else
                        {
                                while(beforeStack(infix[i])<=afterStack(stack[topStack]))
                                {
                                        String op=pop(stack,topStack);
                                        String a=pop(output,topOutput);
                                        String b=pop(output,topOutput);
                                        String tmp=getFix(a,b,op,change);
                                        push(output,topOutput,tmp);
                                }
                                push(stack,topStack,infix[i]);
                        }
                }
                else
                {
                        push(output,topOutput,infix[i]);
                }
                if(Form1->CheckBox1->Checked==true && change==1)
                {
                        Form1->Memo1->Lines->Add("第" + IntToStr(i) + "次");
                        String tmp="";
                        for(int i=1;i<=topOutput;i++) tmp+=output[i];
                        Form1->Memo1->Lines->Add("Stack1:" + tmp);
                        tmp="";
                        for(int i=1;i<=topStack;i++) tmp+=stack[i];
                        Form1->Memo1->Lines->Add("Stack2:" + tmp);
                }
                if(Form1->CheckBox2->Checked==true && change==2)
                {
                        Form1->Memo1->Lines->Add("第" + IntToStr(i) + "次");
                        String tmp="";
                        for(int i=1;i<=topOutput;i++) tmp+=output[i];
                        Form1->Memo1->Lines->Add("Stack1:" + tmp);
                        tmp="";
                        for(int i=1;i<=topStack;i++) tmp+=stack[i];
                        Form1->Memo1->Lines->Add("Stack2:" + tmp);
                }
        }
        while(stack[topStack]!="#")
        {
                String op=pop(stack,topStack);
                String a=pop(output,topOutput);
                String b=pop(output,topOutput);
                String tmp=getFix(a,b,op,change);
                push(output,topOutput,tmp);
        }
        if(Form1->CheckBox1->Checked==true && change==1)
        {
                Form1->Memo1->Lines->Add("後序為:" + output[topOutput]);
                Form1->Memo1->Lines->Add("");
        }
        if(Form1->CheckBox2->Checked==true && change==2)
        {
                Form1->Memo1->Lines->Add("前序為:" + output[topOutput]);
                Form1->Memo1->Lines->Add("");
        }
        return pop(output,topOutput);
}
String postfixToPrefix(String postfix)
{
        const int max=100;//stack最大值
        int length=postfix.Length();
        int topOutput=0;
        String output[max];//放運算元
        for(int i=1;i<=length;i++)
        {
                if(!Is_operand(postfix[i]))
                {//如果是運算子
                        String a=pop(output,topOutput);
                        String b=pop(output,topOutput);
                        String tmp=(String)postfix[i]+b+a;
                        push(output,topOutput,tmp);
                }
                else
                {
                        push(output,topOutput,postfix[i]);
                }
                if(Form1->CheckBox3->Checked)
                {
                        String tmp="";
                        for(int i=1;i<=topOutput;i++) tmp+=output[i];
                        Form1->Memo1->Lines->Add("第" + IntToStr(i) + "次:" + tmp);
                }
        }
        return pop(output,topOutput);
}
String prefixToPostfix(String prefix)
{
        const int max=100;//stack最大值
        int length=prefix.Length();
        int topOutput=0;
        String output[max];//放運算元
        for(int i=length;i>0;i--)
        {
                if(!Is_operand(prefix[i]))
                {//如果是運算子
                        String a=pop(output,topOutput);
                        String b=pop(output,topOutput);
                        String tmp=a+b+(String)prefix[i];
                        push(output,topOutput,tmp);
                }
                else
                {
                        push(output,topOutput,prefix[i]);
                }
                if(Form1->CheckBox5->Checked)
                {
                        String tmp="";
                        for(int i=1;i<=topOutput;i++) tmp+=output[i];
                        Form1->Memo1->Lines->Add("第" + IntToStr(length-i+1) + "次:" + tmp);
                }
        }
        return pop(output,topOutput);
}
String postfixToInfix(String postfix)
{
        const int max=100;//stack最大值
        int length=postfix.Length();
        int topOutput=0;
        String output[max];//放運算元
        for(int i=1;i<=length;i++)
        {
                if(!Is_operand(postfix[i]))
                {//如果是運算子
                        String a=pop(output,topOutput);
                        String b=pop(output,topOutput);
                        String tmp="";
                        tmp="(" +  b + postfix[i] + a + ")";
                        push(output,topOutput,tmp);
                }
                else
                {
                        push(output,topOutput,postfix[i]);
                }
                if(Form1->CheckBox4->Checked==true)
                {
                        String tmp="";
                        for(int i=1;i<=topOutput;i++) tmp+=output[i];
                        Form1->Memo1->Lines->Add("第" + IntToStr(i) + "次:" + tmp);
                }
        }
        return pop(output,topOutput);
}
String prefixToInfix(String prefix)
{
        const int max=100;//stack最大值
        int length=prefix.Length();
        int topOutput=0;
        String output[max];//放運算元
        for(int i=length;i>0;i--)
        {
                if(!Is_operand(prefix[i]))
                {//如果是運算子
                        String a=pop(output,topOutput);
                        String b=pop(output,topOutput);
                        String tmp="";
                        tmp="(" +  a + prefix[i] + b + ")";
                        push(output,topOutput,tmp);
                }
                else
                {
                        push(output,topOutput,prefix[i]);
                }
                if(Form1->CheckBox6->Checked)
                {
                        String tmp="";
                        for(int i=1;i<=topOutput;i++) tmp+=output[i];
                        Form1->Memo1->Lines->Add("第" + IntToStr(length-i+1) + "次:" + tmp);
                }
        }
        return pop(output,topOutput);
}
String getFix(String a,String b,String op,int fix)
{
        if(fix==1)
        {
                return  b+a+op;
        }
        if(fix==2)
        {
                return op+b+a;
        }
        return "錯誤";
}
void push(String *stack,int &top,String data)
{
        top++;
        *(stack+top)=data;
}
String pop(String *stack,int &top)
{
        return *(stack+(top--));
}
int beforeStack(String op)
{
        if(op=='#') return 0;
        if(op=='+' || op=='-') return 3;
        if(op=='*' || op=='/') return 5;
        if(op=='^' || op=='&' || op=='|') return 6;
        if(op=='(') return 8;
        return -1;
}
int afterStack(String op)
{
        if(op=='#') return 0;
        if(op=='+' || op=='-') return 3;
        if(op=='*' || op=='/') return 5;
        if(op=='^' || op=='&' || op=='|') return 6;
        if(op=='(') return 1;
        return -1;
}
int Is_operand(char op)
{
        if(op!='+' && op!='-' && op!='*' &&
           op!='/' && op!='^' && op!='(' &&
           op!=')' && op!='[' && op!=']')
        {
                return 1;
        }
        return 0;                
}
void __fastcall TForm1::Button1Click(TObject *Sender)
{
        Memo1->Clear();
        String infix=Edit1->Text;
        String postfix=infixChange(infix,1);
        String prefix=infixChange(infix,2);
        Edit2->Text=postfix;
        Edit3->Text=prefix;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
        Memo1->Clear();
        String postfix=Edit4->Text;
        String prefix=postfixToPrefix(postfix);
        String infix=postfixToInfix(postfix);
        Edit5->Text=prefix;
        Edit6->Text=infix;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Button3Click(TObject *Sender)
{
        Memo1->Clear();
        String prefix=Edit7->Text;
        String postfix=prefixToPostfix(prefix);
        String infix=prefixToInfix(prefix);
        Edit8->Text=postfix;
        Edit9->Text=infix;
}
//---------------------------------------------------------------------------

