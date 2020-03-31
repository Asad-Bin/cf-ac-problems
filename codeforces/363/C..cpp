//Code by  Asad Bin Saber
//31  03  2020

#include <stdio.h>
#include <vector>
#include <string.h>
#include <iostream>

using namespace std;

void task()
{

    vector<char> input;
    char str[200001];
    long long len;

    scanf(" %[^\n]", str);
    len = strlen(str);
    for(long long i=0; i<len; i++){
        input.push_back(str[i]);
    }

    bool flag=0;

    //while(1){
    for(long long i=0; i<input.size(); ){
        if(input[i]==input[i+1] && (i+1)<input.size()){
            bool kaaj =0;
            if(input[i+2]==input[i] && (i+2)<input.size()){
                //if(input.size()%2==0){
                    /*if(i==(input.size()/2)-1 || i==(input.size()/2)){
                        input.erase(input.begin()+i);
                        input[input.size()] = '\0';
                        flag=1;
                    }
                    else if((i+1)==(input.size()/2)-1 ||  (i+1)==input.size()/2){
                        input.erase(input.begin()+i+1);
                        input[input.size()] = '\0';
                        flag=1;
                        kaaj=1;
                    }
                    else if((i+2)==(input.size()/2)-1 ||  (i+2)==input.size()/2){
                        input.erase(input.begin()+i+2);
                        input[input.size()] = '\0';
                        flag=1;
                        kaaj=1;
                    }*/
                    //if(i==0){                  //priotirity...
                        input.erase(input.begin()+i);
                        input[input.size()] = '\0';
                        flag=1;
                        kaaj=1;
                        //i++;
                    //}
                    /*
                    else if((i+2)==input.size()-1){
                        input.erase(input.end()-1);
                        input[input.size()] = '\0';
                        flag=1;
                        kaaj=1;
                    }
                    else{
                        input.erase(input.begin()+i+1);
                        input[input.size()] = '\0';
                        flag=1;
                        kaaj=1;
                    }*/
                //}
                /*else{
                    if(i==(input.size()-1)/2){
                        input.erase(input.begin()+i);
                        input[input.size()] = '\0';
                        flag=1;
                        kaaj=1;
                    }
                    else if((i+1)==(input.size()-1)/2){
                        input.erase(input.begin()+i+1);
                        input[input.size()] = '\0';
                        flag=1;
                        kaaj=1;
                    }
                    else if((i+2)==(input.size()-1)/2){
                        input.erase(input.begin()+i+2);
                        input[input.size()] = '\0';
                        flag=1;
                        kaaj=1;
                    }
                    else if(i==0){
                        input.erase(input.begin());
                        input[input.size()] = '\0';
                        flag=1;
                        kaaj=1;
                    }
                    else if((i+2)==(input.size()-1)){
                        input.erase(input.end()-1);
                        input[input.size()] = '\0';
                        flag=1;
                        kaaj=1;
                    }
                    else i++;
                }*/
            }
            else if(input[i+2]!=input[i] && (i+3)<input.size() && kaaj==0){
                if(input[i+2]==input[i+3]){
                    //if(input.size()%2==0){
                        /*if(i==(input.size()/2)-1 ||  i==(input.size()/2)){
                            input.erase(input.begin()+i);
                            input[input.size()] = '\0';
                            flag=1;
                        }
                        else if((i+1)==(input.size()/2)-1 ||  (i+1)==input.size()/2){
                            input.erase(input.begin()+i+1);
                            input[input.size()] = '\0';
                            flag=1;
                        }
                        else if((i+2)==(input.size()/2)-1 ||  (i+2)==input.size()/2){
                            input.erase(input.begin()+i+2);
                            input[input.size()] = '\0';
                            flag=1;
                        }
                        else if((i+3)==(input.size()/2)-1 ||  (i+3)==input.size()/2){
                            input.erase(input.begin()+i+3);
                            input[input.size()] = '\0';
                            flag=1;
                        }*/
                        //if(i==0){
                        if((i+3)==input.size()-1){
                            input.erase(input.end()-1);
                            input[input.size()] = '\0';
                            flag=1;
                        }
                        else{
                            input.erase(input.begin()+i+2);
                            input[input.size()] = '\0';
                            flag=1;
                        }
                        //i++;
                        //else i++;
                    //}
                    /*else{
                        if(i==(input.size()-1)/2){
                            input.erase(input.begin()+i);
                            input[input.size()] = '\0';
                            flag=1;
                        }
                        else if((i+1)==(input.size()-1)/2){
                            input.erase(input.begin()+i+1);
                            input[input.size()] = '\0';
                            flag=1;
                        }
                        else if((i+2)==(input.size()-1)/2){
                            input.erase(input.begin()+i+2);
                            input[input.size()] = '\0';
                            flag=1;
                        }
                        else if((i+3)==(input.size()-1)/2){
                            input.erase(input.begin()+i+3);
                            input[input.size()] = '\0';
                            flag=1;
                        }
                        else if(i==0){
                            input.erase(input.begin());
                            input[input.size()] = '\0';
                            flag=1;
                        }
                        else if((i+3)==(input.size()-1)){
                            input.erase(input.end()-1);
                            input[input.size()] = '\0';
                            flag=1;
                        }
                        else i++;
                    }*/
                }
                else{
                    i++;
                }
            }
            else{
                i++;
            }
        }
        else{
            i++;
        }
    }
    //    if(flag==1){
    //            flag=0;
    //    }
    //    else break;
    //}

    for(long long i=0; i<input.size() && input[i]!='\0'; i++) cout<<input[i];
    cout<<endl;
}

int main()
{
    task();

    return 0;
}
