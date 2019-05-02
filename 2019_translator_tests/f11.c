int geo(int n)
{
    int acc=0;
    int t=n;
    while(t<n){
        acc=acc+t;
        t=t+1;
    }
    return acc;
}

int main()
{
    return geo(3)+geo(2)+geo(1);
}

