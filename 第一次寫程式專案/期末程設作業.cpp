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
	system("title �ĤE��.�{�]�@�~--���Q");
	srand(time(NULL));
	int money,sum,num;
	sum=1000;//�`���B
	do{
		begin:
		num=0;
		cout<<"�ѤU"<<sum<<"��"<<endl;
		cout<<"�п�J��J���B\n$";
		
		//��J1~9999���� 
		do{
			if(num>=1){
				cout<<"��J���~!!";
				goto begin;
			} 
			cin>>money;
			num++;
		}while(money<=0 || money>10000 || money>sum);
		cout<<"\a";
		//��X��o�����`�M 
		sum=sum+Slot(money);

		getch();//���N��continue 
		system("CLS");//�M�� 
	}while(sum>0);
	cout<<"Game over!!";
	return 0;
}

int Slot(int money){
	
	/*�гy�}�Ca,�Ʀr���P���v*/ 
	int a[28];
	//�Ʀr7���v1/28
	a[0]=7;
	 //�Ʀr6���v2/28 
	for(int i=1;i<=2;i++)	a[i]=6;
	//�Ʀr5���v3/28 
	for(int i=3;i<=5;i++)	a[i]=5;
	//�Ʀr4���v4/28 
	for(int i=6;i<=9;i++)	a[i]=4;
	//�Ʀr3���v5/28 
	for(int i=10;i<=14;i++) a[i]=3;
	//�Ʀr2���v6/28 
	for(int i=15;i<=20;i++) a[i]=2;
	//�Ʀr1���v7/28 
	for(int i=21;i<=27;i++)	a[i]=1; 
	/*�гy�}�Ca,�Ʀr���P���v*/

	int number[3];//number�}�C�N����Q3�Ʀr
	
	//�Ʀr�B�त 
	for(int i=0;i<=50;i++){
		cout<<"�@�@�@";
		for(int j=0;j<3;j++){
			cout<<rand()%7+1<<"�@";
		}
		cout<<endl;
		cout<<"�СС�";
		for(int i=0;i<3;i++){
			number[i]=a[rand()%28];
			cout<<number[i]<<"�@";
		}
		cout<<"�СС�";
		cout<<endl;
		cout<<"�@�@�@";
		for(int j=0;j<3;j++){
			cout<<rand()%7+1<<"�@";
		}
		Sleep(3*i);
		if(i==50) break;
		system("CLS");
	} 	
	cout<<endl;
	//�߲v
	int j=0;//�p�⭫�ƼƦr����
	
	//�Ʀr1~7 
	for(int i=1;i<=7;i++){
		//number[3]�}�C 
		for(int h=0;h<3;h++){
			//�p�G�}�Cnumber[h]=i 
			if(number[h]==i){
				j++;
				//�ֿn3���h�p��߲v 
				if(j==3){
					money=i*i*10+250;
					cout<<"\a�@�@�@������!!��o"<<i*i*10+250<<"$";
					return money;
				}
			}
		}
		j=0;
	}
	//�S����,��J���B���^ 
	cout<<"\a�@�@�@�b�t�F...\n";
	return -money;
}

void map(void){
	
	char roomWideTop[3][3]={"�z","�w","�{"};
	char roomWideDown[3][3]={"�|","�w","�}"};
	char roomLength[1][3]={"�x"};
	int wide,length,i;
	
	//�]�w���e 3:1
	wide=15;
	length=5;

	//�W�e�׵{���X 
	i=wide;
	cout<<roomWideTop[0];
	for(wide;wide>0;wide--){
		cout<<roomWideTop[1];
	}
	cout<<roomWideTop[2];
	cout<<"\n";
	wide=i;
	
	//���׵{���X 
	for(length;length>0;length--){
		cout<<roomLength[0];
		for(int x=wide/3;x>0;x--){
			cout<<"�@";
		}
		cout<<"\b\b"<<roomLength[0];
		for(int x=wide/3;x>0;x--){
			cout<<"�@";
		}
		cout<<"\b"<<roomLength[0];
		for(int x=wide/3;x>0;x--){
			cout<<"�@";
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
	�z�w�w�w�w�w�{
	�x�@�x�@�x�@�x 
	�|�w�w�w�w�w�}
	*/
}

void num(int x,int n){
}	

