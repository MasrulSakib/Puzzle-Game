#include<iostream>
#include<windows.h>
#include<iomanip>
#include<fstream>

class Player{
	public:
	char name[40];int level;
};
using namespace std;
int board[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,99}};
int  mainGame()
{
    Player* g_data();
	Player newest;
	Player* disp_o_menu(Player* ptr,int n);
	Player data[40],*ptr[40];
	char MMenu[][12]={"Start Game","How To Play","Exit"},name[40];
	char SMenu[][12]={"New User","Existing"};
	char yes_no[][12]={"Yes","No"};
	int level1[][4]={{1,2,3,4},{5,6,7,8},{9,10,12,15},{13,14,11,99}};
	int level2[][4]={{1,6,2,3},{5,10,4,8},{9,14,7,12},{13,15,11,99}};
	int level3[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,99}};
	int level4[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,99}};
	int level5[][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,99}};
	int correct[5]={2,13,4,4,5};
    void showconst(int num[][4]);
	int game_play(int level[][4],int correct,int l);
	int disp_o_menu(char item[][12],int n,char* string);
	int disp_o_menu(int level);
    int choice1=disp_o_menu(MMenu,3,"Main Menu");
	if(choice1==0){
		Sleep(100);
		int choice2=disp_o_menu(SMenu,2,"User type");
		fstream file;
		char name[40];int level,levels;
		file.open("data.txt",ios::app|ios::in|ios::out);
		int id=0;
		while(file>>name>>level)
		{
			strcpy(data[id].name,name);
			data[id].level=level;
			ptr[id]=&data[id];
			id++;
		}
		file.close();
		if(choice2==0)
			{
			int out=1;
			do{
				system("cls");
				cout<<"Enter the name you want ";
				cin>>name;
				out=1;
				for(int j=0;j<id;j++)
				{
					if(!strcmp(data[j].name,name))
					{
						out=0;
						cout<<"name already exists"<<endl;
						Sleep(900);
						break;
					}
				}
			}while(out!=1);
			while(GetAsyncKeyState(VK_RETURN)!=0)
				cout<<".......";
			while(GetAsyncKeyState(VK_ESCAPE)!=0);
			level=1;
			levels=level;
			}
		else
		{	cout<<"loading the menu";
			cout<<".";Sleep(200);
			cout<<".";Sleep(200);
			Player* select=disp_o_menu(ptr[0],id);
			strcpy(name,select->name);
			system("cls");
			cout<<"processing.";
			cout<<".";Sleep(200);
			level=select->level;
			levels=disp_o_menu(level);
			Sleep(500);
		}
	system("cls");
	int ret;
	do{
	system("cls");
	char a;
	switch(levels)
	{
		case 1:
		    ret=game_play(level1,correct[0],1);
			break;
		case 2:
			ret=game_play(level2,correct[1],2);
			break;
		case 3:
		    ret=game_play(level3,correct[2],3);
				break;
		case 4:
			ret=game_play(level4,correct[3],4);
				break;
		case 5:
			ret=game_play(level5,correct[4],5);
				break;
	}
	if(ret==1000)
	 {
	 system("cls");
	 cout<<"you ";Sleep(250);
	 cout<<"wished ";Sleep(250);
	 cout<<"to ";Sleep(250);
	 cout<<"escape ";Sleep(250);
	 while(GetAsyncKeyState(VK_RETURN)!=0)
	     cout<<".......";
	     mainGame();
	 }
	 levels++;
	if(levels>level&&levels!=6)
	{
		level=levels;
		int c=disp_o_menu(yes_no,2,"Do you wish to save the progress");
		if(c==0)
		{
			cout<<"Saving.";
			int x=id;
			cout<<".";
			file.open("data.txt",ios::out);
			cout<<".";
			file.close();
			cout<<".";
			file.open("data.txt",ios::out|ios::app);
			cout<<".";
			while((x-1)>=0){
			if(!strcmp(data[x-1].name,name))
			{
				data[x-1].level=level;
			}
			file<<data[x-1].name<<endl<<data[x-1].level<<endl;
			x--;
			}
			if(choice2==0)
				{
				file<<name<<endl<<level<<endl;
				}
			cout<<".";
			file.close();
		}
		else{
		while(GetAsyncKeyState(VK_RETURN)!=0);
		}
	}
	if(levels>5)
	{
		cout<<endl<<"Game complete";
		Sleep(40);
		break;
	}
	while(GetAsyncKeyState(VK_RETURN)!=0);
	int c=disp_o_menu(yes_no,2,"Do you wish to continue to the next level");
	if(c==1)
		{
			while(GetAsyncKeyState(VK_RETURN)!=0);
			mainGame();
		}
    }while(1);
	}
	else if(choice1==1){
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
		cout<<"How to play"<<endl<<endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),3);
		cout<<"->The no's from 1 to 15 are shown in a jumbled order"<<endl;
		cout<<"->All you have to do is arrange them back in order"<<endl;
		cout<<"->The empty space i.e the dash is the only portion that can be moved"<<endl;
		cout<<"->Use arrow keys to achieve the goal"<<endl;
		showconst(level1);
		cout<<endl<<"becomes..."<<endl<<endl;
		showconst(board);
		system("pause");
		while(GetAsyncKeyState(VK_RETURN)!=0);
		mainGame();
	}
	return 0;
}
int main()
{

	mainGame();

}
	void showconst(int num[][4]){
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),5);
			for(int i=0;i<4;i++){
			for(int j=0;j<4;j++){
				if(num[i][j]==99)
					cout<<setw(3)<<"__";
				else
					cout<<setw(3)<<num[i][j];
			}
			cout<<endl;
		}
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
	}
	Player* disp_o_menu(Player* ptr,int n){
		int pointer=0;
		for(;;){
			Player* ptrt=ptr;
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
			cout<<setw(40)<<"Name"<<setw(5)<<" Level"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			for(int i=0;i<n;i++)
				{
				if(i==pointer)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				cout<<setw(40)<<ptrt->name<<" "<<setw(5)<<ptrt->level<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);

				ptrt++;
				}
				cout<<"PRESS 1 TO GO BACK: "<<endl;
				int x;
				cin>>x;
				if(x)
                {
                    pointer=0;
                    mainGame();
                }
				while(true)
				{
					if(GetAsyncKeyState(VK_UP)!=0)
					{
						pointer-=1;
						if(pointer==-1)
							pointer=n-1;
						break;
					}
					else if(GetAsyncKeyState(VK_DOWN)!=0)
					{
							pointer+=1;
							if(pointer==n)
								pointer=0;
							break;
					}
					else if(GetAsyncKeyState(VK_RETURN)!=0)
							return ptr+pointer;
				}
		Sleep(120);
		}}
	int disp_o_menu(char item[][12],int n,char* string){

	int pointer=0;
		for(;;){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
			cout<<string<<endl<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			for(int i=0;i<n;i++)
				{
				if(i==pointer)
					SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				cout<<item[i]<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				}
				while(true)
				{
					if(GetAsyncKeyState(VK_UP)!=0)
					{
						pointer-=1;
						if(pointer==-1)
							pointer=n-1;
						break;
					}
					else if(GetAsyncKeyState(VK_DOWN)!=0)
					{
							pointer+=1;
							if(pointer==n)
								pointer=0;
							break;
					}
					else if(GetAsyncKeyState(VK_RETURN)!=0)
							return pointer;
				}
		Sleep(120);
		}
}
int disp_o_menu(int level){
		int pointer=0;
		for(;;){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
			cout<<"Select Level"<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			for(int i=0;i<level;i++)
				{
				if(i==pointer)
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
				cout<<"level "<<i+1<<endl;
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				}
				for(int i=level;i<5;i++)
				{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),8);
				cout<<"level "<<i+1<<endl;
				}
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
				while(true)
				{
					if(GetAsyncKeyState(VK_UP)!=0)
					{
						pointer-=1;
						if(pointer==-1)
							pointer=level-1;
						break;
					}
					else if(GetAsyncKeyState(VK_DOWN)!=0)
					{
							pointer+=1;
							if(pointer==level)
								pointer=0;
							break;
					}
					else if(GetAsyncKeyState(VK_RETURN)!=0)
							{
								return pointer+1;
							}


				}
		Sleep(120);
		}
}
int game_play(int level[][4],int correct,int l)
		{
		int win=correct,ptr1,ptr2;
		for(;win!=16;){
			system("cls");
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);
			cout<<"Game level "<<l;
			cout<<endl<<endl;
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
			for(int i=0;i<4;i++)
				{
					for(int j=0;j<4;j++){
						if(level[i][j]==99)
						{
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
							cout<<setw(3)<<"__";
							ptr1=i;ptr2=j;
							SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
						}
						else
							cout<<setw(3)<<level[i][j];
					}
					cout<<endl;
				}
			cout<<"correct positions="<<setw(2)<<win<<" Incorrct= "<<setw(2)<<16-win;
			while(true){
					if(GetAsyncKeyState(VK_UP)!=0)
					{
						if(ptr1>0&&ptr1<=3)
							{
							level[ptr1][ptr2]=level[ptr1-1][ptr2];
							level[ptr1-1][ptr2]=99;
							ptr1--;
							}
						break;
					}
					else if(GetAsyncKeyState(VK_DOWN)!=0)
					{
							if(ptr1>=0&&ptr1<3){
								level[ptr1][ptr2]=level[ptr1+1][ptr2];
								level[ptr1+1][ptr2]=99;
								ptr1++;
						}
						break;
					}
					else if(GetAsyncKeyState(VK_LEFT)!=0)
					{
							if(ptr2>0&&ptr2<=3){
								level[ptr1][ptr2]=level[ptr1][ptr2-1];
								level[ptr1][ptr2-1]=99;
								ptr2--;
						}
						break;
					}
					else if(GetAsyncKeyState(VK_RIGHT)!=0){
							if(ptr2>=0&&ptr2<3){
								level[ptr1][ptr2]=level[ptr1][ptr2+1];
								level[ptr1][ptr2+1]=99;
								ptr2++;
							}
						break;
					}
					else if(GetAsyncKeyState(VK_ESCAPE)!=0){
							return 1000;
							}
					}
			win=0;
			for(int i=0;i<4;i++)
			{
				for(int j=0;j<4;j++)
					{
						if(level[i][j]==board[i][j])
							win++;
					}
			}
		Beep(1000,50);
		Sleep(200);
		}
system("cls");
cout<<endl<<"l";Sleep(100);
cout<<"e";Sleep(100);
cout<<"v";Sleep(200);
cout<<"e";Sleep(200);
cout<<"l";Sleep(200);
cout<<" c";Sleep(200);
cout<<"o";Sleep(200);
cout<<"m";Sleep(200);
cout<<"p";Sleep(200);
cout<<"l";Sleep(200);
cout<<"e";Sleep(200);
cout<<"t";Sleep(200);
cout<<"e";Sleep(200);
return 0;
}
