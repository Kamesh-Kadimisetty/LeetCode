class Solution {
public:
    string numberToWords(int num) {
        if (num==0) return "Zero";
        string bigstring[]={"Thousand","Million","Billion"};
        string result=numtowordhelper(num%1000);
        num/=1000;

        for(int i=0;i<3;i++){
            if(num>0 && num%1000>0){
                result=numtowordhelper(num%1000)+bigstring[i]+" "+result;
            }
            num/=1000;
        }
        return result.empty()?result:result.substr(0,result.size()-1);
    }


    string numtowordhelper(int num){
          string digitstring[] = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
        string teenstring[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        string tenstring[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        string result="";
        if(num>99){
            result+=digitstring[num/100]+" Hundred ";
        }
        num%=100;
        if(num<20 && num>9){
            result+=teenstring[num-10]+" ";
        }else {
                if(num>=20){
                    result+=tenstring[num/10]+" ";
                }
                num%=10;
                if(num>0){
                    result+=digitstring[num]+" ";
                }
            }
    return result;
    }
};