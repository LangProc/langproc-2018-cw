int x;

int gg()
{
    x=x+1;
    return x;
}

int main()
{
    return gg()+gg();
}

