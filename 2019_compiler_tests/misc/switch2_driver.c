
int g();

int main()
{
    int x;
    for(int i=0; i<4; i++){
        fprintf(stderr, "g(%d)==%d\n", i, g(i));
    }
    return !( (g(0)+g(1)+g(2)+g(3))==10);
}
