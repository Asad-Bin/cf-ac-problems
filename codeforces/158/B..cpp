#include<bits/stdc++.h>

using namespace std;

void task()
{
    long long n, x_1=0, x_2=0, x_3=0, car=0, input;

    cin>>n;

    while(n--){
        cin>>input;

        if(input==1){
            if(x_3>0){
                car++;
                x_3--;
            }
            else{
                x_1++;
            }
        }
        else if(input==2){
            x_2++;
            if(x_2%2==0 && x_2!=0){
                car++;
                x_2=0;
            }
        }
        else if(input==3){
            if(x_1>0){
                car++;
                x_1--;
            }
            else{
                x_3++;
            }
        }
        else if(input==4){
            car++;
        }
    }

    if(x_3>0) car+=x_3;
    if(x_2==1 && x_1>=2){
        car++;
        x_1-=2;
    }
    else if(x_2==1 && (x_1==1 || x_1==0)){
        car++;
        x_1=0;
    }

    if(x_1>0){
        if(x_1%4==0){
            x_1 /= 4;
            car = car + x_1;
        }
        else{
            x_1 /= 4;
            car = car + x_1 +1;
        }
    }

    cout<<car<<endl;
}

int main()
{
    task();

    return 0;
}
