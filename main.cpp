#include <iostream>
#include <iomanip>
#include <cmath>
#include <windows.h>
#include <limits>
using namespace std;


void clear(){
	#if _WIN32
	system("cls");
	#else
	system("clear");
	#endif
	cout<<endl;
}
//GLOPAL VARIABLE
int meow=1;
int ra=12;
int trun=1;
int roundd=1 ;
int ok=0;
int we1=10,we2;

class XO{
	protected:
		int state;
		
	public:
		XO(int s=0): state(s){
		}
		void setstate(int s){
			state=s;
		}
		int getstate(){
			return state;
		}
		
		
};
	XO ch[3][3]={	 2,2,2, // 0,1,2,
				 2,2,2, // 3,4,5,
				 2,2,2  // 6,7,8
	};
	XO ch1[4][4]={2,2,2,2,
				  2,2,2,2,
				  2,2,2,2,
				  2,2,2,2};
	
class player: public XO{
	private:
		bool kind;
		int points;
		XO (*choices)[3][3]; 
		XO (*choices1)[4][4];
	public:
	    player(XO (&c)[3][3], bool k) {
	        points = 0;  
			kind=k;       
	        choices = &c;      
	    }
	    player(XO (&c)[4][4], bool k){
	    	points=0;
	    	kind=k;
	    	choices1 = &c;
		}
		void win(){
			points++;
		}
		int getpoints(){
			return points;
		}
		void change(int n, int r){
			    if (kind == 0 && r % 2 == 1) {
			        (*choices)[n / 3][n % 3].setstate(1);
			    }
			    else if (kind == 0 && r % 2 == 0) {
			        (*choices)[n / 3][n % 3].setstate(0);
			    }
			    else if (kind == 1 && r % 2 == 1) {
			        (*choices)[n / 3][n % 3].setstate(0);
			    }
			    else if (kind == 1 && r % 2 == 0) {
			        (*choices)[n / 3][n % 3].setstate(1);
			    }
			
}
void change(int n, int r , int v){
				if (kind == 0 && r % 2 == 1) {
			        (*choices1)[n / 4][n % 4].setstate(1);
			    }
			    else if (kind == 0 && r % 2 == 0) {
			        (*choices1)[n / 4][n % 4].setstate(0);
			    }
			    else if (kind == 1 && r % 2 == 1) {
			        (*choices1)[n / 4][n % 4].setstate(0);
			    }
			    else if (kind == 1 && r % 2 == 0) {
			        (*choices1)[n / 4][n % 4].setstate(1);
			    }
}		
};
	player p1(ch, 0);
	player p2(ch, 1);
	player p144(ch1, 0);
	player p244(ch1, 1);
	
void show4x4(){
	//the last show
				cout<<"Player one: "<<p144.getpoints()<<setw(172)<<setfill(' ')<<"Player tow: "<<p244.getpoints()<<endl;
				for(int q=0;q<4;q++){
				for (int i=0; i<=12; i++){
					cout<<setw(40)<<setfill(' ');
					for( int w=0;w<4;w++){	
						int amk=0;
					// draw one square
						for (int f=0;f<=12;f++){
							if (f%12==0 || i%12==0 ){
								if (f==12){
									for (int q=0;q<amk;q++){
										cout<<" ";
									}
								}
								cout<<"##";
							}		
					
							
					 //draw  o
							else if(ch1[q][w].getstate()==0){
								if((f<=(ra*2-sqrt((ra-i)*4*i)*2)/2)){
									cout<<" ";
									amk++;
								}
								else if(f<2*sqrt((ra-i)*4*i)){
										cout<<"**";
								} 
								else{
									cout<<"1";
								}
							}
							
					// draw x
							else if ((f==i || f+i==12) && ch1[q][w].getstate()==1){
								cout<<"**";
							}
					
							
							else {
								cout<<"  ";
							}
							
							
						}
					}
					cout<<endl;
				}
				//cout<<endl;
			}
}

void show(){
	//the last show
				cout<<"Player one: "<<p1.getpoints()<<setw(142)<<setfill(' ')<<"Player tow: "<<p2.getpoints()<<endl;
				for(int q=0;q<3;q++){
				for (int i=0; i<=12; i++){
					cout<<setw(40)<<setfill(' ');
					for( int w=0;w<3;w++){	
						int amk=0;
					// draw one square
						for (int f=0;f<=12;f++){
							if (f%12==0 || i%12==0 ){
								if (f==12){
									for (int q=0;q<amk;q++){
										cout<<" ";
									}
								}
								cout<<"##";
							}		
					
							
					 //draw  o
							else if(ch[q][w].getstate()==0){
								if((f<=(ra*2-sqrt((ra-i)*4*i)*2)/2)){
									cout<<" ";
									amk++;
								}
								else if(f<2*sqrt((ra-i)*4*i)){
										cout<<"**";
								} 
								else{
									cout<<"1";
								}
							}
							
					// draw x
							else if ((f==i || f+i==12) && ch[q][w].getstate()==1){
								cout<<"**";
							}
					
							
							else {
								cout<<"  ";
							}
							
							
						}
					}
					cout<<endl;
				}
				//cout<<endl;
			}
}


void show1(){
				int wow=0;
				int ra=12;
				for(int q=0;q<1;q++){
				for (int i=0; i<=12; i++){
					cout<<setw(55)<<setfill(' ');
					for( int w=0;w<2;w++){	
						int amk=0;
						for (int f=0;f<=12;f++){
							if(wow==0){
								if((f<=(ra*2-sqrt((ra-i)*4*i)*2)/2)){
									cout<<" ";
									amk++;
								}
								else if(f<2*sqrt((ra-i)*4*i)){
										cout<<"**";
								} 
								else{
									cout<<"1";
								}
								if (w==0){
									wow++;
								}
								
							}
							else if ((f==i || f+i==12) && wow==1){
								cout<<"**";
								wow--;
							}
							else {
								cout<<"  ";
							}	
						}
					}
					cout<<endl;
				}

			}
}
threebythree(){
		clear();
		//check is there winer
		for(int x=0; x<9; x++){
			for(int y=0;y<9;y++){
				for(int z=0; z<9;z++){
					if((x!=y && x!=z && y!=z) && ( (x%3 - z%3)*(z/3 - y/3)==(x/3 - z/3)*(z%3 - y%3) ) && ch[x/3][x%3].getstate()==0 && ch[z/3][z%3].getstate()==0 && ch[y/3][y%3].getstate()==0){
						we1=0;// o win
					}
					else if((x!=y && x!=z && y!=z) && ( (x%3 - z%3)*(z/3 - y/3)==(x/3 - z/3)*(z%3 - y%3) ) && ch[x/3][x%3].getstate()==1 && ch[z/3][z%3].getstate()==1 && ch[y/3][y%3].getstate()==1){
						we1=1;// x win
					}
				}
			}
		}
		if (we1==1){
			//check which player wan
			system("color 2F");
			if(roundd%2==1){
				cout<<setw(100)<<setfill(' ')<<"Player one is the winer in this roundd\n";
				p1.win();
			}
			else if(roundd%2==0){
				cout<<setw(100)<<setfill(' ')<<"Player tow is the winer in this roundd\n";
				p2.win();
			}
			show();//the last show
			we1=10;
			trun=1;
			roundd++;
			for (int l = 0; l < 3; ++l) {
			    for (int k = 0; k < 3; ++k) {
			        ch[l][k] = 2;
			    }
			}
			cout<<setw(120)<<setfill(' ')<<"If you want to play agian write any number and if you want to close the game write 0: ";
			cin>>meow;
		}
		else if(we1==0){
			system("color 2F");
			if(roundd%2==1){
				cout<<setw(100)<<setfill(' ')<<"Player tow is the winer in this roundd\n";
				p2.win();	
			}
			else if(roundd%2==0){
				cout<<setw(100)<<setfill(' ')<<"Player one is the winer in this roundd\n";
				p1.win();
			}
			show();
			we1=10;
			trun=1;
			roundd++;
			for (int l = 0; l < 3; ++l) {
			    for (int k = 0; k < 3; ++k) {
			        ch[l][k] = 2;
			    }
			}
			cout<<setw(120)<<setfill(' ')<<"If you want to play agian write number 1 and if you want to close the game write 0: ";
			cin>>meow;// for player can watch the loap and the text
		}
		else if(trun==10){
			system("color 70");
			cout<<setw(90)<<setfill(' ')<<"No one win, play again\n";
			show();
			trun=1;
			roundd++;
			for (int l = 0; l < 3; ++l) {
			    for (int k = 0; k < 3; ++k) {
			        ch[l][k] = 2;
			    }
			}
			cout<<setw(120)<<setfill(' ')<<"If you want to play agian write number 1 and if you want to close the game write 0: ";
			cin>>meow;
		}
		// the main loop that draw and make the taple
		else if(we1==10){
			//cout<<setw(40)<<setfill(' ')<<"";
			show();
			// check if player1 his turn
			if (roundd%2==trun%2){
				system("color 1E");
				while(ok==0 ){
				cout<<setw(100)<<setfill(' ')<<"player1 Enter your choice from 1 to 9: ";
				cin>>we2;
				if (cin.fail()) {
		            cout <<setw(100)<<setfill(' ')<< "Invalid input! Please enter a valid integer." << endl;
		            cin.clear();
		            cin.ignore(numeric_limits<streamsize>::max(), '\n');
		            we2=0;
		        }
				we2--;
				if(ch[we2/3][we2%3].getstate()==2){
					p1.change(we2,roundd);
					ok=1;		
				}
				
				else if((ch[we2/3][we2%3].getstate()==1 || ch[we2/3][we2%3].getstate()==0) && (we2>=0 && we2<9)){
					cout<<setw(100)<<setfill(' ')<<"YOU choose number already choosen: \n";
				}
				else if(we2!=-1){
					cout <<setw(100)<<setfill(' ')<< "Invalid input! Please enter a valid integer." << endl;	
				}
				
				}
				ok=0;
			}
			// check if player2 his turn
			else if(roundd%2!=trun%2){
				system("color 4E");
				while(ok==0 ){
				cout<<setw(100)<<setfill(' ')<<"player2 Enter your choice from 1 to 9: ";
				cin>>we2;
				if (cin.fail()) {
		            cout <<setw(100)<<setfill(' ')<< "Invalid input! Please enter a valid integer." << endl;
		            cin.clear();
		            cin.ignore(numeric_limits<streamsize>::max(), '\n');
		            we2=0;
		        }
				we2--;
				if(ch[we2/3][we2%3].getstate()==2){
					p2.change(we2,roundd);
					ok=1;
						
				}
				else if((ch[we2/3][we2%3].getstate()==1 || ch[we2/3][we2%3].getstate()==0) && (we2>=0 && we2<9)){
					cout<<setw(100)<<setfill(' ')<<"YOU choose number already choosen: \n";
				}
				else if(we2!=-1){
					cout <<setw(100)<<setfill(' ')<< "Invalid input! Please enter a valid integer." << endl;	
				}
				}
				ok=0;
			}
			trun++;	
		}
}


fourbyfour(){
	clear();
		//check is there winer
		for(int f=0; f<16; f++){
		for(int x=0; x<16; x++){
			for(int y=0;y<16;y++){
				for(int z=0; z<16;z++){
					if((x!=y && x!=z && x!=f && y!=z && f!=y && f!=z) && ( (x%4 - z%4)*(z/4 - y/4)==(x/4 - z/4)*(z%4 - y%4) ) && ((f%4 - z%4)*(z/4 - y/4)==(f/4 - z/4)*(z%4 - y%4)) && ch1[x/4][x%4].getstate()==0 && ch1[z/4][z%4].getstate()==0 && ch1[y/4][y%4].getstate()==0 && ch1[f/4][f%4].getstate()==0){
						we1=0;// o win
					}
					else if((x!=y && x!=z && x!=f && y!=z && f!=y && f!=z) && ( (x%4 - z%4)*(z/4 - y/4)==(x/4 - z/4)*(z%4 - y%4) ) && ((f%4 - z%4)*(z/4 - y/4)==(f/4 - z/4)*(z%4 - y%4)) && ch1[x/4][x%4].getstate()==1 && ch1[z/4][z%4].getstate()==1 && ch1[y/4][y%4].getstate()==1 && ch1[f/4][f%4].getstate()==1){
						we1=1;// x win
					}
				}
			}
		}
	}
		if (we1==1){
			//check which player wan
			system("color 2F");
			if(roundd%2==1){
				cout<<setw(100)<<setfill(' ')<<"Player one is the winer in this roundd\n";
				p144.win();
			}
			else if(roundd%2==0){
				cout<<setw(100)<<setfill(' ')<<"Player tow is the winer in this roundd\n";
				p244.win();
			}
			show4x4();//the last show
			we1=10;
			trun=1;
			roundd++;
			for (int l = 0; l < 4; ++l) {
			    for (int k = 0; k < 4; ++k) {
			        ch1[l][k] = 2;
			    }
			}
			cout<<setw(120)<<setfill(' ')<<"If you want to play agian write any number and if you want to close the game write 0: ";
			cin>>meow;
		}
		else if(we1==0){
			system("color 2F");
			if(roundd%2==1){
				cout<<setw(100)<<setfill(' ')<<"Player tow is the winer in this roundd\n";
				p244.win();	
			}
			else if(roundd%2==0){
				cout<<setw(100)<<setfill(' ')<<"Player one is the winer in this roundd\n";
				p144.win();
			}
			show4x4();
			we1=10;
			trun=1;
			roundd++;
			for (int l = 0; l < 4; ++l) {
			    for (int k = 0; k < 4; ++k) {
			        ch1[l][k] = 2;
			    }
			}
			cout<<setw(120)<<setfill(' ')<<"If you want to play agian write number 2 and if you want to close the game write 0: ";
			cin>>meow;// for player can watch the loap and the text
		}
		else if(trun==17){
			system("color 70");
			cout<<setw(90)<<setfill(' ')<<"No one win, play again\n";
			show4x4();
			trun=1;
			roundd++;
			for (int l = 0; l < 4; ++l) {
			    for (int k = 0; k < 4; ++k) {
			        ch1[l][k] = 2;
			    }
			}
			cout<<setw(120)<<setfill(' ')<<"If you want to play agian write number 2 and if you want to close the game write 0: ";
			cin>>meow;
		}
		// the main loop that draw and make the taple
		else if(we1==10){
			//cout<<setw(40)<<setfill(' ')<<"";
			show4x4();
			// check if player1 his turn
			if (roundd%2==trun%2){
				system("color 1E");
				while(ok==0 ){
				cout<<setw(100)<<setfill(' ')<<"player1 Enter your choice from 1 to 16: ";
				cin>>we2;
				if (cin.fail()) {
		            cout <<setw(100)<<setfill(' ')<< "Invalid input! Please enter a valid integer." << endl;
		            cin.clear();
		            cin.ignore(numeric_limits<streamsize>::max(), '\n');
		            we2=0;
		        }
				we2--;
				if(ch1[we2/4][we2%4].getstate()==2){
					p144.change(we2,roundd,1);
					ok=1;		
				}
				
				else if((ch1[we2/4][we2%4].getstate()==0 || ch1[we2/4][we2%4].getstate()==1) && (we2>=0 && we2<16)){
					cout<<setw(100)<<setfill(' ')<<"YOU choose number already choosen: \n";
				}
				else if(we2!=-1){
					cout <<setw(100)<<setfill(' ')<< "Invalid input! Please enter a valid integer." << endl;
				}
				}
				ok=0;
			}
			// check if player2 his turn
			else if(roundd%2!=trun%2){
				system("color 4E");
				while(ok==0 ){
				cout<<setw(100)<<setfill(' ')<<"player2 Enter your choice from 1 to 16: ";
				cin>>we2;
				if (cin.fail()) {
		            cout <<setw(100)<<setfill(' ')<< "Invalid input! Please enter a valid integer." << endl;
		            cin.clear();
		            cin.ignore(numeric_limits<streamsize>::max(), '\n');
		            we2=0;
		        }
				we2--;
				if(ch1[we2/4][we2%4].getstate()==2){
					p244.change(we2,roundd,1);
					ok=1;	
				}
				
				else if((ch1[we2/4][we2%4].getstate()==0 || ch1[we2/4][we2%4].getstate()==1) && (we2>=0 && we2<16)){
					cout<<setw(100)<<setfill(' ')<<"YOU choose number already choosen: \n";
				}
				else if(we2!=-1){
					cout <<setw(100)<<setfill(' ')<< "Invalid input! Please enter a valid integer." << endl;
				}
				}
				ok=0;
			}
			trun++;	
		}
}


int main(){
	while(true){
		clear();
		cout<<"\n\n\n";
		show1();
		cout<<"\n\n"<<setw(93)<<setfill(' ')<<"p1 VS p2  in 3X3 Enter 1: \n";
		cout<<setw(92)<<setfill(' ')<<"p1 VS p2 in 4X4 Enter 2: ";
		cin>>meow;
		if (cin.fail()) {
		            cout <<setw(100)<<setfill(' ')<< "Invalid input! Please enter a valid integer." << endl;
		            cin.clear();
		            cin.ignore(numeric_limits<streamsize>::max(), '\n');
		        }
		else if( meow== 1 || meow ==2){
			break;
		}
		else{
			cout <<setw(100)<<setfill(' ')<< "Invalid input! Please enter a valid integer." << endl;
		}
	}
	
	
	
	
	
	// 3X3
	while(meow==1){
	threebythree();
	}
	
	
	//4X4
	while ( meow==2){
		fourbyfour();
	}
	

	return 0;
}
