#include<iostream>
#include<cstdlib>
#include<conio.h>
#include<ctime>
#include<windows.h>
#include<string.h> 
using namespace std;

int Slot(int);
void map(void);
void num(int,int);
int main(){
	map();
	system("title 第九組.程設作業--拉霸");
	srand(time(NULL));
	int money,sum,num;
	sum=1000;//總金額
	do{
		begin:
		num=0;
		cout<<"剩下"<<sum<<"元"<<endl;
		cout<<"請輸入投入金額\n$";
		
		//輸入1~9999之值 
		do{
			if(num>=1){
				cout<<"輸入錯誤!!";
				goto begin;
			} 
			cin>>money;
			num++;
		}while(money<=0 || money>10000 || money>sum);
		cout<<"\a";
		//輸出獲得金錢總和 
		sum=sum+Slot(money);

		getch();//任意鍵continue 
		system("CLS");//清除 
	}while(sum>0);
	cout<<"Game over!!";
	return 0;
}

int Slot(int money){
	
	/*創造陣列a,數字不同機率*/ 
	int a[28];
	//數字7機率1/28
	a[0]=7;
	 //數字6機率2/28 
	for(int i=1;i<=2;i++)	a[i]=6;
	//數字5機率3/28 
	for(int i=3;i<=5;i++)	a[i]=5;
	//數字4機率4/28 
	for(int i=6;i<=9;i++)	a[i]=4;
	//數字3機率5/28 
	for(int i=10;i<=14;i++) a[i]=3;
	//數字2機率6/28 
	for(int i=15;i<=20;i++) a[i]=2;
	//數字1機率7/28 
	for(int i=21;i<=27;i++)	a[i]=1; 
	/*創造陣列a,數字不同機率*/

	int number[3];//number陣列代表拉霸3數字
	
	//數字運轉中 
	for(int i=0;i<=50;i++){
		cout<<"　　　";
		for(int j=0;j<3;j++){
			cout<<rand()%7+1<<"　";
		}
		cout<<endl;
		cout<<"－－－";
		for(int i=0;i<3;i++){
			number[i]=a[rand()%28];
			cout<<number[i]<<"　";
		}
		cout<<"－－－";
		cout<<endl;
		cout<<"　　　";
		for(int j=0;j<3;j++){
			cout<<rand()%7+1<<"　";
		}
		Sleep(3*i);
		if(i==50) break;
		system("CLS");
	} 	
	cout<<endl;
	//賠率
	int j=0;//計算重複數字次數
	
	//數字1~7 
	for(int i=1;i<=7;i++){
		//number[3]陣列 
		for(int h=0;h<3;h++){
			//如果陣列number[h]=i 
			if(number[h]==i){
				j++;
				//累積3次則計算賠率 
				if(j==3){
					money=i*i*10+250;
					cout<<"\a　　　中獎拉!!獲得"<<i*i*10+250<<"$";
					return money;
				}
			}
		}
		j=0;
	}
	//沒中獎,投入金額收回 
	cout<<"\a　　　槓龜了...\n";
	return -money;
}

void map(void){
	
	char roomWideTop[3][3]={"┌","─","┐"};
	char roomWideDown[3][3]={"└","─","┘"};
	char roomLength[1][3]={"│"};
	int wide,length,i;
	
	//設定長寬 3:1
	wide=15;
	length=5;

	//上寬度程式碼 
	i=wide;
	cout<<roomWideTop[0];
	for(wide;wide>0;wide--){
		cout<<roomWideTop[1];
	}
	cout<<roomWideTop[2];
	cout<<"\n";
	wide=i;
	
	//長度程式碼 
	for(length;length>0;length--){
		cout<<roomLength[0];
		for(int x=wide/3;x>0;x--){
			cout<<"　";
		}
		cout<<"\b\b"<<roomLength[0];
		for(int x=wide/3;x>0;x--){
			cout<<"　";
		}
		cout<<"\b"<<roomLength[0];
		for(int x=wide/3;x>0;x--){
			cout<<"　";
		}
		cout<<"\b"<<roomLength[0];
		cout<<"\n";
	}
	
	cout<<roomWideDown[0];
	for(wide;wide>0;wide--){
		cout<<roomWideDown[1];
	}
	cout<<roomWideDown[2];
	cout<<"\n";
	/*
	┌─────┐
	│　│　│　│ 
	└─────┘
	*/
}

void num(int x,int n){
}	

