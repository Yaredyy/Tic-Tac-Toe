//
//  main.cpp
//  Tic Tac Toe
//
//  Created by yared yohannes on 12/12/21.
//

#include <iostream>
using namespace std;

char board[3][3]= {{'1','2','3'},{'4','5','6'},{'7','8','9'}};

char marker = 'X';
int player = 1;
int win = 0;

void drawBoard(){
    
    for(int i =0; i<3; i++){
        
        for(int k=0; k<3; k++){
            
            cout << board[i][k];
            
            if(k!=2){
                cout << "|";
            }
            
        }
        if(i!=2){
        cout << "\n-----\n";
        }
        
    }
    
}

void placeMarker(int slot){
    int x,y;
    if(slot%3==0){
        x =  (slot/3)-1;
    }
    else {
        x = slot/3;
    }
    
    if(slot%3==0){
        y = 2;
    }
    else {
        y = (slot%3)-1;
    }
    
    board[x][y]= marker;
}


void winner(){
    
    for(int i = 0; i<3;i++){
        
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            
            win = player;
            
        }
        
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            
            win = player;
            
        }
        
    }
        
    if(board[0][0] == board[1][1] && board[1][1] == board[2][2]){
            
        win = player;
            
    }
            
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0]){
                
        win = player;
                
    }
    
}


int main(){
    
    while(win == 0){
        
        int spot = -1;
        
        if(player==1){
            drawBoard();
            cout << "\n\nPlayer 1, please pick a spot: ";
            cin >> spot;
        }
        
        if(player==2){
            drawBoard();
            cout << "\n\nPlayer 2, please pick a spot: ";
            cin >> spot;
        }
        
        
        placeMarker(spot);
        
        
        cout << "\n\n";
        
        winner();
        
        
        if(win != 0){
            
            cout << "The winner is Player "<<win<<".\n\n";
            return 0;
            
        }
        else{
            
            if(player == 1){
                
                player = 2;
                marker = 'O';
                
            }
            
            else{
                
                player = 1;
                marker = 'X';
                
            }
            
        }
        
        
        
    }
    
}
