#include<curses.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#define UP 1
#define DOWN -1
#define LEFT  2
#define RIGHT -2

struct Snake{
	int hang;
	int lie;
	struct Snake*next;
};//声明贪吃蛇结点的结构体

struct Snake*head=NULL;
struct Snake*tail=NULL;

int key;
int dir;
struct Snake Food;

void initFood()
{
	int x=rand()%20;
	int y=rand()%20;

	Food.hang=x;
	Food.lie=y;
}//初始化食物（在20x20的范围内随机生成食物）
void initNcurse()
{
	initscr();
	keypad(stdscr,1);//开启小键盘方向键输入捕捉支持
}//初始化Ncurses(选择要使用的功能函数)

void addNode()
{
	struct Snake*new=(struct Snake*)malloc(sizeof(struct Snake));
	new->next=NULL;
	switch(dir){

		case UP:
			new->hang=tail->hang-1;
			new->lie=tail->lie;
			break;
		case DOWN:
			new->hang=tail->hang+1;
			new->lie=tail->lie;
			break;
		case LEFT:
			new->hang=tail->hang;
			new->lie=tail->lie-1;
			break;
		case RIGHT:
			new->hang=tail->hang;
			new->lie=tail->lie+1;
			break;
	}
	tail->next=new;
	tail=new;
}//增加贪吃蛇身体结点

void deleNode()
{
	head=head->next;
}//删除贪吃蛇身体的头结点

void initSnake()
{   struct Snake* p;
	dir=RIGHT;  //默认行走方向
	
	if(head!=NULL){
		p=head;
		head=head->next;
		free(p);
	}
	initFood();
	head=(struct Snake*)malloc(sizeof(struct Snake));
	head->hang=2;
	head->lie=2;
	head->next=NULL;
	tail=head;
	addNode();
	addNode();
	addNode();
}

int hasSnakeNode(int hang,int lie)
{       struct Snake*p;
	p=head;
	while(p!=NULL){       
		if(p->hang==hang && p->lie==lie){
			return 1;
		}
		p=p->next;
	}

	return 0;        
}   //判断地图上当前坐标位置是否存在贪吃蛇身体结点

int hasFood(int hang,int lie)
{ 
	if(Food.hang==hang && Food.lie==lie){

		return 1;
	}

	return 0;
} //判断地图上当前坐标位置是否存在食物
void initMap(){
	int hang;
	int lie;
	move(0,0);


	for(hang=0;hang<20;hang++){

		if(hang==0){

			for(lie=-1;lie<20;lie++){

				printw("--");   
			}
			printw("\n");
		}
		if(hang>=0 || hang<=19){

			for(lie=-1;lie<=20;lie++){

				if(lie==-1||lie==20){

					printw("|");
				}

				else if( hasSnakeNode(hang,lie)){

					printw("[]");
				}
				else if( hasFood(hang,lie)){
					printw("##");
				}
				else{

					printw("  ");
				}

			} 
			printw("\n");            
		}

		if(hang==19){
			for(lie=-1;lie<20;lie++){

				printw("--");

			} 
			printw("\n");
			printw("by chenhongming\n");
			printw("food(%d,%d),",Food.hang,Food.lie);
			printw("snake head(%d,%d)\n",tail->hang,tail->lie);
		}  

	} 
}//绘制地图


int issnakedie()
{
	struct Snake* p;
	p=head;

	if(tail->hang<0 || tail->lie==-1 || tail->hang==20 || tail->lie==20){

		return 1;
	}
	while(p->next!=NULL){
		if(p->hang==tail->hang && p->lie==tail->lie){

			return 1;
		}
		p=p->next;
	}
	return 0;
}//判断??是否死亡 


void moveSnake()
{
	addNode();
	if(hasFood(tail->hang,tail->lie)){
		initFood();
	}

	else{
		deleNode();
	}  

	if(issnakedie()){

		initSnake();
		

	}       
}//移动??身（在尾部添加结点 删除头结点 有食物则不删）
void*  refreshjiemian()
{      
	while(1) {
		moveSnake();
		initMap();
		refresh();

		usleep(1000000);


	} 
}//刷新界面（不断的移动??和刷新地图 ）
void turn(int direction)
{
	if(abs(dir) !=abs(direction)){
		dir=direction;
	}
}//转向


void* changeDir()
{

	int key;
	while(1){
		key=getch();
		switch(key){
			case KEY_DOWN:
				turn(DOWN);
				break;   
			case KEY_UP:
				turn(UP);
				break;
			case KEY_RIGHT:
				turn(RIGHT);
				break;
			case KEY_LEFT:
				turn(LEFT);        
				break; 
		}
	}
}//不断从键盘获取方向键的命令
int main(){




	//char 1byte 8bit 128
        initNcurse();
        initSnake();
        initMap();

        pthread_t t1;
        pthread_t t2;
        pthread_create(&t1,NULL,refreshjiemian,NULL);
        pthread_create(&t2,NULL,changeDir,NULL);
		//利用线程同时执行 刷新界面和获得方向的函数
        while(1);

	//    getch();
	endwin();
	return 0;
}
