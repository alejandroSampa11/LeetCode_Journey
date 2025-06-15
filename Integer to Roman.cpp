class Solution {
    public:
        string intToRoman(int num) {
            string val = to_string(num);
            string resu ="";
            map<int,string>roman;
            roman[1] = "I";
            roman[5] = "V";
            roman[10] = "X";
            roman[50] = "L";
            roman[100] = "C";
            roman[500] = "D";
            roman[1000] = "M";
    
            int lon = val.size();
            int p = pow(10,lon-1);
    
            for(int i = 0;i<val.size();i++){
                char num = val[i];
                if(num >= '1' && num <= '3'){
                    int num2 = (int)num - 48;
                    while(num2--){
                        resu+=roman[p];
                    }
                }else if(num == '4'){
                    resu+=roman[p];
                    resu+=roman[p*5];
                }else if(num >= '5' && num <= '8'){
                    resu+=roman[p*5];
                    int num2 = (int)num - 48;
                    num2-=5;
                    while(num2--){
                        resu+=roman[p];
                    }
                }else if(num == '9'){
                    resu+=roman[p];
                    resu+=roman[p*10];
                }
                
                p = p/10;
            }
    
            cout<<p<<endl;
            return resu;
            
        }
    };