int main()
{
    int xx;
    int y;
    int acc=2;
    xx=0;
    y=0;
    
    while(xx<6){
        y=0;
        while(y!=xx){
            acc = acc + y;
            y=y+1;
        }
        xx=xx+2;
    }
    
    
    return acc-xx-y;
}

