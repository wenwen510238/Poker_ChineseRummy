#include "Card.h"

void Card::SetColor(int color ){
  HANDLE hConsole;
  hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(hConsole,color);
}
Card::Card(){
    suit["Spade"]=1;
    suit["Heart"]=2;
    suit["Club"]=3;
    suit["Diamond"]=4;
    ConvertNum[1]="Spade";
    ConvertNum[2]="Heart";
    ConvertNum[3]="Club";
    ConvertNum[4]="Diamond";
    memset(TotalPoint,0,sizeof(TotalPoint));
    srand(time(NULL));
    int number,face;
    for(int j=0;j<4;j++){
        for(int k=0;k<13;k++){
            Record[j][k]=0;
        }
    }
    for(int Count=1;Count<=4;Count++){
        for(int i=1;i<=6;i++){
            number=(rand()%13)+1;
            face=(rand()%4)+1;
            while(Record[face-1][number-1]==1){
                number=(rand()%13)+1;
                face=(rand()%4)+1;
            }
            Record[face-1][number-1]=1;
            if(Count==1){
                player[Count-1].push_back(make_pair(face,number));
            }
            else if(Count==2){
                player[Count-1].push_back(make_pair(face,number));
            }
            else if(Count==3){
                player[Count-1].push_back(make_pair(face,number));
            }
            else if(Count==4){
                player[Count-1].push_back(make_pair(face,number));
            }
        }
    }
    for(int i=0;i<4;i++){
        number=(rand()%13)+1;
        face=(rand()%4)+1;
        while(Record[face-1][number-1]==1){
            number=(rand()%13)+1;
            face=(rand()%4)+1;
        }
        Record[face-1][number-1]=1;
        screen.push_back(make_pair(face,number));
    }
    PrintHuman();
    cout<<"Card on the screen :"<<endl;
    sort(screen.begin(),screen.end());
    for(int j=0;j<13;j++){
        for(int i=0;i<screen.size();i++){
            switch(screen[i].first){
                case 1:
                    SetColor(15);
                    Spade(num[screen[i].second],j);
                    break;
                case 2:
                    SetColor(12);
                    Heart(num[screen[i].second],j);
                    SetColor(15);
                    break;
                case 3:
                    SetColor(15);
                    Club(num[screen[i].second],j);
                    break;
                case 4:
                    SetColor(12);
                    Diamond(num[screen[i].second],j);
                    SetColor(15);
                    break;
            }
            cout<<setw(3)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
//-------------------------------------------------------------------------------------------------------------------
void Card::Spade(string a,int n){
	string S[13]= {"- - - - - -",
                   "|             |",
				   "|      *      |",
				   "|     ***     |",
				   "|   *******   |",
				   "| *********** |",
				   "|*************|",
				   "| **** * **** |",
				   "|      *      |",
				   "|     ***     |",
				   "|             |",
				   "|             |",
				   "- - - - - -"};
	if(a!="10"){
        if(n==0 || n==12){
            cout<<a<<" "<<S[n]<<" "<<a;
        }
        else{
            cout<<S[n];
        }
	}
	else{
        if(n==0 || n==12){
            cout<<a<<S[n]<<a;
        }
        else{
            cout<<S[n];
        }
	}
}

void Card::Heart(string a,int n){
	string H[13]= {"- - - - - -",
                   "|             |",
				   "| ***     *** |",
				   "|****** ******|",
				   "|*************|",
				   "| *********** |",
				   "|  *********  |",
				   "|   *******   |",
				   "|    *****    |",
				   "|     ***     |",
				   "|      *      |",
				   "|             |",
				   "- - - - - -"};
	if(a!="10"){
        if(n==0 || n==12){
            cout<<a<<" "<<H[n]<<" "<<a;
        }
        else{
            cout<<H[n];
        }
	}
	else{
        if(n==0 || n==12){
            cout<<a<<H[n]<<a;
        }
        else{
            cout<<H[n];
        }
	}
}

void Card::Club(string a,int n){
	string C[13]= {"- - - - - -",
                   "|             |",
				   "|     ***     |",
				   "|    *****    |",
				   "|    *****    |",
				   "| *********** |",
				   "|*************|",
				   "| **** * **** |",
				   "|      *      |",
				   "|     ***     |",
				   "|    *****    |",
				   "|             |",
				   "- - - - - -"};
	if(a!="10"){
        if(n==0 || n==12){
            cout<<a<<" "<<C[n]<<" "<<a;
        }
        else{
            cout<<C[n];
        }
	}
	else{
        if(n==0 || n==12){
            cout<<a<<C[n]<<a;
        }
        else{
            cout<<C[n];
        }
	}
}

void Card::Diamond(string a,int n){
	string D[13]= {"- - - - - -",
                   "|             |",
				   "|      *      |",
				   "|     ***     |",
				   "|    *****    |",
				   "|   *******   |",
				   "|  *********  |",
				   "|   *******   |",
				   "|    *****    |",
				   "|     ***     |",
				   "|      *      |",
				   "|             |",
				   "- - - - - -"};
	if(a!="10"){
        if(n==0 || n==12){
            cout<<a<<" "<<D[n]<<" "<<a;
        }
        else{
            cout<<D[n];
        }
	}
	else{
        if(n==0 || n==12){
            cout<<a<<D[n]<<a;
        }
        else{
            cout<<D[n];
        }
	}
}
//-------------------------------------------------------------------------------------------------------------------------------
void Card::PrintHuman(){
    sort(player[0].begin(),player[0].end());
    cout<<"Your card: "<<endl;
    for(int i=0;i<13;i++){
        for(int j=0;j<player[0].size();j++){
            switch(player[0][j].first){
                case 1:
                    SetColor(15);
                    Spade(num[player[0][j].second],i);
                    break;
                case 2:
                    SetColor(12);
                    Heart(num[player[0][j].second],i);
                    SetColor(15);
                    break;
                case 3:
                    SetColor(15);
                    Club(num[player[0][j].second],i);
                    break;
                case 4:
                    SetColor(12);
                    Diamond(num[player[0][j].second],i);
                    SetColor(15);
                    break;
            }
            cout<<setw(3)<<" ";
        }
         cout<<endl;
    }
}

void Card::PrintScreen(){
    cout<<"Card on the screen :"<<endl;
    sort(screen.begin(),screen.end());
    for(int j=0;j<13;j++){
        for(int i=0;i<screen.size();i++){
            switch(screen[i].first){
                case 1:
                    SetColor(15);
                    Spade(num[screen[i].second],j);
                    break;
                case 2:
                    SetColor(12);
                    Heart(num[screen[i].second],j);
                    SetColor(15);
                    break;
                case 3:
                    SetColor(15);
                    Club(num[screen[i].second],j);
                    break;
                case 4:
                    SetColor(12);
                    Diamond(num[screen[i].second],j);
                    SetColor(15);
                    break;
            }
            cout<<setw(3)<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    run();
}

ostream &operator<<( ostream &output, const Card &Poker2){
    output<<"You obtains "<<Poker2.TotalPoint[0]<<" points"<<endl;
    for(int i=1;i<4;i++){
        output<<"Computer "<<i<<" obtains "<<Poker2.TotalPoint[i]<<" points"<<endl;
    }
    int Max=0;
    for(int i=1;i<4;i++){
        if(Poker2.TotalPoint[i]>Max){
            Max=Poker2.TotalPoint[i];
        }
    }
    if(Poker2.TotalPoint[0]>Max){
        output<<"You are a winner!!!"<<endl;
    }
    else{
        output<<"You are a loser!!!"<<endl;
    }
}

bool Card::run(){
    string s,s2;
    pair<int,int> ChooseCard,ScreenCard;
    for(int i=0;i<4;i++){
        if(!player[i].empty()){
            int flag=0,n,n2,flag2=0,HaveCard=0;
            if(i==0){
                if(decide(i)){//人有可配對的牌
                    cout<<"Please choose a card to match the card on the screen."<<endl<<"suit(Spade,Heart,Club,Diamond): "<<endl;
                    while(cin>>s){
                        cout<<"number(1~13): "<<endl;
                        cin>>n;
                        for(int j=0;j<player[0].size();j++){
                            for(int k=0;k<CanPlay[0].size();k++){
                                if(CanPlay[0][k].first==suit[s] && CanPlay[0][k].second==n && player[0][j].first==suit[s] && player[0][j].second==n){
                                    player[0].erase(player[0].begin()+j);
                                    CanPlay[0].clear();
                                    flag=1;
                                    ChooseCard=make_pair(suit[s],n);
                                    break;
                                }
                            }
                        }
                        if(flag==1){
                            break;
                        }
                        else{
                            cout<<"Wrong card!"<<endl;
                            cout<<"Please choose a card to match the card on the screen again."
                            <<endl<<"suit(Spade,Heart,Club,Diamond): "<<endl;
                        }
                    }
                     cout<<"Please choose a card on the screen that you want to match."<<endl
                    <<"suit(Spade,Heart,Club,Diamond): "<<endl;
                    while(cin>>s2){
                        cout<<"number(1~13): "<<endl;
                        cin>>n2;
                        for(int j=0;j<screen.size();j++){
                            if(suit[s2]==screen[j].first && n2==screen[j].second){
                                if(n2>=1 && n2<=9){
                                    if(n2+ChooseCard.second==10){
                                        flag2=1;
                                        ScreenCard=make_pair(suit[s2],n2);
                                        screen.erase(screen.begin()+j);
                                    }
                                }
                                else{
                                    if(n2==ChooseCard.second){
                                        flag2=1;
                                        ScreenCard=make_pair(suit[s2],n2);
                                        screen.erase(screen.begin()+j);
                                    }
                                }
                            }
                        }
                        if(flag2==1) break;
                        else{
                            cout<<"Wrong card!"<<endl;
                            cout<<"Please choose a card on the screen that you want to match again."
                            <<endl<<"suit(Spade,Heart,Club,Diamond): "<<endl;
                        }
                    }
                    CountPoint(ChooseCard,ScreenCard,i);
                }
                else{//人沒有可配對的牌
                    cout<<"You don't have card can match."<<endl<<"Please choose a card and put it on the screen."<<endl
                    <<"suit(Spade,Heart,Club,Diamond): "<<endl;
                    while(cin>>s){
                        cout<<"number(1~13): "<<endl;
                        cin>>n;
                        ChooseCard=make_pair(suit[s],n);
                        for(int j=0;j<player[0].size();j++){
                            if(player[0][j].first==suit[s] && player[0][j].second==n){
                                screen.push_back(make_pair(player[0][j].first,player[0][j].second));
                                player[0].erase(player[0].begin()+j);
                                flag=1;
                                break;
                            }
                        }
                        if(flag==1) break;
                        else{
                            cout<<"Wrong card!"<<endl;
                            cout<<"Please choose the card again"<<endl<<"suit: "<<endl;
                            if(flag==1) break;
                        }
                    }
                }
            }
//----------------------------------------------------------------------------------------------------------------//人出完牌
            else{//電腦開始出牌
                if(decide(i)){//電腦有可配對的牌
                    int Max=0,position;
                    for(int j=0;j<CanPlay[i].size();j++){
                        if(CanPlay[i][j].first==2 || CanPlay[i][j].first==4){
                            if(CanPlay[i][j].second>Max){
                                Max=CanPlay[i][j].second;
                                position=j;
                                HaveCard=1;
                                break;
                            }
                        }
                    }
                    if(HaveCard==1){//電腦手牌可配對的牌有紅色
                        for(int j=0;j<player[i].size();j++){
                            if(player[i][j].first==CanPlay[i][position].first && player[i][j].second==CanPlay[i][position].second){
                                player[i].erase(player[i].begin()+j);
                                ChooseCard=make_pair(CanPlay[i][position].first,CanPlay[i][position].second);
                                cout<<"Computer "<<i<<" sends "<<ConvertNum[CanPlay[i][position].first]<<" "<<CanPlay[i][position].second<<endl;
                                for(int k=0;k<screen.size();k++){
                                    if(CanPlay[i][position].first == 2 || CanPlay[i][position].second == 4){//場上有紅色的牌
                                        if(CanPlay[i][position].second>=1 && CanPlay[i][position].second<=9){
                                            if(screen[k].second+CanPlay[i][position].second==10){
                                                ScreenCard=make_pair(screen[k].first,screen[k].second);
                                                cout<<"Computer "<<i<<" gets "<<ConvertNum[screen[k].first]<<" "<<screen[k].second<<endl;
                                                screen.erase(screen.begin()+k);
                                                break;
                                            }
                                        }
                                        else if(screen[k].second == CanPlay[i][position].second){
                                            ScreenCard=make_pair(screen[k].first,screen[k].second);
                                            cout<<"Computer "<<i<<" gets "<<ConvertNum[screen[k].first]<<" "<<screen[k].second<<endl;
                                            screen.erase(screen.begin()+k);
                                            break;
                                        }
                                    }
                                    else{
                                        if(CanPlay[i][position].second>=1 && CanPlay[i][position].second<=9){
                                            if(screen[k].second+CanPlay[i][position].second==10){
                                                ScreenCard=make_pair(screen[k].first,screen[k].second);
                                                cout<<"Computer "<<i<<" gets "<<ConvertNum[screen[k].first]<<" "<<screen[k].second<<endl;
                                                screen.erase(screen.begin()+k);
                                                break;
                                            }
                                        }
                                        else if(screen[k].second==CanPlay[i][position].second){
                                            ScreenCard=make_pair(screen[k].first,screen[k].second);
                                            cout<<"Computer "<<i<<" gets "<<ConvertNum[screen[k].first]<<" "<<screen[k].second<<endl;
                                            screen.erase(screen.begin()+k);
                                            break;
                                        }
                                    }
                                }
                            }
                        }
                        CountPoint(ChooseCard,ScreenCard,i);
                    }
                    else{//電腦手中可出的牌都是黑色但可配對
                        for(int j=0;j<screen.size();j++){
                            for(int k=0;k<CanPlay[i].size();k++){
                                if(screen[j].first==2 || screen[i].first==4){//場面上有紅色可配對的牌
                                    if(CanPlay[i][k].second>=1 && CanPlay[i][k].second<=9){
                                        if((screen[j].second)+(CanPlay[i][k].second)==10){
                                            position=k;
                                            ChooseCard=make_pair(CanPlay[i][k].first,CanPlay[i][k].second);
                                            ScreenCard=make_pair(screen[j].first,screen[j].second);
                                            HaveCard=1;
                                            cout<<"Computer "<<i<<" sends "<<ConvertNum[CanPlay[i][k].first]<<" "<<CanPlay[i][k].second<<endl;
                                            cout<<"Computer "<<i<<" gets "<<ConvertNum[screen[j].first]<<" "<<screen[j].second<<endl;
                                            screen.erase(screen.begin()+j);
                                            break;
                                        }
                                    }
                                    else if(screen[j].second == CanPlay[i][k].second){
                                        position=k;
                                        HaveCard=1;
                                        ChooseCard=make_pair(CanPlay[i][k].first,CanPlay[i][k].second);
                                        ScreenCard=make_pair(screen[j].first,screen[j].second);
                                        cout<<"Computer "<<i<<" sends "<<ConvertNum[CanPlay[i][k].first]<<" "<<CanPlay[i][k].second<<endl;
                                        cout<<"Computer "<<i<<" gets "<<ConvertNum[screen[j].first]<<" "<<screen[j].second<<endl;
                                        screen.erase(screen.begin()+j);
                                        break;
                                    }
                                }
                            }
                            if(HaveCard==1) break;
                        }
                        if(HaveCard==0){//場面上只有黑色可配對的牌
                            int Min=14;
                            for(int k=0;k<CanPlay[i].size();k++){
                                if(CanPlay[i][k].second<Min){
                                    Min=CanPlay[i][k].second;
                                    position=k;
                                }
                            }
                            for(int j=0;j<screen.size();j++){
                                if(CanPlay[i][position].second>=1 && CanPlay[i][position].second<=9){
                                    if((screen[j].second)+(CanPlay[i][position].second)==10){
                                        ChooseCard=make_pair(CanPlay[i][position].first,CanPlay[i][position].second);
                                        ScreenCard=make_pair(screen[j].first,screen[j].second);
                                        cout<<"Computer "<<i<<" sends "<<ConvertNum[CanPlay[i][position].first]<<" "<<CanPlay[i][position].second<<endl;
                                        cout<<"Computer "<<i<<" gets "<<ConvertNum[screen[j].first]<<" "<<screen[j].second<<endl;
                                        screen.erase(screen.begin()+j);
                                        break;
                                    }
                                }
                                else if(screen[j].second == CanPlay[i][position].second){
                                    ChooseCard=make_pair(CanPlay[i][position].first,CanPlay[i][position].second);
                                    ScreenCard=make_pair(screen[j].first,screen[j].second);
                                    cout<<"Computer "<<i<<" sends "<<ConvertNum[CanPlay[i][position].first]<<" "<<CanPlay[i][position].second<<endl;
                                    cout<<"Computer "<<i<<" gets "<<ConvertNum[screen[j].first]<<" "<<screen[j].second<<endl;
                                    screen.erase(screen.begin()+j);
                                    break;
                                }
                            }
                        }
                        for(int j=0;j<player[i].size();j++){
                            if(player[i][j].first==CanPlay[i][position].first && player[i][j].second==CanPlay[i][position].second){
                                player[i].erase(player[i].begin()+j);
                            }
                        }
                        CountPoint(ChooseCard,ScreenCard,i);
                    }
                    CanPlay[i].clear();
                }
                else{//電腦沒有可配對的牌
                    int Min=14,position,PutBlack=0;
                    for(int j=0;j<player[i].size();j++){
                        if(player[i][j].first==1 || player[i][j].first==3){
                            if(player[i][j].second<Min){
                                PutBlack=1;
                                Min=player[i][j].second;
                                position=j;
                            }
                        }
                    }
                    if(PutBlack==0){
                        for(int k=0;k<player[i].size();k++){
                            if(player[i][k].second<Min){
                                PutBlack=1;
                                Min=player[i][k].second;
                                position=k;
                            }
                        }
                    }
                    cout<<"Computer "<<i<<" puts: "<<ConvertNum[player[i][position].first]<<" "<<player[i][position].second<<endl;
                    screen.push_back(make_pair(player[i][position].first,player[i][position].second));
                    player[i].erase(player[i].begin()+position);
                    cout<<"Computer "<<i<<" don't obtain any points."<<endl<<endl;
                }
            }
            FlopCard(i);
        }
    }
    if(!player[0].empty()){
        PrintHuman();
        PrintScreen();
    }

}

bool Card::decide(int a){
    int HaveCard=0;
    for(int i=0;i<player[a].size();i++){
        for(int j=0;j<screen.size();j++){
            if(player[a][i].second>=1 && player[a][i].second<=9){
                if(player[a][i].second + screen[j].second==10){
                    HaveCard=1;
                    CanPlay[a].push_back(make_pair(player[a][i].first,player[a][i].second));
                }
            }
            else{
                if(player[a][i].second == screen[j].second){
                    HaveCard=1;
                    CanPlay[a].push_back(make_pair(player[a][i].first,player[a][i].second));
                }
            }
        }
    }
    if(HaveCard==1){
        return true;
    }
    else{
        return false;
    }
}

void Card::CountPoint(pair<int,int> deck,pair<int,int> deck2,int a){
    int Count=0;
    if(a==0){//玩家點數
        if(deck.first==2 || deck.first==4){
            if(deck.second==1){
                TotalPoint[a]+=20;
                Count+=20;
            }
            else if(deck.second>=2 && deck.second<=8){
                TotalPoint[a]+=deck.second;
                Count+=deck.second;
            }
            else{
                TotalPoint[a]+=10;
                Count+=10;
            }
        }
        else if(deck.first == 1 && deck.second == 1){
            TotalPoint[a]+=10;
            Count+=10;
        }
       //-----------------------------------------選擇的牌獲得的點數
        if(deck2.first==2 || deck2.first==4){
            if(deck2.second==1){
                TotalPoint[a]+=20;
                Count+=20;
            }
            else if(deck2.second>=2 && deck2.second<=8){
                TotalPoint[a]+=deck2.second;
                Count+=deck2.second;
            }
            else{
                TotalPoint[a]+=10;
                Count+=10;
            }
        }
        else if(deck2.first == 1 && deck2.second == 1){
            TotalPoint[a]+=10;
            Count+=10;
        }
        if(Count==0){
            cout<<"You don't obtain any point."<<endl<<endl;
        }
        else{
            cout<<"You obtains "<<Count<<" points"<<endl<<endl;
        }

    }
    //-----------------------------------------------------------------------------------
    else{//電腦點數
        if(deck.first==2 || deck.first==4){
            if(deck.second==1){;
                TotalPoint[a]+=20;
                Count+=20;
            }
            else if(deck.second>=2 && deck.second<=8){
                TotalPoint[a]+=deck.second;
                Count+=deck.second;
            }
            else{
                TotalPoint[a]+=10;
                Count+=10;
            }
        }
        else if(deck.first == 1 && deck.second == 1){
            TotalPoint[a]+=10;
            Count+=10;
        }
        //---------------------------
        if(deck2.first==2 || deck2.first==4){
            if(deck2.second==1){
                TotalPoint[a]+=20;
                Count+=20;
            }
            else if(deck2.second>=2 && deck2.second<=8){
                TotalPoint[a]+=deck2.second;
                Count+=deck2.second;
            }
            else{
                TotalPoint[a]+=10;
                Count+=10;
            }
        }
        else if(deck2.first == 1 && deck2.second == 1){
            TotalPoint[a]+=10;
            Count+=10;
        }
        if(Count==0){
            cout<<"Computer "<<a<<" don't obtain any point."<<endl<<endl;
        }
        else{
            cout<<"Computer "<<a<<" obtains "<<Count<<" points"<<endl<<endl;
        }
    }
}

void Card::FlopCard(int a){
    int HavePoint=0,Count=0;
    int number=(rand()%13)+1;
    int face=(rand()%4)+1;
    while(Record[face-1][number-1]==1){
        number=(rand()%13)+1;
        face=(rand()%4)+1;
    }
    Record[face-1][number-1]=1;
    for(int i=0;i<screen.size();i++){
        if(face==2 || face==4){//翻出來的牌為紅色且可與場面上的牌配對
            if(screen[i].first==2 || screen[i].first==4){//場面上被配對的牌為紅色
                if(number>=1 && number<=9){
                    if((screen[i].second) + number == 10){
                        HavePoint=1;
                        if(number==1){
                            TotalPoint[a]+=20;
                            Count+=20;
                        }
                        else if(number>=2 && number<=8){
                             TotalPoint[a]+=number;
                             Count+=number;
                        }
                        else{
                            TotalPoint[a]+=10;
                            Count+=10;
                        }
                        if(screen[i].second==1){
                            TotalPoint[a]+=20;
                            Count+=20;
                        }
                        else if(screen[i].second>=2 && screen[i].second<=8){
                            TotalPoint[a]+=screen[i].second;
                            Count+=screen[i].second;
                        }
                        else{
                            TotalPoint[a]+=10;
                            Count+=10;
                        }
                    }
                }
                else{
                    if(screen[i].second == number){
                        HavePoint=1;
                        TotalPoint[a]+=20;
                        Count+=20;
                    }
                }
            }
            else{//翻的牌為紅色 場面上被配對的牌為黑色
                if(number>=1 && number<=9){
                    if((screen[i].second) + number == 10){
                        HavePoint=1;
                        if(screen[i].second==1 && screen[i].first==1){
                            TotalPoint[a]+=10;
                            Count+=10;
                        }
                        if(number==1){
                            TotalPoint[a]+=20;
                            Count+=20;
                        }
                        else if(number>=2 && number<=8){
                            TotalPoint[a]+=number;
                            Count+=number;
                        }
                        else{
                            TotalPoint[a]+=10;
                            Count+=10;
                        }
                    }
                }
                else if(screen[i].second == number){
                    HavePoint=1;
                    TotalPoint[a]+=10;
                    Count+=10;
                }
            }
        }
        else if((screen[i].first==2 || screen[i].first==4) && (face==1 || face==3)){//翻的牌為黑色 場面上的牌為紅色
            if(number>=1 && number<=9){
                if((screen[i].second) + number == 10){
                    HavePoint=1;
                    if(number==1 && face==1){
                        TotalPoint[a]+=10;
                        Count+=10;
                    }
                    if(screen[i].second==1){
                        TotalPoint[a]+=20;
                        Count+=20;
                    }
                    else if(screen[i].second>=2 && screen[i].second<=8){
                        TotalPoint[a]+=screen[i].second;
                        Count+=screen[i].second;
                    }
                    else{
                        TotalPoint[a]+=10;
                        Count+=10;
                    }
                }
            }
            else if(screen[i].second == number){
                HavePoint=1;
                TotalPoint[a]+=10;
                Count+=10;
            }
        }
        if(HavePoint == 1){
            if(a==0) cout<<"You ";
            else{
                cout<<"Computer "<<a<<" ";
            }
            cout<<"gets "<<ConvertNum[face]<<" "<<number<<" and "
            <<ConvertNum[screen[i].first]<<" "<<screen[i].second<<"(Flop card)"<<endl;
            screen.erase(screen.begin()+i);
            break;
        }
    }
    int flag=0;
    if(HavePoint==0){//沒有紅色可配對的牌
        for(int i=0;i<screen.size();i++){
            if(number>=1 && number<=9){
                if((screen[i].second)+number==10){
                    if((number==1 && face==1) || (screen[i].first==1 && screen[i].second==1)){
                        TotalPoint[a]+=10;
                        Count+=10;
                    }
                    flag=1;
                    if(a==0) cout<<"You ";
                    else{
                        cout<<"Computer "<<a<<" ";
                    }
                    cout<<"gets "<<ConvertNum[face]<<" "<<number<<" and "
                    <<ConvertNum[screen[i].first]<<" "<<screen[i].second<<"(Flop card)"<<endl;
                    screen.erase(screen.begin()+i);
                    break;
                }
            }
            else{
                if((screen[i].second) == number){
                    if(a==0) cout<<"You ";
                    else{
                        cout<<"Computer "<<a<<" ";
                    }
                    cout<<"gets "<<ConvertNum[face]<<" "<<number<<" and "
                    <<ConvertNum[screen[i].first]<<" "<<screen[i].second<<"(Flop card)"<<endl;
                    screen.erase(screen.begin()+i);
                    flag=1;
                    break;
                }
            }
        }
        if(flag==0){//沒有可配對的牌
            screen.push_back(make_pair(face,number));
            if(a==0) cout<<"You ";
            else{
                cout<<"Computer "<<a<<" ";
            }
            cout<<"puts "<<ConvertNum[face]<<" "<<number<<"(Flop card)"<<endl;
        }
    }
    if(a==0){
        if(Count==0){
            cout<<"You don't obtain any point."<<endl<<endl;
        }
        else{
            cout<<"You obtains "<<Count<<" points"<<endl<<endl;
        }
    }
    else{
        if(Count==0){
                cout<<"Computer "<<a<<" don't obtain any point."<<endl<<endl;
            }
        else{
            cout<<"Computer "<<a<<" obtains "<<Count<<" points"<<endl<<endl;
        }
    }
}
