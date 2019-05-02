int f(int x)
{
    return x+1;
}

int g(int x)
{
    return f(x+1);
}

int main()
{
    int g;
    g=4;
    return f(2);
}

