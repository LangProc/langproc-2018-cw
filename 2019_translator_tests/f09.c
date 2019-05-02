int function(int aa, int b)
{
    if(aa<b){
        aa=aa-1;
        if(b<aa){
            b=b+3;
            if(aa==b){
                return aa*b;
            }
        }
        return b;
    }
    return 13;
}

int main()
{
    return function(0,0)+function(1,2)+function(4,3)+function(6,7);
}

