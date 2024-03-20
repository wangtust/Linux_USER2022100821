//C语言
#include <stdio.h>
 
int Tile = 1;           //全局变量骨牌号
int Board[100][100];    //全局数组
 
 
//棋盘覆盖
void ChessBoard(int Tr, int Tc, int Dr, int Dc, int Size){
    //Tr表示棋盘左上角的行号，Tc表示棋盘左上角的列
    //Dr表示棋盘特殊方格的行号，Dc表示棋盘特殊方格的列号
    //Size表示棋盘的宽
 
    if(Size == 1)
        return;
    int t = Tile++;     //L型牌骨号
    int s = Size/2;      //割分棋盘
 
    //覆盖左上角的子棋盘
    if(Dr < Tr + s && Dc < Tc + s){
        //说明特殊方格在此棋盘中
        ChessBoard(Tr,Tc,Dr,Dc,s);
    }
    else{
        //说明特殊方格不在此棋盘中
        //需要用t号L型骨牌覆盖右下角
        Board[Tr+s-1][Tc+s-1] = t;
        ChessBoard(Tr,Tc,Tr+s-1,Tc+s-1,s);
    }
 
    //覆盖右上角的子棋盘
    if(Dr < Tr + s && Dc >= Tc+s){
        //说明特殊方格在此棋盘中
        ChessBoard(Tr,Tc + s, Dr, Dc, s);
    }
    else{
        //说明特殊方格不在此棋盘中
        //需要用t号L型骨牌覆盖左下角
        Board[Tr+s-1][Tc+s] = t;
        ChessBoard(Tr,Tc+s,Tr+s-1,Tc+s,s);
    }
 
    //覆盖左下角的子棋盘
    if(Dr >= Tr + s && Dc < Tc + s){
        //说明特殊方格在此棋盘中
        ChessBoard(Tr+s,Tc,Dr,Dc,s);
    }
    else{
         //说明特殊方格不在此棋盘中
        //需要用t号L型骨牌覆盖右上角
        Board[Tr+s][Tc+s-1] = t;
        ChessBoard(Tr+s,Tc,Tr+s,Tc+s-1,s);
    }
 
    //覆盖右下角的子棋盘
    if(Dr >= Tr + s && Dc >= Tc + s){
        //说明特殊方格在此棋盘中
        ChessBoard(Tr+s,Tc+s,Dr,Dc,s);
    }
    else{
        //说明特殊方格不在此棋盘中
        //需要用t号L型骨牌覆盖左上角
        Board[Tr+s][Tc+s] = t;
        ChessBoard(Tr+s,Tc+s,Tr+s,Tc+s,s);
    }
}
 
 
//打印数组
void Func1(int Array[100][100], int Size){
    int i,j;
    for(i=0;i<Size;i++){
        for(j=0;j<Size;j++){
            printf("%d\t",Array[i][j]);
        }
        printf("\n");
    }
}
 
//计算数组的Size：例如k=2，则Size为4，故矩阵为4*4
int Func2(int k){
    int sum = 1;
    int i;
    for(i = 0; i < k; i++){
        sum = sum * 2;
    }
    return sum;
}
 
int main()
{
    int a = 0;
    int b = 0;
    int k = 0;
    int Size = 0;
    printf("请输入棋盘大小k（注：大小是2^k*2^k）：");
    scanf("%d",&k);
    printf("输出k=%d：\n",k);
    Size = Func2(k);
    printf("输出Size=%d：\n",Size);
    printf("请输入特殊方格的位置：");
    scanf("%d,%d",&a,&b);
    Board[a][b] = 0;
    ChessBoard(0,0,a,b,Size);
    Func1(Board,Size);
    return 0;
}