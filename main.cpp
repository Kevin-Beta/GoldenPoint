#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
struct {
	float data;
	float grade;
} Player[100];

void game();

int main() {
	int n;
	scanf("%d", &n);
	if (n == 1) {
		game();

	}
	return 0;
}

void game() {
	int  N, a, b, c, i, j, k;

	scanf("%d", &N);

	scanf("%d", &a);
	for (i= 0; i < N; i++) {
		Player[i].grade = 0;
	}
	for (j = 1; j <= a; j++) {
		float sum=0;
		float G=0,m=0;

		for (i = 0; i < N; i++) {
			scanf("%f", &Player[i].data);
			if(Player[i].data>=0&&Player[i].data<=100) {
				sum += Player[i].data;
			}
		}
		G = (float)sum*0.618 / N;

		for (k = 0; k < N; k++) {
			m = abs((float)Player[k].data - G);
			if (m>=min) {
				min = m;
			}
			if (m <= max) {
				max = m;
			}
		}
		for(i=0; i<N; i++) {
			float delta=abs((float)Player[i].data - G);
			if(delta==max) {
				Player[i].grade-=1;
			}
			if(delta==min) {
				Player[i].grade+=1;
			}
		}
		printf("轮次:%d\n",j);
		for (i = 0; i < N; i++) {
			printf("玩家%d的得分为:", i+1);
			printf("%f\n", Player[i].grade);
		}
	}

}
