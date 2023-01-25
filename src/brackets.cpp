/* Nama file    : brackets.cpp */
/* Fungsi       : Melakukan pengoperasian pada letak tanda kurung */

#include "input.cpp"

double operation(double a, double b, char op){
    switch (op){
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        default: return a / b;
    }
}

void allPossibleKurung(vector<string> *solution, double nums[4], char ops[3]){
/* Operasi pada kartu dipengaruhi juga dengan letak tanda kurung */
    int bracket[5][2][2] = {{{0, 1}, {2, 3}}, 
                            {{0, 1}, {0, 2}},
                            {{1, 2}, {0, 2}},
                            {{1, 2}, {1, 3}},
                            {{2, 3}, {1, 3}}};

    for (int i = 0; i < 5; i++){
        /* Operasi hanya dilakukan 3x */
        int *op1 = bracket[i][0];
        int *op2 = bracket[i][1];
        int opDex[3];
        opDex[0] = op1[1] - 1; 

        if (op1[1] == op2[1]){   
            opDex[1] = op2[0];
        } else {
            opDex[1] = op2[1] - 1;
        }
        opDex[2] = 3 - opDex[0] - opDex[1]; 

        /* First operation */
        double result1 = operation(nums[op1[0]], nums[op1[1]], ops[opDex[0]]);
        bool isFirst = false, isSecond = false;

        double next1[3];
        for (int i = 0; i < 3; i++){
            if (i < op1[0]){
                next1[i] = nums[i];
            } else if (i < op1[1]) {
                next1[i] = result1;
            } else {
                next1[i] = nums[i + 1];
            }
        }

        if (op2[0] >= op1[1]){
            op2[0]--;
            isFirst = true;
        }
        if (op2[1] >= op1[1]){
            op2[1]--;
            isSecond = true;
        }

        /* Second operation */
        double result2 = operation(next1[op2[0]], next1[op2[1]], ops[opDex[1]]);
        double next2[2];
        for (int i = 0; i < 2; i++){
            if (i < op2[0]){
                next2[i] = next1[i];
            } else if (i < op2[1]){
                next2[i] = result2;
            } else {
                next2[i] = next1[i + 1];
            }
        }
        if (isFirst) {
            op2[0]++;
        } if (isSecond) {
            op2[1]++;
        }

        /* Final operation */
        double res3 = operation(next2[0], next2[1], ops[opDex[2]]);

        /* Get answer list */
        if (res3 == 24){
            string ans = "";
            for (int i = 0; i < 4; i++){
                if (i == op1[0]){
                    ans += "(";
                }
                if (i == op2[0]){
                    ans += "(";
                }
                ans += to_string((int)nums[i]);
                if (i == op1[1]){
                    ans += ")";
                }
                if (i == op2[1]){
                    ans += ")";
                }
                if (i < 3){
                    ans += " " + string(1, ops[i]) + " ";
                }
            }
            solution -> push_back(ans);
        }

    }
    
}