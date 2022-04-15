#include <iostream>
#include <cstring>
#include <bitset>
using namespace std;
int transferTable2[64] = {40,8,48,16,56,24,64,32,39,7,47,15,55,23,63,
    31,38,6,46,14,54,22,62,30,37,5,45,13,53,21,61,29,36,4,44,12,52,20,60,
    28,35,3,43,11,51,19,59,27,34,2,42,10,50,18,58,26,33,1,41,9,49,17,57,25};
int expendTableNumber3[48]={
    32,1,2,3,4,5,4,5,6,7,8,9,
    8,9,10,11,12,13,12,13,14,15,16,17,
    16,17,18,19,20,21,20,21,22,23,24,25,
    24,25,26,27,28,29,28,29,30,31,32,1
};
int sBox[8][4][16]={
    {
        {14,4,13,1,2,15,11,8,3,10,6,12,5,9,0,7},
        {0,15,7,4,14,2,13,1,10,6,12,11,9,5,3,8},
        {4,1,14,8,13,6,2,11,15,12,9,7,3,10,5,0},
        {15,12,8,2,4,9,1,7,5,11,3,14,10,0,6,13},
    },
    {
        {15,1,8,14,6,11,3,4,9,7,2,13,12,0,5,10},
        {3,13,4,7,15,2,8,14,12,0,1,10,6,9,11,5},
        {0,14,7,11,10,4,13,1,5,8,12,6,9,3,2,15},
        {13,8,10,1,3,15,4,2,11,6,7,12,0,5,14,9},
    },
    {
        {10,0,9,14,6,3,15,5,1,13,12,7,11,4,2,8},
        {13,7,0,9,3,4,6,10,2,8,5,14,12,11,15,1},
        {13,6,4,9,8,15,3,0,11,1,2,12,5,10,14,7},
        {1,10,13,0,6,9,8,7,4,15,14,3,11,5,2,12},
    },
    {
        {7,13,14,3,0,6,9,10,1,2,8,5,11,12,4,15},
        {13,8,11,5,6,15,0,3,4,7,2,12,1,10,14,9},
        {10,6,9,0,12,11,7,13,15,1,3,14,5,2,8,4},
        {3,15,0,6,10,1,13,8,9,4,5,11,12,7,2,14},
    },
    {
        {2,12,4,1,7,10,11,6,8,5,3,15,13,0,14,9},
        {14,11,2,12,4,7,13,1,5,0,15,10,3,9,8,6},
        {4,2,1,11,10,13,7,8,15,9,12,5,6,3,0,14},
        {11,8,12,7,1,14,2,13,6,15,0,9,10,4,5,3},
    },
    {
        {12,1,10,15,9,2,6,8,0,13,3,4,14,7,5,11},
        {10,15,4,2,7,12,9,5,6,1,13,14,0,11,3,8},
        {9,14,15,5,2,8,12,3,7,0,4,10,1,13,11,6},
        {4,3,2,12,9,5,15,10,11,14,1,7,6,0,8,13},
    },
    {
        {4,11,2,14,15,0,8,13,3,12,9,7,5,10,6,1},
        {13,0,11,7,4,9,1,10,14,3,5,12,2,15,8,6},
        {1,4,11,13,12,3,7,14,10,15,6,8,0,5,9,2},
        {6,11,13,8,1,4,10,7,9,5,0,15,14,2,3,12},
    },
    {
        {13,2,8,4,6,15,11,1,10,9,3,14,5,0,12,7},
        {1,15,13,8,10,3,7,4,12,5,6,11,0,14,9,2},
        {7,11,4,1,9,12,14,2,0,6,10,13,15,3,5,8},
        {2,1,14,7,4,10,8,13,15,12,9,0,3,5,6,11},
    }
};
int transferTable[64] ={
    58,50,42,34,26,18,10,2,60,52,44,36,28,20,12,4,
    62,54,46,38,30,22,14,6,64,56,48,40,32,24,16,8,
    57,49,41,33,25,17,9,1,59,51,43,35,27,19,11,3,
    61,53,45,37,29,21,13,5,63,55,47,39,31,23,15,7
    };//tansfer table
int transferTableNumber4[32]={16,7,20,21,29,12,28,17,1,15,23,26,5,18,31,10,2,8,24,14,32,27,3,9,19,13,30,6,22,11,4,25};
int leftMoveTable[16] = {1,1,2,2,2,2,2,2,1,2,2,2,2,2,2,1};
int replaceTableNumber8[48] = {14,17,11,24,1,5,3,28,15,6,21,10,
    23,19,12,4,26,8,16,7,27,20,13,2,
    41,52,31,37,47,55,30,40,51,45,33,48,
    44,49,39,56,34,53,46,42,50,36,29,32    
};
int tableNumber7[56] = {57,49,41,33,25,17,9,1,58,50,42,34,26,18,
    10,2,59,51,43,35,27,19,11,3,60,52,44,36,
    63,55,47,39,31,23,15,7,62,54,46,38,30,22,
    14,6,61,53,45,37,29,21,13,5,28,20,12,4
};
void show(int show[],int length){
    for (int i = 0;i<length;i++){
        cout<< show[i];
    }
    cout<<endl;
}
void InitTransfer(int cipher[64],int plaintext[64],int transferTable[64])//初始置换
{
    for (int i = 0;i<64;i++)
    {
        cipher[i] = plaintext[transferTable[i]-1];//table start with 1.
    }
}//finish
void _32expand48(int input[32],int output[48],int expandTable[48]){
    for (int i=0;i<48;i++){
        output[i] = input[expandTable[i]-1];
    }
}//finish
void xor48(int inout[48],int key[48]){
    for (int i = 0;i<48;i++){
        if( inout[i] == key[i])
        {inout[i] = 0;}
        else
        inout[i] = 1;
    }
}//finish
void xor32(int inout[32],int key[32]){
    for (int i = 0;i<32;i++){
        if( inout[i] == key[i])
        {inout[i] = 0;}
        else
        inout[i] = 1;
    }
}//finish
void sBoxTransfer(int input[48],int output[32],int sBox[8][4][16]){
    for (int i = 0;i<8;i++){
        int boxX = input[6*i]*2+input[6*i+5];
        int boxY = input[6*i+1]*8+input[6*i+2]*4+input[6*i+3]*2+input[6*i+4];
        int number = sBox[i][boxX][boxY];
        //cout << "x:" << boxX << " y:" << boxY <<endl;
        //cout << "number is "<<number<<endl;
        int fourNum[4]={0,0,0,0};
        if (number >= 8)
        fourNum[0] = 1;
        number = number - fourNum[0]*8;
        if (number >= 4)
        fourNum[1] = 1;
        number = number - fourNum[1]*4;
        if (number >= 2)
        fourNum[2] = 1;
        number = number - fourNum[2]*2;
        fourNum[3] = number;
        //cout << "four number is :"<<fourNum[0]<<fourNum[1]<<fourNum[2]<<fourNum[3]<<endl;
        output[4*i] = fourNum[0];
        //cout << "output" << 4*i <<" is "<< output[4*1]<<endl;
        output[4*i+1] = fourNum[1];
        output[4*i+2] = fourNum[2];
        output[4*i+3] = fourNum[3]; 
    }
}//48->32 finish
void palaceTransfer(int input[32],int output[32],int transferTable[32]){
    for (int i = 0;i<32;i++)
    {
        output[i] = input[transferTable[i]-1];//table start with 1.
    }
}//finish
void _64getHalf(int input[64],int leftHalf[32],int rightHalf[32]){
    for(int i = 0;i<32;i++)
    {
        leftHalf[i] = input[i];
        rightHalf[i] = input[i+32];
    }
}//finish
void _56getHalf(int input[56],int leftHalf[28],int rightHalf[28]){
    for(int i = 0;i<28;i++)
    {
        leftHalf[i] = input[i];
        rightHalf[i] = input[i+28];
    }
}//finish
void key64To28(int input[64],int table[56],int C0[28],int D0[28]){
    int key56[56];
    for (int i = 0;i<56;i++)
    {
        key56[i] = input[table[i]-1];//table start with 1.
        //cout << "key" << i <<" is "<<key56[i] <<endl;
    }//置换选择1，表7
    _56getHalf(key56,C0,D0);
}//finish
void leftMove(int moveStep,int input[28]){
	int temp;
	for (int i = 0;i<moveStep;i++){
        temp = input[0];
		for(int i = 0;i<27;i++){
            input[i] = input[i+1];
        }
        input[27] = temp;
	}
}//finish
void replaceTable2(int input[56],int table[48],int output[48]){
    for(int i = 0;i<48;i++){
        output[i] = input[table[i]-1];
    }
}//finish
void iterater16(int input[64],int output[64],int key[64]){  
    int left[32];
    int right[32];
    _64getHalf(input,left,right);//have an init left and right;
    int C0[28];
    int D0[28];
    key64To28(key,tableNumber7,C0,D0);
    //c0 & d0 here is right;
    int CD[56];
    for (int i = 0;i<16;i++){
        leftMove(leftMoveTable[i],C0);
        leftMove(leftMoveTable[i],D0);//left move
        for(int i = 0;i<28;i++){
            CD[i] = C0[i];
            CD[i+28] = D0[i];
        };//get c0 and d0 together(56)to get ki
         int ki[48];
        replaceTable2(CD,replaceTableNumber8,ki);//replace(56->48)get ki
        //ki is wrong;
        int temp[32];
        for(int i = 0;i<32;i++){
            temp[i] = right[i];
        };//used for left(32) = right(32)
        int afterExpend[48];
        _32expand48(right,afterExpend,expendTableNumber3);
        xor48(afterExpend,ki);//48 ki xor
        //cout << "finish xor\n";
        int afterSbox[32];
        sBoxTransfer(afterExpend,afterSbox,sBox);
       //cout << "finish sBox\n";
        int afterPalace[32];
        palaceTransfer(afterSbox,afterPalace,transferTableNumber4);
        xor32(afterPalace,left);
        for(int i = 0;i<32;i++){
            right[i] = afterPalace[i];
        };
        for(int i = 0;i<32;i++){
            left[i] = temp[i];
        };//left(32) = right(32)
        //right = afterxor32= afterPalace(now);
        //cout << "end the"<< i <<" turns;\n";
    }//16turns
    for(int i = 0;i<32;i++){
        output[i] = left[i];
        output[i+32] = right[i];
    }
}
void halfExchange(int input[64]){
    int temp;
    for (int i = 0;i<32;i++){
        temp = input[i];
        input[i] = input[i+32];
        input[i+32] = temp;
    }
}//finish

int main(){
    //int plaintext[64]={0};//init text No.1
    //plaintext[0] = 1;//N0.2
    int plaintext[64] = {0,1,1,0,1,0,0,0,1,0,0,0,0,1,0,1,0,0,1,0,1,1,1,1,0,1,1,1,1,0,1,0,0,0,0,1,0,0,1,1,0,1,1,1,0,1,1,0,1,1,1,0,1,0,1,1,1,0,1,0,0,1,0,0};//No.3
    //int plaintext[64] = {0,0,0,0,0,0,0,1,0,0,1,0,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,0,0,1,1,1,1,0,0,0,1,0,0,1,1,0,1,0,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,0,1,1,1,1};//test
    cout << "text is :";
    show(plaintext,64);
    int AfterInitTrans[64];//after first ip transfer
    //int key64[64]={0,0,0,0,0,0,1,0,1,0,0,1,0,1,1,0,0,1,0,0,1,0,0,0,1,1,0,0,0,1,0,0,0,0,1,1,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,0,0,0,1,1,0,0,1,0,0};//No1.2
    int key64[64]={0,1,1,0,0,0,1,0,1,1,1,1,0,1,1,0,1,1,0,1,1,1,1,0,0,0,1,1,0,0,0,0,0,0,1,1,1,0,1,0,0,0,0,0,1,0,0,0,0,1,1,0,0,0,1,0,1,1,0,1,1,1,0,0};//No.4
    //int key64[64]={0,0,0,1,0,0,1,1,0,0,1,1,0,1,0,0,0,1,0,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,0,1,1,0,1,1,1,0,1,1,1,1,0,0,1,1,0,1,1,1,1,1,1,1,1,1,0,0,0,1};
    cout << "key is : ";
    show(key64,64);
    int iteraterOutput[64]={0};
    InitTransfer(AfterInitTrans,plaintext,transferTable);
    iterater16(AfterInitTrans,iteraterOutput,key64);
    halfExchange(iteraterOutput);//iterateroutput has been changed now.
    int fianlOutput[64];
    InitTransfer(fianlOutput,iteraterOutput,transferTable2);//transfer in the last;
    cout << "final output:";
    show(fianlOutput,64);
    return 0;
}