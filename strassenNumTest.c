#define _CRT_SECURE_NO_WARNINGS    // fopen 보안 경고로 인한 컴파일 에러 방지
#include <stdio.h>     // fopen, fputs, fclose 함수가 선언된 헤더 파일
#include <time.h>


int main()
{
    double start, end;
    start = (double)clock() / CLOCKS_PER_SEC;
    
    FILE *fp = fopen("strassenNum1to81pi5.txt", "w");

    register unsigned long long N;

    for (N = 282515649610; N < 6003785411879964839; N++) // 6003785411879964839, 282515649610
    {
        if (N % 22876792454961 == 11297181459240) // 22876792454961 = 81 * 81 * 81 * 81 * 81 * 81 * 81, 11297181459240 = 40 * 81 * 81 * 81 * 81 * 81 * 81
        {
            N += 282429536480; // 81 * 81 * 81 * 81 * 81 * 81 - 1 = 282429536480

            continue;
        }
        else if (N % 282429536481 == 139471376040) // 81 * 81 * 81 * 81 * 81 * 81 = 282429536481, 40 * 81 * 81 * 81 * 81 * 81 = 139471376040
        {
            N += 3486784400; // 81 * 81 * 81 * 81 * 81 - 1 = 3486784400

            continue;
        }
        else if (N % 3486784401 == 1721868840) // 81 * 81 * 81 * 81 * 81 = 3486784401, 40 * 81 * 81 * 81 * 81 = 1721868840
        {
            N += 43046720; // 81 * 81 * 81 * 81 - 1 = 43046720

            continue;
        }
        else if (N % 43046721 == 21257640)
        {
            N += 531440; // 81 * 81 * 81 - 1

            continue;
        }
        else if (N % 531441 == 262440)
        {
            N += 6560;

            continue;
        }
        else if (N % 6561 == 3240)
        {
            N += 80;

            continue;
        }
        else if (N % 81 == 40)
        {
            continue;
        }

        else if (N % 6561 == (N % 43046721) / 6561)
        {
            continue;  // 1열과 2열 비교
        }

        else if (N % 6561 == (N % 282429536481) / 43046721)
        {
            continue;  // 1열과 3열 비교
        }

        else if ((N % 43046721) / 6561 == (N % 282429536481) / 43046721)
        {
            continue;  // 2열과 3열 비교
        }

        else if (N % 6561 == (N % 1853020188851841) / 282429536481)
        {
            continue;  // 1열과 4열 비교
        }

        else if ((N % 43046721) / 6561 == (N % 1853020188851841) / 282429536481)
        {
            continue;  // 2열과 4열 비교
        }

        else if ((N % 282429536481) / 43046721 == (N % 1853020188851841) / 282429536481)
        {
            continue;  // 3열과 4열 비교
        }

        else if (N % 6561 == N / 1853020188851841)
        {
            continue;  // 1열과 5열 비교
        }

        else if ((N % 43046721) / 6561 == N / 1853020188851841)
        {
            continue;  // 2열과 5열 비교
        }
        
        else if ((N % 282429536481) / 43046721 == N / 1853020188851841)
        {
            continue;  // 3열과 5열 비교
        }

        else if ((N % 1853020188851841) / 282429536481 == N / 1853020188851841)
        {
            continue;  // 4열과 5열 비교
        }

        /*
        1열 -> N % 6561
        2열 -> (N % 43046721) / 6561
        3열 -> (N % 282429536481) / 43046721
        4열 -> (N % 1853020188851841) / 282429536481
        5열(맨 윗줄) -> N / 1853020188851841
        */

        else if (N % 3 == 1 && (N % 19683) / 6561 == 1 && (N % 129140163) / 43046721 == 1 && (N % 847288609443) / 282429536481 == 1 && (N % 5559060566555523) / 1853020188851841 == 1)
        {
            continue;  // 8항 16항 24항 32항 40항 전부 1이면 거르기
        }
      
      
        else if ((N % 9) / 3 == 1 && (N % 59049) / 19683 == 1 && (N % 387420489) / 129140163 == 1 && (N % 2541865828329) / 847288609443 == 1 && (N % 16677181699666569) / 5559060566555523 == 1)
        {
            continue;  // 7항 15항 23항 31항 39항 전부 1이면 거르기
        }

        else if ((N % 27) / 9 == 1 && (N % 177147) / 59049 == 1 && (N % 1162261467) / 387420489 == 1 && (N % 7625597484987) / 2541865828329 == 1 && (N % 50031545098999707) / 16677181699666569 == 1)
        {
            continue;  // 6항 14항 22항 30항 38항 전부 1이면 거르기
        }
      
        else if ((N % 81) / 27 == 1 && (N % 531441) / 177147 == 1 && (N % 3486784401) / 1162261467 == 1 && (N % 22876792454961) / 7625597484987 == 1 && (N % 150094635296999121) / 50031545098999707 == 1)
        {
            continue;  // 5항 13항 21항 29항 37항 전부 1이면 거르기
        }
      
        else if ((N % 243) / 81 == 1 && (N % 1594323) / 531441 == 1 && (N % 10460353203) / 3486784401 == 1 && (N % 68630377364883) / 22876792454961 == 1 && (N % 450283905890997363) / 150094635296999121 == 1)
        {
            continue;  // 4항 12항 20항 28항 36항 전부 1이면 거르기
        }
      
        else if ((N % 729) / 243 == 1 && (N % 4782969) / 1594323 == 1 && (N % 31381059609) / 10460353203 == 1 && (N % 205891132094649) / 68630377364883 == 1 && (N % 1350851717672992089) / 450283905890997363 == 1)
        {
            continue;  // 3항 11항 19항 27항 35항 전부 1이면 거르기
        }
      
        else if ((N % 2187) / 729 == 1 && (N % 14348907) / 4782969 == 1 && (N % 94143178827) / 31381059609 == 1 && (N % 617673396283947) / 205891132094649 == 1 && (N % 4052555153018976267) / 1350851717672992089 == 1)
        {
            continue;  // 2항 10항 18항 26항 34항 전부 1이면 거르기
        }
      
        else if ((N % 6561) / 2187 == 1 && (N % 43046721) / 14348907 == 1 && (N % 282429536481) / 94143178827 == 1 && (N % 1853020188851841) / 617673396283947 == 1 && N / 4052555153018976267 == 1)
        {
            continue;  // 1항 9항 17항 25항 33항 전부 1이면 거르기
        }
        

        else
        {
            fprintf(fp, "%llu,\n", N);
            if (N % 131072 == 0)
            {
                end = (((double)clock()) / CLOCKS_PER_SEC);
                printf("%llu, 프로그램 수행 시간 :%lf\n", N, (end - start));
            }
        }
    }

    fclose(fp);    // 파일 포인터 닫기

    return 0;
}
