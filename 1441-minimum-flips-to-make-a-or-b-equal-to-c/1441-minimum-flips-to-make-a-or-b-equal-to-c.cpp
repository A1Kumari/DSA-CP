class Solution {
public:
    int minFlips(int a, int b, int c) {
        int flips =0;
        for(int i=0; i<32; i++){
            bool bit_a = a & (1<<i);
            bool bit_b = b & (1<<i);
            bool bit_c = c & (1<<i);

            if(bit_c){
                //if bit in c is 1, atleast one of a or b should be 1
                if(!bit_a && !bit_b){
                    flips += 1;
                }
            }
            else{
                    //if bit in c is 1, atleast one of a or b should be 1
                    if(bit_a){
                        flips += 1;
                    }
                    if(bit_b){
                        flips += 1;
                    }
                }
            
        }
        return flips;
    }
};