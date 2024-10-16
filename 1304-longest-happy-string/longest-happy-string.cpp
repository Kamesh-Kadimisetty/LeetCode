class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans;
        int totlen=a+b+c;
        int cntsA=0,cntsB=0,cntsC=0;
        for(int i=0;i<totlen;i++){
            if((a>=b && a>=c && cntsA!=2)||(cntsB==2 && a>0)||(cntsC==2 && a>0)){
                ans.append("a");
                cntsA++;
                cntsB=0;
                cntsC=0;
                a--;
            }
            else if((b>=a && b>=c && cntsB!=2)||(cntsA==2 && b>0)||(cntsC==2 && b>0)){
                ans.append("b");
                cntsA=0;
                cntsB++;
                cntsC=0;
                b--;
            }
            else if((c>=b && c>=a && cntsC!=2)||(cntsB==2 && c>0)||(cntsA==2 && c>0)){
                ans.append("c");
                cntsA=0;
                cntsB=0;
                cntsC++;
                c--;
            }
        }
        return ans;
    }
};