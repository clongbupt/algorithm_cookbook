#include <!-- <iostream> -->
using namespace std;

int common(int x,int y)
{
    if (x==y)
        return x;
    if (x>y)
        return common(x/2,y);
    else
        return common(x,y/2);
}

int main()
{
    int x,y;
    cin>>x<!--  -->>>y;
    cout<<common(x,y)<<endl;

    return 0;
}
