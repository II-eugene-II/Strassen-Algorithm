#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#define POW3_00 1
#define POW3_01 3
#define POW3_02 9
#define POW3_03 27
#define POW3_04 81
#define POW3_05 243
#define POW3_06 729
#define POW3_07 2187
#define POW3_08 6561
#define POW3_09 19683
#define POW3_10 59049
#define POW3_11 177147
#define POW3_12 531441
#define POW3_13 1594323
#define POW3_14 4782969
#define POW3_15 14348907
#define POW3_16 43046721
#define POW3_17 129140163
#define POW3_18 387420489
#define POW3_19 1162261467
#define POW3_20 3486784401
#define POW3_21 10460353203
#define POW3_22 31381059609
#define POW3_23 94143178827
#define POW3_24 282429536481
#define POW3_25 847288609443
#define POW3_26 2541865828329
#define POW3_27 7625597484987
#define POW3_28 22876792454961
#define POW3_29 68630377364883
#define POW3_30 205891132094649
#define POW3_31 617673396283947
#define POW3_32 1853020188851841
#define POW3_33 5559060566555523
#define POW3_34 16677181699666569
#define POW3_35 50031545098999707
#define POW3_36 150094635296999121
#define POW3_37 450283905890997363
#define POW3_38 1350851717672992089
#define POW3_39 4052555153018976267
#include <stdio.h>     // fopen, fputs, fclose 함수가 선언된 헤더 파일
#include <time.h>


int main()
{
	double start, end;
	start = (double)clock() / CLOCKS_PER_SEC;

	FILE *fp = fopen("strassenNum20milSet1.txt", "w");

	register unsigned long long N;

	int strassenTime = 20000000;

	for (N = 282515649610; N < 6003785411879964839; N++) // 6003785411879964839, 282515649610
	{
		

		if (strassenTime == 0)
		{
			break;
		}

		if (N % POW3_36 == 74120807554073640) // 74120807554073640 = 40 * 81 * 81 * 81 * 81 * 81 * 81 * 81 * 81
		{
			N += POW3_32 - 1;

			continue;
		}
		else if (N % POW3_32 == 915071698198440) // 915071698198440 = 40 * 81 * 81 * 81 * 81 * 81 * 81 * 81
		{
			N += POW3_28 - 1;

			continue;
		}
        else if (N % POW3_28 == 11297181459240) // 11297181459240 = 40 * 81 * 81 * 81 * 81 * 81 * 81
		{
			N += POW3_24 - 1;

			continue;
		}
		else if (N % POW3_24 == 139471376040) // 40 * 81 * 81 * 81 * 81 * 81 = 139471376040
		{
			N += POW3_20 - 1;

			continue;
		}
		else if (N % POW3_20 == 1721868840) // 40 * 81 * 81 * 81 * 81 = 1721868840
		{
			N += POW3_16 - 1; // 81 * 81 * 81 * 81 - 1 = 43046720

			continue;
		}
		else if (N % POW3_16 == 21257640)
		{
			N += POW3_12 - 1; // 81 * 81 * 81 - 1

			continue;
		}
		else if (N % POW3_12 == 262440)
		{
			N += POW3_08 - 1;

			continue;
		}
		else if (N % POW3_08 == 3240)
		{
			N += POW3_04 - 1;

			continue;
		}
		else if (N % POW3_04 == 40)
		{
			continue;
		}

		/*
		"1111" 제거
		*/


		else if (N % POW3_08 <= (N % POW3_16) / POW3_08)
		{
			N += ((N % POW3_16) / POW3_08) - N % POW3_08;

			continue;
		}

		else if ((N % POW3_16) / POW3_08 <= (N % POW3_24) / POW3_16)
		{
			N += ((N % POW3_24) / POW3_16 - (N % POW3_16) / POW3_08) * POW3_08;

			continue;
		}

		else if ((N % POW3_24) / POW3_16 <= (N % POW3_32) / POW3_24)
		{
			N += ((N % POW3_32) / POW3_24 - (N % POW3_24) / POW3_16) * POW3_16;

			continue;
		}

		else if ((N % POW3_32) / POW3_24 <= N / POW3_32)
		{
			N += (N / POW3_32 - (N % POW3_32) / POW3_24) * POW3_24;

			continue;
		}
		/*
		1열 -> N % POW3_08
		2열 -> (N % POW3_16) / POW3_08
		3열 -> (N % POW3_24) / POW3_16
		4열 -> (N % POW3_32) / POW3_24
		5열(맨 윗줄) -> N / POW3_32
		*/
		else if (N % 3 == 1 && (N % POW3_09) / POW3_08 == 1 && (N % POW3_17) / POW3_16 == 1 && (N % POW3_25) / POW3_24 == 1 && (N % POW3_33) / POW3_32 == 1)
		{
			continue;  // 8항 16항 24항 32항 40항 전부 1이면 거르기
		}
		else if ((N % POW3_02) / 3 == 1 && (N % POW3_10) / 19683 == 1 && (N % POW3_18) / POW3_17 == 1 && (N % POW3_26) / POW3_25 == 1 && (N % POW3_34) / POW3_33 == 1)
		{
			N += POW3_01 - (N % POW3_01) - 1;
			
			continue;  // 7항 15항 23항 31항 39항 전부 1이면 거르기
		}
		else if ((N % POW3_03) / POW3_02 == 1 && (N % POW3_11) / POW3_10 == 1 && (N % POW3_19) / POW3_18 == 1 && (N % POW3_27) / POW3_26 == 1 && (N % POW3_35) / POW3_34 == 1)
		{
			N += POW3_02 - (N % POW3_02) - 1;
			
			continue;  // 6항 14항 22항 30항 38항 전부 1이면 거르기
		}
		else if ((N % POW3_04) / POW3_03 == 1 && (N % POW3_12) / POW3_11 == 1 && (N % POW3_20) / POW3_19 == 1 && (N % POW3_28) / POW3_27 == 1 && (N % POW3_36) / POW3_35 == 1)
		{
			N += POW3_03 - (N % POW3_03) - 1;
			
			continue;  // 5항 13항 21항 29항 37항 전부 1이면 거르기
		}
		else if ((N % POW3_05) / POW3_04 == 1 && (N % POW3_13) / POW3_12 == 1 && (N % POW3_21) / POW3_20 == 1 && (N % POW3_29) / POW3_28 == 1 && (N % POW3_37) / POW3_36 == 1)
		{
			N += POW3_04 - (N % POW3_04) - 1;
			
			continue;  // 4항 12항 20항 28항 36항 전부 1이면 거르기
		}
		else if ((N % POW3_06) / POW3_05 == 1 && (N % POW3_14) / POW3_13 == 1 && (N % POW3_22) / POW3_21 == 1 && (N % POW3_30) / POW3_29 == 1 && (N % POW3_38) / POW3_37 == 1)
		{
			N += POW3_05 - (N % POW3_05) - 1;
			
			continue;  // 3항 11항 19항 27항 35항 전부 1이면 거르기
		}
		else if ((N % POW3_07) / POW3_06 == 1 && (N % POW3_15) / POW3_14 == 1 && (N % POW3_23) / POW3_22 == 1 && (N % POW3_31) / POW3_30 == 1 && (N % POW3_39) / POW3_38 == 1)
		{
			N += POW3_06 - (N % POW3_06) - 1;
			
			continue;  // 2항 10항 18항 26항 34항 전부 1이면 거르기
		}
		else if ((N % POW3_08) / POW3_07 == 1 && (N % POW3_16) / POW3_15 == 1 && (N % POW3_24) / POW3_23 == 1 && (N % POW3_32) / POW3_31 == 1 && N / POW3_39 == 1)
		{
			N += POW3_07 - (N % POW3_07) - 1;

			continue;  // 1항 9항 17항 25항 33항 전부 1이면 거르기
		}
		/*
		1
		1
		1
		1
		1
		제거
		*/
		else if (N % POW3_08 / POW3_07 == 2)
		{
			N += POW3_07 - (N % POW3_07) - 1;
				
		    continue;
		}
		else if (N % POW3_16 / POW3_15 == 2)
		{
			N += POW3_15 - (N % POW3_15) - 1;

			continue;
		}
		else if (N % POW3_24 / POW3_23 == 2)
		{
			N += POW3_23 - (N % POW3_23) - 1;

			continue;
		}
		else if (N % POW3_32 / POW3_31 == 2)
		{
			N += POW3_31 - (N % POW3_31) - 1;

			continue;
		}

		/*
		2xxx xxxx 제거
		*/

		else if ((N % POW3_04 / POW3_03 == 1) || (N % POW3_08 / POW3_07 == 1) && (N % POW3_12 / POW3_11 == 1) || (N % POW3_16 / POW3_15 == 1) && (N % POW3_20 / POW3_19 == 1) || (N % POW3_24 / POW3_23 == 1) && (N % POW3_28 / POW3_27 == 1) || (N % POW3_32 / POW3_31 == 1) && (N % POW3_36 / POW3_35 == 1) || (N / POW3_39 == 1))
		{
			N += POW3_03 - (N % POW3_03) - 1;
			
			continue; // 8번과 4번 비교
		}
		else if ((N % POW3_03 / POW3_02 == 1) || (N % POW3_08 / POW3_07 == 1) && (N % POW3_11 / POW3_10 == 1) || (N % POW3_16 / POW3_15 == 1) && (N % POW3_19 / POW3_18 == 1) || (N % POW3_24 / POW3_23 == 1) && (N % POW3_27 / POW3_26 == 1) || (N % POW3_32 / POW3_31 == 1) && (N % POW3_35 / POW3_34 == 1) || (N / POW3_39 == 1))
		{
			N += POW3_02 - (N % POW3_02) - 1;
			
			continue;
		}
		else if ((N % POW3_02 / POW3_01 == 1) || (N % POW3_07 / POW3_06 == 1) && (N % POW3_10 / POW3_09 == 1) || (N % POW3_15 / POW3_14 == 1) && (N % POW3_18 / POW3_17 == 1) || (N % POW3_23 / POW3_22 == 1) && (N % POW3_26 / POW3_25 == 1) || (N % POW3_31 / POW3_30 == 1) && (N % POW3_34 / POW3_33 == 1) || (N % POW3_39 / POW3_38 == 1))
		{
			N += POW3_01 - (N % POW3_01) - 1;
			
			continue;
		}
		else if ((N % POW3_01 / POW3_00 == 1) || (N % POW3_07 / POW3_06 == 1) && (N % POW3_09 / POW3_08 == 1) || (N % POW3_15 / POW3_14 == 1) && (N % POW3_17 / POW3_16 == 1) || (N % POW3_23 / POW3_22 == 1) && (N % POW3_25 / POW3_24 == 1) || (N % POW3_31 / POW3_30 == 1) && (N % POW3_33 / POW3_32 == 1) || (N % POW3_39 / POW3_38 == 1))
		{
			continue;
		}
		else if ((N % POW3_04 / POW3_03 == 1) || (N % POW3_06 / POW3_05 == 1) && (N % POW3_12 / POW3_11 == 1) || (N % POW3_14 / POW3_13 == 1) && (N % POW3_20 / POW3_19 == 1) || (N % POW3_22 / POW3_21 == 1) && (N % POW3_28 / POW3_27 == 1) || (N % POW3_30 / POW3_29 == 1) && (N % POW3_36 / POW3_35 == 1) || (N % POW3_38 / POW3_37 == 1))
		{
			N += POW3_03 - (N % POW3_03) - 1;
			
			continue;
		}
		else if ((N % POW3_03 / POW3_02 == 1) || (N % POW3_06 / POW3_05 == 1) && (N % POW3_11 / POW3_10 == 1) || (N % POW3_14 / POW3_13 == 1) && (N % POW3_19 / POW3_18 == 1) || (N % POW3_22 / POW3_21 == 1) && (N % POW3_27 / POW3_26 == 1) || (N % POW3_30 / POW3_29 == 1) && (N % POW3_35 / POW3_34 == 1) || (N % POW3_38 / POW3_37 == 1))
		{
			N += POW3_02 - (N % POW3_02) - 1;
			
			continue;
		}
		else if ((N % POW3_02 / POW3_01 == 1) || (N % POW3_05 / POW3_04 == 1) && (N % POW3_10 / POW3_09 == 1) || (N % POW3_13 / POW3_12 == 1) && (N % POW3_18 / POW3_17 == 1) || (N % POW3_21 / POW3_20 == 1) && (N % POW3_26 / POW3_25 == 1) || (N % POW3_29 / POW3_28 == 1) && (N % POW3_34 / POW3_33 == 1) || (N % POW3_37 / POW3_36 == 1))
		{
			N += POW3_01 - (N % POW3_01) - 1;
			
			continue;
		}
		else if ((N % POW3_01 / POW3_00 == 1) || (N % POW3_05 / POW3_04 == 1) && (N % POW3_09 / POW3_08 == 1) || (N % POW3_13 / POW3_12 == 1) && (N % POW3_17 / POW3_16 == 1) || (N % POW3_21 / POW3_20 == 1) && (N % POW3_25 / POW3_24 == 1) || (N % POW3_29 / POW3_28 == 1) && (N % POW3_33 / POW3_32 == 1) || (N % POW3_37 / POW3_36 == 1))
		{
			continue;
		}


		else
		{
			fprintf(fp, "%llu,\n", N);
			strassenTime -= 1;
			if (N % 65536 == 0)
			{
				end = (((double)clock()) / CLOCKS_PER_SEC);
				printf("%llu, 프로그램 수행 시간 :%lf초, %d \n", N, (end - start), strassenTime);
			}
		}
	}

	fclose(fp);    // 파일 포인터 닫기

	return 0;
}
