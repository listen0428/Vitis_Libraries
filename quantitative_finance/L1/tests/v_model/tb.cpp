/*
 * Copyright 2019 Xilinx, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include <ap_int.h>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

#define LEN 16
typedef double DT;

void dut(int endCnt, DT time[LEN], DT dtime[LEN], DT flatRate, DT spread, DT a, DT sigma, DT x0, DT b, DT* discount);

int main() {
    DT golden = 0.99689222385548493;
    DT err = 1e-8;

    int endCnt = 13;
    DT discount;
    double time[LEN] = {0,
                        0.5,
                        1,
                        1.4958904109589042,
                        2,
                        2.4986301369863013,
                        3.0027397260273974,
                        3.4986301369863013,
                        4.0027397260273974,
                        4.4986301369863018,
                        5.0027397260273974,
                        5.4986301369863018,
                        6.0027397260273974};
    double dtime[LEN] = {0.5,
                         0.5,
                         0.49589041095890418,
                         0.50410958904109582,
                         0.49863013698630132,
                         0.50410958904109604,
                         0.49589041095890396,
                         0.50410958904109604,
                         0.4958904109589044,
                         0.5041095890410956,
                         0.4958904109589044,
                         0.5041095890410956};
    double flatRate = 0.04875825;
    double spread = 0.0;
    double a = 0.16046325834281869;
    double sigma = 0.0037370022855109613;
    double b = 0.042001179856510314;
    double x0 = 0.0079988201434896891;
    double rates[LEN];
    dut(endCnt, time, dtime, flatRate, spread, a, sigma, x0, b, &discount);

    std::cout << "discount=" << discount << ",diff=" << discount - golden << std::endl;
    if (std::abs(discount - golden) < err)
        return 0;
    else
        return 1;
}
